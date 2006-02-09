diff -u -r1.17.2.8 -r1.17.2.10
--- class/mime/Message.class.php	2004/12/27 15:03:42	1.17.2.8
+++ class/mime/Message.class.php	2005/07/21 15:41:05	1.17.2.10
@@ -8,7 +8,7 @@
  *
   This contains functions needed to handle mime messages.
  *
- * $Id: Message.class.php,v 1.17.2.8 2004/12/27 15:03:42 kink Exp $
+ * $Id: Message.class.php,v 1.17.2.10 2005/07/21 15:41:05 tokul Exp $
  */
 
 class Message {
@@ -673,9 +673,9 @@
                 }
             } else { /* Treat as multipart/mixed */
                 foreach ($this->entities as $ent) {
-                    if((strtolower($ent->header->disposition->name) != 'attachment') &&
-                (!isset($ent->header->parameters['filename'])) &&
-                (!isset($ent->header->parameters['name'])) &&
+                    if(!(is_object($ent->header->disposition) && strtolower($ent->header->disposition->name) == 'attachment') &&
+                       (!isset($ent->header->parameters['filename'])) &&
+                       (!isset($ent->header->parameters['name'])) &&
                        (($ent->type0 != 'message') && ($ent->type1 != 'rfc822'))) {
                         $entity = $ent->findDisplayEntity($entity, $alt_order, $strict);
                         $found = true;
@@ -688,9 +688,10 @@
             foreach ($alt_order as $alt) {
                 if( ($alt == $type) && isset($this->entity_id) ) {
                     if ((count($this->entities) == 0) && 
-                (!isset($ent->header->parameters['filename'])) &&
-                (!isset($ent->header->parameters['name'])) &&
-                        (strtolower($this->header->disposition->name) != 'attachment')) {
+                        (!isset($this->header->parameters['filename'])) &&
+                        (!isset($this->header->parameters['name'])) &&
+                        (isset($this->header->disposition) && is_object($this->header->disposition) &&
+                        strtolower($this->header->disposition->name) != 'attachment')) {
                         $entity[] = $this->entity_id;
                         $found = true;
                     }
@@ -699,7 +700,7 @@
         }
         if(!$found) {
             foreach ($this->entities as $ent) {
-                if((strtolower($ent->header->disposition->name) != 'attachment') &&
+                if(!(is_object($ent->header->disposition) && strtolower($ent->header->disposition->name) == 'attachment') &&
                    (($ent->type0 != 'message') && ($ent->type1 != 'rfc822'))) {
                     $entity = $ent->findDisplayEntity($entity, $alt_order, $strict);
                     $found = true;
@@ -711,7 +712,7 @@
                 in_array($this->type1, array('plain', 'html', 'message')) &&
                 isset($this->entity_id)) {
                 if (count($this->entities) == 0) {
-                    if (strtolower($this->header->disposition->name) != 'attachment') {
+                    if (!is_object($this->header->disposition) || strtolower($this->header->disposition->name) != 'attachment') {
                         $entity[] = $this->entity_id;
                     }
                 }
