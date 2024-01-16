--- vobcopy.c.orig	2022-05-03 19:55:34 UTC
+++ vobcopy.c
@@ -25,7 +25,7 @@
  * rosenauer@users.sf.net - helped me a lot! 
  * Billy Biggs <vektor@dumbterm.net> - took some of his play_title.c code 
  * and implemeted it here 
- * Håkan Hjort <d95hjort@dtek.chalmers.se> and Billy Biggs - libdvdread
+ * HÃ¥kan Hjort <d95hjort@dtek.chalmers.se> and Billy Biggs - libdvdread
  * Stephen Birch <sgbirch@imsmail.org> - debian packaging
  */
 
@@ -160,7 +160,7 @@ and potentially fatal."  - Thanks Leigh!*/
 #if defined( __gettext__ )
   setlocale(LC_ALL, "");
   textdomain("vobcopy");
-  bindtextdomain("vobcopy", "/usr/share/locale");
+  bindtextdomain("vobcopy", "/usr/local/share/locale");
 #endif
 
   /* initialize string */
@@ -1205,7 +1205,7 @@ next: /*for the goto - ugly, I know... */
                   fprintf( stderr, _("\n"));
                   if( !stdout_flag )
                     {
-                      if( fdatasync( streamout ) < 0 )
+                      if( fsync( streamout ) < 0 )
                         {
                           fprintf( stderr, _("\n[Error] error writing to %s \n"), output_file );
                           fprintf( stderr, _("[Error] error: %s\n"), strerror( errno ) );
@@ -1241,7 +1241,7 @@ next: /*for the goto - ugly, I know... */
                   fprintf( stderr, _("\n"));
                   if( !stdout_flag )
                     {
-                      if( fdatasync( streamout ) < 0 )
+                      if( fsync( streamout ) < 0 )
                         {
                           fprintf( stderr, _("\n[Error] error writing to %s \n"), output_file );
                           fprintf( stderr, _("[Error] error: %s\n"), strerror( errno ) );
@@ -1389,7 +1389,7 @@ next: /*for the goto - ugly, I know... */
                   fprintf( stderr, _("\n") );
                   if( !stdout_flag )
                     {
-                      if( fdatasync( streamout ) < 0 )
+                      if( fsync( streamout ) < 0 )
                         {
                           fprintf( stderr, _("\n[Error] error writing to %s \n"), output_file );
                           fprintf( stderr, _("[Error] error: %s\n"), strerror( errno ) );
@@ -1421,6 +1421,8 @@ next: /*for the goto - ugly, I know... */
 
 
 
+   /* initialize string */
+   dvd_path[0] = '\0';
 
   /*
    * Open now up the actual files for reading
@@ -1847,7 +1849,7 @@ The man replies, "I was talking to the sheep."
         }
       if( !stdout_flag )
         {
-          if( fdatasync( streamout ) < 0 )
+          if( fsync( streamout ) < 0 )
             {
               fprintf( stderr, _("\n[Error] error writing to %s \n"), name );
               fprintf( stderr, _("[Error] error: %s\n"), strerror( errno ) );
