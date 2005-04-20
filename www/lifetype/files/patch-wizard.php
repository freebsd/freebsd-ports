--- wizard.php.orig	Sun Apr 17 08:56:58 2005
+++ wizard.php	Sun Apr 17 08:58:10 2005
@@ -1414,6 +1414,9 @@
                     }
                 }
                 
+		// dirty hack, ignore duplicate table/key/column and upgrade anyway
+		$errors = false;
+
                 if( !$errors )
                     $message .= "Changes to table <strong>$tableId</strong> executed successfully.<br/>";
                 else {
