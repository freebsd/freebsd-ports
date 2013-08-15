--- ppl-1.0.p0/src/demos/ppl_lpsol/ppl_lpsol.c.orig	2013-06-20 17:21:39.000000000 +0000
+++ ppl-1.1pre9.p0/src/demos/ppl_lpsol/ppl_lpsol.c	2013-06-20 17:39:44.000000000 +0000
@@ -534,7 +534,7 @@
   if (getrlimit(RLIMIT_AS, &t) != 0)
     fatal("getrlimit failed: %s", strerror(errno));
 
-  if (bytes < t.rlim_cur) {
+  if (bytes < (unsigned long)(t.rlim_cur)) {
     t.rlim_cur = bytes;
     if (setrlimit(RLIMIT_AS, &t) != 0)
       fatal("setrlimit failed: %s", strerror(errno));
