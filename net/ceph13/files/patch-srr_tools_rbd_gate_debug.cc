diff --git a/src/tools/rbd_ggate/debug.cc b/src/tools/rbd_ggate/debug.cc
index 8cf912c3ece8..b675ba5b3cae 100644
--- src/tools/rbd_ggate/debug.cc
+++ src/tools/rbd_ggate/debug.cc
@@ -17,7 +17,7 @@ extern "C" void debugv(int level, const char *fmt, va_list ap) {
 
     vasprintf(&msg, fmt, ap);
 
-    dout(level) << msg << dendl;
+    dout(ceph::dout::need_dynamic(level)) << msg << dendl;
 
     free(msg);
     errno = saved_errno;
