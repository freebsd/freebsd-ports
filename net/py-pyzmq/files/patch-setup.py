--- setup.py.orig	2019-02-19 12:38:50 UTC
+++ setup.py
@@ -1,4 +1,6 @@
 #!/usr/bin/env python
+# -*- coding: utf-8 -*-
+#
 #-----------------------------------------------------------------------------
 #  Copyright (C) PyZMQ Developers
 #  Distributed under the terms of the Modified BSD License.
@@ -24,6 +26,7 @@ import sys
 import time
 import errno
 import platform
+import codecs
 from traceback import print_exc
 
 # whether any kind of bdist is happening
@@ -1236,8 +1239,7 @@ def find_packages():
 #-----------------------------------------------------------------------------
 # Main setup
 #-----------------------------------------------------------------------------
-
-with open("README.md") as f:
+with codecs.open('README.md', 'r', 'utf-8') as f:
     long_desc = f.read()
 
 setup_args = dict(
