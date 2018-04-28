--- protocols/jabber/libjingle/talk/base/httpcommon.cc.orig	2018-03-15 04:21:08 UTC
+++ protocols/jabber/libjingle/talk/base/httpcommon.cc
@@ -25,6 +25,10 @@
  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#  include <sys/param.h>
+#endif
+
 #include <time.h>
 
 #ifdef WIN32
@@ -399,7 +403,7 @@ bool HttpDateToSeconds(const std::string& date, time_t
     gmt = non_gmt + kTimeZoneOffsets[zindex] * 60 * 60;
   }
   // TODO: Android should support timezone, see b/2441195
-#if defined(OSX) || defined(ANDROID) || defined(BSD)
+#if defined(OSX) || defined(ANDROID) || defined(BSD) || defined(__FreeBSD__)
   tm *tm_for_timezone = localtime((time_t *)&gmt);
   *seconds = gmt + tm_for_timezone->tm_gmtoff;
 #else
