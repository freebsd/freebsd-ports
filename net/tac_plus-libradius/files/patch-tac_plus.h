--- ./tac_plus.h.orig	2000-12-18 17:58:02.000000000 +0100
+++ ./tac_plus.h	2011-08-29 00:31:55.000000000 +0200
@@ -70,7 +70,7 @@
  */
 /* #define REARMSIGNAL */
 
-#define VERSION "F4.0.3.alpha.v7(DB&PAM support)"
+#define VERSION "F4.0.3.alpha.v7(DB,PAM&libradius support - incl. mmersbers patches!)"
 
 /*
  * System definitions. 
@@ -154,6 +154,7 @@
 #endif /* MSCHAP */
 
 #include <string.h>
+#include <sys/param.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/ioctl.h>
@@ -172,7 +173,11 @@
 #include <sys/syslog.h>
 #endif
 
+#if __FreeBSD_version >= 900007
+#include <utmpx.h>
+#else
 #include <utmp.h>
+#endif
 
 #include <unistd.h>
 
@@ -681,7 +686,7 @@
 extern char *cfg_get_global_secret();
 #ifdef USE_PAM
 extern char *cfg_get_pam_service();
-#endif / *PAM */ 
+#endif /* PAM */ 
 extern void cfg_clean_config();
 extern char *cfg_nodestring();
 
