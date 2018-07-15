--- sha512.c.orig	2016-12-28 21:17:50 UTC
+++ sha512.c
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
