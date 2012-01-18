--- ./m4/ax_python_devel.m4.orig	2012-01-02 17:23:11.000000000 +0100
+++ ./m4/ax_python_devel.m4	2012-01-02 17:23:13.000000000 +0100
@@ -178,7 +178,8 @@
 	if (e != None):
 		ret += e
 print (ret)
-EOD`
+EOD
+`
 
 		if test -z "$ac_python_version"; then
 			if test -n "$PYTHON_VERSION"; then
@@ -202,7 +203,8 @@
 	if e != None:
 		print (e)
 		break
-EOD`
+EOD
+`
 
 		# Before checking for libpythonX.Y, we need to know
 		# the extension the OS we're on uses for libraries
