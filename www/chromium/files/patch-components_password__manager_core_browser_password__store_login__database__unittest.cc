--- components/password_manager/core/browser/password_store/login_database_unittest.cc.orig	2026-07-01 06:24:19 UTC
+++ components/password_manager/core/browser/password_store/login_database_unittest.cc
@@ -2250,7 +2250,7 @@ INSTANTIATE_TEST_SUITE_P(MigrationToVCurrent,
                          testing::Values(1, 2, 3, 24));
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 class LoginDatabaseUndecryptableLoginsTest : public testing::Test {
  protected:
   LoginDatabaseUndecryptableLoginsTest() = default;
