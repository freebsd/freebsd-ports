--- lib/gibber/gibber-bytestream-oob.h.orig	2010-05-20 06:10:39.000000000 -0400
+++ lib/gibber/gibber-bytestream-oob.h	2010-07-24 20:41:19.000000000 -0400
@@ -20,6 +20,7 @@
 #ifndef __GIBBER_BYTESTREAM_OOB_H__
 #define __GIBBER_BYTESTREAM_OOB_H__
 
+#include <netinet/in.h>
 #include <glib-object.h>
 
 #include "gibber-bytestream-iface.h"
