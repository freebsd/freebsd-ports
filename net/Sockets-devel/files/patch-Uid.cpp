--- Uid.cpp.orig	Sat Jan 15 21:36:02 2005
+++ Uid.cpp	Sat Jan 15 22:41:30 2005
@@ -20,12 +20,22 @@
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #include <stdio.h>
 #include <assert.h>
 #ifdef _WIN32
 #include <objbase.h>
 #elif defined MACOSX
 #include "uuid.h"
+#elif defined __FreeBSD__
+# if __FreeBSD_version >= 500000
+#  include <uuid.h>
+# else
+#  error FreeBSD versions prior to 500000 does not support uuid(3)
+# endif
 #else
 #include <uuid/uuid.h>
 #endif
@@ -49,6 +59,10 @@
 		exit(-1);
 	}
 	memcpy(m_bufuid, &randomGuid, 16);
+#elif defined __FreeBSD__
+	uuid_t uid;
+	uuid_create(&uid, NULL);
+	memcpy(m_bufuid, &uid, 16);
 #else
 	uuid_t uid;
 	uuid_generate(uid);
