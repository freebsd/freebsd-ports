--- ./zdmain.c.orig	2003-01-01 16:49:51.000000000 +0100
+++ ./zdmain.c	2011-06-21 16:03:11.000000000 +0200
@@ -35,7 +35,7 @@
 
 extern void zipdecrypt( char*infile, char*outfile, int k0, int k1, int k2 );
 
-void main( int argc, char **argv )
+int main( int argc, char **argv )
 {
 char *c;
 
@@ -53,8 +53,9 @@
         break;
     default:
         fprintf( stderr, "Usage: %s {<password> | <key0> <key1> <key2>} <cryptedzipfile> <plainzipfile>\n", argv[0] );
-        return;
+        return(0);
     }
 
     zipdecrypt( argv[argc-2], argv[argc-1], key0, key1, key2 );
+    return(0);
 }
