--- src/find.c.orig	Tue Dec 24 17:28:26 2002
+++ src/find.c	Tue Jun 15 03:15:09 2004
@@ -312,7 +312,7 @@
     dir_stack *new;
 
     new = g_new (dir_stack, 1);
-    new->name = g_strdup (dir);
+    new->name = concat_dir_and_file (dir, "");
     new->prev = dir_stack_base;
     dir_stack_base = new;
 }
@@ -338,17 +338,9 @@
 {
     char *tmp_name;
     static char *dirname;
-    int i;
 
-    if (dir [0] == PATH_SEP && dir [1] == PATH_SEP)
+    while (dir [0] == PATH_SEP && dir [1] == PATH_SEP)
 	dir++;
-    i = strlen (dir);
-    if (i){
-	if (dir [i - 1] != PATH_SEP){
-	    dir [i] = PATH_SEP;
-	    dir [i + 1] = 0;
-	}
-    }
 
     if (old_dir){
 	if (strcmp (old_dir, dir)){
@@ -401,7 +393,7 @@
     char ch = 0;
     int  i = 0;
 
-    do {
+    for (;;) {
 	if (*pos >= *n_read){
 	    *pos = 0;
 	    if ((*n_read = mc_read (file_fd, buf, buf_size)) <= 0)
@@ -420,10 +412,12 @@
 	if (i >= buffer_size - 1){
 	    buffer = g_realloc (buffer, buffer_size += 80);
 	}
+	/* Strip newline to fix $ matching */
+	if (ch == '\n')
+	    break;
 
 	buffer [i++] = ch;
-
-    } while (ch != '\n');
+    }
 
     *has_newline = ch ? 1 : 0;
 
@@ -502,7 +496,7 @@
 {
     static struct dirent *dp   = 0;
     static DIR  *dirp = 0;
-    static char directory [MC_MAXPATHLEN+2];
+    static char *directory;
     struct stat tmp_stat;
     static int pos;
     static int subdirs_left = 0;
@@ -513,6 +507,10 @@
 	    mc_closedir (dirp);
 	    dirp = 0;
 	}
+	if (directory) {
+	    g_free (directory);
+	    directory = NULL;
+	}
         dp = 0;
 	return 1;
     }
@@ -550,8 +548,9 @@
 		    break;
 	    } 
 	    
-	    strcpy (directory, tmp);
-	    g_free (tmp);
+	    if (directory)
+		g_free (directory);
+	    directory = tmp;
 
 	    if (verbose){
 		    char buffer [BUF_SMALL];
@@ -582,8 +581,8 @@
     tmp_name = concat_dir_and_file (directory, dp->d_name);
 
     if (subdirs_left){
-	mc_lstat (tmp_name, &tmp_stat);
-	if (S_ISDIR (tmp_stat.st_mode)){
+	if (!mc_lstat (tmp_name, &tmp_stat)
+	    && S_ISDIR (tmp_stat.st_mode)){
 	    push_directory (tmp_name);
 	    subdirs_left--;
 	}
