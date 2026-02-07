--- src/rmd_flush_to_ogg.c.orig	2009-03-09 15:02:47.000000000 +0800
+++ src/rmd_flush_to_ogg.c	2009-03-09 15:03:06.000000000 +0800
@@ -36,6 +36,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <errno.h>
+#include <unistd.h>
 
 
 
