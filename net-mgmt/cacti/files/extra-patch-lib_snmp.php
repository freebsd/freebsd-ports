--- lib/snmp.php.orig	2019-01-14 19:28:50 UTC
+++ lib/snmp.php
@@ -870,6 +870,9 @@ function snmp_escape_string($string) {
 function snmp_get_method($type = 'walk', $version = 1, $context = '', $engineid = '',
 	$value_output_format = SNMP_STRING_OUTPUT_GUESS) {
 
+	/* override PHP SNMP calls and use the binary instead, fixes some broken graph issues */
+	return SNMP_METHOD_BINARY;
+
 	if ($value_output_format == SNMP_STRING_OUTPUT_HEX) {
 		return SNMP_METHOD_BINARY;
 	} elseif ($version == 3 && $context != '') {
