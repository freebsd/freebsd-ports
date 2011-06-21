--- ./findkey.c.orig	2003-01-01 16:49:51.000000000 +0100
+++ ./findkey.c	2011-06-21 16:03:11.000000000 +0200
@@ -56,7 +56,7 @@
     exit( 1 );
 }
 
-void main( int argc, char **argv )
+int main( int argc, char **argv )
 {
 uword	key0, key1, key2;
 int	pwdLen=0;
@@ -81,4 +81,6 @@
 	findLongPwd( key0, key1, key2, pwdLen, initBytes );
     else
 	findPwd( key0, key1, key2 );
+
+    return(0);
 }
