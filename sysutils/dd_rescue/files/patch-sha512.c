--- sha512.c.orig	2014-06-29 00:54:18.000000000 +0900
+++ sha512.c	2014-06-29 00:54:36.000000000 +0900
@@ -19,7 +19,7 @@
 #include <netinet/in.h>
 #include <assert.h>
 #include <unistd.h>
-#include <endian.h>
+#include <machine/endian.h>
 
 /*
 Note 1: All variables are 64 bit unsigned integers and addition is calculated modulo 2^64 
