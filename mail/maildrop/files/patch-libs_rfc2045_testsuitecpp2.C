--- libs/rfc2045/testsuitecpp2.C.orig	2025-09-10 03:08:09 UTC
+++ libs/rfc2045/testsuitecpp2.C
@@ -217,7 +217,7 @@ void test3()
 	auto b=std::istreambuf_iterator<char>{ss};
 	auto e=std::istreambuf_iterator<char>{};
 
-	typename rfc2045::entity::line_iter<crlf>::iter<
+	typename rfc2045::entity::line_iter<crlf>::template iter<
 		std::istreambuf_iterator<char>,
 		std::istreambuf_iterator<char>
 		> iter{b, e};
@@ -310,7 +310,7 @@ void test4()
 	auto b=std::istreambuf_iterator<char>{ss};
 	auto e=std::istreambuf_iterator<char>{};
 
-	typename rfc2045::entity::line_iter<crlf>::iter<
+	typename rfc2045::entity::line_iter<crlf>::template iter<
 		std::istreambuf_iterator<char>,
 		std::istreambuf_iterator<char>
 		> iter{b, e};
@@ -488,7 +488,7 @@ void test5()
 	auto b=std::istreambuf_iterator<char>{ss};
 	auto e=std::istreambuf_iterator<char>{};
 
-	typename rfc2045::entity::line_iter<crlf>::iter<
+	typename rfc2045::entity::line_iter<crlf>::template iter<
 		std::istreambuf_iterator<char>,
 		std::istreambuf_iterator<char>
 		> iter{b, e};
