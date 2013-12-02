--- src/src.pro.orig	2013-06-16 11:57:51.000000000 +0200
+++ src/src.pro	2013-12-01 14:55:10.313369943 +0100
@@ -70,8 +70,8 @@
 
 QMAKE_EXTRA_TARGETS += verinfo
 
-qtPrepareTool(LRELEASE, lrelease)
+qtPrepareTool(LRELEASE, lrelease-qt4)
 
 l10n.commands = $$LRELEASE ${QMAKE_FILE_IN} -qm ${QMAKE_FILE_OUT}
 l10n.input = TRANSLATIONS
 l10n.output = ${QMAKE_FILE_BASE}.qm
