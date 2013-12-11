$OpenBSD: patch-args_c,v 1.3 2002/11/13 17:15:49 naddy Exp $
--- args.c.orig	Thu Oct 17 07:22:48 2002
+++ args.c	Mon Nov 11 05:43:01 2002
@@ -35,6 +35,7 @@ do_args(int argc, char **argv, int envfl
     int consumed;
     int currarg;
     int opterrors;
+    size_t len;
 
     int i;
 
@@ -142,18 +143,17 @@ do_args(int argc, char **argv, int envfl
                         break;
                 case 'C':    /* select character definitions */
                         consumed = 1;
+                        len = (strlen(libdir) + strlen(optstr) + 2);
                         if (*++optstr) { /* did we get a encoding name ? */
-                            if ((charvec_file = (char *) malloc(strlen(libdir) +
-                                                                strlen(optstr) +
-                                                                2)) == NULL) {
+                            if ((charvec_file = (char *) malloc(len)) == NULL) {
                                 perror(optstr);
                                 fprintf(stderr,
                                     "ignoring character encoding definition\n");
                             }
                             else {
-                                (void) strcpy(charvec_file, libdir);
-                                (void) strcat(charvec_file, "/");
-                                (void) strcat(charvec_file, optstr);
+                                (void) strlcpy(charvec_file, libdir, len);
+                                (void) strlcat(charvec_file, "/", len);
+                                (void) strlcat(charvec_file, optstr, len);
                                 opt_encoding = 1;
                             }
                         }
