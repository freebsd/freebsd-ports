--- src/my_glade.c.orig	Sat May 10 23:43:23 2003
+++ src/my_glade.c	Sat May 10 23:45:47 2003
@@ -39,7 +39,7 @@
 
   fun = dlsym(handle, new_symbol);
   error = dlerror();
-  if(error != NULL) {
+  if(fun == NULL) {
     fprintf(stderr, "Error during dlsym of %s: %s\n", new_symbol, error);
     gtk_exit(1);
   }
