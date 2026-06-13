--- lib/functions.php.orig	2024-01-10 22:23:54 UTC
+++ lib/functions.php
@@ -359,7 +359,7 @@ function memory_str_to_int($value) {
 	$value = trim(strtolower($value));
 	if (intval($value) > 0 && preg_match('/^(\d+)([kmg])?$/', $value, $match, PREG_UNMATCHED_AS_NULL)) {
 		[$int, $mod] = [intval($match[1]), $match[2]];
-		$pow = [NULL => 0, 'k' => 1, 'm' => 2, 'g' => 3][$mod];
+		$pow = ["" => 0, 'k' => 1, 'm' => 2, 'g' => 3][$mod];
 		return $int * 1024 ** $pow;
 	}
 	return intval($value);
@@ -2844,8 +2844,8 @@ function utime() {
  */
 function utime() {
 	$time = explode(' ',microtime());
-	$usec = (double)$time[0];
-	$sec = (double)$time[1];
+	$usec = (float)$time[0];
+	$sec = (float)$time[1];
 	return $sec + $usec;
 }
 
