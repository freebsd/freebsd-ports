--- gman.c.orig	Mon Dec 13 22:25:03 2004
+++ gman.c	Mon Dec 13 22:26:54 2004
@@ -62,6 +62,8 @@
 
 	//gtk_main();
 	
+
+	
 	while(1){
 		pthread_mutex_lock(&gtk_lock);
 		while(gtk_events_pending()) {
@@ -77,6 +79,14 @@
 /******************* init_context() *****************/
 void init_context()
 {
+	static char *browser;
+	if ((browser = getenv("BROWSER")) == NULL)
+	{
+		fprintf(stderr,"A BROWSER variable that contains the name of your\n \
+favorite browser's executable file must be created\n \
+in order to use gman with localbrowse/netbrowse.\n");
+			exit(1);
+	}
 	FILE * fd;
 	char buffer[256];
 	context = new AppContext();
@@ -89,9 +99,9 @@
 	context->set_default_value("show_status_bar","int",(void*)0);
 	context->set_default_value("show_warning","int",(void*)0);
 	context->set_default_value("show_mode","int",(void*)0); // 0 = xterm, 1 = ghostview
-	context->set_default_value("xterm_command","char*",(void*)"x-terminal-emulator");
-	context->set_default_value("gv_command","char*",(void*)"gv");
-	context->set_default_value("browser_command","char*",(void*)"mozilla"); // kfm also works
+	context->set_default_value("xterm_command","char*",(void*)"xterm");
+	context->set_default_value("gv_command","char*",(void*)"ghostview");
+	context->set_default_value("browser_command","char*",(void*)browser); // kfm also works
 	context->set_default_value("cgi_host","char*",(void*)"localhost");
 	context->set_default_value("cgi_location","char*",(void*)"/cgi-bin/gman.pl");
 	context->set_default_value("print_command","char*",(void*)"lpr"); // not in use
