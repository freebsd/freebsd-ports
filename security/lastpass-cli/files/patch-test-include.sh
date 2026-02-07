--- test/include.sh.orig	2023-11-10 10:04:34 UTC
+++ test/include.sh
@@ -8,7 +8,7 @@ function setup()
 	export TEST_USER="user@example.com"
 	export TEST_PASS="123456"
 	export TEST_WRONG_PASS="000000"
-	export TEST_LPASS="../build/lpass-test"
+	export TEST_LPASS="../lpass-test"
 	export LPASS_HOME="./.lpass"
 }
 
