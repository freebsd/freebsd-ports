--- console/tidy.c.orig	Sat Mar  6 08:59:12 2004
+++ console/tidy.c	Fri Mar 12 18:16:30 2004
@@ -505,6 +505,9 @@
             else if ( strcasecmp(arg, "quiet") == 0 )
                 tidyOptSetBool( tdoc, TidyQuiet, yes );
 
+            else if ( strcasecmp(arg, "preserve") == 0 ) /* NOOP for docproj */
+                printf( errout, "Warning: tidy-devel does not honour the -preserve flag\n");
+
             else if ( strcasecmp(arg, "help") == 0 ||
                       strcasecmp(arg,    "h") == 0 || *arg == '?' )
             {
