--- sf.c.orig	Mon Dec 21 08:18:55 1998
+++ sf.c	Sat Nov  8 21:20:24 2003
@@ -47,6 +47,7 @@
 
 struct option long_options[] =
 {
+  { "version",          0, 0, c_VERSION          },
   { "view-geometry",    1, 0, c_VIEW_GEOMETRY    },
   { "control-geometry", 1, 0, c_CONTROL_GEOMETRY },
   { "minimize",         0, 0, c_MINIMIZE         },
@@ -77,6 +78,8 @@
 
 help_info_line help_info[] =
 {
+  { "version",          c_VERSION,          " ",
+    "show program version"  },
   { "view-geometry",    c_VIEW_GEOMETRY,    "+x+y",
     "Control window placement" },
   { "control-geometry", c_CONTROL_GEOMETRY, "+x+y",
@@ -134,7 +137,7 @@
 
 /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
 
-void main( int argc,char* argv[] )
+int main( int argc,char* argv[] )
 {
   int   i;
   char* shop;
@@ -175,7 +178,14 @@
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
