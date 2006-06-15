Index: src/mbox.c
===================================================================
RCS file: /pack/anoncvs/sylpheedclaws/sylpheed-claws/src/mbox.c,v
retrieving revision 1.28.2.17
diff -u -u -r1.28.2.17 mbox.c
--- mbox.c	2006/06/12 06:30:30	1.28.2.17
+++ mbox.c	2006/06/15 14:57:57
@@ -278,6 +278,7 @@
 		g_free(lockfile);
 	} else if (type == LOCK_FLOCK) {
 		gint lockfd;
+		gboolean fcntled = FALSE;
 #if HAVE_FCNTL_H
 		struct flock fl;
 		fl.l_type = F_WRLCK;
@@ -299,15 +300,17 @@
 		if (fcntl(lockfd, F_SETLK, &fl) == -1) {
 			g_warning("can't fnctl %s (%s)", base, strerror(errno));
 			return -1;
+		} else {
+			fcntled = TRUE;
 		}
 #endif
 
 #if HAVE_FLOCK
-		if (flock(lockfd, LOCK_EX|LOCK_NB) < 0) {
+		if (flock(lockfd, LOCK_EX|LOCK_NB) < 0 && !fcntled) {
 			perror("flock");
 #else
 #if HAVE_LOCKF
-		if (lockf(lockfd, F_TLOCK, 0) < 0) {
+		if (lockf(lockfd, F_TLOCK, 0) < 0 && !fcntled) {
 			perror("lockf");
 #else
 		{
@@ -345,6 +348,7 @@
 
 		return 0;
 	} else if (type == LOCK_FLOCK) {
+		gboolean fcntled = FALSE;
 #if HAVE_FCNTL_H
 		struct flock fl;
 		fl.l_type = F_UNLCK;
@@ -355,14 +359,16 @@
 		if (fcntl(fd, F_SETLK, &fl) == -1) {
 			g_warning("can't fnctl %s", base);
 			return -1;
+		} else {
+			fcntled = TRUE;
 		}
 #endif
 #if HAVE_FLOCK
-		if (flock(fd, LOCK_UN) < 0) {
+		if (flock(fd, LOCK_UN) < 0 && !fcntled) {
 			perror("flock");
 #else
 #if HAVE_LOCKF
-		if (lockf(fd, F_ULOCK, 0) < 0) {
+		if (lockf(fd, F_ULOCK, 0) < 0 && !fcntled) {
 			perror("lockf");
 #else
 		{
