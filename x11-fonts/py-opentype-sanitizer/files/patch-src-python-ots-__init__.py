--- src/python/ots/__init__.py.orig	2019-10-09 09:44:36 UTC
+++ src/python/ots/__init__.py
@@ -3,7 +3,7 @@ import subprocess
 import sys
 import os
 
-OTS_SANITIZE = os.path.join(os.path.dirname(__file__), "ots-sanitize")
+OTS_SANITIZE = "%%LOCALBASE%%/bin/ots-sanitize"
 
 __all__ = ["sanitize", "OTSError", "CalledProcessError"]
 
