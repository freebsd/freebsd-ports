--- vendor/pear-pear.php.net/Net_Sieve/Net/Sieve.php.orig	2016-03-01 14:32:07 UTC
+++ vendor/pear-pear.php.net/Net_Sieve/Net/Sieve.php
@@ -229,7 +229,7 @@ class Net_Sieve
         $this->_sock              = new Net_Socket();
         $this->_bypassAuth        = $bypassAuth;
         $this->_useTLS            = $useTLS;
-        $this->_options           = $options;
+        $this->_options           = (array)$options;
         $this->setDebug($debug, $handler);
 
         /* Try to include the Auth_SASL package.  If the package is not
