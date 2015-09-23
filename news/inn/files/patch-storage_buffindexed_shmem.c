The problem seems to be that unsupported permission bits are being given to semget(2) as in the following snippet (there are several such instances):

storage/buffindexed/shmem.c:

    id = semget(kt, 2, IPC_CREAT|S_IRWXU|S_IRWXG|S_IRWXO);

The semget(2) man page does not indicate that the usual file mode bits may be used. Instead, it allows:

     SEM_R         Read access for user.

     SEM_A         Alter access for user.

     (SEM_R>>3)    Read access for group.

     (SEM_A>>3)    Alter access for group.

     (SEM_R>>6)    Read access for other.

     (SEM_A>>6)    Alter access for other.

The allowed bits correspond to read and write bits of the file mode constants. The execute bit is not among the defined bits for semget.

The fix: do not set any permission bits except for the six allowed  bits.

Note that the documentation for linux semget differs, and seems to allow but ignore the execute bits.

Patch attached with submission follows:

--- storage/buffindexed/shmem.c.orig	2015-09-12 15:25:22.000000000 +0200
+++ storage/buffindexed/shmem.c	2015-09-21 21:15:18.448425000 +0200
@@ -26,7 +26,9 @@
 static int smcGetSemaphore(const char *name)
 {
     key_t kt = ftok( (char *)name, 0 );
-    int   id = semget(kt, 0, S_IRWXU|S_IRWXG|S_IRWXO);
+    int   perm = SEM_R | SEM_A | (SEM_R>>3) | (SEM_A>>3) |
+	    (SEM_R>>6) | (SEM_A>>6);
+    int   id = semget(kt, 0, perm);
 
     if (id < 0) {
         syswarn("semget failed to get semaphore for %s", name);
@@ -37,15 +39,17 @@ static int smcGetSemaphore(const char *n
 static int smcCreateSemaphore(const char *name)
 {
     key_t kt = ftok( (char *)name, 0 );
-    int   id = semget(kt, 2, IPC_CREAT|S_IRWXU|S_IRWXG|S_IRWXO);
+    int   perm = SEM_R | SEM_A | (SEM_R>>3) | (SEM_A>>3) |
+	    (SEM_R>>6) | (SEM_A>>6);
+    int   id = semget(kt, 2, IPC_CREAT|perm);
 
     if (id < 0) {
         if (errno == EACCES || errno == EINVAL) {
             /* looks like a wrong semaphore exists. remove it. */
-            id = semget(kt, 0, S_IRWXU|S_IRWXG|S_IRWXO);
+            id = semget(kt, 0, perm);
             if (id < 0) {
                 /* couldn't even retrieve it. */
-                syswarn("cant get semaphore using %s", name);
+                syswarn("cant get semaphore using %s (key=%d)", name, kt);
                 return id;
             }
             /* try to remove it */
@@ -65,7 +69,7 @@ static int smcCreateSemaphore(const char
             }
 #endif
             /* and retry creating it */
-            id = semget(kt, 2, IPC_CREAT|S_IRWXU|S_IRWXG|S_IRWXO);
+            id = semget(kt, 2, IPC_CREAT|perm);
         }
     }
     if (id < 0)
