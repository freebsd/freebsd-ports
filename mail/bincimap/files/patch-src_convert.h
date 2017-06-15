--- src/convert.h.orig	2005-02-08 20:30:22 UTC
+++ src/convert.h
@@ -43,6 +43,8 @@
 #include <iostream>
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include <sys/stat.h>
 
 #include "address.h"
@@ -113,7 +113,7 @@ namespace Binc {
       unsigned char c = *i;
       unsigned char d = *(i + 1);
       
-      char *t;
+      const char *t;
       if ((t = strchr(hexchars, c)) == 0)
 	return "out of range";
       n = (t - hexchars) << 4;
