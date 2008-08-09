--- ./src/src.pri.orig	2008-08-05 00:21:54.000000000 +0400
+++ ./src/src.pri	2008-08-09 00:11:30.000000000 +0400
@@ -14,8 +14,6 @@
 
 QT += webkit network
 
-GITVERSION=$$system(git log -n1 --pretty=format:%h)
-GITCHANGENUMBER=$$system(git log --pretty=format:%h | wc -l)
 DEFINES += GITVERSION=\"\\\"$$GITVERSION\\\"\"
 DEFINES += GITCHANGENUMBER=\"\\\"$$GITCHANGENUMBER\\\"\"
 
