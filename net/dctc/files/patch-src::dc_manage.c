--- src/dc_manage.c.orig	Mon Jul 22 13:20:19 2002
+++ src/dc_manage.c	Mon Jul 22 18:18:40 2002
@@ -554,18 +554,6 @@
 
 	unconvert_path(fullpathname);
 
-	if(!file_in_db(fullpathname,&virtual))		/* is it a shared file ? */
-	{
-		GString *err_msg;
-
-		err_msg=g_string_new("$Error ");
-		g_string_sprintfa(err_msg,"%s no more exists",fullpathname);
-		disp_msg(DEBUG_MSG,"com_up_get_process","file not found",err_msg->str,NULL);
-		send_dc_line(sck,err_msg->str,NULL);
-		g_string_free(err_msg,TRUE);
-		return 1;
-	}
-
 	if(hide_absolute==0)
 	{
 		if(((unsigned char)fullpathname[0])==255)
@@ -580,6 +568,18 @@
 		fullpathname[0]='/';
 	}
 
+	if(!file_in_db(fullpathname,&virtual))		/* is it a shared file ? */
+	{
+		GString *err_msg;
+
+		err_msg=g_string_new("$Error ");
+		g_string_sprintfa(err_msg,"%s no more exists",fullpathname);
+		disp_msg(DEBUG_MSG,"com_up_get_process","file not found",err_msg->str,NULL);
+		send_dc_line(sck,err_msg->str,NULL);
+		g_string_free(err_msg,TRUE);
+		return 1;
+	}
+
 	/* it is time to verify if a slot is available */
 	LOCK_WRITE(user_info);
 	if((dl_on==0)||(virtual!=0))
@@ -743,18 +743,6 @@
 
 	unconvert_path(fullpathname);
 
-	if(!file_in_db(fullpathname,&virtual))		/* is it a shared file ? */
-	{
-		GString *err_msg;
-
-		err_msg=g_string_new("$Error ");
-		g_string_sprintfa(err_msg,"%s no more exists",fullpathname);
-		disp_msg(DEBUG_MSG,"com_up_getfilelength_process","file not found",err_msg->str,NULL);
-		send_dc_line(sck,err_msg->str,NULL);
-		g_string_free(err_msg,TRUE);
-		return 1;
-	}
-
 	if(hide_absolute==0)
 	{
 		if(((unsigned char)fullpathname[0])==255)
@@ -769,6 +757,17 @@
 		fullpathname[0]='/';
 	}
 
+	if(!file_in_db(fullpathname,&virtual))		/* is it a shared file ? */
+	{
+		GString *err_msg;
+
+		err_msg=g_string_new("$Error ");
+		g_string_sprintfa(err_msg,"%s no more exists",fullpathname);
+		disp_msg(DEBUG_MSG,"com_up_getfilelength_process","file not found",err_msg->str,NULL);
+		send_dc_line(sck,err_msg->str,NULL);
+		g_string_free(err_msg,TRUE);
+		return 1;
+	}
 
 	if(send_file_length(sck,fullpathname,&file_len))
 	{
