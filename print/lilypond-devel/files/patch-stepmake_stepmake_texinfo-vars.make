--- stepmake/stepmake/texinfo-vars.make.orig	2013-02-23 09:14:13.000000000 -0700
+++ stepmake/stepmake/texinfo-vars.make	2013-03-08 12:16:51.000000000 -0700
@@ -33,7 +33,7 @@
 
 DOCUMENTATION_INCLUDES += -I $(top-src-dir)/Documentation
 
-MAKEINFO_FLAGS += --enable-encoding --error-limit=0 $(DOCUMENTATION_INCLUDES)
+MAKEINFO_FLAGS += --enable-encoding --force $(DOCUMENTATION_INCLUDES)
 MAKEINFO = LANG= $(MAKEINFO_PROGRAM) $(MAKEINFO_FLAGS)
 
 # texi2html xref map files
