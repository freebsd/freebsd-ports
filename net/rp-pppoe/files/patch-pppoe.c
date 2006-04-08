--- pppoe.c.orig	Sat Apr  8 16:11:14 2006
+++ pppoe.c	Sat Apr  8 16:11:53 2006
@@ -409,6 +409,7 @@
     unsigned int s;		/* Temporary to hold session */
     FILE *pidfile;
     unsigned int discoveryType, sessionType;
+    char const *options;
 
     PPPoEConnection conn;
 
@@ -434,7 +435,6 @@
     /* Initialize syslog */
     openlog("pppoe", LOG_PID, LOG_DAEMON);
 
-    char const *options;
 #ifdef DEBUGGING_ENABLED
     options = "I:VAT:D:hS:C:Usm:np:e:kdf:F:t:";
 #else
