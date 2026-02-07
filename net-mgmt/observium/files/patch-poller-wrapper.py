--- poller-wrapper.py.orig	2025-03-15 14:27:22 UTC
+++ poller-wrapper.py
@@ -63,6 +63,7 @@ except ImportError:
     print("threading, sys, subprocess, os, json, stat")
     sys.exit(2)
 
+os.environ['PATH'] += ':%%LOCALBASE%%/sbin:%%LOCALBASE%%/bin'
 
 def new_except_hook(exctype, value, traceback):
     """
