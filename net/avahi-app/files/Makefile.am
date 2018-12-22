--- Makefile.am.orig	2017-07-10 12:14:59.083371116 +0200
+++ Makefile.am	2018-12-22 21:00:37.193294000 +0100
@@ -43,6 +43,7 @@
 	avahi-gobject.pc.in \
 	avahi-qt3.pc.in \
 	avahi-qt4.pc.in \
+	avahi-qt5.pc.in \
 	avahi-sharp.pc.in \
 	avahi-ui-sharp.pc.in \
 	avahi-compat-libdns_sd.pc.in \
@@ -101,7 +102,11 @@
 DX_INPUT += \
 	$(srcdir)/avahi-qt/qt-watch.h
 endif
+if HAVE_QT5
+DX_INPUT += \
+	$(srcdir)/avahi-qt/qt-watch.h
 endif
+endif
 
 if HAVE_GLIB
 DX_INPUT += \
@@ -155,6 +160,8 @@
 %.pc: %.pc.in
 	$(AM_V_GEN)sed -e 's,@prefix\@,$(prefix),g' \
 	    -e 's,@libdir\@,$(libdir),g' \
+	    -e 's,@PTHREAD_CFLAGS\@,$(PTHREAD_CFLAGS),g' \
+	    -e 's,@PTHREAD_LIBS\@,$(PTHREAD_LIBS),g' \
 	    -e 's,@HOWL_COMPAT_VERSION\@,$(HOWL_COMPAT_VERSION),g' \
 	    -e 's,@PACKAGE_VERSION\@,$(PACKAGE_VERSION),g' $< > $@
 
@@ -214,6 +221,11 @@
 if HAVE_QT4
 pkgconfig_DATA += avahi-qt4.pc
 CLEANFILES += avahi-qt4.pc
+endif
+
+if HAVE_QT5
+pkgconfig_DATA += avahi-qt5.pc
+CLEANFILES += avahi-qt5.pc
 endif
 
 CLEANFILES += avahi.devhelp
