--- components/password_manager/core/browser/login_database_unittest.cc.orig	2023-11-22 14:00:11 UTC
+++ components/password_manager/core/browser/login_database_unittest.cc
@@ -2100,7 +2100,7 @@ INSTANTIATE_TEST_SUITE_P(MigrationToVCurrent,
                          LoginDatabaseMigrationTestBroken,
                          testing::Values(1, 2, 3, 24));
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 class LoginDatabaseUndecryptableLoginsTest : public testing::Test {
  protected:
   LoginDatabaseUndecryptableLoginsTest() = default;
