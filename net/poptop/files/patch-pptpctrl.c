--- pptpctrl.c.orig	Mon Jan 24 23:04:13 2005
+++ pptpctrl.c	Sat May  6 12:48:55 2006
@@ -742,7 +742,6 @@
 		sprintf(pppInterfaceIPs, "%s:%s", pppaddrs[0], pppaddrs[1]);
 		pppd_argv[an++] = pppInterfaceIPs;
 	}
-#endif

         if (!noipparam) {
                  pppd_argv[an++] = "ipparam";
@@ -751,10 +750,11 @@

         if (pptp_logwtmp) {
                  pppd_argv[an++] = "plugin";
-                 pppd_argv[an++] = "/usr/lib/pptpd/pptpd-logwtmp.so";
+                 pppd_argv[an++] = "%%PREFIX%%/lib/pptpd/pptpd-logwtmp.so";
                  pppd_argv[an++] = "pptpd-original-ip";
                  pppd_argv[an++] = inet_ntoa(inetaddrs[1]);
         }
+#endif

 	/* argv arrays must always be NULL terminated */
 	pppd_argv[an++] = NULL;
