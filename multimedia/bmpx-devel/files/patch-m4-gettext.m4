--- m4/gettext.m4.orig	Sat Sep  9 14:56:32 2006
+++ m4/gettext.m4	Sat Sep  9 14:57:19 2006
@@ -172,7 +172,7 @@
 #ifdef __cplusplus
 "C"
 #endif
-const char *_nl_expand_alias ();],
+const char *_nl_expand_alias (const char *);],
               [bindtextdomain ("", "");
 return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_expand_alias (0)],
               gt_cv_func_gnugettext_libintl=yes,
@@ -193,7 +193,7 @@
 #ifdef __cplusplus
 "C"
 #endif
-const char *_nl_expand_alias ();],
+const char *_nl_expand_alias (const char *);],
                 [bindtextdomain ("", "");
 return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_expand_alias (0)],
                [LIBINTL="$LIBINTL $LIBICONV"
