--- src/sniffer.cpp.orig	Sun Jul 14 07:58:36 2002
+++ src/sniffer.cpp	Mon Jul 15 14:20:26 2002
@@ -1,3 +1,9 @@
+#include "config.h"
+
+#ifdef HAVE_SYS_PARAM_H
+# include <sys/param.h>  
+#endif
+
 #include "sniffer.h"
 
 #include <kapp.h>
@@ -37,7 +43,13 @@
 
  while(1) 
   {
-   DVDNextEvent(nav2, &mev);
+#if (defined(BSD) && (BSD >= 199306))
+   if (DVDNextEventNonBlocking(nav2, &mev) != DVD_E_Ok)
+    QThread::exit();
+#else
+   if (DVDNextEvent(nav2, &mev) != DVD_E_Ok)
+    QThread::exit();
+#endif
    switch(mev.type) 
     {
      case MsgEventQInputPointerMotion:
