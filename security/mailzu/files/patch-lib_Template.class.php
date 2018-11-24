--- lib/Template.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/Template.class.php
@@ -111,7 +111,7 @@ class Template {
 		<td class="mainBkgrdClr" valign="top">
 		  <div align="right">
 		    <p>
-			<?= translate_date('header', mktime());?>
+			<?= translate_date('header', time());?>
 			</p>
 			<!--<p>
 			  <? $this->link->doLink('javascript: help();', translate('Help')) ?>
