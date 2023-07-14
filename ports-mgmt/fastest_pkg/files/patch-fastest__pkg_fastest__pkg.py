--- fastest_pkg/fastest_pkg.py.orig	2022-11-11 12:59:37 UTC
+++ fastest_pkg/fastest_pkg.py
@@ -146,7 +146,7 @@ def main():
         print(json.dumps(stats_sorted))
     else:
         pkg = PkgMirror(stats_sorted[0]["mirror_name"])
-        pkg_cfg = 'FreeBSD: { url: "http://%s/${ABI}/%s" }' % (
+        pkg_cfg = 'FreeBSD: { url: "http://%s/${ABI}/%s", mirror_type: "NONE" }' % (
             stats_sorted[0]["mirror_name"],
             pkg.release,
         )
