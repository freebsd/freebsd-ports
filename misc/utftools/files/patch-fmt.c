--- fmt.c.orig	Sat May 10 13:50:39 2003
+++ fmt.c	Sat May 10 13:51:23 2003
@@ -4,6 +4,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <errno.h>
+#include <unistd.h>
 
 #include <utf.h>
 #include <utftools.h>
