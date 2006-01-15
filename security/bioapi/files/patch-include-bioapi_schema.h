--- include/bioapi_schema.h	Wed Jun  8 02:51:05 2005
+++ include/bioapi_schema.h	Fri Nov 25 15:28:04 2005
@@ -657,7 +657,7 @@
 /* Linux-Port: _MAX_PATH not defined in this file but used in this file.
  * It is defined in "port/bioapi_port.h";
  */
-#if defined (LINUX) || defined (UNIX) || defined (SOLARIS)
+#if defined (LINUX) || defined (__unix__) || defined (SOLARIS)
 #include <limits.h>
 #define _MAX_PATH (PATH_MAX + 1)
 #define  MAX_PATH _MAX_PATH
