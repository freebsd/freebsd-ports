--- stepmake/stepmake/texinfo-vars.make.orig	2020-04-26 09:45:49 UTC
+++ stepmake/stepmake/texinfo-vars.make
@@ -26,7 +26,7 @@ DO_TEXI_DEP = ( echo ./$@: $(call scan-texi,$<) > $(ba
 
 TEXINFO_PAPERSIZE_OPTION= $(if $(findstring $(PAPERSIZE),a4),,-t @afourpaper)
 
-MAKEINFO_FLAGS += --enable-encoding --error-limit=0 $(DOCUMENTATION_INCLUDES)
+MAKEINFO_FLAGS += --enable-encoding --force $(DOCUMENTATION_INCLUDES)
 MAKEINFO = LANG=C $(MAKEINFO_PROGRAM) $(MAKEINFO_FLAGS)
 
 # texi2html xref map files
