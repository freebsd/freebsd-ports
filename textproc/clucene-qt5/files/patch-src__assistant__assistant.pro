Only enter the directories we want to build, otherwise we might fail due to
missing dependencies.

--- src/assistant/assistant.pro
+++ src/assistant/assistant.pro
@@ -1,21 +1,3 @@
 TEMPLATE = subdirs
 
-SUBDIRS += clucene \
-           help \
-           assistant \
-           qhelpgenerator \
-           qcollectiongenerator \
-           qhelpconverter
-
-help.depends = clucene
-assistant.depends = help
-qhelpgenerator.depends = help
-qcollectiongenerator.depends = help
-qhelpconverter.depends = help
-
-qtNomakeTools( \
-    assistant \
-    qhelpgenerator \
-    qcollectiongenerator \
-    qhelpconverter \
-)
+SUBDIRS += clucene
