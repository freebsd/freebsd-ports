--- signon-oauth2.pro.orig	2018-03-03 17:00:59 UTC
+++ signon-oauth2.pro
@@ -3,7 +3,7 @@ include( common-project-config.pri )
 
 TEMPLATE  = subdirs
 CONFIG   += ordered
-SUBDIRS   = src tests example
+SUBDIRS   = src 
 
 include( common-installs-config.pri )
 
