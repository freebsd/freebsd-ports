--- src/svlogd.c.orig	2014-08-10 18:22:34 UTC
+++ src/svlogd.c
@@ -430,6 +430,7 @@ unsigned int logdir_open(struct logdir *ld, const char
   ld->name =(char*)fn;
   ld->ppid =0;
   ld->match ='+';
+  ld->udpaddr.sin_family =AF_INET;
   ld->udpaddr.sin_port =0;
   ld->udponly =0;
   while (! stralloc_copys(&ld->prefix, "")) pause_nomem();
