===================================================================
RCS file: /home/cvspublic/httpd-2.0/modules/dav/fs/lock.c,v
retrieving revision 1.25.2.5
retrieving revision 1.25.2.6
diff -u -r1.25.2.5 -r1.25.2.6
--- modules/dav/fs/lock.c	2004/04/26 15:45:52	1.25.2.5
+++ modules/dav/fs/lock.c	2004/09/15 08:26:48	1.25.2.6
@@ -66,7 +66,7 @@
 **    INDIRECT LOCK:   [char      (DAV_LOCK_INDIRECT),
 **			apr_uuid_t locktoken,
 **			time_t     expires,
-**			int        key_size,
+**			apr_size_t key_size,
 **			char[]     key]
 **       The key is to the collection lock that resulted in this indirect lock
 */
@@ -157,7 +157,7 @@
 /* Stored indirect lock info - lock token and apr_datum_t */
 #define dav_size_indirect(a)	(1 + sizeof(apr_uuid_t) \
 				 + sizeof(time_t) \
-				 + sizeof(int) + (a)->key.dsize)
+				 + sizeof((a)->key.dsize) + (a)->key.dsize)
 
 /*
 ** The lockdb structure.
@@ -1469,13 +1469,13 @@
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

