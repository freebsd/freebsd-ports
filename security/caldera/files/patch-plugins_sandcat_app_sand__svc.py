--- plugins/sandcat/app/sand_svc.py.orig	2022-07-20 19:48:00 UTC
+++ plugins/sandcat/app/sand_svc.py
@@ -56,7 +56,10 @@ class SandService(BaseService):
             ),
             linux=dict(
                 cflags='CGO_ENABLED=1'
-            )
+            ),
+            freebsd=dict(
+                cflags='CGO_ENABLED=1'
+            ),
         )
         if which('go') is not None:
             if platform in compile_options.keys():
