--- comp.c.orig	Sun Sep 11 18:39:50 2005
+++ comp.c	Sun Sep 11 18:40:09 2005
@@ -40,15 +40,15 @@
   }
   
   *(void **)(&comp_compress) = dlsym(handle, "comp_compress");
-  if((error = dlerror()))  
+  if((error = (char *) dlerror()))  
     { strcpy(comp_error, error); return comp_error; }
   
   *(void **)(&comp_uncompress) = dlsym(handle, "comp_uncompress");
-  if((error = dlerror()))  
+  if((error = (char *) dlerror()))  
     { strcpy(comp_error, error); return comp_error; }
   
   *(void **)(&comp_free) = dlsym(handle, "comp_free");
-  if((error = dlerror()))  
+  if((error = (char *) dlerror()))  
     { strcpy(comp_error, error); return comp_error; }
   
   return 0;
