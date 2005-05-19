--- getmailcore/message.py.orig	Wed May 18 09:28:26 2005
+++ getmailcore/message.py	Wed May 18 10:41:19 2005
@@ -12,6 +12,7 @@
 import cStringIO
 import email
 import email.Errors
+import email.Parser
 import email.Utils
 from email.Generator import Generator
 
@@ -79,7 +80,7 @@
         self.received_from = None
         self.received_with = None
         self.__raw = None
-        parser = email.Parser.HeaderParser(strict=False)
+        parser = email.Parser.HeaderParser()
         
         # Message is instantiated with fromlines for POP3, fromstring for
         # IMAP (both of which can be badly-corrupted or invalid, i.e. spam,
