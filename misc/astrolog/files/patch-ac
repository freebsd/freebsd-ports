diff --git astrolog.c astrolog.c
index 5a26c68..8294d3e 100644
--- astrolog.c
+++ astrolog.c
@@ -38,6 +38,7 @@
 ** Modifications from version 5.40 to 5.41 are by Alois Treindl.
 */
 
+#include <ctype.h>
 #include "astrolog.h"
 
 
@@ -255,7 +256,7 @@ byte **argv;
   byte *pch = szLine;
 
   /* Split the entered line up into its individual switch strings. */
-  while (*pch >= ' ' || *pch == chTab) {
+  while (!iscntrl((_char)*pch) || *pch == chTab) {
     if (*pch == ' ' || *pch == chTab) {
       if (fSpace)
         /* Skip over the current run of spaces between strings. */
@@ -1470,8 +1471,18 @@ byte **argv;
     case 'z':
       if (ch1 == '0') {
         if (argc <= 1 || RParseSz(argv[1], pmZon) == rLarge) {
-          i = us.dstDef != 0.0;
-          SwitchF(i);
+	  if (argc > 1 && strcasecmp(argv[1], "current") == 0) {
+	    time_t t;
+	    struct tm *tm;
+
+	    (void) time(&t);
+	    tm = localtime(&t);
+	    i = tm->tm_isdst != 0;
+	    argc--; argv++;
+	  } else {
+	    i = us.dstDef != 0.0;
+	    SwitchF(i);
+	  }
           SS = us.dstDef = i ? 1.0 : 0.0;
         } else {
           SS = us.dstDef = RParseSz(argv[1], pmZon);
@@ -1556,13 +1567,39 @@ byte **argv;
           return fFalse;
         }
         ciCore.nam = SzPersist(argv[1]);
+	if (CchSz(ciCore.nam) > 29) /* see charts1.c */
+	  ciCore.nam[29] = chNull;
+	for (pch = ciCore.nam; *pch; pch++) {
+	  if (*pch == '"') /* see io.c */
+	    *pch = '\'';
+	  else if (iscntrl((_char)*pch)) /* see xgeneral.c */
+	    *pch = ' ';
+	}
         ciCore.loc = SzPersist(argv[2]);
+	if (CchSz(ciCore.loc) > 29) /* see charts1.c */
+	  ciCore.loc[29] = chNull;
+	for (pch = ciCore.loc; *pch; pch++) {
+	  if (*pch == '"') /* see io.c */
+	    *pch = '\'';
+	  else if (iscntrl((_char)*pch)) /* see xgeneral.c */
+	    *pch = ' ';
+	}
         argc -= 2; argv += 2;
         break;
       }
-      if (argc <= 1 || RParseSz(argv[1], pmZon) == rLarge)
-        ZZ -= 1.0;
-      else {
+      if (argc <= 1 || RParseSz(argv[1], pmZon) == rLarge) {
+	if (argc > 1 && strcasecmp(argv[1], "current") == 0) {
+	  time_t t;
+	  struct tm *tm;
+
+	  (void) time(&t);
+	  tm = localtime(&t);
+	  ZZ = us.zonDef = (tm->tm_isdst ? 1 : 0) -
+			   (real)tm->tm_gmtoff/(60*60);
+          argc--; argv++;
+	} else
+	  ZZ -= 1.0;
+      } else {
         ZZ = us.zonDef = RParseSz(argv[1], pmZon);
         if (!FValidZon(us.zonDef)) {
           ErrorValR("z", us.zonDef);
@@ -2213,7 +2250,7 @@ byte **argv;
 #ifdef SWITCHES
 void main(argc, argv)
 int argc;
-byte **argv;
+char **argv;
 {
 #else
 void main()
