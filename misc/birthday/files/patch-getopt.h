--- getopt.h	Thu Apr  4 19:15:06 2002
+++ getopt.h	Thu Apr  4 19:15:32 2002
@@ -93,15 +93,22 @@
   optional_argument
 };
 
+
+// Note: FreeBSD does follow the normal GNU definition for getopt, but
+// the checks below would cause it to use a new --conflicting-- definition.
+// Therefore, the checks have been commented out.
+//
+// Niek Bergboer, 04-Apr-2002
+
 #if __STDC__
-#if defined(__GNU_LIBRARY__)
+//#if defined(__GNU_LIBRARY__)
 /* Many other libraries have conflicting prototypes for getopt, with
    differences in the consts, in stdlib.h.  To avoid compilation
    errors, only prototype getopt for the GNU C library.  */
 extern int getopt (int argc, char *const *argv, const char *shortopts);
-#else /* not __GNU_LIBRARY__ */
-extern int getopt ();
-#endif /* not __GNU_LIBRARY__ */
+//#else /* not __GNU_LIBRARY__ */
+//extern int getopt ();
+//#endif /* not __GNU_LIBRARY__ */
 extern int getopt_long (int argc, char *const *argv, const char *shortopts,
 		        const struct option *longopts, int *longind);
 extern int getopt_long_only (int argc, char *const *argv,
