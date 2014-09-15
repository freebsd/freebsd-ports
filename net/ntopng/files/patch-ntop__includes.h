--- ntop_includes.h.orig	2014-09-07 02:11:07.296297465 +0600
+++ ntop_includes.h	2014-09-07 02:14:50.419281644 +0600
@@ -81,6 +81,8 @@
 #include <math.h>
 #include <sys/stat.h>
 #include <zmq.h>
+#include <sys/param.h>
+#include <machine/endian.h>
 
 #ifdef __APPLE__
 #include <uuid/uuid.h>
@@ -88,8 +90,8 @@
 
 extern "C" {
 #include "pcap.h"
-#include "ndpi_main.h"
-#include "luajit.h"
+#include <ndpi_main.h>
+#include <luajit.h>
 #include "lauxlib.h"
 #include "lualib.h"
 #ifdef HAVE_PF_RING
