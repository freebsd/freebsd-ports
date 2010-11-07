--- usr/lib/pkcs11/common/loadsave.c.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/lib/pkcs11/common/loadsave.c	2010-10-20 00:11:28.399983780 +0900
@@ -301,11 +301,9 @@
 #include <string.h>
 #include <strings.h>
 #include <unistd.h>
-#include <alloca.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ipc.h>
-#include <sys/file.h>
 #include <errno.h>
 
 #include <pwd.h>
@@ -328,7 +326,7 @@
    // Set absolute permissions or rw-rw-r--
    fchmod(file,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
 
-   grp = getgrnam("pkcs11"); // Obtain the group id
+   grp = getgrnam(PKCS11GROUP); // Obtain the group id
    if (grp){
 	   fchown(file,getuid(),grp->gr_gid);  // set ownership to root, and pkcs11 group
    }
