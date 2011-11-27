--- libcnews/hostname.c.orig	1993-11-21 03:24:17.000000000 +0100
+++ libcnews/hostname.c	2011-05-12 14:49:50.000000000 +0200
@@ -7,6 +7,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <sys/types.h>
 
 #include "libc.h"
