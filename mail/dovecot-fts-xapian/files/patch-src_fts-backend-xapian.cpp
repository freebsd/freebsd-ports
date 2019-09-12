--- src/fts-backend-xapian.cpp.orig	2019-08-18 16:36:45 UTC
+++ src/fts-backend-xapian.cpp
@@ -115,9 +115,7 @@ static int fts_backend_xapian_init(struct fts_backend 
     	}
 
 	const char * path = mailbox_list_get_root_forced(_backend->ns->list, MAILBOX_LIST_PATH_TYPE_INDEX);
-	long l=strlen(path)+strlen(XAPIAN_FILE_PREFIX)+2;
-	backend->path = (char *)i_malloc(l*sizeof(char));
-	snprintf(backend->path,l,"%s/%s",path,XAPIAN_FILE_PREFIX);
+	backend->path = i_strconcat(path, "/" XAPIAN_FILE_PREFIX, NULL);
 
 	struct stat sb;
 	if(!( (stat(backend->path, &sb)==0) && S_ISDIR(sb.st_mode)))
