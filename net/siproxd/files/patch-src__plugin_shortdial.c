--- src/plugin_shortdial.c.orig	Sat May 20 13:48:30 2006
+++ src/plugin_shortdial.c	Wed Jun 21 09:08:19 2006
@@ -22,6 +22,7 @@
 
 #include <stdio.h>
 #include <string.h>
+#include <unistd.h>
 #include <netinet/in.h>
 
 #include <osipparser2/osip_parser.h>
