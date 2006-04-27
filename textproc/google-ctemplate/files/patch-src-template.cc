--- src/template.cc.orig	Mon Apr 24 22:43:36 2006
+++ src/template.cc	Wed Apr 26 15:13:22 2006
@@ -35,7 +35,7 @@
 
 // Needed for pthread_rwlock_*.  If it causes problems, you could take
 // it out, but then you'd have to unset HAVE_RWLOCK (at least on linux).
-#define _XOPEN_SOURCE 500   // needed to get the rwlock calls
+//#define _XOPEN_SOURCE 500   // needed to get the rwlock calls
 
 #include <assert.h>
 #include <stdlib.h>
