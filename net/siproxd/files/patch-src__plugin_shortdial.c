--- src/plugin_shortdial.c.orig	Sat Jan 19 17:06:51 2008
+++ src/plugin_shortdial.c	Mon Feb  4 16:46:26 2008
@@ -23,6 +23,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <unistd.h>
 #include <netinet/in.h>
 
 #include <osipparser2/osip_parser.h>
