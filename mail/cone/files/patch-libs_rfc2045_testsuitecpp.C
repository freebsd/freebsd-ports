--- libs/rfc2045/testsuitecpp.C.orig	2025-10-04 09:00:06 UTC
+++ libs/rfc2045/testsuitecpp.C
@@ -19,7 +19,7 @@ void testrfc2045line_iter_testset(int &testnum, test_t
 		auto b=s.begin();
 		auto e=s.end();
 
-		typename rfc2045::entity::line_iter<crlf>::iter<
+		typename rfc2045::entity::line_iter<crlf>::template iter<
 			std::string_view::iterator,
 			std::string_view::iterator
 			>
