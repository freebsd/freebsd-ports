--- sst.c	Thu May  4 14:47:28 2000
+++ sst.c.new	Sun Dec 31 04:49:43 2000
@@ -609,8 +609,8 @@
 			SHOW_info1("client cert subject: %s", subj);
 			SHOW_info1("client cert issuer: %s", issu);
 
-			Free(subj);
-			Free(issu);
+			free(subj);
+			free(issu);
     
 			/*
 			 * XXX ...
@@ -699,8 +699,8 @@
 		SHOW_info1("server cert subject: %s", subj);
 		SHOW_info1("server cert issuer: %s", issu);
 
-		Free(subj);
-		Free(issu);
+		free(subj);
+		free(issu);
 
 		/*
 		 * XXX ...
