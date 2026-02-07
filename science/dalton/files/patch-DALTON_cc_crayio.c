--- DALTON/cc/crayio.c.orig	2018-09-02 02:03:25 UTC
+++ DALTON/cc/crayio.c
@@ -84,10 +84,10 @@ typedef int INTEGER;
    This problem has been reported for many other programs, for eg. OS
    X and HP/UX. Web searching engines are your friends.
 */
-#if defined (HAVE_NO_LSEEK64)
+//#if defined (HAVE_NO_LSEEK64)
 #define lseek64 lseek
 #define off64_t off_t
-#endif
+//#endif
 
 /* Disable old cruft. */
 #if defined(OLD_CRUFT)
