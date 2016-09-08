--- stepmake/stepmake/texinfo-vars.make.orig	2016-08-30 10:23:53 UTC
+++ stepmake/stepmake/texinfo-vars.make
@@ -31,7 +31,7 @@ DO_TEXI_DEP = ( echo ./$@: $(call scan-t
 
 TEXINFO_PAPERSIZE_OPTION= $(if $(findstring $(PAPERSIZE),a4),,-t @afourpaper)
 
-MAKEINFO_FLAGS += --enable-encoding --error-limit=0 $(DOCUMENTATION_INCLUDES)
+MAKEINFO_FLAGS += --enable-encoding --force $(DOCUMENTATION_INCLUDES)
 MAKEINFO = LANG= $(MAKEINFO_PROGRAM) $(MAKEINFO_FLAGS)
 
 # texi2html xref map files
