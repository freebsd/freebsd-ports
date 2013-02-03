Index: kopete/protocols/jabber/googletalk/libjingle/talk/base/stringencode.cc
===================================================================
--- kopete/protocols/jabber/googletalk/libjingle/talk/base/stringencode.cc	(revision 1242947)
+++ kopete/protocols/jabber/googletalk/libjingle/talk/base/stringencode.cc	(working copy)
@@ -29,10 +29,6 @@
 #include <malloc.h>
 #endif  // WIN32
 #include <stdlib.h>
-#ifdef POSIX
-#include <alloca.h>
-#define _alloca alloca
-#endif  // POSIX
 
 #include "talk/base/basictypes.h"
 #include "talk/base/common.h"
@@ -477,16 +473,18 @@
 
 void transform(std::string& value, size_t maxlen, const std::string& source,
                Transform t) {
-  char * buffer = static_cast<char *>(_alloca(maxlen + 1));
+  char * buffer = new char[maxlen + 1];
   value.assign(buffer, t(buffer, maxlen + 1, source.data(), source.length()));
+  delete [] buffer;
 }
 
 std::string s_transform(const std::string& source, Transform t) {
   // Ask transformation function to approximate the destination size (returns upper bound)
   size_t maxlen = t(NULL, 0, source.data(), source.length());
-  char * buffer = static_cast<char *>(_alloca(maxlen));
+  char * buffer = new char[maxlen];
   size_t len = t(buffer, maxlen, source.data(), source.length());
   std::string result(buffer, len);
+  delete [] buffer;
   return result;
 }
 
