#
# Fix line wraps
# http://lists.gnu.org/archive/html/bug-bash/2004-08/msg00325.html
#
--- lib/readline/display.c.orig	Wed Sep  1 18:28:21 2004
+++ lib/readline/display.c	Wed Sep  1 18:29:18 2004
@@ -351,14 +351,14 @@
       local_prompt = expand_prompt (p, &prompt_visible_length,
 				       &prompt_last_invisible,
 				       (int *)NULL,
-				       (int *)NULL);
+				       &prompt_physical_chars);
       c = *t; *t = '\0';
       /* The portion of the prompt string up to and including the
 	 final newline is now null-terminated. */
       local_prompt_prefix = expand_prompt (prompt, &prompt_prefix_length,
 						   (int *)NULL,
 						   &prompt_invis_chars_first_line,
-						   &prompt_physical_chars);
+						   (int *)NULL);
       *t = c;
       return (prompt_prefix_length);
     }
