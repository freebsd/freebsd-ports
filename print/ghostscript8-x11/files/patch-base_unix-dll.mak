--- base/unix-dll.mak.orig	2009-10-19 20:24:53 UTC
+++ base/unix-dll.mak
@@ -79,12 +79,11 @@ $(GS_SO_MAJOR): $(GS_SO_MAJOR_MINOR)
 # Build the small Ghostscript loaders, with Gtk+ and without
 
 $(GSSOC_XE): $(GS_SO) $(PSSRC)$(SOC_LOADER)
-	$(GLCC) -g -o $(GSSOC_XE) $(PSSRC)dxmainc.c \
-	$(LDFLAGS) -L$(BINDIR) -l$(GS)
+	$(GLCC) -g -o $(GSSOC_XE) $(PSSRC)dxmainc.c -L$(BINDIR) -l$(GS)
 
 $(GSSOX_XE): $(GS_SO) $(PSSRC)$(SOC_LOADER)
 	$(GLCC) -g $(SOC_CFLAGS) -o $(GSSOX_XE) $(PSSRC)$(SOC_LOADER) \
-	$(LDFLAGS) -L$(BINDIR) -l$(GS) $(SOC_LIBS)
+	-L$(BINDIR) -l$(GS) $(SOC_LIBS)
 
 # ------------------------- Recursive make targets ------------------------- #
 
