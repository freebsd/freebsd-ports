--- templates/viewmail.template.php.orig	2007-06-14 19:00:15 UTC
+++ templates/viewmail.template.php
@@ -25,7 +25,7 @@ function startMessage() {
       <table width="100%" border="0" cellspacing="0" cellpadding="0">
         <tr>
           <td class="tableTitle" style="background-color:#0F93DF;">
-            <? echo translate('Message'); ?>
+            <?php echo translate('Message'); ?>
           </td>
           <td class="tableTitle" style="background-color:#0F93DF;">
             <div align="right"
@@ -34,7 +34,7 @@ function startMessage() {
           </td>
         </tr>
       </table>
-<?
+<?php
 }
 
 function endMessage() {
@@ -42,7 +42,7 @@ function endMessage() {
     </td>
   </tr>
 </table>
-<?
+<?php
 }
 
 /**
@@ -81,7 +81,9 @@ function MsgPrintHeader($struct,$hdr_list) {
 function MsgPrintHeaderFull($struct,$hdr_list) {
        
         foreach ($hdr_list as $hdr) {
-          $header_value = $struct->headers[strtolower($hdr)];
+          if ( isset($struct->headers[strtolower($hdr)] ) ) {
+              $header_value = $struct->headers[strtolower($hdr)];
+          }
 	  if (!$header_value) continue;
           if (is_array($header_value)) {
             $value_array = $header_value;
@@ -116,17 +118,17 @@ function MsgDisplayOptions($mail_id, $recip_email) {
 <table class="stdFont" width="100%">
   <tr>
     <td align="left">
-      <a href="javascript: history.back();">&#8249;&#8249; <? echo translate('BackMessageIndex'); ?> </a>
+      <a href="javascript: history.back();">&#8249;&#8249; <?php echo translate('BackMessageIndex'); ?> </a>
     </td>
     <td align="right">
-      <a href="javascript: ViewOriginal('<? echo $enc_mail_id ?>','<? echo $enc_recip_email ?>');"> <? echo translate('ViewOriginal'); ?></a>
+      <a href="javascript: ViewOriginal('<?php echo $enc_mail_id ?>','<?php echo $enc_recip_email ?>');"> <?php echo translate('ViewOriginal'); ?></a>
       |
       <a href="javascript: void(1);" onclick="showHideFullHeaders('headers');">
-   	      <? echo translate('ToggleHeaders'); ?></a>
+   	      <?php echo translate('ToggleHeaders'); ?></a>
      </td>
   </tr>
 </table>
-<?
+<?php
 }
 
 /**
@@ -138,14 +140,14 @@ function MsgOriginalOptions() {
   <table width="100%">
    <tr>
     <td class="stdFont" align="right">
-      <a href="javascript: window.print();"> <? echo translate('Print'); ?></a>
+      <a href="javascript: window.print();"> <?php echo translate('Print'); ?></a>
        |
-      <a href="javascript: window.close();"> <? echo translate('CloseWindow'); ?> </a>
+      <a href="javascript: window.close();"> <?php echo translate('CloseWindow'); ?> </a>
     </td>
    </tr>
     <tr>
      <td class="stdFont" bgcolor="#FAFAFA">
-<?
+<?php
 }
 
 
