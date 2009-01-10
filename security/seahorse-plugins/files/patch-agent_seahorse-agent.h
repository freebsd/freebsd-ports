--- agent/seahorse-agent.h.orig	2008-08-06 01:22:16.000000000 -0400
+++ agent/seahorse-agent.h	2008-08-06 01:22:27.000000000 -0400
@@ -22,6 +22,8 @@
 #ifndef __SEAHORSE_AGENT_H__
 #define __SEAHORSE_AGENT_H__
 
+#include <sys/types.h>
+
 #include <glib.h>
 #include <gconf/gconf-client.h>
 #include <gconf/gconf.h>
