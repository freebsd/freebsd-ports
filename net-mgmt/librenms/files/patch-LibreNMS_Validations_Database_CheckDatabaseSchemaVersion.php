--- LibreNMS/Validations/Database/CheckDatabaseSchemaVersion.php.orig	2023-10-27 13:54:39 UTC
+++ LibreNMS/Validations/Database/CheckDatabaseSchemaVersion.php
@@ -44,7 +44,7 @@ class CheckDatabaseSchemaVersion implements Validation
         self::$current = false;
 
         if (! Schema::isCurrent()) {
-            return ValidationResult::fail(trans('validation.validations.database.CheckSchemaVersion.fail_outdated'), './lnms migrate')
+            return ValidationResult::fail(trans('validation.validations.database.CheckSchemaVersion.fail_outdated'), 'sudo lnms migrate')
                 ->setFixer(__CLASS__);
         }
 
