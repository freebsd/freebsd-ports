From 6c9c611beed57f001ca3ae6b964518d9c7336a69 Mon Sep 17 00:00:00 2001
From: Alexandre Rostovtsev <tetromino@gentoo.org>
Date: Thu, 11 Jul 2013 03:00:54 +0000
Subject: python: fix drv_libxml2.py for python3 compatibility

https://bugzilla.gnome.org/show_bug.cgi?id=703979
---
diff --git a/python/drv_libxml2.py b/python/drv_libxml2.py
index e43fb1d..c9075e6 100644
--- python/drv_libxml2.py
+++ python/drv_libxml2.py
@@ -34,12 +34,20 @@ TODO
 
 """
 
-__author__  = u"Stéphane Bidoul <sbi@skynet.be>"
+__author__  = "Stéphane Bidoul <sbi@skynet.be>"
 __version__ = "0.3"
 
+import sys
 import codecs
-from types import StringType, UnicodeType
-StringTypes = (StringType,UnicodeType)
+
+if sys.version < "3":
+    __author__  = codecs.unicode_escape_decode(__author__)[0]
+
+    from types import StringType, UnicodeType
+    StringTypes = (StringType,UnicodeType)
+
+else:
+    StringTypes = (str)
 
 from xml.sax._exceptions import *
 from xml.sax import xmlreader, saxutils
@@ -65,7 +73,7 @@ def _d(s):
 
 try:
     import libxml2
-except ImportError, e:
+except ImportError as e:
     raise SAXReaderNotAvailable("libxml2 not available: " \
                                 "import error was: %s" % e)
 
--
cgit v0.9.2
