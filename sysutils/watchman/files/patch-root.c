--- root.c.orig	2014-11-03 21:24:12 UTC
+++ root.c
@@ -1092,7 +1092,7 @@ void set_poison_state(w_root_t *root, st
 "All requests will continue to fail with this message until you resolve\n"
 "the underlying problem.  You will find more information on fixing this at\n"
 "https://facebook.github.io/watchman/docs/troubleshooting.html#poison-%s\n",
-    now.tv_sec,
+    (long)now.tv_sec,
     syscall,
     dir->path->len,
     dir->path->buf,
