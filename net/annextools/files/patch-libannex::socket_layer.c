--- libannex/socket_layer.c.orig	Thu Aug  4 15:58:59 1994
+++ libannex/socket_layer.c	Thu Sep 18 20:10:32 2003
@@ -74,6 +74,8 @@
 #include <ctype.h>
 #include <errno.h>
 #include <signal.h>
+#include <netdb.h>
+#include <netinet/in.h>
 #include "../inc/config.h"
 #include "../inc/slip/slip_user.h"
 
@@ -189,7 +191,7 @@
 int protocol;		/* IPPROTO_UDP only */
 {
     struct sockinf *s;
-    errno_t error;
+    int error;
     int i;
 
     /* Check arguments */
@@ -260,7 +262,7 @@
 {
     struct sockinf *t, *u;
     int port;
-    errno_t error;
+    int error;
 
     if(!(t = sockinf_bynumber(s, FALSE))) {
 	errno = EBADF;
@@ -300,7 +302,7 @@
 {
     struct sockinf *t, *u;
     int port;
-    errno_t error;
+    int error;
 
     if(!(t = sockinf_bynumber(s, FALSE))) {
 	errno = EBADF;
