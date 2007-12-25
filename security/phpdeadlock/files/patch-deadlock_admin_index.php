--- ./deadlock/admin/index.php.orig	Mon Jul 31 01:58:55 2006
+++ deadlock/admin/index.php	Thu Oct 11 15:23:49 2007
@@ -119,18 +119,18 @@
       </tr>
       <tr>
         <td width="40%" class="style2">Active Members:</td>
-        <td width="60%" class="style2"><a href="./userlist.php"><?=$currentmembers?></a>
+        <td width="60%" class="style2"><a href="./userlist.php"><?php echo $currentmembers?></a>
           <a href="#" class="hintanchor" onmouseover="showhint('This is the number of registered and approved members currently in the database.', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
         <td class="style2">Pending Requests:</td>
-        <td class="style2"><?=$pendingmembers?>
-          <a href="#" class="hintanchor" onmouseover="showhint('<?=$pendinghintbox?>', this, event, '150px')">[?]</a></td>
+        <td class="style2"><?php echo $pendingmembers?>
+          <a href="#" class="hintanchor" onmouseover="showhint('<?php echo $pendinghintbox?>', this, event, '150px')">[?]</a></td>
       </tr>
       <tr>
         <td class="style2">Inactive Users:</td>
-        <td class="style2"><?=$inactivemembers?>
-          <a href="#" class="hintanchor" onmouseover="showhint('<?=$inactivehintbox?>', this, event, '150px')">[?]</a></td>
+        <td class="style2"><?php echo $inactivemembers?>
+          <a href="#" class="hintanchor" onmouseover="showhint('<?php echo $inactivehintbox?>', this, event, '150px')">[?]</a></td>
       </tr>
     </table>
       <br />
@@ -140,31 +140,31 @@
         </tr>
         <tr>
           <td width="40%" class="style2">Version:</td>
-          <td width="60%"><span class="style11"><?=$this_version?></span> <a href="#" class="hintanchor" onmouseover="showhint('This is the version of Deadlock in which is installed on your server.', this, event, '150px')">[?]</a></td>
+          <td width="60%"><span class="style11"><?php echo $this_version?></span> <a href="#" class="hintanchor" onmouseover="showhint('This is the version of Deadlock in which is installed on your server.', this, event, '150px')">[?]</a></td>
         </tr>
         <tr>
           <td class="style2">Current Version:</td>
-          <td><span class="style11"><?=$latestversion?></span> <a href="#" class="hintanchor" onmouseover="showhint('This is the current version of Deadlock available for download.', this, event, '150px')">[?]</a></td>
+          <td><span class="style11"><?php echo $latestversion?></span> <a href="#" class="hintanchor" onmouseover="showhint('This is the current version of Deadlock available for download.', this, event, '150px')">[?]</a></td>
         </tr>
         <tr>
           <td height="20" class="style2">Status:</td>
-          <td><?=$upgrade?> <a href="#" class="hintanchor" onmouseover="showhint('<?=$statushint?>', this, event, '150px')">[?]</a></td>
+          <td><?php echo $upgrade?> <a href="#" class="hintanchor" onmouseover="showhint('<?php echo $statushint?>', this, event, '150px')">[?]</a></td>
         </tr>
     </table></td>
     <td height="171" valign="top"><span class="style2"><span class="style5">Navigation Menu</span><br />
 <a href="./index.php">Home</a><br />
 <a href="./userlist.php">Manage Users</a><br />
-<? if($config['require_admin_accept']=='true'): ?><a href="./userrequests.php">User Requests</a><br /><? endif; ?>
-<? if($config['verify_email']=='true'): ?><a href="./inactiveusers.php">Inactive Users</a><br /><? endif; ?>
+<?php if($config['require_admin_accept']=='true'): ?><a href="./userrequests.php">User Requests</a><br /><?php endif; ?>
+<?php if($config['verify_email']=='true'): ?><a href="./inactiveusers.php">Inactive Users</a><br /><?php endif; ?>
 <a href="./bulkemail.php">Bulk Email</a><br />
 <br />
 <a href="./editconfig.php">Configuration</a><br />
-<a href="<?=htmlentities($config['protected_area_url'])?>">My Protected Area</a><br />
+<a href="<?php echo htmlentities($config['protected_area_url'])?>">My Protected Area</a><br />
 <a href="./login.php?cmd=logout">Logout</a></span></td>
   </tr>
   
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
