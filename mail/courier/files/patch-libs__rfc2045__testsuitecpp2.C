--- libs/rfc2045/testsuitecpp2.C.orig	2025-09-10 11:00:08.000000000 +0200
+++ libs/rfc2045/testsuitecpp2.C	2025-10-24 14:02:10.528663000 +0200
@@ -217,7 +217,7 @@
 	auto b=std::istreambuf_iterator<char>{ss};
 	auto e=std::istreambuf_iterator<char>{};
 
-	typename rfc2045::entity::line_iter<crlf>::iter<
+	typename rfc2045::entity::line_iter<crlf>::template iter<
 		std::istreambuf_iterator<char>,
 		std::istreambuf_iterator<char>
 		> iter{b, e};
@@ -310,7 +310,7 @@
 	auto b=std::istreambuf_iterator<char>{ss};
 	auto e=std::istreambuf_iterator<char>{};
 
-	typename rfc2045::entity::line_iter<crlf>::iter<
+	typename rfc2045::entity::line_iter<crlf>::template iter<
 		std::istreambuf_iterator<char>,
 		std::istreambuf_iterator<char>
 		> iter{b, e};
@@ -488,7 +488,7 @@
 	auto b=std::istreambuf_iterator<char>{ss};
 	auto e=std::istreambuf_iterator<char>{};
 
-	typename rfc2045::entity::line_iter<crlf>::iter<
+	typename rfc2045::entity::line_iter<crlf>::template iter<
 		std::istreambuf_iterator<char>,
 		std::istreambuf_iterator<char>
 		> iter{b, e};
