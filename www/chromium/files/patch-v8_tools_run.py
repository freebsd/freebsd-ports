--- v8/tools/run.py.orig	2022-02-07 13:39:41 UTC
+++ v8/tools/run.py
@@ -11,7 +11,7 @@ from __future__ import print_function
 import subprocess
 import sys
 
-result = subprocess.call(sys.argv[1:])
+sys.exit(subprocess.call(sys.argv[1:], env={"LD_LIBRARY_PATH":"${WRKSRC}/out/Release"}))
 if result != 0:
   # Windows error codes such as 0xC0000005 and 0xC0000409 are much easier
   # to recognize and differentiate in hex.
