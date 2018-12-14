--- fcgi_util.c.orig	2017-03-29 21:11:44 UTC
+++ fcgi_util.c
@@ -268,13 +268,17 @@ fcgi_util_check_access(pool *tp, 
     /* Get the user membership for the file's group.  If the
      * uid is a member, check the group bits. */
     {
-        const struct group * const gr = getgrgid(statBuf->st_gid);
-        const struct passwd * const pw = getpwuid(uid);
+	char buf[1024], buf2[1024];
+	struct group gr, *r;
+	struct passwd pw, *r2;
 
-        if (gr != NULL && pw != NULL) {
-            char **user = gr->gr_mem;
+	getgrgid_r(statBuf->st_gid, &gr, buf, sizeof(buf), &r);
+	getpwuid_r(uid, &pw, buf2, sizeof(buf2), &r2);
+
+        if (r != NULL && r2 != NULL) {
+            char **user = r->gr_mem;
             for ( ; *user != NULL; user++) {
-                if (strcmp(*user, pw->pw_name) == 0) {
+                if (strcmp(*user, r2->pw_name) == 0) {
                     if (mode & R_OK && !(statBuf->st_mode & S_IRGRP))
                         return "read not allowed by group";
                     if (mode & W_OK && !(statBuf->st_mode & S_IWGRP))
@@ -445,8 +449,9 @@ fcgi_util_fs_set_uid_n_gid(pool *p, fcgi_server *s, ui
 {
 #ifndef WIN32
 
+    char buf[1024];
     struct passwd *pw;
-    struct group  *gr;
+    struct group gr, *r;
 
     if (fcgi_wrapper == NULL)
         return NULL;
@@ -467,14 +472,14 @@ fcgi_util_fs_set_uid_n_gid(pool *p, fcgi_server *s, ui
     s->username = s->user;
 
     s->gid = gid;
-    gr = getgrgid(gid);
-    if (gr == NULL) {
+    getgrgid_r(gid, &gr, buf, sizeof(buf), &r);
+    if (r == NULL) {
         return ap_psprintf(p,
             "getgrgid() couldn't determine the group name for gid '%ld', "
             "you probably need to modify the Group directive: %s",
             (long)gid, strerror(errno));
     }
-    s->group = ap_pstrdup(p, gr->gr_name);
+    s->group = ap_pstrdup(p, r->gr_name);
 
 #endif /* !WIN32 */
 
