--- ./lib/tdb/tdb.mk.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./lib/tdb/tdb.mk	2009-07-12 02:39:36.000000000 +0000
@@ -6,7 +6,7 @@
 ALL_PROGS = $(PROGS) $(PROGS_NOINSTALL)
 
 TDB_SONAME = libtdb.$(SHLIBEXT).1
-TDB_SOLIB = libtdb.$(SHLIBEXT).$(PACKAGE_VERSION)
+TDB_SOLIB = libtdb.$(SHLIBEXT).1
 TDB_STLIB = libtdb.a
 
 TDB_LIB = $(TDB_STLIB) 
@@ -58,8 +58,6 @@
 installdirs::
 	mkdir -p $(DESTDIR)$(bindir)
 	mkdir -p $(DESTDIR)$(includedir)
-	mkdir -p $(DESTDIR)$(libdir) 
-	mkdir -p $(DESTDIR)$(libdir)/pkgconfig
 
 installbin:: all installdirs
 	cp $(PROGS) $(DESTDIR)$(bindir)
@@ -68,7 +66,7 @@
 	cp $(srcdir)/include/tdb.h $(DESTDIR)$(includedir)
 
 installlibs:: all installdirs
-	cp tdb.pc $(DESTDIR)$(libdir)/pkgconfig
+	cp tdb.pc $(DESTDIR)$(prefix)/libdata/pkgconfig
 	cp $(TDB_STLIB) $(TDB_SOLIB) $(DESTDIR)$(libdir)
 
 $(TDB_STLIB): $(TDB_OBJ)
@@ -76,6 +74,3 @@
 
 libtdb.$(SHLIBEXT): $(TDB_SOLIB)
 	ln -fs $< $@
-
-$(TDB_SONAME): $(TDB_SOLIB)
-	ln -fs $< $@
