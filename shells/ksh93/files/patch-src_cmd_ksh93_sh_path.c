
$FreeBSD$

--- src/cmd/ksh93/sh/path.c.orig	Mon Mar 11 19:50:16 2002
+++ src/cmd/ksh93/sh/path.c	Tue Aug 20 12:51:15 2002
@@ -1081,6 +1081,9 @@
 {
 	register const char *cp;
 	Pathcomp_t *old=0;
+	int offset = staktell();
+	char *savptr;
+	
 	if(!path && type!=PATH_PATH)
 		return(first);
 	if(type!=PATH_FPATH)
@@ -1088,6 +1091,8 @@
 		old = first;
 		first = 0;
 	}
+	if(offset)
+		savptr = stakfreeze(0);
 	if(path) while(*(cp=path))
 	{
 		if(*cp==':')
@@ -1117,6 +1122,10 @@
 			first = (void*)path_addpath((Pathcomp_t*)first,cp,PATH_FPATH);
 		path_delete(old);
 	}
+	if(offset)
+		stakset(savptr,offset);
+	else
+		stakseek(0);
 	return(first);
 }
 
