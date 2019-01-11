--- cmake/Conky.cmake.orig	2019-01-08 01:26:24 UTC
+++ cmake/Conky.cmake
@@ -18,7 +18,7 @@
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 #
 
-# set(RELEASE true)
+set(RELEASE true)
 
 # Set system vars
 if(CMAKE_SYSTEM_NAME MATCHES "Linux")
