--- dbuild/ci_test.py.orig	2026-03-07 16:44:08 UTC
+++ dbuild/ci_test.py
@@ -97,6 +97,7 @@ def _check_ocijail_annotation(annotation: str, base_im
         *podman._priv_prefix(),
         "podman", "run", "--rm",
         "--annotation", f"{annotation}=true",
+        "--entrypoint", "",
         base_image,
         "/bin/echo", "ok",
     ]
