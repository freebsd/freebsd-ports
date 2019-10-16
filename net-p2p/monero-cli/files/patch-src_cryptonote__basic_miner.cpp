--- src/cryptonote_basic/miner.cpp.orig	2019-10-13 11:25:19 UTC
+++ src/cryptonote_basic/miner.cpp
@@ -61,7 +61,9 @@
   #include <devstat.h>
   #include <errno.h>
   #include <fcntl.h>
+#if defined(__amd64__ ) || defined(__i386__) || defined(__x86_64__)
   #include <machine/apm_bios.h>
+#endif
   #include <stdio.h>
   #include <sys/resource.h>
   #include <sys/sysctl.h>
@@ -1082,6 +1084,7 @@ namespace cryptonote
           return boost::logic::tribool(boost::logic::indeterminate);
         }
 
+#if defined(__amd64__ ) || defined(__i386__) || defined(__x86_64__)
         apm_info info;
         if( ioctl(fd, APMIO_GETINFO, &info) == -1 ) {
           close(fd);
@@ -1116,6 +1119,7 @@ namespace cryptonote
           << "unexpected ac-line status (" << info.ai_acline << ") and "
           << "battery status (" << info.ai_batt_stat << ").");
         return boost::logic::tribool(boost::logic::indeterminate);
+#endif
       }
       if( n != sizeof(ac) )
       {
