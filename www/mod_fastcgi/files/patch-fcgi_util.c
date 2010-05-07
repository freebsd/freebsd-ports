--- fcgi_util.c.orig	2009-07-08 17:16:29.816884000 +0800
+++ fcgi_util.c	2009-07-09 08:43:09.222180000 +0800
@@ -268,13 +268,17 @@
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
@@ -445,8 +449,9 @@
 {
 #ifndef WIN32
 
+    char buf[1024];
     struct passwd *pw;
-    struct group  *gr;
+    struct group gr, *r;
 
     if (fcgi_wrapper == NULL)
         return NULL;
@@ -467,14 +472,14 @@
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
 
