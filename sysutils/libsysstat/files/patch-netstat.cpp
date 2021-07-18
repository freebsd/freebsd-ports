--- netstat.cpp.orig	2021-04-18 21:04:00 UTC
+++ netstat.cpp
@@ -26,8 +26,23 @@
 
 #include "netstat.h"
 #include "netstat_p.h"
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
 
+#if defined(HAVE_SYSCTL_H) && defined(HAVE_IF_H)
+extern "C"
+{
+    #include <net/if.h>
+    #include <net/if_mib.h>
+    #include <net/if_types.h>
+    #include <sys/socket.h> /* PF_LINK */
+    #include <sys/types.h>
+    #include <sys/sysctl.h>
+}
+#endif
 
+
 namespace SysStat {
 
 NetStatPrivate::NetStatPrivate(NetStat *parent)
@@ -37,6 +52,7 @@ NetStatPrivate::NetStatPrivate(NetStat *parent)
 
     connect(mTimer, SIGNAL(timeout()), SLOT(timeout()));
 
+#ifndef HAVE_SYSCTL_H
 
 #if (QT_VERSION >= QT_VERSION_CHECK(5,15,0))
     QStringList rows(readAllFile("/proc/net/dev").split(QLatin1Char('\n'), Qt::SkipEmptyParts));
@@ -58,12 +74,78 @@ NetStatPrivate::NetStatPrivate(NetStat *parent)
 
         mSources.append(tokens[0].trimmed());
     }
+#else
+        int count;
+        size_t len;
+        int cntifmib[] = { CTL_NET, PF_LINK, NETLINK_GENERIC, IFMIB_SYSTEM, IFMIB_IFCOUNT };// net.link.generic.system.ifcount;
+        len = sizeof(int);
+        if (sysctl(cntifmib, 5, &count, &len, NULL, 0) < 0)
+            perror("sysctl");
+
+
+        struct ifmibdata ifmd;
+        size_t len1 = sizeof(ifmd);
+        for (int i=1; i<=count;i++) {
+            int name[] = { CTL_NET, PF_LINK, NETLINK_GENERIC, IFMIB_IFDATA, i, IFDATA_GENERAL };
+
+            if (sysctl(name, 6, &ifmd, &len1, NULL, 0) < 0) {
+                perror("sysctl");
+            }
+            if ((ifmd.ifmd_data.ifi_type == IFT_ETHER) || (ifmd.ifmd_data.ifi_type == IFT_IEEE80211)) {
+            const char *iface = ifmd.ifmd_name;
+            mSources.append(QString::fromLatin1(iface));
+            }
+        }
+#endif
 }
 
 NetStatPrivate::~NetStatPrivate() = default;
 
 void NetStatPrivate::timeout()
 {
+#if defined(HAVE_IF_H) && defined(HAVE_SYSCTL_H)
+    int count;
+    size_t len;
+    int name[] = { CTL_NET, PF_LINK, NETLINK_GENERIC, IFMIB_SYSTEM, IFMIB_IFCOUNT };
+    struct ifmibdata ifmd;
+
+    len = sizeof(int);
+    if (sysctl(name, 5, &count, &len, NULL, 0) < 0)
+        return;
+
+    for (int i = 1; i <= count; i++)
+    {
+        len = sizeof(ifmd);
+        int name[] = { CTL_NET, PF_LINK, NETLINK_GENERIC, IFMIB_IFDATA, i, IFDATA_GENERAL };
+
+        if (sysctl(name, 6, &ifmd, &len, NULL, 0) < 0)
+            break;
+
+        if ((ifmd.ifmd_data.ifi_type == IFT_ETHER) || (ifmd.ifmd_data.ifi_type == IFT_IEEE80211))
+        {
+            const char *iface = ifmd.ifmd_name;
+            QString interfaceName = QString::fromLatin1(iface);
+            if ((ifmd.ifmd_data.ifi_link_state == LINK_STATE_UP) && (ifmd.ifmd_data.ifi_ipackets > 0))
+            {
+
+
+                Values current;
+                current.received = ifmd.ifmd_data.ifi_ibytes;
+                current.transmitted = ifmd.ifmd_data.ifi_obytes;
+
+                if (!mPrevious.contains(interfaceName))
+                    mPrevious.insert(interfaceName, Values());
+                const Values &previous = mPrevious[interfaceName];
+
+                if (interfaceName == mSource)
+                    emit update((( current.received - previous.received ) * 1000 ) / mTimer->interval(), (( current.transmitted - previous.transmitted ) * 1000 ) / mTimer->interval());
+
+                mPrevious[interfaceName] = current;
+            } else if(interfaceName == mSource)
+                emit(update(0,0));
+
+        }
+    }
 #if (QT_VERSION >= QT_VERSION_CHECK(5,15,0))
     QStringList rows(readAllFile("/proc/net/dev").split(QLatin1Char('\n'), Qt::SkipEmptyParts));
 #else
@@ -122,6 +204,7 @@ void NetStatPrivate::timeout()
 
         mPrevious[interfaceName] = current;
     }
+#endif
 }
 
 QString NetStatPrivate::defaultSource()
