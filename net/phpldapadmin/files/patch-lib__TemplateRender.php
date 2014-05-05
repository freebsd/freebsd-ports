--- ./lib/TemplateRender.php.orig	2014-05-03 07:58:18.076584893 +0100
+++ ./lib/TemplateRender.php	2014-05-03 07:59:18.859574787 +0100
@@ -2466,7 +2466,7 @@
 		if ($val = $attribute->getValue($i))
 			$default = get_enc_type($val);
 		else
-			$default = $this->getServer()->getValue('appearance','password_hash');
+			$default = $this->getServer()->getValue('appearance','password_hash_custom');
 
 		if (! $attribute->getPostValue())
 			printf('<input type="hidden" name="post_value[%s][]" value="%s" />',$attribute->getName(),$i);
