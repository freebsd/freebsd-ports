--- ./deadlock/admin/edituser.php.orig	Tue Aug 15 13:23:21 2006
+++ deadlock/admin/edituser.php	Thu Oct 11 15:23:48 2007
@@ -173,7 +173,7 @@
     <td height="28" colspan="2" class="style2">To edit a user, change the values in the below form, then click Update. All fields are required except for those marked &quot;optional&quot;. </td>
   </tr>
   <tr>
-    <td height="275" colspan="2"><? if (!empty($errors)){ ?><table width="95%" height="24" border="0" align="center">
+    <td height="275" colspan="2"><?php if (!empty($errors)){ ?><table width="95%" height="24" border="0" align="center">
       <tr>
         <td height="20">
 		<div class="style9"><ul>
@@ -185,27 +185,27 @@
 		</ul></div></td>
       </tr>
     </table>
-      <? } else { print '<br />'; } ?>
-	  <form action="<?=$_SERVER['PHP_SELF']?>?<?=$_SERVER['QUERY_STRING']?>" method="post">
+      <?php } else { print '<br />'; } ?>
+	  <form action="<?php echo $_SERVER['PHP_SELF']?>?<?php echo $_SERVER['QUERY_STRING']?>" method="post">
       <table width="73%" border="0" align="center">
       <tr>
         <td width="47%" class="style5">First Name:</td>
-        <td width="53%"><input name="firstname" maxlength="15" type="text" id="firstname" value="<? if(isset($_POST['firstname'])) print $_POST['firstname']; else print $firstname ?>" /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your first name. This must be 1-15 characters and alphanumeric.', this, event, '150px')">[?]</a></td>
+        <td width="53%"><input name="firstname" maxlength="15" type="text" id="firstname" value="<?php if(isset($_POST['firstname'])) print $_POST['firstname']; else print $firstname ?>" /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your first name. This must be 1-15 characters and alphanumeric.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
         <td class="style5">Last Name: </td>
-        <td><input name="lastname" maxlength="15" type="text" id="lastname" value="<? if(isset($_POST['lastname'])) print $_POST['lastname']; else print $lastname ?>" /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your last name. This must be 1-15 characters and alphanumeric.', this, event, '150px')">[?]</a></td>
+        <td><input name="lastname" maxlength="15" type="text" id="lastname" value="<?php if(isset($_POST['lastname'])) print $_POST['lastname']; else print $lastname ?>" /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your last name. This must be 1-15 characters and alphanumeric.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
         <td class="style5">Email:</td>
-        <td><input name="email" type="text" id="email" value="<? if(isset($_POST['email'])) print $_POST['email']; else print $email ?>" /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your email address. This email address must be valid.', this, event, '150px')">[?]</a></td>
+        <td><input name="email" type="text" id="email" value="<?php if(isset($_POST['email'])) print $_POST['email']; else print $email ?>" /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your email address. This email address must be valid.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
-        <td class="style5">Phone<? if($config['optional_fields_phone']=="false") print ' (optional)'; ?>: </td>
-        <td><input name="phone" type="text" id="phone" value="<? if(isset($_POST['phone'])) print $_POST['phone']; else print $phone ?>" /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your phone number. This should be <?=$config['phone_digits']?> digits and contain only numbers.', this, event, '150px')">[?]</a></td>
+        <td class="style5">Phone<?php if($config['optional_fields_phone']=="false") print ' (optional)'; ?>: </td>
+        <td><input name="phone" type="text" id="phone" value="<?php if(isset($_POST['phone'])) print $_POST['phone']; else print $phone ?>" /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your phone number. This should be <?php echo $config['phone_digits']?> digits and contain only numbers.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
-        <td class="style5">Country<? if($config['optional_fields_country']=="false") print ' (optional)'; ?>:</td>
+        <td class="style5">Country<?php if($config['optional_fields_country']=="false") print ' (optional)'; ?>:</td>
         <td>
 <?php
 if(isset($_POST['country'])){
@@ -221,7 +221,7 @@
 
       <tr>
         <td class="style5">Username:</td>
-        <td><input type="text" disabled="disabled" value="<?=$username?>" /><a href="#" class="hintanchor" onMouseover="showhint('Please choose a username. This must be alphanumeric and contain 5-10 characters.', this, event, '150px')"></a></td>
+        <td><input type="text" disabled="disabled" value="<?php echo $username?>" /><a href="#" class="hintanchor" onMouseover="showhint('Please choose a username. This must be alphanumeric and contain 5-10 characters.', this, event, '150px')"></a></td>
       </tr>
       <tr>
         <td class="style5"> New Password:</td>
@@ -237,7 +237,7 @@
       </tr>
       <tr>
         <td class="style2">Notify User:</td>
-        <td class="style2"><input name="notify_user" type="checkbox" id="notify_user" value="1" <? if(($config['user_welcome_email']=="true" && !isset($_POST['submit'])) || isset($_POST['welcome_user'])) print 'checked="checked" '; ?>/>
+        <td class="style2"><input name="notify_user" type="checkbox" id="notify_user" value="1" <?php if(($config['user_welcome_email']=="true" && !isset($_POST['submit'])) || isset($_POST['welcome_user'])) print 'checked="checked" '; ?>/>
           <a href="#" class="hintanchor" onmouseover="showhint('Check this box if you would like to notify the user of these changes.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
@@ -246,7 +246,7 @@
       </tr>
       <tr>
         <td>&nbsp;</td>
-        <td><input type="hidden" name="submit" value="1" /><input type="hidden" name="username" value="<?=$username?>" /><input type="submit" value="Update" /> <input type="button" onclick="window.location='./userinfo.php?user=<?=$username?>'" value="Back" /></td>
+        <td><input type="hidden" name="submit" value="1" /><input type="hidden" name="username" value="<?php echo $username?>" /><input type="submit" value="Update" /> <input type="button" onclick="window.location='./userinfo.php?user=<?php echo $username?>'" value="Back" /></td>
       </tr>
     </table>
 	<br />
@@ -254,10 +254,10 @@
   </tr>
   
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
-</html><? 
+</html><?php 
 }
 ?>
