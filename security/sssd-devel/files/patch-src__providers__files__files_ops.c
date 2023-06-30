--- src/providers/files/files_ops.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/files/files_ops.c
@@ -53,8 +53,11 @@ static errno_t enum_files_users(TALLOC_CTX *mem_ctx,
     struct passwd *pwd_iter = NULL;
     struct passwd *pwd = NULL;
     struct passwd **users = NULL;
+    struct passwd *pbuf = NULL;
     FILE *pwd_handle = NULL;
     size_t n_users = 0;
+    char *buf = NULL;
+    unsigned int bufsize = 1024;
 
     pwd_handle = fopen(passwd_file, "r");
     if (pwd_handle == NULL) {
@@ -72,7 +75,19 @@ static errno_t enum_files_users(TALLOC_CTX *mem_ctx,
         goto done;
     }
 
-    while ((pwd_iter = fgetpwent(pwd_handle)) != NULL) {
+    buf = talloc_zero_array(mem_ctx, char, bufsize);
+    if (buf == NULL) {
+        ret = ENOMEM;
+        goto done;
+    }
+
+    pbuf = talloc_zero(mem_ctx, struct passwd);
+    if (pbuf == NULL) {
+        ret = ENOMEM;
+        goto done;
+    }
+
+    while (getpwent_r(pbuf, buf, (size_t)bufsize, &pwd_iter) == 0 && pwd_iter != NULL) {
         /* FIXME - we might want to support paging of sorts to avoid allocating
          * all users atop a memory context or only return users that differ from
          * the local storage as a diff to minimize memory spikes
@@ -126,6 +141,9 @@ done:
     users[n_users] = NULL;
     *_users = users;
 done:
+    talloc_free(pbuf);
+    talloc_free(buf);
+
     if (ret != EOK) {
         talloc_free(users);
     }
@@ -150,8 +168,11 @@ static errno_t enum_files_groups(TALLOC_CTX *mem_ctx,
     struct group *grp_iter = NULL;
     struct group *grp = NULL;
     struct group **groups = NULL;
+    struct group *pbuf = NULL;
     size_t n_groups = 0;
     FILE *grp_handle = NULL;
+    char *buf = NULL;
+    unsigned int bufsize = 1024;
 
     grp_handle = fopen(group_file, "r");
     if (grp_handle == NULL) {
@@ -169,7 +190,19 @@ static errno_t enum_files_groups(TALLOC_CTX *mem_ctx,
         goto done;
     }
 
-    while ((grp_iter = fgetgrent(grp_handle)) != NULL) {
+    buf = talloc_zero_array(mem_ctx, char, bufsize);
+    if (buf == NULL) {
+        ret = ENOMEM;
+        goto done;
+    }
+
+    pbuf = talloc_zero(mem_ctx, struct group);
+    if (pbuf == NULL) {
+        ret = ENOMEM;
+        goto done;
+    }
+
+    while (getgrent_r(pbuf, buf, (size_t)bufsize, &grp_iter) == 0 && grp_iter != NULL) {
         DEBUG(SSSDBG_TRACE_LIBS,
               "Group found (%s, %"SPRIgid")\n",
               grp_iter->gr_name, grp_iter->gr_gid);
@@ -230,6 +263,9 @@ done:
     groups[n_groups] = NULL;
     *_groups = groups;
 done:
+    talloc_free(pbuf);
+    talloc_free(buf);
+
     if (ret != EOK) {
         talloc_free(groups);
     }
