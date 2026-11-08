--- bazel/foreign_cc/luajit.bzl.orig	2026-06-18 18:08:19 UTC
+++ bazel/foreign_cc/luajit.bzl
@@ -68,12 +68,16 @@ def _get_host_platform():
         host_os = "linux"
     elif "@platforms//os:osx" in HOST_CONSTRAINTS:
         host_os = "macos"
+    elif "@platforms//os:freebsd" in HOST_CONSTRAINTS:
+        host_os = "linux"  # FreeBSD uses the same LuaJIT build as Linux
     else:
         fail("unknown host platform: %s" % HOST_CONSTRAINTS)
 
     if "@platforms//cpu:x86_64" in HOST_CONSTRAINTS:
         host_arch = "x64"
     elif "@platforms//cpu:arm64" in HOST_CONSTRAINTS:
+        host_arch = "arm64"
+    elif "@platforms//cpu:aarch64" in HOST_CONSTRAINTS:
         host_arch = "arm64"
     else:
         fail("unknown host platform: %s" % HOST_CONSTRAINTS)
