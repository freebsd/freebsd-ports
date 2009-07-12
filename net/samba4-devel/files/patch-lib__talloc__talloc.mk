--- ./lib/talloc/talloc.mk.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./lib/talloc/talloc.mk	2009-07-12 02:39:36.000000000 +0000
@@ -1,6 +1,6 @@
 TALLOC_OBJ = $(tallocdir)/talloc.o 
 
-TALLOC_SOLIB = libtalloc.$(SHLIBEXT).$(PACKAGE_VERSION)
+TALLOC_SOLIB = libtalloc.$(SHLIBEXT).1
 TALLOC_SONAME = libtalloc.$(SHLIBEXT).1
 TALLOC_STLIB = libtalloc.a
 
@@ -15,16 +15,14 @@
 
 install:: all 
 	${INSTALLCMD} -d $(DESTDIR)$(libdir)
-	${INSTALLCMD} -d $(DESTDIR)$(libdir)/pkgconfig
+	${INSTALLCMD} -d $(DESTDIR)$(prefix)/libdata/pkgconfig
 	${INSTALLCMD} -m 755 $(TALLOC_STLIB) $(DESTDIR)$(libdir)
 	${INSTALLCMD} -m 755 $(TALLOC_SOLIB) $(DESTDIR)$(libdir)
 	${INSTALLCMD} -d $(DESTDIR)${includedir}
 	${INSTALLCMD} -m 644 $(srcdir)/talloc.h $(DESTDIR)$(includedir)
-	${INSTALLCMD} -m 644 talloc.pc $(DESTDIR)$(libdir)/pkgconfig
+	${INSTALLCMD} -m 644 talloc.pc $(DESTDIR)$(prefix)/libdata/pkgconfig
 	if [ -f talloc.3 ];then ${INSTALLCMD} -d $(DESTDIR)$(mandir)/man3; fi
 	if [ -f talloc.3 ];then ${INSTALLCMD} -m 644 talloc.3 $(DESTDIR)$(mandir)/man3; fi
-	which swig >/dev/null 2>&1 && ${INSTALLCMD} -d $(DESTDIR)`swig -swiglib` || true
-	which swig >/dev/null 2>&1 && ${INSTALLCMD} -m 644 talloc.i $(DESTDIR)`swig -swiglib` || true
 
 doc:: talloc.3 talloc.3.html
 
