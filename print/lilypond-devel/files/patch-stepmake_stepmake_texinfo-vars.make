--- stepmake/stepmake/texinfo-vars.make.orig	2020-03-01 14:00:51 UTC
+++ stepmake/stepmake/texinfo-vars.make
@@ -31,7 +31,7 @@ DO_TEXI_DEP = ( echo ./$@: $(call scan-texi,$<) > $(ba
 
 TEXINFO_PAPERSIZE_OPTION= $(if $(findstring $(PAPERSIZE),a4),,-t @afourpaper)
 
-MAKEINFO_FLAGS += --enable-encoding --error-limit=0 $(DOCUMENTATION_INCLUDES)
+MAKEINFO_FLAGS += --enable-encoding --force $(DOCUMENTATION_INCLUDES)
 MAKEINFO = LANG=C $(MAKEINFO_PROGRAM) $(MAKEINFO_FLAGS)
 
 # texi2html xref map files
