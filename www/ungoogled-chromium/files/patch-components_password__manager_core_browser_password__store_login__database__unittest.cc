--- components/password_manager/core/browser/password_store/login_database_unittest.cc.orig	2024-07-31 14:19:23 UTC
+++ components/password_manager/core/browser/password_store/login_database_unittest.cc
@@ -2141,7 +2141,7 @@ INSTANTIATE_TEST_SUITE_P(MigrationToVCurrent,
                          testing::Values(1, 2, 3, 24));
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 class LoginDatabaseUndecryptableLoginsTest : public testing::Test {
  protected:
   LoginDatabaseUndecryptableLoginsTest() = default;
