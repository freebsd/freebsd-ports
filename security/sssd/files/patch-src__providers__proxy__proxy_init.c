--- ./src/providers/proxy/proxy_init.c.orig	2011-08-29 11:39:05.000000000 -0400
+++ ./src/providers/proxy/proxy_init.c	2011-10-13 12:15:03.000000000 -0400
@@ -124,7 +124,7 @@
     if (!ctx->handle) {
         DEBUG(0, ("Unable to load %s module with path, error: %s\n",
                   libpath, dlerror()));
-        ret = ELIBACC;
+        ret = ENOENT;
         goto done;
     }
 
@@ -132,7 +132,7 @@
                                       libname);
     if (!ctx->ops.getpwnam_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
@@ -140,14 +140,14 @@
                                       libname);
     if (!ctx->ops.getpwuid_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
     ctx->ops.setpwent = proxy_dlsym(ctx->handle, "_nss_%s_setpwent", libname);
     if (!ctx->ops.setpwent) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
@@ -155,14 +155,14 @@
                                       libname);
     if (!ctx->ops.getpwent_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
     ctx->ops.endpwent = proxy_dlsym(ctx->handle, "_nss_%s_endpwent", libname);
     if (!ctx->ops.endpwent) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
@@ -170,7 +170,7 @@
                                       libname);
     if (!ctx->ops.getgrnam_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
@@ -178,14 +178,14 @@
                                       libname);
     if (!ctx->ops.getgrgid_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
     ctx->ops.setgrent = proxy_dlsym(ctx->handle, "_nss_%s_setgrent", libname);
     if (!ctx->ops.setgrent) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
@@ -193,14 +193,14 @@
                                       libname);
     if (!ctx->ops.getgrent_r) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
     ctx->ops.endgrent = proxy_dlsym(ctx->handle, "_nss_%s_endgrent", libname);
     if (!ctx->ops.endgrent) {
         DEBUG(0, ("Failed to load NSS fns, error: %s\n", dlerror()));
-        ret = ELIBBAD;
+        ret = ENOENT;
         goto done;
     }
 
