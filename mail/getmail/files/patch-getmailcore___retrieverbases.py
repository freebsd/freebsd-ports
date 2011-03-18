--- ./getmailcore/_retrieverbases.py.orig	2010-06-29 18:03:42.000000000 +0200
+++ ./getmailcore/_retrieverbases.py	2011-03-18 00:25:54.000000000 +0100
@@ -898,11 +898,11 @@
 
     def _getmsgbyid(self, msgid):
         self.log.trace()
-        return self._getmsgpartbyid(msgid, '(RFC822)')
+        return self._getmsgpartbyid(msgid, '(BODY.PEEK[])')
 
     def _getheaderbyid(self, msgid):
         self.log.trace()
-        return self._getmsgpartbyid(msgid, '(RFC822[header])')
+        return self._getmsgpartbyid(msgid, '(BODY.PEEK[header])')
 
     def initialize(self):
         self.log.trace()
