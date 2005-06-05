--- watch.c.orig	Sat Jun  4 02:34:34 2005
+++ watch.c	Sat Jun  4 02:34:38 2005
@@ -147,6 +147,13 @@
 	setlocale(LC_ALL, "");
 	progname = argv[0];
 
+	float
+	strtof(const char * restrict nptr, char ** restrict endptr)
+	{
+	
+		return ((float)strtod(nptr, endptr));
+	}
+
 	while ((optc = getopt_long(argc, argv, "+d::hn:vt", longopts, (int *) 0))
 	       != EOF) {
 		switch (optc) {
