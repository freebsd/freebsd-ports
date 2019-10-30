--- src/tests/p11test/p11test.c.orig	2019-10-30 14:56:38 UTC
+++ src/tests/p11test/p11test.c
@@ -49,7 +49,7 @@ void display_usage() {
 }
 
 int main(int argc, char** argv) {
-	char command;
+	signed char command;
 	const struct CMUnitTest readonly_tests_without_initialization[] = {
 		/* Test card events on slot */
 		cmocka_unit_test_setup_teardown(wait_test,
