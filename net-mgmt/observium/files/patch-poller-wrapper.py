--- poller-wrapper.py.orig	2016-12-05 00:19:29 UTC
+++ poller-wrapper.py
@@ -45,6 +45,8 @@ except:
     print("threading, sys, subprocess, time, os, json")
     sys.exit(2)
 
+os.environ['PATH'] += ':%%LOCALBASE%%/sbin:%%LOCALBASE%%/bin'
+
 # start time
 s_time = time.time()
 
@@ -608,4 +610,4 @@ db.close()
 # Return exit code
 sys.exit(exit_code)
 
-# EOF
\ No newline at end of file
+# EOF
