--- watch.c.orig	2016-07-09 21:49:25 UTC
+++ watch.c
@@ -52,7 +52,11 @@
 # define _XOPEN_SOURCE_EXTENDED 1
 # include <wchar.h>
 # include <wctype.h>
+#ifdef __FreeBSD__
+# include <ncurses.h>
+#else
 # include <ncursesw/ncurses.h>
+#endif
 #else
 # include <ncurses.h>
 #endif	/* WITH_WATCH8BIT */
@@ -72,6 +76,10 @@ static int flags;
 #define WATCH_ERREXIT	(1 << 6)
 #define WATCH_CHGEXIT	(1 << 7)
 
+#ifdef __FreeBSD__
+#define HOST_NAME_MAX 1024
+#endif
+
 static int curses_started = 0;
 static long height = 24, width = 80;
 static int screen_size_changed = 0;
