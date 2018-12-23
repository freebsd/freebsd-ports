--- ctm/ctm_pass1.c.orig	2018-10-27 15:56:22 UTC
+++ ctm/ctm_pass1.c
@@ -24,7 +24,8 @@ Pass1(FILE *fd, unsigned applied)
 {
     u_char *p,*q;
     MD5_CTX ctx;
-    int i,j,sep,cnt;
+    int i,j,sep;
+    intmax_t cnt, rel;
     u_char *md5=0,*name=0,*trash=0;
     struct CTM_Syntax *sp;
     int slashwarn=0, match=0, total_matches=0;
@@ -98,7 +99,7 @@ Pass1(FILE *fd, unsigned applied)
 	if(Verbose > 5)
 	    fprintf(stderr,"%s ",sp->Key);
 	for(i=0;(j = sp->List[i]);i++) {
-	    if (sp->List[i+1] && (sp->List[i+1] & CTM_F_MASK) != CTM_F_Bytes)
+	    if (sp->List[i+1] && (sp->List[i+1] & CTM_F_MASK) != CTM_F_Bytes && (sp->List[i+1] & CTM_F_MASK) != CTM_F_Forward)
 		sep = ' ';
 	    else
 		sep = '\n';
@@ -213,6 +214,17 @@ Pass1(FILE *fd, unsigned applied)
 		    if(md5 && strcmp(md5,p)) {
 			Fatal("Internal MD5 failed.");
 			return Exit_Garbage;
+		case CTM_F_Release:
+		    GETBYTECNT(rel,sep);
+		    break;
+		case CTM_F_Forward:
+		    if(cnt < 0) WRONG
+		    if ((j & CTM_Q_MASK) == CTM_Q_Forward_SVN && system("which -s svnadmin") != 0) {
+			fprintf(stderr, "svn is not found in $PATH.  You can install it from ports/devel/subversion, or adjust $PATH.\n");
+			return Exit_Garbage;
+		    }
+		    GETFORWARD(cnt,NULL);
+		    break;
 		default:
 			fprintf(stderr,"List = 0x%x\n",j);
 			Fatal("List had garbage.");
