--- lib/gibber/gibber-bytestream-oob.h.orig	2010-10-22 15:15:56 UTC
+++ lib/gibber/gibber-bytestream-oob.h
@@ -20,6 +20,7 @@
 #ifndef __GIBBER_BYTESTREAM_OOB_H__
 #define __GIBBER_BYTESTREAM_OOB_H__
 
+#include <netinet/in.h>
 #include <glib-object.h>
 
 #include "gibber-bytestream-iface.h"
