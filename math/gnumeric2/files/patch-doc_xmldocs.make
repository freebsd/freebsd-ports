--- doc/xmldocs.make.orig	Tue Apr 22 04:37:57 2003
+++ doc/xmldocs.make	Tue May 13 01:59:56 2003
@@ -32,7 +32,7 @@
 #   dist-hook: app-dist-hook
 #
 
-docdir = $(gnumeric_datadir)/gnome/help/$(docname)/$(lang)
+docdir = $(gnumeric_datadir)/help/$(docname)/$(lang)
 
 xml_files = $(entities) $(docname).xml
 
