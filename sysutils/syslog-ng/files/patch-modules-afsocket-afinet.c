--- modules/afsocket/afinet.c.orig	2012-09-01 21:03:17.658244740 -0400
+++ modules/afsocket/afinet.c	2012-09-01 21:03:31.720944758 -0400
@@ -539,11 +539,13 @@
 static gboolean
 afinet_dd_init(LogPipe *s)
 {
-  AFInetDestDriver *self = (AFInetDestDriver *) s;
+  AFInetDestDriver *self G_GNUC_UNUSED = (AFInetDestDriver *) s;
   gboolean success;
 
+#if ENABLE_SPOOF_SOURCE
   if (self->spoof_source)
     self->super.flags &= ~AFSOCKET_KEEP_ALIVE;
+#endif
 
   success = afsocket_dd_init(s);
 #if ENABLE_SPOOF_SOURCE
