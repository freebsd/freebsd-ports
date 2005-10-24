--- pptpctrl.c.orig	Wed Apr 28 11:36:07 2004
+++ pptpctrl.c	Thu Oct 20 22:33:48 2005
@@ -734,7 +734,7 @@
 
         if (pptp_logwtmp) {
                  pppd_argv[an++] = "plugin";
-                 pppd_argv[an++] = "/usr/lib/pptpd/pptpd-logwtmp.so";
+                 pppd_argv[an++] = "@@PREFIX@@/lib/pptpd/pptpd-logwtmp.so";
                  pppd_argv[an++] = "pptpd-original-ip";
                  pppd_argv[an++] = inet_ntoa(inetaddrs[1]);
         }
