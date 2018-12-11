--- pitivi/check.py.orig	2018-09-05 09:38:24 UTC
+++ pitivi/check.py
@@ -25,6 +25,7 @@ Package maintainers should look at the bottom section 
 """
 import os
 import sys
+import numpy
 from gettext import gettext as _
 
 missing_soft_deps = {}
