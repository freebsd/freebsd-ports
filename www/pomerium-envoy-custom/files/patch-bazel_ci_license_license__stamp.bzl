--- bazel/ci/license/license_stamp.bzl.orig	2026-11-06 05:18:29 UTC
+++ bazel/ci/license/license_stamp.bzl
@@ -4,6 +4,7 @@ _src_templates = {
 _src_templates = {
     "linux": r'__attribute__((used, retain, section(".license"), aligned(1))) static const char pomerium_license_name[] = %r;',
     "darwin": r'__attribute__((used, retain, section("__TEXT,__license"), aligned(1))) static const char pomerium_license_name[] = %r;',
+    "freebsd": r'__attribute__((used, retain, section(".license"), aligned(1))) static const char pomerium_license_name[] = %r;',
 }
 
 def _license_stamp_src_impl(ctx):
@@ -33,6 +34,7 @@ def cc_license_stamp_lib(name, license_name, visibilit
         os = select({
             "@platforms//os:linux": "linux",
             "@platforms//os:macos": "darwin",
+            "@platforms//os:freebsd": "freebsd",
         }),
     )
     cc_library(
