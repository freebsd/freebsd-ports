--- media/mtransport/third_party/nICEr/src/util/mbslen.c~
+++ media/mtransport/third_party/nICEr/src/util/mbslen.c
@@ -54,6 +54,13 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 # endif
 #endif
 
+#ifdef __DragonFly__
+#include <osreldate.h>
+# if __DragonFly_version > 300502
+#  define HAVE_XLOCALE
+# endif
+#endif
+
 #ifdef HAVE_XLOCALE
 #include <xlocale.h>
 #endif /* HAVE_XLOCALE */
