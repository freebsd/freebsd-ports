--- main.c.orig	Jan 17 01:19:17 2004
+++ main.c	Wed Dec 29 19:47:31 2004
@@ -144,7 +144,7 @@
 		"Hãy đặt lại LANG thành %s.\n"
 		"Tham khảo thêm tài liệu của xvnkb để chọn LANG và tạo locale."
 	};
-	static char *locale_messages[] = {
+/*	static char *locale_messages[] = {
 		"Missing locale information for LANG %s in\n"
 		"/usr/share/locale/%s.\n"
 		"We may not work with Vietnamese properly.%s\n"
@@ -153,7 +153,7 @@
 		"/usr/share/locale/%s.\n"
 		"Chúng ta có thể sẽ không làm việc được với tiếng Việt.%s\n"
 		"Tham khảo thêm tài liệu của xvnkb để tạo các thông tin này."
-	};
+	};*/
 
 	FILE *fp;
 	char buf[512];
@@ -202,7 +202,7 @@
 			sprintf(buf, lang_messages[vk_interface], sys_lang, slang);
 			VKShowMessage(buf);
 		}
-		else {
+/*		else {
 			sprintf(buf, "/usr/share/locale/%s/LC_IDENTIFICATION", sys_lang);
 			fp = fopen(buf, "r");
 			if( fp ) {
@@ -216,7 +216,7 @@
 						"\nAnd xvnkb will display Vietnamese text incorrectly.");
 				VKShowMessage(buf);
 			}
-		}
+		}*/
 	}
 }
 /*----------------------------------------------------------------------------*/
