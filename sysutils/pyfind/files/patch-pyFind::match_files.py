
$FreeBSD$

--- pyFind/match_files.py.orig	Sat Mar 31 01:48:01 2001
+++ pyFind/match_files.py	Thu Apr  5 12:25:04 2001
@@ -97,6 +97,10 @@
     #pclsApp.clstFiles.freeze() 
     pclsApp.apbMain.set_progress(iProgress)
 
+    #search mounted volumes?
+    if not pbSearchMounted:
+         psSearchPath = '-x ' + psSearchPath
+
     #case sensitive file name search
     if pbCaseSensitive:
         sParam = ' -name "' #yes
@@ -126,10 +130,6 @@
     #output to command line
     sFindCmd = sFindCmd + ' -print'
     
-    #search mounted volumes?
-    if not pbSearchMounted:
-         sFindCmd = sFindCmd + ' -mount'
-
     #search contents?
     if pbSearchContents:       
         #case-sensitive contents
