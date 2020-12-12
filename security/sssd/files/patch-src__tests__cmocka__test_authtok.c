diff --git src/tests/cmocka/test_authtok.c src/tests/cmocka/test_authtok.c
index 9422f96bc..8492e186a 100644
--- src/tests/cmocka/test_authtok.c
+++ src/tests/cmocka/test_authtok.c
@@ -28,6 +28,7 @@
 #include "tests/cmocka/common_mock.h"
 
 #include "util/authtok.h"
+#include "util/sss_endian.h"
 
 
 struct test_state {
