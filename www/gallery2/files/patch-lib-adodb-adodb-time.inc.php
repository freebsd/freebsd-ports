Obtained from:	https://github.com/bobosch/gallery2/commit/4ddfafa416ffe5babd95f2a6532742c3ec903275

--- lib/adodb/adodb-time.inc.php.orig
+++ lib/adodb/adodb-time.inc.php
@@ -1006,7 +1006,6 @@ function adodb_tz_offset($gmt,$isphp5)
 		return sprintf('%s%02d%02d',($gmt<=0)?'+':'-',floor($zhrs),($zhrs-$hrs)*60); 
 	else
 		return sprintf('%s%02d%02d',($gmt<0)?'+':'-',floor($zhrs),($zhrs-$hrs)*60); 
-	break;
 }
 
 
