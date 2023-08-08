--- src/launch.py.orig	2022-12-08 21:31:12 UTC
+++ src/launch.py
@@ -114,7 +114,7 @@ def main():
         '(requires Qt 5.11+)')
     parser.add_argument(
         '-b', '--web-backend', action='store',
-        choices=['auto', 'webkit', 'webengine'], default='auto',
+        choices=['auto', 'webkit', 'webengine'], default='webkit',
         help="Web backend to use for Timeline")
     parser.add_argument(
         '-d', '--debug', action='store_true',
