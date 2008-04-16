--- src/getopt.c.orig	2000-02-17 03:12:38.000000000 +0100
+++ src/getopt.c	2008-04-14 23:51:02.000000000 +0200
@@ -34,6 +34,8 @@
 #include <config.h>
 #endif
 
+#include <string.h>
+
 #if !defined (__STDC__) || !__STDC__
 /* This is a separate conditional since some stdc systems
    reject `defined (const)'.  */
