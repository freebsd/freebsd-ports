--- plugins/mail_fetch/functions.php.old	2012-09-08 17:58:39.000000000 -0400
+++ plugins/mail_fetch/functions.php	2012-09-08 18:01:06.000000000 -0400
@@ -92,15 +92,22 @@
     return '';
 }
 
-function hex2bin( $data ) {
-    /* Original code by josh@superfork.com */
+/**
+ * hex2bin - convert a hexadecimal string into binary
+ * Part of php54, so don't try to clobber it
+ */
+if ( ! function_exists('hex2bin') ) {
+	function hex2bin( $data ) {
 
-    $len = strlen($data);
-    $newdata = '';
-    for( $i=0; $i < $len; $i += 2 ) {
-        $newdata .= pack( "C", hexdec( substr( $data, $i, 2) ) );
-    }
-    return $newdata;
+		/* Original code by josh@superfork.com */
+
+		$len = strlen($data);
+		$newdata = '';
+		for( $i=0; $i < $len; $i += 2 ) {
+			$newdata .= pack( "C", hexdec( substr( $data, $i, 2) ) );
+		}
+		return $newdata;
+	}
 }
 
 function mf_keyED( $txt ) {
