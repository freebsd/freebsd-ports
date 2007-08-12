--- mandata.c.orig	2007-08-12 19:00:16.000000000 +0200
+++ mandata.c	2007-08-12 19:00:46.000000000 +0200
@@ -239,13 +239,13 @@
 	char buffer[2*BUFFER_SIZE];
 	char loc_name[BUFFER_SIZE];
 	char buffer2[BUFFER_SIZE];
-	switch ((int)context->get_value("show_mode")) {
+	switch ((intptr_t)context->get_value("show_mode")) {
 	case 0:
-		sprintf(buffer,"%s -T '%s manual page' -n GMan -e man ",
+		sprintf(buffer,"%s -T '%s manual page' -n GMan -e man %s",
 				(char*)context->get_value("xterm_command"),
-				get_display_name(buffer1));
-		len = strlen(buffer);
-		attach(buffer+len,man_path->GetPath(),file_name);
+				get_display_name(buffer1), get_display_name(buffer1));
+/*		len = strlen(buffer);
+		attach(buffer+len,man_path->GetPath(),file_name); */
 		//g_warning(buffer);
 		if(!fork())
 		{
@@ -256,9 +256,9 @@
 		break;
 	case 1:
 		sprintf(loc_name," ~/.gman.%s.ps ",get_display_name(buffer1));
-		sprintf(buffer,"man -t ");
-		len = strlen(buffer);
-		attach(buffer+len,man_path->GetPath(),file_name);
+		sprintf(buffer,"man -t %s", get_display_name(buffer1));
+/*		len = strlen(buffer);
+		attach(buffer+len,man_path->GetPath(),file_name); */
 		strcat(buffer," >> ");
 		strcat(buffer,loc_name);
 		strcat(buffer," ; ");
@@ -306,7 +306,7 @@
 	case 2:
 		sprintf(loc_name," ~/.gman.%s.html ",get_display_name(buffer1));
 		//g_warning(loc_name);
-		strcpy(buffer,"/usr/lib/cgi-bin/gman.pl ");
+		strcpy(buffer,"/usr/local/www/cgi-bin/gman.pl ");
 		strcat(buffer," ");
 		strcat(buffer,get_section_name(buffer2));
 		strcat(buffer," ");
@@ -350,7 +350,7 @@
 		break;
 	default:
 		if(context->get_value("show_warning"))
-			g_print("unexpected \'show_mode\' : %d ",(int)context->get_value("show_mode"));
+			g_print("unexpected \'show_mode\' : %d ",(intptr_t)context->get_value("show_mode"));
 		return;
 	}
 	//g_warning(buffer);
