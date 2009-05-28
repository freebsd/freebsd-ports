--- http.c.orig	2009-04-10 16:01:37.000000000 +0200
+++ http.c	2009-04-10 16:01:57.000000000 +0200
@@ -1,4 +1,6 @@
+/* this define breaks the build on FreeBSD:
 #define _XOPEN_SOURCE 500
+*/
 
 #include "gatling.h"
 
