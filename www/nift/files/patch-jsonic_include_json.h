--- jsonic/include/json.h.orig	2026-10-20 14:19:24 UTC
+++ jsonic/include/json.h
@@ -611,6 +611,10 @@ class Document { (private)
             const char* number_start = source_.data() + start;
             const char* number_end = source_.data() + position_;
             double value = 0.0;
+#ifdef __FreeBSD__
+            const std::string number_token(source_.substr(start, position_ - start));
+            value = std::strtod(number_token.c_str(), nullptr);
+#else
             const std::from_chars_result converted =
                 std::from_chars(number_start, number_end, value, std::chars_format::general);
             if (converted.ec == std::errc::result_out_of_range) {
@@ -619,6 +623,7 @@ class Document { (private)
             } else if (converted.ec != std::errc() || converted.ptr != number_end) {
                 fail("invalid JSON number");
             }
+#endif
             if (!std::isfinite(value)) fail("JSON number is outside the supported finite range");
 
             const std::string_view token(number_start, static_cast<std::size_t>(number_end - number_start));
