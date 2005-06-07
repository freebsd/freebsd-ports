--- src/main.py.orig	Tue Jun  7 09:54:58 2005
+++ src/main.py	Tue Jun  7 09:56:26 2005
@@ -1,3 +1,4 @@
+#!%%PYTHON_CMD%%
 # Copyright 2004 James Bunton <james@delx.cjb.net>
 # Licensed for distribution under the GPL version 2, check COPYING for details
 
@@ -13,15 +14,9 @@
 	print("You are using version %s of Python, at least 2.3 is required." % (sys.version[:3]))
 	os._exit(0)
 
-name = "PyICQt"
-exe = os.path.realpath(sys.executable)
-if (exe.find("python") >= 0):
-	print("Restarting with process name %s..." % (name))
-	os.execv(exe, [name, sys.argv[0]]+sys.argv[1:])
-
 import config
 import xmlconfig
-conffile = "config.xml"
+conffile = "%%PREFIX%%/etc/jabber-pyicq.xml"
 options = {}
 opts, args = getopt.getopt(sys.argv[1:], "c:o:dDl:h", ["config=", "option=", "debug", "Debug", "log=", "help"])
 for o, v in opts:
