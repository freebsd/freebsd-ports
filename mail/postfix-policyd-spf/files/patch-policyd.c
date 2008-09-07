--- policyd.c.orig	2004-07-09 06:42:25.000000000 +0900
+++ policyd.c	2008-06-23 12:55:02.000000000 +0900
@@ -70,12 +70,14 @@
 
 #define POSTFIX_DUNNO	"DUNNO"
 #define POSTFIX_REJECT	"REJECT"
+#define POSTFIX_PREPEND	"PREPEND"
 
 typedef
 struct _config_t {
 	char	*localpolicy;
 	char	*explanation;
 	int		 trustedforwarder;
+	int		 softfailreject;
 	int		 debug;
 } config_t;
 
@@ -106,6 +108,7 @@
 static const struct option	longopts[] = {
 		{ "localpolicy",		required_argument,	NULL, 'l', },
 		{ "trustedforwarder",	no_argument,		NULL, 't', },
+		{ "softfailreject",	no_argument,		NULL, 's', },
 		{ "explanation",		required_argument,	NULL, 'x', },
 		{ "debug",				optional_argument,	NULL, 'd', },
 		{ "help",				no_argument,		NULL, 'h', },
@@ -119,7 +122,7 @@
 #else
 #define DOC_LONGOPT(l, v, t, p1) do { } while(0)
 #endif
-static const char	*shortopts = "a:h";
+static const char	*shortopts = "l:x:d:tsh";
 
 #define DOC_OPT(s, l, v, t, p0, p1) do { \
 		fprintf(stderr, "    -%c%c%s%*s" t "\n", \
@@ -137,10 +140,12 @@
 			"Set the SPF local policy.", 21, 10);
 	DOC_OPT('t', "trustedforwarder", NULL,
 			"Use the trusted-forwarder.com whitelist.", 29, 13);
+	DOC_OPT('s', "softfailreject", NULL,
+			"Reject SOFTFAIL.", 29, 15);
 	DOC_OPT('x', "explanation", "<explanation>",
 			"Set the SPF explanation.", 16, 5);
-	DOC_OPT('d', "debug", "[<level>]",
-			"Set the debug level.", 20, 15);
+	DOC_OPT('d', "debug", "<level>",
+			"Set the debug level.", 22, 17);
 	DOC_OPT('h', "help", NULL,
 			"Display this help.", 29, 25);
 }
@@ -249,7 +254,7 @@
 }
 
 static void
-process_request(request_t *req)
+process_request(request_t *req, config_t *conf)
 {
 	SPF_output_t	output;
 
@@ -268,7 +273,7 @@
 
 	switch (output.result) {
 		case SPF_RESULT_PASS:
-			strcpy(req->result, POSTFIX_DUNNO);
+			snprintf(req->result, RESULTSIZE, POSTFIX_PREPEND " %s", output.received_spf);
 			break;
 		case SPF_RESULT_FAIL:
 			snprintf(req->result, RESULTSIZE,
@@ -287,11 +292,21 @@
 								: ""));
 			break;
 		case SPF_RESULT_SOFTFAIL:
+			if (conf->softfailreject == 1) {
+				snprintf(req->result, RESULTSIZE,
+							POSTFIX_REJECT " %s",
+							(output.smtp_comment
+								? output.smtp_comment
+								: (output.header_comment
+									? output.header_comment
+									: "")));
+				break;
+			}
 		case SPF_RESULT_NEUTRAL:
 		case SPF_RESULT_UNKNOWN:
 		case SPF_RESULT_NONE:
 		default:
-			strcpy(req->result, POSTFIX_DUNNO);
+			snprintf(req->result, RESULTSIZE, POSTFIX_PREPEND " %s", output.received_spf);
 			break;
 	}
 
@@ -315,6 +330,11 @@
 		argv0 = argv[0];
 
 
+	config.localpolicy = NULL;
+	config.explanation = NULL;
+	config.trustedforwarder = 0;
+	config.softfailreject = 0;
+	config.debug = 0;
 	while ((c =
 #ifdef HAVE_GETOPT_LONG
 		getopt_long(argc, argv, shortopts, longopts, &idx)
@@ -329,12 +349,15 @@
 			case 't':
 				config.trustedforwarder = 1;
 				break;
+			case 's':
+				config.softfailreject = 1;
+				break;
 			case 'x':
 				config.explanation = optarg;
 				break;
 			case 'd':
 				if (optarg)
-					config.debug = atol(optarg);
+					config.debug = atoi(optarg);
 				else
 					config.debug = 1;
 				break;
@@ -366,7 +389,7 @@
 		CHECK(req.client_ip, "client_address")
 		else CHECK(req.sender_address, "sender")
 		else CHECK(req.helo_address, "helo_name")
-		else process_request(&req);
+		else process_request(&req, &config);
 
 		req.result[RESULTSIZE - 1] = '\0';
 		printf("action=%s\n\n", req.result);
