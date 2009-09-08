--- src/tsocks.c	2009-02-07 11:48:12.000000000 +0100
+++ src/tsocks.c	2009-08-18 07:35:08.000000000 +0200
@@ -54,6 +54,13 @@
 #define _GNU_SOURCE
 #endif
 
+/* Required by some BSDs */
+#ifndef  MAP_ANONYMOUS
+#ifdef MAP_ANON
+#define MAP_ANONYMOUS MAP_ANON
+#endif
+#endif
+
 /* Global configuration variables */
 const char *progname = "libtorsocks";         /* Name used in err msgs    */
 
@@ -66,7 +73,6 @@
 #include <sys/socket.h>
 #include <string.h>
 #include <strings.h>
-#include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/poll.h>
@@ -164,7 +164,7 @@
 void tsocks_init(void) {
 
 #define LOAD_ERROR(s,l) { \
-    char *error; \
+    const char *error; \
     error = dlerror(); \
     show_msg(l, "The symbol %s() was not found in any shared " \
                      "library. The error reported was: %s!\n", s, \
@@ -278,9 +284,9 @@
 #ifndef ALLOW_MSG_OUTPUT
    set_log_options(-1, (char *)stderr, 0);
 #else
-   if ((env = getenv("TSOCKS_DEBUG")))
+   if ((env = getenv("TORSOCKS_DEBUG")))
       loglevel = atoi(env);
-   if (((env = getenv("TSOCKS_DEBUG_FILE"))) && !suid)
+   if (((env = getenv("TORSOCKS_DEBUG_FILE"))) && !suid)
       logfile = env;
    set_log_options(loglevel, logfile, 1);
 #endif
@@ -299,7 +305,7 @@
     /* Determine the location of the config file */
   #ifdef ALLOW_ENV_CONFIG
     if (!suid) 
-        conffile = getenv("TSOCKS_CONF_FILE");
+        conffile = getenv("TORSOCKS_CONF_FILE");
   #endif
     
     /* Read in the config file */
@@ -367,8 +373,8 @@
     /* If this a UDP socket  */
     /* then we refuse it, since it is probably a DNS request      */
     if ((sock_type != SOCK_STREAM)) {
-        show_msg(MSGERR, "Connection is a UDP stream, may be a "
-                           "DNS request: rejecting.\n");
+        show_msg(MSGERR, "connect: Connection is a UDP or ICMP stream, may be a "
+                           "DNS request or other form of leak: rejecting.\n");
         return -1;
     }
 #endif
@@ -1331,20 +1337,20 @@
         nixuser = getpwuid(getuid());
 
         if (((uname = conn->path->defuser) == NULL) &&
-          ((uname = getenv("TSOCKS_USERNAME")) == NULL) &&
+          ((uname = getenv("TORSOCKS_USERNAME")) == NULL) &&
             ((uname = (nixuser == NULL ? NULL : nixuser->pw_name)) == NULL)) {
             show_msg(MSGERR, "Could not get SOCKS username from "
                     "local passwd file, torsocks.conf "
-                    "or $TSOCKS_USERNAME to authenticate "
+                    "or $TORSOCKS_USERNAME to authenticate "
                     "with");
           conn->state = FAILED;
             return(ECONNREFUSED);
         }
 
-        if (((upass = getenv("TSOCKS_PASSWORD")) == NULL) &&
+        if (((upass = getenv("TORSOCKS_PASSWORD")) == NULL) &&
           ((upass = conn->path->defpass) == NULL)) {
             show_msg(MSGERR, "Need a password in torsocks.conf or "
-                    "$TSOCKS_PASSWORD to authenticate with");
+                    "$TORSOCKS_PASSWORD to authenticate with");
           conn->state = FAILED;
             return(ECONNREFUSED);
         }
@@ -1695,11 +1701,12 @@
     /* If this a UDP socket  */
     /* then we refuse it, since it is probably a DNS request      */
     if ((sock_type != SOCK_STREAM)) {
-        show_msg(MSGERR, "Connection is a UDP stream, may be a "
-                           "DNS request: rejecting.\n");
+        show_msg(MSGERR, "sendto: Connection is a UDP or ICMP stream, may be a "
+                           "DNS request or other form of leak: rejecting.\n");
         return -1;
     }
 #endif
+
     return (ssize_t) realsendto(s, buf, len, flags, to, tolen);
 
 }
@@ -1748,8 +1755,8 @@
     /* If this a UDP socket  */
     /* then we refuse it, since it is probably a DNS request      */
     if ((sock_type != SOCK_STREAM)) {
-        show_msg(MSGERR, "Connection is a UDP stream, may be a "
-                           "DNS request: rejecting.\n");
+        show_msg(MSGERR, "sendmsg: Connection is a UDP or ICMP stream, may be a "
+                           "DNS request or other form of leak: rejecting.\n");
         return -1;
     }
 #endif
