--- imap/xapian_wrap.cpp.orig	2022-02-23 00:13:21 UTC
+++ imap/xapian_wrap.cpp
@@ -32,7 +32,11 @@ extern "C" {
 #include <xapian.h>
 
 #ifdef HAVE_CLD2
+#ifdef __FreeBSD__
+#include <cld/public/compact_lang_det.h>
+#else
 #include <cld2/public/compact_lang_det.h>
+#endif
 #endif
 
 // from global.h
