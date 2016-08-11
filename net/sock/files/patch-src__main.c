--- src/main.c.orig	2010-05-28 00:03:25 UTC
+++ src/main.c
@@ -23,9 +23,10 @@
 char	*host;		/* hostname or dotted-decimal string */
 char	*port;
 
-			/* DefinE global variables */
+			/* Define global variables */
+int		af_46 = AF_INET;		/* AF_INET or AF_INET6 */
 int		bindport;			/* 0 or TCP or UDP port number to bind */
-							/* set by -b or -l options */
+						/* set by -b or -l options */
 int		broadcast;			/* SO_BROADCAST */
 int		cbreak;				/* set terminal to cbreak mode */
 int		chunkwrite;			/* write in small chunks; not all-at-once */
@@ -76,7 +77,8 @@ int		urgwrite;			/* write urgent byte af
 int		verbose;			/* each -v increments this by 1 */
 int		usewritev;			/* use writev() instead of write() */
 
-struct sockaddr_in	cliaddr, servaddr;
+struct sockaddr_in	cliaddr4, servaddr4;
+struct sockaddr_in6	cliaddr6, servaddr6;
 
 static void	usage(const char *);
 
@@ -90,13 +92,16 @@ main(int argc, char *argv[])
 		usage("");
 
 	opterr = 0;		/* don't want getopt() writing to stderr */
-	while ( (c = getopt(argc, argv, "2b:cf:g:hij:kl:n:op:q:r:st:uvw:x:y:ABCDEFG:H:IJ:KL:NO:P:Q:R:S:TU:VWX:YZ")) != -1) {
+	while ( (c = getopt(argc, argv, "26b:cf:g:hij:kl:n:op:q:r:st:uvw:x:y:ABCDEFG:H:IJ:KL:NO:P:Q:R:S:TU:VWX:YZ")) != -1) {
 		switch (c) {
 #ifdef	IP_ONESBCAST
 		case '2':			/* use 255.255.255.255 as broadcast address */
 			onesbcast = 1;
 			break;
 #endif
+		case '6':			/* use IPv6 */
+			af_46 = AF_INET6;
+			break;
 
 		case 'b':
 			bindport = atoi(optarg);
@@ -309,7 +314,7 @@ main(int argc, char *argv[])
 		}
 	}
 
-		/* check for options that don't make sense */
+	/* check for options that don't make sense */
 	if (udp && halfclose)
 		usage("can't specify -h and -u");
 	if (udp && debug)
@@ -439,6 +444,7 @@ usage(const char *msg)
 #ifdef	IP_ONESBCAST
 "         -2    IP_ONESBCAST option (255.255.255.255 for broadcast\n"
 #endif
+"         -6    use IPv6 instead of IPv4\n"
 );
 
 	if (msg[0] != 0)
