--- vfs/cpio.c.orig	Sun Dec  8 07:12:28 2002
+++ vfs/cpio.c	Tue Jun 15 03:15:09 2004
@@ -103,9 +103,9 @@
 
 static struct defer_inode * defer_find(struct defer_inode *l, struct defer_inode *i)
 {
-    if(!l) return NULL;
-    return l->inumber == i->inumber && l->device == i->device ? l : 
-	   defer_find(l->next, i);
+    while (l && (l->inumber != i->inumber || l->device != i->device))
+	l = l->next;
+    return l;
 }
 
 static int cpio_skip_padding(vfs_s_super *super)
@@ -127,8 +127,14 @@
 
 static void cpio_free_archive(vfs *me, vfs_s_super *super)
 {
+    struct defer_inode *l, *lnext;
     if(super->u.cpio.fd != -1)
-	mc_close(super->u.cpio.fd);
+	mc_close(super->u.cpio.fd), super->u.cpio.fd = -1;
+    for (l = super->u.cpio.defered; l; l = lnext) {
+	lnext = l->next;
+	g_free (l);
+    }
+    super->u.cpio.defered = NULL;
 }
 
 static int cpio_open_cpio_file(vfs *me, vfs_s_super *super, char *name)
@@ -246,26 +252,34 @@
 #define HEAD_LENGTH (26)
 static int cpio_read_bin_head(vfs *me, vfs_s_super *super)
 {
-    struct old_cpio_header buf;
+    union {
+	struct old_cpio_header buf;
+	short shorts[HEAD_LENGTH >> 1];
+    } u;
     int len;
     char *name;
     struct stat stat;
 
-    if((len = mc_read(super->u.cpio.fd, (char *)&buf, HEAD_LENGTH)) < HEAD_LENGTH)
+    if((len = mc_read(super->u.cpio.fd, (char *)&u.buf, HEAD_LENGTH)) < HEAD_LENGTH)
 	return STATUS_EOF;
     CPIO_POS(super) += len;
     if(super->u.cpio.type == CPIO_BINRE) {
 	int i;
 	for(i = 0; i < (HEAD_LENGTH >> 1); i++)
-	    ((short *)&buf)[i] = GUINT16_SWAP_LE_BE(((short *)&buf)[i]);
+	    u.shorts[i] = GUINT16_SWAP_LE_BE(u.shorts[i]);
     }
-    g_assert(buf.c_magic == 070707);
+    g_assert(u.buf.c_magic == 070707);
 
-    name = g_malloc(buf.c_namesize);
-    if((len = mc_read(super->u.cpio.fd, name, buf.c_namesize)) < buf.c_namesize){
+    if (u.buf.c_namesize == 0 || u.buf.c_namesize > MC_MAXPATHLEN) {
+	message (1, MSG_ERROR, _("Corrupted cpio header encountered in\n%s"), super->name);
+	return STATUS_FAIL;
+    }
+    name = g_malloc(u.buf.c_namesize);
+    if((len = mc_read(super->u.cpio.fd, name, u.buf.c_namesize)) < u.buf.c_namesize){
 	g_free(name);
 	return STATUS_EOF;
     }
+    name[u.buf.c_namesize - 1] = '\0';
     CPIO_POS(super) += len;
     cpio_skip_padding(super);
 
@@ -274,15 +288,15 @@
 	return STATUS_TRAIL;
     }
 
-    stat.st_dev = buf.c_dev;
-    stat.st_ino = buf.c_ino;
-    stat.st_mode = buf.c_mode;
-    stat.st_nlink = buf.c_nlink;
-    stat.st_uid = buf.c_uid;
-    stat.st_gid = buf.c_gid;
-    stat.st_rdev = buf.c_rdev;
-    stat.st_size = (buf.c_filesizes[0] << 16) | buf.c_filesizes[1];
-    stat.st_atime = stat.st_mtime = stat.st_ctime = (buf.c_mtimes[0] << 16) | buf.c_mtimes[1];
+    stat.st_dev = u.buf.c_dev;
+    stat.st_ino = u.buf.c_ino;
+    stat.st_mode = u.buf.c_mode;
+    stat.st_nlink = u.buf.c_nlink;
+    stat.st_uid = u.buf.c_uid;
+    stat.st_gid = u.buf.c_gid;
+    stat.st_rdev = u.buf.c_rdev;
+    stat.st_size = (u.buf.c_filesizes[0] << 16) | u.buf.c_filesizes[1];
+    stat.st_atime = stat.st_mtime = stat.st_ctime = (u.buf.c_mtimes[0] << 16) | u.buf.c_mtimes[1];
 
     return cpio_create_entry(me, super, &stat, name);
 }
@@ -310,11 +324,16 @@
 	return STATUS_FAIL;
     }
 
+    if (hd.c_namesize == 0 || hd.c_namesize > MC_MAXPATHLEN) {
+	message (1, MSG_ERROR, _("Corrupted cpio header encountered in\n%s"), super->name);
+	return STATUS_FAIL;
+    }
     name = g_malloc(hd.c_namesize);
     if((len = mc_read(super->u.cpio.fd, name, hd.c_namesize)) < hd.c_namesize) {
 	g_free (name);
 	return STATUS_EOF;
     }
+    name[hd.c_namesize - 1] = '\0';
     CPIO_POS(super) +=  len;
     cpio_skip_padding(super);
 
@@ -365,11 +384,16 @@
        (super->u.cpio.type == CPIO_CRC && hd.c_magic != 070702))
 	return STATUS_FAIL;
 
+    if (hd.c_namesize == 0 || hd.c_namesize > MC_MAXPATHLEN) {
+	message (1, MSG_ERROR, _("Corrupted cpio header encountered in\n%s"), super->name);
+	return STATUS_FAIL;
+    }
     name = g_malloc(hd.c_namesize);
     if((len = mc_read(super->u.cpio.fd, name, hd.c_namesize)) < hd.c_namesize){
 	g_free (name);
 	return STATUS_EOF;
     }
+    name[hd.c_namesize - 1] = '\0';
     CPIO_POS(super) += len;
     cpio_skip_padding(super);
 
@@ -430,7 +454,8 @@
 		message_3s(1, MSG_ERROR, _("Inconsistent hardlinks of\n%s\nin cpio archive\n%s"),
 			   name, super->name);
 		inode = NULL;
-	    }
+	    } else if (!inode->st.st_size)
+		inode->st.st_size = stat->st_size;
 	}
     }
 
