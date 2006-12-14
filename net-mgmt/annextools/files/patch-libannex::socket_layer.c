--- libannex/socket_layer.c.orig	Thu Aug  4 16:58:59 1994
+++ libannex/socket_layer.c	Thu Dec 14 13:09:21 2006
@@ -74,6 +74,8 @@
 #include <ctype.h>
 #include <errno.h>
 #include <signal.h>
+#include <netdb.h>
+#include <netinet/in.h>
 #include "../inc/config.h"
 #include "../inc/slip/slip_user.h"
 
@@ -168,6 +170,8 @@
 static struct sockinf *sockinf_bynumber();
 static struct sockinf *sockinf_byport();
 
+static int trivial_alarm_handler(int);
+
 
 struct protoent *GETPROTOBYNAME(name)
 char *name;
@@ -189,7 +193,7 @@
 int protocol;		/* IPPROTO_UDP only */
 {
     struct sockinf *s;
-    errno_t error;
+    int error;
     int i;
 
     /* Check arguments */
@@ -260,7 +264,7 @@
 {
     struct sockinf *t, *u;
     int port;
-    errno_t error;
+    int error;
 
     if(!(t = sockinf_bynumber(s, FALSE))) {
 	errno = EBADF;
@@ -300,7 +304,7 @@
 {
     struct sockinf *t, *u;
     int port;
-    errno_t error;
+    int error;
 
     if(!(t = sockinf_bynumber(s, FALSE))) {
 	errno = EBADF;
