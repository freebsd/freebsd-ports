--- etc/afpd/acls.c.orig	2011-07-30 18:08:35.000000000 -0400
+++ etc/afpd/acls.c	2011-07-30 18:19:19.000000000 -0400
@@ -1060,7 +1060,59 @@ static int set_acl(const struct vol *vol
 #ifdef HAVE_ACL_FROM_MODE
     EC_NULL_LOG_ERR(acc_acl = acl_from_mode(st.st_mode), AFPERR_MISC);
 #else
-#error "Missing acl_from_mode() replacement"
+    /* Implement the non POSIX.1e function acl_from_mode
+     *
+     * Taken from http://people.freebsd.org/~markus/stuff/kacl.diff
+     */
+    {
+	    acl_t new_acl = acl_init( 3 );
+	    acl_entry_t entry;
+	    acl_permset_t permset = 0;
+	    int error = 0;
+
+	    /* Add owner entry */
+	    if ( ( error = acl_create_entry( &new_acl, &entry ) ) == 0 ) {
+		    /* Set owner permissions */
+		    acl_set_tag_type( entry, ACL_USER_OBJ );
+		    acl_get_permset( entry, &permset );
+		    acl_clear_perms( permset );
+		    if ( st.st_mode & S_IRUSR ) acl_add_perm( permset, ACL_READ );
+		    if ( st.st_mode & S_IWUSR ) acl_add_perm( permset, ACL_WRITE );
+		    if ( st.st_mode & S_IXUSR ) acl_add_perm( permset, ACL_EXECUTE );
+		    acl_set_permset( entry, permset );
+
+		    /* Add group entry */
+		    if ( ( error = acl_create_entry( &new_acl, &entry ) ) == 0 ) {
+			    /* Set group permissions */
+			    acl_set_tag_type( entry, ACL_GROUP_OBJ );
+			    acl_get_permset( entry, &permset );
+			    acl_clear_perms( permset );
+			    if ( st.st_mode & S_IRGRP ) acl_add_perm( permset, ACL_READ );
+			    if ( st.st_mode & S_IWGRP ) acl_add_perm( permset, ACL_WRITE );
+			    if ( st.st_mode & S_IXGRP ) acl_add_perm( permset, ACL_EXECUTE );
+			    acl_set_permset( entry, permset );
+
+			    /* Add other entry */
+			    if ( ( error = acl_create_entry( &new_acl, &entry ) ) == 0 ) {
+				    /* Set other permissions */
+				    acl_set_tag_type( entry, ACL_OTHER );
+				    acl_get_permset( entry, &permset );
+				    acl_clear_perms( permset );
+				    if ( st.st_mode & S_IROTH ) acl_add_perm( permset, ACL_READ );
+				    if ( st.st_mode & S_IWOTH ) acl_add_perm( permset, ACL_WRITE );
+				    if ( st.st_mode & S_IXOTH ) acl_add_perm( permset, ACL_EXECUTE );
+				    acl_set_permset( entry, permset );
+			    }
+		    }
+	    }
+
+	    if ( error ) {
+		    acl_free( &new_acl );
+		    EC_NULL_LOG_ERR(acc_acl = NULL, AFPERR_MISC);
+	    }
+	    else
+		    acc_acl = new_acl;
+    }
 #endif
     /* adds the clients aces */
     EC_ZERO_ERR(map_aces_darwin_to_posix(daces, &def_acl, &acc_acl, ace_count), AFPERR_MISC);
