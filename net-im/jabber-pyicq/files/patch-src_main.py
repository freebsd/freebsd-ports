--- src/main.py.orig	Mon Mar  6 21:58:50 2006
+++ src/main.py	Mon Mar 20 13:34:50 2006
@@ -1,3 +1,4 @@
+#!%%PYTHON_CMD%%
 # Copyrigh 2004-2006 Daniel Henninger <jadestorm@nc.rr.com>
 # Licensed for distribution under the GPL version 2, check COPYING for details
 
@@ -25,7 +26,7 @@
 
 import config
 import xmlconfig
-conffile = "config.xml"
+conffile = "%%PREFIX%%/etc/jabber-pyicq.xml"
 profilelog = None
 options = {}
 daemonizeme = False
