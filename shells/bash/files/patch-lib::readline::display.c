--- lib/readline/display.c.orig	2009-01-04 11:32:32.000000000 -0800
+++ lib/readline/display.c	2009-03-08 00:51:31.000000000 -0800
@@ -654,5 +654,8 @@ rl_redisplay ()
   /* inv_lbreaks[i] is where line i starts in the buffer. */
   inv_lbreaks[newlines = 0] = 0;
+  if (local_prompt)
   lpos = prompt_physical_chars + modmark;
+  else
+    lpos = 0;
 
 #if defined (HANDLE_MULTIBYTE)
