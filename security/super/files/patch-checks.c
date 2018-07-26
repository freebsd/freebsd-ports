--- checks.c.orig	2018-05-21 22:43:28 UTC
+++ checks.c
@@ -567,7 +567,6 @@ int
 set_u_g()
 {
     /* Return 0 on success, -1 on failure */
-    SETGRENT_T setgrent();
     void endgrent();
     int i, j, k = -1;
     int found_gid = -1, found_egid = -1;
@@ -1425,7 +1424,6 @@ int allowbrackets;	/* accept names like <caller> */
 char *grouplabel;	/* name or numeric form */
 {
     struct group *gp;
-    SETGRENT_T setgrent();
     void endgrent();
     int numeric_gid;
     int found_gid, is_numeric=0;
@@ -1897,7 +1895,6 @@ char *gp_pat;	/* pattern to match */
     struct group *gp;
     char **mem;
     char buf[20];
-    SETGRENT_T setgrent();
     void endgrent();
 
     ENTRY item, *found_item;
