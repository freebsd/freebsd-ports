--- azurelinuxagent/common/utils/textutil.py.orig	2024-08-20 23:23:16 UTC
+++ azurelinuxagent/common/utils/textutil.py
@@ -445,7 +445,7 @@ def format_exception(exception):
     if tb is None or (sys.version_info[0] == 2 and e != exception):
         msg += "[Traceback not available]"
     else:
-        msg += ''.join(traceback.format_exception(etype=type(exception), value=exception, tb=tb))
+        msg += ''.join(traceback.format_exception(type(exception), value=exception, tb=tb))
 
     return msg
 
