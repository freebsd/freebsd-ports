Build fix for clang.

    error: unknown type name 'time_t'

--- kopete/protocols/jabber/googletalk/libjingle/talk/base/diskcache.h
++- kopete/protocols/jabber/googletalk/libjingle/talk/base/diskcache.h
@@ -30,6 +30,7 @@
 
 #include <map>
 #include <string>
+#include <time.h>
 
 #ifdef WIN32
 #undef UnlockResource
