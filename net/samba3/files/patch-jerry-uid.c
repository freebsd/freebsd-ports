Index: source/smbd/uid.c
===================================================================
--- smbd/uid.c	(revision 842)
+++ smbd/uid.c	(working copy)
@@ -189,20 +189,26 @@
 
 	snum = SNUM(conn);
 
+	if ((vuser) && !check_user_ok(conn, vuser, snum)) {
+		DEBUG(2,("change_to_user: SMB user %s (unix user %s, vuid %d) not permitted access to share %s.\n",
+			vuser->user.smb_name, vuser->user.unix_name, vuid, lp_servicename(snum)));
+		return False;
+	}
+
 	if (conn->force_user) /* security = share sets this too */ {
 		uid = conn->uid;
 		gid = conn->gid;
 		current_user.groups = conn->groups;
 		current_user.ngroups = conn->ngroups;
 		token = conn->nt_user_token;
-	} else if ((vuser) && check_user_ok(conn, vuser, snum)) {
+	} else if (vuser) {
 		uid = conn->admin_user ? 0 : vuser->uid;
 		gid = vuser->gid;
 		current_user.ngroups = vuser->n_groups;
 		current_user.groups  = vuser->groups;
 		token = vuser->nt_user_token;
 	} else {
-		DEBUG(2,("change_to_user: Invalid vuid used %d or vuid not permitted access to share.\n",vuid));
+		DEBUG(2,("change_to_user: Invalid vuid used %d in accessing share %s.\n",vuid, lp_servicename(snum) ));
 		return False;
 	}
 
