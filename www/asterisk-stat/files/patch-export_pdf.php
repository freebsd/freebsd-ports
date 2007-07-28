--- export_pdf.php.orig Thu Mar  3 00:11:32 2005
+++ export_pdf.php      Thu Jul 20 23:50:45 2006
@@ -2,7 +2,7 @@
 include_once(dirname(__FILE__) . "/lib/defines.php");
 include_once(dirname(__FILE__) . "/lib/Class.Table.php");
 define(FPDF_FONTPATH,dirname(__FILE__).'/lib/font/');
-include_once(dirname(__FILE__) . "/lib/fpdf.php');
+include_once(dirname(__FILE__) . "/lib/fpdf.php");
 
 session_start();
 
