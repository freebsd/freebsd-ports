--- lib/readline/display.c.orig	2025-05-02 13:20:32 UTC
+++ lib/readline/display.c
@@ -999,7 +999,10 @@ rl_redisplay (void)
      the line breaks in the prompt string in expand_prompt, taking invisible
      characters into account, and if lpos exceeds the screen width, we copy
      the data in the loop below. */
-  lpos = local_prompt ? prompt_physical_chars + modmark : 0;
+  if (local_prompt)
+	  lpos = local_prompt ? prompt_physical_chars + modmark : 0;
+  else
+	  lpos = 0;
 
 #if defined (HANDLE_MULTIBYTE)
   memset (line_state_invisible->wrapped_line, 0, line_state_invisible->wbsize * sizeof (int));
