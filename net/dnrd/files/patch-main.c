--- main.c.orig	Thu Jan  4 14:40:42 2001
+++ main.c	Sat Jan  6 15:06:31 2001
@@ -18,6 +18,7 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
  */
 
+#include <sys/types.h>
 #include "relay.h"
 #include "cache.h"
 #include "common.h"
@@ -26,7 +27,6 @@
 #include "master.h"
 #include <stdio.h>
 #include <stdlib.h>
-#include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
@@ -170,20 +170,20 @@
      * Change our root and current working directories to /etc/dnrd.
      * Also, so some sanity checking on that directory first.
      */
-    dirp = opendir("/etc/dnrd");
+    dirp = opendir("%%PREFIX%%/etc/dnrd");
     if (!dirp) {
-	log_msg(LOG_ERR, "The directory /etc/dnrd must be created before "
+	log_msg(LOG_ERR, "The directory %%PREFIX%%/etc/dnrd must be created before "
 		"dnrd will run");
     }
 
-    rslt = stat("/etc/dnrd", &st);
+    rslt = stat("%%PREFIX%%/etc/dnrd", &st);
     if (st.st_uid != 0) {
-	log_msg(LOG_ERR, "The /etc/dnrd directory must be owned by root");
+	log_msg(LOG_ERR, "The %%PREFIX%%/dnrd directory must be owned by root");
 	cleanexit(-1);
     }
     if ((st.st_mode & (S_IWGRP | S_IWOTH)) != 0) {
 	log_msg(LOG_ERR,
-		"The /etc/dnrd directory should only be user writable");
+		"The %%PREFIX%%/etc/dnrd directory should only be user writable");
 	cleanexit(-1);
     }
 
@@ -198,31 +198,31 @@
 
 	if (rslt) continue;
 	if (S_ISDIR(st.st_mode)) {
-	    log_msg(LOG_ERR, "The /etc/dnrd directory must not contain "
+	    log_msg(LOG_ERR, "The %%PREFIX%%/etc/dnrd directory must not contain "
 		    "subdirectories");
 	    cleanexit(-1);
 	}
 	if ((st.st_mode & (S_IXUSR|S_IXGRP|S_IXOTH|S_IWGRP|S_IWOTH)) != 0) {
-	    log_msg(LOG_ERR, "A file in /etc/dnrd has either execute "
+	    log_msg(LOG_ERR, "A file in %%PREFIX%%/etc/dnrd has either execute "
 		    "permissions or non-user write permission.  Please do a "
 		    "\"chmod a-x,go-w\" on all files in this directory");
 	    cleanexit(-1);
 	}
 	if (st.st_uid != 0) {
-	    log_msg(LOG_ERR, "All files in /etc/dnrd must be owned by root");
+	    log_msg(LOG_ERR, "All files in %%PREFIX%%/etc/dnrd must be owned by root");
 	    cleanexit(-1);
 	}
     }
     closedir(dirp);
 
-    if (chdir("/etc/dnrd")) {
+    if (chdir("%%PREFIX%%/etc/dnrd")) {
 	log_msg(LOG_ERR, "couldn't chdir to %s, %s",
-		"/etc/dnrd", strerror(errno));
+		"%%PREFIX%%/etc/dnrd", strerror(errno));
 	cleanexit(-1);
     }
-    if (chroot("/etc/dnrd")) {
+    if (chroot("%%PREFIX%%/etc/dnrd")) {
 	log_msg(LOG_ERR, "couldn't chroot to %s, %s",
-		"/etc/dnrd", strerror(errno));
+		"%%PREFIX%%/etc/dnrd", strerror(errno));
 	cleanexit(-1);
     }
 
