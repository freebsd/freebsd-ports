--- ./src/purple/purple-private.h.orig	2010-11-03 05:13:51.000000000 +0100
+++ ./src/purple/purple-private.h	2011-06-21 11:23:35.000000000 +0200
@@ -20,18 +20,28 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
+#include "version.h"
+
 /* Forward declarations */
 struct sipe_core_public;
 struct _PurpleAccount;
 struct _PurpleConnection;
+#if PURPLE_VERSION_CHECK(2,8,0)
+struct _PurpleSrvTxtQueryData;
+#else
 struct _PurpleSrvQueryData;
+#endif
 struct _PurpleXfer;
 
 struct sipe_backend_private {
 	struct sipe_core_public *public;
 	struct _PurpleConnection *gc;
 	struct _PurpleAccount *account;
+#if PURPLE_VERSION_CHECK(2,8,0)
+	struct _PurpleSrvTxtQueryData *dns_query;
+#else
 	struct _PurpleSrvQueryData *dns_query;
+#endif
 	time_t last_keepalive;
 };
 
