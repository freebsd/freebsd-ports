--- console/tidy.c.orig	2008-03-22 20:53:08 UTC
+++ console/tidy.c
@@ -1031,6 +1031,9 @@ int main( int argc, char** argv )
             else if ( strcasecmp(arg, "quiet") == 0 )
                 tidyOptSetBool( tdoc, TidyQuiet, yes );
 
+            else if ( strcasecmp(arg, "preserve") == 0 ) /* NOOP for docproj */
+                printf( errout, "Warning: tidy-devel does not honour the -preserve flag\n");
+
             else if ( strcasecmp(arg, "help") == 0 ||
                       strcasecmp(arg,    "h") == 0 || *arg == '?' )
             {
