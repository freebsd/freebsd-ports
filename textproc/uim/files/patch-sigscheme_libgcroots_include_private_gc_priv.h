--- sigscheme/libgcroots/include/private/gc_priv.h.orig	2020-08-25 09:13:47 UTC
+++ sigscheme/libgcroots/include/private/gc_priv.h
@@ -1979,7 +1979,7 @@ void GC_err_puts(const char *s);
   /* the signal mask.						*/
 # define SETJMP(env) sigsetjmp(env, 1)
 # define LONGJMP(env, val) siglongjmp(env, val)
-# define JMP_BUF sigjmp_buf
+# define JMP_BUF extern sigjmp_buf
 #else
 # ifdef ECOS
 #   define SETJMP(env)  hal_setjmp(env)
