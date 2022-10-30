--- src/gsad.c	2022-10-30 17:54:07.766381000 -0500
+++ src/gsad.c	2022-10-30 17:57:38.383048000 -0500
@@ -480,7 +480,7 @@
   gvm_validator_add (validator, "asset_name", "(?s)^.*$");
   gvm_validator_add (validator, "asset_type", "^(host|os)$");
   gvm_validator_add (validator, "asset_id",
-                     "^([[:alnum:]-_.:\\/~()']|&amp;)+$");
+                     "^([[:alnum:]\\-_.:\\/~()']|&amp;)+$");
   gvm_validator_add (validator, "auth_algorithm", "^(md5|sha1)$");
   gvm_validator_add (validator, "auth_method", "^(0|1|2)$");
   /* Defined in RFC 2253. */
@@ -595,7 +595,7 @@
   gvm_validator_add (validator, "list_fname",
                      "^([[:alnum:]_-]|%[%CcDFMmNTtUu])+$");
   /* Used for users, credentials, and scanner login name. */
-  gvm_validator_add (validator, "login", "^[[:alnum:]-_@.]+$");
+  gvm_validator_add (validator, "login", "^[[:alnum:]\\-_@.]+$");
   gvm_validator_add (validator, "lsc_password", "^.*$");
   gvm_validator_add (validator, "max_result", "^[0-9]+$");
   gvm_validator_add (validator, "max_groups", "^-?[0-9]+$");
@@ -605,10 +605,10 @@
   gvm_validator_add (validator, "note_required", "(?s)^(.)+$");
   gvm_validator_add (validator, "note_id", "^[a-z0-9\\-]+$");
   gvm_validator_add (validator, "override_id", "^[a-z0-9\\-]+$");
-  gvm_validator_add (validator, "name", "^[#-_[:alnum:], \\./]*$");
+  gvm_validator_add (validator, "name", "^[#\\-_[:alnum:], \\./]*$");
   gvm_validator_add (validator, "info_name", "(?s)^.*$");
   gvm_validator_add (validator, "info_type", "(?s)^.*$");
-  gvm_validator_add (validator, "info_id", "^([[:alnum:]-_.:\\/~()']|&amp;)+$");
+  gvm_validator_add (validator, "info_id", "^([[:alnum:]\\-_.:\\/~()']|&amp;)+$");
   gvm_validator_add (validator, "details", "^[0-1]$");
   /* Number is special cased in params_mhd_validate to remove the space. */
   gvm_validator_add (validator, "number", "^ *[0-9]+ *$");
@@ -660,7 +660,7 @@
     "filter|group|host|info|nvt|note|os|ovaldef|override|permission|port_list|"
     "report|report_format|result|role|scanner|schedule|tag|target|task|ticket|"
     "tls_certificate|user|vuln|)$");
-  gvm_validator_add (validator, "resource_id", "^[[:alnum:]-_.:\\/~]*$");
+  gvm_validator_add (validator, "resource_id", "^[[:alnum:]\\-_.:\\/~]*$");
   gvm_validator_add (validator, "resources_action", "^(|add|set|remove)$");
   gvm_validator_add (
     validator, "optional_resource_type",
@@ -719,7 +719,7 @@
   gvm_validator_add (validator, "uuid", "^[0-9abcdefABCDEF\\-]{1,40}$");
   gvm_validator_add (validator, "usage_type", "^(audit|policy|scan|)$");
   /* This must be "login" with space and comma. */
-  gvm_validator_add (validator, "users", "^[[:alnum:]-_@., ]*$");
+  gvm_validator_add (validator, "users", "^[[:alnum:]\\-_@., ]*$");
   gvm_validator_add (validator, "x_field", "^[\\[\\]_[:alnum:]]+$");
   gvm_validator_add (validator, "y_fields:name", "^[0-9]+$");
   gvm_validator_add (validator, "y_fields:value", "^[\\[\\]_[:alnum:]]+$");
