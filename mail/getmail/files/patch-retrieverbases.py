--- getmailcore/_retrieverbases.py.orig	Wed May 18 09:31:20 2005
+++ getmailcore/_retrieverbases.py	Wed May 18 10:41:09 2005
@@ -445,7 +446,7 @@
         self.log.trace()
         msgnum = self._getmsgnumbyid(msgid)
         response, headerlist, octets = self.conn.top(msgnum, 0)
-        parser = email.Parser.HeaderParser(strict=False)
+        parser = email.Parser.HeaderParser()
         return parser.parsestr(os.linesep.join(headerlist))
 
     def initialize(self):
