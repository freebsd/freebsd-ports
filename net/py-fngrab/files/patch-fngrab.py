--- fngrab.py.orig	Sun Mar 24 14:14:24 2002
+++ fngrab.py	Sun Mar 24 14:14:38 2002
@@ -14,10 +14,10 @@
 import os, socket, sys, string, time, threading
 
 # Custom stuff:
-#from FreenetGrab import cmdline
-#from FreenetGrab import xmlrpclib
-import cmdline
-from xmlrpclib import *
+from FreenetGrab import cmdline
+from FreenetGrab import xmlrpclib
+#import cmdline
+#from xmlrpclib import *
 
 TRANSFERRING=0
 DONE=1
