--- include/shmbutil.h.orig	Sun Aug 25 20:35:01 2002
+++ include/shmbutil.h	Sun Aug 25 20:37:01 2002
@@ -34,7 +34,10 @@
 #  include <wchar.h>
 #  include <wctype.h>
 #  if defined (HAVE_MBSRTOWCS) /* system is supposed to support XPG5 */
+/*
+	FreeBSD lies...
 #    define HANDLE_MULTIBYTE      1
+*/
 #  endif
 #endif /* HAVE_WCTYPE_H && HAVE_WCHAR_H */
 
