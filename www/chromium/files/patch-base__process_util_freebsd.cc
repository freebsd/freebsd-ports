--- base/process_util_freebsd.cc.orig	2013-08-16 22:09:53.000000000 +0300
+++ base/process_util_freebsd.cc	2013-08-16 22:10:18.000000000 +0300
@@ -18,7 +18,7 @@
 #include <unistd.h>
 
 #include "base/logging.h"
-#include "base/string_tokenizer.h"
+#include "base/strings/string_tokenizer.h"
 #include "base/strings/string_number_conversions.h"
 #include "base/strings/string_split.h"
 #include "base/strings/string_util.h"
