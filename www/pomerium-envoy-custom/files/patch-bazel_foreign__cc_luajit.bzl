--- bazel/foreign_cc/luajit.bzl.orig	2026-06-18 18:08:19 UTC
+++ bazel/foreign_cc/luajit.bzl
@@ -68,6 +68,8 @@ def _get_host_platform():
         host_os = "linux"
     elif "@platforms//os:osx" in HOST_CONSTRAINTS:
         host_os = "macos"
+    elif "@platforms//os:freebsd" in HOST_CONSTRAINTS:
+        host_os = "linux"  # FreeBSD uses the same LuaJIT build as Linux
     else:
         fail("unknown host platform: %s" % HOST_CONSTRAINTS)
 
