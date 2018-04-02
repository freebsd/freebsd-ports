--- lib/TemplateRender.php.orig	2012-10-01 06:54:14 UTC
+++ lib/TemplateRender.php
@@ -2466,7 +2466,7 @@ function deleteAttribute(attrName,friend
 		if ($val = $attribute->getValue($i))
 			$default = get_enc_type($val);
 		else
-			$default = $this->getServer()->getValue('appearance','password_hash');
+			$default = $this->getServer()->getValue('appearance','password_hash_custom');
 
 		if (! $attribute->getPostValue())
 			printf('<input type="hidden" name="post_value[%s][]" value="%s" />',$attribute->getName(),$i);
