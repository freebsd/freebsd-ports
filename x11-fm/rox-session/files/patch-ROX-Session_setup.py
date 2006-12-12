
$FreeBSD$

--- ROX-Session/setup.py.orig
+++ ROX-Session/setup.py
@@ -126,7 +126,8 @@
 	try:
 		session_dirs = ['/etc/X11/sessions', '/etc/dm/Sessions',
 				'/etc/X11/dm/Sessions', '/usr/share/xsessions',
-				'/opt/kde3/share/apps/kdm/sessions']
+				'/opt/kde3/share/apps/kdm/sessions',
+				'/usr/local/etc/dm/Sessions']
 		# TODO: more guesses about where KDE is installed, /opt/kde3
 		# works for SuSE 9.2
 		for d in session_dirs:
