--- src/users.c.orig
+++ src/users.c
@@ -157,7 +157,7 @@ void update_user_time(char *tty)
 	}
 }
 
-void update_users(void)
+int update_users(void)
 {
 	struct information *current_info = &info;
 	char temp[BUFLEN] = "";
@@ -221,4 +221,5 @@ void update_users(void)
 		current_info->users.times = malloc(text_buffer_size);
 		strncpy(current_info->users.times, "broken", text_buffer_size);
 	}
+	return 0;
 }
