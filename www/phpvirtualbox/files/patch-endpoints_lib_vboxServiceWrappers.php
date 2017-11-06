--- endpoints/lib/vboxServiceWrappers.php.orig	2017-07-27 16:54:58 UTC
+++ endpoints/lib/vboxServiceWrappers.php
@@ -7889,6 +7889,10 @@ class IMedium extends VBox_ManagedObject
 
     public function changeEncryption($arg_currentPassword, $arg_cipher, $arg_newPassword, $arg_newPasswordId)
     {
+        // No password ID in case of decryption and de-/encryption are both handled here.
+        $isDecryption      = ($arg_cipher == '') && ($arg_newPassword == '');
+        $arg_newPasswordId = $isDecryption ? '' : $arg_newPasswordId;
+
         $request = new stdClass();
         $request->_this = $this->handle;
         $request->currentPassword = $arg_currentPassword;
