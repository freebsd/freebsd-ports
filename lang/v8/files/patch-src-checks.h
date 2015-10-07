--- src/checks.h.orig	2013-05-01 12:56:29 UTC
+++ src/checks.h
@@ -248,7 +248,7 @@ template <int> class StaticAssertionHelp
 #define STATIC_CHECK(test)                                                    \
   typedef                                                                     \
     StaticAssertionHelper<sizeof(StaticAssertion<static_cast<bool>((test))>)> \
-    SEMI_STATIC_JOIN(__StaticAssertTypedef__, __LINE__)
+    SEMI_STATIC_JOIN(__StaticAssertTypedef__, __LINE__) __attribute__((__unused__))
 
 
 extern bool FLAG_enable_slow_asserts;
