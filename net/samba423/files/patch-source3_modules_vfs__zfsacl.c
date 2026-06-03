--- source3/modules/vfs_zfsacl.c	2024-07-29 11:03:15.390630700 +0200
+++ source3/modules/vfs_zfsacl.c	2025-01-07 15:56:32.048227000 +0100
@@ -169,6 +169,7 @@
 	bool must_add_empty_ace = false;
 	struct zfsacl_config_data *config = NULL;
 	int fd;
+	struct sys_proc_fd_path_buf buf;
 
 	SMB_VFS_HANDLE_GET_DATA(handle, config,
 				struct zfsacl_config_data,
@@ -235,24 +236,52 @@
 	SMB_ASSERT(i == naces);
 
 	/* store acl */
-	fd = fsp_get_pathref_fd(fsp);
-	if (fd == -1) {
+	
+	if (!fsp->fsp_flags.is_pathref) {
+	    fd = fsp_get_io_fd(fsp);
+	    
+	    rv = facl(fd, ACE_SETACL, naces, acebuf);
+	    if (rv != 0) {
+		DEBUG(8, ("zfs_process_smbacl(%s): Not PATHREF: facl(ACE_SETACL, %d): %s\n",
+			  fsp_str_dbg(fsp), naces,
+			  strerror(errno)));
+		return false;
+	    }
+	    DEBUG(10, ("zfs_process_smbacl(%s): Not PATHREF: facl(ACE_SETACL, %d) -> %d\n",
+		      fsp_str_dbg(fsp), naces,
+		      rv));
+	    
+	} else if (fsp->fsp_flags.have_proc_fds) {
+	    fd = fsp_get_pathref_fd(fsp);
+	    if (fd == -1) {
+		DEBUG(8, ("zfs_process_smbacl(%s): PATHREF(proc_fd): fsp_get_pathref_fd=-1: %s\n",
+			  fsp_str_dbg(fsp), strerror(errno)));
 		errno = EBADF;
 		return false;
-	}
-	rv = facl(fd, ACE_SETACL, naces, acebuf);
-	if (rv != 0) {
-		if(errno == ENOSYS) {
-			DEBUG(9, ("acl(ACE_SETACL, %s): Operation is not "
-				  "supported on the filesystem where the file "
-				  "resides\n", fsp_str_dbg(fsp)));
-		} else {
-			DEBUG(9, ("acl(ACE_SETACL, %s): %s\n", fsp_str_dbg(fsp),
-				  strerror(errno)));
-		}
+	    }
+	    rv = acl(sys_proc_fd_path(fd, &buf), ACE_SETACL, naces, acebuf);
+	    if (rv != 0) {
+		DEBUG(8, ("zfs_process_smbacl(%s): acl(ACE_SETACL, %d): %s\n",
+			  fsp_str_dbg(fsp), naces,
+			  strerror(errno)));
 		return false;
+	    }
+	    DEBUG(10, ("zfs_process_smbacl(%s): PATHREF(proc_fd): acl(ACE_SETACL, %d) -> %d\n",
+		      fsp_str_dbg(fsp), naces,
+		      rv));
+	} else {
+	    rv = acl(fsp->fsp_name->base_name, ACE_SETACL, naces, acebuf);
+	    if (rv != 0) {
+		DEBUG(8, ("zfs_process_smbacl(%s): PATHREF(base_name): acl(ACE_SETACL, %d): %s\n",
+			  fsp_str_dbg(fsp), naces,
+			  strerror(errno)));
+		return false;
+	    }
+	    DEBUG(10, ("zfs_process_smbacl(%s): PATHREF(base_name): facl(ACE_SETACL, %d) -> %d\n",
+		      fsp_str_dbg(fsp), naces,
+		      rv));
 	}
-
+	
 	return True;
 }
 
@@ -282,25 +311,46 @@
 		       struct files_struct *fsp,
 		       ace_t **outbuf)
 {
-	int naces, rv;
+    	int naces, rv = -1, fd = -1;
 	ace_t *acebuf = NULL;
-	int fd;
+	struct sys_proc_fd_path_buf buf;
 
-	fd = fsp_get_pathref_fd(fsp);
-	if (fd == -1) {
+	
+	if (!fsp->fsp_flags.is_pathref) {
+	    fd = fsp_get_io_fd(fsp);
+	    if (fd == -1) {
+		DEBUG(8, ("fget_zfsacl(%s): Not PATHREF: fsp_get_io_fd=-1: %s\n",
+				  fsp_str_dbg(fsp), strerror(errno)));
 		errno = EBADF;
 		return -1;
-	}
-	naces = facl(fd, ACE_GETACLCNT, 0, NULL);
-	if (naces == -1) {
-		int dbg_level = 10;
-
-		if (errno == ENOSYS) {
-			dbg_level = 1;
-		}
-		DEBUG(dbg_level, ("facl(ACE_GETACLCNT, %s): %s\n",
+	    }
+	    naces = facl(fd, ACE_GETACLCNT, 0, NULL);
+	    if (naces == -1) {
+		DEBUG(8, ("fget_zfsacl(%s): Not PATHREF: facl(ACE_GETACLCNT): %s\n",
+			  fsp_str_dbg(fsp), strerror(errno)));
+		return -1;
+	    }
+	} else if (fsp->fsp_flags.have_proc_fds) {
+	    fd = fsp_get_pathref_fd(fsp);
+	    if (fd == -1) {
+		DEBUG(8, ("fget_zfsacl(%s): PATHREF(proc_fd): fsp_get_pathref_fd=-1: %s\n",
+			  fsp_str_dbg(fsp), strerror(errno)));
+		errno = EBADF;
+		return -1;
+	    }
+	    naces = acl(sys_proc_fd_path(fd, &buf), ACE_GETACLCNT, 0, NULL);
+	    if (naces == -1) {
+		DEBUG(8, ("fget_zfsacl(%s): PATHREF(proc_fd): acl(ACE_GETACLCNT): %s\n",
 				  fsp_str_dbg(fsp), strerror(errno)));
-		return naces;
+		return -1;
+	    }
+	} else {
+	    naces = acl(fsp->fsp_name->base_name, ACE_GETACLCNT, 0, NULL);
+	    if (naces == -1) {
+		DEBUG(8, ("fget_zfsacl(%s): PATHREF(base_name): acl(ACE_GETACLCNT): %s\n",
+				  fsp_str_dbg(fsp), strerror(errno)));
+		return -1;
+	    }
 	}
 
 	acebuf = talloc_size(mem_ctx, sizeof(ace_t)*naces);
@@ -309,15 +359,37 @@
 		return -1;
 	}
 
-	rv = facl(fd, ACE_GETACL, naces, acebuf);
-	if (rv == -1) {
-		DBG_DEBUG("acl(ACE_GETACL, %s): %s\n",
-			  fsp_str_dbg(fsp), strerror(errno));
+	if (!fsp->fsp_flags.is_pathref) {
+	    rv = facl(fd, ACE_GETACL, naces, acebuf);
+	    if (rv == -1) {
+		DEBUG(8, ("fget_zfsacl(%s): Not PATHREF: facl(ACE_GETACL): %s\n",
+			  fsp_str_dbg(fsp), strerror(errno)));
 		return -1;
+	    }
+	    DEBUG(10, ("fget_zfsacl(%s): Not PATHREF: facl(ACE_GETACL) -> %d entries\n",
+		      fsp_str_dbg(fsp), rv));
+	} else if (fsp->fsp_flags.have_proc_fds) {
+	    rv = acl(sys_proc_fd_path(fd, &buf), ACE_GETACL, naces, acebuf);
+	    if (rv == -1) {
+		DEBUG(8, ("fget_zfsacl(%s): PATHREF(proc_fd): acl(ACE_GETACL): %s\n",
+			  fsp_str_dbg(fsp), strerror(errno)));
+		return -1;
+	    }
+	    DEBUG(10, ("fget_zfsacl(%s): PATHREF(proc_fd): acl(ACE_GETACL) -> %d entries\n",
+		      fsp_str_dbg(fsp), rv));
+	} else {
+	    rv = acl(fsp->fsp_name->base_name, ACE_GETACL, naces, acebuf);
+	    if (rv == -1) {
+		DEBUG(8, ("fget_zfsacl(%s): PATHREF(base_name): acl(ACE_GETACL): %s\n",
+			  fsp_str_dbg(fsp), strerror(errno)));
+		return -1;
+	    }
+	    DEBUG(10, ("fget_zfsacl(%s): PATHREF(base_name): acl(ACE_GETACL) -> %d entries\n",
+		      fsp_str_dbg(fsp), rv));
 	}
-
+	    
 	*outbuf = acebuf;
-	return naces;
+	return rv;
 }
 
 static NTSTATUS zfsacl_fget_nt_acl(struct vfs_handle_struct *handle,
