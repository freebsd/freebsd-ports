--- doc/xmldocs.make.orig	Thu Sep 12 00:45:41 2002
+++ doc/xmldocs.make	Thu Sep 12 00:45:53 2002
@@ -32,7 +32,7 @@
 #   dist-hook: app-dist-hook
 #
 
-docdir = $(gnumeric_datadir)/gnome/help/$(docname)/$(lang)
+docdir = $(gnumeric_datadir)/help/$(docname)/$(lang)
 
 xml_files = $(entities) $(docname).xml
 
