--- src/file.c.orig	2024-07-04 00:23:14 UTC
+++ src/file.c
@@ -127,7 +127,8 @@ int walker(const char *startPath, const char *searchin
                 }
 
                 char entryPath[MAXPATHLEN];
-                char *currentDir = get_current_dir_name();
+		char buf[PATH_MAX];
+                char *currentDir = getcwd(buf, PATH_MAX);
                 snprintf(entryPath, sizeof(entryPath), "%s/%s", currentDir, dir->d_name);
                 free(currentDir);
 
@@ -141,7 +142,8 @@ int walker(const char *startPath, const char *searchin
                         if (((exactSearch && (strcasecmp(dir->d_name, searching) == 0)) || (!exactSearch && c_strcasestr(dir->d_name, searching) != NULL)) &&
                             (searchType != FileOnly) && (searchType != SearchPlayList))
                         {
-                                char *curDir = get_current_dir_name();
+				char buf[PATH_MAX];
+                                char *curDir = getcwd(buf, PATH_MAX);
                                 snprintf(result, MAXPATHLEN, "%s/%s", curDir, dir->d_name);
                                 free(curDir);
                                 copyresult = true;
@@ -187,7 +189,8 @@ int walker(const char *startPath, const char *searchin
 
                         if ((exactSearch && (strcasecmp(dir->d_name, searching) == 0)) || (!exactSearch && c_strcasestr(dir->d_name, searching) != NULL))
                         {
-                                char *curDir = get_current_dir_name();
+				char buf[PATH_MAX];
+                                char *curDir = getcwd(buf, PATH_MAX);
                                 snprintf(result, MAXPATHLEN, "%s/%s", curDir, dir->d_name);
                                 copyresult = true;
                                 free(curDir);
