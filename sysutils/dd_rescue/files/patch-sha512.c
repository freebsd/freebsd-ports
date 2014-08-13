--- sha512.c.orig	2014-08-07 02:38:59.000000000 +0900
+++ sha512.c	2014-08-13 23:04:15.000000000 +0900
@@ -13,13 +13,14 @@
 #endif
 
 #include "sha512.h"
+#include "ffs.h"
 #include <stdint.h>
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
 #include <assert.h>
 #include <unistd.h>
-#include <endian.h>
+#include <machine/endian.h>
 
 /*
 Note 1: All variables are 64 bit unsigned integers and addition is calculated modulo 2^64 
