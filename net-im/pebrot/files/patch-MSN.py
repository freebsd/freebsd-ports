--- pypebrot/MSN.py.orig	2009-01-28 05:21:19.000000000 +0800
+++ pypebrot/MSN.py	2010-11-06 16:09:40.000000000 +0800
@@ -4,7 +4,7 @@
 import os
 import re
 import socket
-import md5
+import hashlib
 import urllib
 import select
 import errno
@@ -729,7 +729,7 @@
             self.send( 'CHG', '%s\r\n' % state )
 
     def challenge( self, msg ):
-        chunk= md5.new( msg.fields['hash']+ 'Q1P7W2E4J9R8U3S5' ).hexdigest()
+        chunk= hashlib.md5( msg.fields['hash']+ 'Q1P7W2E4J9R8U3S5' ).hexdigest()
         self.send( 'QRY', 'msmsgs@msnmsgr.com 32\r\n%s' % chunk )
 
     def ping( self ):
@@ -1107,7 +1107,7 @@
             elif ( msg.type == 'USR' ):
                 if msg.fields['type'] == 'MD5':
                     hash= msg.fields['arg2']
-                    chunk= md5.new( hash + self.passwd ).hexdigest()
+                    chunk= hashlib.md5( hash + self.passwd ).hexdigest()
                     self.send( 'USR', 'MD5 S %s\r\n' % chunk )
                 elif msg.fields['type'] == 'TWN': 
                     text= split(msg.st)[4]
