--- annotations.py.orig	2016-02-10 10:11:37 UTC
+++ annotations.py
@@ -1,9 +1,13 @@
-#!/usr/bin/env python
+#!/usr/local/bin/python2.7
 import os
 import sys
 
 if __name__ == "__main__":
-    os.environ.setdefault("DJANGO_SETTINGS_MODULE", "annotator.settings.local")
+    if not os.environ.get("DJANGO_SETTINGS_MODULE"):
+        print "Please set DJANGO_SETTINGS_MODULE"
+        exit(-1)
+
+    sys.path.append("/usr/local/etc/annotations")
 
     from django.core.management import execute_from_command_line
 
