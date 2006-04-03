--- src/kcm/configdialog.cpp.orig	Sat Apr  1 21:44:21 2006
+++ src/kcm/configdialog.cpp	Sun Apr  2 19:14:11 2006
@@ -17,6 +17,16 @@
    Boston, MA 02110-1301, USA.
 */
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <net/if.h>
+#include <net/if_mib.h>
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#include <net/route.h>
+#endif
+
 #include <qfile.h>
 #include <qdict.h>
 #include <qlabel.h>
@@ -363,6 +373,39 @@
 void ConfigDialog::defaults()
 {
     // Default interfaces
+#ifdef Q_OS_FREEBSD
+    /* Determine number of interfaces */
+    u_int   n    = 0;
+    size_t  nlen = 0;
+    nlen = sizeof(n);
+
+    if ( sysctlbyname("net.link.generic.system.ifcount", &n, &nlen, NULL, 0) != -1 )
+    {
+        mSettingsDict.clear();
+        mDlg->listBoxInterfaces->clear();
+
+        ifmibdata ifmd;
+        size_t len = 0;
+        len = sizeof(ifmd);
+        static  int name[] = { CTL_NET,
+                               PF_LINK,
+                               NETLINK_GENERIC,
+                               IFMIB_IFDATA,
+                               0,
+                               IFDATA_GENERAL };
+
+        for (int i = 1; i <= n; ++i)
+        {
+            name[4] = i;
+            /* Get data for iface-number i */
+            if ( sysctl(name, 6, (void*)&ifmd, (size_t*)&len, (void*)NULL, (size_t)0) == -1 )
+                continue;
+
+            QString interface = QString::fromLatin1(ifmd.ifmd_name);
+
+            if ( ifmd.ifmd_flags & IFF_LOOPBACK)
+                continue;
+#else
     QFile proc( "/proc/net/dev" );
     if ( proc.open( IO_ReadOnly ) )
     {
@@ -380,6 +423,7 @@
                 if ( interface == "lo" )
                     continue;
 
+#endif
                 InterfaceSettings* settings = new InterfaceSettings();
                 settings->customCommands = false;
                 settings->hideWhenNotAvailable = false;
@@ -401,8 +445,10 @@
                 mDlg->checkBoxStatistics->setChecked( false );
                 mDlg->checkBoxCustom->setChecked( false );
             }
+#ifndef __FreeBSD__
         }
         proc.close();
+#endif
     }
 
     // Default tool tips
