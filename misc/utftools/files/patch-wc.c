--- wc.c.orig	Sat May 10 13:51:37 2003
+++ wc.c	Sat May 10 13:52:00 2003
@@ -4,6 +4,7 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 
 #include <utf.h>
 #include <utftools.h>
