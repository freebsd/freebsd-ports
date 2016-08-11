--- progs/mincdump/mincdump.c.orig	2012-09-24 17:35:36 UTC
+++ progs/mincdump/mincdump.c
@@ -553,7 +553,7 @@ do_ncdump(char *path, struct fspec* spec
 static void
 set_brief(struct fspec * fspecp, char *key, char *optarg)
 {
-    fspecp->brief_data_cmnts = true;
+    fspecp->brief_data_cmnts = my_true;
     switch (tolower(optarg[0])) {
     case 'c':
         fspecp->data_lang = LANG_C;
@@ -569,7 +569,7 @@ set_brief(struct fspec * fspecp, char *k
 static void
 set_full(struct fspec * fspecp, char *key, char *optarg)
 {
-    fspecp->full_data_cmnts = true;
+    fspecp->full_data_cmnts = my_true;
     switch (tolower(optarg[0])) {
     case 'c':
         fspecp->data_lang = LANG_C;
@@ -688,10 +688,10 @@ main(int argc, char *argv[])
     static struct fspec fspec =	/* defaults, overridden on command line */
       {
 	  0,			/* construct netcdf name from file name */
-	  false,		/* print header info only, no data? */
-	  false,		/* just print coord vars? */
-	  false,		/* brief  comments in data section? */
-	  false,		/* full annotations in data section?  */
+	  my_false,		/* print header info only, no data? */
+	  my_false,		/* just print coord vars? */
+	  my_false,		/* brief  comments in data section? */
+	  my_false,		/* full annotations in data section?  */
 	  LANG_C,		/* language conventions for indices */
 	  0,			/* if -v specified, number of variables */
 	  0			/* if -v specified, list of variable names */
@@ -701,13 +701,13 @@ main(int argc, char *argv[])
     static ArgvInfo argTable[] = {
         {"-b", ARGV_FUNC, (char *) set_brief, (char *) &fspec,
          "Brief annotations for C or Fortran indices in data" },
-        {"-c", ARGV_CONSTANT, (char *) true, (char *) &fspec.coord_vals,
+        {"-c", ARGV_CONSTANT, (char *) my_true, (char *) &fspec.coord_vals,
          "Coordinate variable data and header information" },
         {"-d", ARGV_FUNC, (char *) set_sigdigs, (char *) NULL,
          "Obsolete option for setting significant digits" },
         {"-f", ARGV_FUNC, (char *) set_full, (char *) &fspec,
          "Full annotations for C or Fortran indices in data" },
-        {"-h", ARGV_CONSTANT, (char *) true, (char *) &fspec.header_only, 
+        {"-h", ARGV_CONSTANT, (char *) my_true, (char *) &fspec.header_only, 
          "Header information only, no data" }, 
         {"-l", ARGV_INT, (char *) 1, (char *) &max_len, 
          "Line length maximum in data section (default 80)" },
