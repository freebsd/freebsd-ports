--- argp/argp-fmtstream.h.orig	2006-05-22 16:49:23 UTC
+++ argp/argp-fmtstream.h
@@ -186,7 +186,7 @@ extern void __argp_fmtstream_update (arg
 extern int _argp_fmtstream_ensure (argp_fmtstream_t __fs, size_t __amount);
 extern int __argp_fmtstream_ensure (argp_fmtstream_t __fs, size_t __amount);
 
-#ifdef __OPTIMIZE__
+#ifdef __OPTIMIZE_INLINE__
 /* Inline versions of above routines.  */
 
 #if !_LIBC
@@ -298,7 +298,7 @@ __argp_fmtstream_point (argp_fmtstream_t
 #undef __argp_fmtstream_ensure
 #endif
 
-#endif /* __OPTIMIZE__ */
+#endif /* __OPTIMIZE_INLINE__ */
 
 #endif /* ARGP_FMTSTREAM_USE_LINEWRAP */
 
