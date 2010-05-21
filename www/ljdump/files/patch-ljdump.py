--- ljdump.py.orig
+++ ljdump.py
@@ -1,4 +1,4 @@
-#!/usr/bin/python
+#!%%LOCALBASE%%/bin/python
 #
 # ljdump.py - livejournal archiver
 # Greg Hewgill <greg@hewgill.com> http://hewgill.com
@@ -24,7 +24,7 @@
 #
 # Copyright (c) 2005-2009 Greg Hewgill
 
-import codecs, md5, os, pickle, pprint, re, shutil, sys, urllib2, xml.dom.minidom, xmlrpclib
+import codecs, os, pickle, pprint, re, shutil, sys, urllib2, xml.dom.minidom, xmlrpclib
 from xml.sax import saxutils
 
 MimeExtensions = {
@@ -33,8 +33,14 @@
     "image/png": ".png",
 }
 
+try:
+    from hashlib import md5
+except ImportError:
+    import md5 as _md5
+    md5 = _md5.new
+
 def calcchallenge(challenge, password):
-    return md5.new(challenge+md5.new(password).hexdigest()).hexdigest()
+    return md5(challenge+md5(password).hexdigest()).hexdigest()
 
 def flatresponse(response):
     r = {}
@@ -157,7 +163,8 @@
         'getpickwurls': 1,
     }, Password))
     userpics = dict(zip(map(str, r['pickws']), r['pickwurls']))
-    userpics['*'] = r['defaultpicurl']
+    if r['defaultpicurl']:
+        userpics['*'] = r['defaultpicurl']
 
     while True:
         r = server.LJ.XMLRPC.syncitems(dochallenge(server, {
@@ -345,8 +352,12 @@
         print "%d errors" % errors
 
 if __name__ == "__main__":
-    if os.access("ljdump.config", os.F_OK):
-        config = xml.dom.minidom.parse("ljdump.config")
+    for file in [ "%%PREFIX%%/etc/ljdump.config", "ljdump.config", "/"]:
+        if os.access(file, os.F_OK):
+            break
+    if file != "/":
+        print "Using configuration file %s" % file
+        config = xml.dom.minidom.parse(file)
         server = config.documentElement.getElementsByTagName("server")[0].childNodes[0].data
         username = config.documentElement.getElementsByTagName("username")[0].childNodes[0].data
         password = config.documentElement.getElementsByTagName("password")[0].childNodes[0].data
