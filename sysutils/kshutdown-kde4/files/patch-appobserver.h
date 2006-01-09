--- kshutdown/appobserver.h.orig	Mon Jan  9 18:30:18 2006
+++ kshutdown/appobserver.h	Mon Jan  9 18:30:35 2006
@@ -20,6 +20,8 @@
 #ifndef __APPOBSERVER_H__
 #define __APPOBSERVER_H__
 
+#include <sys/types.h>
+
 #include <qhbox.h>
 
 class QComboBox;
