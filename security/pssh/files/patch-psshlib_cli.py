--- psshlib/cli.py.orig
+++ psshlib/cli.py
@@ -6,7 +6,7 @@
 import shlex
 import sys
 import textwrap
-import version
+from psshlib import version
 
 _DEFAULT_PARALLELISM = 32
 _DEFAULT_TIMEOUT     = 0 # "infinity" by default
