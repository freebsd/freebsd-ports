--- psshlib/manager.py.orig
+++ psshlib/manager.py
@@ -2,6 +2,7 @@
 
 from errno import EINTR
 import os
+import fcntl
 import select
 import signal
 import sys
@@ -209,6 +210,7 @@
 
         # Setup the wakeup file descriptor to avoid hanging on lost signals.
         wakeup_readfd, wakeup_writefd = os.pipe()
+        fcntl.fcntl(wakeup_writefd, fcntl.F_SETFL, os.O_NONBLOCK)
         self.register_read(wakeup_readfd, self.wakeup_handler)
         # TODO: remove test when we stop supporting Python <2.5
         if hasattr(signal, 'set_wakeup_fd'):
