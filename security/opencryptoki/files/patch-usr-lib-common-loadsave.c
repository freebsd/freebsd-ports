--- usr/lib/common/loadsave.c.orig	2018-11-16 14:53:03 UTC
+++ usr/lib/common/loadsave.c
@@ -20,11 +20,9 @@
 #include <string.h>
 #include <strings.h>
 #include <unistd.h>
-#include <alloca.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ipc.h>
-#include <sys/file.h>
 #include <errno.h>
 #include <syslog.h>
 #include <pwd.h>
@@ -370,7 +368,7 @@ void set_perm(int file)
         // Set absolute permissions or rw-rw----
         fchmod(file, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
 
-        grp = getgrnam("pkcs11");       // Obtain the group id
+        grp = getgrnam(PKCS11GROUP);       // Obtain the group id
         if (grp) {
             // set ownership to root, and pkcs11 group
             if (fchown(file, getuid(), grp->gr_gid) != 0) {
