--- main.c.orig	Mon Oct 20 17:59:26 2003
+++ main.c	Mon Oct 20 18:02:56 2003
@@ -1,9 +1,9 @@
 /* program that prints IP address ranges */
+#include "prips.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
-#include "prips.h"
 #include "except.h"
 
 typedef enum {
@@ -16,11 +16,11 @@
 
 const char *MAINTAINER = "dan@vertekcorp.com";
 const char *VERSION =
-	"\rprips 0.9.4
-	\rThis program comes with NO WARRANTY,
-	\rto the extent permitted by law.
-	\rYou may redistribute copies under 
-	\rthe terms of the GNU General Public License.\n";
+	"\rprips 0.9.4\n"\
+"	\rThis program comes with NO WARRANTY,\n"\
+"	\rto the extent permitted by law.\n"\
+"	\rYou may redistribute copies under\n"\
+"	\rthe terms of the GNU General Public License.\n";
 
 void usage(char *prog);
 AddrFormat get_format(char *format);
@@ -166,14 +166,13 @@
 
 void usage(char *prog)
 {
-	fprintf(stderr, "usage: %s [options] <start end | CIDR block>
-	-c		print range in CIDR notation
-	-d <x>		set the delimeter 'x' where 0 =< x =< 255 
-	-f <x> 		set the format of addresses (hex, dec, or dot)
-	-i <x>		set the increment to 'x'
-	-e <x.x.x,x.x>	e.g. -e ..4. will not print 192.168.4.[0-255]
-	
-	\rReport bugs to %s\n",
+	fprintf(stderr, "usage: %s [options] <start end | CIDR block>\n"\
+"	-c		print range in CIDR notation\n"\
+"	-d <x>		set the delimeter 'x' where 0 =< x =< 255\n"\
+"	-f <x> 		set the format of addresses (hex, dec, or dot)\n"\
+"	-i <x>		set the increment to 'x'\n"\
+"	-e <x.x.x,x.x>	e.g. -e ..4. will not print 192.168.4.[0-255]\n\n"\
+"	\rReport bugs to %s\n",
 			prog, MAINTAINER);
 }
 
