--- src/unix-dll.mak.orig	Wed Sep 24 22:41:20 2003
+++ src/unix-dll.mak	Wed Dec 10 19:25:49 2003
@@ -46,11 +46,9 @@
 
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
 
@@ -58,24 +56,20 @@
 
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
+	$(GLCC) `pkg-config --cflags gtk+` -o $(GSSOX_XE) $(GLSRC)dxmain.c -L$(BINDIR) -l$(GS) `pkg-config --libs gtk+`
 
 $(GSSOC_XE): $(GS_SO) $(GLSRC)dxmainc.c
-	$(GLCC) -g -o $(GSSOC_XE) $(GLSRC)dxmainc.c -L$(BINDIR) -l$(GS)
+	$(GLCC) -o $(GSSOC_XE) $(GLSRC)dxmainc.c -L$(BINDIR) -l$(GS)
 
 # ------------------------- Recursive make targets ------------------------- #
 
-SODEFS=LDFLAGS='$(LDFLAGS) $(CFLAGS_SO) -shared -Wl,-soname=$(GS_SONAME_MAJOR)'\
- GS_XE=$(BINDIR)/$(SOBINRELDIR)/$(GS_SONAME_MAJOR_MINOR)\
+SODEFS=LDFLAGS='$(LDFLAGS) $(CFLAGS_SO) -shared -Wl,-soname,$(GS_SONAME_MAJOR)'\
+ GS_XE=$(BINDIR)/$(SOBINRELDIR)/$(GS_SONAME_MAJOR)\
  STDIO_IMPLEMENTATION=c\
  DISPLAY_DEV=$(DD)$(SOOBJRELDIR)/display.dev\
  BINDIR=$(BINDIR)/$(SOBINRELDIR)\
@@ -104,11 +98,9 @@
 	-mkdir -p $(libdir)
 	$(INSTALL_PROGRAM) $(GSSOC) $(bindir)/$(GSSOC_XENAME)
 	$(INSTALL_PROGRAM) $(GSSOX) $(bindir)/$(GSSOX_XENAME)
-	$(INSTALL_PROGRAM) $(BINDIR)/$(SOBINRELDIR)/$(GS_SONAME_MAJOR_MINOR) $(libdir)/$(GS_SONAME_MAJOR_MINOR)
+	$(INSTALL_PROGRAM) $(BINDIR)/$(SOBINRELDIR)/$(GS_SONAME_MAJOR) $(libdir)/$(GS_SONAME_MAJOR)
 	$(RM_) $(libdir)/$(GS_SONAME)
-	ln -s $(GS_SONAME_MAJOR_MINOR) $(libdir)/$(GS_SONAME)
-	$(RM_) $(libdir)/$(GS_SONAME_MAJOR)
-	ln -s $(GS_SONAME_MAJOR_MINOR) $(libdir)/$(GS_SONAME_MAJOR)
+	ln -s $(GS_SONAME_MAJOR) $(libdir)/$(GS_SONAME)
 
 soinstall: install-so install-scripts install-data
 
