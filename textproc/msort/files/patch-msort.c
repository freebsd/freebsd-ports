--- msort.c.orig
+++ msort.c
@@ -639,7 +639,6 @@
   char *endptr;			/* Used by strtol */
   char * tmpstr;
   char *FirstLocale = NULL;
-  void *InitialBreak;
   int lgoindex;			/* Unused but needed by getopt_long */
   char t;
 #ifndef USEUTF8PROC
@@ -720,7 +719,6 @@
   xav = av;
   xac = ac;
 
-  InitialBreak = sbrk(0);
 #ifdef HAVE_SETLOCALE
    (void) setlocale(LC_ALL,"");
 #endif
@@ -1946,18 +1944,14 @@
 
   if(LogP) {
 
-    /* Record random number generator seed, dynamic memory usage and number of comparisons */
+    /* Record random number generator seed and number of comparisons */
 #ifdef HAVE_PRINTF_THSEP
-    PrintLog(_("Dynamically allocated memory: %'15d bytes\n"),
-	     ((char *)sbrk(0) - (char *)InitialBreak));
     PrintLog(_("Random number generator seed: %15u\n"),RandomSeed);
 #ifndef NOCOMPARISONCNT
     PrintLog(_("Comparisons:                  %'15llu\n"),ComparisonCnt);
     if(VerboseP) fprintf(stderr,_("Comparisons:                  %'15llu\n"),ComparisonCnt);
 #endif
 #else
-    PrintLog("Dynamically allocated memory: %d bytes\n",
-	     ((char *)sbrk(0) - (char *)InitialBreak));
     PrintLog(_("Random number generator seed: %15u\n"),RandomSeed);
 #ifndef NOCOMPARISONCNT
     PrintLog(_("Comparisons:      %'14llu\n"),ComparisonCnt);
