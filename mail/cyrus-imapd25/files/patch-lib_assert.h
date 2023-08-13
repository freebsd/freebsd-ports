--- lib/assert.h.orig	2021-03-09 02:28:07 UTC
+++ lib/assert.h
@@ -43,11 +43,13 @@
 #ifndef INCLUDED_ASSERT_H
 #define INCLUDED_ASSERT_H
 
+#ifndef PERL_POLLUTE
 #ifdef __STDC__
 #define assert(ex)	{if (!(ex))assertionfailed(__FILE__, __LINE__, #ex);}
 void assertionfailed(const char *file, int line, const char *expr);
 #else
 #define assert(ex)	{if (!(ex))assertionfailed(__FILE__, __LINE__, (char*)0);}
+#endif
 #endif
 
 #endif /* INCLUDED_ASSERT_H */
