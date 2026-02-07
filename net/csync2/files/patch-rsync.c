--- rsync.c.orig	2015-03-09 14:08:51 UTC
+++ rsync.c
@@ -41,6 +41,7 @@
 
 /* This has been taken from rsync:lib/compat.c */
 
+#if 0
 /**
  * Like strncpy but does not 0 fill the buffer and always null
  * terminates.
@@ -61,6 +62,7 @@ static size_t strlcpy(char *d, const cha
         }
         return ret;
 }
+#endif
 
 /* splits filepath at the last '/', if any, like so:
  *	dirname		basename	filepath
@@ -117,7 +119,10 @@ int mkpath(const char *path, mode_t mode
 		return -1;
 	}
 
-	strlcpy(temp,path,strlen(path));
+	if(strlcpy(temp,path,sizeof(temp))>=sizeof(temp)) {
+		csync_debug(1,"path too long: %s",path);
+		return -1;
+	}
 	csync_debug(1,"mkpath full path: %s",temp);
 	for( remaining=strchr(temp+1, '/'); remaining!=NULL; remaining=strchr(remaining+1, '/') ){
 		*remaining='\0';
