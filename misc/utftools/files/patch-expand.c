--- expand.c.orig	Sat May 10 13:52:15 2003
+++ expand.c	Sat May 10 13:52:31 2003
@@ -5,6 +5,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <errno.h>
+#include <unistd.h>
 
 #include <utf.h>
 #include <utftools.h>
