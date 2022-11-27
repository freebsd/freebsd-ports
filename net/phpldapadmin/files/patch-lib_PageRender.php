--- lib/PageRender.php.orig	2021-12-12 02:35:51 UTC
+++ lib/PageRender.php
@@ -182,7 +182,7 @@ class PageRender extends Visitor {
 						$attribute2 = $this->template->getAttribute($joinattr);
 
 						if (! $attribute2) {
-							if (($pv = get_request(strtolower($joinattr),'REQUEST')) && isset($pv[$attribute->getName()][$i])) {
+							if (($pv = get_request(strtolower((string) $joinattr),'REQUEST')) && isset($pv[$attribute->getName()][$i])) {
 								array_push($values,$pv[$attribute->getName()][$i]);
 
 								if (! $pv[$attribute->getName()][$i])
@@ -242,7 +242,7 @@ class PageRender extends Visitor {
 					return;
 
 				# Get the attribute.
-				if (preg_match_all('/%(\w+)(\|.+)?(\/[lU])?%/U',strtolower($args[1]),$matchall)) {
+				if (preg_match_all('/%(\w+)(\|.+)?(\/[lU])?%/U',strtolower((string) $args[1]),$matchall)) {
 					if (count($matchall[1]) != 1)
 						system_message(array(
 							'title'=>_('Invalid value count for PasswordEncrypt'),
@@ -255,11 +255,11 @@ class PageRender extends Visitor {
 				} else
 					$passwordvalue = $args[1];
 
-				if (! trim($passwordvalue) || in_array($passwordvalue,$attribute->getOldValues()))
+				if (! trim((string) $passwordvalue) || in_array($passwordvalue,$attribute->getOldValues()))
 					return;
 
 				# Get the encoding
-				if ($passwordattr && preg_match_all('/%(\w+)(\|.+)?(\/[lU])?%/U',strtolower($args[0]),$matchall)) {
+				if ($passwordattr && preg_match_all('/%(\w+)(\|.+)?(\/[lU])?%/U',strtolower((string) $args[0]),$matchall)) {
 					if (count($matchall[1]) != 1)
 						system_message(array(
 							'title'=>_('Invalid value count for PasswordEncrypt'),
@@ -271,7 +271,7 @@ class PageRender extends Visitor {
 				} else
 					$enc = $args[0];
 
-				$enc = strtolower($enc);
+				$enc = strtolower((string) $enc);
 
 				switch ($enc) {
 					case 'lm':
@@ -403,7 +403,7 @@ class PageRender extends Visitor {
 			$alias_note = $this->get($note,$attribute);
 
 			if ($alias_note) {
-				if (trim($attr_note))
+				if (trim((string) $attr_note))
 					$attr_note .= ', ';
 
 				$attr_note .= $alias_note;
@@ -423,7 +423,7 @@ class PageRender extends Visitor {
 		# Is there a user-friendly translation available for this attribute?
 		$friendly_name = $attribute->getFriendlyName();
 
-		if (strtolower($friendly_name) != $attribute->getName())
+		if (strtolower((string) $friendly_name) != $attribute->getName())
 			return sprintf('<acronym title="%s: \'%s\' %s \'%s\'">%s</acronym>',
 				_('Note'),$friendly_name,_('is an alias for'),$attribute->getName(false),_('alias'));
 		else
@@ -954,7 +954,7 @@ class PageRender extends Visitor {
 		$server = $this->getServer();
 		$val = $attribute->getValue($i);
 
-		if (trim($val))
+		if (trim((string) $val))
 			$enc_type = get_enc_type($val);
 		else
 			$enc_type = $server->getValue('appearance','pla_password_hash');
@@ -966,7 +966,7 @@ class PageRender extends Visitor {
 			htmlspecialchars($attribute->getName()),$i,htmlspecialchars($attribute->getName()),
 			$i,htmlspecialchars($val),($attribute->getSize() > 0) ? 'size="'.$attribute->getSize().'"' : '');
 
-		if (trim($val))
+		if (trim((string) $val))
 			$this->draw('CheckLink',$attribute,'new_values_'.htmlspecialchars($attribute->getName()).'_'.$i);
 	}
 
@@ -979,7 +979,7 @@ class PageRender extends Visitor {
 		$enc_type = get_enc_type($val);
 
 		# Set the default hashing type if the password is blank (must be newly created)
-		if (trim($val))
+		if (trim((string) $val))
 			$enc_type = get_enc_type($val);
 		else
 			$enc_type = $server->getValue('appearance','pla_password_hash');
@@ -1125,7 +1125,7 @@ class PageRender extends Visitor {
 
 			foreach ($attribute->getSelection() as $value => $description) {
 				printf('<option value="%s" %s>%s</option>',$value,
-					((strcasecmp($value,$val) == 0) && $found = true) ? 'selected="selected"' : '',$description);
+					((strcasecmp((string) $value,(string) $val) == 0) && (string) $found = true) ? 'selected="selected"' : '',(string) $description);
 
 				if ($value == '')
 					$empty_value = true;
@@ -1140,7 +1140,7 @@ class PageRender extends Visitor {
 				echo "\n";
 			}
 
-			if ((strlen($val) > 0) && ! $empty_value && $this->template->getDN()) {
+			if ((strlen((string) $val) > 0) && ! $empty_value && $this->template->getDN()) {
 				printf('<option value="">(%s)</option>',_('none, remove value'));
 				echo "\n";
 			}
@@ -1212,11 +1212,11 @@ class PageRender extends Visitor {
 		$today = date('U');
 
 		echo '<br/><small>';
-		if (($today < $shadow_date) && in_array(strtolower($attribute->getName()),$shadow_before_today_attrs))
+		if (($today < $shadow_date) && in_array(strtolower((string) $attribute->getName()),$shadow_before_today_attrs))
 			printf('<span style="color:red">(%s)</span>',
 				strftime($_SESSION[APPCONFIG]->getValue('appearance','date'),$shadow_date));
 
-		elseif (($today > $shadow_date) && in_array(strtolower($attribute->getName()),$shadow_after_today_attrs))
+		elseif (($today > $shadow_date) && in_array(strtolower((string) $attribute->getName()),$shadow_after_today_attrs))
 			printf('<span style="color:red">(%s)</span>',
 				strftime($_SESSION[APPCONFIG]->getValue('appearance','date'),$shadow_date));
 
