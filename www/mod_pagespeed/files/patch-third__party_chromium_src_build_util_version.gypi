--- third_party/chromium/src/build/util/version.gypi.orig	2017-10-06 23:59:53 UTC
+++ third_party/chromium/src/build/util/version.gypi
@@ -11,8 +11,8 @@
     'version_py_path': '<(version_py_path)',
     'version_path': '<(version_path)',
     'version_full':
-        '<!(python <(version_py_path) -f <(version_path) -t "@MAJOR@.@MINOR@.@BUILD@.@PATCH@")',
+        '<!(python2.7 <(version_py_path) -f <(version_path) -t "@MAJOR@.@MINOR@.@BUILD@.@PATCH@")',
     'version_mac_dylib':
-        '<!(python <(version_py_path) -f <(version_path) -t "@BUILD@.@PATCH_HI@.@PATCH_LO@" -e "PATCH_HI=int(PATCH)/256" -e "PATCH_LO=int(PATCH)%256")',
+        '<!(python2.7 <(version_py_path) -f <(version_path) -t "@BUILD@.@PATCH_HI@.@PATCH_LO@" -e "PATCH_HI=int(PATCH)/256" -e "PATCH_LO=int(PATCH)%256")',
   },  # variables
 }
