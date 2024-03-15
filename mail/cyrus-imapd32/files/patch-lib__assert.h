--- lib/assert.h.orig	2024-03-12 23:12:10 UTC
+++ lib/assert.h
@@ -43,11 +43,21 @@
 #ifndef INCLUDED_ASSERT_H
 #define INCLUDED_ASSERT_H
 
+#ifndef PERL_POLLUTE
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 void assertionfailed(const char *file, int line, const char *expr);
 
 #define assert(expr)                                                \
     ((expr)                                                         \
      ? (void)(0)                                                    \
      : assertionfailed(__FILE__, __LINE__, #expr))
+
+#ifdef __cplusplus
+}
+#endif
+#endif
 
 #endif /* INCLUDED_ASSERT_H */
