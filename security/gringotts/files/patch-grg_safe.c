--- src/grg_safe.c.orig	Sun Jun 16 18:41:21 2002
+++ src/grg_safe.c	Fri Jul  5 19:12:36 2002
@@ -24,13 +24,16 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
+#include <sys/types.h>
 #include <regex.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/mman.h>
+#ifdef HAVE_SYS_FSUID_H
 #include <sys/fsuid.h>
-#include <sys/types.h>
+#endif
+#include <sys/mman.h>
 
 #include <gtk/gtk.h>
 #include <gdk-pixbuf/gdk-pixbuf.h>
@@ -131,12 +134,12 @@
 	if (!geteuid())
 	//the process is SUID root. I can mlockall() the memory in order to avoid swapping.
 	{
-		gint res = mlockall (MCL_FUTURE);
+//		gint res = mlockall (MCL_FUTURE);
 
-		if (res)
-			g_critical ("%s", _("The process is setuid root, but I can't lock memory paging"));
-		else
-			mem_safe = TRUE;
+//		if (res)
+//			g_critical ("%s", _("The process is setuid root, but I can't lock memory paging"));
+//		else
+//			mem_safe = TRUE;
 
 		//drop root privileges
 		setuid(getuid());
@@ -181,8 +184,8 @@
 
 	if (ulimit != '0')
 	{
-		g_critical ("%s", _("Your shell is configured to produce core dumps. I cannot go on. Please run gringotts via its shell script."));
-		return FALSE;
+		g_critical ("%s", _("Your shell is configured to produce core dumps."));
+//		return FALSE;
 	}
 
 	//checks that stderr, stdin & stdout are opened
