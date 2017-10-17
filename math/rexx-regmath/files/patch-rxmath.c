--- rxmath.c.orig	2001-11-04 22:23:42 UTC
+++ rxmath.c
@@ -116,8 +116,8 @@ static rxfunc(trigfunc1)
     rxstrdup(arg, argv[0]);
 
     /* argument might be in degrees or grades */
-    if (argc > 2) {
-       switch (argv[2].strptr[0]) {
+    if (argc > 1 && argv[1].strptr != NULL) {
+       switch (argv[1].strptr[0]) {
           /* degrees -- convert to radians */
           case 'd':
           case 'D':
@@ -144,7 +144,7 @@ static rxfunc(trigfunc1)
        argval = atof(arg) * PI/180.;
     }
 
-    result->strlength = setresult(result->strptr, theFunc->fnptr(argval), argc - 1, argv+1);
+    result->strlength = setresult(result->strptr, theFunc->fnptr(argval), argc - 2, argv+2);
 
     return 0;
 
@@ -170,8 +170,8 @@ static rxfunc(trigfunc2)
     res = theFunc->fnptr(atof(arg));
 
     /* result could be needed in degrees or grades */
-    if (argc > 2) {
-       switch (argv[2].strptr[0]) {
+    if (argc > 1 && argv[1].strptr != NULL) {
+       switch (argv[1].strptr[0]) {
           /* degrees -- convert radians to degrees */
           case 'd':
           case 'D':
@@ -198,7 +198,7 @@ static rxfunc(trigfunc2)
        res *= 180./PI;
     }
 
-    result->strlength = setresult(result->strptr, res, argc - 1, argv+1);
+    result->strlength = setresult(result->strptr, res, argc - 2, argv+2);
 
     return 0;
 }
