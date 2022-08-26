--- Net/IPv6.php.orig	2022-08-11 20:00:46 UTC
+++ Net/IPv6.php
@@ -117,6 +117,19 @@ define("NET_IPV6_UNKNOWN_TYPE", 1001);
 define("NET_IPV6_UNKNOWN_TYPE", 1001);
 
 // }}}
+// {{{ compatability
+
+/* define str_ends_with() for php < 8 */
+if (! function_exists('str_ends_with')) {
+    function str_ends_with(string $haystack, string $needle): bool
+    {
+        $needle_len = strlen($needle);
+        return ($needle_len === 0 ||
+                substr_compare($haystack, $needle, - $needle_len) === 0);
+    }
+}
+
+// }}}
 // {{{ Net_IPv6
 
 /**
@@ -224,6 +237,27 @@ class Net_IPv6
     }
 
     // }}}
+    // {{{ removeZone()
+
+    /**
+     * Removes a zone from a non-global presentation address if it exists
+     *
+     * @param String $ip a valid ipv6 link local address
+     *
+     * @return String the address without a zone
+     * @access public
+     * @static
+     * @author Reid Linnemann <rlinnemann@netgate.com>
+     */
+    public static function removeZone($ip)
+    {
+
+        $ip = explode('%', $ip)[0];
+
+        return $ip;
+
+    }
+    // }}}
     // {{{ getNetmaskSpec()
 
     /**
@@ -324,6 +358,33 @@ class Net_IPv6
     }
 
     // }}}
+    // {{{ getZone()
+
+    /**
+     * Returns zone from a non-global presentation address if it exists
+     *
+     * @param String $ip a valid ipv6 link local address
+     *
+     * @return String a zone or empty string if none exists
+     * @access public
+     * @static
+     * @author Reid Linnemann <rlinnemann@netgate.com>
+     */
+    public static function getZone($ip)
+    {
+
+        $items = explode('%', $ip);
+
+        if (count($items) > 1) {
+
+            return array_pop($items);
+
+        }
+
+        return '';
+
+    }
+    // }}}
     // {{{ isInNetmask()
 
     /**
@@ -549,6 +610,8 @@ class Net_IPv6
 
         }
 
+        $zone = Net_IPv6::getZone($ip);
+        $ip = Net_IPv6::removeZone($ip);
         $netmask = Net_IPv6::getNetmaskSpec($ip);
         $uip     = Net_IPv6::removeNetmaskSpec($ip);
 
@@ -639,6 +702,12 @@ class Net_IPv6
             $uip = implode(':', $uipT);
         }
 
+        if ('' != $zone) {
+
+            $uip = $uip.'%'.$zone;
+
+        }
+
         if ('' != $netmask) {
 
                 $uip = $uip.'/'.$netmask;
@@ -696,6 +765,9 @@ class Net_IPv6
 
         }
 
+        $zone = Net_IPv6::getZone($ip);
+        $ip = Net_IPv6::removeZone($ip);
+
         $prefix = Net_IPv6::getPrefixLength($ip);
 
         if (false === $prefix) {
@@ -709,7 +781,7 @@ class Net_IPv6
 
         }
         
-        $split = Net_IPv6::splitV64($ip);
+        $split = Net_IPv6::SplitV64($ip);
         $ip = $split[0];
 
         $netmask = Net_IPv6::getNetmaskSpec($ip);
@@ -750,9 +822,20 @@ class Net_IPv6
         }
 
         if ('' != $split[1]) { // add ipv4 part is available
-            $cip = $cip.$split[1];
+            if(str_ends_with($cip, ':')) {
+                $sep = '';
+            } else {
+                $sep = ':';
+            }
+            $cip = $cip.$sep.$split[1];
         }
-        
+
+        if ('' != $zone) {
+
+            $cip = $cip.'%'.$zone;
+
+        }
+
         if ('' != $netmask) {
 
             $cip = $cip.'/'.$netmask;
@@ -807,7 +890,7 @@ class Net_IPv6
     public static function isCompressible($ip)
     {
 
-        return (bool)($ip != Net_IPv6::compress($address));
+        return (bool)($ip != Net_IPv6::compress($ip));
 
     }
 
@@ -820,6 +903,9 @@ class Net_IPv6
      * RFC 2373 allows you to note the last two parts of an IPv6 address as
      * an IPv4 compatible address
      *
+     * Note that any zone will necessarily be stripped from the IPv6 part that
+     * is returned
+     *
      * Example:  0:0:0:0:0:0:13.1.68.3
      *           0:0:0:0:0:FFFF:129.144.52.38
      *
@@ -837,6 +923,7 @@ class Net_IPv6
      */
     public static function SplitV64($ip, $uncompress = true)
     {
+        $ip = Net_IPv6::removeZone($ip);
         $ip = Net_IPv6::removeNetmaskSpec($ip);
 
         if ($uncompress) {
@@ -853,10 +940,10 @@ class Net_IPv6
                 return array("", $ip);
             }
 
-            $ip{$pos} = '_';
+            $ip[$pos] = '_';
             $ipPart   = explode('_', $ip);
             
-            if ($ip{$pos-1} === ":") {
+            if ($ip[$pos-1] === ":") {
                 $ipPart[0] .= ":";
             }
 
@@ -885,7 +972,6 @@ class Net_IPv6
      */
     public static function checkIPv6($ip)
     {
-
         $elements = Net_IPv6::separate($ip);
 
         $ip = $elements[0];
@@ -1057,13 +1143,13 @@ class Net_IPv6
     protected static function _ip2Bin($ip)
     {
         $binstr = '';
-
+        $ip = Net_IPv6::removeZone($ip);
         $ip = Net_IPv6::removeNetmaskSpec($ip);
 
         // Correctly convert IPv4 mapped addresses (::ffff:x.x.x.x)
         list(, $ipv4) = Net_IPv6::SplitV64($ip, FALSE);
         if (strlen($ipv4)) {
-            $ipv4map = explode('.', $ipv4, 4);
+            $ipv4map = array_map("intval", explode('.', $ipv4, 4));
             $ipv4replace = dechex($ipv4map[0] * 256 + $ipv4map[1]) . ':' . dechex($ipv4map[2] * 256 + $ipv4map[3]);
             $ip = str_replace($ipv4, $ipv4replace, $ip);
         }
