--- setup.py.orig	2019-02-12 06:00:47 UTC
+++ setup.py
@@ -52,6 +52,8 @@ try:
             "shared library; no: disable fast MMTF load support")
     parser.add_argument('--help-distutils', action="store_true",
             help="show help for distutils options and exit")
+    parser.add_argument('--single-version-externally-managed', action="store_true",
+            help="single-version-externally-managed")
     parser.add_argument('--testing', action="store_true",
             help="Build C-level tests")
     options, sys.argv[1:] = parser.parse_known_args(namespace=options)
