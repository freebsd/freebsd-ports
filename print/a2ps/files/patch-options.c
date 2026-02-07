--- liba2ps/options.c.orig	2023-03-19 17:22:01 UTC
+++ liba2ps/options.c
@@ -463,6 +463,15 @@ a2ps_handle_options (a2ps_job * job, int argc, char *a
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
