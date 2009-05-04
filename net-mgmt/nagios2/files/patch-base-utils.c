--- base/utils.c.orig	2008-02-11 03:50:10.000000000 +1030
+++ base/utils.c	2009-05-03 11:58:03.000000000 +0930
@@ -4553,7 +4553,7 @@
 /* initializes embedded perl interpreter */
 int init_embedded_perl(char **env){
 #ifdef EMBEDDEDPERL
-	char *embedding[] = { "", "" };
+	char **embedding = NULL;
 	int exitstatus = 0;
 	char buffer[MAX_INPUT_BUFFER];
 	int argc = 2;
@@ -4571,6 +4571,21 @@
 
 	else{
 
+	  embedding = malloc(argc * sizeof(char *));
+	  if (embedding == NULL) {
+	    use_embedded_perl = FALSE;
+	    snprintf(buffer, sizeof(buffer), "Error: Unable to allocate memory for embedded Perl interpreter! (see ports/131993)\n");
+	    buffer[sizeof(buffer) - 1] = '\0';
+	    write_to_logs_and_console(buffer, NSLOG_RUNTIME_ERROR, TRUE);
+	  } else {
+	    embedding[0] = malloc(sizeof(char));
+	    if (embedding[0] == NULL) {
+	      use_embedded_perl = FALSE;
+	      snprintf(buffer, sizeof(buffer), "Error: Unable to allocate memory for embedded Perl interpreter! (see ports/131993)\n");
+	      buffer[sizeof(buffer) - 1] = '\0';
+	      write_to_logs_and_console(buffer, NSLOG_RUNTIME_ERROR, TRUE);
+	    } else {
+		*embedding[0] = '\0';
 		embedding[1]=p1_file;
 
 		use_embedded_perl=TRUE;
@@ -4584,6 +4599,8 @@
 			write_to_logs_and_console(buffer,NSLOG_RUNTIME_ERROR,TRUE);
 			}
 		}
+	    }
+	  }
 
 	/* a fatal error occurred... */
 	if(use_embedded_perl==FALSE){
