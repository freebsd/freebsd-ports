--- gman.c.orig	Sat Mar 31 18:38:43 2001
+++ gman.c	Sat Apr 14 05:10:14 2001
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
 	context->set_default_value("xterm_command","char*",(void*)"xterm"); // rxvt, Eterm also works
-	context->set_default_value("gv_command","char*",(void*)"gv");
+	context->set_default_value("gv_command","char*",(void*)"ghostview");
 	context->set_default_value("browser_command","char*",(void*)"netscape"); // kfm also works
 	context->set_default_value("cgi_host","char*",(void*)"localhost");
 	context->set_default_value("cgi_location","char*",(void*)"/cgi-bin/gman/gman.pl");
