--- makedb.c.orig	1993-03-03 22:10:04.000000000 +0100
+++ makedb.c	2013-06-16 18:17:48.000000000 +0200
@@ -4,6 +4,7 @@
 #endif /* lint */
 
 #include <stdio.h>
+#include <unistd.h>
 #include "config.h"
 
 typedef struct {
