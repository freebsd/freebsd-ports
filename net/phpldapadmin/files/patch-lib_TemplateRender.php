--- lib/TemplateRender.php.orig	2021-12-12 02:35:51 UTC
+++ lib/TemplateRender.php
@@ -291,8 +291,8 @@ class TemplateRender extends PageRender {
 					$formvalues = array_change_key_case($_REQUEST['form']);
 
 					foreach ($filtermatchall[1] as $arg) {
-						$value = $formvalues[strtolower($arg)];
-						$args[1] = preg_replace("/%($arg)(\|.+)?(\/[lU])?%/U",$value,$args[1]);
+						$value = $formvalues[strtolower((string) $arg)];
+						$args[1] = preg_replace("/%($arg)(\|.+)?(\/[lU])?%/U",$value,is_null($args[1])? "":$args[1]);
 					}
 				}
 
@@ -323,7 +323,7 @@ class TemplateRender extends PageRender {
 						$fixedvalue = preg_split('/=\>/',$fixedvalue);
 						$displayvalue = explode('=',$fixedvalue[1]);
 
-						$newvalue[trim($fixedvalue[0])] = array($args[2]=>trim($fixedvalue[0]),trim($displayvalue[0])=>trim($displayvalue[1]));
+						$newvalue[trim((string) $fixedvalue[0])] = array($args[2]=>trim((string) $fixedvalue[0]),trim((string) $displayvalue[0])=>trim((string) $displayvalue[1]));
 
 						$picklistvalues = array_merge($picklistvalues,$newvalue);
 					}
@@ -353,7 +353,7 @@ class TemplateRender extends PageRender {
 									if (function_exists('mb_convert_case'))
 										$disp_val = mb_convert_case($disp_val,MB_CASE_LOWER,'utf-8');
 									else
-										$disp_val = strtolower($disp_val);
+										$disp_val = strtolower((string) $disp_val);
 
 									break;
 
@@ -380,11 +380,11 @@ class TemplateRender extends PageRender {
 							}
 
 						# make value a substring of
-						preg_match_all('/^\|([0-9]*)-([0-9]*)$/',trim($matchall[2][$key]),$substrarray);
+						preg_match_all('/^\|([0-9]*)-([0-9]*)$/',trim((string) $matchall[2][$key]),$substrarray);
 
 						if ((isset($substrarray[1][0]) && $substrarray[1][0]) || (isset($substrarray[2][0]) && $substrarray[2][0])) {
 							$begin = $substrarray[1][0] ? $substrarray[1][0] : '0';
-							$end = $substrarray[2][0] ? $substrarray[2][0] : strlen($disp_val);
+							$end = $substrarray[2][0] ? $substrarray[2][0] : strlen((string) $disp_val);
 
 							if (function_exists('mb_substr'))
 								$disp_val = mb_substr($disp_val,$begin,$end,'utf-8');
@@ -392,7 +392,7 @@ class TemplateRender extends PageRender {
 								$disp_val = substr($disp_val,$begin,$end);
 						}
 
-						$display = preg_replace("/%($arg)(\|.+)?(\/[lUC])?%/U",$disp_val,$display);
+						$display = preg_replace("/%($arg)(\|.+)?(\/[lUC])?%/U",$disp_val,is_null($display)? "":$display);
 					}
 
 					if (! isset($picklist[$values[$args[2]]])) {
@@ -1347,7 +1347,7 @@ class TemplateRender extends PageRender {
 		echo '<td><select name="new_values[objectclass][]" multiple="multiple" size="15">';
 
 		foreach ($socs as $name => $oclass) {
-			if (! strcasecmp('top',$name))
+			if (! strcasecmp('top',(string) $name))
 				continue;
 
 			printf('<option %s value="%s">%s</option>',
@@ -1879,7 +1879,7 @@ function fillRec(id,value) {
 	protected function drawDnValueIconAttribute($attribute,$val) {
 		if (DEBUGTMP) printf('<font size=-2>%s</font><br />',__METHOD__);
 
-		if (strlen($val) <= 0)
+		if (strlen((string) $val) <= 0)
 			printf('<img src="%s/ldap-alias.png" alt="Go" style="float: right;" />&nbsp;',IMGDIR);
 		elseif ($this->getServer()->dnExists($val))
 			printf('<a href="cmd.php?cmd=template_engine&amp;server_id=%s&amp;dn=%s" title="%s %s"><img src="%s/ldap-alias.png" alt="Go" /></a>&nbsp;',
@@ -1892,7 +1892,7 @@ function fillRec(id,value) {
 		if (DEBUGTMP) printf('<font size=-2>%s</font><br />',__METHOD__);
 
 		$img = sprintf('<img src="%s/mail.png" alt="%s" style="float: right;" />',IMGDIR,_('Mail'));
-		if (strlen($val) <= 0)
+		if (strlen((string) $val) <= 0)
 			echo $img;
 		else
 			printf('<a href="mailto:%s">%s</a>',htmlspecialchars($val),$img);
@@ -1905,7 +1905,7 @@ function fillRec(id,value) {
 		$img = sprintf('<img src="%s/ldap-dc.png" alt="%s" style="float: right;" />',IMGDIR,_('URL'));
 		$url = explode(' +',$val,2);
 
-		if (strlen($val) <= 0)
+		if (strlen((string) $val) <= 0)
 			echo $img;
 		else
 			printf('<a href="%s" onclick="target=\'new\';">%s</a>',htmlspecialchars($url[0]),$img);
@@ -2387,7 +2387,7 @@ function deleteAttribute(attrName,friendlyName,i)
 		if (! $_SESSION[APPCONFIG]->getValue('appearance','show_schema_link') || !$_SESSION[APPCONFIG]->isCommandAvailable('script','schema'))
 			return;
 
-		if (strlen($val) > 0) {
+		if (strlen((string) $val) > 0) {
 			$href = sprintf('cmd.php?cmd=schema&server_id=%s&view=objectclasses&viewvalue=%s',
 				$this->getServerID(),$val);
 			printf('<a href="%s" title="%s"><img src="%s/info.png" alt="Info" /></a>&nbsp;',
