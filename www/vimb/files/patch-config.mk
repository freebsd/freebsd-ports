--- config.mk.orig	2023-06-19 20:39:23.000000000 +0000
+++ config.mk	2023-08-07 07:27:35.408991000 +0000
@@ -18,7 +18,7 @@ SRCDIR  = src
 DOCDIR  = doc
 
 # used libs
-LIBS = gtk+-3.0 webkit2gtk-4.1
+LIBS = gtk+-3.0 webkit2gtk-4.0 gdk-pixbuf-2.0 cairo harfbuzz pango glib-2.0 harfbuzz atk
 
 # setup general used CFLAGS
 CFLAGS   += -std=c99 -pipe -Wall -fPIC
@@ -35,9 +35,9 @@ endif
 
 # flags used to build webextension
 EXTTARGET   = webext_main.so
-EXTCFLAGS   = ${CFLAGS} $(shell pkg-config --cflags webkit2gtk-web-extension-4.1)
+EXTCFLAGS   = ${CFLAGS} $(shell pkg-config --cflags webkit2gtk-web-extension-4.0)
 EXTCPPFLAGS = $(CPPFLAGS)
-EXTLDFLAGS  = ${LDFLAGS} $(shell pkg-config --libs webkit2gtk-web-extension-4.1) -shared
+EXTLDFLAGS  = ${LDFLAGS} $(shell pkg-config --libs webkit2gtk-web-extension-4.0) -shared
 
 # flags used for the main application
 CFLAGS     += $(shell pkg-config --cflags $(LIBS))
