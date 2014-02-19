--- protocols/jabber/googletalk/libjingle/talk/base/httpcommon.cc.orig	2013-08-12 12:58:35.392328957 +0000
+++ protocols/jabber/googletalk/libjingle/talk/base/httpcommon.cc	2013-08-12 13:01:23.000326301 +0000
@@ -25,6 +25,10 @@
  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#  include <sys/param.h>
+#endif
+
 #include <time.h>
 
 #ifdef WIN32
@@ -399,7 +403,7 @@
     gmt = non_gmt + kTimeZoneOffsets[zindex] * 60 * 60;
   }
   // TODO: Android should support timezone, see b/2441195
-#if defined(OSX) || defined(ANDROID) || defined(BSD)
+#if defined(OSX) || defined(ANDROID) || defined(BSD) || defined(__FreeBSD__)
   tm *tm_for_timezone = localtime((time_t *)&gmt);
   *seconds = gmt + tm_for_timezone->tm_gmtoff;
 #else
