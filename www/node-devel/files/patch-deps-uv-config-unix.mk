--- deps/uv/config-unix.mk.orig	2011-08-05 10:43:22.000000000 +0800
+++ deps/uv/config-unix.mk	2011-08-05 10:43:28.000000000 +0800
@@ -18,8 +18,8 @@
 # FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 # IN THE SOFTWARE.
 
-CC = $(PREFIX)gcc
-AR = $(PREFIX)ar
+#CC = $(PREFIX)gcc
+#AR = $(PREFIX)ar
 E=
 CSTDFLAG=--std=c89 -pedantic -Wall -Wextra -Wno-unused-parameter
 CFLAGS=-g
