--- src/rmd_jack.c.orig	2007-07-18 13:43:52.000000000 +0800
+++ src/rmd_jack.c	2007-07-18 13:44:03.000000000 +0800
@@ -95,7 +95,7 @@
 }
 
 int LoadJackLib(void *jack_lib_handle){
-    char *error;
+    const char *error;
     jack_lib_handle=dlopen("libjack.so",RTLD_LAZY);
     if(!jack_lib_handle){
         fprintf(stderr,"%s\n",dlerror());
