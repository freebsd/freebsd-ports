--- unexpand.c.orig	Sat May 10 13:52:43 2003
+++ unexpand.c	Sat May 10 13:52:58 2003
@@ -5,6 +5,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <errno.h>
+#include <unistd.h>
 
 #include <utf.h>
 #include <utftools.h>
