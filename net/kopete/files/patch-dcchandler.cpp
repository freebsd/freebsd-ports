--- kopete/protocols/irc/libkirc/dcchandler.cpp.orig	Wed Nov 20 14:39:14 2002
+++ kopete/protocols/irc/libkirc/dcchandler.cpp	Wed Nov 20 14:41:58 2002
@@ -29,13 +29,9 @@
 #include <qregexp.h>
 #include <qtextcodec.h>
 
-#ifdef NEED_TYPES_H
 #include <sys/types.h>
-#endif
 #include <inttypes.h>
-#ifndef __FreeBSD__
 #  include <netinet/in.h>
-#endif
 #include <unistd.h>
 
 
