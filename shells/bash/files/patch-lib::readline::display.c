#
# Fix handling of `read -e' while PS1 is set longer than the screen width
#
# http://lists.gnu.org/archive/html/bug-bash/2004-11/msg00220.html
# http://lists.gnu.org/archive/html/bug-bash/2004-11/msg00266.html
#
--- lib/readline/display.c.orig	Wed Nov 30 17:05:02 2005
+++ lib/readline/display.c	Wed Dec 28 20:13:15 2005
@@ -594,11 +594,10 @@
 
   /* inv_lbreaks[i] is where line i starts in the buffer. */
   inv_lbreaks[newlines = 0] = 0;
-#if 0
-  lpos = out - wrap_offset;
-#else
-  lpos = prompt_physical_chars + modmark;
-#endif
+  if (local_prompt)
+    lpos = prompt_physical_chars + modmark;
+  else
+    lpos = 0;
 
 #if defined (HANDLE_MULTIBYTE)
   memset (_rl_wrapped_line, 0, vis_lbsize);
