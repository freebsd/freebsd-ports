--- src/c/urweb.c.orig	2014-07-04 15:32:47.000000000 +0200
+++ src/c/urweb.c	2014-12-19 01:22:02.000000000 +0100
@@ -4204,7 +4204,7 @@ uw_Basis_int uw_Basis_rand(uw_context ct
   pthread_mutex_unlock(&rand_mutex);
 
   if (r)
-    return abs(ret);
+    return llabs(ret);
   else
     uw_error(ctx, FATAL, "Random number generation failed");
 }
