--- include/bioapi_type.h	Wed Jun  8 02:51:05 2005
+++ include/bioapi_type.h	Fri Nov 25 15:27:46 2005
@@ -17,7 +17,7 @@
 
 #define BioAPI __stdcall
 
-#elif defined (UNIX)
+#elif defined (__unix__)
 
 #define BioAPI
 #define CALLBACK
