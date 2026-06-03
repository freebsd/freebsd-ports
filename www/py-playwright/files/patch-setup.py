--- setup.py.orig	2025-08-28 09:27:29 UTC
+++ setup.py
@@ -74,6 +74,16 @@ base_wheel_bundles = [
     },
 ]
 
+# override for FreeBSD: use the Linux one and update the node binary in it
+base_wheel_bundles = [
+    {
+        "wheel": "manylinux1_x86_64.whl",
+        "machine": platform.machine().lower(),
+        "platform": sys.platform,
+        "zip_name": "linux",
+    }
+]
+
 if len(sys.argv) == 2 and sys.argv[1] == "--list-wheels":
     for bundle in base_wheel_bundles:
         print(bundle["wheel"])
@@ -108,7 +118,7 @@ def download_driver(zip_name: str) -> None:
         or "-beta" in driver_version
         or "-next" in driver_version
     ):
-        url = url + "next/"
+        pass  # do not alter the URL
     url = url + zip_file
     temp_destination_path = destination_path + ".tmp"
     print(f"Fetching {url}")
