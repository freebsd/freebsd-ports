--- ./lib/Locale/Po4a/Xml.pm.orig	2010-10-19 10:43:04.000000000 -0200
+++ ./lib/Locale/Po4a/Xml.pm	2010-10-19 10:43:13.000000000 -0200
@@ -730,7 +730,7 @@
 		f_extract	=> \&tag_extract_doctype,
 		f_translate	=> \&tag_trans_doctype},
 	{	beginning	=> "![CDATA[",
-		end		=> "",
+		end		=> "]]",
 		breaking	=> 1,
 		f_extract	=> \&CDATA_extract,
 		f_translate	=> \&CDATA_trans},
