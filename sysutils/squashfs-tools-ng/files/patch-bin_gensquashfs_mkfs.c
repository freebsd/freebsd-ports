--- bin/gensquashfs/mkfs.c.orig	2024-01-24 08:55:22 UTC
+++ bin/gensquashfs/mkfs.c
@@ -70,7 +70,8 @@ static int pack_files(sqfs_block_processor_t *data, fs
 }
 
 static int relabel_tree_dfs(const char *filename, sqfs_xattr_writer_t *xwr,
-			    tree_node_t *n, void *selinux_handle)
+			    tree_node_t *n, void *selinux_handle,
+			    void *xattrmap)
 {
 	char *path = fstree_get_path(n);
 	int ret;
@@ -86,24 +87,28 @@ static int relabel_tree_dfs(const char *filename, sqfs
 		return -1;
 	}
 
-	if (selinux_relable_node(selinux_handle, xwr, n, path)) {
-		free(path);
-		return -1;
-	}
+	if (xattrmap != NULL)
+		ret = xattr_apply_map_file(path, xattrmap, xwr);
 
-	ret = sqfs_xattr_writer_end(xwr, &n->xattr_idx);
+	if (ret == 0 && selinux_handle != NULL)
+		ret = selinux_relable_node(selinux_handle, xwr, n, path);
+
+	free(path);
+	if (ret == 0)
+		ret = sqfs_xattr_writer_end(xwr, &n->xattr_idx);
+
 	if (ret) {
 		sqfs_perror(filename, "flushing completed key-value pairs",
 			    ret);
 		return -1;
 	}
 
-	free(path);
-
 	if (S_ISDIR(n->mode)) {
 		for (n = n->data.dir.children; n != NULL; n = n->next) {
-			if (relabel_tree_dfs(filename, xwr, n, selinux_handle))
+			if (relabel_tree_dfs(filename, xwr, n,
+					     selinux_handle, xattrmap)) {
 				return -1;
+			}
 		}
 	}
 
@@ -111,15 +116,15 @@ static int relabel_tree_dfs(const char *filename, sqfs
 }
 
 static int read_fstree(fstree_t *fs, options_t *opt, sqfs_xattr_writer_t *xwr,
-		       void *selinux_handle)
+		       void *selinux_handle, void *xattrmap)
 {
 	int ret;
 
 	ret = fstree_from_file(fs, opt->infile, opt->packdir);
 
-	if (ret == 0 && selinux_handle != NULL)
+	if (ret == 0 && (selinux_handle != NULL || xattrmap != NULL))
 		ret = relabel_tree_dfs(opt->cfg.filename, xwr,
-				       fs->root, selinux_handle);
+				       fs->root, selinux_handle, xattrmap);
 
 	return ret;
 }
@@ -175,7 +180,7 @@ int main(int argc, char **argv)
 			goto out;
 		}
 	} else {
-		if (read_fstree(&sqfs.fs, &opt, sqfs.xwr, sehnd))
+		if (read_fstree(&sqfs.fs, &opt, sqfs.xwr, sehnd, xattrmap))
 			goto out;
 	}
 
