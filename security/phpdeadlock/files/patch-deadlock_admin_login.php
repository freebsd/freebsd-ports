--- ./deadlock/admin/login.php.orig	Mon Jul 31 01:58:55 2006
+++ deadlock/admin/login.php	Thu Oct 11 15:23:49 2007
@@ -94,11 +94,11 @@
     <td height="20" colspan="2" class="style2"><strong><a href="./index.php">Top</a>: Admin Panel Login </strong></td>
   </tr>
   <tr>
-    <td height="22" colspan="2" class="style2"><?=$message?></td>
+    <td height="22" colspan="2" class="style2"><?php echo $message?></td>
   </tr>
   <tr>
     <td height="19" colspan="2"><br /><br/><div align="center">
-      <form id="form1" name="form1" method="post" action="<?=$_SERVER['PHP_SELF']?>?<?=$_SERVER['QUERY_STRING']?>">
+      <form id="form1" name="form1" method="post" action="<?php echo $_SERVER['PHP_SELF']?>?<?php echo $_SERVER['QUERY_STRING']?>">
         <span class="style2">Password:</span>
         <input name="password" type="password" id="password" />
         <input type="submit" value="Login" />
@@ -107,7 +107,7 @@
     </div><br/><br/><br/></td>
   </tr>
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
