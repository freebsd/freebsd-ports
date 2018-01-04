--- poller-wrapper.py.orig	2017-12-02 14:04:45 UTC
+++ poller-wrapper.py
@@ -72,6 +72,8 @@ except:
     print("threading, sys, subprocess, os, json")
     sys.exit(2)
 
+os.environ['PATH'] += ':%%LOCALBASE%%/sbin:%%LOCALBASE%%/bin'
+
 """
     Register global exepthook for ability stop execute wrapper by Ctrl+C
     See: https://stackoverflow.com/questions/6598053/python-global-exception-handling
