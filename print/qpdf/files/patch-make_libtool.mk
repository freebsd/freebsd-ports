--- make/libtool.mk.orig	2021-12-24 07:35:47 UTC
+++ make/libtool.mk
@@ -1,7 +1,7 @@
 # --- Required interface definitions ---
 
-# LIBTOOL needs bash
-SHELL=/bin/bash
+# LIBTOOL needs sh
+SHELL=/bin/sh
 
 OBJ=o
 LOBJ=lo
@@ -128,10 +128,10 @@ install: all install-libs
 	./mkinstalldirs -m 0755 $(DESTDIR)$(bindir)
 	./mkinstalldirs -m 0755 $(DESTDIR)$(docdir)
 	./mkinstalldirs -m 0755 $(DESTDIR)$(mandir)/man1
-	$(LIBTOOL) --mode=install ./install-sh \
+	$(LIBTOOL) --mode=install ./install-sh -s \
 		qpdf/$(OUTPUT_DIR)/qpdf \
 		$(DESTDIR)$(bindir)/qpdf
-	$(LIBTOOL) --mode=install ./install-sh \
+	$(LIBTOOL) --mode=install ./install-sh -s \
 		zlib-flate/$(OUTPUT_DIR)/zlib-flate \
 		$(DESTDIR)$(bindir)/zlib-flate
 	$(LIBTOOL) --mode=install ./install-sh \
