Fixes compile issue
Supposedly DT_* is not defined, though header file
exists. 

--- nbd-server.c.orig	2018-08-28 16:46:42 UTC
+++ nbd-server.c
@@ -678,13 +678,9 @@ SERVER* cmdline(int argc, char *argv[], struct generic
 /* forward definition of parse_cfile */
 GArray* parse_cfile(gchar* f, struct generic_conf *genconf, bool expect_generic, GError** e);
 
-#ifdef HAVE_STRUCT_DIRENT_D_TYPE
-#define NBD_D_TYPE de->d_type
-#else
 #define NBD_D_TYPE 0
 #define DT_UNKNOWN 0
 #define DT_REG 1
-#endif
 
 /**
  * Parse config file snippets in a directory. Uses readdir() and friends
