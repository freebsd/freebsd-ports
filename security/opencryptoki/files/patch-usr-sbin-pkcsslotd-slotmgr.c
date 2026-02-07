--- usr/sbin/pkcsslotd/slotmgr.c.orig	2022-04-25 11:04:51 UTC
+++ usr/sbin/pkcsslotd/slotmgr.c
@@ -137,9 +137,9 @@ void run_sanity_checks()
     }
 
     /* check that the pkcs11 group exists */
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (!grp) {
-        fprintf(stderr, "There is no 'pkcs11' group on this system.\n");
+        fprintf(stderr, "There is no '" PKCS11GROUP "' group on this system.\n");
         exit(1);
     }
 
@@ -162,6 +162,15 @@ void run_sanity_checks()
                 fprintf(stderr, "Directory %s missing\n", dircheck[i].dir);
                 exit(2);
             }
+	}
+        ec = stat(dircheck[i].dir, &sbuf);
+	if (ec != 0) {
+                fprintf(stderr, "Directory %s missing\n", dircheck[i].dir);
+                exit(2);
+	}
+	if (sbuf.st_mode != dircheck[i].mode ||
+	    sbuf.st_uid != geteuid() ||
+	    sbuf.st_gid != grp->gr_gid) {
             /* set ownership to root, and pkcs11 group */
             if (chown(dircheck[i].dir, geteuid(), grp->gr_gid) != 0) {
                 fprintf(stderr,
@@ -230,9 +239,9 @@ int chk_create_tokdir(Slot_Info_t_64 *psinfo)
 
     /* get 'PKCS11' group id */
     uid = (int) geteuid();
-    grp = getgrnam("pkcs11");
+    grp = getgrnam(PKCS11GROUP);
     if (!grp) {
-        fprintf(stderr, "PKCS11 group does not exist [errno=%d].\n", errno);
+        fprintf(stderr, PKCS11GROUP " group does not exist [errno=%d].\n", errno);
         return errno;
     } else {
         grpid = grp->gr_gid;
@@ -719,7 +728,12 @@ int main(int argc, char *argv[], char *envp[])
      */
     if (Daemon) {
         pid_t pid;
+#if !defined(__FreeBSD__)
         if ((pid = fork()) < 0) {
+#else
+	/* epoll emulation with kqueue requires sharing the fd table */
+        if ((pid = rfork(RFPROC)) < 0) {
+#endif
             term_socket_server();
             DestroyMutexes();
             DetachFromSharedMemory();
