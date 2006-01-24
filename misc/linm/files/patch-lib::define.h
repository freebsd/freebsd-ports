--- lib/define.h~	Sat Jan 14 20:55:18 2006
+++ lib/define.h	Tue Jan 24 11:16:05 2006
@@ -39,6 +39,7 @@
 	# endif
 	
 	#ifdef HAVE_GETTEXT
+		#include <libintl.h>
 		#define _(Text)	gettext(Text)
 	#else
 		#define _(Text)	Text
