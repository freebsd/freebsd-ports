--- LibreNMS/Validations/Database/CheckDatabaseSchemaVersion.php.orig	2025-11-17 19:20:29 UTC
+++ LibreNMS/Validations/Database/CheckDatabaseSchemaVersion.php
@@ -45,7 +45,7 @@ class CheckDatabaseSchemaVersion implements Validation
         self::$current = false;
 
         if (! Schema::isCurrent()) {
-            return ValidationResult::fail(trans('validation.validations.database.CheckSchemaVersion.fail_outdated'), './lnms migrate')
+            return ValidationResult::fail(trans('validation.validations.database.CheckSchemaVersion.fail_outdated'), 'sudo lnms migrate')
                 ->setFixer(self::class);
         }
 
