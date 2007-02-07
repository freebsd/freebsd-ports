--- mpz/set_d.c.orig	Tue Mar 14 16:57:54 2006
+++ mpz/set_d.c	Wed Feb  7 07:56:31 2007
@@ -56,6 +56,9 @@
   if (ALLOC(r) < rn)
     _mpz_realloc (r, rn);
 
+  if (rn <= 0)
+    rn = 0;
+
   rp = PTR (r);
 
   switch (rn)
