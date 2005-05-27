--- wizard.php.orig	Wed May 25 01:20:42 2005
+++ wizard.php	Fri May 27 14:40:20 2005
@@ -1419,6 +1419,9 @@
                     }
                 }
 
+                // dirty hack, ignore duplicate table/key/column and upgrade anyway
+                $errors = false;
+ 
                 if( !$errors )
                     $message .= "Changes to table <strong>$tableId</strong> executed successfully.<br/>";
                 else {
