--- Source/JavaScriptCore/wtf/DisallowCType.h.orig	2012-08-20 18:26:04.000000000 +0200
+++ Source/JavaScriptCore/wtf/DisallowCType.h	2013-09-11 12:41:07.000000000 +0200
@@ -35,6 +35,13 @@
 // ASCII-specific functions instead. This header makes sure we get a compile-time
 // error if we use one of the <ctype.h> functions by accident.
 
+// Include inlined functions using <ctype.h> first to avoid compilation errors
+#ifdef __cplusplus
+#include <cwchar>
+#include <cwctype>
+#include <string>
+#endif
+
 #include <ctype.h>
 
 #undef isalnum
