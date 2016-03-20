--- make/libtool.mk.orig	2015-11-10 17:48:52 UTC
+++ make/libtool.mk
@@ -1,7 +1,7 @@
 # --- Required interface definitions ---
 
-# LIBTOOL needs bash
-SHELL=/bin/bash
+# LIBTOOL needs sh
+SHELL=/bin/sh
 
 OBJ=o
 LOBJ=lo
@@ -94,20 +94,20 @@ endef
 define makelib
 	$(LIBTOOL) --mode=link \
 		$(CXX) $(CXXFLAGS) $(LD_VERSION_FLAGS) \
-		 -o $(2) $(1) $(4) $(3) \
+		 -o $(2) $(1) $(3) $(4) \
 		 -rpath $(libdir) -version-info $(5):$(6):$(7)
 endef
 
 #                       1    2      3       4
 # Usage: $(call makebin,objs,binary,ldflags,libs)
 define makebin
-	$(LIBTOOL) --mode=link $(CXX) $(CXXFLAGS) $(1) -o $(2) $(4) $(3)
+	$(LIBTOOL) --mode=link $(CXX) $(CXXFLAGS) $(1) -o $(2) $(3) $(4)
 endef
 
 # Install target
 
 install: all
-	./mkinstalldirs $(DESTDIR)$(libdir)/pkgconfig
+	./mkinstalldirs $(DESTDIR)$(prefix)/libdata/pkgconfig
 	./mkinstalldirs $(DESTDIR)$(bindir)
 	./mkinstalldirs $(DESTDIR)$(includedir)/qpdf
 	./mkinstalldirs $(DESTDIR)$(docdir)
@@ -129,4 +129,4 @@ install: all
 	cp doc/qpdf-manual.html $(DESTDIR)$(docdir)
 	cp doc/qpdf-manual.pdf $(DESTDIR)$(docdir)
 	cp doc/*.1 $(DESTDIR)$(mandir)/man1
-	cp libqpdf.pc $(DESTDIR)$(libdir)/pkgconfig
+	cp libqpdf.pc $(DESTDIR)$(prefix)/libdata/pkgconfig
