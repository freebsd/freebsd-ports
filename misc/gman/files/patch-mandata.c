--- mandata.c.orig	Mon Mar 26 16:40:49 2001
+++ mandata.c	Sat Mar 31 00:21:55 2001
@@ -58,7 +58,7 @@
 	if(path_name) free(path_name);
 }
 
-ManPath::GetSize(int section_ID)
+int ManPath::GetSize(int section_ID)
 {
 	int count;
 	int i;
@@ -67,7 +67,7 @@
 	return count;
 }
 
-ManPath::GetItems(int section_ID, ManItem * buffer[])
+int ManPath::GetItems(int section_ID, ManItem * buffer[])
 {
 	int count;
 	int i;
@@ -80,7 +80,7 @@
 
 struct stat state;
 
-ManPath::LoadManPath(char * path_name)
+int ManPath::LoadManPath(char * path_name)
 {
 	DIR *dirp;
 	#if defined(SYS_DIR)||defined(NDIR)
@@ -125,7 +125,7 @@
 	return 0;
 }
 
-ManPath::LoadManSubPath(char * sub_name)
+int ManPath::LoadManSubPath(char * sub_name)
 {
 	DIR *dirp;
 	#if defined(SYS_DIR)||defined(NDIR)
@@ -242,11 +242,11 @@
 	char loc_name[BUFFER_SIZE];
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
@@ -257,9 +257,9 @@
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
