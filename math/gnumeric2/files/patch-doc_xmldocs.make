--- doc/xmldocs.make.orig	Sun Sep  7 22:37:55 2003
+++ doc/xmldocs.make	Sat Sep 13 02:47:14 2003
@@ -32,7 +32,7 @@
 #   dist-hook: app-dist-hook
 #
 
-docdir = $(gnumeric_datadir)/share/gnome/help/$(docname)/$(lang)
+docdir = $(gnumeric_datadir)/help/$(docname)/$(lang)
 
 xml_files = $(entities) $(docname).xml
 
