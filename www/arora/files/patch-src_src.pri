--- src.pri.orig	2009-01-19 15:05:40.000000000 +1300
+++ src/src.pri	2009-01-19 15:05:49.000000000 +1300
@@ -19,9 +19,7 @@
     DEFINES += GITCHANGENUMBER=0
 }
 !win32 {
-    GITVERSION=$$system(git log -n1 --pretty=format:%h)
     DEFINES += GITVERSION=\"\\\"$$GITVERSION\\\"\"
-    GITCHANGENUMBER=$$system(git log --pretty=format:%h | wc -l)
     DEFINES += GITCHANGENUMBER=\"\\\"$$GITCHANGENUMBER\\\"\"
 }
 
