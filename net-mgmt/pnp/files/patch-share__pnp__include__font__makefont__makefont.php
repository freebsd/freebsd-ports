--- ./share/pnp/include/font/makefont/makefont.php.orig	2010-05-29 23:27:44.000000000 +0200
+++ ./share/pnp/include/font/makefont/makefont.php	2010-05-29 23:30:23.000000000 +0200
@@ -171,7 +171,7 @@
 	//StemV
 	if(isset($fm['StdVW']))
 		$stemv=$fm['StdVW'];
-	elseif(isset($fm['Weight']) and eregi('(bold|black)',$fm['Weight']))
+	elseif(isset($fm['Weight']) and preg_match('/(bold|black)/i',$fm['Weight']))
 		$stemv=120;
 	else
 		$stemv=70;
