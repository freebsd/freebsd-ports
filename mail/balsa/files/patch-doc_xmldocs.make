--- doc/xmldocs.make.orig	Wed Sep 18 07:12:20 2002
+++ doc/xmldocs.make	Tue Oct 29 12:20:37 2002
@@ -36,7 +36,7 @@
 # ************* Begin of section some packagers may need to modify  **************
 # This variable (docdir) specifies where the documents should be installed.
 # This default value should work for most packages.
-docdir = $(datadir)/gnome/help/$(docname)/$(lang)
+docdir = $(datadir)/help/$(docname)/$(lang)
 
 # **************  You should not have to edit below this line  *******************
 xml_files = $(entities) $(docname).xml
