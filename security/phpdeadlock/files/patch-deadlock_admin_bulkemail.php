--- ./deadlock/admin/bulkemail.php.orig	Wed Aug  2 20:28:00 2006
+++ deadlock/admin/bulkemail.php	Thu Oct 11 15:23:48 2007
@@ -174,13 +174,13 @@
       <table width="91%" height="107" border="0" align="center">
       <tr>
         <td width="13%" height="20"><span class="style5">Subject:</span></td>
-        <td width="87%"><span class="style2"><?=$_POST['subject']?></span></td>
+        <td width="87%"><span class="style2"><?php echo $_POST['subject']?></span></td>
       </tr>
       <tr>
         <td height="21" colspan="2"><span class="style5">Message:</span></td>
         </tr>
       <tr>
-        <td colspan="2"><div class="style2"><?=nl2br(htmlentities($_POST['message']."\n\n".$_POST['footer']))?></div></td>
+        <td colspan="2"><div class="style2"><?php echo nl2br(htmlentities($_POST['message']."\n\n".$_POST['footer']))?></div></td>
         </tr>
     </table>
 
@@ -189,7 +189,7 @@
   </tr>
   
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
@@ -211,7 +211,7 @@
 ***********************************************/
 </script>
 <script type="text/javascript">
-<? if((isset($_GET['type']) && $_GET['type']=='html') && isset($_GET['editor'])): ?>
+<?php if((isset($_GET['type']) && $_GET['type']=='html') && isset($_GET['editor'])): ?>
 function insertAtCursor(myField, myValue){
 	// Get the editor instance that we want to interact with.
 	var oEditor = FCKeditorAPI.GetInstance('message') ;
@@ -225,7 +225,7 @@
 	else
 		alert( 'You must be on WYSIWYG mode!' ) ;
 }
-<? else: ?>
+<?php else: ?>
 function insertAtCursor(myField, myValue) {
 	//IE support
 	if (document.selection) {
@@ -245,7 +245,7 @@
 	}
 	myField.focus();
 }
-<? endif; ?>
+<?php endif; ?>
 function changeeditor(){
 	if(document.mailer.enableeditor.checked == true){
 		window.location = './bulkemail.php?type=html&editor=1';
@@ -279,7 +279,7 @@
       <strong>Codes:</strong>    &lt;%FirstName%&gt;, &lt;%LastName%&gt;, &lt;%Email%&gt;, &lt;%Username%&gt;, &lt;%RegistrationDate%&gt;, &lt;%RemovalURL%&gt; </td>
   </tr>
   <tr>
-    <td height="275" colspan="2"><? if (!empty($errors)){ ?><table width="95%" height="24" border="0" align="center">
+    <td height="275" colspan="2"><?php if (!empty($errors)){ ?><table width="95%" height="24" border="0" align="center">
       <tr>
         <td height="20">
 		<div class="style9"><ul>
@@ -291,45 +291,45 @@
 		</ul></div></td>
       </tr>
     </table>
-      <? } else { print '<br />'; } ?>
-	  <form action="<?=$_SERVER['PHP_SELF']?>" method="post" name="mailer">
+      <?php } else { print '<br />'; } ?>
+	  <form action="<?php echo $_SERVER['PHP_SELF']?>" method="post" name="mailer">
       <table width="100%" border="0" align="center">
       <tr>
         <td class="style5">Send To<a href="#" class="hintanchor" onmouseover="showhint('Please specify who you would like this email to be sent to. You may either select &quot;All Users&quot; or a specific user.', this, event, '150px')">[?]</a>:</td>
         <td><select name="to">
-        <option value="//all//"<?=$select_default?>>All Users</option>
-        <?=generate_user_menu($mysql['prefix'],$selected_user)?>
+        <option value="//all//"<?php echo $select_default?>>All Users</option>
+        <?php echo generate_user_menu($mysql['prefix'],$selected_user)?>
         </select></td>
       </tr>
       <tr>
         <td width="45%" class="style5">Email Subject<a href="#" class="hintanchor" onmouseover="showhint('Please enter the subject of the email you wish to send.', this, event, '150px')">[?]</a>:</td>
-        <td width="55%"><input name="subject" type="text" id="subject"<? if(isset($_POST['subject'])) print ' value="'.$_POST['subject'].'"'; ?> /></td>
+        <td width="55%"><input name="subject" type="text" id="subject"<?php if(isset($_POST['subject'])) print ' value="'.$_POST['subject'].'"'; ?> /></td>
       </tr>
       <tr>
         <td height="22" class="style5">Email Type<a href="#" class="hintanchor" onmouseover="showhint('If you want your email to be in HTML, select HTML, otherwise select Plain Text. Changing this will clear the whole form.', this, event, '150px')">[?]</a>:</td>
         <td height="22" class="style2">
-		<label><input name="type" type="radio" onclick="window.location='<?=$textlocation?>'" value="text"<? if(!isset($_GET['type']) || $_GET['type']!='html') print ' checked="checked"'; ?> />Plain Text</label>
-        <label><input name="type" type="radio" onclick="window.location='<?=$htmllocation?>'" value="html"<? if(isset($_GET['type']) && $_GET['type']=='html') print ' checked="checked"'; ?> />HTML</label>
+		<label><input name="type" type="radio" onclick="window.location='<?php echo $textlocation?>'" value="text"<?php if(!isset($_GET['type']) || $_GET['type']!='html') print ' checked="checked"'; ?> />Plain Text</label>
+        <label><input name="type" type="radio" onclick="window.location='<?php echo $htmllocation?>'" value="html"<?php if(isset($_GET['type']) && $_GET['type']=='html') print ' checked="checked"'; ?> />HTML</label>
 		</td>
       </tr>
-      <? if(isset($_GET['type']) && $_GET['type']=='html'): ?>
+      <?php if(isset($_GET['type']) && $_GET['type']=='html'): ?>
       <tr>
         <td height="22" class="style5">Enable HTML Editor:<a href="#" class="hintanchor" onmouseover="showhint('Select this box if you wish to enable the WYSIWYG editor. Changing the value here will reset the form.', this, event, '150px')">[?]</a>:</td>
         <td height="22" class="style2">
-		<input type="checkbox" id="enableeditor" name="enableeditor" value="1" onchange="changeeditor()"<? if(isset($_GET['editor'])) print ' checked="checked"'; ?> />
+		<input type="checkbox" id="enableeditor" name="enableeditor" value="1" onchange="changeeditor()"<?php if(isset($_GET['editor'])) print ' checked="checked"'; ?> />
 		</td>
       </tr>
-      <? endif; ?>
+      <?php endif; ?>
       <tr>
         <td height="22" colspan="2" class="style5">Email Message<a href="#" class="hintanchor" onmouseover="showhint('Please enter your message here. This will appear in the body of the email.', this, event, '150px')">[?]</a>: </td>
         </tr>
-      <? //if((!isset($_GET['type']) || $_GET['type']!='html') && (!isset($_GET['editor']))): ?><tr>
-        <td height="19" colspan="2" class="style2 style13"><div align="center"><strong>Insert:</strong> <a href="javascript:insertAtCursor(document.mailer.message, '<?='<%FirstName%>'?>')">First Name</a> | <a href="javascript:insertAtCursor(document.mailer.message, '<?='<%LastName%>'?>')">Last Name</a> | <a href="javascript:insertAtCursor(document.mailer.message, '<?='<%Email%>'?>')">Email</a> | <a href="javascript:insertAtCursor(document.mailer.message, '<?='<%Username%>'?>')">Username</a> | <a href="javascript:insertAtCursor(document.mailer.message, '<?='<%RegistrationDate%>'?>')">Date Registered</a> | 
-            <a href="javascript:insertAtCursor(document.mailer.message, '<?='<%RemovalURL%>'?>')">Removal URL</a></div></td>
-      </tr><? //endif; ?>
+      <?php //if((!isset($_GET['type']) || $_GET['type']!='html') && (!isset($_GET['editor']))): ?><tr>
+        <td height="19" colspan="2" class="style2 style13"><div align="center"><strong>Insert:</strong> <a href="javascript:insertAtCursor(document.mailer.message, '<?php echo '<%FirstName%>'?>')">First Name</a> | <a href="javascript:insertAtCursor(document.mailer.message, '<?php echo '<%LastName%>'?>')">Last Name</a> | <a href="javascript:insertAtCursor(document.mailer.message, '<?php echo '<%Email%>'?>')">Email</a> | <a href="javascript:insertAtCursor(document.mailer.message, '<?php echo '<%Username%>'?>')">Username</a> | <a href="javascript:insertAtCursor(document.mailer.message, '<?php echo '<%RegistrationDate%>'?>')">Date Registered</a> | 
+            <a href="javascript:insertAtCursor(document.mailer.message, '<?php echo '<%RemovalURL%>'?>')">Removal URL</a></div></td>
+      </tr><?php //endif; ?>
       <tr>
         <td colspan="2" class="style2">
-<? 
+<?php 
 if((isset($_GET['type']) && $_GET['type']=='html') && isset($_GET['editor'])):
 $oFCKeditor = new FCKeditor('message') ;
 $oFCKeditor->BasePath = '../fckeditor/';
@@ -339,27 +339,27 @@
 $oFCKeditor->Create() ;
 else:
 ?> 
-        <textarea name="message" cols="60" rows="10" id="message"><? if(isset($_POST['message'])) print $_POST['message']; ?></textarea>
-<? endif; ?>
+        <textarea name="message" cols="60" rows="10" id="message"><?php if(isset($_POST['message'])) print $_POST['message']; ?></textarea>
+<?php endif; ?>
         </td>
         </tr>
-      <? if(!isset($_GET['type'])): ?>
+      <?php if(!isset($_GET['type'])): ?>
 	  <tr>
         <td height="20" colspan="2" class="style5">Footer<a href="#" class="hintanchor" onmouseover="showhint('Whatever is entered in this field will be directly attached to your message.', this, event, '150px')">[?]</a>:</td>
         </tr>
       
       <tr>
         <td colspan="2"><span class="style2">
-          <textarea name="footer" cols="60" rows="5" id="footer"><?=$config['bulk_email_footer']?></textarea>
+          <textarea name="footer" cols="60" rows="5" id="footer"><?php echo $config['bulk_email_footer']?></textarea>
         </span></td>
         </tr>
       <tr>
-      <? endif; ?>
+      <?php endif; ?>
         <td>&nbsp;</td>
         <td><div align="right">
           <input type="hidden" name="submit" value="1" />
           <input type="submit" value="Submit" />
-            <input type="button" value="Reset" onclick="window.location='<?=$_SERVER['PHP_SELF']?>'" />
+            <input type="button" value="Reset" onclick="window.location='<?php echo $_SERVER['PHP_SELF']?>'" />
         </div></td>
       </tr>
     </table>
@@ -368,7 +368,7 @@
   </tr>
   
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
