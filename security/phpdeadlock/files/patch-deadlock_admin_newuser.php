--- ./deadlock/admin/newuser.php.orig	Sat Aug  5 04:05:16 2006
+++ deadlock/admin/newuser.php	Thu Oct 11 15:23:49 2007
@@ -103,7 +103,7 @@
 <html xmlns="http://www.w3.org/1999/xhtml">
 <head>
 <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
-<META HTTP-EQUIV="Refresh" CONTENT="5; URL=./userinfo.php?user=<?=htmlentities($_POST['username'])?>">
+<META HTTP-EQUIV="Refresh" CONTENT="5; URL=./userinfo.php?user=<?php echo htmlentities($_POST['username'])?>">
 <title>Deadlock - User Created Successfully</title>
 <link href="../images/admin.css" rel="stylesheet" type="text/css" media="all" />
 </head>
@@ -120,15 +120,15 @@
     <td height="20" colspan="2" class="style2"><strong><a href="./index.php">Top</a>: User Created Successfully </strong></td>
   </tr>
   <tr>
-    <td height="28" colspan="2" class="style2">The user <?=htmlentities($_POST['username'])?> was created successfully! Please wait while your are redirected to the user's profile.</td>
+    <td height="28" colspan="2" class="style2">The user <?php echo htmlentities($_POST['username'])?> was created successfully! Please wait while your are redirected to the user's profile.</td>
   </tr>
   <tr>
     <td height="19" colspan="2"><br />
-      <span class="style2">If you are not redirected within 5 seconds, <a href="./userinfo.php?user=<?=htmlentities($_POST['username'])?>">click here</a>...</span><br /><br /><br /></td>
+      <span class="style2">If you are not redirected within 5 seconds, <a href="./userinfo.php?user=<?php echo htmlentities($_POST['username'])?>">click here</a>...</span><br /><br /><br /></td>
   </tr>
   
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
@@ -169,7 +169,7 @@
     <td height="28" colspan="2" class="style2">To add a user, fill in the required fields below. A welcome email will be sent to the email address provided once the account has been created. </td>
   </tr>
   <tr>
-    <td height="275" colspan="2"><? if (!empty($errors)){ ?><table width="95%" height="24" border="0" align="center">
+    <td height="275" colspan="2"><?php if (!empty($errors)){ ?><table width="95%" height="24" border="0" align="center">
       <tr>
         <td height="20">
 		<div class="style9"><ul>
@@ -181,27 +181,27 @@
 		</ul></div></td>
       </tr>
     </table>
-      <? } else { print '<br />'; } ?>
-	  <form action="<?=$_SERVER['PHP_SELF']?>" method="post">
+      <?php } else { print '<br />'; } ?>
+	  <form action="<?php echo $_SERVER['PHP_SELF']?>" method="post">
       <table width="73%" border="0" align="center">
       <tr>
         <td width="47%" class="style5">First Name:</td>
-        <td width="53%"><input name="firstname" maxlength="15" type="text" id="firstname"<? if(isset($_POST['firstname'])) print ' value="'.$_POST['firstname'].'"'; ?> /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your first name. This must be 1-15 characters and alphanumeric.', this, event, '150px')">[?]</a></td>
+        <td width="53%"><input name="firstname" maxlength="15" type="text" id="firstname"<?php if(isset($_POST['firstname'])) print ' value="'.$_POST['firstname'].'"'; ?> /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your first name. This must be 1-15 characters and alphanumeric.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
         <td class="style5">Last Name: </td>
-        <td><input name="lastname" maxlength="15" type="text" id="lastname"<? if(isset($_POST['lastname'])) print ' value="'.$_POST['lastname'].'"'; ?> /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your last name. This must be 1-15 characters and alphanumeric.', this, event, '150px')">[?]</a></td>
+        <td><input name="lastname" maxlength="15" type="text" id="lastname"<?php if(isset($_POST['lastname'])) print ' value="'.$_POST['lastname'].'"'; ?> /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your last name. This must be 1-15 characters and alphanumeric.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
         <td class="style5">Email:</td>
-        <td><input name="email" type="text" id="email"<? if(isset($_POST['email'])) print ' value="'.$_POST['email'].'"'; ?> /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your email address. This email address must be valid.', this, event, '150px')">[?]</a></td>
+        <td><input name="email" type="text" id="email"<?php if(isset($_POST['email'])) print ' value="'.$_POST['email'].'"'; ?> /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your email address. This email address must be valid.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
-        <td class="style5">Phone<? if($config['optional_fields_phone']=="false") print ' (optional)'; ?>: </td>
-        <td><input name="phone" type="text" id="phone"<? if(isset($_POST['phone'])) print ' value="'.$_POST['phone'].'"'; ?> /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your phone number. This should be <?=$config['phone_digits']?> digits and contain only numbers.', this, event, '150px')">[?]</a></td>
+        <td class="style5">Phone<?php if($config['optional_fields_phone']=="false") print ' (optional)'; ?>: </td>
+        <td><input name="phone" type="text" id="phone"<?php if(isset($_POST['phone'])) print ' value="'.$_POST['phone'].'"'; ?> /><a href="#" class="hintanchor" onMouseover="showhint('Please enter your phone number. This should be <?php echo $config['phone_digits']?> digits and contain only numbers.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
-        <td class="style5">Country<? if($config['optional_fields_country']=="false") print ' (optional)'; ?>:</td>
+        <td class="style5">Country<?php if($config['optional_fields_country']=="false") print ' (optional)'; ?>:</td>
         <td>
 <?php
 if(isset($_POST['country'])){
@@ -216,7 +216,7 @@
         </tr>
       <tr>
         <td class="style5">Username:</td>
-        <td><input name="username" maxlength="15" type="text" id="username"<? if(isset($_POST['username'])) print ' value="'.$_POST['username'].'"'; ?> /><a href="#" class="hintanchor" onMouseover="showhint('Please choose a username. This must be alphanumeric and contain 5-10 characters.', this, event, '150px')">[?]</a></td>
+        <td><input name="username" maxlength="15" type="text" id="username"<?php if(isset($_POST['username'])) print ' value="'.$_POST['username'].'"'; ?> /><a href="#" class="hintanchor" onMouseover="showhint('Please choose a username. This must be alphanumeric and contain 5-10 characters.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
         <td class="style5">Password:</td>
@@ -227,9 +227,9 @@
         <td><input name="password2" maxlength="10" type="password" id="password2" /><a href="#" class="hintanchor" onMouseover="showhint('Please confirm the password you entered above.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
-        <td class="style2"><input name="welcome_user" type="checkbox" id="welcome_user" value="1" <? if(($config['user_welcome_email']=="true" && !isset($_POST['submit'])) || isset($_POST['welcome_user'])) print 'checked="checked" '; ?>/>
+        <td class="style2"><input name="welcome_user" type="checkbox" id="welcome_user" value="1" <?php if(($config['user_welcome_email']=="true" && !isset($_POST['submit'])) || isset($_POST['welcome_user'])) print 'checked="checked" '; ?>/>
         Send welcome email<a href="#" class="hintanchor2" onMouseover="showhint('Check this box if you would like to send a welcome email to the above email address.', this, event, '150px')">[?]</a></td>
-        <td class="style2"><input name="notify_admin" type="checkbox" id="notify_admin" value="checkbox" <? if(($config['admin_user_email']=="true" && !isset($_POST['submit'])) || isset($_POST['notify_admin'])) print 'checked="checked" '; ?>/>
+        <td class="style2"><input name="notify_admin" type="checkbox" id="notify_admin" value="checkbox" <?php if(($config['admin_user_email']=="true" && !isset($_POST['submit'])) || isset($_POST['notify_admin'])) print 'checked="checked" '; ?>/>
 Notify administrator<a href="#" class="hintanchor2" onmouseover="showhint('Check this box if you would like to send the administrator a notification email with this user\'s information.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
@@ -245,7 +245,7 @@
   </tr>
   
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
