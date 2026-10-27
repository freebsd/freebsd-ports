Description: Do not install the source tree's VERSION file as data_files
  into ${PREFIX}/output_dir/: nothing reads it there.  setup.py's
  version() reads VERSION from the source tree at build time, and zkg
  reports zeekpkg.__version__.
Issue ID: https://github.com/zeek/package-manager/pull/256
Changeset: none
TODO: Drop once a release includes it.

--- setup.py.orig	2026-08-25 16:14:47 UTC
+++ setup.py
@@ -9,7 +9,4 @@ def version() -> str:
 
 setup(
     version=version(),
-    data_files=[
-        ("output_dir", ["VERSION"]),
-    ],
 )
