Fix compiler errors due to void pointer in stdio macros

Cast the `priv` void pointer to `FILE *` before passing it to `feof()`,
`clearerr()` and GAVL_FSEEK()`.

On platforms where standard I/O operations are implemented as macros
(such as FreeBSD), these macros directly dereference the underlying
struct members (e.g., `(p)->_flags`). Passing a `void *` directly to
them triggers a compilation failure: "member reference base type 'void'
is not a structure or union".

io_stdio.c:67:6: error: member reference base type 'void' is not a structure or union
   67 |   if(feof(priv))
      |      ^~~~~~~~~~
/usr/include/stdio.h:505:35: note: expanded from macro 'feof'
  505 | #define feof(p)         (!__isthreaded ? __sfeof(p) : (feof)(p))
      |                                          ^~~~~~~~~~
/usr/include/stdio.h:499:25: note: expanded from macro '__sfeof'
  499 | #define __sfeof(p)      (((p)->_flags & __SEOF) != 0)
      |                           ~~~^ ~~~~~~
io_stdio.c:68:5: error: member reference base type 'void' is not a structure or union
   68 |     clearerr(priv);
      |     ^~~~~~~~~~~~~~
/usr/include/stdio.h:507:38: note: expanded from macro 'clearerr'
  507 | #define clearerr(p)     (!__isthreaded ? __sclearerr(p) : (clearerr)(p))
      |                                          ^~~~~~~~~~~~~~
/usr/include/stdio.h:501:35: note: expanded from macro '__sclearerr'
  501 | #define __sclearerr(p)  ((void)((p)->_flags &= ~(__SERR|__SEOF)))
      |                                 ~~~^ ~~~~~~

--- gavl/io_stdio.c.orig	2025-04-18 11:16:35 UTC
+++ gavl/io_stdio.c
@@ -64,11 +64,13 @@ static int64_t seek_file(void * priv, int64_t pos, int
 
 static int64_t seek_file(void * priv, int64_t pos, int whence)
   {
-  if(feof(priv))
-    clearerr(priv);
-  
-  GAVL_FSEEK(priv, pos, whence);
-  return GAVL_FTELL(priv);
+  FILE * f = priv;
+
+  if(feof(f))
+    clearerr(f);
+
+  GAVL_FSEEK(f, pos, whence);
+  return GAVL_FTELL(f);
   }
 
 static int flush_file(void * priv)
