--- crypt/random_prime.C.orig	Tue Oct 14 23:24:18 2003
+++ crypt/random_prime.C	Tue Oct 14 22:59:32 2003
@@ -336,7 +336,7 @@
   bigint t1, t2;
   for (;;) {
     next_weak ();
-    if (!tmp || (fermat2_test (tmp, &t1, &t2) == 2 && tmp.probab_prime (iter)))
+    if (!tmp || (fermat2_test (tmp, &t1, &t2) && tmp.probab_prime (iter)))
       return tmp;
   }
 }
