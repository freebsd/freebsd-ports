--- server/xauth.c.orig	Fri Dec  9 03:53:20 1994
+++ server/xauth.c	Mon Nov  4 05:48:08 2002
@@ -30,7 +30,7 @@
 extern char	Host[];
 
 /* forward declarations */
-void getpass();
+void my_getpass();
 void getuser();
 
  
@@ -59,7 +59,9 @@
 	union wait status;
 #endif
 	struct stat stb;
+#ifndef __FreeBSD__
 	char *malloc();
+#endif
 
 	av += 2;
 
@@ -249,7 +251,7 @@
 			fflush(stdout);
 			return;
 		}
-		getpass(argv[2]);
+		my_getpass(argv[2]);
 		return;
 	}
 #ifdef GENAUTH
@@ -301,7 +303,7 @@
 
 /* password */
 void
-getpass(p)
+my_getpass(p)
 char *p;
 {
 	static char pass[10];
