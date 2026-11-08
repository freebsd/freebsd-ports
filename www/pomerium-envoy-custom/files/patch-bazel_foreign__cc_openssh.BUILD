--- bazel/foreign_cc/openssh.BUILD.orig	2026-06-18 18:08:19 UTC
+++ bazel/foreign_cc/openssh.BUILD
@@ -44,10 +44,16 @@ config_setting(
     constraint_values = ["@platforms//os:macos"],
 )
 
+config_setting(
+    name = "freebsd",
+    constraint_values = ["@platforms//os:freebsd"],
+)
+
 copy_file(
     name = "config_h",
     src = select({
         ":darwin": "@pomerium_envoy//bazel/foreign_cc/openssh/include/config_darwin:config.h",
+        ":freebsd": "@pomerium_envoy//bazel/foreign_cc/openssh/include/config_freebsd:config.h",
         "//conditions:default": "@pomerium_envoy//bazel/foreign_cc/openssh/include/config_linux:config.h",
     }),
     out = "config.h",
@@ -148,6 +154,7 @@ cc_library(
     ],
     linkopts = select({
         "@platforms//os:osx": ["-lresolv.9"],
+        ":freebsd": [],
         "//conditions:default": [
             "-lcrypt",
             "-lresolv",
