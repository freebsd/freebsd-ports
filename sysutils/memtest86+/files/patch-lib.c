--- lib.c.orig	2021-02-06 17:28:48 UTC
+++ lib.c
@@ -33,7 +33,7 @@ struct ascii_map_str {
         int keycode;
 };
 
-inline void reboot(void)
+void reboot(void)
 {
 	
 	/* tell the BIOS to do a cold start */
@@ -1196,4 +1196,4 @@ void get_list(int x, int y, int len, char *buf)
 		   return;
 		}
 	}
-}
\ No newline at end of file
+}
