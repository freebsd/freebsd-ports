--- lib/MailMime.class.php.orig	2007-06-14 19:00:15 UTC
+++ lib/MailMime.class.php
@@ -94,8 +94,14 @@ function MsgParseBody($struct) {
 
           case "text":
             // Do not display attached text types
-            if ($attachment = $struct->d_parameters['filename'] or
-                  $attachment = $struct->d_parameters['name']) {
+            if ( isset($struct->d_parameters['filename']) ) {
+                $attachment = $struct->d_parameters['filename'];
+            } elseif ( isset($struct->d_parameters['name']) ) {
+                $attachment = $struct->d_parameters['name'];
+            } else {
+                $attachment = NULL;
+            }
+            if ($attachment) {
                 array_push($filelist, $attachment);
                 break;
             }
@@ -117,7 +123,9 @@ function MsgParseBody($struct) {
           default:
             // Save the listed filename or notify the
             // reader that this mail is not displayed completely
-            $attachment = $struct->d_parameters['filename'];
+            if ( isset( $struct->d_parameters['filename'] )) {
+               $attachment = $struct->d_parameters['filename'];
+            } else { $attachment = NULL; }
             $attachment ? array_push($filelist, $attachment) : $errors['Unsupported MIME objects present'] = true;
 
         }
@@ -137,9 +145,9 @@ function FindMultiAlt($parts) {
     foreach ($parts as $cur_part) {
       $type = GetCtype($cur_part);
       if ($type == 'multipart/related') {
-      $type = $cur_part->d_parameters['type'];
-      // Mozilla bug. Mozilla does not provide the parameter type.
-      if (!$type) $type = 'text/html';
+        if ( isset( $cur_part->d_parameters['type'] )) { $type = $cur_part->d_parameters['type']; }
+        // Mozilla bug. Mozilla does not provide the parameter type.
+        if (!$type) $type = 'text/html';
       }
       $altCount = count($alt_pref);
       for ($j = $best_view; $j < $altCount; ++$j) {
@@ -163,7 +171,7 @@ function FindMultiAlt($parts) {
 */
 function FindMultiRel($struct) {
   $entities = array();
-  $type = $struct->d_parameters['type'];
+  if ( isset( $cur_part->d_parameters['type'] )) { $type = $cur_part->d_parameters['type']; }
   // Mozilla bug. Mozilla does not provide the parameter type.
   if (!$type) $type = 'text/html';
   // Bad Headers sometimes have invalid MIME.... 
