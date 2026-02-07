--- src/mma_util/cgetshmem.c.orig	2023-06-12 11:58:03 UTC
+++ src/mma_util/cgetshmem.c
@@ -137,6 +137,8 @@ INT add_shmentry(mstat *MM, mentry *tmp, char *path, I
   shmid = shmget(SHM_key, (size_t)tmp->len, 0644 | IPC_CREAT | IPC_EXCL);
 #   elif _AIX_
   shmid = shmget(SHM_key, (size_t)tmp->len, 0644 | IPC_CREAT | IPC_EXCL | SHM_PIN);
+#elif __FreeBSD__
+  shmid = shmget(SHM_key, (size_t) tmp->len, 0644 | IPC_CREAT | IPC_EXCL);
 #   else
   shmid = shmget(SHM_key, (size_t)tmp->len, 0644 | IPC_CREAT | IPC_EXCL | SHM_LOCKED);
   /* shmid = shmget(SHM_key, (size_t)tmp->len, 0644 | IPC_CREAT | IPC_EXCL | SHM_LOCKED | SHM_NORESERVE);*/
