--- src/template_dictionary.cc.orig	Wed Apr 26 15:14:17 2006
+++ src/template_dictionary.cc	Wed Apr 26 15:14:26 2006
@@ -36,7 +36,7 @@
 
 // Needed for pthread_rwlock_*.  If it causes problems, you could take
 // it out, but then you'd have to unset HAVE_RWLOCK (at least on linux).
-#define _XOPEN_SOURCE 500       // needed to get the rwlock calls
+//#define _XOPEN_SOURCE 500       // needed to get the rwlock calls
 
 #include <assert.h>
 #include <stdlib.h>
