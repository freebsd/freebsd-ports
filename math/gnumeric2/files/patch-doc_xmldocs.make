--- doc/xmldocs.make.orig	Tue Sep 24 09:15:18 2002
+++ doc/xmldocs.make	Sat Oct  5 02:43:17 2002
@@ -32,7 +32,7 @@
 #   dist-hook: app-dist-hook
 #
 
-docdir = $(gnumeric_datadir)/share/gnome/help/$(docname)/$(lang)
+docdir = $(gnumeric_datadir)/help/$(docname)/$(lang)
 
 xml_files = $(entities) $(docname).xml
 
