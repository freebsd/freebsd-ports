--- lib/loader/win32.h.orig	Mon Dec 11 18:10:09 2006
+++ lib/loader/win32.h	Mon Dec 11 18:10:21 2006
@@ -1 +1,2 @@
 int ext_unknown();
+void* LookupExternalByName(const char* library, const char* name);
