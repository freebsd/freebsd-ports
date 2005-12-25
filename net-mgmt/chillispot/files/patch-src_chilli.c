--- src/chilli.c.orig	Mon Dec 26 08:06:46 2005
+++ src/chilli.c	Mon Dec 26 08:10:01 2005
@@ -14,13 +14,14 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/stat.h>
 #include <unistd.h>
-#include <sys/socket.h>
 #include <net/if.h>
 #include <errno.h>
-#include <sys/types.h>
 
 #if defined(__linux__)
 #include <asm/types.h>
@@ -460,13 +461,13 @@
   memset(options.uamokmask, 0, sizeof(options.uamokmask));
   options.uamoknetlen = 0;
   for (numargs = 0; numargs < args_info.uamallowed_given; ++numargs) {
+    char *p1 = NULL;
+    char *p2 = NULL;
+    char *p3 = malloc(strlen(args_info.uamallowed_arg[numargs])+1);
     if (options.debug & DEBUG_CONF) {
       printf ("Uamallowed #%d: %s\n", 
 	      numargs, args_info.uamallowed_arg[numargs]);
     }
-    char *p1 = NULL;
-    char *p2 = NULL;
-    char *p3 = malloc(strlen(args_info.uamallowed_arg[numargs])+1);
     strcpy(p3, args_info.uamallowed_arg[numargs]);
     p1 = p3;
     if ((p2 = strchr(p1, ','))) {
@@ -766,14 +767,14 @@
   memset(options.macok, 0, sizeof(options.macok));
   options.macoklen = 0;
   for (numargs = 0; numargs < args_info.macallowed_given; ++numargs) {
-    if (options.debug & DEBUG_CONF) {
-      printf ("Macallowed #%d: %s\n", numargs, 
-	      args_info.macallowed_arg[numargs]);
-    }
     char *p1 = NULL;
     char *p2 = NULL;
     char *p3 = malloc(strlen(args_info.macallowed_arg[numargs])+1);
     int i;
+    if (options.debug & DEBUG_CONF) {
+      printf ("Macallowed #%d: %s\n", numargs, 
+	      args_info.macallowed_arg[numargs]);
+    }
     strcpy(p3, args_info.macallowed_arg[numargs]);
     p1 = p3;
     if ((p2 = strchr(p1, ','))) {
