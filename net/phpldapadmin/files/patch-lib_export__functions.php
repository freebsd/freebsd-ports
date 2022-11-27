--- lib/export_functions.php.orig	2021-12-12 02:35:51 UTC
+++ lib/export_functions.php
@@ -131,7 +131,7 @@ abstract class Export {
 		$query['size_limit'] = 0;
 		$attrs = get_request('attributes','REQUEST');
 
-		$attrs = preg_replace('/\s+/','',$attrs);
+		$attrs = preg_replace('/\s+/','',is_null($attrs)? "":$attrs);
 		if ($attrs)
 			$query['attrs'] = explode(',',$attrs);
 		else
@@ -222,7 +222,7 @@ abstract class Export {
 	 * @return boolean true if the string is safe ascii, false otherwise.
 	 */
 	protected function isSafeAscii($str) {
-		for ($i=0;$i<strlen($str);$i++)
+		for ($i=0;$i<strlen((string) $str);$i++)
 			if (ord($str[$i]) < 32 || ord($str[$i]) > 127)
 				return false;
 
@@ -478,7 +478,7 @@ class ExportLDIF extends Export {
 
 				$title_string = sprintf('# %s %s: %s%s',_('Entry'),$counter,$dn,$this->br);
 
-				if (strlen($title_string) > $this->line_length-3)
+				if (strlen((string) $title_string) > $this->line_length-3)
 					$title_string = substr($title_string,0,$this->line_length-3).'...'.$this->br;
 
 				$output .= $title_string;
@@ -517,14 +517,14 @@ class ExportLDIF extends Export {
 	 * @param The line to be wrapped if needed.
 	 */
 	private function multiLineDisplay($str) {
-		$length_string = strlen($str);
+		$length_string = strlen((string) $str);
 		$length_max = $this->line_length;
 
 		$output = '';
 		while ($length_string > $length_max) {
 			$output .= substr($str,0,$length_max).$this->br.' ';
 			$str = substr($str,$length_max,$length_string);
-			$length_string = strlen($str);
+			$length_string = strlen((string) $str);
 
 			/* Need to do minus one to align on the right
 			 * the first line with the possible following lines
