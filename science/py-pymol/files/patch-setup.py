--- setup.py.orig	2018-07-24 16:14:37 UTC
+++ setup.py
@@ -54,6 +54,8 @@ try:
             "keyword support.")
     parser.add_argument('--help-distutils', action="store_true",
             help="show help for distutils options and exit")
+    parser.add_argument('--single-version-externally-managed', action="store_true",
+            help="single-version-externally-managed")
     options, sys.argv[1:] = parser.parse_known_args(namespace=options)
 except ImportError:
     print("argparse not available")
@@ -278,7 +280,6 @@ ext_comp_args = [
     # optimizations
     "-ffast-math",
     "-funroll-loops",
-    "-O3",
     "-fcommon",
 ]
 ext_link_args = []
