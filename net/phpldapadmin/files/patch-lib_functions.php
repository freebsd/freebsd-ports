--- lib/functions.php.orig	2021-12-12 02:35:51 UTC
+++ lib/functions.php
@@ -161,7 +161,7 @@ function app_error_handler($errno,$errstr,$file,$linen
 	}
 
 	# Take out extra spaces in error strings.
-	$errstr = preg_replace('/\s+/',' ',$errstr);
+	$errstr = preg_replace('/\s+/',' ',is_null($errstr)? "":$errstr);
 
 	if ($errno == E_NOTICE) {
 		$body = '<table class="notice">';
@@ -214,9 +214,9 @@ function app_version() {
 		$CACHE = 'UNKNOWN';
 
 	else {
-		$version = rtrim(file_get_contents($version_file));
+		$version = rtrim((string) file_get_contents($version_file));
 
-		$CACHE = preg_replace('/^RELEASE-([0-9\.]+(-.*)*)$/','$1',$version);
+		$CACHE = preg_replace('/^RELEASE-([0-9\.]+(-.*)*)$/','$1',is_null($version)? "":$version);
 
 		# Check if we are a CVS copy.
 		if (preg_match('/^(DEVEL)?$/',$CACHE))
@@ -525,7 +525,8 @@ function debug_log($msg,$level,$indent) {
 
 	# Pull the file/line/method
 	if (is_string($args[0]) && preg_match('/.php$/',$args[0])) {
-		$file = preg_replace('/.php$/','',array_shift($args));
+		$file_a_shift = array_shift($args);
+		$file = preg_replace('/.php$/','',is_null($file_a_shift? "":$file_a_shift));
 		$line = array_shift($args);
 		$method = array_shift($args);
 
@@ -550,7 +551,7 @@ function debug_log($msg,$level,$indent) {
 	}
 
 	if (preg_match('/%%/',$msg))
-		$msg = preg_replace('/%%/',join('|',$fargs),$msg);
+		$msg = preg_replace('/%%/',join('|',$fargs),is_null($msg)? "":$msg);
 	else
 		$msg = vsprintf($msg,array_values($fargs));
 
@@ -761,11 +762,11 @@ function blowfish_encrypt($data,$secret=null) {
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 	# If our secret is null or blank, get the default.
-	if ($secret === null || ! trim($secret))
+	if ($secret === null || ! trim((string) $secret))
 		$secret = $_SESSION[APPCONFIG]->getValue('session','blowfish') ? $_SESSION[APPCONFIG]->getValue('session','blowfish') : session_id();
 
 	# If the secret isnt set, then just return the data.
-	if (! trim($secret))
+	if (! trim((string) $secret))
 		return $data;
 
 	if (! empty($data) && function_exists('openssl_encrypt') && in_array('bf-ecb', openssl_get_cipher_methods())) {
@@ -791,10 +792,10 @@ function blowfish_encrypt($data,$secret=null) {
 	$pma_cipher = new Horde_Cipher_blowfish;
 	$encrypt = '';
 
-	for ($i=0; $i<strlen($data); $i+=8) {
+	for ($i=0; $i<strlen((string) $data); $i+=8) {
 		$block = substr($data, $i, 8);
 
-		if (strlen($block) < 8)
+		if (strlen((string) $block) < 8)
 			$block = full_str_pad($block,8,"\0", 1);
 
 		$encrypt .= $pma_cipher->encryptBlock($block, $secret);
@@ -822,11 +823,11 @@ function blowfish_decrypt($encdata,$secret=null) {
 		return $CACHE[$encdata];
 
 	# If our secret is null or blank, get the default.
-	if ($secret === null || ! trim($secret))
+	if ($secret === null || ! trim((string) $secret))
 		$secret = $_SESSION[APPCONFIG]->getValue('session','blowfish') ? $_SESSION[APPCONFIG]->getValue('session','blowfish') : session_id();
 
 	# If the secret isnt set, then just return the data.
-	if (! trim($secret))
+	if (! trim((string) $secret))
 		return $encdata;
 
 	if (! empty($encdata) && function_exists('openssl_encrypt') && in_array('bf-ecb', openssl_get_cipher_methods())) {
@@ -838,7 +839,7 @@ function blowfish_decrypt($encdata,$secret=null) {
 		$td = mcrypt_module_open(MCRYPT_BLOWFISH,'',MCRYPT_MODE_ECB,'');
 		$iv = mcrypt_create_iv(mcrypt_enc_get_iv_size($td),MCRYPT_DEV_URANDOM);
 		mcrypt_generic_init($td,substr($secret,0,mcrypt_enc_get_key_size($td)),$iv);
-		$decrypted_data = trim(mdecrypt_generic($td,base64_decode($encdata)));
+		$decrypted_data = trim((string) mdecrypt_generic($td,base64_decode($encdata)));
 		mcrypt_generic_deinit($td);
 
 		return $decrypted_data;
@@ -853,11 +854,11 @@ function blowfish_decrypt($encdata,$secret=null) {
 	$decrypt = '';
 	$data = base64_decode($encdata);
 
-	for ($i=0; $i<strlen($data); $i+=8)
+	for ($i=0; $i<strlen((string) $data); $i+=8)
 		$decrypt .= $pma_cipher->decryptBlock(substr($data, $i, 8), $secret);
 
 	// Strip off our \0's that were added.
-	$return = preg_replace("/\\0*$/",'',$decrypt);
+	$return = preg_replace("/\\0*$/",'',is_null($decrypt)? "":$decrypt);
 	$CACHE[$encdata] = $return;
 	return $return;
 }
@@ -876,7 +877,7 @@ function full_str_pad($input,$pad_length,$pad_string='
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 	$str = '';
-	$length = $pad_length - strlen($input);
+	$length = $pad_length - strlen((string) $input);
 
 	if ($length > 0) { // str_repeat doesn't like negatives
 		if ($pad_type == STR_PAD_RIGHT) { // STR_PAD_RIGHT == 1
@@ -1090,7 +1091,7 @@ function masort(&$data,$sortby,$rev=0) {
 			$code .= "	\$a = array_change_key_case(\$a);\n";
 			$code .= "	\$b = array_change_key_case(\$b);\n";
 
-			$key = strtolower($key);
+			$key = strtolower((string) $key);
 
 			$code .= "	if ((! isset(\$a['$key'])) && isset(\$b['$key'])) return 1;\n";
 			$code .= "	if (isset(\$a['$key']) && (! isset(\$b['$key']))) return -1;\n";
@@ -1248,7 +1249,7 @@ function is_dn_string($str) {
 		$left = $sub_parts[0];
 		$right = $sub_parts[1];
 
-		if ( ! strlen(trim($left)) || ! strlen(trim($right)))
+		if ( ! strlen((string) trim((string) $left)) || ! strlen((string) trim((string) $right)))
 			return false;
 
 		if (strpos($left,'#') !== false)
@@ -1343,7 +1344,7 @@ function pla_compare_dns($dn1,$dn2) {
 			$dn2 = implode('+',$dn2);
 
 	# If they are obviously the same, return immediately
-	if (! strcasecmp($dn1,$dn2))
+	if (! strcasecmp((string) $dn1,(string) $dn2))
 		return 0;
 
 	$dn1_parts = pla_explode_dn(pla_reverse_dn($dn1));
@@ -1364,15 +1365,15 @@ function pla_compare_dns($dn1,$dn2) {
 		$dn1_sub_parts = explode('=',$dn1_part,2);
 		$dn2_sub_parts = explode('=',$dn2_part,2);
 
-		$dn1_sub_part_attr = trim($dn1_sub_parts[0]);
-		$dn2_sub_part_attr = trim($dn2_sub_parts[0]);
+		$dn1_sub_part_attr = trim((string) $dn1_sub_parts[0]);
+		$dn2_sub_part_attr = trim((string) $dn2_sub_parts[0]);
 
-		if (0 != ($cmp = strcasecmp($dn1_sub_part_attr,$dn2_sub_part_attr)))
+		if (0 != ((string) $cmp = strcasecmp((string) $dn1_sub_part_attr,(string) $dn2_sub_part_attr)))
 			return $cmp;
 
-		$dn1_sub_part_val = trim($dn1_sub_parts[1]);
-		$dn2_sub_part_val = trim($dn2_sub_parts[1]);
-		if (0 != ($cmp = strcasecmp($dn1_sub_part_val,$dn2_sub_part_val)))
+		$dn1_sub_part_val = trim((string) $dn1_sub_parts[1]);
+		$dn2_sub_part_val = trim((string) $dn2_sub_parts[1]);
+		if (0 != ((string) $cmp = strcasecmp((string) $dn1_sub_part_val,(string) $dn2_sub_part_val)))
 			return $cmp;
 	}
 
@@ -1430,7 +1431,7 @@ function get_next_number($base,$attr,$increment=false,
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 	$server = $_SESSION[APPCONFIG]->getServer(get_request('server_id','REQUEST'));
-	$attr = strtolower($attr);
+	$attr = strtolower((string) $attr);
 	$query = array();
 
 	if (! $server->getValue('auto_number','enable')) {
@@ -1457,7 +1458,7 @@ function get_next_number($base,$attr,$increment=false,
 	if (! $base) {
 		$query['base'] = $server->getValue('auto_number','search_base');
 
-		if (! trim($query['base'])) {
+		if (! trim((string) $query['base'])) {
 			system_message(array(
 				'title'=>_('No AUTO_NUMBER search_base configured for this server'),
 				'body'=>_('A call was made to get_next_number(), however, the base to search is empty.'),
@@ -1628,7 +1629,7 @@ function get_icon($server_id,$dn,$object_classes=array
 		$object_classes = $server->getDNAttrValue($dn,'objectClass');
 
 	foreach ($object_classes as $index => $value)
-		$object_classes[$index] = strtolower($value);
+		$object_classes[$index] = strtolower((string) $value);
 
 	$rdn = get_rdn($dn);
 	$rdn_parts = explode('=',$rdn,2);
@@ -1638,7 +1639,7 @@ function get_icon($server_id,$dn,$object_classes=array
 
 	# Return icon filename based upon objectClass value
 	if (in_array('sambaaccount',$object_classes) &&
-		'$' == $rdn[ strlen($rdn) - 1 ])
+		'$' == $rdn[ strlen((string) $rdn) - 1 ])
 		return 'nt_machine.png';
 
 	if (in_array('sambaaccount',$object_classes))
@@ -1688,9 +1689,9 @@ function get_icon($server_id,$dn,$object_classes=array
 		$cval = explode('=',$tmp[0],2);
 		$cval = isset($cval[1]) ? $cval[1] : false;
 		if ($cval && false === strpos($cval,'..') &&
-			file_exists(realpath(sprintf('%s/../countries/%s.png',IMGDIR,strtolower($cval)))))
+			file_exists(realpath(sprintf('%s/../countries/%s.png',IMGDIR,strtolower((string) $cval)))))
 
-			return sprintf('../countries/%s.png',strtolower($cval));
+			return sprintf('../countries/%s.png',strtolower((string) $cval));
 
 		else
 			return 'country.png';
@@ -1777,13 +1778,13 @@ function get_icon($server_id,$dn,$object_classes=array
 		return 'hard-drive.png';
 
 	elseif (strpos($rdn_value,'ipsec') === 0 ||
-		strcasecmp($rdn_value,'IP Security') == 0||
-		strcasecmp($rdn_value,'MSRADIUSPRIVKEY Secret') == 0 ||
+		strcasecmp((string) $rdn_value,'IP Security') == 0||
+		strcasecmp((string) $rdn_value,'MSRADIUSPRIVKEY Secret') == 0 ||
 		strpos($rdn_value,'BCKUPKEY_') === 0)
 
 		return 'lock.png';
 
-	elseif (strcasecmp($rdn_value,'MicrosoftDNS') == 0)
+	elseif (strcasecmp((string) $rdn_value,'MicrosoftDNS') == 0)
 		return 'ldap-dc.png';
 
 	# Oh well, I don't know what it is. Use a generic icon.
@@ -1802,7 +1803,7 @@ function expand_dn_with_base($base,$sub_dn) {
 	if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-	$empty_str = (is_null($sub_dn) || (($len=strlen(trim($sub_dn))) == 0));
+	$empty_str = (is_null($sub_dn) || (($len=strlen((string) trim((string) $sub_dn))) == 0));
 
 	if ($empty_str)
 		return $base;
@@ -1927,7 +1928,7 @@ function pla_verbose_error($key) {
 			$hex_code = isset($entry[1]) ? $entry[1] : null;
 			$title = isset($entry[2]) ? $entry[2] : null;
 			$desc = isset($entry[3]) ? $entry[3] : null;
-			$desc = preg_replace('/\s+/',' ',$desc);
+			$desc = preg_replace('/\s+/',' ',is_null($desc)? "":$desc);
 			$CACHE[$hex_code] = array('title'=>$title,'desc'=>$desc);
 		}
 	}
@@ -1984,7 +1985,7 @@ function support_oid_to_text($key) {
 				$CACHE[$oid_id]['title'] = isset($entry[4]) ? $entry[4] : null;
 				$CACHE[$oid_id]['ref'] = isset($entry[6]) ? $entry[6] : null;
 				$desc = isset($entry[8]) ? $entry[8] : sprintf('<acronym title="%s">%s</acronym>',$unknown['desc'],$unknown['title']);
-				$CACHE[$oid_id]['desc'] = preg_replace('/\s+/',' ',$desc);
+				$CACHE[$oid_id]['desc'] = preg_replace('/\s+/',' ',is_null($desc)? "":$desc);
 			}
 		}
 	}
@@ -2164,7 +2165,7 @@ function pla_password_hash($password_clear,$enc_type) 
 	if (DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-	$enc_type = strtolower($enc_type);
+	$enc_type = strtolower((string) $enc_type);
 
 	switch($enc_type) {
 		case 'blowfish':
@@ -2335,7 +2336,7 @@ function password_check($cryptedpassword,$plainpasswor
 
 	if (preg_match('/{([^}]+)}(.*)/',$cryptedpassword,$matches)) {
 		$cryptedpassword = $matches[2];
-		$cypher = strtolower($matches[1]);
+		$cypher = strtolower((string) $matches[1]);
 
 	} else {
 		$cypher = null;
@@ -2389,7 +2390,7 @@ function password_check($cryptedpassword,$plainpasswor
 
 		# SHA crypted passwords
 		case 'sha':
-			if (strcasecmp(pla_password_hash($plainpassword,'sha'),'{SHA}'.$cryptedpassword) == 0)
+			if (strcasecmp(pla_password_hash((string) $plainpassword,'sha'),'{SHA}'.(string) $cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2398,7 +2399,7 @@ function password_check($cryptedpassword,$plainpasswor
 
 		# MD5 crypted passwords
 		case 'md5':
-			if( strcasecmp(pla_password_hash($plainpassword,'md5'),'{MD5}'.$cryptedpassword) == 0)
+			if( strcasecmp(pla_password_hash((string) $plainpassword,'md5'),'{MD5}'.(string) $cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2463,7 +2464,7 @@ function password_check($cryptedpassword,$plainpasswor
 
 		# SHA256 crypted passwords
 		case 'sha256':
-			if (strcasecmp(pla_password_hash($plainpassword,'sha256'),'{SHA256}'.$cryptedpassword) == 0)
+			if (strcasecmp(pla_password_hash((string) $plainpassword,'sha256'),'{SHA256}'.(string) $cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2485,7 +2486,7 @@ function password_check($cryptedpassword,$plainpasswor
 
 		# SHA384 crypted passwords
 		case 'sha384':
-			if (strcasecmp(pla_password_hash($plainpassword,'sha384'),'{SHA384}'.$cryptedpassword) == 0)
+			if (strcasecmp(pla_password_hash((string) $plainpassword,'sha384'),'{SHA384}'.(string) $cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2507,7 +2508,7 @@ function password_check($cryptedpassword,$plainpasswor
 
 		# SHA512 crypted passwords
 		case 'sha512':
-			if (strcasecmp(pla_password_hash($plainpassword,'sha512'),'{SHA512}'.$cryptedpassword) == 0)
+			if (strcasecmp(pla_password_hash((string) $plainpassword,'sha512'),'{SHA512}'.(string) $cryptedpassword) == 0)
 				return true;
 			else
 				return false;
@@ -2554,12 +2555,12 @@ function get_enc_type($user_password) {
 	$enc_type = null;
 
 	if (preg_match('/{([^}]+)}/',$user_password,$enc_type))
-		$enc_type = strtolower($enc_type[1]);
+		$enc_type = strtolower((string) $enc_type[1]);
 	else
 		return null;
 
 	# Handle crypt types
-	if (strcasecmp($enc_type,'crypt') == 0) {
+	if (strcasecmp((string) $enc_type,'crypt') == 0) {
 
 		# No need to check for standard crypt, because enc_type is already equal to 'crypt'.
 		if (preg_match('/{[^}]+}\\$1\\$+/',$user_password))
@@ -2698,9 +2699,9 @@ function dn_escape($dn) {
 
 	# Check if the RDN has a comma and escape it.
 	while (preg_match('/([^\\\\]),(\s*[^=]*\s*),/',$dn))
-		$dn = preg_replace('/([^\\\\]),(\s*[^=]*\s*),/','$1\\\\2C$2,',$dn);
+		$dn = preg_replace('/([^\\\\]),(\s*[^=]*\s*),/','$1\\\\2C$2,',is_null($dn)? "":$dn);
 
-	$dn = preg_replace('/([^\\\\]),(\s*[^=]*\s*)([^,])$/','$1\\\\2C$2$3',$dn);
+	$dn = preg_replace('/([^\\\\]),(\s*[^=]*\s*)([^,])$/','$1\\\\2C$2$3',is_null($dn)? "":$dn);
 
 	if (DEBUG_ENABLED)
 		debug_log('Returning (%s)',1,0,__FILE__,__LINE__,__METHOD__,$dn);
@@ -2872,17 +2873,17 @@ function sortAttrs($a,$b) {
 	$b_key = array_search($b->getName(),$attrs_display_order);
 
 	if ((! $a_key) && ($a_key !== 0))
-		if ((! $a_key = array_search(strtolower($a->getFriendlyName()),$attrs_display_order)) && ($a_key !== 0))
+		if ((! $a_key = array_search(strtolower((string) $a->getFriendlyName()),$attrs_display_order)) && ($a_key !== 0))
 			$a_key = count($attrs_display_order)+1;
 
 	if ((! $b_key) && ($b_key !== 0))
-		if ((! $b_key = array_search(strtolower($b->getFriendlyName()),$attrs_display_order)) && ($b_key !== 0))
+		if ((! $b_key = array_search(strtolower((string) $b->getFriendlyName()),$attrs_display_order)) && ($b_key !== 0))
 			$b_key = count($attrs_display_order)+1;
 
 	# Case where neither $a, nor $b are in $attrs_display_order, $a_key = $b_key = one greater than num elements.
 	# So we sort them alphabetically
 	if ($a_key === $b_key)
-		return strcasecmp($a->getFriendlyName(),$b->getFriendlyName());
+		return strcasecmp((string) $a->getFriendlyName(),(string) $b->getFriendlyName());
 
 	# Case where at least one attribute or its friendly name is in $attrs_display_order
 	# return -1 if $a before $b in $attrs_display_order
@@ -2904,7 +2905,7 @@ function arrayLower($array) {
 
 	$newarray = array();
 	foreach ($array as $key => $value)
-		$newarray[$key] = strtolower($value);
+		$newarray[$key] = strtolower((string) $value);
 
 	return $newarray;
 }
@@ -2929,7 +2930,7 @@ function in_array_ignore_case($needle,$haystack) {
 	$return = false;
 
 	foreach ($haystack as $element) {
-		if (is_string($element) && (strcasecmp($needle,$element) == 0)) {
+		if (is_string((string) $element) && (strcasecmp((string) $needle,(string) $element) == 0)) {
 			$return = true;
 			break;
 		}
@@ -2961,13 +2962,13 @@ function draw_formatted_dn($server,$entry) {
 			debug_log('The tokens are (%s)',1,0,__FILE__,__LINE__,__METHOD__,$tokens);
 
 		foreach ($tokens as $token) {
-			if (strcasecmp($token,'%dn') == 0)
+			if (strcasecmp((string) $token,'%dn') == 0)
 				$format = str_replace($token,pretty_print_dn($dn),$format);
 
-			elseif (strcasecmp($token,'%rdn') == 0)
+			elseif (strcasecmp((string) $token,'%rdn') == 0)
 				$format = str_replace($token,pretty_print_dn($entry->getRDN()),$format);
 
-			elseif (strcasecmp($token,'%rdnvalue') == 0) {
+			elseif (strcasecmp((string) $token,'%rdnvalue') == 0) {
 				$rdn = get_rdn($dn,0,true);
 				$rdn_value = explode('=',$rdn,2);
 				$rdn_value = $rdn_value[1];
@@ -3046,7 +3047,7 @@ function littleEndian($hex) {
 
 	$result = '';
 
-	for ($x=strlen($hex)-2;$x>= 0;$x=$x-2)
+	for ($x=strlen((string) $hex)-2;$x>= 0;$x=$x-2)
 		$result .= substr($hex,$x,2);
 
 	return $result;
@@ -3088,7 +3089,7 @@ function return_ldap_hash($base,$filter,$key,$attrs,$s
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
 	$server = $_SESSION[APPCONFIG]->getServer(get_request('server_id','REQUEST'));
-	$key = strtolower($key);
+	$key = strtolower((string) $key);
 
 	$query = array();
 	$query['base'] = $base;
@@ -3103,21 +3104,21 @@ function return_ldap_hash($base,$filter,$key,$attrs,$s
 			if (is_array($values[$key]))
 				foreach ($values[$key] as $i => $k)
 					foreach ($attrs as $attr) {
-						$lattr = strtolower($attr);
+						$lattr = strtolower((string) $attr);
 						if (isset($values[$lattr])) {
 							$v = '';
 
 							if (is_array($values[$lattr]) && isset($values[$lattr][$i]))
 								$v = $values[$lattr][$i];
 
-							if (is_string($v) && (strlen($v) > 0))
+							if (is_string($v) && (strlen((string) $v) > 0))
 								$results[$k][$attr] = $v;
 						}
 					}
 
 			else
 				foreach ($attrs as $attr) {
-					$lattr = strtolower($attr);
+					$lattr = strtolower((string) $attr);
 					if (isset($values[$lattr]))
 						$results[$values[$key]][$attr] = $values[$lattr];
 				}
@@ -3263,7 +3264,7 @@ function random_junk() {
  * @return string
  */
 function htmlid($sid,$dn) {
-	return sprintf('SID%s:%s',$sid,preg_replace('/[\ =,]/','_',$dn));
+	return sprintf('SID%s:%s',$sid,preg_replace('/[\ =,]/','_',is_null($dn)? "":$dn));
 }
 
 /**
