--- cygwin.h.orig	Sat Apr  5 20:06:44 2003
+++ cygwin.h	Thu Aug 26 18:50:49 2004
@@ -36,7 +36,6 @@
 #include <zlib.h>
 #include <ctype.h>
 #include <signal.h>
-#include <malloc.h>
 
 #ifdef __cplusplus
 #include <string>  // for stl string
@@ -166,7 +165,6 @@
 	#include <netinet/in.h>
 	#include <netinet/tcp.h>
 	#include <sys/poll.h>
-	#include <mcheck.h>
 	#define dir_delim	'/'
 	#define HAVE_SIGHUP	1
 	#define HAVE_SIGINT	1
