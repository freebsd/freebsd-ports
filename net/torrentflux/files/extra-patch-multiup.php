--- html/index.php.orig	Mon Oct 10 00:08:03 2005
+++ html/index.php	Mon Oct 10 00:08:54 2005
@@ -365,6 +381,7 @@
 		<?php echo _SELECTFILE ?>:<br>
 		<input type="File" name="upload_file" size="40">
 		<input type="Submit" value="<?php echo _UPLOAD ?>">	
+		<a href="multiup.php">Upload More?</a>
 		</td>
 		</form>
 	</tr>
--- html/multiup.php.orig	Thu Sep 29 09:57:15 2005
+++ html/multiup.php	Thu Sep 29 10:49:42 2005
@@ -0,0 +1,136 @@
+<?php
+
+/*************************************************************
+*  TorrentFlux - PHP Torrent Manager
+*  www.torrentflux.com
+**************************************************************/
+/*
+  This file is part of TorrentFlux.
+
+  TorrentFlux is free software; you can redistribute it and/or modify
+  it under the terms of the GNU General Public License as published by
+  the Free Software Foundation; either version 2 of the License, or
+  (at your option) any later version.
+
+  TorrentFlux is distributed in the hope that it will be useful,
+  but WITHOUT ANY WARRANTY; without even the implied warranty of
+  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+  GNU General Public License for more details.
+
+  You should have received a copy of the GNU General Public License
+  along with TorrentFlux; if not, write to the Free Software
+  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+*/
+
+
+include_once("config.php");
+include_once("functions.php");
+
+if (!empty($_FILES['upload_files'])) {
+    //echo '<pre>'; var_dump($_FILES); echo '</pre>';
+    foreach($_FILES['upload_files']['size'] as $id => $size) {
+        if ($size == 0)
+        {
+            //no or empty file, skip it
+            continue;
+        }
+        $file_name = stripslashes($_FILES['upload_files']['name'][$id]);
+        $file_name = str_replace(array("'",","), "", $file_name);
+        $file_name = cleanFileName($file_name);
+        $ext_msg = "";
+
+        if($_FILES['upload_files']['size'][$id] <= $cfg["max_upload"] &&
+           $_FILES['upload_files']['size'][$id] > $cfg["min_upload"])
+        {
+            if (ereg(getFileFilter($cfg["file_types_array"]), $file_name))
+            {
+                //FILE IS BEING UPLOADED
+                if (is_file($cfg["torrent_file_path"].$file_name))
+                {
+                    // Error
+                    $messages .= "<b>Error</b> with (<b>".$file_name."</b>), the file already exists on the server.<br><center><a href=\"".$_SERVER['PHP_SELF']."\">[Refresh]</a></center>";
+                    $ext_msg = "DUPLICATE :: ";
+                }
+                else
+                {
+                    if(move_uploaded_file($_FILES['upload_files']['tmp_name'][$id], $cfg["torrent_file_path"].$file_name))
+                    {
+                        chmod($cfg["torrent_file_path"].$file_name, 0644);
+                        AuditAction($cfg["constants"]["file_upload"], $file_name);
+                    }
+                    else
+                    {
+                        $messages .= "<font color=\"#ff0000\" size=3>ERROR: File not uploaded, file could not be found or could not be moved:<br>".$cfg["torrent_file_path"] . $file_name."</font><br>";
+                    }
+                }
+            }
+            else
+            {
+                $messages .= "<font color=\"#ff0000\" size=3>ERROR: The type of file you are uploading is not allowed.</font><br>";
+            }
+        }
+        else
+        {
+            $messages .= "<font color=\"#ff0000\" size=3>ERROR: File not uploaded, check file size limit.</font><br>";
+        }
+
+        if($messages != "")
+        {
+            // there was an error
+            AuditAction($cfg["constants"]["error"], $cfg["constants"]["file_upload"]." :: ".$ext_msg.$file_name);
+        }
+        else
+        {
+            header("location: index.php");
+        }
+    }  // End File Upload
+}
+    
+displayHead("Upload Multiple Torrents");
+?>
+
+<?php
+if ($messages != "")
+{
+?>
+<table border="1" cellpadding="10" bgcolor="#ff9b9b">
+    <tr>
+    <td><div align="center"><?php echo $messages ?></div></td>
+    </tr>
+</table><br><br>
+<?php
+}
+?>
+
+<table border="0" cellpadding="0" cellspacing="0" width="760">
+  <tr>
+    <td>
+      <table border="1" bordercolor="<?php echo $cfg["table_border_dk"] ?>" cellpadding="4" cellspacing="0" width="100%">
+        <tr>
+          <td bgcolor="<?php echo $cfg["table_header_bg"] ?>">
+            <table width="100%" cellpadding="3" cellspacing="0" border="0">
+              <form name="form_file" action="multiup.php" method="post" enctype="multipart/form-data">
+              <?php for($j = 0; $j < 5; ++$j) { ?>
+              <tr>
+                <?php for($i = 0; $i < 2; ++$i) { ?>
+                <td>
+                  <?php echo _SELECTFILE ?>:<br>
+                  <input type="File" name="upload_files[]" size="40">
+                </td>
+                <?php } ?>
+              </tr>
+              <?php } ?>
+              <tr>
+                <td>
+                  <input type="Submit" value="<?php echo _UPLOAD ?>" method="post">
+                </td>
+              </tr>
+              </form>
+            </table>
+          </td>
+        </tr>
+      </table>
+    </td>
+  </tr>
+</table>
+<?php DisplayFoot(); ?>
