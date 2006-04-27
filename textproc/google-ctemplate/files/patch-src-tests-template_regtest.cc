--- src/tests/template_regtest.cc.orig	Wed Apr 26 15:25:03 2006
+++ src/tests/template_regtest.cc	Wed Apr 26 15:24:10 2006
@@ -131,7 +131,7 @@
   fclose(fp);
 }
 
-static int select_testdata(const struct dirent* d) {
+static int select_testdata(struct dirent* d) {
   return !strncmp(d->d_name, "template_unittest_test",
                   sizeof("template_unittest_test")-1);
 }
