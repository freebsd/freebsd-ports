--- lib/nlohmann-json/src/json.hpp.orig	2016-04-23 13:52:02 UTC
+++ lib/nlohmann-json/src/json.hpp
@@ -6224,7 +6224,9 @@ class basic_json
                     // use integer array index as key
                     case value_t::array:
                     {
-                        return std::to_string(array_index);
+                        std::ostringstream TempStream;
+                        TempStream << array_index;
+                        return TempStream.str();
                     }
 
                     // use key from the object
@@ -8204,7 +8206,7 @@ basic_json_parser_63:
         */
         long double str_to_float_t(long double* /* type */, char** endptr) const
         {
-            return std::strtold(reinterpret_cast<typename string_t::const_pointer>(m_start), endptr);
+            return std::strtod(reinterpret_cast<typename string_t::const_pointer>(m_start), endptr);
         }
 
         /*!
