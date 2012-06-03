--- ./libpkg/packing.c.orig	2012-06-03 16:28:53.000000000 +0200
+++ ./libpkg/packing.c	2012-06-03 20:55:42.669538609 +0200
@@ -133,8 +133,8 @@
 	struct stat st;
 	struct archive_entry *entry, *sparse_entry;
 	/* ugly hack for python and emacs */
-	char *p;
-	bool unset_timestamp = true;
+	/*char *p;
+	bool unset_timestamp = true;*/
 
 	entry = archive_entry_new();
 	archive_entry_copy_sourcepath(entry, filepath);
@@ -171,7 +171,7 @@
 		archive_entry_set_perm(entry, perm);
 
 	/* XXX ugly hack for python and emacs */
-	p = strrchr(filepath, '.');
+	/*p = strrchr(filepath, '.');
 
 	if (p != NULL && (strcmp(p, ".pyc") == 0 ||
 	    strcmp(p, ".py") == 0 ||
@@ -186,7 +186,7 @@
 		archive_entry_unset_ctime(entry);
 		archive_entry_unset_mtime(entry);
 		archive_entry_unset_birthtime(entry);
-	}
+	}*/
 
 	archive_entry_linkify(pack->resolver, &entry, &sparse_entry);
 
