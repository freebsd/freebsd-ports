--- ./deadlock/install/install.php.orig	Sun Aug 20 02:30:18 2006
+++ deadlock/install/install.php	Thu Oct 11 15:23:49 2007
@@ -109,7 +109,7 @@
     <td height="20" colspan="2" class="style2"><strong>Installation Step 1</strong></td>
   </tr>
   <tr>
-    <td colspan="2" class="style2">Welcome to the Deadlock installation script. This script will guide you through the entire setup process.<br /><br /><?=$dbconfigpermissions?></td>
+    <td colspan="2" class="style2">Welcome to the Deadlock installation script. This script will guide you through the entire setup process.<br /><br /><?php echo $dbconfigpermissions?></td>
   </tr>
   <tr>
     <td colspan="2">
@@ -122,7 +122,7 @@
 </table>
 </body>
 </html>
-<?
+<?php
 elseif($currentstep=='2'):
 if(!is_writable('../db_config.php')) die('Deadlock found that db_config.php is not writable. Did you skip step 1?');
 
@@ -214,7 +214,7 @@
     <td colspan="2" class="style2">Here you need to specify your MySQL database information, so that we can create the db_config.php file containing your database settings. </td>
   </tr>
   <tr>
-    <td colspan="2"><? if (!empty($errors)){ ?>
+    <td colspan="2"><?php if (!empty($errors)){ ?>
       <table width="95%" height="24" border="0" align="center">
       <tr>
         <td height="20">
@@ -227,10 +227,10 @@
 		</ul></div></td>
       </tr>
     </table>
-      <? } else { print '<br />'; } ?>
+      <?php } else { print '<br />'; } ?>
       <br />
     <br />
-    <form id="form1" name="form1" method="post" action="<?=$_SERVER['PHP_SELF']?>?<?=$_SERVER['QUERY_STRING']?>">
+    <form id="form1" name="form1" method="post" action="<?php echo $_SERVER['PHP_SELF']?>?<?php echo $_SERVER['QUERY_STRING']?>">
       <table width="70%" border="0" align="center">
         <tr>
           <td class="style5">MySQL Host:</td>
@@ -273,7 +273,7 @@
 </table>
 </body>
 </html>
-<?
+<?php
 elseif($currentstep=='3'):
 if(!file_exists('../db_config.php')) die('db_config.php does not yet exist. Did you skip step 2?');
 if(!defined('DEADLOCK_INSTALLED')){
@@ -468,7 +468,7 @@
 </table>
 </body>
 </html>
-<?
+<?php
 exit;
 	}
 }
@@ -504,7 +504,7 @@
     <td colspan="2" class="style2">Here we need to specify settings required in order for Deadlock to function properly. Clicking Submit will create the database tables, provided there are no errors.</td>
   </tr>
   <tr>
-    <td colspan="2"><? if (!empty($errors)){ ?>
+    <td colspan="2"><?php if (!empty($errors)){ ?>
       <table width="95%" height="24" border="0" align="center">
       <tr>
         <td height="20">
@@ -517,25 +517,25 @@
 		</ul></div></td>
       </tr>
     </table>
-      <? } else { print '<br />'; } ?>
+      <?php } else { print '<br />'; } ?>
       <br />
     <br />
-    <form id="form1" name="form1" method="post" action="<?=$_SERVER['PHP_SELF']?>?<?=$_SERVER['QUERY_STRING']?>">
+    <form id="form1" name="form1" method="post" action="<?php echo $_SERVER['PHP_SELF']?>?<?php echo $_SERVER['QUERY_STRING']?>">
       <table width="70%" border="0" align="center">
         <tr>
           <td class="style5">Path to Htpasswd:</td>
-          <td><input name="htpasswd_path" type="text" id="htpasswd_path" value="<? if(isset($_POST['htpasswd_path'])) print $_POST['htpasswd_path']; else print "/protected/.htpasswd"; ?>" />
+          <td><input name="htpasswd_path" type="text" id="htpasswd_path" value="<?php if(isset($_POST['htpasswd_path'])) print $_POST['htpasswd_path']; else print "/protected/.htpasswd"; ?>" />
             <a href="#" class="hintanchor" onmouseover="showhint('Enter the path to your htpasswd file. This must be relative to the document root. For example, if the URL to your protected area is http://www.example.com/protected/, in this field you would most likely enter &quot;/protected/.htpasswd&quot;.', this, event, '150px')">[?]</a></td>
         </tr>
         <tr>
           <td class="style5">&nbsp;</td>
           <td class="style2">Relative? 
-            <input name="htpasswd_relative" type="checkbox" value="true"<? if($htpasswd_relative){ print ' checked="checked"'; } elseif(!isset($_POST['submit'])) { print ' checked="checked"'; } ?> />
+            <input name="htpasswd_relative" type="checkbox" value="true"<?php if($htpasswd_relative){ print ' checked="checked"'; } elseif(!isset($_POST['submit'])) { print ' checked="checked"'; } ?> />
             <a href="#" class="hintanchor" onmouseover="showhint('If this box is checked, the path entered above must be relative to your document root. If this box is not checked, the path above must be a full path.', this, event, '150px')">[?]</a></td>
         </tr>
         <tr>
           <td width="48%" class="style5">Path to Htaccess:</td>
-          <td width="52%"><input name="htaccess_path" type="text" id="htaccess_path" value="<? if(isset($_POST['htaccess_path'])) print $_POST['htaccess_path']; else print "/protected/.htaccess"; ?>" />
+          <td width="52%"><input name="htaccess_path" type="text" id="htaccess_path" value="<?php if(isset($_POST['htaccess_path'])) print $_POST['htaccess_path']; else print "/protected/.htaccess"; ?>" />
             <a href="#" class="hintanchor" onmouseover="showhint('Enter the path to your htaccess file. This MUST be relative to the document root and MUST be within your protected area. For example, if the URL to your protected area is http://www.example.com/protected/, in this field you would most likely enter &quot;/protected/.haccess&quot;. This file MUST be in your protected area directory for Deadlock to function properly!', this, event, '200px')">[?]</a></td>
         </tr>
         <tr>
@@ -544,17 +544,17 @@
         </tr>
         <tr>
           <td class="style5">Protected URL:</td>
-          <td><input name="protected_area_url" type="text" id="protected_area_url" value="<? if(isset($_POST['protected_area_url'])) print $_POST['protected_area_url']; else print "http://".$_SERVER['HTTP_HOST']."/protected/"; ?>" />
+          <td><input name="protected_area_url" type="text" id="protected_area_url" value="<?php if(isset($_POST['protected_area_url'])) print $_POST['protected_area_url']; else print "http://".$_SERVER['HTTP_HOST']."/protected/"; ?>" />
 		  <a href="#" class="hintanchor" onmouseover="showhint('Enter the URL to your protected area.', this, event, '150px')">[?]</a></td>
         </tr>
         <tr>
           <td class="style5">Deadlock URL:</td>
-          <td><input name="deadlock_url" type="text" id="deadlock_url" value ="<? if(isset($_POST['deadlock_url'])) print $_POST['deadlock_url']; else print "http://".$_SERVER['HTTP_HOST'].str_replace('/install','',dirname($_SERVER['REQUEST_URI'])); ?>" />
+          <td><input name="deadlock_url" type="text" id="deadlock_url" value ="<?php if(isset($_POST['deadlock_url'])) print $_POST['deadlock_url']; else print "http://".$_SERVER['HTTP_HOST'].str_replace('/install','',dirname($_SERVER['REQUEST_URI'])); ?>" />
 		  <a href="#" class="hintanchor" onmouseover="showhint('This is the URL to the root directory of Deadlock. On most installations this will be http://www.yoursite.com/deadlock. Do NOT include a trailing forwardslash!', this, event, '150px')">[?]</a></td>
         </tr>
         <tr>
           <td class="style5">Admin Email: </td>
-          <td><input name="admin_email" type="text" id="admin_email" value="<? if(isset($_POST['admin_email'])) print $_POST['admin_email']; else print "admin@example.com"; ?>" />
+          <td><input name="admin_email" type="text" id="admin_email" value="<?php if(isset($_POST['admin_email'])) print $_POST['admin_email']; else print "admin@example.com"; ?>" />
 		  <a href="#" class="hintanchor" onmouseover="showhint('Enter your email address.', this, event, '150px')">[?]</a></td>
         </tr>
         <tr>
@@ -573,4 +573,4 @@
 </table>
 </body>
 </html>
-<? endif; ?>
\ No newline at end of file
+<?php endif; ?>
\ No newline at end of file
