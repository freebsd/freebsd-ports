--- Makefile.PL.orig	Sat Oct 11 09:04:24 2003
+++ Makefile.PL	Mon Oct 13 00:00:33 2003
@@ -10,8 +10,8 @@
     'ABSTRACT_FROM' => 'lib/I18N/LangTags.pm', # 
     'dist'        => { COMPRESS => 'gzip -6f', SUFFIX => 'gz', },
     
-    (($] >= 5.007003) ?
-     ('INSTALLDIRS' => 'perl') : ()),
+#    (($] >= 5.007003) ?
+#     ('INSTALLDIRS' => 'perl') : ()),
 
 );
 
