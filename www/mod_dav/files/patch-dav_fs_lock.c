--- dav_fs_lock.c.orig	Sat Dec  2 00:32:23 2000
+++ dav_fs_lock.c	Wed Sep 15 21:50:09 2004
@@ -77,7 +77,7 @@
 **    INDIRECT LOCK:   [char  (DAV_LOCK_INDIRECT),
 **			uuid_t locktoken,
 **			time_t expires,
-**			int    key_size,
+**			size_t   key_size,
 **			char[] key]
 **       The key is to the collection lock that resulted in this indirect lock
 */
@@ -166,7 +166,7 @@
 /* Stored indirect lock info - lock token and dav_datum */
 #define dav_size_indirect(a)	(1 + sizeof(uuid_t) \
 				 + sizeof(time_t) \
-				 + sizeof(int) + (a)->key.dsize)
+				 + sizeof((a)->key.dsize) + (a)->key.dsize)
 
 /*
 ** The lockdb structure.
@@ -1456,13 +1456,13 @@
 	}
 	if (dav_fs_do_refresh(dp_scan, ltl, new_time)) {
 	    /* the lock was refreshed. return the lock. */
-	    newlock = dav_fs_alloc_lock(lockdb, ip->key, dp->locktoken);
+	    newlock = dav_fs_alloc_lock(lockdb, ip->key, dp_scan->locktoken);
 	    newlock->is_locknull = !resource->exists;
-	    newlock->scope = dp->f.scope;
-	    newlock->type = dp->f.type;
-	    newlock->depth = dp->f.depth;
-	    newlock->timeout = dp->f.timeout;
-	    newlock->owner = dp->owner;
+	    newlock->scope = dp_scan->f.scope;
+	    newlock->type = dp_scan->f.type;
+	    newlock->depth = dp_scan->f.depth;
+	    newlock->timeout = dp_scan->f.timeout;
+	    newlock->owner = dp_scan->owner;
             newlock->auth_user = dp_scan->auth_user;
 
 	    newlock->next = *locks;
