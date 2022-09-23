--- third_party/remote_config/remote_platform_configure.bzl.orig	2022-08-28 06:50:48 UTC
+++ third_party/remote_config/remote_platform_configure.bzl
@@ -8,6 +8,8 @@ def _remote_platform_configure_impl(repository_ctx):
             platform = "windows"
         elif os.startswith("mac os"):
             platform = "osx"
+        elif os.startswith("freebsd"):
+            platform = "freebsd"
         else:
             platform = "linux"
 
@@ -50,6 +52,6 @@ remote_platform_configure = repository_rule(
     implementation = _remote_platform_configure_impl,
     attrs = {
         "platform_exec_properties": attr.string_dict(mandatory = True),
-        "platform": attr.string(default = "linux", values = ["linux", "windows", "local"]),
+        "platform": attr.string(default = "linux", values = ["linux", "windows", "freebsd", "local"]),
     },
 )
