
$FreeBSD$

--- object/Regex.c.orig	Wed Dec 18 22:49:17 2002
+++ object/Regex.c	Wed Dec 18 22:49:29 2002
@@ -51,8 +51,8 @@
 
 #define  REGEX_CODEIT    /* only include sysv regex code once.. */
 #include "config.h"
-#include "Regex.h"
 #include "Malloc.h"
+#include "Regex.h"
 
 /**************************************************
  POSIX
