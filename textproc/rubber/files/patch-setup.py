--- setup.py.orig	Sat Jun 26 22:57:07 2004
+++ setup.py	Thu Jan 27 02:27:30 2005
@@ -103,10 +103,8 @@
 	from distutils.core import setup
 	try:
 		mandir = expand_vars(settings.sub, settings.sub["mandir"])
-		infodir = expand_vars(settings.sub, settings.sub["infodir"])
 	except NameError:
 		mandir = "man"
-		infodir = "info"
 	setup(
 		name = "rubber",
 		version = settings.sub["version"],
@@ -132,8 +130,7 @@
 		[(mandir + "/man1",
 			["doc/man-en/rubber.1", "doc/man-en/rubber-info.1", "doc/man-en/rubber-pipe.1"]),
 		 (mandir + "/fr/man1",
-			["doc/man-fr/rubber.1", "doc/man-fr/rubber-info.1", "doc/man-fr/rubber-pipe.1"]),
-		 (infodir, ["doc/rubber.info"])]
+			["doc/man-fr/rubber.1", "doc/man-fr/rubber-info.1", "doc/man-fr/rubber-pipe.1"])]
 		)
 
 
@@ -164,13 +161,11 @@
     the main script: %s
     the modules:     %s
     the man pages:   %s
-    the info pages:  %s
 (unless you specify otherwise when running `make install')""" %
 		(expand_vars(sub, sub["python"]),
 		 expand_vars(sub, sub["bindir"]),
 		 expand_vars(sub, sub["moddir"]),
-		 expand_vars(sub, sub["mandir"]),
-		 expand_vars(sub, sub["infodir"])))
+		 expand_vars(sub, sub["mandir"])))
 	elif cmd == "inst":
 		sub = settings.sub
 		sub["prefix"] = sys.argv[2]
