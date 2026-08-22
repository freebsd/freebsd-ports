From a56c166a0e8f25b032fea71f3bc7c6d9c59c7685 Mon Sep 17 00:00:00 2001
From: Jim Garlick <garlick.jim@gmail.com>
Date: Tue, 17 Sep 2024 14:44:36 -0700
Subject: [PATCH] testsuite: skip el capitan test by default

Problem: the debian riscv64 build environment is failing on the
el capitan scaling test.

We don't have detailed test output to diagnose the failure but we
can probably assume that this is a fairly under-powered builder.

Set the EXPENSIVE built-in test prereq so that this test only runs
if TEST_LONG is set in the environment or the --long test option is
given.

To avoid losing coverage in github CI, also allow the test to run
if GITHUB_CI is set in the environment, and then set it where the
workflow runs make check.

Fixes #206

more
--- t/t0039-llnl-el-capitan-cluster.t.orig	2024-07-11 23:05:22 UTC
+++ t/t0039-llnl-el-capitan-cluster.t
@@ -4,6 +4,12 @@ test_description='Check LLNL El Capitan config'
 
 . `dirname $0`/sharness.sh
 
+# Setting the --long option or TEST_LONG=t fulfills the EXPENSIVE prereq
+if ! test_have_prereq EXPENSIVE && ! test -n "$GITHUB_CI"; then
+	skip_all='skipping large scale El Capitan test'
+	test_done
+fi
+
 ulimit -n 2048
 
 powermand=$SHARNESS_BUILD_DIRECTORY/src/powerman/powermand
