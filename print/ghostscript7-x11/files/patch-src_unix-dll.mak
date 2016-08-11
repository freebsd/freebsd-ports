--- src/unix-dll.mak.orig	2003-01-17 00:49:05 UTC
+++ src/unix-dll.mak
@@ -47,12 +47,17 @@ GSSOX_XE=$(BINDIR)/$(GSSOX_XENAME)
 GSSOX=$(BINDIR)/$(SOBINRELDIR)/$(GSSOX_XENAME)
 
 # shared library
-GS_SONAME=lib$(GS).so
+GS_SONAME_BASE=lib$(GS)
+
+GS_SOEXT=so
+GS_SONAME=$(GS_SONAME_BASE).$(GS_SOEXT)
 GS_SONAME_MAJOR=$(GS_SONAME).$(GS_VERSION_MAJOR)
-GS_SONAME_MAJOR_MINOR= $(GS_SONAME).$(GS_VERSION_MAJOR).$(GS_VERSION_MINOR)
+GS_SONAME_MAJOR_MINOR=$(GS_SONAME).$(GS_VERSION_MAJOR).$(GS_VERSION_MINOR)
+LDFLAGS_SO=-shared -Wl,-soname=$(GS_SONAME_MAJOR)
+
 GS_SO=$(BINDIR)/$(GS_SONAME)
-GS_SO_MAJOR=$(GS_SO).$(GS_VERSION_MAJOR)
-GS_SO_MAJOR_MINOR=$(GS_SO_MAJOR).$(GS_VERSION_MINOR)
+GS_SO_MAJOR=$(BINDIR)/$(GS_SONAME_MAJOR) 
+GS_SO_MAJOR_MINOR=$(BINDIR)/$(GS_SONAME_MAJOR_MINOR)
 
 # Shared object is built by redefining GS_XE in a recursive make.
 
@@ -68,15 +73,16 @@ $(GS_SO_MAJOR): $(GS_SO_MAJOR_MINOR)
 
 # Build the small Ghostscript loaders, with Gtk+ and without
 
-$(GSSOX_XE): $(GS_SO) $(GLSRC)dxmain.c
-	$(GLCC) -g `gtk-config --cflags` -o $(GSSOX_XE) $(GLSRC)dxmain.c -L$(BINDIR) -l$(GS) `gtk-config --libs`
+$(GSSOX_XE): $(GS_SO) $(GLSRC)$(SOC_LOADER)
+	$(GLCC) -g -o $(GSSOX_XE) $(GLSRC)dxmainc.c -L$(BINDIR) -l$(GS)
 
-$(GSSOC_XE): $(GS_SO) $(GLSRC)dxmainc.c
-	$(GLCC) -g -o $(GSSOC_XE) $(GLSRC)dxmainc.c -L$(BINDIR) -l$(GS)
+$(GSSOC_XE): $(GS_SO) $(GLSRC)$(SOC_LOADER)
+	$(GLCC) -g $(SOC_CFLAGS) -o $(GSSOC_XE) $(GLSRC)$(SOC_LOADER) \
+	    -L$(BINDIR) -l$(GS) $(SOC_LIBS)
 
 # ------------------------- Recursive make targets ------------------------- #
 
-SODEFS=LDFLAGS='$(LDFLAGS) $(CFLAGS_SO) -shared -Wl,-soname,$(GS_SONAME_MAJOR)'\
+SODEFS=LDFLAGS='$(LDFLAGS) $(LDFLAGS_SO)'\
  GS_XE=$(BINDIR)/$(SOBINRELDIR)/$(GS_SONAME_MAJOR_MINOR)\
  STDIO_IMPLEMENTATION=c\
  DISPLAY_DEV=$(DD)$(SOOBJRELDIR)/display.dev\
@@ -98,21 +104,26 @@ sodebug: SODIRS
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
+	-mkdir -p $(DESTDIR)$(gsincludedir)
+	$(INSTALL_PROGRAM) $(GSSOC) $(DESTDIR)$(bindir)/$(GSSOC_XENAME)
+	$(INSTALL_PROGRAM) $(GSSOX) $(DESTDIR)$(bindir)/$(GSSOX_XENAME)
+	$(INSTALL_PROGRAM) $(BINDIR)/$(SOBINRELDIR)/$(GS_SONAME_MAJOR_MINOR) $(DESTDIR)$(libdir)/$(GS_SONAME_MAJOR_MINOR)
+	$(RM_) $(DESTDIR)$(libdir)/$(GS_SONAME)
+	ln -s $(GS_SONAME_MAJOR_MINOR) $(DESTDIR)$(libdir)/$(GS_SONAME)
+	$(RM_) $(DESTDIR)$(libdir)/$(GS_SONAME_MAJOR)
+	ln -s $(GS_SONAME_MAJOR_MINOR) $(DESTDIR)$(libdir)/$(GS_SONAME_MAJOR)
+	$(INSTALL_DATA) $(GLSRC)iapi.h $(DESTDIR)$(gsincludedir)iapi.h
+	$(INSTALL_DATA) $(GLSRC)errors.h $(DESTDIR)$(gsincludedir)ierrors.h
+	$(INSTALL_DATA) $(GLSRC)gdevdsp.h $(DESTDIR)$(gsincludedir)gdevdsp.h
 
-soinstall: install-so install-scripts install-data
+
+soinstall: install-so install-scripts install-data $(INSTALL_SHARED) $(INSTALL_CONTRIB)
 
 # Make the build directories
 SODIRS: STDDIRS
