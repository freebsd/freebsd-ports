--- doc/xmldocs.make.orig	Mon Sep 16 02:44:11 2002
+++ doc/xmldocs.make	Mon Sep 16 02:44:32 2002
@@ -36,7 +36,7 @@
 # ************* Begin of section some packagers may need to modify  **************
 # This variable (docdir) specifies where the documents should be installed.
 # This default value should work for most packages.
-docdir = $(datadir)/@PACKAGE@/doc/$(docname)/$(lang)
+docdir = $(prefix)/share/doc/@PACKAGE@/$(docname)/$(lang)
 
 # **************  You should not have to edit below this line  *******************
 xml_files = $(entities) $(docname).xml
