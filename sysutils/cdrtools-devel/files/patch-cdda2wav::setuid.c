--- cdda2wav/setuid.c.orig	Thu Nov 21 16:12:35 2002
+++ cdda2wav/setuid.c	Sat Nov 30 18:17:51 2002
@@ -92,7 +92,7 @@
 
     if (geteuid() == 0) return; /* nothing to do */
 
-#if defined _POSIX_SAVED_IDS && defined (HAVE_SETEUID)
+#if defined (HAVE_SETEUID)
     if (seteuid(effective_uid)) {
 	perror("seteuid in needroot()");
 	exit(PERM_ERROR);
@@ -126,7 +126,7 @@
 	return;
     if (geteuid() != 0) return; /* nothing to do */
 
-#if defined _POSIX_SAVED_IDS && defined (HAVE_SETEUID)
+#if defined (HAVE_SETEUID)
     if (seteuid(real_uid)) {
 	perror("seteuid in dontneedroot()");
 	exit(PERM_ERROR);
@@ -186,7 +186,7 @@
 
     if (getegid() == effective_gid) return; /* nothing to do */
 
-#if defined _POSIX_SAVED_IDS && defined (HAVE_SETEGID)
+#if defined (HAVE_SETEGID)
     if (setegid(effective_gid)) {
 	perror("setegid in needgroup()");
 	exit(PERM_ERROR);
@@ -217,7 +217,7 @@
 	exit(INTERNAL_ERROR);
     }
     if (getegid() != effective_gid) return; /* nothing to do */
-#if defined _POSIX_SAVED_IDS && defined (HAVE_SETEGID)
+#if defined (HAVE_SETEGID)
     if (setegid(real_gid)) {
 	perror("setegid in dontneedgroup()");
 	exit(PERM_ERROR);
