-- Teach the wheel platform tags about FreeBSD. Not supported upstream.
--- jaxlib/jax.bzl.orig	2026-10-20 13:31:57 UTC
+++ jaxlib/jax.bzl
@@ -79,6 +79,8 @@ PLATFORM_TAGS_DICT = {
     ("Darwin", "x86_64"): ("macosx_11_0", "x86_64"),
     ("Darwin", "arm64"): ("macosx_11_0", "arm64"),
     ("Windows", "AMD64"): ("win", "amd64"),
+    ("FreeBSD", "x86_64"): ("freebsd", "amd64"),
+    ("FreeBSD", "aarch64"): ("freebsd", "aarch64"),
 }
 
 _py_deps = {
@@ -633,6 +635,7 @@ def jax_wheel(
             "@platforms//os:macos": "Darwin",
             "@platforms//os:windows": "Windows",
             "@platforms//os:linux": "Linux",
+            "@platforms//os:freebsd": "FreeBSD",
         }),
         # TODO(kanglan) Add @platforms//cpu:ppc64le once JAX Bazel is upgraded > 6.5.0.
         cpu = select({
@@ -641,6 +644,8 @@ def jax_wheel(
             Label("//jaxlib/tools:win_amd64"): "AMD64",
             Label("//jaxlib/tools:linux_aarch64"): "aarch64",
             Label("//jaxlib/tools:linux_x86_64"): "x86_64",
+            Label("//jaxlib/tools:freebsd_aarch64"): "aarch64",
+            Label("//jaxlib/tools:freebsd_x86_64"): "x86_64",
         }),
         source_files = source_files,
     )
