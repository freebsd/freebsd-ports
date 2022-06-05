--- make/texinfo-vars.make.orig	2022-05-20 13:40:50 UTC
+++ make/texinfo-vars.make
@@ -3,7 +3,7 @@ TEXINFO_SOURCES = $(TEXI_FILES)
 
 TEXINFO_PAPERSIZE_OPTION= $(if $(findstring $(PAPERSIZE),a4),,-t @afourpaper)
 
-MAKEINFO_FLAGS += --enable-encoding --error-limit=0 $(DOCUMENTATION_INCLUDES)
+MAKEINFO_FLAGS += --enable-encoding --force $(DOCUMENTATION_INCLUDES)
 MAKEINFO = LANG=C $(MAKEINFO_PROGRAM) $(MAKEINFO_FLAGS)
 
 ###########
