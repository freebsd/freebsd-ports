--- ctm/ctm_pass2.c.orig	2018-10-27 15:56:22 UTC
+++ ctm/ctm_pass2.c
@@ -24,7 +24,11 @@ Pass2(FILE *fd)
 {
     u_char *p,*q,*md5=0;
     MD5_CTX ctx;
-    int i,j,sep,cnt,fdesc;
+    int i,j,sep,fdesc;
+    intmax_t cnt, rel;
+    int rel2;
+    FILE *current;
+    char *current_file_name = NULL;
     u_char *trash=0,*name=0;
     struct CTM_Syntax *sp;
     struct stat st;
@@ -32,7 +36,7 @@ Pass2(FILE *fd)
     int match = 0;
     char md5_1[33];
     struct CTM_Filter *filter;
-    FILE *ed = NULL;
+    FILE *ed = NULL, *fd_to = NULL;
     static char *template = NULL;
 
     if(Verbose>3)
@@ -74,7 +78,7 @@ Pass2(FILE *fd)
 	WRONG
     found:
 	for(i=0;(j = sp->List[i]);i++) {
-	    if (sp->List[i+1] && (sp->List[i+1] & CTM_F_MASK) != CTM_F_Bytes)
+	    if (sp->List[i+1] && (sp->List[i+1] & CTM_F_MASK) != CTM_F_Bytes && (sp->List[i+1] & CTM_F_MASK) != CTM_F_Forward)
 		sep = ' ';
 	    else
 		sep = '\n';
@@ -130,6 +134,22 @@ Pass2(FILE *fd)
 				sp->Key,name);
 			    ret |= Exit_NotOK;
 			}
+			if (j & CTM_Q_Name_Svnbase) {
+			    current_file_name = alloca(strlen(name)+128);
+			    strcpy(current_file_name,name);
+			    strcat(current_file_name,"/db/current");
+	 		    current = fopen(current_file_name,"r");
+			    if (current==NULL) {
+				fprintf(stderr,"Cannot open %s\n",current_file_name);
+				WRONG
+			    }
+			    if (fscanf(current,"%d",&rel2) != 1) {
+				fprintf(stderr,"Cannot find release number in %s\n",current_file_name);
+				fclose(current);
+				WRONG
+			    }
+			    fclose(current);
+			}
 			break;
 		    }
 		    if (j & CTM_Q_Name_File) {
@@ -285,6 +305,42 @@ Pass2(FILE *fd)
 			Free(p);
 		    }
 
+		    break;
+		case CTM_F_Release:
+		    GETBYTECNT(rel,sep);
+		    if(Verbose > 3)
+			printf("Expecting release number %jd\n",rel);
+		    if(Verbose > 3)
+			printf("Actual release number %d\n",rel2);
+		    if (rel != rel2) {
+			fprintf(stderr,"Release number mismatch: found %d, need %jd\n",rel2,rel);
+			WRONG
+		    }
+		    break;
+		case CTM_F_Forward:
+		    if ((j & CTM_Q_MASK) == CTM_Q_Forward_SVN) {
+			if(Verbose>3)
+			    printf("This is a svn dump file and there is no certainty that it will apply cleanly.\n");
+			GETFORWARD(cnt,NULL);
+		    }
+		    else if ((j & CTM_Q_MASK) == CTM_Q_Forward_Tar) {
+			if(Verbose>3) {
+			    printf("This is a tar file and there is no certainty that it will apply cleanly even if it passes the following test.\n");
+			    fd_to = popen("tar tvf -","w");
+			} else
+			    fd_to = popen("tar tf - >/dev/null 2>&1","w");
+			if (fd_to == NULL) {
+			    fprintf(stderr,"Cannot forward\n");
+			    WRONG
+			}
+			GETFORWARD(cnt,fd_to);
+			if (pclose(fd_to)) {
+			    fprintf(stderr,"Tar failed to close properly\n");
+			    WRONG
+			} else
+			    if (Verbose > 3)
+				printf("Tar file test was good\n");
+		    }
 		    break;
 		default: WRONG
 	    }
