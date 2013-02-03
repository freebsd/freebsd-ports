--- kopete/protocols/jabber/googletalk/libjingle/talk/base/httpcommon.cc.orig	2008-09-06 23:18:41.000000000 -0300
+++ kopete/protocols/jabber/googletalk/libjingle/talk/base/httpcommon.cc	2008-09-06 23:31:38.000000000 -0300
@@ -25,6 +25,10 @@
  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include <time.h>
 
 #ifdef WIN32
@@ -369,7 +373,7 @@
     }
     gmt = non_gmt + kTimeZoneOffsets[zindex] * 60 * 60;
   }
-#ifdef OSX
+#if defined(OSX) || defined(__FreeBSD__)
   tm *tm_for_timezone = localtime((time_t *)&gmt);
   *seconds = gmt + tm_for_timezone->tm_gmtoff;
 #else
