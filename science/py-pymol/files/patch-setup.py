--- setup.py.orig	2024-04-09 16:59:46 UTC
+++ setup.py
@@ -60,6 +60,8 @@ parser.add_argument('--help-distutils', action="store_
                     "shared library; no: disable fast MMTF load support")
 parser.add_argument('--help-distutils', action="store_true",
                     help="show help for distutils options and exit")
+parser.add_argument('--single-version-externally-managed', action="store_true",
+                    help="single-version-externally-managed")
 parser.add_argument('--testing', action="store_true",
                     help="Build C-level tests")
 parser.add_argument('--openvr', dest='openvr', action='store_true')
@@ -295,7 +297,7 @@ ext_comp_args = [
 libs = ["png", "freetype"]
 lib_dirs = []
 ext_comp_args = [
-    "-Werror=return-type",
+    #"-Werror=return-type",
     "-Wunused-variable",
     "-Wno-switch",
     "-Wno-narrowing",
