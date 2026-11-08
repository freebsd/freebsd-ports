--- source/init_rsrc.c.orig	2026-10-17 00:01:03 UTC
+++ source/init_rsrc.c
@@ -28,7 +28,7 @@
 
 #include <stdio.h>
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #include <unistd.h>
 #include <sys/types.h>
 #elif _WIN32
@@ -117,7 +117,7 @@ int main(int argc, char *argv[])
   ni_retcode_t retval = ni_rsrc_init(should_match_rev, timeout_seconds);
   ni_host_ts_set();
   return retval;
-#elif __APPLE__
+#elif __APPLE__ || __FreeBSD__
   return ni_rsrc_init(should_match_rev, timeout_seconds);
 #elif _WIN32
   ni_retcode_t retval = ni_rsrc_init(should_match_rev, timeout_seconds);
