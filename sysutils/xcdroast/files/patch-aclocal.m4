--- aclocal.m4.orig	Sun Oct 26 00:51:41 2003
+++ aclocal.m4	Thu Oct 30 23:28:02 2003
@@ -1367,9 +1367,13 @@
         AC_CACHE_CHECK([for GNU gettext in libc], gt_cv_func_gnugettext_libc,
          [AC_TRY_LINK([#include <libintl.h>
 extern int _nl_msg_cat_cntr;
-extern int *_nl_domain_bindings;],
+extern 
+#ifdef __cplusplus
+"C"
+#endif
+const char *_nl_expand_alias ();],
             [bindtextdomain ("", "");
-return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_domain_bindings],
+return (int) gettext ("")]ifelse([$2], [need-ngettext], [ + (int) ngettext ("", "", 0)], [])[ + _nl_msg_cat_cntr + *_nl_expand_alias (0)],
             gt_cv_func_gnugettext_libc=yes,
             gt_cv_func_gnugettext_libc=no)])
 
