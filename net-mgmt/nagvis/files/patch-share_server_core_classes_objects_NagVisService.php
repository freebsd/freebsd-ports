--- share/server/core/classes/objects/NagVisMapObj.php.orig	2017-12-21 20:54:27.936999000 +0100
+++ share/server/core/classes/objects/NagVisMapObj.php	2017-12-21 20:54:31.229491000 +0100
@@ -187,7 +187,7 @@
      *
      * @author	Lars Michelsen <lars@vertical-visions.de>
      */
-    public function queueState($_unused_flag = true, $_unused_flag = true) {
+    public function queueState($_unused_flag = true, $_unused_flag2 = true) {
         // Get state of all member objects
         foreach($this->getStateRelevantMembers() AS $OBJ) {
             // The states of the map objects members only need to be fetched when this
--- share/server/core/classes/objects/NagVisService.php.orig	2017-12-21 20:55:07.358180000 +0100
+++ share/server/core/classes/objects/NagVisService.php	2017-12-21 20:55:31.487418000 +0100
@@ -56,7 +56,7 @@
     /**
      * Queues state fetching for this object
      */
-    public function queueState($_unused_flag = true, $_unused_flag = true) {
+    public function queueState($_unused_flag = true, $_unused_flag2 = true) {
         global $_BACKEND;
         $_BACKEND->queue(Array('serviceState' => true), $this);
     }
