--- pptpctrl.c.orig	Fri Oct 21 16:23:58 2005
+++ pptpctrl.c	Fri Oct 21 16:24:28 2005
@@ -770,7 +770,7 @@
 
         if (pptp_logwtmp) {
                  pppd_argv[an++] = "plugin";
-                 pppd_argv[an++] = "/usr/lib/pptpd/pptpd-logwtmp.so";
+                 pppd_argv[an++] = "%%PREFIX%%/lib/pptpd/pptpd-logwtmp.so";
                  pppd_argv[an++] = "pptpd-original-ip";
                  pppd_argv[an++] = inet_ntoa(inetaddrs[1]);
         }
