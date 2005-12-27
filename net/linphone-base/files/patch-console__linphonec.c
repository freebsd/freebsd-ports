--- console/linphonec.c.orig	Wed Nov 30 21:11:54 2005
+++ console/linphonec.c	Tue Dec 20 13:29:42 2005
@@ -71,8 +71,8 @@
 //Process termination handling
 void term(int sig)
 {
-   terminate = TRUE;
    char input[LINE_MAX_LEN];
+   terminate = TRUE;
    snprintf (input,sizeof(LINE_MAX_LEN),"%s", "terminate");
    linphonec_parse_command_line(&linphonec,input);
    snprintf (input,sizeof(LINE_MAX_LEN), "%s", "quit");
@@ -161,9 +161,6 @@
 int
 linphonec_main_loop (LinphoneCore * opm, char * sipAddr)
 {
-	if (terminate_on_close) {
-           signal(SIGTERM, term); 
-        }
 	//auto call handling
 	gboolean firstTimeInLoop=TRUE;
 	char input[LINE_MAX_LEN];
@@ -171,6 +168,9 @@
 	fd_set fdset;
 	struct timeval timeout;
 	gboolean run=TRUE;
+	if (terminate_on_close) {
+           signal(SIGTERM, term); 
+        }
 	printf("linphonec> ");fflush(stdout);
 	while (run && !terminate)
 	{
