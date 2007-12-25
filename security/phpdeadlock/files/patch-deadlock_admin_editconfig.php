--- ./deadlock/admin/editconfig.php.orig	Sun Aug 20 02:05:01 2006
+++ deadlock/admin/editconfig.php	Thu Oct 11 15:23:48 2007
@@ -332,23 +332,23 @@
   </tr>
   <tr>
     <td height="19" colspan="2"><br /><span class="style2">
-    <? if(isset($updatedoptions)): ?>
+    <?php if(isset($updatedoptions)): ?>
       The following options were updated:<br />
 	  <?php
 	  foreach($updatedoptions as $option){
 	  	print '- '.$option.'<br />';
 	  }
 	  ?>
-	 <? else: ?>
+	 <?php else: ?>
 	 No options were updated.<br />
-	 <? endif; ?> 
+	 <?php endif; ?> 
       <br />
       If you are not redirected within 5 seconds, <a href="./index.php">click here</a>...</span><br />
     <br /><br /></td>
   </tr>
   
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
@@ -407,7 +407,7 @@
     <td height="28" colspan="2" class="style2">This page allows you to modify settings which are used throughout Deadlock to customize various features. Once you are finished making changes, click submit to update the settings. If there are any errors, nothing is changed. </td>
   </tr>
   <tr>
-    <td colspan="2"><? if (!empty($errors)){ ?>
+    <td colspan="2"><?php if (!empty($errors)){ ?>
       <br /><table width="100%" border="0" align="center">
       <tr>
         <td height="20">
@@ -421,8 +421,8 @@
 		</ul></div></td>
       </tr>
     </table>
-      <? } else { print '<br />'; } ?>
-	  <form action="<?=$_SERVER['PHP_SELF']?>" method="post">
+      <?php } else { print '<br />'; } ?>
+	  <form action="<?php echo $_SERVER['PHP_SELF']?>" method="post">
 	  <table width="100%" height="100%" border="0" align="center">
   <tr>
     <td width="100%">		 
@@ -431,7 +431,7 @@
 	        <table width="100%" border="0">
 	          <tr>
 	            <td width="123"><span class="style5">Protected Area</span><span class="style5">: </span></td>
-                <td width="242"><input type="text" name="protected_area_name" value="<?=ConfigTextField(@$_POST['protected_area_name'],$config['protected_area_name'])?>" />
+                <td width="242"><input type="text" name="protected_area_name" value="<?php echo ConfigTextField(@$_POST['protected_area_name'],$config['protected_area_name'])?>" />
                 <a href="#" class="hintanchor" onmouseover="showhint('Enter a name for your protected area. The value entered here will be shown in the login box. This cannot be left blank.', this, event, '150px')">[?]</a></td>
               </tr>
 	        </table>
@@ -442,12 +442,12 @@
 	        <table width="100%" border="0">
 	          <tr>
 	            <td width="123"><span class="style5">Admin Email</span><span class="style5">: </span></td>
-                <td width="242"><input type="text" name="admin_email" value="<?=ConfigTextField(@$_POST['admin_email'],$config['admin_email'])?>" />
+                <td width="242"><input type="text" name="admin_email" value="<?php echo ConfigTextField(@$_POST['admin_email'],$config['admin_email'])?>" />
                 <a href="#" class="hintanchor" onmouseover="showhint('Enter the administrator\'s email address. This will be used in the from field of outgoing messages.', this, event, '150px')">[?]</a></td>
               </tr>
 	          <tr>
 	            <td class="style5">System Email:</td>
-                <td><input type="text" name="system_email" value="<?=ConfigTextField(@$_POST['system_email'],$config['system_messages_email'])?>" />
+                <td><input type="text" name="system_email" value="<?php echo ConfigTextField(@$_POST['system_email'],$config['system_messages_email'])?>" />
                 <span class="style5"><a href="#" class="hintanchor" onmouseover="showhint('Enter the system\'s email address. This will primarily be used for sending emails to the administrator.', this, event, '150px')">[?]</a></span></td>
               </tr>
 	          </table>
@@ -458,20 +458,20 @@
 	          <tr>
 	            <td width="151" height="22" class="style5">Welcome Users: </td>
                 <td width="282">
-                  <label class="style2"><input name="user_welcome_email" type="radio" value="true"<?=ConfigRadioCheck(@$_POST['user_welcome_email'],$config['user_welcome_email'],'on')?> />On</label>
-                  <label class="style2"><input type="radio" name="user_welcome_email" value="false"<?=ConfigRadioCheck(@$_POST['user_welcome_email'],$config['user_welcome_email'],'off')?> />Off</label>
+                  <label class="style2"><input name="user_welcome_email" type="radio" value="true"<?php echo ConfigRadioCheck(@$_POST['user_welcome_email'],$config['user_welcome_email'],'on')?> />On</label>
+                  <label class="style2"><input type="radio" name="user_welcome_email" value="false"<?php echo ConfigRadioCheck(@$_POST['user_welcome_email'],$config['user_welcome_email'],'off')?> />Off</label>
                   <a href="#" class="hintanchor" onmouseover="showhint('Send a welcome email to new users. If admin verification is enabled, this email will tell the user that their account is pending verification.', this, event, '150px')">[?]</a></td>
               </tr>
 	          <tr>
 	            <td height="22" class="style5">New User Notify: </td>
-	            <td><label class="style2"><input name="admin_user_email" type="radio" value="true"<?=ConfigRadioCheck(@$_POST['admin_user_email'],$config['admin_user_email'],'on')?> />On</label>
-                  <label class="style2"><input type="radio" name="admin_user_email" value="false"<?=ConfigRadioCheck(@$_POST['admin_user_email'],$config['admin_user_email'],'off')?> />Off</label>
+	            <td><label class="style2"><input name="admin_user_email" type="radio" value="true"<?php echo ConfigRadioCheck(@$_POST['admin_user_email'],$config['admin_user_email'],'on')?> />On</label>
+                  <label class="style2"><input type="radio" name="admin_user_email" value="false"<?php echo ConfigRadioCheck(@$_POST['admin_user_email'],$config['admin_user_email'],'off')?> />Off</label>
                   <a href="#" class="hintanchor" onmouseover="showhint('If this option is enabled, the administrator will receive an email when a user registers.', this, event, '150px')">[?]</a></td>
 	            </tr>
 	          <tr>
 	            <td height="22" class="style5">Status Change Email: </td>
-	            <td><label class="style2"><input name="email_user_accept" type="radio" value="true"<?=ConfigRadioCheck(@$_POST['email_user_accept'],$config['email_user_accept'],'on')?> />On</label>
-                  <label class="style2"><input type="radio" name="email_user_accept" value="false"<?=ConfigRadioCheck(@$_POST['email_user_accept'],$config['email_user_accept'],'off')?> />Off</label>
+	            <td><label class="style2"><input name="email_user_accept" type="radio" value="true"<?php echo ConfigRadioCheck(@$_POST['email_user_accept'],$config['email_user_accept'],'on')?> />On</label>
+                  <label class="style2"><input type="radio" name="email_user_accept" value="false"<?php echo ConfigRadioCheck(@$_POST['email_user_accept'],$config['email_user_accept'],'off')?> />Off</label>
 				  <a href="#" class="hintanchor" onmouseover="showhint('If this option is enabled, Deadlock will send the user an email when the administrator approves or denies a request. This is only applicable if admin validation is enabled.', this, event, '150px')">[?]</a></td>
 	            </tr>
         </table>
@@ -484,27 +484,27 @@
 	          <tr>
 	            <td width="32%" class="style5">Date Format: </td>
                 <td width="68%"><select name="date_format" id="date_format">
-                  <?=ConfigDateSelects(@$_POST['date_format'],$config['date_format'])?>
+                  <?php echo ConfigDateSelects(@$_POST['date_format'],$config['date_format'])?>
                   </select>
                 <a href="#" class="hintanchor" onmouseover="showhint('Anywhere a date is shown, for example a user registration date, this is the format the date will be shown in.', this, event, '150px')">[?]</a> </td>
               </tr>
 	          <tr>
 	            <td class="style5">Phone Digits: </td>
-                <td><input name="phone_digits" type="text" size="4" maxlength="2" value="<?=ConfigTextField(@$_POST['phone_digits'],$config['phone_digits'])?>" />
+                <td><input name="phone_digits" type="text" size="4" maxlength="2" value="<?php echo ConfigTextField(@$_POST['phone_digits'],$config['phone_digits'])?>" />
                 <a href="#" class="hintanchor" onmouseover="showhint('Set this to how many digits should be required for a phone number. Usually this should be 10.', this, event, '150px')">[?]</a></td>
               </tr>
 	          
 	          <tr>
 	            <td class="style5">Required Fields: </td>
                 <td>
-                  <label class="style2"><input type="checkbox" name="require_phone" value="true" <?=ConfigCheckboxCheck(@$_POST['submit'],@$_POST['require_phone'],$config['optional_fields_phone'])?>/>Phone</label>
-                  <label class="style2"><input type="checkbox" name="require_country" value="true" <?=ConfigCheckboxCheck(@$_POST['submit'],@$_POST['require_country'],$config['optional_fields_country'])?>/>Country</label>
+                  <label class="style2"><input type="checkbox" name="require_phone" value="true" <?php echo ConfigCheckboxCheck(@$_POST['submit'],@$_POST['require_phone'],$config['optional_fields_phone'])?>/>Phone</label>
+                  <label class="style2"><input type="checkbox" name="require_country" value="true" <?php echo ConfigCheckboxCheck(@$_POST['submit'],@$_POST['require_country'],$config['optional_fields_country'])?>/>Country</label>
                 <a href="#" class="hintanchor" onmouseover="showhint('Select the checkboxes next to the fields that are required in order for a user to register.', this, event, '150px')">[?]</a></td>
               </tr>
 	          <tr>
                 <td class="style5">Validation:</td>
 	            <td><select name="validation">
-                    <?=ConfigVerificationSelects(@$_POST['validation'],$config['verify_email'],$config['require_admin_accept'])?>
+                    <?php echo ConfigVerificationSelects(@$_POST['validation'],$config['verify_email'],$config['require_admin_accept'])?>
                   </select>
                   <a href="#" class="hintanchor" onmouseover="showhint('Email validation will require a user to validate their email address before they are able to access the protected area. Admin approval will make it so that you must approve accounts before they are able to access the protected area. If both are enabled, you will be asked to approve accounts after they have validated their email address.', this, event, '200px')">[?]</a></td>
 	            </tr>
@@ -518,25 +518,25 @@
 	          <tr>
 	            <td width="40%" class="style5">Deadlock URL:</td>
                 <td>
-                <input name="deadlock_url" type="text" id="deadlock_url" value="<?=ConfigTextField(@$_POST['deadlock_url'],$config['deadlock_url'])?>" /><a href="#" class="hintanchor" onmouseover="showhint('This is the URL to the root directory of Deadlock. On most installations this will be http://www.yoursite.com/deadlock/. Do NOT include a trailing forwardslash!', this, event, '200px')">[?]</a></td>
+                <input name="deadlock_url" type="text" id="deadlock_url" value="<?php echo ConfigTextField(@$_POST['deadlock_url'],$config['deadlock_url'])?>" /><a href="#" class="hintanchor" onmouseover="showhint('This is the URL to the root directory of Deadlock. On most installations this will be http://www.yoursite.com/deadlock/. Do NOT include a trailing forwardslash!', this, event, '200px')">[?]</a></td>
               </tr>
 	          <tr>
 	            <td class="style5">Protected Area URL:</td>
-                <td><input name="protected_url" type="text" id="protected_url" value="<?=ConfigTextField(@$_POST['protected_url'],$config['protected_area_url'])?>" /><a href="#" class="hintanchor" onmouseover="showhint('Enter the URL to your protected area. Please include a trailing forward slash.', this, event, '150px')">[?]</a></td>
+                <td><input name="protected_url" type="text" id="protected_url" value="<?php echo ConfigTextField(@$_POST['protected_url'],$config['protected_area_url'])?>" /><a href="#" class="hintanchor" onmouseover="showhint('Enter the URL to your protected area. Please include a trailing forward slash.', this, event, '150px')">[?]</a></td>
               </tr>
 	          <tr>
 	            <td class="style5">Htpasswd Path:</td>
-                <td><input name="htpasswd_path" type="text" id="htpasswd_path" value="<?=ConfigTextField(@$_POST['htpasswd_path'],$config['htpasswd_path'])?>" /><a href="#" class="hintanchor" onmouseover="showhint('Enter the path to your htpasswd file. This must be relevant to the document root. For example, if the URL to your protected area is http://www.example.com/protected/, in this field you would most likely enter &quot;/protected/.htpasswd&quot;.', this, event, '200px')">[?]</a></td>
+                <td><input name="htpasswd_path" type="text" id="htpasswd_path" value="<?php echo ConfigTextField(@$_POST['htpasswd_path'],$config['htpasswd_path'])?>" /><a href="#" class="hintanchor" onmouseover="showhint('Enter the path to your htpasswd file. This must be relevant to the document root. For example, if the URL to your protected area is http://www.example.com/protected/, in this field you would most likely enter &quot;/protected/.htpasswd&quot;.', this, event, '200px')">[?]</a></td>
               </tr>
 	          <tr>
 	            <td class="style5">&nbsp;</td>
 	            <td class="style2">Relative?
-                  <input name="htpasswd_relative" type="checkbox" value="true" <?=ConfigCheckboxCheck(@$_POST['submit'],@$_POST['htpasswd_relative'],$config['htpasswd_relative'])?>/>
+                  <input name="htpasswd_relative" type="checkbox" value="true" <?php echo ConfigCheckboxCheck(@$_POST['submit'],@$_POST['htpasswd_relative'],$config['htpasswd_relative'])?>/>
                   <a href="#" class="hintanchor" onmouseover="showhint('If this box is checked, the path entered above should be relative to the document root. If this box is not checked, the path above should be a full path.', this, event, '150px')">[?]</a></td>
 	            </tr>
 	          <tr>
 	            <td class="style5">Htaccess Path:</td>
-                <td><input name="htaccess_path" type="text" id="htaccess_path" value="<?=ConfigTextField(@$_POST['htaccess_path'],$config['htaccess_path'])?>" /><a href="#" class="hintanchor" onmouseover="showhint('Enter the path to your htaccess file. This must be relevant to the document root. For example, if the URL to your protected area is http://www.example.com/protected/, in this field you would most likely enter &quot;/protected/.htaccess&quot;.', this, event, '200px')">[?]</a></td>
+                <td><input name="htaccess_path" type="text" id="htaccess_path" value="<?php echo ConfigTextField(@$_POST['htaccess_path'],$config['htaccess_path'])?>" /><a href="#" class="hintanchor" onmouseover="showhint('Enter the path to your htaccess file. This must be relevant to the document root. For example, if the URL to your protected area is http://www.example.com/protected/, in this field you would most likely enter &quot;/protected/.htaccess&quot;.', this, event, '200px')">[?]</a></td>
               </tr>
         </table>
 		</fieldset>
@@ -565,32 +565,32 @@
 	          <tr>
 	            <td width="40%" class="style5">Debug Mode: </td>
                 <td>
-                  <label class="style2"><input name="debug_mode" type="radio" value="true"<?=ConfigRadioCheck(@$_POST['debug_mode'],$config['debug_mode'],'on')?> />On</label>
-                  <label class="style2"><input type="radio" name="debug_mode" value="false"<?=ConfigRadioCheck(@$_POST['debug_mode'],$config['debug_mode'],'off')?> />Off</label>
+                  <label class="style2"><input name="debug_mode" type="radio" value="true"<?php echo ConfigRadioCheck(@$_POST['debug_mode'],$config['debug_mode'],'on')?> />On</label>
+                  <label class="style2"><input type="radio" name="debug_mode" value="false"<?php echo ConfigRadioCheck(@$_POST['debug_mode'],$config['debug_mode'],'off')?> />Off</label>
                 <a href="#" class="hintanchor" onmouseover="showhint('If there is an internal progrm error, and this option is enabled, the error will be displayed so that the person viewing the page can see it. This is not reccomeded unless you know what you are doing.', this, event, '200px')">[?]</a></td>
               </tr>
 	          <tr>
 	            <td width="40%" class="style5">Authentication Type:</td>
                 <td class="style2">
 				  <select name="auth_type">
-				  <?=ConfigAuthTypeSelects(@$_POST['auth_type'],$config['digest_auth'])?>
+				  <?php echo ConfigAuthTypeSelects(@$_POST['auth_type'],$config['digest_auth'])?>
 				  </select>
                   <a href="#" class="hintanchor" onmouseover="showhint('Please select the type of authentication you would like to use for your protected area. Digest is by far more secure, but some older browsers do not support it. If you are unable to get digest working, it is possible that either your brower, or your server does not support it.', this, event, '200px')">[?]</a></td>
               </tr>
               <tr>
 	            <td width="40%" class="style5">401 Error Page:</td>
-                <td class="style2"><input name="err_401_doc" type="text" id="err_401_doc" value="<?=ConfigTextField(@$_POST['err_401_doc'],$config['err_401_doc'])?>" /><a href="#" class="hintanchor" onmouseover="showhint('This is the page that will be displayed when someone enters and invalid login. This path must be relative to your document root. If you want to keep the default error page, leave this field blank.', this, event, '200px')">[?]</a></td>
+                <td class="style2"><input name="err_401_doc" type="text" id="err_401_doc" value="<?php echo ConfigTextField(@$_POST['err_401_doc'],$config['err_401_doc'])?>" /><a href="#" class="hintanchor" onmouseover="showhint('This is the page that will be displayed when someone enters and invalid login. This path must be relative to your document root. If you want to keep the default error page, leave this field blank.', this, event, '200px')">[?]</a></td>
               </tr>
                 <td class="style5">Prune Inactive Users:</td>
-	            <td><label class="style2"><input name="prune_inactive_users" type="radio" value="true"<?=ConfigRadioCheck(@$_POST['prune_inactive_users'],$config['prune_inactive_users'],'on')?> />On</label>
-                    <label class="style2"><input type="radio" name="prune_inactive_users" value="false"<?=ConfigRadioCheck(@$_POST['prune_inactive_users'],$config['prune_inactive_users'],'off')?> />Off</label>
+	            <td><label class="style2"><input name="prune_inactive_users" type="radio" value="true"<?php echo ConfigRadioCheck(@$_POST['prune_inactive_users'],$config['prune_inactive_users'],'on')?> />On</label>
+                    <label class="style2"><input type="radio" name="prune_inactive_users" value="false"<?php echo ConfigRadioCheck(@$_POST['prune_inactive_users'],$config['prune_inactive_users'],'off')?> />Off</label>
                   <a href="#" class="hintanchor" onmouseover="showhint('Users that have not validated their email address after 72 hours will automatically be removed.', this, event, '200px')">[?]</a></td>
 	            </tr>
 	          <tr>
 	            <td height="23" colspan="2" valign="bottom" class="style5">Default Bulk Email Footer<a href="#" class="hintanchor" onmouseover="showhint('This is the deafult footer that will appear on the bulk mail page.', this, event, '150px')">[?]</a>: </td>
 	            </tr>
 	          <tr>
-	            <td colspan="2" class="style5"><textarea name="footer" cols="50" rows="6" ><? if(isset($_POST['footer'])) print $_POST['footer']; else print $config['bulk_email_footer']; ?></textarea></td>
+	            <td colspan="2" class="style5"><textarea name="footer" cols="50" rows="6" ><?php if(isset($_POST['footer'])) print $_POST['footer']; else print $config['bulk_email_footer']; ?></textarea></td>
 	            </tr>
         </table>
 		</fieldset></td>
@@ -599,7 +599,7 @@
 		<div align="center"><br />
 	        	<input type="hidden" name="submit" value="1" />
 	            <input type="submit" value="Update Changed Options" />
-	            <input type="button" onclick="window.location='<?=$_SERVER['PHP_SELF']?>'" value="Reset" />
+	            <input type="button" onclick="window.location='<?php echo $_SERVER['PHP_SELF']?>'" value="Reset" />
 	            <br />
         </div>
               </div>
@@ -609,7 +609,7 @@
   </tr>
   
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
