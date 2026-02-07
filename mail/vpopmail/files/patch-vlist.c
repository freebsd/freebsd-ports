Description: Sanity and usage fixes.
 Do not impose an arbitrary limit of 100 list entries.
 Fix the usage message and an error message.
Forwarded: no
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2009-11-26

--- a/vlist.c
+++ b/vlist.c
@@ -44,6 +44,7 @@
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <dirent.h>
+#include <limits.h>
 #include "vpopmail.h"
 #include "config.h"
 
@@ -79,7 +80,7 @@
 
 void usage( int status, char *Message ) {
     printf( "%s\n", Message );
-    printf( "vlist:\n   usage: vlist list_name command \n");
+    printf( "vlist:\n   usage: vlist command1 list_name [command2 [address]]\n");
     printf("\n");
     printf("Commands that affect the entire list\n");
     printf("   vlist count   domain \n");
@@ -222,7 +223,7 @@
     char **Buffer = NULL;
     int I=0;
 
-    Buffer = listList( LI, 1, 100 );
+    Buffer = listList( LI, 1, INT_MAX );
     if( NULL != Buffer ) {
         while( Buffer[I] != NULL ) {
             printf( "%s\n", Buffer[I] );
@@ -630,6 +631,7 @@
     //  Parse the second command   
     //    Note that the strncmp does not check all of the words. 1 or 2 chars is all that is needed.
     if( command1 > 7 ) {
+             if( argc < 3 ) usage( 101, "At least four parameters are required\n");
              if( 0 == strncmp( argv[3], "count",  2 )) command2 = 1;  
         else if( 0 == strncmp( argv[3], "list",   1 )) command2 = 2;  
         else if( 0 == strncmp( argv[3], "add",    2 )) command2 = 3;
