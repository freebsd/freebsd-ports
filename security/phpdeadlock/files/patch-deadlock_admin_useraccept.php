--- ./deadlock/admin/useraccept.php.orig	Mon Jul 31 01:58:55 2006
+++ deadlock/admin/useraccept.php	Thu Oct 11 15:23:49 2007
@@ -117,7 +117,7 @@
     <td height="20" colspan="2" class="style2"><strong><a href="./index.php">Top</a>: User Updated Successfully </strong></td>
   </tr>
   <tr>
-    <td height="28" colspan="2" class="style2">The user &quot;<?=htmlentities($_GET['user'])?>&quot; was updated successfully! Please wait while your are redirected to the user request list.</td>
+    <td height="28" colspan="2" class="style2">The user &quot;<?php echo htmlentities($_GET['user'])?>&quot; was updated successfully! Please wait while your are redirected to the user request list.</td>
   </tr>
   <tr>
     <td height="19" colspan="2"><br />
@@ -125,17 +125,17 @@
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
 <meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
-<META HTTP-EQUIV="Refresh" CONTENT="5; URL=./userinfo.php?user=<?=htmlentities($_GET['user'])?>">
+<META HTTP-EQUIV="Refresh" CONTENT="5; URL=./userinfo.php?user=<?php echo htmlentities($_GET['user'])?>">
 <title>Deadlock - User Updated Successfully</title>
 <link href="../images/admin.css" rel="stylesheet" type="text/css" media="all" />
 </head>
@@ -152,7 +152,7 @@
     <td height="20" colspan="2" class="style2"><strong><a href="./index.php">Top</a>: User Update Failed </strong></td>
   </tr>
   <tr>
-    <td height="28" colspan="2" class="style2">The user <?=htmlentities($_GET['user'])?> was unable to be updated. Please make sure MySQL is running and setup correctly. Please wait while your are redirected to the request list.</td>
+    <td height="28" colspan="2" class="style2">The user <?php echo htmlentities($_GET['user'])?> was unable to be updated. Please make sure MySQL is running and setup correctly. Please wait while your are redirected to the request list.</td>
   </tr>
   <tr>
     <td height="19" colspan="2"><br />
@@ -160,7 +160,7 @@
   </tr>
   
   <tr>
-    <td height="21" colspan="2" class="footercell"><div align="center"><?show_footer($software_signature)?></div></td>
+    <td height="21" colspan="2" class="footercell"><div align="center"><?phpshow_footer($software_signature)?></div></td>
   </tr>
 </table>
 </body>
