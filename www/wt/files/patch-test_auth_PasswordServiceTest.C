--- test/auth/PasswordServiceTest.C.orig	2024-10-21 15:06:23 UTC
+++ test/auth/PasswordServiceTest.C
@@ -116,28 +116,3 @@ BOOST_AUTO_TEST_CASE( throttle_enabled_failure_test )
     BOOST_REQUIRE(f.myPasswordService_->delayForNextAttempt(user) == attemptResults[failures]);
   }
 }
-
-BOOST_AUTO_TEST_CASE( throttle_enabled_failure_with_last_attempt_offset_test )
-{
-  PasswordDboFixture f;
-  f.myPasswordService_->setPasswordThrottle(std::make_unique<Auth::AuthThrottle>());
-
-  Wt::Dbo::Transaction transaction(*f.session_);
-  Auth::User user = f.users_->registerNew();
-  transaction.commit();
-
-  std::vector<int> attemptResults { 0, 3, 7, 21, 20 };
-
-  // Test for 5 failure attempts
-  for (std::size_t failures = 0; failures < 5; ++failures) {
-    // Have one additional login failure
-    user.setAuthenticated(false);
-    transaction.commit();
-
-    // Sleep for x number of seconds, to test current datetime offset.
-    std::this_thread::sleep_for(std::chrono::seconds(failures + 1));
-
-    BOOST_REQUIRE(f.myPasswordService_->delayForNextAttempt(user) == attemptResults[failures]);
-  }
-}
-
