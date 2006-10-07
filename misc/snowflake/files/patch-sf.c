--- sf.c.orig	Mon Dec 21 00:18:55 1998
+++ sf.c	Sat Oct  7 16:19:50 2006
@@ -23,9 +23,8 @@
 #include <sys/shm.h>
 #include <sys/sem.h>
 
-#include "sf.h"
-
 #include "getopt.h"
+#include "sf.h"
 
 /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
 
@@ -47,6 +46,7 @@
 
 struct option long_options[] =
 {
+  { "version",          0, 0, c_VERSION          },
   { "view-geometry",    1, 0, c_VIEW_GEOMETRY    },
   { "control-geometry", 1, 0, c_CONTROL_GEOMETRY },
   { "minimize",         0, 0, c_MINIMIZE         },
@@ -77,6 +77,8 @@
 
 help_info_line help_info[] =
 {
+  { "version",          c_VERSION,          " ",
+    "show program version"  },
   { "view-geometry",    c_VIEW_GEOMETRY,    "+x+y",
     "Control window placement" },
   { "control-geometry", c_CONTROL_GEOMETRY, "+x+y",
@@ -134,7 +136,7 @@
 
 /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
 
-void main( int argc,char* argv[] )
+int main( int argc,char* argv[] )
 {
   int   i;
   char* shop;
@@ -175,7 +177,14 @@
                  help_info[i].description );
 
       exit( 0 );
-   }
+    }
+    /* asking for version? */
+    if ( ( strncmp( argv[1], "-V",   2 ) == 0 ) ||
+         ( strncmp( argv[1],"--version",3 ) == 0 ) )
+    {
+      printf( "%s - %s\n",program_name,version );
+      exit( 0 );
+    }
   }
 
   /* create shared memory image and mutex */
