--- pptpd.c.orig	2006-09-05 01:17:25.000000000 +0200
+++ pptpd.c	2008-11-27 22:09:53.000000000 +0100
@@ -110,18 +110,21 @@
 #define OPT_VRFA ""
 #define OPT_VRF ""
 #endif
-#if !defined(BSDUSER_PPP)
+#ifdef BSDUSER_PPP
+        printf(" [-o] [--option file]      Specifies the userland PPP system label to use\n");
+        printf("                           (default is pptp).\n");
+#else
         printf(" [-o] [--option file]      Specifies the PPP options file to use\n");
         printf("                           (default is /etc/ppp/options).\n");
 #endif
         printf(" [-p] [--pidfile file]     Specifies the file to write the process ID to\n");
-        printf("                           (default is /var/run/pptpd.pid).\n");
+        printf("                           (default is %s).\n",PIDFILE_DEFAULT);
 #if !defined(BSDUSER_PPP)
         printf(" [-s] [--speed baud]       Specifies the baud speed for the PPP daemon\n");
-        printf("                           (default is 115200).\n");
+        printf("                           (default is %s).\n",PPP_SPEED_DEFAULT);
 #endif
         printf(" [-t] [--stimeout seconds] Specifies the timeout for the first packet. This is a DOS protection\n");
-        printf("                           (default is 10).\n");
+        printf("                           (default is %s).\n",STIMEOUT_DEFAULT);
         printf(" [-v] [--version]          Displays the pptpd version number.\n");
         printf(" [-w] [--logwtmp]          Update wtmp as users login.\n");
         printf(" [-C] [--connections n]    Limit on number of connections.\n");
@@ -395,12 +398,18 @@
                        ppp_binary);
                 return 1;
         }
+
         /* check that the PPP options file is readable */
+        /* If -o or --option is being used to specify BSD userland
+           PPP system label, it makes no sense to check the option string to
+           see if it is the name of a readable file. */
+#if !defined(BSDUSER_PPP)
         if (pppdoptstr && access(pppdoptstr, R_OK) < 0) {
                 syslog(LOG_ERR, "MGR: PPP options file %s not readable",
                        pppdoptstr);
                 return 1;
         }
+#endif
 #ifdef BCRELAY
         /* check that the bcrelay binary is executable */
         if (bcrelay && access(BCRELAY_BIN, X_OK) < 0) {
