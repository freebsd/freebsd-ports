--- setup.py.orig	2008-04-13 18:36:56.000000000 +0200
+++ setup.py	2012-09-09 17:11:39.000000000 +0200
@@ -137,7 +137,9 @@
 	try:
 		session_dirs = ['/etc/X11/sessions', '/etc/dm/Sessions',
 				'/etc/X11/dm/Sessions', '/usr/share/xsessions',
-				'/opt/kde3/share/apps/kdm/sessions']
+				'/opt/kde3/share/apps/kdm/sessions',
+				'/usr/local/share/applications',
+				'/usr/local/etc/dm/Sessions']
 		# TODO: more guesses about where KDE is installed, /opt/kde3
 		# works for SuSE 9.2
 		for d in session_dirs:
