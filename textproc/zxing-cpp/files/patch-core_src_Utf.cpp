--- core/src/Utf.cpp.orig	2023-12-10 23:43:27 UTC
+++ core/src/Utf.cpp
@@ -20,7 +20,7 @@ using char8_t = uint8_t;
 #if __cplusplus <= 201703L
 using char8_t = uint8_t;
 #endif
-using utf8_t = std::basic_string_view<char8_t>;
+using utf8_t = std::vector<char8_t>;
 
 using state_t = uint8_t;
 constexpr state_t kAccepted = 0;
@@ -118,7 +118,8 @@ std::wstring FromUtf8(std::string_view utf8)
 std::wstring FromUtf8(std::string_view utf8)
 {
 	std::wstring str;
-	AppendFromUtf8({reinterpret_cast<const char8_t*>(utf8.data()), utf8.size()}, str);
+	const char8_t* data = reinterpret_cast<const char8_t*>(utf8.data());
+	AppendFromUtf8({data, data + utf8.size()}, str);
 	return str;
 }
 
