--- include/libfyaml.h.orig	2022-11-03 06:41:20 UTC
+++ include/libfyaml.h
@@ -37,7 +37,7 @@ extern "C" {
 #include <stdarg.h>
 #include <stdio.h>
 #include <string.h>
-#include <alloca.h>
+#include <stdlib.h>
 
 #if defined (__unix__) || (defined (__APPLE__) && defined (__MACH__))
 #include <unistd.h>
