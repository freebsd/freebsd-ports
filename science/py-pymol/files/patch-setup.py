--- setup.py.orig	2017-03-09 18:16:07 UTC
+++ setup.py
@@ -52,6 +52,8 @@ try:
             "keyword support.")
     parser.add_argument('--help-distutils', action="store_true",
             help="show help for distutils options and exit")
+    parser.add_argument('--single-version-externally-managed', action="store_true",
+            help="single-version-externally-managed")
     options, sys.argv[1:] = parser.parse_known_args(namespace=options)
 except ImportError:
     print("argparse not available")
@@ -318,8 +320,8 @@ else: # unix style (linux, mac, ...)
 
     # optimization currently causes a clang segfault on OS X 10.9 when
     # compiling layer2/RepCylBond.cpp
-    if sys.platform != 'darwin':
-        ext_comp_args += ["-O3"]
+    #if sys.platform != 'darwin':
+    #    ext_comp_args += ["-O3"]
 
 def get_pymol_version():
     return re.findall(r'_PyMOL_VERSION "(.*)"', open('layer0/Version.h').read())[0]
