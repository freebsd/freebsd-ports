--- src/shrpx.cc.orig	2015-01-25 09:01:44.000000000 -0500
+++ src/shrpx.cc	2015-02-09 17:51:30.000000000 -0500
@@ -1862,6 +1862,7 @@
 
   if (get_config()->rlimit_nofile) {
-    struct rlimit lim = {get_config()->rlimit_nofile,
-                         get_config()->rlimit_nofile};
+    struct rlimit lim;
+
+    lim.rlim_cur = lim.rlim_max = get_config()->rlimit_nofile;
     if (setrlimit(RLIMIT_NOFILE, &lim) != 0) {
       auto error = errno;
