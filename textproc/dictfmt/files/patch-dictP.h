--- dictP.h.orig
+++ dictP.h
@@ -99,13 +99,13 @@
 #if HAVE_WINT_T && HAVE_WCHAR_H
 #include <wchar.h>
 #else
-#typedef unsigned int wint_t;
+typedef unsigned int wint_t;
 #endif
 
-#if !HAVE_WCHAR_T && HAVE_WCHAR_H
+#if HAVE_WCHAR_T && HAVE_WCHAR_H
 #include <wchar.h>
 #else
-#typedef unsigned int wchar_t;
+typedef unsigned int wchar_t;
 #endif
 
 #if !HAVE_MBSTATE_T
