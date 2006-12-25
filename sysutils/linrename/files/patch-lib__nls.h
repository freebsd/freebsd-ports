--- ./lib/nls.h.orig	Thu Jul  4 23:03:26 2002
+++ ./lib/nls.h	Mon Dec 25 14:54:11 2006
@@ -1,7 +1,5 @@
 int main(int argc, char *argv[]);
 
-#include "../defines.h"		/* for HAVE_locale_h */
-
 #ifndef PACKAGE
 #define PACKAGE	"util-linux"
 #endif
@@ -10,25 +8,12 @@
 #define LOCALEDIR "/usr/share/locale"
 #endif
 
-#ifdef HAVE_locale_h
-# include <locale.h>
-#endif
+#include <locale.h>
 
-#if defined MAY_ENABLE_NLS && !defined DISABLE_NLS
-# include <libintl.h>
-# define _(Text) gettext (Text)
-# ifdef gettext_noop
-#  define N_(String) gettext_noop (String)
-# else
-#  define N_(String) (String)
-# endif
+#include <libintl.h>
+#define _(Text) gettext (Text)
+#ifdef gettext_noop
+# define N_(String) gettext_noop (String)
 #else
-# undef bindtextdomain
-# define bindtextdomain(Domain, Directory) /* empty */
-# undef textdomain
-# define textdomain(Domain) /* empty */
-# define _(Text) (Text)
-# define N_(Text) (Text)
+# define N_(String) (String)
 #endif
-
-
