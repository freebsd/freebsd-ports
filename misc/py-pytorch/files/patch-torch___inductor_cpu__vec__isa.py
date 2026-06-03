--- torch/_inductor/cpu_vec_isa.py.orig	2026-04-18 06:29:09 UTC
+++ torch/_inductor/cpu_vec_isa.py
@@ -438,7 +438,7 @@ def x86_isa_checker() -> list[str]:
     """
     Arch value is x86_64 on Linux, and the value is AMD64 on Windows.
     """
-    if Arch != "x86_64" and Arch != "AMD64":
+    if Arch != "x86_64" and Arch != "AMD64" and Arch != "amd64":
         return supported_isa
 
     avx2 = torch.cpu._is_avx2_supported()
@@ -504,7 +504,9 @@ def valid_vec_isa_list() -> list[VecISA]:
     if sys.platform == "darwin" and platform.processor() == "arm":
         isa_list.append(VecNEON())
 
-    if sys.platform not in ["linux", "win32"]:
+    if sys.platform not in ["linux", "win32"] and not sys.platform.startswith(
+        "freebsd"
+    ):
         return isa_list
 
     arch = platform.machine()
@@ -529,7 +531,7 @@ def valid_vec_isa_list() -> list[VecISA]:
         else:
             isa_list.append(VecNEON())
 
-    elif arch in ["x86_64", "AMD64"]:
+    elif arch in ["x86_64", "AMD64", "amd64"]:
         """
         arch value is x86_64 on Linux, and the value is AMD64 on Windows.
         """
