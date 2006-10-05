diff -urN -x .svn ../../vendor/vpopmail/vpalias.c ./vpalias.c
--- ../../vendor/vpopmail/vpalias.c	Wed Oct  4 13:19:16 2006
+++ ./vpalias.c	Wed Oct  4 17:14:57 2006
@@ -160,6 +160,7 @@
 {
  char *tmpstr;
  char Dir[156];
+ char *p;
  uid_t uid;
  gid_t gid;
  int i;
@@ -174,8 +175,10 @@
 	return(-1);
     }
     strncat(Dir, "/.qmail-", sizeof(Dir)-strlen(Dir)-1);
-    for(i=0;alias[i]!=0;++i) if ( alias[i] == '.' ) alias[i] = ':';
-    strncat(Dir, alias, sizeof(Dir)-strlen(Dir)-1);
+    i = strlen(Dir);
+    for (p = alias; (i < (int)sizeof(Dir) - 1) && (*p != '\0'); p++)
+      Dir[i++] = (*p == '.' ? ':' : *p);
+    Dir[i] = '\0';
     return(unlink(Dir));
 }
 
@@ -192,8 +195,8 @@
  gid_t gid;
  int countit;
  struct stat mystat;
- char filename[500];
- int i, j, len;
+ char filename[500], **new_names;
+ int i, j, len, cnt_names;
 
     if ( domain == NULL ) { 
       verrori=VA_NULL_POINTER;
@@ -226,27 +229,8 @@
      *  Its only a few bytes...
      */
 
-    if (mydir!=NULL) closedir(mydir);
-    if ( (mydir = opendir(Dir)) == NULL ) return(NULL);
-
-    while ((mydirent=readdir(mydir))!=NULL) {
-      if ( strncmp(mydirent->d_name,".qmail-", 7) == 0 &&
-           strcmp(mydirent->d_name, ".qmail-default") != 0 ) {
-        max_names++;
-      }
-    }
-
-    /*  Now we know about how many aliases there may be.
-     *  Allocate a buffer for them
-     */    
-
-    if (mydir!=NULL) {
-	    closedir(mydir);
-		/* this is static and hence must be nulled incase max_names == 0 below */
-	    mydir = NULL;
-    }
-
-    if (max_names == 0) return NULL;
+    max_names = 100; /* some kind of default... */
+    num_names = 0;
 
     names = malloc( max_names * sizeof(char *));
     memset(names, 0, max_names * sizeof(char *));
@@ -258,7 +242,7 @@
            strcmp(mydirent->d_name, ".qmail-default") != 0 ) {
 
         countit=0;
-        sprintf(filename, "%s/%s", Dir, mydirent->d_name);
+        snprintf(filename, sizeof(filename), "%s/%s", Dir, mydirent->d_name);
         
         if(!lstat(filename, &mystat) && S_ISLNK(mystat.st_mode)) {
           /*  It is a mailing list  */
@@ -274,18 +258,39 @@
         }
 
         if(countit) {
+	  if (num_names == max_names) {
+	    // reallocate the array
+	    cnt_names = 2 * max_names;
+	    new_names = realloc( names, cnt_names * sizeof(char *) );
+	    if (new_names == NULL) {
+	      for(i = 0; i < num_names; i++)
+		free(names[i]);
+	      free(names);
+	      return(NULL);
+	    }
+
+	    // Okay, looks like we allocated enough memory
+	    names = new_names;
+	    max_names = cnt_names;
+	  }
           sprintf(filename, "%s", mydirent->d_name );
           len = strlen( filename ) - 7;
           names[ num_names ] = malloc( len + 1 );
           for(i=7,j=0; j<=len; i++,j++) {
-            names[num_names][j] = filename[i];
             if( ':' == filename[i] ) {
               names[num_names][j] = '.';
-            }
+            } else {
+	      names[num_names][j] = filename[i];
+	    }
           }
           num_names++;          
         }
       }
+    }
+    if (num_names < max_names) {
+      new_names = realloc( names, num_names * sizeof(char *) );
+      if (new_names != NULL)
+	names = new_names;
     }
 
     if (mydir!=NULL) {
