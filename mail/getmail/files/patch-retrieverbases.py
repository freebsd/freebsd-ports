--- getmailcore/_retrieverbases.py.orig	Mon Feb 21 15:57:08 2005
+++ getmailcore/_retrieverbases.py	Mon Feb 21 15:59:11 2005
@@ -33,6 +33,7 @@
     'RetrieverSkeleton',
 ]
 
+import sys
 import os
 import socket
 import time
@@ -445,7 +446,11 @@
         self.log.trace()
         msgnum = self._getmsgnumbyid(msgid)
         response, headerlist, octets = self.conn.top(msgnum, 0)
-        parser = email.Parser.Parser(strict=False)
+        # 'strict' argument is deprecated in Python 2.4
+        if sys.version_info < (2, 4):
+            parser = email.Parser.Parser(strict=False)
+        else:
+            parser = email.Parser.Parser()
         return parser.parsestr(os.linesep.join(headerlist), headersonly=True)
 
     def initialize(self):
