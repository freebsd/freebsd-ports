--- gman.c.dist	Mon May 12 07:39:11 2003
+++ gman.c	Mon May 12 07:39:53 2003
@@ -90,7 +90,7 @@
 	context->set_default_value("show_warning","int",(void*)0);
 	context->set_default_value("show_mode","int",(void*)0); // 0 = xterm, 1 = ghostview
 	context->set_default_value("xterm_command","char*",(void*)"x-terminal-emulator");
-	context->set_default_value("gv_command","char*",(void*)"gv");
+	context->set_default_value("gv_command","char*",(void*)"ghostview");
 	context->set_default_value("browser_command","char*",(void*)"mozilla"); // kfm also works
 	context->set_default_value("cgi_host","char*",(void*)"localhost");
 	context->set_default_value("cgi_location","char*",(void*)"/cgi-bin/gman.pl");
