
$FreeBSD$

--- subst.c.orig	Mon Nov  5 20:19:49 2001
+++ subst.c	Tue Nov 20 23:52:45 2001
@@ -121,6 +121,9 @@
    a null file. */
 int allow_null_glob_expansion;
 
+/* Non-zero means to signal an error when globbing fails to match. */
+int fail_glob_expansion;
+
 #if 0
 /* Variables to keep track of which words in an expanded word list (the
    output of expand_word_list_internal) are the result of globbing
@@ -6132,6 +6135,11 @@
 	    {
 	      output_list = (WORD_LIST *)list_append (glob_list, output_list);
 	      PREPEND_LIST (tlist, disposables);
+	    }
+	  else if (fail_glob_expansion != 0)
+	    {
+	      report_error ("no match: %s", tlist->word->word);
+	      jump_to_top_level (DISCARD);
 	    }
 	  else if (allow_null_glob_expansion == 0)
 	    {
