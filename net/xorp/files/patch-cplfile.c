--- cli/libtecla/cplfile.c.orig	2018-07-11 16:49:26 UTC
+++ cli/libtecla/cplfile.c
@@ -314,7 +314,7 @@ int _cf_complete_file(WordCompletion *cp
  * might be the start of the last component, and mark the character
  * that follows it as the start of the name that is to be completed.
  */
-      if(nleft >= FS_DIR_SEP_LEN &&
+      if((unsigned long)(nleft) >= FS_DIR_SEP_LEN &&
 	 strncmp(lptr + seglen, FS_DIR_SEP, FS_DIR_SEP_LEN)==0) {
 	word_start = (lptr + seglen) - line + FS_DIR_SEP_LEN;
       };
@@ -394,12 +394,12 @@ int _cf_complete_file(WordCompletion *cp
 /*
  * Prevent extra directory separators from being added.
  */
-	if(nleft >= FS_DIR_SEP_LEN &&
+	if((unsigned long)(nleft) >= FS_DIR_SEP_LEN &&
 	   strcmp(cf->path->name, FS_ROOT_DIR) == 0 &&
 	   strncmp(lptr, FS_DIR_SEP, FS_DIR_SEP_LEN) == 0) {
 	  lptr += FS_DIR_SEP_LEN;
 	  nleft -= FS_DIR_SEP_LEN;
-	} else if(vlen > FS_DIR_SEP_LEN &&
+	} else if((unsigned long)(vlen) > FS_DIR_SEP_LEN &&
 		  strcmp(value + vlen - FS_DIR_SEP_LEN, FS_DIR_SEP)==0) {
 	  cf->path->name[vlen-FS_DIR_SEP_LEN] = '\0';
 	};
@@ -781,7 +781,7 @@ static char *cf_read_name(CompleteFile *
  * Get the environment variable name that follows the dollar.
  */
   for(sptr=string,namlen=0;
-      namlen < nmax && (slen-namlen < FS_DIR_SEP_LEN ||
+      namlen < nmax && ((unsigned long)(slen-namlen) < FS_DIR_SEP_LEN ||
 			strncmp(sptr, FS_DIR_SEP, FS_DIR_SEP_LEN) != 0);
       namlen++) {
     nambuf[namlen] = *sptr++;
