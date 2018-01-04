--- source3/modules/vfs_streams_xattr.c.orig	2017-09-17 19:15:34 UTC
+++ source3/modules/vfs_streams_xattr.c
@@ -1,10 +1,10 @@
 /*
  * Store streams in xattrs
  *
- * Copyright (C) Volker Lendecke, 2008
+ * Copyright (C) Volker Lendecke,  2008
+ * Copyright (C) Timur I. Bakeyev, 2017
  *
  * Partly based on James Peach's Darwin module, which is
- *
  * Copyright (C) James Peach 2006-2007
  *
  * This program is free software; you can redistribute it and/or modify
@@ -79,25 +79,79 @@ static SMB_INO_T stream_inode(const SMB_
 }
 
 static ssize_t get_xattr_size(connection_struct *conn,
-				const struct smb_filename *smb_fname,
-				const char *xattr_name)
+			      const struct smb_filename *smb_fname,
+			      const char *xattr_name)
 {
-	NTSTATUS status;
-	struct ea_struct ea;
 	ssize_t result;
 
-	status = get_ea_value(talloc_tos(), conn, NULL, smb_fname,
-			      xattr_name, &ea);
+	result = SMB_VFS_GETXATTR(conn, smb_fname, xattr_name, NULL, 0);
+	// ? -1
+//	result = result-1;
+	return result;
+}
 
-	if (!NT_STATUS_IS_OK(status)) {
-		return -1;
+static NTSTATUS get_xattr_value(TALLOC_CTX *mem_ctx,
+			connection_struct *conn,
+			const struct smb_filename *smb_fname,
+			const char *ea_name,
+			struct ea_struct *pea)
+{
+	ssize_t attr_size;
+
+	attr_size = get_xattr_size(conn, smb_fname, ea_name);
+
+	if (attr_size == -1) {
+		return map_nt_error_from_unix(errno);
 	}
 
-	result = ea.value.length-1;
-	TALLOC_FREE(ea.value.data);
-	return result;
+	pea->value = data_blob_talloc(mem_ctx, NULL, attr_size);
+	if(pea->value.data == NULL) {
+		DEBUG(5,
+			("get_xattr_value: for EA '%s' failed to allocate %lu bytes\n",
+			ea_name, (unsigned long)attr_size)
+		);
+		return NT_STATUS_NO_MEMORY;
+	}
+
+	attr_size = SMB_VFS_GETXATTR(conn, smb_fname, ea_name, pea->value.data, pea->value.length);
+
+	if (attr_size == -1) {
+		return map_nt_error_from_unix(errno);
+	}
+
+	if(pea->value.length != attr_size) {
+		DEBUG(5,
+			("get_xattr_value: for EA '%s' requested %lu, read %lu bytes\n",
+			ea_name, (unsigned long)pea->value.length, (unsigned long)attr_size)
+		);
+		return NT_STATUS_UNSUCCESSFUL;
+	}
+
+	DEBUG(10,("get_xattr_value: EA '%s' is of length %lu\n", ea_name, (unsigned long)attr_size));
+	/*
+	 * This can dump huge amount of data multiple times. For example
+	 * for 1Mb ADS and chunk size 64Kb the same 1Mb dump will be
+	 * logged 16 times!
+	 */
+	dump_data(50, (uint8_t *)pea->value.data, pea->value.length);
+
+	pea->flags = 0;
+	// ? user.
+	if (strnequal(ea_name, "user.", 5)) {
+		pea->name = talloc_strdup(mem_ctx, &ea_name[5]);
+	} else {
+		pea->name = talloc_strdup(mem_ctx, ea_name);
+	}
+
+	if (pea->name == NULL) {
+		data_blob_free(&pea->value);
+		return NT_STATUS_NO_MEMORY;
+	}
+
+	return NT_STATUS_OK;
 }
 
+
 /**
  * Given a stream name, populate xattr_name with the xattr name to use for
  * accessing the stream.
@@ -114,6 +168,7 @@ static NTSTATUS streams_xattr_get_name(v
 	SMB_VFS_HANDLE_GET_DATA(handle, config, struct streams_xattr_config,
 				return NT_STATUS_UNSUCCESSFUL);
 
+        // stream_name is passed as ':stream', so skip leading ':'
 	sname = talloc_strdup(ctx, stream_name + 1);
 	if (sname == NULL) {
 		return NT_STATUS_NO_MEMORY;
@@ -125,7 +180,7 @@ static NTSTATUS streams_xattr_get_name(v
 	 * characters from their on-the-wire Unicode Private Range
 	 * encoding to their native ASCII representation.
 	 *
-	 * As as result the name of xattrs storing the streams (via
+	 * As a result the name of xattrs storing the streams (via
 	 * vfs_streams_xattr) may contain a colon, so we have to use
 	 * strrchr_m() instead of strchr_m() for matching the stream
 	 * type suffix.
@@ -157,7 +212,7 @@ static NTSTATUS streams_xattr_get_name(v
 		return NT_STATUS_NO_MEMORY;
 	}
 
-	DEBUG(10, ("xattr_name: %s, stream_name: %s\n", *xattr_name,
+	DEBUG(10, ("xattr_name: '%s', stream_name: '%s'\n", *xattr_name,
 		   stream_name));
 
 	talloc_free(sname);
@@ -265,8 +320,8 @@ static int streams_xattr_fstat(vfs_handl
 		return -1;
 	}
 
-	sbuf->st_ex_size = get_xattr_size(handle->conn,
-					smb_fname_base, io->xattr_name);
+	sbuf->st_ex_size = get_xattr_size(handle->conn, smb_fname_base,
+					  io->xattr_name);
 	if (sbuf->st_ex_size == -1) {
 		TALLOC_FREE(smb_fname_base);
 		SET_STAT_INVALID(*sbuf);
@@ -451,10 +506,10 @@ static int streams_xattr_open(vfs_handle
 	pipe_fds[1] = -1;
 	fakefd = pipe_fds[0];
 
-	status = get_ea_value(talloc_tos(), handle->conn, NULL,
-			      smb_fname, xattr_name, &ea);
+	status = get_xattr_value(talloc_tos(), handle->conn,
+				 smb_fname, xattr_name, &ea);
 
-	DEBUG(10, ("get_ea_value returned %s\n", nt_errstr(status)));
+	DEBUG(10, ("get_xattr_value returned %s\n", nt_errstr(status)));
 
 	if (!NT_STATUS_IS_OK(status)
 	    && !NT_STATUS_EQUAL(status, NT_STATUS_NOT_FOUND)) {
@@ -631,8 +686,8 @@ static int streams_xattr_rename(vfs_hand
 	}
 
 	/* read the old stream */
-	status = get_ea_value(talloc_tos(), handle->conn, NULL,
-			      smb_fname_src, src_xattr_name, &ea);
+	status = get_xattr_value(talloc_tos(), handle->conn,
+				 smb_fname_src, src_xattr_name, &ea);
 	if (!NT_STATUS_IS_OK(status)) {
 		errno = ENOENT;
 		goto fail;
@@ -719,14 +774,13 @@ static NTSTATUS walk_xattr_streams(vfs_h
 			continue;
 		}
 
-		status = get_ea_value(names,
+		status = get_xattr_value(names,
 					handle->conn,
-					NULL,
 					smb_fname,
 					names[i],
 					&ea);
 		if (!NT_STATUS_IS_OK(status)) {
-			DEBUG(10, ("Could not get ea %s for file %s: %s\n",
+			DEBUG(10, ("Could not get EA %s for file %s: %s\n",
 				names[i],
 				smb_fname->base_name,
 				nt_errstr(status)));
@@ -788,16 +842,17 @@ struct streaminfo_state {
 	NTSTATUS status;
 };
 
-static bool collect_one_stream(struct ea_struct *ea, void *private_data)
+static bool collect_one_stream(struct ea_struct *pea, void *private_data)
 {
 	struct streaminfo_state *state =
 		(struct streaminfo_state *)private_data;
 
+	// ? -1
 	if (!add_one_stream(state->mem_ctx,
 			    &state->num_streams, &state->streams,
-			    ea->name, ea->value.length-1,
+			    pea->name, pea->value.length,
 			    smb_roundup(state->handle->conn,
-					ea->value.length-1))) {
+					pea->value.length))) {
 		state->status = NT_STATUS_NO_MEMORY;
 		return false;
 	}
@@ -917,14 +972,17 @@ static ssize_t streams_xattr_pwrite(vfs_
 				    files_struct *fsp, const void *data,
 				    size_t n, off_t offset)
 {
-        struct stream_io *sio =
+	struct stream_io *sio =
 		(struct stream_io *)VFS_FETCH_FSP_EXTENSION(handle, fsp);
+	struct smb_filename *smb_fname_base = NULL;
+	TALLOC_CTX *frame = NULL;
+
 	struct ea_struct ea;
 	NTSTATUS status;
-	struct smb_filename *smb_fname_base = NULL;
 	int ret;
 
-	DEBUG(10, ("streams_xattr_pwrite called for %d bytes\n", (int)n));
+	DEBUG(10, ("streams_xattr_pwrite: offset=%lu, size=%lu\n",
+		   (unsigned long)offset, (unsigned long)n));
 
 	if (sio == NULL) {
 		return SMB_VFS_NEXT_PWRITE(handle, fsp, data, n, offset);
@@ -934,6 +992,8 @@ static ssize_t streams_xattr_pwrite(vfs_
 		return -1;
 	}
 
+	frame = talloc_stackframe();
+
 	/* Create an smb_filename with stream_name == NULL. */
 	smb_fname_base = synthetic_smb_fname(talloc_tos(),
 					sio->base,
@@ -945,35 +1005,28 @@ static ssize_t streams_xattr_pwrite(vfs_
 		return -1;
 	}
 
-	status = get_ea_value(talloc_tos(), handle->conn, NULL,
-			      smb_fname_base, sio->xattr_name, &ea);
+	status = get_xattr_value(talloc_tos(), handle->conn,
+				 smb_fname_base, sio->xattr_name, &ea);
 	if (!NT_STATUS_IS_OK(status)) {
+		TALLOC_FREE(frame);
 		return -1;
 	}
-
-        if ((offset + n) > ea.value.length-1) {
-		uint8_t *tmp;
-
-		tmp = talloc_realloc(talloc_tos(), ea.value.data, uint8_t,
-					   offset + n + 1);
-
-		if (tmp == NULL) {
-			TALLOC_FREE(ea.value.data);
-                        errno = ENOMEM;
-                        return -1;
-                }
-		ea.value.data = tmp;
-		ea.value.length = offset + n + 1;
-		ea.value.data[offset+n] = 0;
-        }
-
-        memcpy(ea.value.data + offset, data, n);
+	// ? -1
+	if ((offset + n) > ea.value.length) {
+		if(!data_blob_realloc(talloc_tos(), &ea.value, offset + n)) {
+			TALLOC_FREE(frame);
+			errno = ENOMEM;
+			return -1;
+		}
+	}
+	memcpy(ea.value.data + offset, data, n);
 
 	ret = SMB_VFS_SETXATTR(fsp->conn,
 			       fsp->fsp_name,
 			       sio->xattr_name,
 			       ea.value.data, ea.value.length, 0);
-	TALLOC_FREE(ea.value.data);
+
+	TALLOC_FREE(frame);
 
 	if (ret == -1) {
 		return -1;
@@ -986,15 +1039,17 @@ static ssize_t streams_xattr_pread(vfs_h
 				   files_struct *fsp, void *data,
 				   size_t n, off_t offset)
 {
-        struct stream_io *sio =
+	struct stream_io *sio =
 		(struct stream_io *)VFS_FETCH_FSP_EXTENSION(handle, fsp);
+	struct smb_filename *smb_fname_base = NULL;
+	TALLOC_CTX *frame = NULL;
+
 	struct ea_struct ea;
 	NTSTATUS status;
-	size_t length, overlap;
-	struct smb_filename *smb_fname_base = NULL;
+	size_t overlap;
 
-	DEBUG(10, ("streams_xattr_pread: offset=%d, size=%d\n",
-		   (int)offset, (int)n));
+	DEBUG(10, ("streams_xattr_pread: offset=%lu, size=%lu\n",
+		   (unsigned long)offset, (unsigned long)n));
 
 	if (sio == NULL) {
 		return SMB_VFS_NEXT_PREAD(handle, fsp, data, n, offset);
@@ -1004,6 +1059,8 @@ static ssize_t streams_xattr_pread(vfs_h
 		return -1;
 	}
 
+	frame = talloc_stackframe();
+
 	/* Create an smb_filename with stream_name == NULL. */
 	smb_fname_base = synthetic_smb_fname(talloc_tos(),
 					sio->base,
@@ -1011,31 +1068,35 @@ static ssize_t streams_xattr_pread(vfs_h
 					NULL,
 					fsp->fsp_name->flags);
 	if (smb_fname_base == NULL) {
+		TALLOC_FREE(frame);
 		errno = ENOMEM;
 		return -1;
 	}
 
-	status = get_ea_value(talloc_tos(), handle->conn, NULL,
-			      smb_fname_base, sio->xattr_name, &ea);
+	status = get_xattr_value(talloc_tos(), handle->conn,
+				 smb_fname_base, sio->xattr_name, &ea);
 	if (!NT_STATUS_IS_OK(status)) {
+		TALLOC_FREE(frame);
 		return -1;
 	}
+	// ? -1
+	//length = ea.value.length-1;
 
-	length = ea.value.length-1;
+	DEBUG(10, ("streams_xattr_pread: get_xattr_value() returned %lu bytes\n",
+		   (unsigned long)ea.value.length));
 
-	DEBUG(10, ("streams_xattr_pread: get_ea_value returned %d bytes\n",
-		   (int)length));
+	/* Attempt to read past EOF. */
+	if (ea.value.length <= offset) {
+		TALLOC_FREE(frame);
+		return 0;
+	}
 
-        /* Attempt to read past EOF. */
-        if (length <= offset) {
-                return 0;
-        }
+	overlap = (offset + n) > ea.value.length ? (ea.value.length - offset) : n;
+	memcpy(data, ea.value.data + offset, overlap);
 
-        overlap = (offset + n) > length ? (length - offset) : n;
-        memcpy(data, ea.value.data + offset, overlap);
+	TALLOC_FREE(frame);
 
-	TALLOC_FREE(ea.value.data);
-        return overlap;
+	return overlap;
 }
 
 struct streams_xattr_pread_state {
@@ -1202,16 +1263,18 @@ static int streams_xattr_ftruncate(struc
 					struct files_struct *fsp,
 					off_t offset)
 {
-	int ret;
-	uint8_t *tmp;
-	struct ea_struct ea;
-	NTSTATUS status;
-        struct stream_io *sio =
+	struct stream_io *sio =
 		(struct stream_io *)VFS_FETCH_FSP_EXTENSION(handle, fsp);
 	struct smb_filename *smb_fname_base = NULL;
+	TALLOC_CTX *frame = NULL;
 
-	DEBUG(10, ("streams_xattr_ftruncate called for file %s offset %.0f\n",
-		   fsp_str_dbg(fsp), (double)offset));
+	struct ea_struct ea;
+	NTSTATUS status;
+	size_t orig_length;
+	int ret;
+
+	DEBUG(10, ("streams_xattr_ftruncate: called for file '%s' with offset %lu\n",
+		   fsp_str_dbg(fsp), (unsigned long)offset));
 
 	if (sio == NULL) {
 		return SMB_VFS_NEXT_FTRUNCATE(handle, fsp, offset);
@@ -1221,6 +1284,8 @@ static int streams_xattr_ftruncate(struc
 		return -1;
 	}
 
+	frame = talloc_stackframe();
+
 	/* Create an smb_filename with stream_name == NULL. */
 	smb_fname_base = synthetic_smb_fname(talloc_tos(),
 					sio->base,
@@ -1228,40 +1293,43 @@ static int streams_xattr_ftruncate(struc
 					NULL,
 					fsp->fsp_name->flags);
 	if (smb_fname_base == NULL) {
+		TALLOC_FREE(frame);
 		errno = ENOMEM;
 		return -1;
 	}
 
-	status = get_ea_value(talloc_tos(), handle->conn, NULL,
-			      smb_fname_base, sio->xattr_name, &ea);
+	status = get_xattr_value(talloc_tos(), handle->conn,
+				 smb_fname_base, sio->xattr_name, &ea);
 	if (!NT_STATUS_IS_OK(status)) {
+		TALLOC_FREE(frame);
 		return -1;
 	}
+	orig_length = ea.value.length;
 
-	tmp = talloc_realloc(talloc_tos(), ea.value.data, uint8_t,
-				   offset + 1);
+	/* Requested size matches the original size */
+	if(orig_length == offset) {
+		TALLOC_FREE(frame);
+		return 0;
+	}
 
-	if (tmp == NULL) {
-		TALLOC_FREE(ea.value.data);
+	/* That can both shrink and expand */
+	if(!data_blob_realloc(talloc_tos(), &ea.value, offset)) {
+		TALLOC_FREE(frame);
 		errno = ENOMEM;
 		return -1;
 	}
 
-	/* Did we expand ? */
-	if (ea.value.length < offset + 1) {
-		memset(&tmp[ea.value.length], '\0',
-			offset + 1 - ea.value.length);
+	/* If we expanded, fill up extra space with zeros */
+	if (orig_length < offset) {
+		memset(ea.value.data + orig_length, 0,
+			offset - orig_length);
 	}
 
-	ea.value.data = tmp;
-	ea.value.length = offset + 1;
-	ea.value.data[offset] = 0;
-
 	ret = SMB_VFS_SETXATTR(fsp->conn,
 			       fsp->fsp_name,
 			       sio->xattr_name,
 			       ea.value.data, ea.value.length, 0);
-	TALLOC_FREE(ea.value.data);
+	TALLOC_FREE(frame);
 
 	if (ret == -1) {
 		return -1;
@@ -1279,9 +1347,9 @@ static int streams_xattr_fallocate(struc
         struct stream_io *sio =
 		(struct stream_io *)VFS_FETCH_FSP_EXTENSION(handle, fsp);
 
-	DEBUG(10, ("streams_xattr_fallocate called for file %s offset %.0f"
-		"len = %.0f\n",
-		fsp_str_dbg(fsp), (double)offset, (double)len));
+	DEBUG(10, ("streams_xattr_fallocate: called for file '%s' with offset %lu"
+		"len = %lu\n",
+		fsp_str_dbg(fsp), (unsigned long)offset, (unsigned long)len));
 
 	if (sio == NULL) {
 		return SMB_VFS_NEXT_FALLOCATE(handle, fsp, mode, offset, len);
