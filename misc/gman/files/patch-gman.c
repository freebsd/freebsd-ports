--- gman.c.orig	Mon Mar 26 17:08:28 2001
+++ gman.c	Fri Mar 30 23:46:22 2001
@@ -83,7 +83,7 @@
 	context = new AppContext();
 	//	context->set_default_value("v_size",(void*)400);
 	context->set_default_value("debuging","int",(void*)0);
-	context->set_default_value("man_paths","char*",(void*)"/usr/man:/usr/local/man:/usr/X11R6/man");
+	context->set_default_value("man_paths","char*",(void*)"/usr/share/man:/usr/local/man:/usr/X11R6/man");
 	context->set_default_value("display_section_policy","int",(void*)0);
 	context->set_default_value("display_section","int",(void*)3);
 	context->set_default_value("searching_mode","int",(void*)0);
@@ -91,7 +91,7 @@
 	context->set_default_value("show_warning","int",(void*)0);
 	context->set_default_value("show_mode","int",(void*)0); // 0 = xterm, 1 = ghostview
 	context->set_default_value("xterm_command","char*",(void*)"xterm");
-	context->set_default_value("gv_command","char*",(void*)"gv");
+	context->set_default_value("gv_command","char*",(void*)"ghostview");
 	context->set_default_value("print_command","char*",(void*)"lpr");
 
 	attach(buffer,getenv("HOME"),".gman");
