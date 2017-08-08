--- object/Regex.c.orig	2003-08-18 16:58:55 UTC
+++ object/Regex.c
@@ -51,8 +51,8 @@
 
 #define  REGEX_CODEIT    /* only include sysv regex code once.. */
 #include "config.h"
-#include "Regex.h"
 #include "Malloc.h"
+#include "Regex.h"
 
 /**************************************************
  POSIX
