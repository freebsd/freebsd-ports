--- ./inc/PMF_Search/Resultset.php.orig	2010-08-02 13:58:15.000000000 +0200
+++ ./inc/PMF_Search/Resultset.php	2010-08-02 13:58:40.000000000 +0200
@@ -107,7 +107,9 @@
         
         $duplicateResults = array();
         $currentUserId    = $this->user->getUserId();
-        $currentGroupIds  = $this->user->perm->getUserGroups($currentUserId);
+        if ('medium' == PMF_Configuration::getInstance()->get('main.permLevel')) {
+            $currentGroupIds  = $this->user->perm->getUserGroups($currentUserId);
+        }

