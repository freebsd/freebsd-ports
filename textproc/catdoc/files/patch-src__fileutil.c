diff --git src/fileutil.c src/fileutil.c
index d902a6a..6afddec 100644
--- src/fileutil.c
+++ src/fileutil.c
@@ -71,13 +71,12 @@ char *find_file(char *name, const char *path)
 	char *q;
 	char path_buf[PATH_BUF_SIZE];
 	char dir_sep[2]={DIR_SEP,0};
-	for (p=path;p;p=q+1) {
+	for (p=path;p;) {
 		q=strchr(p,LIST_SEP);
 
 		if (q) {
 			if (!prepare_path_buf(path_buf,p,q)) continue;
 		} else {
-			q--;
 			if (!prepare_path_buf(path_buf,p,p+strlen(p))) continue;
 		}
 		strcat(path_buf,dir_sep); /* always one char */
@@ -88,6 +87,11 @@ char *find_file(char *name, const char *path)
 			free(name); 
 			return strdup(path_buf);
 		}
+		if (q) {
+			p = q + 1;
+		} else {
+			p = NULL;
+		}
 	}
 	/* if we are here, nothing found */
 	free(name); 
@@ -186,7 +190,7 @@ void list_charsets(void) {
 	int count,glob_flags=GLOB_ERR;
 #endif
 	char **ptr;
-	for (p=charset_path;p;p=q+1) {
+	for (p=charset_path;p;) {
 		q=strchr(p,LIST_SEP);
 
 		if (q) {
@@ -197,7 +201,6 @@ void list_charsets(void) {
 			strncpy(path_buf,p,q-p);
 			path_buf[q-p]=0;
 		} else {
-			q--;
 			if (strlen(p)>=PATH_BUF_SIZE) continue;
 			strcpy(path_buf,p);
 		}
@@ -244,6 +247,11 @@ void list_charsets(void) {
 		}
 		glob_flags|=GLOB_APPEND;
 #endif
+		if (q) {
+			p = q + 1;
+		} else {
+			p = NULL;
+		}
 	}
 #ifdef __MSDOS__
 	fputs("utf-8\n",stdout);
