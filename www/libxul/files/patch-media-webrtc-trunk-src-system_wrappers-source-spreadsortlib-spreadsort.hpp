--- media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp~
+++ media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp
@@ -21,6 +21,13 @@ Scott McMurray
 #include "constants.hpp"
 #include <cstring>

+#ifdef __FreeBSD__
+# include <osreldate.h>
+# if __FreeBSD_version < 900506
+#  define getchar boost_getchar
+# endif
+#endif
+
 namespace boost {
   namespace detail {
        //This only works on unsigned data types
