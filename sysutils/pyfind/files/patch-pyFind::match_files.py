
$FreeBSD$

--- pyFind/match_files.py.orig	Tue Apr 17 18:00:00 2001
+++ pyFind/match_files.py	Wed Apr 18 21:56:29 2001
@@ -113,6 +113,10 @@
     #pclsApp.clstFiles.freeze() 
     pclsApp.apbMain.set_progress(iProgress)
 
+    #search mounted volumes?
+    if not pbSearchMounted:
+         psSearchPath = '-x ' + psSearchPath
+
     #case sensitive file name search
     if pbCaseSensitive:
         sParam = ' -name "' #yes
@@ -142,10 +146,6 @@
     #output to command line
     sFindCmd = sFindCmd + " -print"
     
-    #search mounted volumes?
-    if not pbSearchMounted:
-         sFindCmd = sFindCmd + " -mount"
-
     #search contents?
     if pbSearchContents:       
         #case-sensitive contents
