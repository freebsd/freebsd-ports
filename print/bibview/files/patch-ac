--- FileNom.c.orig	Thu May  4 18:15:11 1995
+++ FileNom.c	Thu Sep 11 13:08:28 1997
@@ -822,20 +822,20 @@
     Dimension height, internalHeight, rowSpacing;
     int num, newNum, idx;
     struct dirent  **namelist;
- #ifndef HAVE_DIR
+#ifndef HAVE_DIR
     DIR *dirp;
     struct dirent *direntp;
     int direntp_size;
- #else
+#else
     extern int alphasort();
- #endif 
+#endif 
     char buf[MAXPATHLEN], *bp;
     String name;
     struct stat fstats;
     unsigned int namlen;
- #ifdef HAVE_DIR
+#ifdef HAVE_DIR
     num = scandir(CurrentDir(fnw), &namelist, (int(*)())0, alphasort);
- #else
+#else
     /* Read the directory `CurrentDir(fnw)'
        and set the `dirent's in `namelist'. */
        dirp = opendir( CurrentDir(fnw) );
@@ -860,7 +860,7 @@
 
     /* Sort the directory entries in `namelist'. */
        qsort( namelist, num, sizeof(struct dirent*), direntpcmp );
- #endif 
+#endif 
     
     if (num <= 0)
     {
