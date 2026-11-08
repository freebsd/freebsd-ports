--- src/config.c.orig	2026-08-12 08:28:49 UTC
+++ src/config.c
@@ -22,6 +22,7 @@
 
 #include <ctype.h>
 #include <errno.h>
+#include <getopt.h>
 #include <pwd.h>
 #include <stdio.h>
 #include <stdlib.h>
