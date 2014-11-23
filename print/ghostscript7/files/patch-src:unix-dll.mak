--- src/unix-dll.mak.orig	2003-01-17 09:49:05.000000000 +0900
+++ src/unix-dll.mak	2014-11-23 14:43:44.000000000 +0900
@@ -48,11 +48,9 @@
 
 # shared library
 GS_SONAME=lib$(GS).so
-GS_SONAME_MAJOR=$(GS_SONAME).$(GS_VERSION_MAJOR)
-GS_SONAME_MAJOR_MINOR= $(GS_SONAME).$(GS_VERSION_MAJOR).$(GS_VERSION_MINOR)
+GS_SONAME_MAJOR=$(GS_SONAME).$(GS_SHLIB_VER)
 GS_SO=$(BINDIR)/$(GS_SONAME)
-GS_SO_MAJOR=$(GS_SO).$(GS_VERSION_MAJOR)
-GS_SO_MAJOR_MINOR=$(GS_SO_MAJOR).$(GS_VERSION_MINOR)
+GS_SO_MAJOR=$(GS_SO).$(GS_SHLIB_VER)
 
 # Shared object is built by redefining GS_XE in a recursive make.
 
@@ -60,24 +58,20 @@
 
 $(GS_SO): $(GS_SO_MAJOR)
 	$(RM_) $(GS_SO)
-	ln -s $(GS_SONAME_MAJOR_MINOR) $(GS_SO)
-
-$(GS_SO_MAJOR): $(GS_SO_MAJOR_MINOR)
-	$(RM_) $(GS_SO_MAJOR)
-	ln -s $(GS_SONAME_MAJOR_MINOR) $(GS_SO_MAJOR)
+	ln -s $(GS_SONAME_MAJOR) $(GS_SO)
 
 # Build the small Ghostscript loaders, with Gtk+ and without
 
 $(GSSOX_XE): $(GS_SO) $(GLSRC)dxmain.c
-	$(GLCC) -g `gtk-config --cflags` -o $(GSSOX_XE) $(GLSRC)dxmain.c -L$(BINDIR) -l$(GS) `gtk-config --libs`
+	$(GLCC) `$(GTK_CONFIG) --cflags` -o $(GSSOX_XE) $(GLSRC)dxmain.c -L$(BINDIR) -l$(GS) `$(GTK_CONFIG) --libs`
 
 $(GSSOC_XE): $(GS_SO) $(GLSRC)dxmainc.c
-	$(GLCC) -g -o $(GSSOC_XE) $(GLSRC)dxmainc.c -L$(BINDIR) -l$(GS)
+	$(GLCC) -o $(GSSOC_XE) $(GLSRC)dxmainc.c -L$(BINDIR) -l$(GS)
 
 # ------------------------- Recursive make targets ------------------------- #
 
 SODEFS=LDFLAGS='$(LDFLAGS) $(CFLAGS_SO) -shared -Wl,-soname,$(GS_SONAME_MAJOR)'\
- GS_XE=$(BINDIR)/$(SOBINRELDIR)/$(GS_SONAME_MAJOR_MINOR)\
+ GS_XE=$(BINDIR)/$(SOBINRELDIR)/$(GS_SONAME_MAJOR)\
  STDIO_IMPLEMENTATION=c\
  DISPLAY_DEV=$(DD)$(SOOBJRELDIR)/display.dev\
  BINDIR=$(BINDIR)/$(SOBINRELDIR)\
@@ -98,19 +92,17 @@
 	$(MAKE) $(SODEFS) GENOPT='-DDEBUG' CFLAGS='$(CFLAGS_DEBUG) $(CFLAGS_SO) $(GCFLAGS) $(XCFLAGS)' $(GSSOC) $(GSSOX)
 
 install-so: so
-	-mkdir -p $(prefix)
-	-mkdir -p $(datadir)
-	-mkdir -p $(gsdir)
-	-mkdir -p $(gsdatadir)
-	-mkdir -p $(bindir)
-	-mkdir -p $(libdir)
-	$(INSTALL_PROGRAM) $(GSSOC) $(bindir)/$(GSSOC_XENAME)
-	$(INSTALL_PROGRAM) $(GSSOX) $(bindir)/$(GSSOX_XENAME)
-	$(INSTALL_PROGRAM) $(BINDIR)/$(SOBINRELDIR)/$(GS_SONAME_MAJOR_MINOR) $(libdir)/$(GS_SONAME_MAJOR_MINOR)
-	$(RM_) $(libdir)/$(GS_SONAME)
-	ln -s $(GS_SONAME_MAJOR_MINOR) $(libdir)/$(GS_SONAME)
-	$(RM_) $(libdir)/$(GS_SONAME_MAJOR)
-	ln -s $(GS_SONAME_MAJOR_MINOR) $(libdir)/$(GS_SONAME_MAJOR)
+	-mkdir -p $(DESTDIR)$(prefix)
+	-mkdir -p $(DESTDIR)$(datadir)
+	-mkdir -p $(DESTDIR)$(gsdir)
+	-mkdir -p $(DESTDIR)$(gsdatadir)
+	-mkdir -p $(DESTDIR)$(bindir)
+	-mkdir -p $(DESTDIR)$(libdir)
+	$(INSTALL_PROGRAM) $(GSSOC) $(DESTDIR)$(bindir)/$(GSSOC_XENAME)
+	$(INSTALL_PROGRAM) $(GSSOX) $(DESTDIR)$(bindir)/$(GSSOX_XENAME)
+	$(INSTALL_PROGRAM) $(BINDIR)/$(SOBINRELDIR)/$(GS_SONAME_MAJOR) $(DESTDIR)$(libdir)/$(GS_SONAME_MAJOR)
+	$(RM_) $(DESTDIR)$(libdir)/$(GS_SONAME)
+	ln -s $(GS_SONAME_MAJOR) $(DESTDIR)$(libdir)/$(GS_SONAME)
 
 soinstall: install-so install-scripts install-data
 
