--- src/plugins/wordleaker/wordextractor.cc.orig	Fri Mar 17 09:11:34 2006
+++ src/plugins/wordleaker/wordextractor.cc	Fri Mar 17 09:16:55 2006
@@ -84,7 +84,10 @@
 		      &t))
       return NULL;
       
-    return strndup(f, 128);
+    // in case strftime() (very old libc (4.4.1)) has returned 128 and 
+    // left undefined bulk in f
+    f[sizeof(f) - 1] = '\0';
+    return strdup(f);
   }
   
   static const char * idToProduct( unsigned int id ) {
