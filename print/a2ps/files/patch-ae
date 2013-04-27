--- lib/options.c.orig	Thu Sep 21 23:22:36 2000
+++ lib/options.c	Thu Sep 21 23:22:42 2000
@@ -493,6 +493,15 @@
 	  /* A font size is given */
 	  job->fontsize = get_length ("--font-size", cp,
 				      0.0, 0.0, "pt", range_min_strict);
+	  if (job->fontsize == 0.0) 
+	  {
+	    error (0, 0, _("invalid argument %s for -f or --font-size option"),
+	      cp);
+	    fprintf (stderr,
+	      _("Valid arguments are floats with optonal units!\n"));
+	    fprintf (stderr, _("Try `a2ps --help' for more information.\n"));
+	    exit (EXIT_FAILURE);
+	  }
 	  job->columns_requested = 0;
 	  job->lines_requested = 0;
 	}
