--- ./deadlock/admin/userinfo.php.orig	Mon Jul 31 01:58:55 2006
+++ deadlock/admin/userinfo.php	Thu Oct 11 15:23:49 2007
@@ -127,53 +127,53 @@
       <table width="70%" border="0">
       <tr>
         <td width="31%" class="style5">Full Name:</td>
-        <td width="69%" class="style2"><?=$name?></td>
+        <td width="69%" class="style2"><?php echo $name?></td>
       </tr>
       <tr>
         <td class="style5">Username:</td>
-        <td class="style2"><?=$username?></td>
+        <td class="style2"><?php echo $username?></td>
       </tr>
       <tr>
         <td class="style5">Email Address: </td>
-        <td class="style2"><? if($status=='2'): ?><a href="./bulkemail.php?user=<?=$username?>"><?=$email?></a><? else: print $email; endif; ?></td>
+        <td class="style2"><?php if($status=='2'): ?><a href="./bulkemail.php?user=<?php echo $username?>"><?php echo $email?></a><?php else: print $email; endif; ?></td>
       </tr>
       <tr>
         <td class="style5">Country:</td>
-        <td class="style2"><?=$country?></td>
+        <td class="style2"><?php echo $country?></td>
       </tr>
       <tr>
         <td class="style5">Phone:</td>
-        <td class="style2"><?=FormatPhoneNumber($phone)?></td>
+        <td class="style2"><?php echo FormatPhoneNumber($phone)?></td>
       </tr>
       <tr>
         <td class="style5">Date Registered:</td>
-        <td class="style2"><?=$RegistrationDate?></td>
+        <td class="style2"><?php echo $RegistrationDate?></td>
       </tr>
       <tr>
         <td class="style5">Status:</td>
-        <td class="style2"><?=$statustext?></td>
+        <td class="style2"><?php echo $statustext?></td>
       </tr>
     </table>
       <br />
-      <? if($status=='1'): ?>
-      <input name="Button" type="button" value="Accept" onclick="acceptuser('<?=$username?>')" />
-      <input name="Button" type="button" value="Decline" onclick="denyuser('<?=$username?>')" />
-      <? else: ?>
-      <input name="Button" type="button" value="Delete" onclick="deleteuser('<?=$username?>')" />
-      <input type="submit" value="Edit" onclick="window.location='./edituser.php?user=<?=$username?>'" />
-      <? endif; ?>
+      <?php if($status=='1'): ?>
+      <input name="Button" type="button" value="Accept" onclick="acceptuser('<?php echo $username?>')" />
+      <input name="Button" type="button" value="Decline" onclick="denyuser('<?php echo $username?>')" />
+      <?php else: ?>
+      <input name="Button" type="button" value="Delete" onclick="deleteuser('<?php echo $username?>')" />
+      <input type="submit" value="Edit" onclick="window.location='./edituser.php?user=<?php echo $username?>'" />
+      <?php endif; ?>
       <br />
 
   <span class="style2"><br />
       <br /><a href="./userlist.php">&lt;&lt; Back to user list</a><br/><br/><br/></span></td>
   </tr>
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
 </html>
-<? else: ?>
+<?php else: ?>
 <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
 <html xmlns="http://www.w3.org/1999/xhtml">
 <head>
@@ -211,9 +211,9 @@
   </tr>
   
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
 </html>
-<? endif; ?>
\ No newline at end of file
+<?php endif; ?>
\ No newline at end of file
