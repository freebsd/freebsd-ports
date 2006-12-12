--- proxychains/libproxychains.c.orig	Wed Mar 15 18:16:59 2006
+++ proxychains/libproxychains.c	Sun Dec 10 01:16:37 2006
@@ -160,7 +160,7 @@
 
 	if(!(file=fopen("./proxychains.conf","r")))
 	if(!(file=fopen(buff,"r")))
-	if(!(file=fopen("/etc/proxychains.conf","r")))
+	if(!(file=fopen(PREFIX "/etc/proxychains.conf","r")))
 	{
 		perror("Can't locate proxychains.conf");
 		exit(1);
@@ -290,8 +290,8 @@
 
 int getnameinfo (const struct sockaddr * sa,
 			socklen_t salen, char * host,
-			socklen_t hostlen, char * serv,
-			socklen_t servlen, unsigned int flags)
+			size_t hostlen, char * serv,
+			size_t servlen, int flags)
 {
 	int ret = 0;
 	if(!init_l)
