--- src/launch.py.orig	2021-08-24 18:04:45 UTC
+++ src/launch.py
@@ -109,7 +109,7 @@ def main():
         '(requires Qt 5.11+)')
     parser.add_argument(
         '-b', '--web-backend', action='store',
-        choices=['auto', 'webkit', 'webengine'], default='auto',
+        choices=['auto', 'webkit', 'webengine'], default='webkit',
         help="Web backend to use for Timeline")
     parser.add_argument(
         '-d', '--debug', action='store_true',
