--- config-bot.h.orig	Sun Aug 25 20:34:26 2002
+++ config-bot.h	Sun Aug 25 20:38:07 2002
@@ -108,7 +108,10 @@
 #  include <wchar.h>
 #  include <wctype.h>
 #  if defined (HAVE_MBSRTOWCS) /* system is supposed to support XPG5 */
+/*
+	FreeBSD lies...
 #    define HANDLE_MULTIBYTE      1
+*/
 #  endif
 #endif
 
