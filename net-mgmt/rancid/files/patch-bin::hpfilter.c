--- bin/hpfilter.c.orig	Wed Oct 15 15:52:48 2003
+++ bin/hpfilter.c	Wed Oct 15 15:53:08 2003
@@ -382,7 +382,7 @@
 usage(void)
 {
     fprintf(stderr,
-"usage: %s [-hv] <telnet|ssh> <hostname>
+"usage: %s [-hv] <telnet|ssh> <hostname>\n\
 ", progname);
     return;
 }
@@ -391,7 +391,7 @@
 vers(void)
 {
     fprintf(stderr,
-"%s: %s version %s
+"%s: %s version %s\n\
 ", progname, package, version);
     return;
 }
