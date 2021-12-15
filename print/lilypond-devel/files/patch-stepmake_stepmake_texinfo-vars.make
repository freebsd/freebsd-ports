--- stepmake/stepmake/texinfo-vars.make.orig	2021-11-28 13:46:28 UTC
+++ stepmake/stepmake/texinfo-vars.make
@@ -3,7 +3,7 @@ TEXINFO_SOURCES = $(TEXI_FILES)
 
 TEXINFO_PAPERSIZE_OPTION= $(if $(findstring $(PAPERSIZE),a4),,-t @afourpaper)
 
-MAKEINFO_FLAGS += --enable-encoding --error-limit=0 $(DOCUMENTATION_INCLUDES)
+MAKEINFO_FLAGS += --enable-encoding --force $(DOCUMENTATION_INCLUDES)
 MAKEINFO = LANG=C $(MAKEINFO_PROGRAM) $(MAKEINFO_FLAGS)
 
 ###########
