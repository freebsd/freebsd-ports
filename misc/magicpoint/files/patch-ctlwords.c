--- ctlwords.c.orig	1999-02-14 23:02:25 UTC
+++ ctlwords.c
@@ -24,6 +24,8 @@ BEGIN {
 
 #include <stdio.h>
 #include <string.h>
+#include <stdlib.h>
+#include <ctype.h>
 
 main(int argc, char *argv[])
 {
