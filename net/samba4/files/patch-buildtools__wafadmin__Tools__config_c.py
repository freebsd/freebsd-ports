--- buildtools/wafadmin/Tools/config_c.py.orig	2013-06-13 09:21:02.000000000 +0000
+++ buildtools/wafadmin/Tools/config_c.py	2014-03-27 11:46:02.381178536 +0000
@@ -73,6 +73,19 @@
 			app('CCFLAGS_' + uselib, x)
 			app('CXXFLAGS_' + uselib, x)
 			app('LINKFLAGS_' + uselib, x)
+		#
+		# NOTE on special treatment of -Wl,-R and -Wl,-rpath:
+		#
+		# It is important to not put a library provided RPATH
+		# into the LINKFLAGS but in the RPATH instead, since
+		# the provided LINKFLAGS get prepended to our own internal
+		# RPATH later, and hence can potentially lead to linking
+		# in too old versions of our internal libs.
+		#
+		elif x.startswith('-Wl,-R'):
+			app('RPATH_' + uselib, x[6:])
+		elif x.startswith('-Wl,-rpath,'):
+			app('RPATH_' + uselib, x[11:])
 		elif x.startswith('-Wl'):
 			app('LINKFLAGS_' + uselib, x)
 		elif x.startswith('-m') or x.startswith('-f'):
