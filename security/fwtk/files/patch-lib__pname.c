Patch from Rudolf Polzer to fix a compile time warning
and make binaries compiled on 64bit FreeBSD 7.3 work
without segfault on startup.

diff -ru lib/pname.c lib/pname.c
--- lib/pname.c	1997-01-18 19:20:57.000000000 +0000
+++ lib/pname.c	2010-06-30 12:06:26.000000000 +0000
@@ -15,6 +15,7 @@
 #include	<sys/types.h>
 #include	<sys/socket.h>
 #include	<netinet/in.h>
+#include	<arpa/inet.h>
 #include	<netdb.h>
 #include	<syslog.h>
 #include	<ctype.h>
