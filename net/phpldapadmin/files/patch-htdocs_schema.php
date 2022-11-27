--- htdocs/schema.php.orig	2021-12-12 02:35:51 UTC
+++ htdocs/schema.php
@@ -25,7 +25,7 @@ $entry['value'] = get_request('viewvalue','GET');
 
 if (! is_null($entry['value'])) {
 	$entry['viewed'] = false;
-	$entry['value'] = strtolower($entry['value']);
+	$entry['value'] = strtolower((string) $entry['value']);
 }
 
 $schema_error_str = sprintf('%s <b>%s</b>.<br /><br /></div>%s<ul><li>%s</li><li>%s</li><li>%s</li><li>%s</li></ul>',
@@ -149,12 +149,12 @@ switch($entry['view']) {
 		echo '<br />';
 
 		foreach ($sattrs as $attr) {
-			if (isAjaxEnabled() || (is_null($entry['value']) || ! trim($entry['value']) || $entry['value']==$attr->getName())) {
-				if ((! is_null($entry['value']) && $entry['value']==$attr->getName()) || ! trim($entry['value']))
+			if (isAjaxEnabled() || (is_null($entry['value']) || ! trim((string) $entry['value']) || $entry['value']==$attr->getName())) {
+				if ((! is_null($entry['value']) && $entry['value']==$attr->getName()) || ! trim((string) $entry['value']))
 					$entry['viewed'] = true;
 
 				if (isAjaxEnabled() && $entry['value'])
-					printf('<div id="at%s" style="display: %s">',$attr->getName(),strcasecmp($entry['value'],$attr->getName()) ? 'none' : 'block');
+					printf('<div id="at%s" style="display: %s">',(string) $attr->getName(),strcasecmp((string) $entry['value'],(string) $attr->getName()) ? 'none' : 'block');
 				else
 					printf('<div id="at%s">',$attr->getName());
 
@@ -193,10 +193,10 @@ switch($entry['view']) {
 								printf('(%s)',_('none'));
 
 							else {
-								$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['attributes'],strtolower($attr->getSupAttribute())));
+								$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['attributes'],strtolower((string) $attr->getSupAttribute())));
 								if (isAjaxEnabled())
 									printf('<a href="cmd.php?%s" onclick="return ajSHOWSCHEMA(\'attributes\',\'at\',\'%s\');">%s</a>',
-										$href,strtolower($attr->getSupAttribute()),$attr->getSupAttribute());
+										$href,strtolower((string) $attr->getSupAttribute()),$attr->getSupAttribute());
 								else
 									printf('<a href="cmd.php?%s">%s</a>',$href,$attr->getSupAttribute());
 							}
@@ -287,10 +287,10 @@ switch($entry['view']) {
 
 							else
 								foreach ($attr->getAliases() as $alias) {
-									$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['attributes'],strtolower($alias)));
+									$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['attributes'],strtolower((string) $alias)));
 									if (isAjaxEnabled())
 										printf('<a href="cmd.php?%s" onclick="return ajSHOWSCHEMA(\'attributes\',\'at\',\'%s\');">%s</a>',
-											$href,strtolower($alias),$alias);
+											$href,strtolower((string) $alias),$alias);
 									else
 										printf('<a href="cmd.php?%s">%s</a>',$href,$alias);
 								}
@@ -306,10 +306,10 @@ switch($entry['view']) {
 
 							else
 								foreach ($attr->getUsedInObjectClasses() as $objectclass) {
-									$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['objectclasses'],strtolower($objectclass)));
+									$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['objectclasses'],strtolower((string) $objectclass)));
 									if (isAjaxEnabled())
 										printf('<a href="cmd.php?%s" onclick="return ajJUMP(\'%s\',\'%s\',\'%s\');">%s</a> ',
-											$href,$href,_('ObjectClasses'),strtolower($objectclass),$objectclass);
+											$href,$href,_('ObjectClasses'),strtolower((string) $objectclass),$objectclass);
 									else
 										printf('<a href="cmd.php?%s">%s</a> ',$href,$objectclass);
 								}
@@ -379,8 +379,8 @@ switch($entry['view']) {
 			$oid = $rule->getOID();
 			$desc = $rule->getName(false);
 
-			if (isAjaxEnabled() || (is_null($entry['value']) || ! trim($entry['value']) || $entry['value']==$rule->getName())) {
-				if ((! is_null($entry['value']) && $entry['value']==$rule->getName()) || ! trim($entry['value']))
+			if (isAjaxEnabled() || (is_null($entry['value']) || ! trim((string) $entry['value']) || $entry['value']==$rule->getName())) {
+				if ((! is_null($entry['value']) && $entry['value']==$rule->getName()) || ! trim((string) $entry['value']))
 					$entry['viewed'] = true;
 
 				if (null != $rule->getDescription())
@@ -391,7 +391,7 @@ switch($entry['view']) {
 
 				if (isAjaxEnabled() && $entry['value'])
 					printf('<tr class="%s" id="mr%s" style="display: %s">',$counter%2 ? 'odd' : 'even',$rule->getName(),
-						strcasecmp($entry['value'],$rule->getName()) ? 'none' : '');
+						strcasecmp((string) $entry['value'],(string) $rule->getName()) ? 'none' : '');
 				else
 					printf('<tr class="%s" id="mr%s">',$counter%2 ? 'odd' : 'even',$rule->getName());
 				printf('<td>%s</td>',$oid);
@@ -467,12 +467,12 @@ switch($entry['view']) {
 		echo '<br />';
 
 		foreach ($socs as $name => $oclass) {
-			if (isAjaxEnabled() || (is_null($entry['value']) || ! trim($entry['value']) || $entry['value']==$oclass->getName())) {
-				if ((! is_null($entry['value']) && $entry['value']==$oclass->getName()) || ! trim($entry['value']))
+			if (isAjaxEnabled() || (is_null($entry['value']) || ! trim((string) $entry['value']) || $entry['value']==$oclass->getName())) {
+				if ((! is_null($entry['value']) && $entry['value']==$oclass->getName()) || ! trim((string) $entry['value']))
 					$entry['viewed'] = true;
 
 				if (isAjaxEnabled() && $entry['value'])
-					printf('<div id="oc%s" style="display: %s">',$oclass->getName(),strcasecmp($entry['value'],$oclass->getName()) ? 'none' : '');
+					printf('<div id="oc%s" style="display: %s">',(string) $oclass->getName(),strcasecmp((string) $entry['value'],(string) $oclass->getName()) ? 'none' : '');
 				else
 					printf('<div id="oc%s">',$oclass->getName());
 
@@ -494,10 +494,10 @@ switch($entry['view']) {
 
 				else
 					foreach ($oclass->getSupClasses() as $i => $object_class) {
-						$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['objectclasses'],strtolower($object_class)));
+						$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['objectclasses'],strtolower((string) $object_class)));
 						if (isAjaxEnabled())
 							printf('<a href="cmd.php?%s" onclick="return ajSHOWSCHEMA(\'objectclasses\',\'oc\',\'%s\');">%s</a>',
-								$href,strtolower($object_class),$object_class);
+								$href,strtolower((string) $object_class),$object_class);
 						else
 							printf('<a href="cmd.php?%s&viewvalue=%s" title="%s">%s</a>',
 								$href,$object_class,_('Jump to this objectClass definition'),$object_class);
@@ -508,7 +508,7 @@ switch($entry['view']) {
 				echo '</b></td></tr>';
 
 				printf('<tr class="odd"><td colspan="4">%s: <b>',_('Parent to'));
-				if (strcasecmp($oclass->getName(),'top') == 0) {
+				if (strcasecmp((string) $oclass->getName(),'top') == 0) {
 					$href = htmlspecialchars($entry['href']['objectclasses']);
 					if (isAjaxEnabled())
 						printf('<a href="cmd.php?%s" onclick="return ajSHOWSCHEMA(\'objectclasses\',\'oc\',\'\');">all</a>',
@@ -521,10 +521,10 @@ switch($entry['view']) {
 
 				else
 					foreach ($oclass->getChildObjectClasses() as $i => $object_class) {
-						$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['objectclasses'],strtolower($object_class)));
+						$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['objectclasses'],strtolower((string) $object_class)));
 						if (isAjaxEnabled())
 							printf('<a href="cmd.php?%s" title="%s" onclick="return ajSHOWSCHEMA(\'objectclasses\',\'oc\',\'%s\');">%s</a>',
-								$href,_('Jump to this objectClass definition'),strtolower($object_class),$object_class);
+								$href,_('Jump to this objectClass definition'),strtolower((string) $object_class),$object_class);
 						else
 							printf('<a href="cmd.php?%s" title="%s">%s</a>',$href,_('Jump to this objectClass definition'),$object_class);
 
@@ -553,11 +553,11 @@ switch($entry['view']) {
 
 						if ($attr->getSource() != $oclass->getName(false)) {
 							echo '<br />';
-							$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['objectclasses'],strtolower($attr->getSource())));
+							$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['objectclasses'],strtolower((string) $attr->getSource())));
 							printf('<small>(%s ',_('Inherited from'));
 							if (isAjaxEnabled())
 								printf('<a href="cmd.php?%s" title="%s" onclick="return ajSHOWSCHEMA(\'objectclasses\',\'oc\',\'%s\');">%s</a>',
-									$href,_('Jump to this objectClass definition'),strtolower($attr->getSource()),$attr->getSource());
+									$href,_('Jump to this objectClass definition'),strtolower((string) $attr->getSource()),$attr->getSource());
 							else
 								printf('<a href="cmd.php?%s">%s</a>',$href,$attr->getSource());
 							echo ')</small>';
@@ -586,11 +586,11 @@ switch($entry['view']) {
 
 						if ($attr->getSource() != $oclass->getName(false)) {
 							echo '<br />';
-							$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['objectclasses'],strtolower($attr->getSource())));
+							$href = htmlspecialchars(sprintf('%s&viewvalue=%s',$entry['href']['objectclasses'],strtolower((string) $attr->getSource())));
 							printf('<small>(%s ',_('Inherited from'));
 							if (isAjaxEnabled())
 								printf('<a href="cmd.php?%s" title="%s" onclick="return ajSHOWSCHEMA(\'objectclasses\',\'oc\',\'%s\');">%s</a>',
-									$href,_('Jump to this objectClass definition'),strtolower($attr->getSource()),$attr->getSource());
+									$href,_('Jump to this objectClass definition'),strtolower((string) $attr->getSource()),$attr->getSource());
 							else
 								printf('<a href="cmd.php?%s">%s</a>',$href,$attr->getSource());
 							echo ')</small>';
