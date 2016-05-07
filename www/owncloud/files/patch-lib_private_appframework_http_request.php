--- lib/private/appframework/http/request.php.orig	2016-05-04 03:03:50 UTC
+++ lib/private/appframework/http/request.php
@@ -264,6 +264,9 @@ class Request implements \ArrayAccess, \
 	 * @return bool
 	 */
 	public function __isset($name) {
+		if (in_array($name, $this->allowedKeys, true)) {
+			return true;
+		}
 		return isset($this->items['parameters'][$name]);
 	}
 
