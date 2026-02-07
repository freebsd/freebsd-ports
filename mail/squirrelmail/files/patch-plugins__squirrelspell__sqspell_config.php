--- plugins/squirrelspell/sqspell_config.php.orig	2015-10-03 17:59:19 UTC
+++ plugins/squirrelspell/sqspell_config.php
@@ -22,9 +22,6 @@ sqgetGlobalVar('username', $username, SQ
  *
  * $SQSPELL_APP = array( 'English' => 'ispell -a',
  *                     'Spanish' => 'ispell -d spanish -a' );
- * You can replace ispell with aspell keeping the same commandline:
- * $SQSPELL_APP = array( 'English' => 'aspell -a',
- *                     'Spanish' => 'aspell -d spanish -a' );
  */
 $SQSPELL_APP = array('English' => 'ispell -a',
 			'Spanish' => 'ispell -d spanish -a');
