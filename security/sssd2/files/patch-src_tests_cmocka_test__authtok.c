--- src/tests/cmocka/test_authtok.c.orig	2023-05-05 08:11:07 UTC
+++ src/tests/cmocka/test_authtok.c
@@ -28,6 +28,7 @@
 #include "tests/cmocka/common_mock.h"
 
 #include "util/authtok.h"
+#include "util/sss_endian.h"
 
 
 struct test_state {
