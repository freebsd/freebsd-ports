--- lib/loader/win32.h.orig	Tue Sep 12 18:12:21 2000
+++ lib/loader/win32.h	Mon Jul  2 02:44:09 2007
@@ -1 +1 @@
-int ext_unknown();
+void* LookupExternalByName(const char* library, const char* name);
