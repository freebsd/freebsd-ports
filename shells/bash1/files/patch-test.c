--- test.c.orig	Fri Dec 23 06:45:12 1994
+++ test.c	Sat May  4 21:08:08 2002
@@ -194,6 +194,7 @@
   return (stat (path, finfo));
 }
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 500023	/* use native FreeBSD libc version */
 /* Do the same thing access(2) does, but use the effective uid and gid,
    and don't make the mistake of telling root that any file is
    executable. */
@@ -237,6 +238,7 @@
 
   return (-1);
 }
+#endif
 
 #if defined (HAVE_GETGROUPS)
 /* The number of groups that this user is a member of. */
