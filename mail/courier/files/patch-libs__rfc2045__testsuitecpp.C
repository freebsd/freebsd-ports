--- libs/rfc2045/testsuitecpp.C.orig	2025-10-03 19:53:41.000000000 +0200
+++ libs/rfc2045/testsuitecpp.C	2025-10-24 14:00:53.643970000 +0200
@@ -19,7 +19,7 @@
 		auto b=s.begin();
 		auto e=s.end();
 
-		typename rfc2045::entity::line_iter<crlf>::iter<
+		typename rfc2045::entity::line_iter<crlf>::template iter<
 			std::string_view::iterator,
 			std::string_view::iterator
 			>
