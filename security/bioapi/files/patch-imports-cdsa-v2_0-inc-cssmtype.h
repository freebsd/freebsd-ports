--- imports/cdsa/v2_0/inc/cssmtype.h	Wed Jun  8 02:51:05 2005
+++ imports/cdsa/v2_0/inc/cssmtype.h	Fri Nov 25 18:21:25 2005
@@ -19,7 +19,7 @@
 #define CSSMAPI __stdcall
 #define CSSM_FUNC __cdecl
 
-#elif defined (UNIX) 
+#elif defined (__unix__) 
 
 #define CSSMAPI
 #define CALLBACK
