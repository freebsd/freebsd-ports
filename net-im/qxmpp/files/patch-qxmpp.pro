--- ./qxmpp.pro.orig	2014-07-02 00:55:44.879359720 +0400
+++ ./qxmpp.pro	2014-07-02 00:56:27.297356491 +0400
@@ -6,29 +6,19 @@
 
 android {
 } else {
-    SUBDIRS += tests examples doc
-    INSTALLS += htmldocs
+    SUBDIRS += tests examples
 }
 
 CONFIG += ordered
 
-# Documentation generation
-docs.commands = cd doc/ && $(QMAKE) && $(MAKE) docs
-
 # Source distribution
 QXMPP_ARCHIVE = qxmpp-$$QXMPP_VERSION
 dist.commands = \
     $(DEL_FILE) -r $$QXMPP_ARCHIVE && \
     $(MKDIR) $$QXMPP_ARCHIVE && \
     git archive master | tar -x -C $$QXMPP_ARCHIVE && \
-    $(COPY_DIR) doc/html $$QXMPP_ARCHIVE/doc && \
     tar czf $${QXMPP_ARCHIVE}.tar.gz $$QXMPP_ARCHIVE && \
     $(DEL_FILE) -r $$QXMPP_ARCHIVE
-dist.depends = docs
 
-# Install rules
-htmldocs.files = doc/html
-htmldocs.path = $$PREFIX/share/doc/qxmpp
-htmldocs.CONFIG += no_check_exist directory
 
-QMAKE_EXTRA_TARGETS += dist docs
+QMAKE_EXTRA_TARGETS += dist
