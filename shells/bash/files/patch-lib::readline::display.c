#
# Fix handling of `read -e' while PS1 is set longer than the screen width
#
# http://lists.gnu.org/archive/html/bug-bash/2004-11/msg00220.html
# http://lists.gnu.org/archive/html/bug-bash/2004-11/msg00266.html
#
--- lib/readline/display.c.orig	2004-11-18 16:24:46.000000000 +0000
+++ lib/readline/display.c	2004-11-18 17:12:32.904903404 +0000
@@ -572,11 +572,10 @@
 
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
