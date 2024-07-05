--- src/tests/cmocka/test_authtok.c.orig	2020-03-17 13:31:28 UTC
+++ src/tests/cmocka/test_authtok.c
@@ -28,6 +28,7 @@
 #include "tests/cmocka/common_mock.h"
 
 #include "util/authtok.h"
+#include "util/sss_endian.h"
 
 
 struct test_state {
