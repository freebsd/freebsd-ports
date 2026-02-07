--- fmt.c.orig	1997-02-25 18:47:26 UTC
+++ fmt.c
@@ -4,6 +4,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <errno.h>
+#include <unistd.h>
 
 #include <utf.h>
 #include <utftools.h>
