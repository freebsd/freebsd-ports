--- mandata.c.orig	Sat Mar 31 19:16:19 2001
+++ mandata.c	Sat Apr 14 05:12:49 2001
@@ -243,11 +243,11 @@
 	char buffer2[BUFFER_SIZE];
 	switch ((int)context->get_value("show_mode")) {
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
@@ -258,9 +258,9 @@
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
