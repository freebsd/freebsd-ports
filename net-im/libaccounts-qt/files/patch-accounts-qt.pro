--- accounts-qt.pro.orig	2019-09-18 19:00:34 UTC
+++ accounts-qt.pro
@@ -2,10 +2,10 @@ include( common-vars.pri )
 
 TEMPLATE  = subdirs
 CONFIG   += ordered
-SUBDIRS  += Accounts tests
+SUBDIRS  += Accounts
 
 include( common-project-config.pri )
-include( doc/doc.pri )
+docs { include( doc/doc.pri ) }
 
 DISTNAME = $${PROJECT_NAME}-$${PROJECT_VERSION}
 EXCLUDES = \
