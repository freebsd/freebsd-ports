--- xmit/xmitauth.c.orig	Sat Dec  3 22:54:06 1994
+++ xmit/xmitauth.c	Fri Jul 25 19:15:39 2003
@@ -11,6 +11,7 @@
 
 extern char Debug;
 extern int converse();
+extern void nntpdlog();
 
 FILE *sys;
 
@@ -37,7 +38,7 @@
 		/* malformed entry? */
 		if (i != 3)
 			{
-			log(L_NOTICE,"malformed entry in nntp.sys");
+			nntpdlog(L_NOTICE,"malformed entry in nntp.sys");
 			continue;
 			}
 		
@@ -48,14 +49,14 @@
 	if (feof(sys))
 		{
 		sprintf(buf,"host %s authinfo not in nntp.sys", host);
-		log(L_NOTICE, buf);
+		nntpdlog(L_NOTICE, buf);
 		exit(1);
 		}
 	
 	sprintf(buf,"authinfo user %s", user);
 	if (converse(buf, sizeof(buf)) != NEED_AUTHDATA)
 		{
-		log(L_NOTICE, buf);
+		nntpdlog(L_NOTICE, buf);
 		exit(1);
 		}
 	
@@ -66,7 +67,7 @@
 	sprintf(buf,"authinfo pass %s", pass);
 	if (converse(buf, sizeof(buf)) != OK_AUTH)
 		{
-		log(L_NOTICE, buf);
+		nntpdlog(L_NOTICE, buf);
 		exit(1);
 		}
 	
