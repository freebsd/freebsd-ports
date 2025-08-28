commit e8f3a3e6f2c27e78c2778e0040b385b430dfc9fc
Author: Andrew Ruthven <puck@catalystcloud.nz>
Date:   Sun Apr 30 12:13:37 2023 +1200

    Add a missing space to a SQL statement to fix adding groups.
    
    It looks to me like this bug has been present since 2011.
    
    Closes: #294

diff --git a/inc/ui/principal-edit.php b/inc/ui/principal-edit.php
index 603fd1e1..df975e22 100644
--- inc/ui/principal-edit.php.orig
+++ inc/ui/principal-edit.php
@@ -495,9 +495,9 @@ function group_memberships_browser() {
 function group_row_editor() {
   global $c, $id, $editor, $can_write_principal;
   $grouprow = new Editor("Group Members", "group_member");
-  $sql = 'SELECT principal_id, coalesce(displayname,fullname,username) FROM dav_principal ';
-  $sql .= 'WHERE principal_id NOT IN (SELECT member_id FROM group_member WHERE group_id = '.$id.') ';
-  $sql .= 'AND principal_id != '.$id;
+  $sql = 'SELECT principal_id, coalesce(displayname, fullname, username) FROM dav_principal ';
+  $sql .= 'WHERE principal_id NOT IN (SELECT member_id FROM group_member WHERE group_id = ' . $id . ') ';
+  $sql .= 'AND principal_id != ' . $id . ' ';
   $sql .= 'ORDER BY 2';
   $grouprow->SetLookup( 'member_id', $sql);
   $grouprow->SetSubmitName( 'savegrouprow' );
