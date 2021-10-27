--- Telegram/lib_base/base/bytes.h.orig	2021-10-06 07:02:39 UTC
+++ Telegram/lib_base/base/bytes.h
@@ -145,7 +145,7 @@ template <
 vector concatenate(Args &&...args) {
 	const auto size = details::spansLength(args...);
 	auto result = vector(size);
-	details::spansAppend(make_span(result), args...);
+	details::spansAppend(bytes::make_span(result), args...);
 	return result;
 }
 
@@ -156,7 +156,7 @@ vector concatenate(SpanRange args) {
 		size += bytes::make_span(arg).size();
 	}
 	auto result = vector(size);
-	auto buffer = make_span(result);
+	auto buffer = bytes::make_span(result);
 	for (const auto &arg : args) {
 		const auto part = bytes::make_span(arg);
 		bytes::copy(buffer, part);
