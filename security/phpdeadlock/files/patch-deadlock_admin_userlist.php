--- ./deadlock/admin/userlist.php.orig	Sun Aug  6 17:40:16 2006
+++ deadlock/admin/userlist.php	Thu Oct 11 15:23:49 2007
@@ -139,10 +139,10 @@
   </tr>
   <tr>
     <td height="19" colspan="2"><br />
-        <form id="form1" name="form1" method="get" action="<?=$_SERVER['PHP_SELF']?>">
+        <form id="form1" name="form1" method="get" action="<?php echo $_SERVER['PHP_SELF']?>">
           <span class="style2">Search:</span>
           <input type="text" name="search" />
-          <input type="submit" value="Go" /><? if(!empty($_GET['search'])): ?><input type="button" value="View All" onclick="window.location='<?=$_SERVER['PHP_SELF']?>'" /><? endif; ?>
+          <input type="submit" value="Go" /><?php if(!empty($_GET['search'])): ?><input type="button" value="View All" onclick="window.location='<?php echo $_SERVER['PHP_SELF']?>'" /><?php endif; ?>
         </form>
         <br />
         <a href="./newuser.php" class="style2">Create New User&gt;&gt;</a><br /><br />
@@ -153,14 +153,14 @@
           <td width="28%" class="style5">Email</td>
           <td width="21%" class="style5">Actions</td>
         </tr>
-       <?=$userlist?>
+       <?php echo $userlist?>
       </table><br />
-      <? if($count > 0): ?><div align="center"><span class="style2">Page:</span> <span class="style5"><?=$pagelist?></span></div><br /><? endif; ?>
+      <?php if($count > 0): ?><div align="center"><span class="style2">Page:</span> <span class="style5"><?php echo $pagelist?></span></div><br /><?php endif; ?>
     <br /></td>
   </tr>
 
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
