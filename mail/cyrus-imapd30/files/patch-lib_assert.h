--- lib/assert.h.orig	2023-02-12 23:06:46 UTC
+++ lib/assert.h
@@ -43,11 +43,21 @@
 #ifndef INCLUDED_ASSERT_H
 #define INCLUDED_ASSERT_H
 
+#ifndef PERL_POLLUTE
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 #ifdef __STDC__
 #define assert(ex)      {if (!(ex))assertionfailed(__FILE__, __LINE__, #ex);}
 void assertionfailed(const char *file, int line, const char *expr);
 #else
 #define assert(ex)      {if (!(ex))assertionfailed(__FILE__, __LINE__, (char*)0);}
+#endif
+
+#ifdef __cplusplus
+}
+#endif
 #endif
 
 #endif /* INCLUDED_ASSERT_H */
