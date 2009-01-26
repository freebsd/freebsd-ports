--- src/server.c.orig	Tue Jan  6 14:51:55 2009
+++ src/server.c	Sun Jan 25 19:39:58 2009
@@ -423,7 +423,6 @@
                 int serr=errno;
                 switch(serr) {
                         case ECONNABORTED:
-                        case EPROTO:
                         case EINTR:
                                 TRACE(TRACE_DEBUG, "%s", strerror(serr));
                                 break;
@@ -462,7 +461,6 @@
                 int serr=errno;
                 switch(serr) {
                         case ECONNABORTED:
-                        case EPROTO:
                         case EINTR:
                                 TRACE(TRACE_DEBUG, "%s", strerror(serr));
                                 break;
