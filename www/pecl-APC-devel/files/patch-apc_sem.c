#
# Fix http://pecl.php.net/bugs/bug.php?id=5280
#
--- apc_sem.c.orig	2008-01-25 00:32:24.000000000 -0200
+++ apc_sem.c	2008-01-25 00:35:28.000000000 -0200
@@ -82,12 +82,16 @@
         }
     }
     
-    if ((semid = semget(key, 1, IPC_CREAT | IPC_EXCL | perms)) >= 0) {
+    if ((semid = semget(key, 2, IPC_CREAT | IPC_EXCL | perms)) >= 0) {
         /* sempahore created for the first time, initialize now */
         arg.val = initval;
         if (semctl(semid, 0, SETVAL, arg) < 0) {
             apc_eprint("apc_sem_create: semctl(%d,...) failed:", semid);
         }
+        arg.val = getpid();
+        if (semctl(semid, 1, SETVAL, arg) < 0) {
+            apc_eprint("apc_sem_create: semctl(%d,...) failed:", semid);
+        }
     }
     else if (errno == EEXIST) {
         /* sempahore already exists, don't initialize */
@@ -107,7 +111,10 @@
 {
     /* we expect this call to fail often, so we do not check */
     union semun arg;
-    semctl(semid, 0, IPC_RMID, arg);
+    int semPid = semctl(semid, 1, GETVAL, 0);
+    if (semPid == getpid()) {
+        semctl(semid, 0, IPC_RMID, arg);
+    }
 }
 
 void apc_sem_lock(int semid)
