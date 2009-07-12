--- ./lib/tevent/tevent.mk.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./lib/tevent/tevent.mk	2009-07-12 02:39:36.000000000 +0000
@@ -1,6 +1,6 @@
 TEVENT_SOBASE = libtevent.$(SHLIBEXT)
 TEVENT_SONAME = $(TEVENT_SOBASE).0
-TEVENT_SOLIB = $(TEVENT_SOBASE).$(PACKAGE_VERSION)
+TEVENT_SOLIB = $(TEVENT_SOBASE).0
 TEVENT_STLIB = libtevent.a
 
 $(TEVENT_STLIB): $(TEVENT_OBJ)
@@ -9,23 +9,20 @@
 $(TEVENT_SOBASE): $(TEVENT_SOLIB)
 	ln -fs $< $@
 
-$(TEVENT_SONAME): $(TEVENT_SOLIB)
-	ln -fs $< $@
-
 dirs::
 	@mkdir -p lib
 
 installdirs::
 	mkdir -p $(DESTDIR)$(includedir)
-	mkdir -p $(DESTDIR)$(libdir)
-	mkdir -p $(DESTDIR)$(libdir)/pkgconfig
+	mkdir -p $(DESTDIR)$(prefix)/libdata
+	mkdir -p $(DESTDIR)$(prefix)/libdata/pkgconfig
 
 installheaders:: installdirs
 	cp $(srcdir)/tevent.h $(DESTDIR)$(includedir)
 	cp $(srcdir)/tevent_internal.h $(DESTDIR)$(includedir)
 
 installlibs:: installdirs
-	cp tevent.pc $(DESTDIR)$(libdir)/pkgconfig
+	cp tevent.pc $(DESTDIR)$(prefix)/libdata/pkgconfig
 	cp $(TEVENT_STLIB) $(TEVENT_SOLIB) $(DESTDIR)$(libdir)
 
 install:: all installdirs installheaders installlibs $(PYTHON_INSTALL_TARGET)
