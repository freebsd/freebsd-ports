--- lib/readline/display.c.orig	2016-07-28 18:49:33 UTC
+++ lib/readline/display.c
@@ -743,7 +743,10 @@ rl_redisplay ()
   inv_lbreaks[newlines = 0] = 0;
   /* lpos is a physical cursor position, so it needs to be adjusted by the
      number of invisible characters in the prompt, per line */
+  if (local_prompt)
   lpos = prompt_physical_chars + modmark;
+  else
+    lpos = 0;
 
 #if defined (HANDLE_MULTIBYTE)
   memset (line_state_invisible->wrapped_line, 0, line_state_invisible->wbsize * sizeof (int));
