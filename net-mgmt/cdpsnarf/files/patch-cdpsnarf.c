--- cdpsnarf.c.orig	2016-02-05 16:29:16 UTC
+++ cdpsnarf.c
@@ -194,11 +194,6 @@ int main( int argc, char *argv[] ) {
     int i = 0;
    
     printf( "CDPSnarf %s [%s] initiated.\n", VERSION, SVN_REV );
-    printf( "   Author: Anastasios \"Zapotek\" Laskos\n" );
-    printf( "             <tasos.laskos@gmail.com>\n" );
-    printf( "                <zapotek@segfault.gr>\n" );
-    printf( "   Website: http://www.segfault.gr\n" );
-    printf( "            http://github.com/Zapotek/cdpsnarf\n\n" );
     
     // get command line arguments
     while( ( c = getopt( argc, argv, "i:dhw:r:" ) ) != -1 ) {
