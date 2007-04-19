--- src/salut-contact.h.orig	Thu Apr 19 17:06:44 2007
+++ src/salut-contact.h	Thu Apr 19 17:08:20 2007
@@ -20,6 +20,8 @@
 #ifndef __SALUT_CONTACT_H__
 #define __SALUT_CONTACT_H__
 
+#include <sys/socket.h>
+
 #include <netinet/in.h>
 #include <glib-object.h>
 
