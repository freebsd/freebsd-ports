--- netcat.c.orig	Wed Jun 27 02:23:58 2001
+++ netcat.c	Fri Oct 19 07:31:54 2001
@@ -36,6 +36,9 @@
 #include <sys/time.h>
 
 #include <netinet/in.h>
+#ifdef IPSEC
+#include <netinet6/ipsec.h>
+#endif
 #include <arpa/telnet.h>
 
 #include <err.h>
@@ -51,6 +54,7 @@
 #define PORT_MAX 65535
 
 /* Command Line Options */
+int	Eflag;					/* Use IPsec ESP */
 int	iflag;					/* Interval Flag */
 int	kflag;					/* More than one connect */
 int	lflag;					/* Bind to local port */
@@ -77,12 +81,18 @@
 int	udptest __P((int));
 void	usage __P((int));
 
+#ifdef IPSEC
+void	add_ipsec_policy __P((int, const char *));
+
+char	*ipsec_policy[2];
+#endif
+
 int
 main(argc, argv)
 	int argc;
 	char *argv[];
 {
-	int ch, s, ret;
+	int ch, s, ret, ipsec_count;
 	char *host, *uport, *endp;
 	struct addrinfo hints;
 	struct servent *sv;
@@ -91,12 +101,13 @@
 
 	ret = 1;
 	s = 0;
+	ipsec_count = 0;
 	host = NULL;
 	uport = NULL;
 	endp = NULL;
 	sv = NULL;
 
-	while ((ch = getopt(argc, argv, "46hi:klnp:rs:tuvw:z")) != -1) {
+	while ((ch = getopt(argc, argv, "46e:Ehi:klnp:rs:tuvw:z")) != -1) {
 		switch (ch) {
 		case '4':
 			family = AF_INET;
@@ -104,6 +115,21 @@
 		case '6':
 			family = AF_INET6;
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
@@ -295,6 +321,12 @@
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
@@ -372,6 +404,12 @@
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
@@ -571,7 +609,13 @@
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
 	\t-h		This help text\n\
 	\t-i secs\t	Delay interval for lines sent, ports scanned\n\
 	\t-k		Keep inbound sockets open for multiple connects\n\
@@ -586,14 +630,43 @@
 	\t-w secs\t	Timeout for connects and final net reads\n\
 	\t-z		Zero-I/O mode [used for scanning]\n\
 	Port numbers can be individual or ranges: lo-hi [inclusive]\n");
+#ifdef IPSEC
+	fprintf(stderr, "See ipsec_set_policy(3) for -e argument format\n");
+#endif
 	exit(1);
 }
 
+#ifdef IPSEC
+void
+add_ipsec_policy(int s, const char *policy)
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
 usage(ret)
 	int ret;
 {
+#ifdef IPSEC
+	fprintf(stderr, "usage: nc [-46Ehklnrtuvz] [-e policy] [-i interval] [-p source port]\n");
+#else
 	fprintf(stderr, "usage: nc [-46hklnrtuvz] [-i interval] [-p source port]\n");
+#endif
 	fprintf(stderr, "\t  [-s ip address] [-w timeout] [hostname] [port[s...]]\n");
 	if (ret)
 		exit(1);
