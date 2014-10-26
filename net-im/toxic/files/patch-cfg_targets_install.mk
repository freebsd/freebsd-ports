--- cfg/targets/install.mk.orig	2014-10-21 15:20:51.000000000 +0200
+++ cfg/targets/install.mk	2014-10-25 17:27:09.000000000 +0200
@@ -23,7 +23,7 @@
 	@echo "Installing man pages"
 	@mkdir -p $(abspath $(DESTDIR)/$(MANDIR))
 	@for f in $(MANFILES) ; do \
-		if [ ! -e "$$f" ]; then \
+		if [ ! -e "$(DOC_DIR)/$$f" ]; then \
 			continue ;\
 		fi ;\
 		section=$(abspath $(DESTDIR)/$(MANDIR))/man`echo $$f | rev | cut -d "." -f 1` ;\
