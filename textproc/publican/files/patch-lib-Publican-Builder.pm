--- lib/Publican/Builder.pm.orig	2012-08-16 13:33:44.153394319 -0400
+++ lib/Publican/Builder.pm	2012-08-16 13:34:26.115391916 -0400
@@ -768,7 +768,7 @@
             $wkhtmltopdf_cmd,                  '--header-spacing',
             5,                                 '--margin-top',
             20,                                '--header-html',
-            '/usr/share/publican/header.html', '--title',
+            '%%DATADIR%%/header.html', '--title',
             $title,                            "$tmp_dir/$lang/html-single/index.html",
             "$tmp_dir/$lang/pdf/$pdf_name"
         );
