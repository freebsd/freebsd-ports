--- pexpect.py.orig	Mon Apr 26 14:16:08 2004
+++ pexpect.py	Mon Apr 26 14:19:45 2004
@@ -498,21 +498,24 @@ class spawn:
             pid, status = os.waitpid(self.pid, os.WNOHANG)
         except OSError:
             return 0
 
         # I have to do this twice for Solaris.
         # I can't even believe that I figured this out...
-        if pid == 0 and status == 0:
+
+        # If waitpid() returns 0 it means that no child process wishes to
+        # report, and the value of status is undefined.
+        if pid == 0:
             try:
                 pid, status = os.waitpid(self.pid, os.WNOHANG)
                 #print 'Solaris sucks'
             except OSError: # This is crufty. When does this happen?
                 return 0
             # If pid and status is still 0 after two calls to waitpid() then
             # the process really is alive. This seems to work on all platforms.
-            if pid == 0 and status == 0:
+            if pid == 0:
                 return 1
 
         # I do not OR this together because I want hooks for debugging.
         if os.WIFEXITED (status):
             self.exitstatus = os.WEXITSTATUS(status)
             return 0
