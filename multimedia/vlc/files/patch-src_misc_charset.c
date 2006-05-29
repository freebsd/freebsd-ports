--- src/misc/charset.c.orig	Mon May 29 15:08:35 2006
+++ src/misc/charset.c	Mon May 29 15:09:00 2006
@@ -570,7 +570,9 @@
     /* Some systems (like Darwin, SunOS 4 or DJGPP) have only the C locale.
      * Therefore we don't use setlocale here; it would return "C". */
 #  if HAVE_SETLOCALE && !__APPLE__
+#  if defined LC_ALL
     psz_lang = setlocale( LC_ALL, NULL );
+#  endif
 #  endif
     if( psz_lang == NULL || psz_lang[0] == '\0' )
     {
