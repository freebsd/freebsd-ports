--- include/com.h.orig	Sat Dec  9 05:05:32 2000
+++ include/com.h	Sun Dec  7 02:30:26 2003
@@ -24,7 +24,7 @@
 int RegisterComClass(GUID* clsid, GETCLASSOBJECT gcs);
 
 #ifndef STDCALL
-#define STDCALL __attribute__((__stdcall__))	
+#define STDCALL
 #endif
 
 struct IUnknown;
