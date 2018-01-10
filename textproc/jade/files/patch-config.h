--- include/config.h.orig	Fri Jun 14 12:58:51 2002
+++ include/config.h	Fri Jun 14 13:01:00 2002
@@ -31,6 +31,10 @@
 #define SP_ANSI_LIB
 #define SP_NO_STD_NAMESPACE
 #undef SP_NEW_H_MISSING
+#if __GNUC__ > 2
+#define SP_HAVE_TYPENAME
+#undef SP_NO_STD_NAMESPACE
+#endif
 #endif
 
 #endif /* __GNUG__ */
