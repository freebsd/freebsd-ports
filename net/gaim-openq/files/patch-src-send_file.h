--- src/send_file.h.orig	Thu Aug 18 18:49:04 2005
+++ src/send_file.h	Thu Aug 18 17:55:56 2005
@@ -40,7 +40,7 @@
 	union {
 		FILE *dest_fp;
 		guint8 *buffer;
-	};
+	} un;
 	gboolean use_major;
 } ft_info;
 
