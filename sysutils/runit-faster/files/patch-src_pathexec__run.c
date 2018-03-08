--- src/pathexec_run.c.orig	2014-08-10 18:22:35 UTC
+++ src/pathexec_run.c
@@ -5,6 +5,7 @@
 #include "str.h"
 #include "env.h"
 #include "pathexec.h"
+#include <unistd.h>
 
 static stralloc tmp;
 
@@ -15,7 +16,7 @@ void pathexec_run(const char *file,const char * const 
   int savederrno;
 
   if (file[str_chr(file,'/')]) {
-    execve(file,argv,envp);
+    execve(file,(char *const *)argv,(char *const *)envp);
     return;
   }
 
@@ -32,7 +33,7 @@ void pathexec_run(const char *file,const char * const 
     if (!stralloc_cats(&tmp,file)) return;
     if (!stralloc_0(&tmp)) return;
 
-    execve(tmp.s,argv,envp);
+    execve(tmp.s,(char *const *)argv,(char * const *)envp);
     if (errno != error_noent) {
       savederrno = errno;
       if ((errno != error_acces) && (errno != error_perm) && (errno != error_isdir)) return;
