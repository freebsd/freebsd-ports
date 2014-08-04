--- web/includes/functions.php.orig	2011-08-03 10:33:59.000000000 -0700
+++ web/includes/functions.php	2014-08-03 00:19:38.000000000 -0700
@@ -648,7 +648,7 @@
     foreach ( $contents as $contentValue => $contentText )
     {
 ?>
-<option value="<?= $contentValue ?>"<?php if ( $value == $contentValue ) { ?> selected="selected"<? } ?>><?= validHtmlStr($contentText) ?></option>
+<option value="<?= $contentValue ?>"<?php if ( $value == $contentValue ) { ?> selected="selected"<?php } ?>><?= validHtmlStr($contentText) ?></option>
 <?php
     }
 ?>
