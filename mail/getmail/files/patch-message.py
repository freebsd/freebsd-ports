--- getmailcore/message.py.orig	Mon Feb 21 15:57:08 2005
+++ getmailcore/message.py	Mon Feb 21 16:04:17 2005
@@ -7,6 +7,7 @@
     'Message',
 ]
 
+import sys
 import os
 import time
 import cStringIO
@@ -86,20 +87,28 @@
         # of filters, etc, which should be saner.
         if fromlines:
             try:
-                self.__msg = email.message_from_string(os.linesep.join(
-                    fromlines), strict=False)
+                if sys.version_info < (2, 4):
+                    self.__msg = email.message_from_string(os.linesep.join(fromlines), strict=False)
+                else:
+                    self.__msg = email.message_from_string(os.linesep.join(fromlines))
             except email.Errors.MessageError, o:
                 self.__msg = corrupt_message(o, fromlines=fromlines)
             self.__raw = os.linesep.join(fromlines)
         elif fromstring:
             try:
-                self.__msg = email.message_from_string(fromstring, strict=False)
+                if sys.version_info < (2, 4):
+                    self.__msg = email.message_from_string(fromstring, strict=False)
+                else:
+                    self.__msg = email.message_from_string(fromstring)
             except email.Errors.MessageError, o:
                 self.__msg = corrupt_message(o, fromstring=fromstring)
             self.__raw = fromstring
         elif fromfile:
             try:
-                self.__msg = email.message_from_file(fromfile, strict=False)
+                if sys.version_info < (2, 4):
+                    self.__msg = email.message_from_file(fromfile, strict=False)
+                else:
+                    self.__msg = email.message_from_file(fromfile)
             except email.Errors.MessageError, o:
                 # Shouldn't happen
                 self.__msg = corrupt_message(o, fromstring=fromfile.read())
