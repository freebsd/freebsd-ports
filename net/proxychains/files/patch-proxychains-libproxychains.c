--- proxychains/libproxychains.c.orig	2006-03-15 16:16:59 UTC
+++ proxychains/libproxychains.c
@@ -160,7 +160,7 @@ static inline void get_chain_data(
 
 	if(!(file=fopen("./proxychains.conf","r")))
 	if(!(file=fopen(buff,"r")))
-	if(!(file=fopen("/etc/proxychains.conf","r")))
+	if(!(file=fopen(PREFIX "/etc/proxychains.conf","r")))
 	{
 		perror("Can't locate proxychains.conf");
 		exit(1);
@@ -290,8 +290,8 @@ void freeaddrinfo(struct addrinfo *res)
 
 int getnameinfo (const struct sockaddr * sa,
 			socklen_t salen, char * host,
-			socklen_t hostlen, char * serv,
-			socklen_t servlen, unsigned int flags)
+			size_t hostlen, char * serv,
+			size_t servlen, int flags)
 {
 	int ret = 0;
 	if(!init_l)
