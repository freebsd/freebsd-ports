--- src/xsniffer.c.orig	Sat Dec  8 14:28:37 2001
+++ src/xsniffer.c	Sat Dec  8 15:33:28 2001
@@ -16,6 +16,11 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+#define HAVE_SYS_PARAM_H
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -35,6 +40,10 @@
 #include "callbacks.h"
 #include "bindings.h"
 
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
+
 extern int msgqid;
 
 
@@ -64,7 +73,13 @@
   init_actions(nav2);
   
   while(1) {
-    DVDNextEvent(nav2, &mev);
+
+#if (defined(BSD) && (BSD >= 199306))
+	if (DVDNextEventNonBlocking(nav2, &mev) != DVD_E_Ok)
+#else
+	if (DVDNextEvent(nav2, &mev) != DVD_E_Ok)
+#endif
+		pthread_exit(NULL);
     
     switch(mev.type) {
 
