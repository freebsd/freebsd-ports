--- getopt.c.orig	Thu Jun  5 16:00:34 2003
+++ getopt.c	Thu Jun  5 16:02:34 2003
@@ -66,7 +66,6 @@
 int quiet_errors=0; /* 0 is not quiet. */
 int quiet_output=0; /* 0 is not quiet. */
 int quote=1; /* 1 is do quote. */
-int alternative=0; /* 0 is getopt_long, 1 is getopt_long_only */
 
 /* Function prototypes */
 void *our_malloc(size_t size);
@@ -188,9 +187,7 @@
 		opterr=0;
 	optind=0; /* Reset getopt(3) */
 
-	while ((opt = (alternative?
-	              getopt_long_only(argc,argv,optstr,longopts,&longindex):
-	              getopt_long(argc,argv,optstr,longopts,&longindex))) 
+	while ((opt = getopt_long(argc,argv,optstr,longopts,&longindex)) 
                != EOF) 
 		if (opt == '?' || opt == ':' )
 			exit_code = 1;
@@ -325,7 +322,6 @@
 	fputs(_("       getopt [options] [--] optstring parameters\n"),stderr);
 	fputs(_("       getopt [options] -o|--options optstring [options] [--]\n"),stderr);
 	fputs(_("              parameters\n"),stderr);
-	fputs(_("  -a, --alternative            Allow long options starting with single -\n"),stderr);
 	fputs(_("  -h, --help                   This small usage guide\n"),stderr);
 	fputs(_("  -l, --longoptions=longopts   Long options to be recognized\n"),stderr);
 	fputs(_("  -n, --name=progname          The name under which errors are reported\n"),stderr);
@@ -355,14 +351,13 @@
                                   {"test",no_argument,NULL,'T'},
                                   {"unquoted",no_argument,NULL,'u'},
                                   {"help",no_argument,NULL,'h'},
-                                  {"alternative",no_argument,NULL,'a'},
                                   {"name",required_argument,NULL,'n'},
                                   {"version",no_argument,NULL,'V'},
                                   {NULL,0,NULL,0}
                                 };
 
 /* Stop scanning as soon as a non-option argument is found! */
-static const char *shortopts="+ao:l:n:qQs:TuhV";
+static const char *shortopts="+o:l:n:qQs:TuhV";
 
 int main(int argc, char *argv[])
 {
@@ -405,9 +400,6 @@
 	
 	while ((opt=getopt_long(argc,argv,shortopts,longopts,NULL)) != EOF) 
 		switch (opt) {
-		case 'a':
-			alternative=1;
-			break;
 		case 'h':
 			print_help();
 			exit(0);
