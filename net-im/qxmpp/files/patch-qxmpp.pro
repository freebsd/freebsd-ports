--- qxmpp.pro.orig	2012-01-07 22:29:59.855639988 +0000
+++ qxmpp.pro	2012-01-07 22:30:28.846689409 +0000
@@ -3,8 +3,6 @@ include(qxmpp.pri)
 TEMPLATE = subdirs
 
 SUBDIRS = src \
-          tests \
-          examples \
           doc
 
 CONFIG += ordered
@@ -24,7 +22,7 @@ dist.depends = docs
 
 # Install rules
 htmldocs.files = doc/html
-htmldocs.path = $$[QT_INSTALL_PREFIX]/share/doc/qxmpp
+htmldocs.path = %%DOCSDIR%%
 htmldocs.CONFIG += no_check_exist directory
 
 QMAKE_EXTRA_TARGETS += dist docs
