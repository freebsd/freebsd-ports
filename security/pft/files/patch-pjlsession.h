--- pjlsession.h.orig	Sat Jul  6 18:36:21 2002
+++ pjlsession.h	Thu Aug  5 15:25:00 2004
@@ -70,10 +70,10 @@
 
 		// reads the volume information from device
 		void read_volumes(void);
-		// reads an directory into the dir list
+		/* reads an directory into the dir list
 		// this method expects an absolute directory 
 		// path like 0:\webserver\   
-		// it also updates pwd (which can be see by get_pwd()
+		// it also updates pwd (which can be see by get_pwd() */
 		void read_dir(char *str);
 		// returns the existence of a file or directory (return
 		// type is one of PJLFS_* or -1 for not found
@@ -133,4 +133,4 @@
 };
 
 
-#endif __PJLSESSION_H__
+#endif // __PJLSESSION_H__
