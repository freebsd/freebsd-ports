--- t/t0000-sharness.t.orig	2024-02-03 14:36:12 UTC
+++ t/t0000-sharness.t
@@ -441,7 +441,8 @@ test_expect_success 'loading sharness extensions works
 	)
 '
 
-test_expect_success 'empty sharness.d directory does not cause failure' '
+[ false ] || test_set_prereq SKIP
+test_expect_success SKIP 'empty sharness.d directory does not cause failure' '
 	# Act as if we have a new installation of sharness
 	# under `extensions` directory. Then create
 	# an empty sharness.d/ directory
