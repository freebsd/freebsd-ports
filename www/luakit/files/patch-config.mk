diff -r 1a525885c788 config.mk
--- config.mk Fri Mar 23 23:55:52 2012 -0300
+++ config.mk Fri Mar 23 23:57:41 2012 -0300
@@ -5,10 +5,10 @@
 PREFIX     ?= /usr/local
 INSTALLDIR := $(DESTDIR)$(PREFIX)
 
-MANPREFIX  ?= $(PREFIX)/share/man
+MANPREFIX  := $(PREFIX)/man
 MANPREFIX  := $(DESTDIR)$(MANPREFIX)
 
-DOCDIR     ?= $(PREFIX)/share/luakit/docs
+DOCDIR     ?= $(PREFIX)/share/doc/luakit
 DOCDIR     := $(DESTDIR)$(DOCDIR)
 
 # Use the Just-In-Time compiler for lua (for faster lua code execution)
