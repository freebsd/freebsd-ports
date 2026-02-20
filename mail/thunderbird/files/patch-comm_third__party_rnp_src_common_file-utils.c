commit a3e3372ce78c5ef57a17010633f35fb23e761395
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    include stdlib.h unconditionally for getenv()

diff --git comm/third_party/rnp/src/common/file-utils.cpp comm/third_party/rnp/src/common/file-utils.cpp
index e0610f20314..95f8c0b8dcd 100644
--- comm/third_party/rnp/src/common/file-utils.cpp
+++ comm/third_party/rnp/src/common/file-utils.cpp
@@ -30,7 +30,6 @@
 #include "file-utils.h"
 #include "config.h"
 #ifdef _MSC_VER
-#include <stdlib.h>
 #include <stdio.h>
 #include "uniwin.h"
 #include <errno.h>
@@ -39,6 +38,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #endif // !_MSC_VER
+#include <stdlib.h>
 #include "str-utils.h"
 #include <algorithm>
 #ifdef _WIN32
