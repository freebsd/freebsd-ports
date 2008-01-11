--- ljdump.py.orig	2006-09-08 15:49:11.000000000 +0700
+++ ljdump.py	2008-01-12 03:30:50.000000000 +0600
@@ -1,4 +1,4 @@
-#!/usr/bin/python
+#!%%LOCALBASE%%/bin/python
 #
 # ljdump.py - livejournal archiver
 # Greg Hewgill <greg@hewgill.com> http://hewgill.com
@@ -113,7 +113,14 @@
         return ""
     return e[0].firstChild.nodeValue
 
-config = xml.dom.minidom.parse("ljdump.config")
+for file in [ "%%PREFIX%%/etc/ljdump.config", "ljdump.config", "/"]:
+    if os.access(file, os.R_OK):
+        break
+if file == "/":
+    print "Neither global (in %%PREFIX%%/etc) nor local configuration file found, exiting"
+    sys.exit()
+print "Using configuration file %s" % file
+config = xml.dom.minidom.parse(file)
 Server = config.documentElement.getElementsByTagName("server")[0].childNodes[0].data
 Username = config.documentElement.getElementsByTagName("username")[0].childNodes[0].data
 Password = config.documentElement.getElementsByTagName("password")[0].childNodes[0].data
