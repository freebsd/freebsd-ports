--- src/lavfmuxer.cpp~	2007-04-13 19:36:27.000000000 +0200
+++ src/lavfmuxer.cpp	2007-07-17 01:09:12 +0200
@@ -16,7 +16,9 @@
     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
 
+extern "C" {
 #include <ffmpeg/avformat.h>
+}
 #include <string.h>
 #include <utility>
 #include <list>
