--- src/xsniffer.c.orig	Thu Sep  6 14:10:17 2001
+++ src/xsniffer.c	Thu Oct 25 18:22:04 2001
@@ -16,6 +16,10 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -35,6 +39,9 @@
 #include "xsniffer.h"
 #include "callbacks.h"
 
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
 
 extern int msgqid;
 
@@ -66,7 +73,12 @@
   
   fprintf(stderr, "xsniff_mouse\n");
   while(1) {
-    DVDNextEvent(nav2, &mev);
+#if (defined(BSD) && (BSD >= 199306))
+	if (DVDNextEventNonBlocking(nav2, &mev) != DVD_E_Ok)
+#else
+	if (DVDNextEvent(nav2, &mev) != DVD_E_Ok) 
+#endif
+		pthread_exit(NULL);
     
     switch(mev.type) {
 
