--- src/main.py.orig	Sat Feb 11 01:14:59 2006
+++ src/main.py	Thu Mar  2 17:01:07 2006
@@ -1,3 +1,4 @@
+#!%%PYTHON_CMD%%
 # Copyrigh 2004-2005 Daniel Henninger <jadestorm@nc.rr.com>
 # Licensed for distribution under the GPL version 2, check COPYING for details
 
@@ -34,7 +35,7 @@
 
 import config
 import xmlconfig
-conffile = "config.xml"
+conffile = "%%PREFIX%%/etc/jabber-pyicq.xml"
 options = {}
 daemonizeme = False
 opts, args = getopt.getopt(sys.argv[1:], "bc:o:dDgtl:h", ["background", "config=", "option=", "debug", "Debug", "garbage", "traceback", "log=", "help"])
