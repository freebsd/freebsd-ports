--- make/libtool.mk.orig	2018-01-15 01:09:20 UTC
+++ make/libtool.mk
@@ -1,7 +1,7 @@
 # --- Required interface definitions ---
 
-# LIBTOOL needs bash
-SHELL=/bin/bash
+# LIBTOOL needs sh
+SHELL?=/bin/sh
 
 OBJ=o
 LOBJ=lo
@@ -112,14 +112,14 @@ install: all
 	./mkinstalldirs $(DESTDIR)$(includedir)/qpdf
 	./mkinstalldirs $(DESTDIR)$(docdir)
 	./mkinstalldirs $(DESTDIR)$(mandir)/man1
-	$(LIBTOOL) --mode=install ./install-sh \
+	$(LIBTOOL) --mode=install ./install-sh -s \
 		libqpdf/$(OUTPUT_DIR)/libqpdf.la \
 		$(DESTDIR)$(libdir)/libqpdf.la
 	$(LIBTOOL) --finish $(DESTDIR)$(libdir)
-	$(LIBTOOL) --mode=install ./install-sh \
+	$(LIBTOOL) --mode=install ./install-sh -s \
 		qpdf/$(OUTPUT_DIR)/qpdf \
 		$(DESTDIR)$(bindir)/qpdf
-	$(LIBTOOL) --mode=install ./install-sh \
+	$(LIBTOOL) --mode=install ./install-sh -s \
 		zlib-flate/$(OUTPUT_DIR)/zlib-flate \
 		$(DESTDIR)$(bindir)/zlib-flate
 	cp qpdf/fix-qdf $(DESTDIR)$(bindir)
