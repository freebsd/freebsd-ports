--- signon-oauth2.pro.orig	2020-11-10 19:43:33 UTC
+++ signon-oauth2.pro
@@ -3,7 +3,7 @@ include( common-project-config.pri )
 
 TEMPLATE  = subdirs
 CONFIG   += ordered
-SUBDIRS   = src tests
+SUBDIRS   = src
 
 CONFIG(make_examples) {
     SUBDIRS += example
