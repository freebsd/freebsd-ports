--- vfs/names.c.orig	Fri Nov 15 12:19:34 2002
+++ vfs/names.c	Tue Jun 15 03:15:09 2004
@@ -31,6 +31,7 @@
 #include <stdio.h>
 #include <pwd.h>
 #include <grp.h>
+#include <glib.h>
 
 #include "names.h"
 
@@ -59,7 +60,7 @@
 
     if (uname[0] != saveuname[0]	/* Quick test w/o proc call */
 	||0 != strncmp (uname, saveuname, TUNMLEN)) {
-	strncpy (saveuname, uname, TUNMLEN);
+	g_strlcpy (saveuname, uname, TUNMLEN);
 	pw = getpwnam (uname);
 	if (pw) {
 	    saveuid = pw->pw_uid;
@@ -77,7 +78,7 @@
 
     if (gname[0] != savegname[0]	/* Quick test w/o proc call */
 	||0 != strncmp (gname, savegname, TUNMLEN)) {
-	strncpy (savegname, gname, TUNMLEN);
+	g_strlcpy (savegname, gname, TUNMLEN);
 	gr = getgrnam (gname);
 	if (gr) {
 	    savegid = gr->gr_gid;
