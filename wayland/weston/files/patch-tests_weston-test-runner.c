--- tests/weston-test-runner.c.orig	2015-10-24 00:02:43 UTC
+++ tests/weston-test-runner.c
@@ -155,7 +155,7 @@ int main(int argc, char *argv[])
 		const char *testname = argv[1];
 		if (strcmp(testname, "--help") == 0 ||
 		    strcmp(testname, "-h") == 0) {
-			fprintf(stderr, "Usage: %s [test-name]\n", program_invocation_short_name);
+			fprintf(stderr, "Usage: %s [test-name]\n", getprogname());
 			list_tests();
 			exit(EXIT_SUCCESS);
 		}
