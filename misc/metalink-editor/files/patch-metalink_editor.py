--- metalink_editor.py.orig	2009-04-28 08:57:40.000000000 -0300
+++ metalink_editor.py	2009-04-28 08:58:27.000000000 -0300
@@ -18,7 +18,8 @@
 
 import wxversion
 wxversion.ensureMinimal("2.6")
-import wx, metalink, sys, os.path
+import wx, sys, os.path
+from Metalink_editor import metalink
 
 current_version = "1.2.0"
 
@@ -28,7 +29,7 @@
 
 # Just a simple hack... (used to locate the icon)
 try:
-    data_path = os.path.dirname(sys.argv[0])
+    data_path = os.path.dirname("%%DATADIR%%/metalink_small.png")
     if data_path != "" and data_path != ".":
         print "Data path:", data_path
 except:
