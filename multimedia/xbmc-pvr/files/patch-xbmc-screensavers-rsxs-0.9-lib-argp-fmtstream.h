--- xbmc/screensavers/rsxs-0.9/lib/argp-fmtstream.h.orig
+++ xbmc/screensavers/rsxs-0.9/lib/argp-fmtstream.h
@@ -182,7 +182,7 @@ extern void __argp_fmtstream_update (arg
 extern int _argp_fmtstream_ensure (argp_fmtstream_t __fs, size_t __amount);
 extern int __argp_fmtstream_ensure (argp_fmtstream_t __fs, size_t __amount);
 
-#ifdef __OPTIMIZE__
+#if defined(__OPTIMIZE__) && (!defined(__clang__) || defined(ARGP_FS_EI))
 /* Inline versions of above routines.  */
 
 #if !_LIBC
