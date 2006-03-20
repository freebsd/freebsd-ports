--- bgpctl/bgpctl.c.orig	Tue Jan 24 15:28:03 2006
+++ bgpctl/bgpctl.c	Mon Mar 20 11:55:29 2006
@@ -29,7 +29,11 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#if defined(__OpenBSD__)
 #include <util.h>
+#else /* defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) */
+#include <libutil.h>
+#endif
 
 #include "bgpd.h"
 #include "session.h"
@@ -1032,7 +1039,11 @@
 {
 	static char	buf[16];
 
+#if defined(__OpenBSD__)
 	if (fmt_scaled(num, buf) == -1)
+#else /* defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) */
+	if (humanize_number(buf, 16, num, "", HN_AUTOSCALE, HN_B | HN_NOSPACE | HN_DECIMAL) == -1)
+#endif
 		snprintf(buf, sizeof(buf), "%lldB", num);
 
 	return (buf);
