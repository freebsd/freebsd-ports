--- libobs/obs-nix.c.orig	2015-03-27 21:29:37 UTC
+++ libobs/obs-nix.c
@@ -16,6 +16,10 @@
     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/
 
+#ifdef __FreeBSD__
+#define _WITH_GETLINE
+#endif
+
 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
