--- src/tools/netkey-tool.c.orig	2023-03-24 14:58:28 UTC
+++ src/tools/netkey-tool.c
@@ -443,13 +443,12 @@ int main(
 	int do_help=0, do_unblock=0, do_change=0, do_nullpin=0, do_readcert=0, do_writecert=0;
 	u8 newpin[32];
 	char *certfile=NULL, *p;
-	int r, oerr=0, reader=0, debug=0, pin_nr=-1, cert_nr=-1;
+	int r, oerr=0, reader=0, pin_nr=-1, cert_nr=-1;
 	size_t i, newlen=0;
 
-	while ((r = getopt_long(argc, argv, "hvr:p:u:0:1:", options, NULL)) != -1) {
+	while ((r = getopt_long(argc, argv, "hr:p:u:0:1:", options, NULL)) != -1) {
 		switch (r) {
 		case 'h': ++do_help; break;
-		case 'v': ++debug; break;
 		case 'r': reader=atoi(optarg); break;
 		case 'p': set_pin(pinlist[0].value, &pinlist[0].len, optarg); break;
 		case 'u': set_pin(pinlist[1].value, &pinlist[1].len, optarg); break;
@@ -462,7 +461,6 @@ int main(
 		fprintf(stderr,"This is netkey-tool V1.0, May 15 2005, Copyright Peter Koch <pk_opensc@web.de>\n");
 		fprintf(stderr,"usage: %s <options> command\n", argv[0]);
 		fprintf(stderr,"\nOptions:\n");
-		fprintf(stderr,"  -v                       : verbose, may be specified several times\n");
 		fprintf(stderr,"  --reader <num>, -r <num> : use reader num (default 0)\n");
 		fprintf(stderr,"  --pin <pin>, -p <pin>    : current value of global PIN\n");
 		fprintf(stderr,"  --puk <pin>, -u <pin>    : current value of global PUK\n");
