
$FreeBSD$

--- doc/gnumeric-doc.make	2002/06/07 19:30:21	1.1
+++ doc/gnumeric-doc.make	2002/06/07 19:30:33
@@ -9,7 +9,7 @@
 gnumeric_docdir  = $(top_srcdir)/doc
 sgml_ents = functions.sgml
 
-gnumeric_helpdir = $(datadir)/gnome/help/gnumeric/$(lang)
+gnumeric_helpdir = $(datadir)/help/gnumeric/$(lang)
 gnumeric_help_DATA = topic.dat
 
 # include generated files to simplify installation
