--- netcat.c.orig	Tue Feb 19 23:42:04 2002
+++ netcat.c	Wed Jul 30 11:41:11 2003
@@ -37,6 +37,9 @@
 #include <sys/un.h>
 
 #include <netinet/in.h>
+#ifdef IPSEC
+#include <netinet6/ipsec.h>
+#endif
 #include <arpa/telnet.h>
 
 #include <err.h>
@@ -53,10 +56,12 @@
 #define PORT_MAX 65535
 
 /* Command Line Options */
+int	Eflag;					/* Use IPsec ESP */
 int	iflag;					/* Interval Flag */
 int	kflag;					/* More than one connect */
 int	lflag;					/* Bind to local port */
 int	nflag;					/* Dont do name lookup */
+int	oflag;					/* Once only: stop on EOF */
 char   *pflag;					/* Localport flag */
 int	rflag;					/* Random ports flag */
 char   *sflag;					/* Source Address */
@@ -84,10 +89,16 @@
 int	unix_listen(char *);
 void	usage(int);
 
+#ifdef IPSEC
+void	add_ipsec_policy(int, char *);
+
+char	*ipsec_policy[2];
+#endif
+
 int
 main(int argc, char *argv[])
 {
-	int ch, s, ret;
+	int ch, s, ret, ipsec_count;
 	char *host, *uport, *endp;
 	struct addrinfo hints;
 	struct servent *sv;
@@ -99,12 +110,13 @@
 
 	ret = 1;
 	s = 0;
+	ipsec_count = 0;
 	host = NULL;
 	uport = NULL;
 	endp = NULL;
 	sv = NULL;
 
-	while ((ch = getopt(argc, argv, "46Uhi:klnp:rs:tuvw:x:z")) != -1) {
+	while ((ch = getopt(argc, argv, "46e:EUhi:klnop:rs:tuvw:x:z")) != -1) {
 		switch (ch) {
 		case '4':
 			family = AF_INET;
@@ -115,6 +127,21 @@
 		case 'U':
 			family = AF_UNIX;
 			break;
+		case 'e':
+#ifdef IPSEC
+			ipsec_policy[ipsec_count++ % 2] = optarg;
+#else
+			errx(1, "IPsec support unavailable.");
+#endif
+			break;
+		case 'E':
+#ifdef IPSEC
+			ipsec_policy[0] = "in  ipsec esp/transport//require";
+			ipsec_policy[1] = "out ipsec esp/transport//require";
+#else
+			errx(1, "IPsec support unavailable.");
+#endif
+			break;
 		case 'h':
 			help();
 			break;
@@ -132,6 +159,9 @@
 		case 'n':
 			nflag = 1;
 			break;
+		case 'o':
+			oflag = 1;
+			break;
 		case 'p':
 			pflag = optarg;
 			break;
@@ -422,6 +452,12 @@
 		if ((s = socket(res0->ai_family, res0->ai_socktype,
 		    res0->ai_protocol)) < 0)
 			continue;
+#ifdef IPSEC
+		if (ipsec_policy[0] != NULL)
+			add_ipsec_policy(s, ipsec_policy[0]);
+		if (ipsec_policy[1] != NULL)
+			add_ipsec_policy(s, ipsec_policy[1]);
+#endif
 
 		/* Bind to a local port or source address if specified */
 		if (sflag || pflag) {
@@ -497,6 +533,12 @@
 		ret = setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &x, sizeof(x));
 		if (ret == -1)
 			err(1, NULL);
+#ifdef IPSEC
+		if (ipsec_policy[0] != NULL)
+			add_ipsec_policy(s, ipsec_policy[0]);
+		if (ipsec_policy[1] != NULL)
+			add_ipsec_policy(s, ipsec_policy[1]);
+#endif
 
 		if (bind(s, (struct sockaddr *)res0->ai_addr,
 		    res0->ai_addrlen) == 0)
@@ -561,7 +603,8 @@
 		}
 
 		if (pfd[1].revents & POLLIN) {
-			if ((n = read(wfd, buf, sizeof(buf))) < 0) {
+			if ((n = read(wfd, buf, sizeof(buf))) < 0 ||
+			    (oflag && n == 0)) {
 				return;
 			} else
 				if((ret = atomicio(write, nfd, buf, n)) != n)
@@ -690,7 +733,13 @@
 	usage(0);
 	fprintf(stderr, "\tCommand Summary:\n\
 	\t-4		Use IPv4\n\
-	\t-6		Use IPv6\n\
+	\t-6		Use IPv6\n");
+#ifdef IPSEC
+	fprintf(stderr, "\
+	\t-e policy	Use specified IPsec policy\n\
+	\t-E		Use IPsec ESP\n");
+#endif
+	fprintf(stderr, "\
 	\t-U		Use UNIX domain socket\n\
 	\t-h		This help text\n\
 	\t-i secs\t	Delay interval for lines sent, ports scanned\n\
@@ -707,13 +756,42 @@
 	\t-x addr[:port]\tSpecify socks5 proxy address and port\n\
 	\t-z		Zero-I/O mode [used for scanning]\n\
 	Port numbers can be individual or ranges: lo-hi [inclusive]\n");
+#ifdef IPSEC
+	fprintf(stderr, "See ipsec_set_policy(3) for -e argument format\n");
+#endif
 	exit(1);
 }
 
+#ifdef IPSEC
+void
+add_ipsec_policy(int s, char *policy)
+{
+	char *raw;
+	int e;
+
+	raw = ipsec_set_policy(policy, strlen(policy));
+	if (raw == NULL)
+		errx(1, "ipsec_set_policy `%s': %s", policy,
+		    ipsec_strerror());
+	e = setsockopt(s, IPPROTO_IP, IP_IPSEC_POLICY, raw,
+	    ipsec_get_policylen(raw));
+	if (e < 0)
+		err(1, "ipsec policy cannot be configured");
+	free(raw);
+	if (vflag)
+		fprintf(stderr, "ipsec policy configured: `%s'\n", policy);
+	return;
+}
+#endif /* IPSEC */
+
 void
 usage(int ret)
 {
+#ifdef IPSEC
+	fprintf(stderr, "usage: nc [-46EUhklnrtuvz] [-e policy] [-i interval] [-p source port]\n");
+#else
 	fprintf(stderr, "usage: nc [-46Uhklnrtuvz] [-i interval] [-p source port]\n");
+#endif
 	fprintf(stderr, "\t  [-s ip address] [-w timeout] [-x proxy address [:port]]\n");
 	fprintf(stderr, "\t  [hostname] [port[s...]]\n");
 	if (ret)
