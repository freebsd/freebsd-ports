
$FreeBSD$

--- btdownloadgui.py.orig	Sun Apr  4 23:40:03 2004
+++ btdownloadgui.py	Sun Apr  4 23:40:50 2004
@@ -48,7 +48,7 @@
 
 PROFILER = False
 
-basepath=os.path.abspath(os.path.dirname(os.path.realpath(sys.argv[0])))
+basepath="%%PREFIX%%/share/BitTornado"
 
 def hours(n):
     if n == -1:
