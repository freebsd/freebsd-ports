
$FreeBSD$

--- pygmymailbox.py	2001/05/04 20:56:16	1.1
+++ pygmymailbox.py	2001/05/04 21:07:51
@@ -1,7 +1,7 @@
 ## $Id: pygmymailbox.py,v 1.1 2001/05/04 20:56:16 root Exp root $
 
 ## System Modules
-import mailbox
+import mailbox, rfc822
 
 
 ##
@@ -11,9 +11,10 @@
 ##
 class PygmyMailbox(mailbox.UnixMailbox):
     # Have to include the seek-start parameter here
-    def __init__(self, fp, start=0):
+    def __init__(self, fp, start=0, factory=rfc822.Message):
         self.fp = fp
         self.seekp = start
+	self.factory = factory
 
     # Current start index in file
     cur_start = 0
