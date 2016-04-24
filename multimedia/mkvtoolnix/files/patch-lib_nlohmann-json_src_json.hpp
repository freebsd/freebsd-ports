--- lib/nlohmann-json/src/json.hpp.orig	2016-04-23 13:52:02 UTC
+++ lib/nlohmann-json/src/json.hpp
@@ -87,6 +87,14 @@ struct has_mapped_type
     static constexpr bool value = sizeof(test<T>(0)) == 1;
 };
 
+template<typename T>
+std::string ToString(T val)
+{
+  std::ostringstream TempStream;
+  TempStream << val;
+  return TempStream.str();
+}
+
 }
 
 /*!
@@ -3029,7 +3037,7 @@ class basic_json
             catch (std::out_of_range&)
             {
                 // create better exception explanation
-                throw std::out_of_range("array index " + std::to_string(idx) + " is out of range");
+                throw std::out_of_range("array index " + ToString(idx) + " is out of range");
             }
         }
         else
@@ -3073,7 +3081,7 @@ class basic_json
             catch (std::out_of_range&)
             {
                 // create better exception explanation
-                throw std::out_of_range("array index " + std::to_string(idx) + " is out of range");
+                throw std::out_of_range("array index " + ToString(idx) + " is out of range");
             }
         }
         else
@@ -6224,7 +6232,7 @@ class basic_json
                     // use integer array index as key
                     case value_t::array:
                     {
-                        return std::to_string(array_index);
+                        return ToString(array_index);
                     }
 
                     // use key from the object
@@ -8204,7 +8212,7 @@ basic_json_parser_63:
         */
         long double str_to_float_t(long double* /* type */, char** endptr) const
         {
-            return std::strtold(reinterpret_cast<typename string_t::const_pointer>(m_start), endptr);
+            return std::strtod(reinterpret_cast<typename string_t::const_pointer>(m_start), endptr);
         }
 
         /*!
@@ -8244,7 +8252,8 @@ basic_json_parser_63:
         */
         float str_to_float_t(float* /* type */, char** endptr) const
         {
-            return std::strtof(reinterpret_cast<typename string_t::const_pointer>(m_start), endptr);
+            auto v = std::strtod(reinterpret_cast<typename string_t::const_pointer>(m_start), endptr);
+            return (float)v;
         }
 
         /*!
@@ -8316,7 +8325,7 @@ basic_json_parser_63:
             {
                 // positive, parse with strtoull and attempt cast to
                 // number_unsigned_t
-                if (attempt_cast(std::strtoull(reinterpret_cast<typename string_t::const_pointer>(m_start), &endptr,
+                if (attempt_cast(strtoull(reinterpret_cast<typename string_t::const_pointer>(m_start), &endptr,
                                                10), result.m_value.number_unsigned))
                 {
                     result.m_type = value_t::number_unsigned;
@@ -8331,7 +8340,7 @@ basic_json_parser_63:
             {
                 // Negative, parse with strtoll and attempt cast to
                 // number_integer_t
-                if (attempt_cast(std::strtoll(reinterpret_cast<typename string_t::const_pointer>(m_start), &endptr,
+                if (attempt_cast(strtoll(reinterpret_cast<typename string_t::const_pointer>(m_start), &endptr,
                                               10), result.m_value.number_integer))
                 {
                     result.m_type = value_t::number_integer;
