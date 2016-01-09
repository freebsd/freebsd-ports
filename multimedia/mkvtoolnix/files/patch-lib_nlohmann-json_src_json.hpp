--- lib/nlohmann-json/src/json.hpp.orig	2015-12-31 12:23:52 UTC
+++ lib/nlohmann-json/src/json.hpp
@@ -5737,7 +5737,9 @@ class basic_json
                     /// use integer array index as key
                     case (value_t::array):
                     {
-                        return std::to_string(array_index);
+                        std::ostringstream TempStream;
+                        TempStream << array_index;
+                        return TempStream.str();
                     }
 
                     /// use key from the object
@@ -6902,7 +6904,7 @@ basic_json_parser_59:
         {
             // conversion
             typename string_t::value_type* endptr;
-            const auto float_val = std::strtold(reinterpret_cast<typename string_t::const_pointer>(m_start),
+            const auto float_val = std::strtod(reinterpret_cast<typename string_t::const_pointer>(m_start),
                                                 &endptr);
 
             // return float_val if the whole number was translated and NAN
