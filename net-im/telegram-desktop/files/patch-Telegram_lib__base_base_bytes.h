--- Telegram/lib_base/base/bytes.h.orig	2020-01-29 09:41:30 UTC
+++ Telegram/lib_base/base/bytes.h
@@ -136,7 +136,7 @@ template <
 vector concatenate(Args &&...args) {
 	const auto size = details::spansLength(args...);
 	auto result = vector(size);
-	details::spansAppend(make_span(result), args...);
+	details::spansAppend(bytes::make_span(result), args...);
 	return result;
 }
 
@@ -148,7 +148,7 @@ vector concatenate(SpanRange args) {
 		size += bytes::make_span(arg).size();
 	}
 	auto result = vector(size);
-	auto buffer = make_span(result);
+	auto buffer = bytes::make_span(result);
 	for (const auto &arg : args) {
 		const auto part = bytes::make_span(arg);
 		bytes::copy(buffer, part);
