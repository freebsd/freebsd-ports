--- dav_fs_repos.c.orig	Mon Nov  5 16:20:32 2001
+++ dav_fs_repos.c	Tue Nov 11 14:14:11 2003
@@ -154,6 +154,30 @@
 **
 ** PRIVATE REPOSITORY FUNCTIONS
 */
+
+static int symlink_aware_rmdir(const char *pathname)
+{
+
+    struct stat finfo;
+
+    /* Is this a symbolic link? */
+    /* If not, just call rmdir() and return. */
+
+    if (lstat(pathname, &finfo) != 0) {
+        return -1; /* and errno set by lstat() */
+    }
+
+    if (!S_ISLNK(finfo.st_mode)) {
+        return rmdir(pathname); /* and errno set by rmdir() */
+    }
+
+    /* It's a symlink. */
+    /* Remove the link itself, leaving the link's target untouched. */
+    return unlink(pathname); /* and errno set by unlink() */
+
+}
+
+
 pool *dav_fs_pool(const dav_resource *resource)
 {
     return resource->info->pool;
@@ -258,13 +282,25 @@
     /* chmod() the destination if the source is executable, and the
      * destination already exists. */
     if ((mode & DAV_FS_MODE_XUSR) && (dst_finfo != NULL) && 
-	(dst_finfo->st_mode != 0)) {
+	(dst_finfo->st_mode != 0) && !S_ISLNK(dst_finfo->st_mode)) {
 	if (chmod(dst, mode) == -1) {
 	    return dav_new_error(p, HTTP_INTERNAL_SERVER_ERROR, 0,
 				 "Could not set permissions on destination");
 	}
     }
 
+    /* If the destination is a symlink, break it so that we don't overwrite
+     * its target. */
+    if ((dst_finfo != NULL) && S_ISLNK(dst_finfo->st_mode)) {
+        if (unlink(dst) != 0) {
+           return dav_new_error(p, HTTP_INTERNAL_SERVER_ERROR, 0,
+                                "Could not break destination symlink");
+        }
+    }
+
+
+      dav_set_bufsize(p, pbuf, DAV_FS_COPY_BLOCKSIZE);
+
     dav_set_bufsize(p, pbuf, DAV_FS_COPY_BLOCKSIZE);
 
     if ((fdi = open(src, O_RDONLY | O_BINARY)) == -1) {
@@ -565,8 +601,6 @@
     ctx->pool = r->pool;
     ctx->finfo = r->finfo;
 
-    (void) ap_update_mtime(r, r->finfo.st_mtime);
-
     /* Preserve case on OSes which fold canonical filenames */
 #if MODULE_MAGIC_NUMBER_MAJOR > 19990320 || (MODULE_MAGIC_NUMBER_MAJOR == 19990320 && MODULE_MAGIC_NUMBER_MINOR >= 8)
     filename = r->case_preserved_filename;
@@ -606,9 +640,18 @@
 	resource->uri = r->uri;
     }
 
-    if (r->finfo.st_mode != 0) {
+    if (r->finfo.st_mode == 0) {
+        /* Apache says it does not exists.  Is it maybe a dangling symlink? */
+        if (lstat(ctx->pathname, &(ctx->finfo)) != 0) {
+            ctx->finfo.st_mode = 0; /* does not exist */
+        }
+    }
+
+    (void) ap_update_mtime(r, ctx->finfo.st_mtime);
+
+    if (ctx->finfo.st_mode != 0) {
         resource->exists = 1;
-        resource->collection = S_ISDIR(r->finfo.st_mode);
+        resource->collection = S_ISDIR(ctx->finfo.st_mode);
 
 	/* unused info in the URL will indicate a null resource */
 
@@ -979,7 +1022,7 @@
 	     * Note: when copying, we do not enable the postfix-traversal.
 	     */
 	    /* ### we are ignoring any error here; what should we do? */
-	    (void) rmdir(srcinfo->pathname);
+	    (void) symlink_aware_rmdir(srcinfo->pathname);
 	}
         else {
 	    /* copy/move of a collection. Create the new, target collection */
@@ -1157,6 +1200,15 @@
 	}
     }
 
+    /* Renaming a symlink will only work in some circumstances (e.g., if
+     * old and new names are in the same directory).  Be safe and break
+     * the link.
+     */
+    if (S_ISLNK(srcinfo->finfo.st_mode)) {
+        can_rename = 0;
+    }
+
+
     /* if we can't simply renamed, then do it the hard way... */
     if (!can_rename) {
         if ((err = dav_fs_copymove_resource(1, src, dst, DAV_INFINITY, response)) == NULL) {
@@ -1226,8 +1278,31 @@
 
 static dav_error * dav_fs_delete_walker(dav_walker_ctx *ctx, int calltype)
 {
+    struct stat finfo;
     dav_resource_private *info = ctx->resource->info;
 
+    /* If this is a symlink to a directory, immediately remove the link
+     * during any "prefix traversal", then signal our caller, dav_fs_walker(),
+     * that we're done and not to follow the link to the target's children.
+     */
+    if (ctx->resource->exists && ctx->resource->collection) {
+        if (lstat(info->pathname, &finfo) != 0) {
+                dav_add_response(ctx, ctx->resource->uri, HTTP_FORBIDDEN, NULL);
+                return NULL; /* failure */
+        }
+        if (S_ISLNK(finfo.st_mode)) {
+           if (unlink(info->pathname) != 0) {
+                /* ### assume there is a permissions problem */
+                /* ### use errno to generate DAV:responsedescription? */
+                dav_add_response(ctx, ctx->resource->uri, HTTP_FORBIDDEN, NULL);
+                return NULL; /* failure */
+            }
+            ctx->is_dir = 0; /* signal dav_fs_walker() that we're done */
+            return NULL; /* success */
+        }
+    }
+
+
     /* do not attempt to remove a null resource,
      * or a collection with children
      */
@@ -1237,7 +1312,7 @@
 	int result;
 
 	result = ctx->resource->collection
-	    ? rmdir(info->pathname)
+	    ? symlink_aware_rmdir(info->pathname)
 	    : remove(info->pathname);
 
 	/*
@@ -1320,20 +1395,25 @@
 {
     dav_error *err = NULL;
     dav_walker_ctx *wctx = fsctx->wctx;
-    int isdir = wctx->resource->collection;
     DIR *dirp;
     struct dirent *ep;
 
-    /* ensure the context is prepared properly, then call the func */
+    /* ensure the context is prepared properly, then call the func.
+     * Note that if the resource is a symbolic link to a directory,
+     * and we should not recurse (for example, because we're deleting)
+     * func() will change wctx->is_dir to 0 to signal this.
+     */
+    wctx->is_dir = wctx->resource->collection;
     err = (*wctx->func)(wctx,
-			isdir
+			wctx->is_dir
 			? DAV_CALLTYPE_COLLECTION
 			: DAV_CALLTYPE_MEMBER);
     if (err != NULL) {
 	return err;
     }
 
-    if (!isdir) {
+    /* At this point, wctx->is_dir actually means "should we recurse?" */
+    if (!wctx->is_dir) {
 	return NULL;
     }
 
@@ -1397,11 +1477,15 @@
 	dav_buffer_place_mem(wctx->pool,
 			     &fsctx->path1, ep->d_name, len + 1, 0);
 
-	if (lstat(fsctx->path1.buf, &fsctx->info1.finfo) != 0) {
-	    /* woah! where'd it go? */
-	    /* ### should have a better error here */
-	    err = dav_new_error(wctx->pool, HTTP_NOT_FOUND, 0, NULL);
-	    break;
+        /* stat() not lstat() because we want to follow symlinks */
+        /* BUT, ignore dangling symlinks (symlinks whose targets don't exist) */
+	if (stat(fsctx->path1.buf, &fsctx->info1.finfo) != 0) {
+	    if (lstat(fsctx->path1.buf, &fsctx->info1.finfo) != 0) {
+	        /* woah! where'd it go? */
+	        /* ### should have a better error here */
+	        err = dav_new_error(wctx->pool, HTTP_NOT_FOUND, 0, NULL);
+	        break;
+            }
 	}
 
 	/* copy the file to the URI, too. NOTE: we will pad an extra byte
@@ -1421,8 +1505,8 @@
 	/* set up the URI for the current resource */
 	fsctx->res1.uri = wctx->uri.buf;
 
-	/* ### for now, only process regular files (e.g. skip symlinks) */
-	if (S_ISREG(fsctx->info1.finfo.st_mode)) {
+	if (S_ISREG(fsctx->info1.finfo.st_mode) ||
+            S_ISLNK(fsctx->info1.finfo.st_mode)) {
 	    /* call the function for the specified dir + file */
 	    if ((err = (*wctx->func)(wctx, DAV_CALLTYPE_MEMBER)) != NULL) {
 		/* ### maybe add a higher-level description? */
