--- config.mk.orig	2024-12-23 06:24:27 UTC
+++ config.mk
@@ -18,7 +18,7 @@ DOCDIR  = doc
 DOCDIR  = doc
 
 # used libs
-LIBS = gtk+-3.0 webkit2gtk-4.1
+LIBS = gtk+-3.0 webkit2gtk-4.0
 
 # setup general used CFLAGS
 CFLAGS   += -std=c99 -pipe -Wall -fPIC
@@ -35,9 +35,9 @@ EXTTARGET   = webext_main.so
 
 # flags used to build webextension
 EXTTARGET   = webext_main.so
-EXTCFLAGS   = ${CFLAGS} $(shell pkg-config --cflags webkit2gtk-web-extension-4.1)
+EXTCFLAGS   = ${CFLAGS} $(shell pkg-config --cflags webkit2gtk-web-extension-4.0)
 EXTCPPFLAGS = $(CPPFLAGS)
-EXTLDFLAGS  = ${LDFLAGS} $(shell pkg-config --libs webkit2gtk-web-extension-4.1) -shared
+EXTLDFLAGS  = ${LDFLAGS} $(shell pkg-config --libs webkit2gtk-web-extension-4.0) -shared
 
 # flags used for the main application
 CFLAGS     += $(shell pkg-config --cflags $(LIBS))
