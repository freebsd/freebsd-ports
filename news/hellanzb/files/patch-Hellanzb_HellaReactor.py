--- ./Hellanzb/HellaReactor.py.orig	2007-03-27 08:20:43.000000000 +0400
+++ ./Hellanzb/HellaReactor.py	2013-02-26 22:29:07.000000000 +0400
@@ -9,7 +9,11 @@
 import Hellanzb, sys, time
 
 import twisted.copyright
-if twisted.copyright.version >= '2.0.0':
+if twisted.copyright.version >= '11.1.0':
+    from twisted.internet.selectreactor import SelectReactor
+    from twisted.internet.posixbase import _NO_FILENO
+    from twisted.internet.posixbase import _NO_FILEDESC
+elif twisted.copyright.version >= '2.0.0' or twisted.copyright.version >= '10.0.0':
     from twisted.internet.selectreactor import SelectReactor
     from twisted.internet.selectreactor import _NO_FILENO
     from twisted.internet.selectreactor import _NO_FILEDESC
