--- pptpctrl.c.orig	Fri Dec  8 01:01:40 2006
+++ pptpctrl.c	Tue Jul 31 07:56:19 2007
@@ -163,8 +163,13 @@
                         syslog(LOG_DEBUG, "CTRL: remote address = %s", pppRemote);
                 if (*speed)
                         syslog(LOG_DEBUG, "CTRL: pppd speed = %s", speed);
+#if BSDUSER_PPP
+                if (*pppdxfig)
+                        syslog(LOG_DEBUG, "CTRL: BSD userland ppp system label = %s", pppdxfig);
+#else
                 if (*pppdxfig)
                         syslog(LOG_DEBUG, "CTRL: pppd options file = %s", pppdxfig);
+#endif
         }
 
         addrlen = sizeof(addr);
@@ -708,14 +713,19 @@
 
         /* options for BSDUSER_PPP
          *
-         * ignores IP addresses, config file option, speed
-         * fix usage info in pptpd.c and configure script if this changes
+         * Ignore IP addresses and line speed
+         * Use -o or --option string as PPP system label
+         * Usage info in pptpd.c and configure script have been updated to
+         * reflect this change
          *
          * IP addresses can be specified in /etc/ppp/ppp.secret per user
          */
         pppd_argv[an++] = "-direct";
-        pppd_argv[an++] = "pptp";       /* XXX this is the system name */
-        /* should be dynamic - PMG */
+        if (*pppdxfig) {
+                pppd_argv[an++] = pppdxfig;
+        } else {
+                pppd_argv[an++] = "pptp";       /* XXX this is the system label */
+        }
 
 #elif SLIRP
 
@@ -786,7 +796,7 @@
 
         if (pptp_logwtmp) {
                  pppd_argv[an++] = "plugin";
-                 pppd_argv[an++] = "/usr/lib/pptpd/pptpd-logwtmp.so";
+                 pppd_argv[an++] = "%%PREFIX%%/lib/pptpd/pptpd-logwtmp.so";
                  pppd_argv[an++] = "pptpd-original-ip";
                  pppd_argv[an++] = inet_ntoa(inetaddrs[1]);
         }
