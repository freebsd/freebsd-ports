--- smbd/sec_ctx.c.orig	Thu Mar  1 05:54:08 2007
+++ smbd/sec_ctx.c	Tue Jun  5 01:16:32 2007
@@ -192,7 +192,7 @@
 
 	if (sec_ctx_stack_ndx == MAX_SEC_CTX_DEPTH) {
 		DEBUG(0, ("Security context stack overflow!\n"));
-		smb_panic("Security context stack overflow!\n");
+		smb_panic("Security context stack overflow!");
 	}
 
 	/* Store previous user context */
@@ -234,7 +234,9 @@
 void set_sec_ctx(uid_t uid, gid_t gid, int ngroups, gid_t *groups, NT_USER_TOKEN *token)
 {
 	struct sec_ctx *ctx_p = &sec_ctx_stack[sec_ctx_stack_ndx];
-	
+#ifdef HAVE_SETGROUPS
+	gid_t *new_groups = NULL;
+#endif
 	/* Set the security context */
 
 	DEBUG(3, ("setting sec ctx (%u, %u) - sec_ctx_stack_ndx = %d\n", 
@@ -246,12 +248,20 @@
 	gain_root();
 
 #ifdef HAVE_SETGROUPS
-	sys_setgroups(ngroups, groups);
+	if (!(new_groups = SMB_MALLOC_ARRAY(gid_t, ngroups+1))) {
+	    smb_panic("malloc for groups failed");
+	}
+	new_groups[0] = gid;
+	if(ngroups) {
+		memcpy(&new_groups[1], groups, sizeof(gid_t) * ngroups);
+	}
+	sys_setgroups(ngroups+1, new_groups);
+	SAFE_FREE(new_groups);
 #endif
 
 	ctx_p->ut.ngroups = ngroups;
-
 	SAFE_FREE(ctx_p->ut.groups);
+
 	if (token && (token == ctx_p->token)) {
 		smb_panic("DUPLICATE_TOKEN");
 	}
@@ -262,7 +272,7 @@
 		ctx_p->ut.groups = (gid_t *)memdup(groups,
 						   sizeof(gid_t) * ngroups);
 		if (!ctx_p->ut.groups) {
-			smb_panic("memdup failed");
+			smb_panic("memdup for groups failed");
 		}
 	} else {
 		ctx_p->ut.groups = NULL;
@@ -315,7 +325,7 @@
 
 	if (sec_ctx_stack_ndx == 0) {
 		DEBUG(0, ("Security context stack underflow!\n"));
-		smb_panic("Security context stack underflow!\n");
+		smb_panic("Security context stack underflow!");
 	}
 
 	ctx_p = &sec_ctx_stack[sec_ctx_stack_ndx];
