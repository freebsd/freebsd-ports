--- kcm/configdialog.cpp.orig	Wed Sep 15 18:24:37 2004
+++ kcm/configdialog.cpp	Wed Jan 19 15:23:57 2005
@@ -17,6 +17,16 @@
    Boston, MA 02111-1307, USA.
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
@@ -355,6 +365,39 @@
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
@@ -372,6 +415,7 @@
                 if ( interface == "lo" )
                     continue;
 
+#endif
                 InterfaceSettings* settings = new InterfaceSettings();
                 settings->customCommands = false;
                 settings->hideWhenNotAvailable = false;
@@ -391,8 +435,10 @@
                 mDlg->checkBoxNotExisting->setChecked( false );
                 mDlg->checkBoxCustom->setChecked( false );
             }
+#ifndef __FreeBSD__
         }
         proc.close();
+#endif
     }
 
     // Default tool tips
