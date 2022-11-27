--- setup.py.orig	2021-05-10 18:38:37 UTC
+++ setup.py
@@ -53,6 +53,8 @@ try:
             "shared library; no: disable fast MMTF load support")
     parser.add_argument('--help-distutils', action="store_true",
             help="show help for distutils options and exit")
+    parser.add_argument('--single-version-externally-managed', action="store_true",
+            help="single-version-externally-managed")
     parser.add_argument('--testing', action="store_true",
             help="Build C-level tests")
     parser.add_argument('--openvr', dest='openvr', action='store_true')
@@ -282,7 +284,7 @@ if DEBUG and not WIN:
 libs = ["png", "freetype"]
 lib_dirs = []
 ext_comp_args = [
-    "-Werror=return-type",
+    #"-Werror=return-type",
     "-Wunused-variable",
     "-Wno-switch",
     "-Wno-narrowing",
