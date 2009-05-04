--- base/utils.c.orig	2008-12-01 03:52:58.000000000 +1030
+++ base/utils.c	2009-05-03 11:51:19.000000000 +0930
@@ -3597,7 +3597,7 @@
 /* initializes embedded perl interpreter */
 int init_embedded_perl(char **env){
 #ifdef EMBEDDEDPERL
-	char *embedding[]={ "", "" };
+	char **embedding = NULL;
 	int exitstatus=0;
 	char *temp_buffer=NULL;
 	int argc=2;
@@ -3613,6 +3613,17 @@
 
 	else{
 
+	  embedding = malloc(argc * sizeof(char *));
+	  if (embedding == NULL) {
+	    use_embedded_perl = FALSE;
+	    logit(NSLOG_RUNTIME_ERROR, TRUE, "Error: Unable to allocate memory for embedded Perl interpreter! (see ports/131993)\n");
+	  } else {
+	    embedding[0] = malloc(sizeof(char));
+	    if (embedding[0] == NULL) {
+	      use_embedded_perl = FALSE;
+	      logit(NSLOG_RUNTIME_ERROR, TRUE, "Error: Unable to allocate memory for embedded Perl interpreter! (see ports/131993)\n");
+	    } else {
+		*embedding[0] = '\0';
 		embedding[1]=p1_file;
 
 		use_embedded_perl=TRUE;
@@ -3624,6 +3635,8 @@
 			logit(NSLOG_RUNTIME_ERROR,TRUE,"Error: Could not allocate memory for embedded Perl interpreter!\n");
 			}
 		}
+	    }
+	  }
 
 	/* a fatal error occurred... */
 	if(use_embedded_perl==FALSE){
