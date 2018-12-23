--- ctm/ctm_pass3.c.orig	2018-10-27 15:56:22 UTC
+++ ctm/ctm_pass3.c
@@ -35,10 +35,12 @@ Pass3(FILE *fd)
 {
     u_char *p,*q,buf[BUFSIZ];
     MD5_CTX ctx;
-    int i,j,sep,cnt;
+    int i,j,sep;
+    intmax_t cnt,rel;
+    char *svn_command = NULL;
     u_char *md5=0,*md5before=0,*trash=0,*name=0,*uid=0,*gid=0,*mode=0;
     struct CTM_Syntax *sp;
-    FILE *ed=0;
+    FILE *ed=0, *fd_to;
     struct stat st;
     char md5_1[33];
     int match=0;
@@ -131,7 +133,7 @@ Pass3(FILE *fd)
 	WRONG
     found:
 	for(i=0;(j = sp->List[i]);i++) {
-	    if (sp->List[i+1] && (sp->List[i+1] & CTM_F_MASK) != CTM_F_Bytes)
+	    if (sp->List[i+1] && (sp->List[i+1] & CTM_F_MASK) != CTM_F_Bytes && (sp->List[i+1] & CTM_F_MASK) != CTM_F_Forward)
 		sep = ' ';
 	    else
 		sep = '\n';
@@ -149,53 +151,98 @@ Pass3(FILE *fd)
 		    break;
 		case CTM_F_Count: GETBYTECNT(cnt,sep); break;
 		case CTM_F_Bytes: GETDATA(trash,cnt); break;
+		case CTM_F_Release: GETBYTECNT(rel,sep); break;
+		case CTM_F_Forward:
+		    if ((j & CTM_Q_MASK) == CTM_Q_Forward_Tar) {
+			if (Verbose > 0)
+			    fd_to = popen("tar xvf -","w");
+			else
+			    fd_to = popen("tar xvf - >/dev/null 2>&1","w");
+		    } else if ((j & CTM_Q_MASK) == CTM_Q_Forward_SVN) {
+			svn_command = alloca(strlen(name)+128);
+			if (Verbose > 0)
+			    snprintf(svn_command,strlen(name)+127,"svnadmin load %s\n", name);
+			else
+			    snprintf(svn_command,strlen(name)+127,"svnadmin load %s > /dev/null 2>&1\n", name);
+			fd_to = popen(svn_command,"w");
+		    } else WRONG
+		    if (fd_to == NULL) {
+			fprintf(stderr,"Cannot forward\n");
+			WRONG
+		    }
+	    	    if (Verbose > 0) {
+			if (!strcmp(sp->Key,"TR"))
+			    fprintf(stderr,"> %s\n",sp->Key);
+			else
+	 		    fprintf(stderr,"> %s %s\n",sp->Key,name);
+		    }
+		    GETFORWARD(cnt,fd_to);
+		    if (pclose(fd_to)) {
+			if ((j & CTM_Q_MASK) == CTM_Q_Forward_Tar)
+			    fprintf(stderr,"Tar failed to close properly\n");
+			else if ((j & CTM_Q_MASK) == CTM_Q_Forward_SVN)
+			    fprintf(stderr,"Svnadmin failed to close properly\n");
+			WRONG
+		    }
+		    if ((j & CTM_Q_MASK) == CTM_Q_Forward_SVN) {
+			snprintf(svn_command,strlen(name)+127,"svnadmin pack %s\n", name);
+			if (system(svn_command)) {
+			    fprintf(stderr,"\"%s\" didn't work.", svn_command);
+			    WRONG
+			}
+		    }
+		    break;
 		default: WRONG
 		}
 	    }
-	/* XXX This should go away.  Disallow trailing '/' */
-	j = strlen(name)-1;
-	if(name[j] == '/') name[j] = '\0';
 
-	/*
-	 * If a filter list is specified, run thru the filter list and
-	 * match `name' against filters.  If the name matches, set the
-	 * required action to that specified in the filter.
-	 * The default action if no filterlist is given is to match
-	 * everything.  
-	 */
+	if (name) {
+	    /* XXX This should go away.  Disallow trailing '/' */
+	    j = strlen(name)-1;
+	    if(name[j] == '/') name[j] = '\0';
 
-	match = (FilterList ? !(FilterList->Action) : CTM_FILTER_ENABLE);
-	for (filter = FilterList; filter; filter = filter->Next) {
-	    if (0 == regexec(&filter->CompiledRegex, name,
-		0, 0, 0)) {
-		match = filter->Action;
+	    /*
+	     * If a filter list is specified, run thru the filter list and
+	     * match `name' against filters.  If the name matches, set the
+	     * required action to that specified in the filter.
+	     * The default action if no filterlist is given is to match
+	     * everything.  
+	     */
+
+	    match = (FilterList ? !(FilterList->Action) : CTM_FILTER_ENABLE);
+	    for (filter = FilterList; filter; filter = filter->Next) {
+		if (0 == regexec(&filter->CompiledRegex, name,
+		    0, 0, 0)) {
+		    match = filter->Action;
+		}
 	    }
-	}
 
-	if (CTM_FILTER_DISABLE == match) /* skip file if disabled */
-		continue;
+	    if (CTM_FILTER_DISABLE == match) /* skip file if disabled */
+		    continue;
 
-	if (Verbose > 0)
+	    if (Verbose > 0 && strcmp(sp->Key,"SV") && strcmp(sp->Key,"TR"))
 		fprintf(stderr,"> %s %s\n",sp->Key,name);
-	if(!strcmp(sp->Key,"FM") || !strcmp(sp->Key, "FS")) {
-	    i = open(name,O_WRONLY|O_CREAT|O_TRUNC,0666);
-	    if(i < 0) {
-		warn("%s", name);
-		WRONG
+	    if(!strcmp(sp->Key,"FM") || !strcmp(sp->Key, "FS")) {
+		i = open(name,O_WRONLY|O_CREAT|O_TRUNC,0666);
+		if(i < 0) {
+		    warn("%s", name);
+		    WRONG
+		}
+		if(cnt != write(i,trash,cnt)) {
+		    warn("%s", name);
+		    WRONG
+		}
+		close(i);
+		if(strcmp(md5,MD5File(name,md5_1))) {
+		    fprintf(stderr,"  %s %s MD5 didn't come out right\n",
+		       sp->Key,name);
+		    WRONG
+		}
+		if (settime(name,times)) WRONG
+		continue;
 	    }
-	    if(cnt != write(i,trash,cnt)) {
-		warn("%s", name);
-		WRONG
-	    }
-	    close(i);
-	    if(strcmp(md5,MD5File(name,md5_1))) {
-		fprintf(stderr,"  %s %s MD5 didn't come out right\n",
-		   sp->Key,name);
-		WRONG
-	    }
-	    if (settime(name,times)) WRONG
-	    continue;
 	}
+
 	if(!strcmp(sp->Key,"FE")) {
 	    ed = popen("ed","w");
 	    if(!ed) {
@@ -278,6 +325,8 @@ Pass3(FILE *fd)
 	    }
 	    continue;
 	}
+	if(!strcmp(sp->Key,"TR") || !strcmp(sp->Key,"SV"))
+	    continue;
 	WRONG
     }
 
