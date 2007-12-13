--- src/plugin_shortdial.c.orig	Fri Jun  8 21:42:57 2007
+++ src/plugin_shortdial.c	Wed Nov 14 12:26:19 2007
@@ -22,6 +22,7 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #include <netinet/in.h>
 
 #include <osipparser2/osip_parser.h>
