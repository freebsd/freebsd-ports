--- src/utils.c.orig	Sun Aug 22 21:04:37 2004
+++ src/utils.c	Thu Oct 14 07:18:15 2004
@@ -247,12 +247,12 @@
           * as it loads some dynamic libraries. Once chrootet
           * these libraries will *not* be found and gethostbyname()
           * calls will simply fail (return NULL pointer and h_errno=0).
+          * Also (at least for FreeBSD) syslog() needs to be called
+          * before chroot()ing - this is done in main() by an INFO().
           * Took me a while to figure THIS one out
           */
          struct in_addr dummy;
-         DEBUGC(DBCLASS_DNS, "Initializing DNS, the following DNS "
-                             "failure is normal, don't worry");
-         get_ip_by_host("foobar", &dummy);
+         get_ip_by_host("localhost", &dummy);
          DEBUGC(DBCLASS_CONFIG,"chrooting to %s",
                 configuration.chrootjail);
          sts = chroot(configuration.chrootjail);
