--- cdist/argparse.py.orig	2026-09-08 01:30:51 UTC
+++ cdist/argparse.py
@@ -472,9 +472,6 @@ def get_parsers():
     parser['info'].set_defaults(func=cdist.info.Info.commandline)
 
     # Scan = config + further
-    parser['scan'] = parser['sub'].add_parser('scan', add_help=False,
-                                              parents=[parser['config']])
-
     parser['scan'] = parser['sub'].add_parser(
             'scan', parents=[parser['loglevel'],
                              parser['beta'],
