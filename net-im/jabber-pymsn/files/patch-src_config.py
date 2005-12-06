--- src/config.py.orig	Mon Dec  5 16:43:57 2005
+++ src/config.py	Mon Dec  5 16:45:18 2005
@@ -1,11 +1,12 @@
 # This file contains the default settings for various options.
 # Please edit config.xml instead of this file
 
-configFile = "config.xml"
+configFile = "%%PREFIX%%/etc/jabber-pymsn.xml"
 
 jid = "msn"
 compjid = ""
-spooldir = ""
+spooldir = "/tmp/jabber-pymsn"
+pid = "/var/jabberd/pid/pymsn.pid"
 
 mainServer = "127.0.0.1"
 mainServerJID = ""
