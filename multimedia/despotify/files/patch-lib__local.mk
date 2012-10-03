--- ./lib/local.mk.orig	2012-10-03 13:21:24.000000000 +0200
+++ ./lib/local.mk	2012-10-03 13:22:42.000000000 +0200
@@ -49,14 +49,13 @@
 	$(LT) --mode=clean rm -f $(LIB_OBJS) Makefile.dep
 
 install: libdespotify.la
-	install -d $(INSTALL_PREFIX)/lib/pkgconfig
+	install -d $(INSTALL_PREFIX)/libdata/pkgconfig
 	 
 	$(LT) --mode=install install libdespotify.la $(INSTALL_PREFIX)/lib/libdespotify.la
-	$(LDCONFIG) -n $(INSTALL_PREFIX)/lib
 	install -d $(INSTALL_PREFIX)/include/ 
 	install despotify.h $(INSTALL_PREFIX)/include/
-	install -d $(INSTALL_PREFIX)/lib/pkgconfig/
-	install despotify.pc $(INSTALL_PREFIX)/lib/pkgconfig/despotify.pc
+	install -d $(INSTALL_PREFIX)/libdata/pkgconfig/
+	install despotify.pc $(INSTALL_PREFIX)/libdata/pkgconfig/despotify.pc
 
 uninstall:
 	$(LT) --mode=uninstall rm -f $(INSTALL_PREFIX)/lib/libdespotify.la
