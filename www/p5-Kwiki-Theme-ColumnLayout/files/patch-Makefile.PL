--- Makefile.PL.orig	Wed Jan 12 14:26:26 2005
+++ Makefile.PL	Thu Jan 20 20:29:51 2005
@@ -7,9 +7,6 @@
 license         ('perl');
 version_from    ('lib/Kwiki/Theme/ColumnLayout.pm');
 requires        ('Kwiki');
-requires        ('Kwiki::ConfigBlocks');
-requires        ('Kwiki::Infobox');
-requires        ('Kwiki::NavigationToolbar');
 
 &WriteAll;
 
