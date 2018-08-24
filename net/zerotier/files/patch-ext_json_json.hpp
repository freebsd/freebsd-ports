--- ext/json/json.hpp.orig	2018-05-11 20:40:22 UTC
+++ ext/json/json.hpp
@@ -1,11 +1,12 @@
 /*
     __ _____ _____ _____
  __|  |   __|     |   | |  JSON for Modern C++
-|  |  |__   |  |  | | | |  version 3.0.1
+|  |  |__   |  |  | | | |  version 3.2.0
 |_____|_____|_____|_|___|  https://github.com/nlohmann/json
 
 Licensed under the MIT License <http://opensource.org/licenses/MIT>.
-Copyright (c) 2013-2017 Niels Lohmann <http://nlohmann.me>.
+SPDX-License-Identifier: MIT
+Copyright (c) 2013-2018 Niels Lohmann <http://nlohmann.me>.
 
 Permission is hereby  granted, free of charge, to any  person obtaining a copy
 of this software and associated  documentation files (the "Software"), to deal
@@ -29,43 +30,105 @@ SOFTWARE.
 #ifndef NLOHMANN_JSON_HPP
 #define NLOHMANN_JSON_HPP
 
-#include <algorithm> // all_of, copy, fill, find, for_each, generate_n, none_of, remove, reverse, transform
-#include <array> // array
+#define NLOHMANN_JSON_VERSION_MAJOR 3
+#define NLOHMANN_JSON_VERSION_MINOR 2
+#define NLOHMANN_JSON_VERSION_PATCH 0
+
+#include <algorithm> // all_of, find, for_each
 #include <cassert> // assert
 #include <ciso646> // and, not, or
-#include <clocale> // lconv, localeconv
-#include <cmath> // isfinite, labs, ldexp, signbit
 #include <cstddef> // nullptr_t, ptrdiff_t, size_t
-#include <cstdint> // int64_t, uint64_t
-#include <cstdlib> // abort, strtod, strtof, strtold, strtoul, strtoll, strtoull
-#include <cstring> // memcpy, strlen
-#include <forward_list> // forward_list
-#include <functional> // function, hash, less
+#include <functional> // hash, less
 #include <initializer_list> // initializer_list
-#include <iomanip> // hex
-#include <iosfwd>   // istream, ostream
-#include <iterator> // advance, begin, back_inserter, bidirectional_iterator_tag, distance, end, inserter, iterator, iterator_traits, next, random_access_iterator_tag, reverse_iterator
-#include <limits> // numeric_limits
-#include <locale> // locale
-#include <map> // map
-#include <memory> // addressof, allocator, allocator_traits, unique_ptr
+#include <iosfwd> // istream, ostream
+#include <iterator> // iterator_traits, random_access_iterator_tag
 #include <numeric> // accumulate
-#include <sstream> // stringstream
-#include <string> // getline, stoi, string, to_string
-#include <type_traits> // add_pointer, conditional, decay, enable_if, false_type, integral_constant, is_arithmetic, is_base_of, is_const, is_constructible, is_convertible, is_default_constructible, is_enum, is_floating_point, is_integral, is_nothrow_move_assignable, is_nothrow_move_constructible, is_pointer, is_reference, is_same, is_scalar, is_signed, remove_const, remove_cv, remove_pointer, remove_reference, true_type, underlying_type
-#include <utility> // declval, forward, make_pair, move, pair, swap
-#include <valarray> // valarray
+#include <string> // string, stoi, to_string
+#include <utility> // declval, forward, move, pair, swap
+
+// #include <nlohmann/json_fwd.hpp>
+#ifndef NLOHMANN_JSON_FWD_HPP
+#define NLOHMANN_JSON_FWD_HPP
+
+#include <cstdint> // int64_t, uint64_t
+#include <map> // map
+#include <memory> // allocator
+#include <string> // string
 #include <vector> // vector
 
+/*!
+@brief namespace for Niels Lohmann
+@see https://github.com/nlohmann
+@since version 1.0.0
+*/
+namespace nlohmann
+{
+/*!
+@brief default JSONSerializer template argument
+
+This serializer ignores the template arguments and uses ADL
+([argument-dependent lookup](https://en.cppreference.com/w/cpp/language/adl))
+for serialization.
+*/
+template<typename T = void, typename SFINAE = void>
+struct adl_serializer;
+
+template<template<typename U, typename V, typename... Args> class ObjectType =
+         std::map,
+         template<typename U, typename... Args> class ArrayType = std::vector,
+         class StringType = std::string, class BooleanType = bool,
+         class NumberIntegerType = std::int64_t,
+         class NumberUnsignedType = std::uint64_t,
+         class NumberFloatType = double,
+         template<typename U> class AllocatorType = std::allocator,
+         template<typename T, typename SFINAE = void> class JSONSerializer =
+         adl_serializer>
+class basic_json;
+
+/*!
+@brief JSON Pointer
+
+A JSON pointer defines a string syntax for identifying a specific value
+within a JSON document. It can be used with functions `at` and
+`operator[]`. Furthermore, JSON pointers are the base for JSON patches.
+
+@sa [RFC 6901](https://tools.ietf.org/html/rfc6901)
+
+@since version 2.0.0
+*/
+template<typename BasicJsonType>
+class json_pointer;
+
+/*!
+@brief default JSON class
+
+This type is the default specialization of the @ref basic_json class which
+uses the standard template types.
+
+@since version 1.0.0
+*/
+using json = basic_json<>;
+}
+
+#endif
+
+// #include <nlohmann/detail/macro_scope.hpp>
+
+
+// This file contains all internal macro definitions
+// You MUST include macro_unscope.hpp at the end of json.hpp to undef all of them
+
 // exclude unsupported compilers
-#if defined(__clang__)
-    #if (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__) < 30400
-        #error "unsupported Clang version - see https://github.com/nlohmann/json#supported-compilers"
+#if !defined(JSON_SKIP_UNSUPPORTED_COMPILER_CHECK)
+    #if defined(__clang__)
+        #if (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__) < 30400
+            #error "unsupported Clang version - see https://github.com/nlohmann/json#supported-compilers"
+        #endif
+    #elif defined(__GNUC__) && !(defined(__ICC) || defined(__INTEL_COMPILER))
+        #if (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) < 40900
+            #error "unsupported GCC version - see https://github.com/nlohmann/json#supported-compilers"
+        #endif
     #endif
-#elif defined(__GNUC__) && !(defined(__ICC) || defined(__INTEL_COMPILER))
-    #if (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__) < 40900
-        #error "unsupported GCC version - see https://github.com/nlohmann/json#supported-compilers"
-    #endif
 #endif
 
 // disable float-equal warnings on GCC/clang
@@ -90,16 +153,37 @@ SOFTWARE.
 #endif
 
 // allow to disable exceptions
-#if (defined(__cpp_exceptions) || defined(__EXCEPTIONS) || defined(_CPPUNWIND)) && not defined(JSON_NOEXCEPTION)
+#if (defined(__cpp_exceptions) || defined(__EXCEPTIONS) || defined(_CPPUNWIND)) && !defined(JSON_NOEXCEPTION)
     #define JSON_THROW(exception) throw exception
     #define JSON_TRY try
     #define JSON_CATCH(exception) catch(exception)
+    #define JSON_INTERNAL_CATCH(exception) catch(exception)
 #else
     #define JSON_THROW(exception) std::abort()
     #define JSON_TRY if(true)
     #define JSON_CATCH(exception) if(false)
+    #define JSON_INTERNAL_CATCH(exception) if(false)
 #endif
 
+// override exception macros
+#if defined(JSON_THROW_USER)
+    #undef JSON_THROW
+    #define JSON_THROW JSON_THROW_USER
+#endif
+#if defined(JSON_TRY_USER)
+    #undef JSON_TRY
+    #define JSON_TRY JSON_TRY_USER
+#endif
+#if defined(JSON_CATCH_USER)
+    #undef JSON_CATCH
+    #define JSON_CATCH JSON_CATCH_USER
+    #define JSON_INTERNAL_CATCH JSON_CATCH_USER
+#endif
+#if defined(JSON_INTERNAL_CATCH_USER)
+    #undef JSON_INTERNAL_CATCH
+    #define JSON_INTERNAL_CATCH JSON_INTERNAL_CATCH_USER
+#endif
+
 // manual branch prediction
 #if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
     #define JSON_LIKELY(x)      __builtin_expect(!!(x), 1)
@@ -117,27 +201,6 @@ SOFTWARE.
     #define JSON_HAS_CPP_14
 #endif
 
-/*!
-@brief namespace for Niels Lohmann
-@see https://github.com/nlohmann
-@since version 1.0.0
-*/
-namespace nlohmann
-{
-template<typename = void, typename = void>
-struct adl_serializer;
-
-// forward declaration of basic_json (required to split the class)
-template<template<typename, typename, typename...> class ObjectType = std::map,
-         template<typename, typename...> class ArrayType = std::vector,
-         class StringType = std::string, class BooleanType = bool,
-         class NumberIntegerType = std::int64_t,
-         class NumberUnsignedType = std::uint64_t,
-         class NumberFloatType = double,
-         template<typename> class AllocatorType = std::allocator,
-         template<typename, typename = void> class JSONSerializer = adl_serializer>
-class basic_json;
-
 // Ugly macros to avoid uglier copy-paste when specializing basic_json. They
 // may be removed in the future once the class is split.
 
@@ -154,17 +217,334 @@ class basic_json;
     NumberIntegerType, NumberUnsignedType, NumberFloatType,                \
     AllocatorType, JSONSerializer>
 
+/*!
+@brief Helper to determine whether there's a key_type for T.
 
+This helper is used to tell associative containers apart from other containers
+such as sequence containers. For instance, `std::map` passes the test as it
+contains a `mapped_type`, whereas `std::vector` fails the test.
+
+@sa http://stackoverflow.com/a/7728728/266378
+@since version 1.0.0, overworked in version 2.0.6
+*/
+#define NLOHMANN_JSON_HAS_HELPER(type)                                        \
+    template<typename T> struct has_##type {                                  \
+    private:                                                                  \
+        template<typename U, typename = typename U::type>                     \
+        static int detect(U &&);                                              \
+        static void detect(...);                                              \
+    public:                                                                   \
+        static constexpr bool value =                                         \
+                std::is_integral<decltype(detect(std::declval<T>()))>::value; \
+    }
+
+// #include <nlohmann/detail/meta/cpp_future.hpp>
+
+
+#include <ciso646> // not
+#include <cstddef> // size_t
+#include <type_traits> // conditional, enable_if, false_type, integral_constant, is_constructible, is_integral, is_same, remove_cv, remove_reference, true_type
+
+namespace nlohmann
+{
+namespace detail
+{
+// alias templates to reduce boilerplate
+template<bool B, typename T = void>
+using enable_if_t = typename std::enable_if<B, T>::type;
+
+template<typename T>
+using uncvref_t = typename std::remove_cv<typename std::remove_reference<T>::type>::type;
+
+// implementation of C++14 index_sequence and affiliates
+// source: https://stackoverflow.com/a/32223343
+template<std::size_t... Ints>
+struct index_sequence
+{
+    using type = index_sequence;
+    using value_type = std::size_t;
+    static constexpr std::size_t size() noexcept
+    {
+        return sizeof...(Ints);
+    }
+};
+
+template<class Sequence1, class Sequence2>
+struct merge_and_renumber;
+
+template<std::size_t... I1, std::size_t... I2>
+struct merge_and_renumber<index_sequence<I1...>, index_sequence<I2...>>
+        : index_sequence < I1..., (sizeof...(I1) + I2)... > {};
+
+template<std::size_t N>
+struct make_index_sequence
+    : merge_and_renumber < typename make_index_sequence < N / 2 >::type,
+      typename make_index_sequence < N - N / 2 >::type > {};
+
+template<> struct make_index_sequence<0> : index_sequence<> {};
+template<> struct make_index_sequence<1> : index_sequence<0> {};
+
+template<typename... Ts>
+using index_sequence_for = make_index_sequence<sizeof...(Ts)>;
+
+/*
+Implementation of two C++17 constructs: conjunction, negation. This is needed
+to avoid evaluating all the traits in a condition
+
+For example: not std::is_same<void, T>::value and has_value_type<T>::value
+will not compile when T = void (on MSVC at least). Whereas
+conjunction<negation<std::is_same<void, T>>, has_value_type<T>>::value will
+stop evaluating if negation<...>::value == false
+
+Please note that those constructs must be used with caution, since symbols can
+become very long quickly (which can slow down compilation and cause MSVC
+internal compiler errors). Only use it when you have to (see example ahead).
+*/
+template<class...> struct conjunction : std::true_type {};
+template<class B1> struct conjunction<B1> : B1 {};
+template<class B1, class... Bn>
+struct conjunction<B1, Bn...> : std::conditional<bool(B1::value), conjunction<Bn...>, B1>::type {};
+
+template<class B> struct negation : std::integral_constant<bool, not B::value> {};
+
+// dispatch utility (taken from ranges-v3)
+template<unsigned N> struct priority_tag : priority_tag < N - 1 > {};
+template<> struct priority_tag<0> {};
+
+// taken from ranges-v3
+template<typename T>
+struct static_const
+{
+    static constexpr T value{};
+};
+
+template<typename T>
+constexpr T static_const<T>::value;
+}
+}
+
+// #include <nlohmann/detail/meta/type_traits.hpp>
+
+
+#include <ciso646> // not
+#include <limits> // numeric_limits
+#include <type_traits> // false_type, is_constructible, is_integral, is_same, true_type
+#include <utility> // declval
+
+// #include <nlohmann/json_fwd.hpp>
+
+// #include <nlohmann/detail/meta/cpp_future.hpp>
+
+// #include <nlohmann/detail/macro_scope.hpp>
+
+
+namespace nlohmann
+{
 /*!
-@brief unnamed namespace with internal helper functions
+@brief detail namespace with internal helper functions
 
-This namespace collects some functions that could not be defined inside the
-@ref basic_json class.
+This namespace collects functions that should not be exposed,
+implementations of some @ref basic_json methods, and meta-programming helpers.
 
 @since version 2.1.0
 */
 namespace detail
 {
+/////////////
+// helpers //
+/////////////
+
+template<typename> struct is_basic_json : std::false_type {};
+
+NLOHMANN_BASIC_JSON_TPL_DECLARATION
+struct is_basic_json<NLOHMANN_BASIC_JSON_TPL> : std::true_type {};
+
+////////////////////////
+// has_/is_ functions //
+////////////////////////
+
+// source: https://stackoverflow.com/a/37193089/4116453
+
+template <typename T, typename = void>
+struct is_complete_type : std::false_type {};
+
+template <typename T>
+struct is_complete_type<T, decltype(void(sizeof(T)))> : std::true_type {};
+
+NLOHMANN_JSON_HAS_HELPER(mapped_type);
+NLOHMANN_JSON_HAS_HELPER(key_type);
+NLOHMANN_JSON_HAS_HELPER(value_type);
+NLOHMANN_JSON_HAS_HELPER(iterator);
+
+template<bool B, class RealType, class CompatibleObjectType>
+struct is_compatible_object_type_impl : std::false_type {};
+
+template<class RealType, class CompatibleObjectType>
+struct is_compatible_object_type_impl<true, RealType, CompatibleObjectType>
+{
+    static constexpr auto value =
+        std::is_constructible<typename RealType::key_type, typename CompatibleObjectType::key_type>::value and
+        std::is_constructible<typename RealType::mapped_type, typename CompatibleObjectType::mapped_type>::value;
+};
+
+template<bool B, class RealType, class CompatibleStringType>
+struct is_compatible_string_type_impl : std::false_type {};
+
+template<class RealType, class CompatibleStringType>
+struct is_compatible_string_type_impl<true, RealType, CompatibleStringType>
+{
+    static constexpr auto value =
+        std::is_same<typename RealType::value_type, typename CompatibleStringType::value_type>::value and
+        std::is_constructible<RealType, CompatibleStringType>::value;
+};
+
+template<class BasicJsonType, class CompatibleObjectType>
+struct is_compatible_object_type
+{
+    static auto constexpr value = is_compatible_object_type_impl <
+                                  conjunction<negation<std::is_same<void, CompatibleObjectType>>,
+                                  has_mapped_type<CompatibleObjectType>,
+                                  has_key_type<CompatibleObjectType>>::value,
+                                  typename BasicJsonType::object_t, CompatibleObjectType >::value;
+};
+
+template<class BasicJsonType, class CompatibleStringType>
+struct is_compatible_string_type
+{
+    static auto constexpr value = is_compatible_string_type_impl <
+                                  conjunction<negation<std::is_same<void, CompatibleStringType>>,
+                                  has_value_type<CompatibleStringType>>::value,
+                                  typename BasicJsonType::string_t, CompatibleStringType >::value;
+};
+
+template<typename BasicJsonType, typename T>
+struct is_basic_json_nested_type
+{
+    static auto constexpr value = std::is_same<T, typename BasicJsonType::iterator>::value or
+                                  std::is_same<T, typename BasicJsonType::const_iterator>::value or
+                                  std::is_same<T, typename BasicJsonType::reverse_iterator>::value or
+                                  std::is_same<T, typename BasicJsonType::const_reverse_iterator>::value;
+};
+
+template<class BasicJsonType, class CompatibleArrayType>
+struct is_compatible_array_type
+{
+    static auto constexpr value =
+        conjunction<negation<std::is_same<void, CompatibleArrayType>>,
+        negation<is_compatible_object_type<
+        BasicJsonType, CompatibleArrayType>>,
+        negation<std::is_constructible<typename BasicJsonType::string_t,
+        CompatibleArrayType>>,
+        negation<is_basic_json_nested_type<BasicJsonType, CompatibleArrayType>>,
+        has_value_type<CompatibleArrayType>,
+        has_iterator<CompatibleArrayType>>::value;
+};
+
+template<bool, typename, typename>
+struct is_compatible_integer_type_impl : std::false_type {};
+
+template<typename RealIntegerType, typename CompatibleNumberIntegerType>
+struct is_compatible_integer_type_impl<true, RealIntegerType, CompatibleNumberIntegerType>
+{
+    // is there an assert somewhere on overflows?
+    using RealLimits = std::numeric_limits<RealIntegerType>;
+    using CompatibleLimits = std::numeric_limits<CompatibleNumberIntegerType>;
+
+    static constexpr auto value =
+        std::is_constructible<RealIntegerType, CompatibleNumberIntegerType>::value and
+        CompatibleLimits::is_integer and
+        RealLimits::is_signed == CompatibleLimits::is_signed;
+};
+
+template<typename RealIntegerType, typename CompatibleNumberIntegerType>
+struct is_compatible_integer_type
+{
+    static constexpr auto value =
+        is_compatible_integer_type_impl <
+        std::is_integral<CompatibleNumberIntegerType>::value and
+        not std::is_same<bool, CompatibleNumberIntegerType>::value,
+        RealIntegerType, CompatibleNumberIntegerType > ::value;
+};
+
+// trait checking if JSONSerializer<T>::from_json(json const&, udt&) exists
+template<typename BasicJsonType, typename T>
+struct has_from_json
+{
+  private:
+    // also check the return type of from_json
+    template<typename U, typename = enable_if_t<std::is_same<void, decltype(uncvref_t<U>::from_json(
+                 std::declval<BasicJsonType>(), std::declval<T&>()))>::value>>
+    static int detect(U&&);
+    static void detect(...);
+
+  public:
+    static constexpr bool value = std::is_integral<decltype(
+                                      detect(std::declval<typename BasicJsonType::template json_serializer<T, void>>()))>::value;
+};
+
+// This trait checks if JSONSerializer<T>::from_json(json const&) exists
+// this overload is used for non-default-constructible user-defined-types
+template<typename BasicJsonType, typename T>
+struct has_non_default_from_json
+{
+  private:
+    template <
+        typename U,
+        typename = enable_if_t<std::is_same<
+                                   T, decltype(uncvref_t<U>::from_json(std::declval<BasicJsonType>()))>::value >>
+    static int detect(U&&);
+    static void detect(...);
+
+  public:
+    static constexpr bool value = std::is_integral<decltype(detect(
+                                      std::declval<typename BasicJsonType::template json_serializer<T, void>>()))>::value;
+};
+
+// This trait checks if BasicJsonType::json_serializer<T>::to_json exists
+template<typename BasicJsonType, typename T>
+struct has_to_json
+{
+  private:
+    template<typename U, typename = decltype(uncvref_t<U>::to_json(
+                 std::declval<BasicJsonType&>(), std::declval<T>()))>
+    static int detect(U&&);
+    static void detect(...);
+
+  public:
+    static constexpr bool value = std::is_integral<decltype(detect(
+                                      std::declval<typename BasicJsonType::template json_serializer<T, void>>()))>::value;
+};
+
+template <typename BasicJsonType, typename CompatibleCompleteType>
+struct is_compatible_complete_type
+{
+    static constexpr bool value =
+        not std::is_base_of<std::istream, CompatibleCompleteType>::value and
+        not is_basic_json<CompatibleCompleteType>::value and
+        not is_basic_json_nested_type<BasicJsonType, CompatibleCompleteType>::value and
+        has_to_json<BasicJsonType, CompatibleCompleteType>::value;
+};
+
+template <typename BasicJsonType, typename CompatibleType>
+struct is_compatible_type
+    : conjunction<is_complete_type<CompatibleType>,
+      is_compatible_complete_type<BasicJsonType, CompatibleType>>
+{
+};
+}
+}
+
+// #include <nlohmann/detail/exceptions.hpp>
+
+
+#include <exception> // exception
+#include <stdexcept> // runtime_error
+#include <string> // to_string
+
+namespace nlohmann
+{
+namespace detail
+{
 ////////////////
 // exceptions //
 ////////////////
@@ -419,6 +799,8 @@ json.exception.out_of_range.403 | key 'foo' not found 
 json.exception.out_of_range.404 | unresolved reference token 'foo' | A reference token in a JSON Pointer could not be resolved.
 json.exception.out_of_range.405 | JSON pointer has no parent | The JSON Patch operations 'remove' and 'add' can not be applied to the root element of the JSON value.
 json.exception.out_of_range.406 | number overflow parsing '10E1000' | A parsed number could not be stored as without changing it to NaN or INF.
+json.exception.out_of_range.407 | number overflow serializing '9223372036854775808' | UBJSON only supports integers numbers up to 9223372036854775807. |
+json.exception.out_of_range.408 | excessive array size: 8658170730974374167 | The size (following `#`) of an UBJSON array or object exceeds the maximal capacity. |
 
 @liveexample{The following code shows how an `out_of_range` exception can be
 caught.,out_of_range}
@@ -481,9 +863,21 @@ class other_error : public exception
   private:
     other_error(int id_, const char* what_arg) : exception(id_, what_arg) {}
 };
+}
+}
 
+// #include <nlohmann/detail/value_t.hpp>
 
 
+#include <array> // array
+#include <ciso646> // and
+#include <cstddef> // size_t
+#include <cstdint> // uint8_t
+
+namespace nlohmann
+{
+namespace detail
+{
 ///////////////////////////
 // JSON type enumeration //
 ///////////////////////////
@@ -512,7 +906,7 @@ value with the default value for a given type
 
 @since version 1.0.0
 */
-enum class value_t : uint8_t
+enum class value_t : std::uint8_t
 {
     null,             ///< null value
     object,           ///< object (unordered set of name/value pairs)
@@ -537,7 +931,7 @@ Returns an ordering that is similar to Python:
 */
 inline bool operator<(const value_t lhs, const value_t rhs) noexcept
 {
-    static constexpr std::array<uint8_t, 8> order = {{
+    static constexpr std::array<std::uint8_t, 8> order = {{
             0 /* null */, 3 /* object */, 4 /* array */, 5 /* string */,
             1 /* boolean */, 2 /* integer */, 2 /* unsigned */, 2 /* float */
         }
@@ -547,80 +941,558 @@ inline bool operator<(const value_t lhs, const value_t
     const auto r_index = static_cast<std::size_t>(rhs);
     return l_index < order.size() and r_index < order.size() and order[l_index] < order[r_index];
 }
+}
+}
 
+// #include <nlohmann/detail/conversions/from_json.hpp>
 
-/////////////
-// helpers //
-/////////////
 
-template<typename> struct is_basic_json : std::false_type {};
+#include <algorithm> // transform
+#include <array> // array
+#include <ciso646> // and, not
+#include <forward_list> // forward_list
+#include <iterator> // inserter, front_inserter, end
+#include <map> // map
+#include <string> // string
+#include <tuple> // tuple, make_tuple
+#include <type_traits> // is_arithmetic, is_same, is_enum, underlying_type, is_convertible
+#include <unordered_map> // unordered_map
+#include <utility> // pair, declval
+#include <valarray> // valarray
 
-NLOHMANN_BASIC_JSON_TPL_DECLARATION
-struct is_basic_json<NLOHMANN_BASIC_JSON_TPL> : std::true_type {};
+// #include <nlohmann/detail/exceptions.hpp>
 
-// alias templates to reduce boilerplate
-template<bool B, typename T = void>
-using enable_if_t = typename std::enable_if<B, T>::type;
+// #include <nlohmann/detail/macro_scope.hpp>
 
-template<typename T>
-using uncvref_t = typename std::remove_cv<typename std::remove_reference<T>::type>::type;
+// #include <nlohmann/detail/meta/cpp_future.hpp>
 
-// implementation of C++14 index_sequence and affiliates
-// source: https://stackoverflow.com/a/32223343
-template<std::size_t... Ints>
-struct index_sequence
+// #include <nlohmann/detail/meta/type_traits.hpp>
+
+// #include <nlohmann/detail/value_t.hpp>
+
+
+namespace nlohmann
 {
-    using type = index_sequence;
-    using value_type = std::size_t;
-    static constexpr std::size_t size() noexcept
+namespace detail
+{
+template<typename BasicJsonType>
+void from_json(const BasicJsonType& j, typename std::nullptr_t& n)
+{
+    if (JSON_UNLIKELY(not j.is_null()))
     {
-        return sizeof...(Ints);
+        JSON_THROW(type_error::create(302, "type must be null, but is " + std::string(j.type_name())));
     }
+    n = nullptr;
+}
+
+// overloads for basic_json template parameters
+template<typename BasicJsonType, typename ArithmeticType,
+         enable_if_t<std::is_arithmetic<ArithmeticType>::value and
+                     not std::is_same<ArithmeticType, typename BasicJsonType::boolean_t>::value,
+                     int> = 0>
+void get_arithmetic_value(const BasicJsonType& j, ArithmeticType& val)
+{
+    switch (static_cast<value_t>(j))
+    {
+        case value_t::number_unsigned:
+        {
+            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_unsigned_t*>());
+            break;
+        }
+        case value_t::number_integer:
+        {
+            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_integer_t*>());
+            break;
+        }
+        case value_t::number_float:
+        {
+            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_float_t*>());
+            break;
+        }
+
+        default:
+            JSON_THROW(type_error::create(302, "type must be number, but is " + std::string(j.type_name())));
+    }
+}
+
+template<typename BasicJsonType>
+void from_json(const BasicJsonType& j, typename BasicJsonType::boolean_t& b)
+{
+    if (JSON_UNLIKELY(not j.is_boolean()))
+    {
+        JSON_THROW(type_error::create(302, "type must be boolean, but is " + std::string(j.type_name())));
+    }
+    b = *j.template get_ptr<const typename BasicJsonType::boolean_t*>();
+}
+
+template<typename BasicJsonType>
+void from_json(const BasicJsonType& j, typename BasicJsonType::string_t& s)
+{
+    if (JSON_UNLIKELY(not j.is_string()))
+    {
+        JSON_THROW(type_error::create(302, "type must be string, but is " + std::string(j.type_name())));
+    }
+    s = *j.template get_ptr<const typename BasicJsonType::string_t*>();
+}
+
+template <
+    typename BasicJsonType, typename CompatibleStringType,
+    enable_if_t <
+        is_compatible_string_type<BasicJsonType, CompatibleStringType>::value and
+        not std::is_same<typename BasicJsonType::string_t,
+                         CompatibleStringType>::value,
+        int > = 0 >
+void from_json(const BasicJsonType& j, CompatibleStringType& s)
+{
+    if (JSON_UNLIKELY(not j.is_string()))
+    {
+        JSON_THROW(type_error::create(302, "type must be string, but is " + std::string(j.type_name())));
+    }
+
+    s = *j.template get_ptr<const typename BasicJsonType::string_t*>();
+}
+
+template<typename BasicJsonType>
+void from_json(const BasicJsonType& j, typename BasicJsonType::number_float_t& val)
+{
+    get_arithmetic_value(j, val);
+}
+
+template<typename BasicJsonType>
+void from_json(const BasicJsonType& j, typename BasicJsonType::number_unsigned_t& val)
+{
+    get_arithmetic_value(j, val);
+}
+
+template<typename BasicJsonType>
+void from_json(const BasicJsonType& j, typename BasicJsonType::number_integer_t& val)
+{
+    get_arithmetic_value(j, val);
+}
+
+template<typename BasicJsonType, typename EnumType,
+         enable_if_t<std::is_enum<EnumType>::value, int> = 0>
+void from_json(const BasicJsonType& j, EnumType& e)
+{
+    typename std::underlying_type<EnumType>::type val;
+    get_arithmetic_value(j, val);
+    e = static_cast<EnumType>(val);
+}
+
+template<typename BasicJsonType>
+void from_json(const BasicJsonType& j, typename BasicJsonType::array_t& arr)
+{
+    if (JSON_UNLIKELY(not j.is_array()))
+    {
+        JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
+    }
+    arr = *j.template get_ptr<const typename BasicJsonType::array_t*>();
+}
+
+// forward_list doesn't have an insert method
+template<typename BasicJsonType, typename T, typename Allocator,
+         enable_if_t<std::is_convertible<BasicJsonType, T>::value, int> = 0>
+void from_json(const BasicJsonType& j, std::forward_list<T, Allocator>& l)
+{
+    if (JSON_UNLIKELY(not j.is_array()))
+    {
+        JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
+    }
+    std::transform(j.rbegin(), j.rend(),
+                   std::front_inserter(l), [](const BasicJsonType & i)
+    {
+        return i.template get<T>();
+    });
+}
+
+// valarray doesn't have an insert method
+template<typename BasicJsonType, typename T,
+         enable_if_t<std::is_convertible<BasicJsonType, T>::value, int> = 0>
+void from_json(const BasicJsonType& j, std::valarray<T>& l)
+{
+    if (JSON_UNLIKELY(not j.is_array()))
+    {
+        JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
+    }
+    l.resize(j.size());
+    std::copy(j.m_value.array->begin(), j.m_value.array->end(), std::begin(l));
+}
+
+template<typename BasicJsonType, typename CompatibleArrayType>
+void from_json_array_impl(const BasicJsonType& j, CompatibleArrayType& arr, priority_tag<0> /*unused*/)
+{
+    using std::end;
+
+    std::transform(j.begin(), j.end(),
+                   std::inserter(arr, end(arr)), [](const BasicJsonType & i)
+    {
+        // get<BasicJsonType>() returns *this, this won't call a from_json
+        // method when value_type is BasicJsonType
+        return i.template get<typename CompatibleArrayType::value_type>();
+    });
+}
+
+template<typename BasicJsonType, typename CompatibleArrayType>
+auto from_json_array_impl(const BasicJsonType& j, CompatibleArrayType& arr, priority_tag<1> /*unused*/)
+-> decltype(
+    arr.reserve(std::declval<typename CompatibleArrayType::size_type>()),
+    void())
+{
+    using std::end;
+
+    arr.reserve(j.size());
+    std::transform(j.begin(), j.end(),
+                   std::inserter(arr, end(arr)), [](const BasicJsonType & i)
+    {
+        // get<BasicJsonType>() returns *this, this won't call a from_json
+        // method when value_type is BasicJsonType
+        return i.template get<typename CompatibleArrayType::value_type>();
+    });
+}
+
+template<typename BasicJsonType, typename T, std::size_t N>
+void from_json_array_impl(const BasicJsonType& j, std::array<T, N>& arr, priority_tag<2> /*unused*/)
+{
+    for (std::size_t i = 0; i < N; ++i)
+    {
+        arr[i] = j.at(i).template get<T>();
+    }
+}
+
+template <
+    typename BasicJsonType, typename CompatibleArrayType,
+    enable_if_t <
+        is_compatible_array_type<BasicJsonType, CompatibleArrayType>::value and
+        not std::is_same<typename BasicJsonType::array_t,
+                         CompatibleArrayType>::value and
+        std::is_constructible <
+            BasicJsonType, typename CompatibleArrayType::value_type >::value,
+        int > = 0 >
+void from_json(const BasicJsonType& j, CompatibleArrayType& arr)
+{
+    if (JSON_UNLIKELY(not j.is_array()))
+    {
+        JSON_THROW(type_error::create(302, "type must be array, but is " +
+                                      std::string(j.type_name())));
+    }
+
+    from_json_array_impl(j, arr, priority_tag<2> {});
+}
+
+template<typename BasicJsonType, typename CompatibleObjectType,
+         enable_if_t<is_compatible_object_type<BasicJsonType, CompatibleObjectType>::value, int> = 0>
+void from_json(const BasicJsonType& j, CompatibleObjectType& obj)
+{
+    if (JSON_UNLIKELY(not j.is_object()))
+    {
+        JSON_THROW(type_error::create(302, "type must be object, but is " + std::string(j.type_name())));
+    }
+
+    auto inner_object = j.template get_ptr<const typename BasicJsonType::object_t*>();
+    using value_type = typename CompatibleObjectType::value_type;
+    std::transform(
+        inner_object->begin(), inner_object->end(),
+        std::inserter(obj, obj.begin()),
+        [](typename BasicJsonType::object_t::value_type const & p)
+    {
+        return value_type(p.first, p.second.template get<typename CompatibleObjectType::mapped_type>());
+    });
+}
+
+// overload for arithmetic types, not chosen for basic_json template arguments
+// (BooleanType, etc..); note: Is it really necessary to provide explicit
+// overloads for boolean_t etc. in case of a custom BooleanType which is not
+// an arithmetic type?
+template<typename BasicJsonType, typename ArithmeticType,
+         enable_if_t <
+             std::is_arithmetic<ArithmeticType>::value and
+             not std::is_same<ArithmeticType, typename BasicJsonType::number_unsigned_t>::value and
+             not std::is_same<ArithmeticType, typename BasicJsonType::number_integer_t>::value and
+             not std::is_same<ArithmeticType, typename BasicJsonType::number_float_t>::value and
+             not std::is_same<ArithmeticType, typename BasicJsonType::boolean_t>::value,
+             int> = 0>
+void from_json(const BasicJsonType& j, ArithmeticType& val)
+{
+    switch (static_cast<value_t>(j))
+    {
+        case value_t::number_unsigned:
+        {
+            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_unsigned_t*>());
+            break;
+        }
+        case value_t::number_integer:
+        {
+            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_integer_t*>());
+            break;
+        }
+        case value_t::number_float:
+        {
+            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_float_t*>());
+            break;
+        }
+        case value_t::boolean:
+        {
+            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::boolean_t*>());
+            break;
+        }
+
+        default:
+            JSON_THROW(type_error::create(302, "type must be number, but is " + std::string(j.type_name())));
+    }
+}
+
+template<typename BasicJsonType, typename A1, typename A2>
+void from_json(const BasicJsonType& j, std::pair<A1, A2>& p)
+{
+    p = {j.at(0).template get<A1>(), j.at(1).template get<A2>()};
+}
+
+template<typename BasicJsonType, typename Tuple, std::size_t... Idx>
+void from_json_tuple_impl(const BasicJsonType& j, Tuple& t, index_sequence<Idx...>)
+{
+    t = std::make_tuple(j.at(Idx).template get<typename std::tuple_element<Idx, Tuple>::type>()...);
+}
+
+template<typename BasicJsonType, typename... Args>
+void from_json(const BasicJsonType& j, std::tuple<Args...>& t)
+{
+    from_json_tuple_impl(j, t, index_sequence_for<Args...> {});
+}
+
+template <typename BasicJsonType, typename Key, typename Value, typename Compare, typename Allocator,
+          typename = enable_if_t<not std::is_constructible<
+                                     typename BasicJsonType::string_t, Key>::value>>
+void from_json(const BasicJsonType& j, std::map<Key, Value, Compare, Allocator>& m)
+{
+    if (JSON_UNLIKELY(not j.is_array()))
+    {
+        JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
+    }
+    for (const auto& p : j)
+    {
+        if (JSON_UNLIKELY(not p.is_array()))
+        {
+            JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(p.type_name())));
+        }
+        m.emplace(p.at(0).template get<Key>(), p.at(1).template get<Value>());
+    }
+}
+
+template <typename BasicJsonType, typename Key, typename Value, typename Hash, typename KeyEqual, typename Allocator,
+          typename = enable_if_t<not std::is_constructible<
+                                     typename BasicJsonType::string_t, Key>::value>>
+void from_json(const BasicJsonType& j, std::unordered_map<Key, Value, Hash, KeyEqual, Allocator>& m)
+{
+    if (JSON_UNLIKELY(not j.is_array()))
+    {
+        JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
+    }
+    for (const auto& p : j)
+    {
+        if (JSON_UNLIKELY(not p.is_array()))
+        {
+            JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(p.type_name())));
+        }
+        m.emplace(p.at(0).template get<Key>(), p.at(1).template get<Value>());
+    }
+}
+
+struct from_json_fn
+{
+  private:
+    template<typename BasicJsonType, typename T>
+    auto call(const BasicJsonType& j, T& val, priority_tag<1> /*unused*/) const
+    noexcept(noexcept(from_json(j, val)))
+    -> decltype(from_json(j, val), void())
+    {
+        return from_json(j, val);
+    }
+
+    template<typename BasicJsonType, typename T>
+    void call(const BasicJsonType& /*unused*/, T& /*unused*/, priority_tag<0> /*unused*/) const noexcept
+    {
+        static_assert(sizeof(BasicJsonType) == 0,
+                      "could not find from_json() method in T's namespace");
+#ifdef _MSC_VER
+        // MSVC does not show a stacktrace for the above assert
+        using decayed = uncvref_t<T>;
+        static_assert(sizeof(typename decayed::force_msvc_stacktrace) == 0,
+                      "forcing MSVC stacktrace to show which T we're talking about.");
+#endif
+    }
+
+  public:
+    template<typename BasicJsonType, typename T>
+    void operator()(const BasicJsonType& j, T& val) const
+    noexcept(noexcept(std::declval<from_json_fn>().call(j, val, priority_tag<1> {})))
+    {
+        return call(j, val, priority_tag<1> {});
+    }
 };
+}
 
-template<class Sequence1, class Sequence2>
-struct merge_and_renumber;
+/// namespace to hold default `from_json` function
+/// to see why this is required:
+/// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4381.html
+namespace
+{
+constexpr const auto& from_json = detail::static_const<detail::from_json_fn>::value;
+}
+}
 
-template<std::size_t... I1, std::size_t... I2>
-struct merge_and_renumber<index_sequence<I1...>, index_sequence<I2...>>
-        : index_sequence < I1..., (sizeof...(I1) + I2)... > {};
+// #include <nlohmann/detail/conversions/to_json.hpp>
 
-template<std::size_t N>
-struct make_index_sequence
-    : merge_and_renumber < typename make_index_sequence < N / 2 >::type,
-      typename make_index_sequence < N - N / 2 >::type > {};
 
-template<> struct make_index_sequence<0> : index_sequence<> {};
-template<> struct make_index_sequence<1> : index_sequence<0> {};
+#include <ciso646> // or, and, not
+#include <iterator> // begin, end
+#include <tuple> // tuple, get
+#include <type_traits> // is_same, is_constructible, is_floating_point, is_enum, underlying_type
+#include <utility> // move, forward, declval, pair
+#include <valarray> // valarray
+#include <vector> // vector
 
-template<typename... Ts>
-using index_sequence_for = make_index_sequence<sizeof...(Ts)>;
+// #include <nlohmann/detail/meta/cpp_future.hpp>
 
-/*
-Implementation of two C++17 constructs: conjunction, negation. This is needed
-to avoid evaluating all the traits in a condition
+// #include <nlohmann/detail/meta/type_traits.hpp>
 
-For example: not std::is_same<void, T>::value and has_value_type<T>::value
-will not compile when T = void (on MSVC at least). Whereas
-conjunction<negation<std::is_same<void, T>>, has_value_type<T>>::value will
-stop evaluating if negation<...>::value == false
+// #include <nlohmann/detail/value_t.hpp>
 
-Please note that those constructs must be used with caution, since symbols can
-become very long quickly (which can slow down compilation and cause MSVC
-internal compiler errors). Only use it when you have to (see example ahead).
-*/
-template<class...> struct conjunction : std::true_type {};
-template<class B1> struct conjunction<B1> : B1 {};
-template<class B1, class... Bn>
-struct conjunction<B1, Bn...> : std::conditional<bool(B1::value), conjunction<Bn...>, B1>::type {};
+// #include <nlohmann/detail/iterators/iteration_proxy.hpp>
 
-template<class B> struct negation : std::integral_constant<bool, not B::value> {};
 
-// dispatch utility (taken from ranges-v3)
-template<unsigned N> struct priority_tag : priority_tag < N - 1 > {};
-template<> struct priority_tag<0> {};
+#include <cstddef> // size_t
+#include <string> // string, to_string
+#include <iterator> // input_iterator_tag
 
+// #include <nlohmann/detail/value_t.hpp>
 
+
+namespace nlohmann
+{
+namespace detail
+{
+/// proxy class for the items() function
+template<typename IteratorType> class iteration_proxy
+{
+  private:
+    /// helper class for iteration
+    class iteration_proxy_internal
+    {
+      public:
+        using difference_type = std::ptrdiff_t;
+        using value_type = iteration_proxy_internal;
+        using pointer = iteration_proxy_internal*;
+        using reference = iteration_proxy_internal&;
+        using iterator_category = std::input_iterator_tag;
+
+      private:
+        /// the iterator
+        IteratorType anchor;
+        /// an index for arrays (used to create key names)
+        std::size_t array_index = 0;
+        /// last stringified array index
+        mutable std::size_t array_index_last = 0;
+        /// a string representation of the array index
+        mutable std::string array_index_str = "0";
+        /// an empty string (to return a reference for primitive values)
+        const std::string empty_str = "";
+
+      public:
+        explicit iteration_proxy_internal(IteratorType it) noexcept : anchor(it) {}
+
+        iteration_proxy_internal(const iteration_proxy_internal&) = default;
+        iteration_proxy_internal& operator=(const iteration_proxy_internal&) = default;
+
+        /// dereference operator (needed for range-based for)
+        iteration_proxy_internal& operator*()
+        {
+            return *this;
+        }
+
+        /// increment operator (needed for range-based for)
+        iteration_proxy_internal& operator++()
+        {
+            ++anchor;
+            ++array_index;
+
+            return *this;
+        }
+
+        /// equality operator (needed for InputIterator)
+        bool operator==(const iteration_proxy_internal& o) const noexcept
+        {
+            return anchor == o.anchor;
+        }
+
+        /// inequality operator (needed for range-based for)
+        bool operator!=(const iteration_proxy_internal& o) const noexcept
+        {
+            return anchor != o.anchor;
+        }
+
+        /// return key of the iterator
+        const std::string& key() const
+        {
+            assert(anchor.m_object != nullptr);
+
+            switch (anchor.m_object->type())
+            {
+                // use integer array index as key
+                case value_t::array:
+                {
+                    if (array_index != array_index_last)
+                    {
+                        array_index_str = std::to_string(array_index);
+                        array_index_last = array_index;
+                    }
+                    return array_index_str;
+                }
+
+                // use key from the object
+                case value_t::object:
+                    return anchor.key();
+
+                // use an empty key for all primitive types
+                default:
+                    return empty_str;
+            }
+        }
+
+        /// return value of the iterator
+        typename IteratorType::reference value() const
+        {
+            return anchor.value();
+        }
+    };
+
+    /// the container to iterate
+    typename IteratorType::reference container;
+
+  public:
+    /// construct iteration proxy from a container
+    explicit iteration_proxy(typename IteratorType::reference cont) noexcept
+        : container(cont) {}
+
+    /// return iterator begin (needed for range-based for)
+    iteration_proxy_internal begin() noexcept
+    {
+        return iteration_proxy_internal(container.begin());
+    }
+
+    /// return iterator end (needed for range-based for)
+    iteration_proxy_internal end() noexcept
+    {
+        return iteration_proxy_internal(container.end());
+    }
+};
+}
+}
+
+
+namespace nlohmann
+{
+namespace detail
+{
 //////////////////
 // constructors //
 //////////////////
@@ -657,6 +1529,16 @@ struct external_constructor<value_t::string>
         j.m_value = std::move(s);
         j.assert_invariant();
     }
+
+    template<typename BasicJsonType, typename CompatibleStringType,
+             enable_if_t<not std::is_same<CompatibleStringType, typename BasicJsonType::string_t>::value,
+                         int> = 0>
+    static void construct(BasicJsonType& j, const CompatibleStringType& str)
+    {
+        j.m_type = value_t::string;
+        j.m_value.string = j.template create<typename BasicJsonType::string_t>(str);
+        j.assert_invariant();
+    }
 };
 
 template<>
@@ -783,159 +1665,6 @@ struct external_constructor<value_t::object>
     }
 };
 
-
-////////////////////////
-// has_/is_ functions //
-////////////////////////
-
-/*!
-@brief Helper to determine whether there's a key_type for T.
-
-This helper is used to tell associative containers apart from other containers
-such as sequence containers. For instance, `std::map` passes the test as it
-contains a `mapped_type`, whereas `std::vector` fails the test.
-
-@sa http://stackoverflow.com/a/7728728/266378
-@since version 1.0.0, overworked in version 2.0.6
-*/
-#define NLOHMANN_JSON_HAS_HELPER(type)                                        \
-    template<typename T> struct has_##type {                                  \
-    private:                                                                  \
-        template<typename U, typename = typename U::type>                     \
-        static int detect(U &&);                                              \
-        static void detect(...);                                              \
-    public:                                                                   \
-        static constexpr bool value =                                         \
-                std::is_integral<decltype(detect(std::declval<T>()))>::value; \
-    }
-
-NLOHMANN_JSON_HAS_HELPER(mapped_type);
-NLOHMANN_JSON_HAS_HELPER(key_type);
-NLOHMANN_JSON_HAS_HELPER(value_type);
-NLOHMANN_JSON_HAS_HELPER(iterator);
-
-#undef NLOHMANN_JSON_HAS_HELPER
-
-
-template<bool B, class RealType, class CompatibleObjectType>
-struct is_compatible_object_type_impl : std::false_type {};
-
-template<class RealType, class CompatibleObjectType>
-struct is_compatible_object_type_impl<true, RealType, CompatibleObjectType>
-{
-    static constexpr auto value =
-        std::is_constructible<typename RealType::key_type, typename CompatibleObjectType::key_type>::value and
-        std::is_constructible<typename RealType::mapped_type, typename CompatibleObjectType::mapped_type>::value;
-};
-
-template<class BasicJsonType, class CompatibleObjectType>
-struct is_compatible_object_type
-{
-    static auto constexpr value = is_compatible_object_type_impl <
-                                  conjunction<negation<std::is_same<void, CompatibleObjectType>>,
-                                  has_mapped_type<CompatibleObjectType>,
-                                  has_key_type<CompatibleObjectType>>::value,
-                                  typename BasicJsonType::object_t, CompatibleObjectType >::value;
-};
-
-template<typename BasicJsonType, typename T>
-struct is_basic_json_nested_type
-{
-    static auto constexpr value = std::is_same<T, typename BasicJsonType::iterator>::value or
-                                  std::is_same<T, typename BasicJsonType::const_iterator>::value or
-                                  std::is_same<T, typename BasicJsonType::reverse_iterator>::value or
-                                  std::is_same<T, typename BasicJsonType::const_reverse_iterator>::value;
-};
-
-template<class BasicJsonType, class CompatibleArrayType>
-struct is_compatible_array_type
-{
-    static auto constexpr value =
-        conjunction<negation<std::is_same<void, CompatibleArrayType>>,
-        negation<is_compatible_object_type<
-        BasicJsonType, CompatibleArrayType>>,
-        negation<std::is_constructible<typename BasicJsonType::string_t,
-        CompatibleArrayType>>,
-        negation<is_basic_json_nested_type<BasicJsonType, CompatibleArrayType>>,
-        has_value_type<CompatibleArrayType>,
-        has_iterator<CompatibleArrayType>>::value;
-};
-
-template<bool, typename, typename>
-struct is_compatible_integer_type_impl : std::false_type {};
-
-template<typename RealIntegerType, typename CompatibleNumberIntegerType>
-struct is_compatible_integer_type_impl<true, RealIntegerType, CompatibleNumberIntegerType>
-{
-    // is there an assert somewhere on overflows?
-    using RealLimits = std::numeric_limits<RealIntegerType>;
-    using CompatibleLimits = std::numeric_limits<CompatibleNumberIntegerType>;
-
-    static constexpr auto value =
-        std::is_constructible<RealIntegerType, CompatibleNumberIntegerType>::value and
-        CompatibleLimits::is_integer and
-        RealLimits::is_signed == CompatibleLimits::is_signed;
-};
-
-template<typename RealIntegerType, typename CompatibleNumberIntegerType>
-struct is_compatible_integer_type
-{
-    static constexpr auto value =
-        is_compatible_integer_type_impl <
-        std::is_integral<CompatibleNumberIntegerType>::value and
-        not std::is_same<bool, CompatibleNumberIntegerType>::value,
-        RealIntegerType, CompatibleNumberIntegerType >::value;
-};
-
-
-// trait checking if JSONSerializer<T>::from_json(json const&, udt&) exists
-template<typename BasicJsonType, typename T>
-struct has_from_json
-{
-  private:
-    // also check the return type of from_json
-    template<typename U, typename = enable_if_t<std::is_same<void, decltype(uncvref_t<U>::from_json(
-                 std::declval<BasicJsonType>(), std::declval<T&>()))>::value>>
-    static int detect(U&&);
-    static void detect(...);
-
-  public:
-    static constexpr bool value = std::is_integral<decltype(
-                                      detect(std::declval<typename BasicJsonType::template json_serializer<T, void>>()))>::value;
-};
-
-// This trait checks if JSONSerializer<T>::from_json(json const&) exists
-// this overload is used for non-default-constructible user-defined-types
-template<typename BasicJsonType, typename T>
-struct has_non_default_from_json
-{
-  private:
-    template<typename U, typename =
-             enable_if_t<std::is_same<T, decltype(uncvref_t<U>::from_json(std::declval<BasicJsonType>()))>::value>>
-    static int detect(U&&);
-    static void detect(...);
-
-  public:
-    static constexpr bool value = std::is_integral<decltype(detect(
-                                      std::declval<typename BasicJsonType::template json_serializer<T, void>>()))>::value;
-};
-
-// This trait checks if BasicJsonType::json_serializer<T>::to_json exists
-template<typename BasicJsonType, typename T>
-struct has_to_json
-{
-  private:
-    template<typename U, typename = decltype(uncvref_t<U>::to_json(
-                 std::declval<BasicJsonType&>(), std::declval<T>()))>
-    static int detect(U&&);
-    static void detect(...);
-
-  public:
-    static constexpr bool value = std::is_integral<decltype(detect(
-                                      std::declval<typename BasicJsonType::template json_serializer<T, void>>()))>::value;
-};
-
-
 /////////////
 // to_json //
 /////////////
@@ -1006,7 +1735,7 @@ void to_json(BasicJsonType& j, const CompatibleArrayTy
 
 template<typename BasicJsonType, typename T,
          enable_if_t<std::is_convertible<T, BasicJsonType>::value, int> = 0>
-void to_json(BasicJsonType& j, std::valarray<T> arr)
+void to_json(BasicJsonType& j, const std::valarray<T>& arr)
 {
     external_constructor<value_t::array>::construct(j, std::move(arr));
 }
@@ -1043,6 +1772,14 @@ void to_json(BasicJsonType& j, const std::pair<Args...
     j = {p.first, p.second};
 }
 
+// for https://github.com/nlohmann/json/pull/1134
+template<typename BasicJsonType, typename T,
+         enable_if_t<std::is_same<T, typename iteration_proxy<typename BasicJsonType::iterator>::iteration_proxy_internal>::value, int> = 0>
+void to_json(BasicJsonType& j, T b) noexcept
+{
+    j = {{b.key(), b.value()}};
+}
+
 template<typename BasicJsonType, typename Tuple, std::size_t... Idx>
 void to_json_tuple_impl(BasicJsonType& j, const Tuple& t, index_sequence<Idx...>)
 {
@@ -1055,261 +1792,6 @@ void to_json(BasicJsonType& j, const std::tuple<Args..
     to_json_tuple_impl(j, t, index_sequence_for<Args...> {});
 }
 
-///////////////
-// from_json //
-///////////////
-
-// overloads for basic_json template parameters
-template<typename BasicJsonType, typename ArithmeticType,
-         enable_if_t<std::is_arithmetic<ArithmeticType>::value and
-                     not std::is_same<ArithmeticType, typename BasicJsonType::boolean_t>::value,
-                     int> = 0>
-void get_arithmetic_value(const BasicJsonType& j, ArithmeticType& val)
-{
-    switch (static_cast<value_t>(j))
-    {
-        case value_t::number_unsigned:
-        {
-            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_unsigned_t*>());
-            break;
-        }
-        case value_t::number_integer:
-        {
-            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_integer_t*>());
-            break;
-        }
-        case value_t::number_float:
-        {
-            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_float_t*>());
-            break;
-        }
-
-        default:
-            JSON_THROW(type_error::create(302, "type must be number, but is " + std::string(j.type_name())));
-    }
-}
-
-template<typename BasicJsonType>
-void from_json(const BasicJsonType& j, typename BasicJsonType::boolean_t& b)
-{
-    if (JSON_UNLIKELY(not j.is_boolean()))
-    {
-        JSON_THROW(type_error::create(302, "type must be boolean, but is " + std::string(j.type_name())));
-    }
-    b = *j.template get_ptr<const typename BasicJsonType::boolean_t*>();
-}
-
-template<typename BasicJsonType>
-void from_json(const BasicJsonType& j, typename BasicJsonType::string_t& s)
-{
-    if (JSON_UNLIKELY(not j.is_string()))
-    {
-        JSON_THROW(type_error::create(302, "type must be string, but is " + std::string(j.type_name())));
-    }
-    s = *j.template get_ptr<const typename BasicJsonType::string_t*>();
-}
-
-template<typename BasicJsonType>
-void from_json(const BasicJsonType& j, typename BasicJsonType::number_float_t& val)
-{
-    get_arithmetic_value(j, val);
-}
-
-template<typename BasicJsonType>
-void from_json(const BasicJsonType& j, typename BasicJsonType::number_unsigned_t& val)
-{
-    get_arithmetic_value(j, val);
-}
-
-template<typename BasicJsonType>
-void from_json(const BasicJsonType& j, typename BasicJsonType::number_integer_t& val)
-{
-    get_arithmetic_value(j, val);
-}
-
-template<typename BasicJsonType, typename EnumType,
-         enable_if_t<std::is_enum<EnumType>::value, int> = 0>
-void from_json(const BasicJsonType& j, EnumType& e)
-{
-    typename std::underlying_type<EnumType>::type val;
-    get_arithmetic_value(j, val);
-    e = static_cast<EnumType>(val);
-}
-
-template<typename BasicJsonType>
-void from_json(const BasicJsonType& j, typename BasicJsonType::array_t& arr)
-{
-    if (JSON_UNLIKELY(not j.is_array()))
-    {
-        JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
-    }
-    arr = *j.template get_ptr<const typename BasicJsonType::array_t*>();
-}
-
-// forward_list doesn't have an insert method
-template<typename BasicJsonType, typename T, typename Allocator,
-         enable_if_t<std::is_convertible<BasicJsonType, T>::value, int> = 0>
-void from_json(const BasicJsonType& j, std::forward_list<T, Allocator>& l)
-{
-    if (JSON_UNLIKELY(not j.is_array()))
-    {
-        JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
-    }
-    std::transform(j.rbegin(), j.rend(),
-                   std::front_inserter(l), [](const BasicJsonType & i)
-    {
-        return i.template get<T>();
-    });
-}
-
-// valarray doesn't have an insert method
-template<typename BasicJsonType, typename T,
-         enable_if_t<std::is_convertible<BasicJsonType, T>::value, int> = 0>
-void from_json(const BasicJsonType& j, std::valarray<T>& l)
-{
-    if (JSON_UNLIKELY(not j.is_array()))
-    {
-        JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
-    }
-    l.resize(j.size());
-    std::copy(j.m_value.array->begin(), j.m_value.array->end(), std::begin(l));
-}
-
-template<typename BasicJsonType, typename CompatibleArrayType>
-void from_json_array_impl(const BasicJsonType& j, CompatibleArrayType& arr, priority_tag<0> /*unused*/)
-{
-    using std::end;
-
-    std::transform(j.begin(), j.end(),
-                   std::inserter(arr, end(arr)), [](const BasicJsonType & i)
-    {
-        // get<BasicJsonType>() returns *this, this won't call a from_json
-        // method when value_type is BasicJsonType
-        return i.template get<typename CompatibleArrayType::value_type>();
-    });
-}
-
-template<typename BasicJsonType, typename CompatibleArrayType>
-auto from_json_array_impl(const BasicJsonType& j, CompatibleArrayType& arr, priority_tag<1> /*unused*/)
--> decltype(
-    arr.reserve(std::declval<typename CompatibleArrayType::size_type>()),
-    void())
-{
-    using std::end;
-
-    arr.reserve(j.size());
-    std::transform(j.begin(), j.end(),
-                   std::inserter(arr, end(arr)), [](const BasicJsonType & i)
-    {
-        // get<BasicJsonType>() returns *this, this won't call a from_json
-        // method when value_type is BasicJsonType
-        return i.template get<typename CompatibleArrayType::value_type>();
-    });
-}
-
-template<typename BasicJsonType, typename T, std::size_t N>
-void from_json_array_impl(const BasicJsonType& j, std::array<T, N>& arr, priority_tag<2> /*unused*/)
-{
-    for (std::size_t i = 0; i < N; ++i)
-    {
-        arr[i] = j.at(i).template get<T>();
-    }
-}
-
-template<typename BasicJsonType, typename CompatibleArrayType,
-         enable_if_t<is_compatible_array_type<BasicJsonType, CompatibleArrayType>::value and
-                     std::is_convertible<BasicJsonType, typename CompatibleArrayType::value_type>::value and
-                     not std::is_same<typename BasicJsonType::array_t, CompatibleArrayType>::value, int> = 0>
-void from_json(const BasicJsonType& j, CompatibleArrayType& arr)
-{
-    if (JSON_UNLIKELY(not j.is_array()))
-    {
-        JSON_THROW(type_error::create(302, "type must be array, but is " + std::string(j.type_name())));
-    }
-
-    from_json_array_impl(j, arr, priority_tag<2> {});
-}
-
-template<typename BasicJsonType, typename CompatibleObjectType,
-         enable_if_t<is_compatible_object_type<BasicJsonType, CompatibleObjectType>::value, int> = 0>
-void from_json(const BasicJsonType& j, CompatibleObjectType& obj)
-{
-    if (JSON_UNLIKELY(not j.is_object()))
-    {
-        JSON_THROW(type_error::create(302, "type must be object, but is " + std::string(j.type_name())));
-    }
-
-    auto inner_object = j.template get_ptr<const typename BasicJsonType::object_t*>();
-    using value_type = typename CompatibleObjectType::value_type;
-    std::transform(
-        inner_object->begin(), inner_object->end(),
-        std::inserter(obj, obj.begin()),
-        [](typename BasicJsonType::object_t::value_type const & p)
-    {
-        return value_type(p.first, p.second.template get<typename CompatibleObjectType::mapped_type>());
-    });
-}
-
-// overload for arithmetic types, not chosen for basic_json template arguments
-// (BooleanType, etc..); note: Is it really necessary to provide explicit
-// overloads for boolean_t etc. in case of a custom BooleanType which is not
-// an arithmetic type?
-template<typename BasicJsonType, typename ArithmeticType,
-         enable_if_t <
-             std::is_arithmetic<ArithmeticType>::value and
-             not std::is_same<ArithmeticType, typename BasicJsonType::number_unsigned_t>::value and
-             not std::is_same<ArithmeticType, typename BasicJsonType::number_integer_t>::value and
-             not std::is_same<ArithmeticType, typename BasicJsonType::number_float_t>::value and
-             not std::is_same<ArithmeticType, typename BasicJsonType::boolean_t>::value,
-             int> = 0>
-void from_json(const BasicJsonType& j, ArithmeticType& val)
-{
-    switch (static_cast<value_t>(j))
-    {
-        case value_t::number_unsigned:
-        {
-            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_unsigned_t*>());
-            break;
-        }
-        case value_t::number_integer:
-        {
-            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_integer_t*>());
-            break;
-        }
-        case value_t::number_float:
-        {
-            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::number_float_t*>());
-            break;
-        }
-        case value_t::boolean:
-        {
-            val = static_cast<ArithmeticType>(*j.template get_ptr<const typename BasicJsonType::boolean_t*>());
-            break;
-        }
-
-        default:
-            JSON_THROW(type_error::create(302, "type must be number, but is " + std::string(j.type_name())));
-    }
-}
-
-template<typename BasicJsonType, typename A1, typename A2>
-void from_json(const BasicJsonType& j, std::pair<A1, A2>& p)
-{
-    p = {j.at(0).template get<A1>(), j.at(1).template get<A2>()};
-}
-
-template<typename BasicJsonType, typename Tuple, std::size_t... Idx>
-void from_json_tuple_impl(const BasicJsonType& j, Tuple& t, index_sequence<Idx...>)
-{
-    t = std::make_tuple(j.at(Idx).template get<typename std::tuple_element<Idx, Tuple>::type>()...);
-}
-
-template<typename BasicJsonType, typename... Args>
-void from_json(const BasicJsonType& j, std::tuple<Args...>& t)
-{
-    from_json_tuple_impl(j, t, index_sequence_for<Args...> {});
-}
-
 struct to_json_fn
 {
   private:
@@ -1342,50 +1824,39 @@ struct to_json_fn
         return call(j, std::forward<T>(val), priority_tag<1> {});
     }
 };
+}
 
-struct from_json_fn
+/// namespace to hold default `to_json` function
+namespace
 {
-  private:
-    template<typename BasicJsonType, typename T>
-    auto call(const BasicJsonType& j, T& val, priority_tag<1> /*unused*/) const
-    noexcept(noexcept(from_json(j, val)))
-    -> decltype(from_json(j, val), void())
-    {
-        return from_json(j, val);
-    }
+constexpr const auto& to_json = detail::static_const<detail::to_json_fn>::value;
+}
+}
 
-    template<typename BasicJsonType, typename T>
-    void call(const BasicJsonType& /*unused*/, T& /*unused*/, priority_tag<0> /*unused*/) const noexcept
-    {
-        static_assert(sizeof(BasicJsonType) == 0,
-                      "could not find from_json() method in T's namespace");
-#ifdef _MSC_VER
-        // MSVC does not show a stacktrace for the above assert
-        using decayed = uncvref_t<T>;
-        static_assert(sizeof(typename decayed::force_msvc_stacktrace) == 0,
-                      "forcing MSVC stacktrace to show which T we're talking about.");
-#endif
-    }
+// #include <nlohmann/detail/input/input_adapters.hpp>
 
-  public:
-    template<typename BasicJsonType, typename T>
-    void operator()(const BasicJsonType& j, T& val) const
-    noexcept(noexcept(std::declval<from_json_fn>().call(j, val, priority_tag<1> {})))
-    {
-        return call(j, val, priority_tag<1> {});
-    }
-};
 
-// taken from ranges-v3
-template<typename T>
-struct static_const
-{
-    static constexpr T value{};
-};
+#include <cassert> // assert
+#include <cstddef> // size_t
+#include <cstring> // strlen
+#include <istream> // istream
+#include <iterator> // begin, end, iterator_traits, random_access_iterator_tag, distance, next
+#include <memory> // shared_ptr, make_shared, addressof
+#include <numeric> // accumulate
+#include <string> // string, char_traits
+#include <type_traits> // enable_if, is_base_of, is_pointer, is_integral, remove_pointer
+#include <utility> // pair, declval
 
-template<typename T>
-constexpr T static_const<T>::value;
+// #include <nlohmann/detail/macro_scope.hpp>
 
+
+namespace nlohmann
+{
+namespace detail
+{
+/// the supported input formats
+enum class input_format_t { json, cbor, msgpack, ubjson };
+
 ////////////////////
 // input adapters //
 ////////////////////
@@ -1394,19 +1865,17 @@ constexpr T static_const<T>::value;
 @brief abstract input adapter interface
 
 Produces a stream of std::char_traits<char>::int_type characters from a
-std::istream, a buffer, or some other input type.  Accepts the return of exactly
-one non-EOF character for future input.  The int_type characters returned
-consist of all valid char values as positive values (typically unsigned char),
-plus an EOF value outside that range, specified by the value of the function
-std::char_traits<char>::eof().  This value is typically -1, but could be any
-arbitrary value which is not a valid char value.
+std::istream, a buffer, or some other input type. Accepts the return of
+exactly one non-EOF character for future input. The int_type characters
+returned consist of all valid char values as positive values (typically
+unsigned char), plus an EOF value outside that range, specified by the value
+of the function std::char_traits<char>::eof(). This value is typically -1, but
+could be any arbitrary value which is not a valid char value.
 */
 struct input_adapter_protocol
 {
     /// get a character [0,255] or std::char_traits<char>::eof().
     virtual std::char_traits<char>::int_type get_character() = 0;
-    /// restore the last non-eof() character to input
-    virtual void unget_character() = 0;
     virtual ~input_adapter_protocol() = default;
 };
 
@@ -1434,34 +1903,7 @@ class input_stream_adapter : public input_adapter_prot
 
     explicit input_stream_adapter(std::istream& i)
         : is(i), sb(*i.rdbuf())
-    {
-        // skip byte order mark
-        std::char_traits<char>::int_type c;
-        if ((c = get_character()) == 0xEF)
-        {
-            if ((c = get_character()) == 0xBB)
-            {
-                if ((c = get_character()) == 0xBF)
-                {
-                    return; // Ignore BOM
-                }
-                else if (c != std::char_traits<char>::eof())
-                {
-                    is.unget();
-                }
-                is.putback('\xBB');
-            }
-            else if (c != std::char_traits<char>::eof())
-            {
-                is.unget();
-            }
-            is.putback('\xEF');
-        }
-        else if (c != std::char_traits<char>::eof())
-        {
-            is.unget(); // no byte order mark; process as usual
-        }
-    }
+    {}
 
     // delete because of pointer members
     input_stream_adapter(const input_stream_adapter&) = delete;
@@ -1475,11 +1917,6 @@ class input_stream_adapter : public input_adapter_prot
         return sb.sbumpc();
     }
 
-    void unget_character() override
-    {
-        sb.sungetc();  // is.unget() avoided for performance
-    }
-
   private:
     /// the associated input stream
     std::istream& is;
@@ -1491,14 +1928,8 @@ class input_buffer_adapter : public input_adapter_prot
 {
   public:
     input_buffer_adapter(const char* b, const std::size_t l)
-        : cursor(b), limit(b + l), start(b)
-    {
-        // skip byte order mark
-        if (l >= 3 and b[0] == '\xEF' and b[1] == '\xBB' and b[2] == '\xBF')
-        {
-            cursor += 3;
-        }
-    }
+        : cursor(b), limit(b + l)
+    {}
 
     // delete because of pointer members
     input_buffer_adapter(const input_buffer_adapter&) = delete;
@@ -1514,21 +1945,164 @@ class input_buffer_adapter : public input_adapter_prot
         return std::char_traits<char>::eof();
     }
 
-    void unget_character() noexcept override
+  private:
+    /// pointer to the current character
+    const char* cursor;
+    /// pointer past the last character
+    const char* const limit;
+};
+
+template<typename WideStringType>
+class wide_string_input_adapter : public input_adapter_protocol
+{
+  public:
+    explicit wide_string_input_adapter(const WideStringType& w) : str(w) {}
+
+    std::char_traits<char>::int_type get_character() noexcept override
     {
-        if (JSON_LIKELY(cursor > start))
+        // check if buffer needs to be filled
+        if (utf8_bytes_index == utf8_bytes_filled)
         {
-            --cursor;
+            if (sizeof(typename WideStringType::value_type) == 2)
+            {
+                fill_buffer_utf16();
+            }
+            else
+            {
+                fill_buffer_utf32();
+            }
+
+            assert(utf8_bytes_filled > 0);
+            assert(utf8_bytes_index == 0);
         }
+
+        // use buffer
+        assert(utf8_bytes_filled > 0);
+        assert(utf8_bytes_index < utf8_bytes_filled);
+        return utf8_bytes[utf8_bytes_index++];
     }
 
   private:
-    /// pointer to the current character
-    const char* cursor;
-    /// pointer past the last character
-    const char* limit;
-    /// pointer to the first character
-    const char* start;
+    void fill_buffer_utf16()
+    {
+        utf8_bytes_index = 0;
+
+        if (current_wchar == str.size())
+        {
+            utf8_bytes[0] = std::char_traits<char>::eof();
+            utf8_bytes_filled = 1;
+        }
+        else
+        {
+            // get the current character
+            const int wc = static_cast<int>(str[current_wchar++]);
+
+            // UTF-16 to UTF-8 encoding
+            if (wc < 0x80)
+            {
+                utf8_bytes[0] = wc;
+                utf8_bytes_filled = 1;
+            }
+            else if (wc <= 0x7FF)
+            {
+                utf8_bytes[0] = 0xC0 | ((wc >> 6));
+                utf8_bytes[1] = 0x80 | (wc & 0x3F);
+                utf8_bytes_filled = 2;
+            }
+            else if (0xD800 > wc or wc >= 0xE000)
+            {
+                utf8_bytes[0] = 0xE0 | ((wc >> 12));
+                utf8_bytes[1] = 0x80 | ((wc >> 6) & 0x3F);
+                utf8_bytes[2] = 0x80 | (wc & 0x3F);
+                utf8_bytes_filled = 3;
+            }
+            else
+            {
+                if (current_wchar < str.size())
+                {
+                    const int wc2 = static_cast<int>(str[current_wchar++]);
+                    const int charcode = 0x10000 + (((wc & 0x3FF) << 10) | (wc2 & 0x3FF));
+                    utf8_bytes[0] = 0xf0 | (charcode >> 18);
+                    utf8_bytes[1] = 0x80 | ((charcode >> 12) & 0x3F);
+                    utf8_bytes[2] = 0x80 | ((charcode >> 6) & 0x3F);
+                    utf8_bytes[3] = 0x80 | (charcode & 0x3F);
+                    utf8_bytes_filled = 4;
+                }
+                else
+                {
+                    // unknown character
+                    ++current_wchar;
+                    utf8_bytes[0] = wc;
+                    utf8_bytes_filled = 1;
+                }
+            }
+        }
+    }
+
+    void fill_buffer_utf32()
+    {
+        utf8_bytes_index = 0;
+
+        if (current_wchar == str.size())
+        {
+            utf8_bytes[0] = std::char_traits<char>::eof();
+            utf8_bytes_filled = 1;
+        }
+        else
+        {
+            // get the current character
+            const int wc = static_cast<int>(str[current_wchar++]);
+
+            // UTF-32 to UTF-8 encoding
+            if (wc < 0x80)
+            {
+                utf8_bytes[0] = wc;
+                utf8_bytes_filled = 1;
+            }
+            else if (wc <= 0x7FF)
+            {
+                utf8_bytes[0] = 0xC0 | ((wc >> 6) & 0x1F);
+                utf8_bytes[1] = 0x80 | (wc & 0x3F);
+                utf8_bytes_filled = 2;
+            }
+            else if (wc <= 0xFFFF)
+            {
+                utf8_bytes[0] = 0xE0 | ((wc >> 12) & 0x0F);
+                utf8_bytes[1] = 0x80 | ((wc >> 6) & 0x3F);
+                utf8_bytes[2] = 0x80 | (wc & 0x3F);
+                utf8_bytes_filled = 3;
+            }
+            else if (wc <= 0x10FFFF)
+            {
+                utf8_bytes[0] = 0xF0 | ((wc >> 18 ) & 0x07);
+                utf8_bytes[1] = 0x80 | ((wc >> 12) & 0x3F);
+                utf8_bytes[2] = 0x80 | ((wc >> 6) & 0x3F);
+                utf8_bytes[3] = 0x80 | (wc & 0x3F);
+                utf8_bytes_filled = 4;
+            }
+            else
+            {
+                // unknown character
+                utf8_bytes[0] = wc;
+                utf8_bytes_filled = 1;
+            }
+        }
+    }
+
+  private:
+    /// the wstring to process
+    const WideStringType& str;
+
+    /// index of the current wchar in str
+    std::size_t current_wchar = 0;
+
+    /// a buffer for UTF-8 bytes
+    std::array<std::char_traits<char>::int_type, 4> utf8_bytes = {{0, 0, 0, 0}};
+
+    /// index to the utf8_codes array for the next valid byte
+    std::size_t utf8_bytes_index = 0;
+    /// number of valid bytes in the utf8_codes array
+    std::size_t utf8_bytes_filled = 0;
 };
 
 class input_adapter
@@ -1544,6 +2118,15 @@ class input_adapter
     input_adapter(std::istream&& i)
         : ia(std::make_shared<input_stream_adapter>(i)) {}
 
+    input_adapter(const std::wstring& ws)
+        : ia(std::make_shared<wide_string_input_adapter<std::wstring>>(ws)) {}
+
+    input_adapter(const std::u16string& ws)
+        : ia(std::make_shared<wide_string_input_adapter<std::u16string>>(ws)) {}
+
+    input_adapter(const std::u32string& ws)
+        : ia(std::make_shared<wide_string_input_adapter<std::u32string>>(ws)) {}
+
     /// input adapter for buffer
     template<typename CharT,
              typename std::enable_if<
@@ -1624,11 +2207,33 @@ class input_adapter
     /// the actual adapter
     input_adapter_t ia = nullptr;
 };
+}
+}
 
-//////////////////////
-// lexer and parser //
-//////////////////////
+// #include <nlohmann/detail/input/lexer.hpp>
 
+
+#include <clocale> // localeconv
+#include <cstddef> // size_t
+#include <cstdlib> // strtof, strtod, strtold, strtoll, strtoull
+#include <cstdio> // snprintf
+#include <initializer_list> // initializer_list
+#include <string> // char_traits, string
+#include <vector> // vector
+
+// #include <nlohmann/detail/macro_scope.hpp>
+
+// #include <nlohmann/detail/input/input_adapters.hpp>
+
+
+namespace nlohmann
+{
+namespace detail
+{
+///////////
+// lexer //
+///////////
+
 /*!
 @brief lexical analysis
 
@@ -1640,6 +2245,7 @@ class lexer
     using number_integer_t = typename BasicJsonType::number_integer_t;
     using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
     using number_float_t = typename BasicJsonType::number_float_t;
+    using string_t = typename BasicJsonType::string_t;
 
   public:
     /// token types for the parser
@@ -1701,12 +2307,14 @@ class lexer
                 return "end of input";
             case token_type::literal_or_value:
                 return "'[', '{', or a literal";
+            // LCOV_EXCL_START
             default: // catch non-enum values
-                return "unknown token"; // LCOV_EXCL_LINE
+                return "unknown token";
+                // LCOV_EXCL_STOP
         }
     }
 
-    explicit lexer(detail::input_adapter_t adapter)
+    explicit lexer(detail::input_adapter_t&& adapter)
         : ia(std::move(adapter)), decimal_point_char(get_decimal_point()) {}
 
     // delete because of pointer members
@@ -1819,9 +2427,10 @@ class lexer
     @brief scan a string literal
 
     This function scans a string according to Sect. 7 of RFC 7159. While
-    scanning, bytes are escaped and copied into buffer yytext. Then the function
-    returns successfully, yytext is *not* null-terminated (as it may contain \0
-    bytes), and yytext.size() is the number of bytes in the string.
+    scanning, bytes are escaped and copied into buffer token_buffer. Then the
+    function returns successfully, token_buffer is *not* null-terminated (as it
+    may contain \0 bytes), and token_buffer.size() is the number of bytes in the
+    string.
 
     @return token_type::value_string if string could be successfully scanned,
             token_type::parse_error otherwise
@@ -1831,7 +2440,7 @@ class lexer
     */
     token_type scan_string()
     {
-        // reset yytext (ignore opening quote)
+        // reset token_buffer (ignore opening quote)
         reset();
 
         // we entered the function by reading an open quote
@@ -2303,7 +2912,7 @@ class lexer
     contains cycles, but any cycle can be left when EOF is read. Therefore,
     the function is guaranteed to terminate.
 
-    During scanning, the read bytes are stored in yytext. This string is
+    During scanning, the read bytes are stored in token_buffer. This string is
     then converted to a signed integer, an unsigned integer, or a
     floating-point number.
 
@@ -2317,7 +2926,7 @@ class lexer
     */
     token_type scan_number()
     {
-        // reset yytext to store the number's bytes
+        // reset token_buffer to store the number's bytes
         reset();
 
         // the type of the parsed number; initially set to unsigned; will be
@@ -2353,11 +2962,13 @@ class lexer
                 goto scan_number_any1;
             }
 
+            // LCOV_EXCL_START
             default:
             {
                 // all other characters are rejected outside scan_number()
-                assert(false); // LCOV_EXCL_LINE
+                assert(false);
             }
+                // LCOV_EXCL_STOP
         }
 
 scan_number_minus:
@@ -2601,10 +3212,10 @@ scan_number_done:
         // try to parse integers first and fall back to floats
         if (number_type == token_type::value_unsigned)
         {
-            const auto x = std::strtoull(yytext.data(), &endptr, 10);
+            const auto x = std::strtoull(token_buffer.data(), &endptr, 10);
 
             // we checked the number format before
-            assert(endptr == yytext.data() + yytext.size());
+            assert(endptr == token_buffer.data() + token_buffer.size());
 
             if (errno == 0)
             {
@@ -2617,10 +3228,10 @@ scan_number_done:
         }
         else if (number_type == token_type::value_integer)
         {
-            const auto x = std::strtoll(yytext.data(), &endptr, 10);
+            const auto x = std::strtoll(token_buffer.data(), &endptr, 10);
 
             // we checked the number format before
-            assert(endptr == yytext.data() + yytext.size());
+            assert(endptr == token_buffer.data() + token_buffer.size());
 
             if (errno == 0)
             {
@@ -2634,10 +3245,10 @@ scan_number_done:
 
         // this code is reached if we parse a floating-point number or if an
         // integer conversion above failed
-        strtof(value_float, yytext.data(), &endptr);
+        strtof(value_float, token_buffer.data(), &endptr);
 
         // we checked the number format before
-        assert(endptr == yytext.data() + yytext.size());
+        assert(endptr == token_buffer.data() + token_buffer.size());
 
         return token_type::value_float;
     }
@@ -2666,10 +3277,10 @@ scan_number_done:
     // input management
     /////////////////////
 
-    /// reset yytext; current character is beginning of token
+    /// reset token_buffer; current character is beginning of token
     void reset() noexcept
     {
-        yytext.clear();
+        token_buffer.clear();
         token_string.clear();
         token_string.push_back(std::char_traits<char>::to_char_type(current));
     }
@@ -2687,7 +3298,16 @@ scan_number_done:
     std::char_traits<char>::int_type get()
     {
         ++chars_read;
-        current = ia->get_character();
+        if (next_unget)
+        {
+            // just reset the next_unget variable and work with current
+            next_unget = false;
+        }
+        else
+        {
+            current = ia->get_character();
+        }
+
         if (JSON_LIKELY(current != std::char_traits<char>::eof()))
         {
             token_string.push_back(std::char_traits<char>::to_char_type(current));
@@ -2695,22 +3315,29 @@ scan_number_done:
         return current;
     }
 
-    /// unget current character (return it again on next get)
+    /*!
+    @brief unget current character (read it again on next get)
+
+    We implement unget by setting variable next_unget to true. The input is not
+    changed - we just simulate ungetting by modifying chars_read and
+    token_string. The next call to get() will behave as if the unget character
+    is read again.
+    */
     void unget()
     {
+        next_unget = true;
         --chars_read;
         if (JSON_LIKELY(current != std::char_traits<char>::eof()))
         {
-            ia->unget_character();
             assert(token_string.size() != 0);
             token_string.pop_back();
         }
     }
 
-    /// add a character to yytext
+    /// add a character to token_buffer
     void add(int c)
     {
-        yytext.push_back(std::char_traits<char>::to_char_type(c));
+        token_buffer.push_back(std::char_traits<char>::to_char_type(c));
     }
 
   public:
@@ -2737,9 +3364,9 @@ scan_number_done:
     }
 
     /// return current string value (implicitly resets the token; useful only once)
-    std::string move_string()
+    string_t& get_string()
     {
-        return std::move(yytext);
+        return token_buffer;
     }
 
     /////////////////////
@@ -2764,10 +3391,9 @@ scan_number_done:
             if ('\x00' <= c and c <= '\x1F')
             {
                 // escape control characters
-                std::stringstream ss;
-                ss << "<U+" << std::setw(4) << std::uppercase << std::setfill('0')
-                   << std::hex << static_cast<int>(c) << ">";
-                result += ss.str();
+                char cs[9];
+                snprintf(cs, 9, "<U+%.4X>", static_cast<unsigned char>(c));
+                result += cs;
             }
             else
             {
@@ -2789,8 +3415,43 @@ scan_number_done:
     // actual scanner
     /////////////////////
 
+    /*!
+    @brief skip the UTF-8 byte order mark
+    @return true iff there is no BOM or the correct BOM has been skipped
+    */
+    bool skip_bom()
+    {
+        if (get() == 0xEF)
+        {
+            if (get() == 0xBB and get() == 0xBF)
+            {
+                // we completely parsed the BOM
+                return true;
+            }
+            else
+            {
+                // after reading 0xEF, an unexpected character followed
+                return false;
+            }
+        }
+        else
+        {
+            // the first character is not the beginning of the BOM; unget it to
+            // process is later
+            unget();
+            return true;
+        }
+    }
+
     token_type scan()
     {
+        // initially, skip the BOM
+        if (chars_read == 0 and not skip_bom())
+        {
+            error_message = "invalid BOM; must be 0xEF 0xBB 0xBF if given";
+            return token_type::parse_error;
+        }
+
         // read next character and ignore whitespace
         do
         {
@@ -2860,6 +3521,9 @@ scan_number_done:
     /// the current character
     std::char_traits<char>::int_type current = std::char_traits<char>::eof();
 
+    /// whether the next get() call should just return current
+    bool next_unget = false;
+
     /// the number of characters read
     std::size_t chars_read = 0;
 
@@ -2867,7 +3531,7 @@ scan_number_done:
     std::vector<char> token_string {};
 
     /// buffer for variable-length tokens (numbers, strings)
-    std::string yytext {};
+    string_t token_buffer {};
 
     /// a description of occurred lexer errors
     const char* error_message = "";
@@ -2880,8 +3544,957 @@ scan_number_done:
     /// the decimal point
     const char decimal_point_char = '.';
 };
+}
+}
 
+// #include <nlohmann/detail/input/parser.hpp>
+
+
+#include <cassert> // assert
+#include <cmath> // isfinite
+#include <cstdint> // uint8_t
+#include <functional> // function
+#include <string> // string
+#include <utility> // move
+
+// #include <nlohmann/detail/exceptions.hpp>
+
+// #include <nlohmann/detail/macro_scope.hpp>
+
+// #include <nlohmann/detail/meta/is_sax.hpp>
+
+
+#include <cstdint> // size_t
+#include <utility> // declval
+
+// #include <nlohmann/detail/meta/detected.hpp>
+
+
+#include <type_traits>
+
+// #include <nlohmann/detail/meta/void_t.hpp>
+
+
+namespace nlohmann
+{
+namespace detail
+{
+template <typename...>
+using void_t = void;
+}
+}
+
+
+// http://en.cppreference.com/w/cpp/experimental/is_detected
+namespace nlohmann
+{
+namespace detail
+{
+struct nonesuch
+{
+    nonesuch() = delete;
+    ~nonesuch() = delete;
+    nonesuch(nonesuch const&) = delete;
+    void operator=(nonesuch const&) = delete;
+};
+
+template <class Default,
+          class AlwaysVoid,
+          template <class...> class Op,
+          class... Args>
+struct detector
+{
+    using value_t = std::false_type;
+    using type = Default;
+};
+
+template <class Default, template <class...> class Op, class... Args>
+struct detector<Default, void_t<Op<Args...>>, Op, Args...>
+{
+    using value_t = std::true_type;
+    using type = Op<Args...>;
+};
+
+template <template <class...> class Op, class... Args>
+using is_detected = typename detector<nonesuch, void, Op, Args...>::value_t;
+
+template <template <class...> class Op, class... Args>
+using detected_t = typename detector<nonesuch, void, Op, Args...>::type;
+
+template <class Default, template <class...> class Op, class... Args>
+using detected_or = detector<Default, void, Op, Args...>;
+
+template <class Default, template <class...> class Op, class... Args>
+using detected_or_t = typename detected_or<Default, Op, Args...>::type;
+
+template <class Expected, template <class...> class Op, class... Args>
+using is_detected_exact = std::is_same<Expected, detected_t<Op, Args...>>;
+
+template <class To, template <class...> class Op, class... Args>
+using is_detected_convertible =
+    std::is_convertible<detected_t<Op, Args...>, To>;
+}
+}
+
+// #include <nlohmann/detail/meta/type_traits.hpp>
+
+
+namespace nlohmann
+{
+namespace detail
+{
+template <typename T>
+using null_function_t = decltype(std::declval<T&>().null());
+
+template <typename T>
+using boolean_function_t =
+    decltype(std::declval<T&>().boolean(std::declval<bool>()));
+
+template <typename T, typename Integer>
+using number_integer_function_t =
+    decltype(std::declval<T&>().number_integer(std::declval<Integer>()));
+
+template <typename T, typename Unsigned>
+using number_unsigned_function_t =
+    decltype(std::declval<T&>().number_unsigned(std::declval<Unsigned>()));
+
+template <typename T, typename Float, typename String>
+using number_float_function_t = decltype(std::declval<T&>().number_float(
+                                    std::declval<Float>(), std::declval<const String&>()));
+
+template <typename T, typename String>
+using string_function_t =
+    decltype(std::declval<T&>().string(std::declval<String&>()));
+
+template <typename T>
+using start_object_function_t =
+    decltype(std::declval<T&>().start_object(std::declval<std::size_t>()));
+
+template <typename T, typename String>
+using key_function_t =
+    decltype(std::declval<T&>().key(std::declval<String&>()));
+
+template <typename T>
+using end_object_function_t = decltype(std::declval<T&>().end_object());
+
+template <typename T>
+using start_array_function_t =
+    decltype(std::declval<T&>().start_array(std::declval<std::size_t>()));
+
+template <typename T>
+using end_array_function_t = decltype(std::declval<T&>().end_array());
+
+template <typename T, typename Exception>
+using parse_error_function_t = decltype(std::declval<T&>().parse_error(
+        std::declval<std::size_t>(), std::declval<const std::string&>(),
+        std::declval<const Exception&>()));
+
+template <typename SAX, typename BasicJsonType>
+struct is_sax
+{
+  private:
+    static_assert(is_basic_json<BasicJsonType>::value,
+                  "BasicJsonType must be of type basic_json<...>");
+
+    using number_integer_t = typename BasicJsonType::number_integer_t;
+    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
+    using number_float_t = typename BasicJsonType::number_float_t;
+    using string_t = typename BasicJsonType::string_t;
+    using exception_t = typename BasicJsonType::exception;
+
+  public:
+    static constexpr bool value =
+        is_detected_exact<bool, null_function_t, SAX>::value &&
+        is_detected_exact<bool, boolean_function_t, SAX>::value &&
+        is_detected_exact<bool, number_integer_function_t, SAX,
+        number_integer_t>::value &&
+        is_detected_exact<bool, number_unsigned_function_t, SAX,
+        number_unsigned_t>::value &&
+        is_detected_exact<bool, number_float_function_t, SAX, number_float_t,
+        string_t>::value &&
+        is_detected_exact<bool, string_function_t, SAX, string_t>::value &&
+        is_detected_exact<bool, start_object_function_t, SAX>::value &&
+        is_detected_exact<bool, key_function_t, SAX, string_t>::value &&
+        is_detected_exact<bool, end_object_function_t, SAX>::value &&
+        is_detected_exact<bool, start_array_function_t, SAX>::value &&
+        is_detected_exact<bool, end_array_function_t, SAX>::value &&
+        is_detected_exact<bool, parse_error_function_t, SAX, exception_t>::value;
+};
+
+template <typename SAX, typename BasicJsonType>
+struct is_sax_static_asserts
+{
+  private:
+    static_assert(is_basic_json<BasicJsonType>::value,
+                  "BasicJsonType must be of type basic_json<...>");
+
+    using number_integer_t = typename BasicJsonType::number_integer_t;
+    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
+    using number_float_t = typename BasicJsonType::number_float_t;
+    using string_t = typename BasicJsonType::string_t;
+    using exception_t = typename BasicJsonType::exception;
+
+  public:
+    static_assert(is_detected_exact<bool, null_function_t, SAX>::value,
+                  "Missing/invalid function: bool null()");
+    static_assert(is_detected_exact<bool, boolean_function_t, SAX>::value,
+                  "Missing/invalid function: bool boolean(bool)");
+    static_assert(is_detected_exact<bool, boolean_function_t, SAX>::value,
+                  "Missing/invalid function: bool boolean(bool)");
+    static_assert(
+        is_detected_exact<bool, number_integer_function_t, SAX,
+        number_integer_t>::value,
+        "Missing/invalid function: bool number_integer(number_integer_t)");
+    static_assert(
+        is_detected_exact<bool, number_unsigned_function_t, SAX,
+        number_unsigned_t>::value,
+        "Missing/invalid function: bool number_unsigned(number_unsigned_t)");
+    static_assert(is_detected_exact<bool, number_float_function_t, SAX,
+                  number_float_t, string_t>::value,
+                  "Missing/invalid function: bool number_float(number_float_t, const string_t&)");
+    static_assert(
+        is_detected_exact<bool, string_function_t, SAX, string_t>::value,
+        "Missing/invalid function: bool string(string_t&)");
+    static_assert(is_detected_exact<bool, start_object_function_t, SAX>::value,
+                  "Missing/invalid function: bool start_object(std::size_t)");
+    static_assert(is_detected_exact<bool, key_function_t, SAX, string_t>::value,
+                  "Missing/invalid function: bool key(string_t&)");
+    static_assert(is_detected_exact<bool, end_object_function_t, SAX>::value,
+                  "Missing/invalid function: bool end_object()");
+    static_assert(is_detected_exact<bool, start_array_function_t, SAX>::value,
+                  "Missing/invalid function: bool start_array(std::size_t)");
+    static_assert(is_detected_exact<bool, end_array_function_t, SAX>::value,
+                  "Missing/invalid function: bool end_array()");
+    static_assert(
+        is_detected_exact<bool, parse_error_function_t, SAX, exception_t>::value,
+        "Missing/invalid function: bool parse_error(std::size_t, const "
+        "std::string&, const exception&)");
+};
+}
+}
+
+// #include <nlohmann/detail/input/input_adapters.hpp>
+
+// #include <nlohmann/detail/input/json_sax.hpp>
+
+
+#include <cstddef>
+#include <string>
+#include <vector>
+
+// #include <nlohmann/detail/input/parser.hpp>
+
+// #include <nlohmann/detail/exceptions.hpp>
+
+
+namespace nlohmann
+{
+
 /*!
+@brief SAX interface
+
+This class describes the SAX interface used by @ref nlohmann::json::sax_parse.
+Each function is called in different situations while the input is parsed. The
+boolean return value informs the parser whether to continue processing the
+input.
+*/
+template<typename BasicJsonType>
+struct json_sax
+{
+    /// type for (signed) integers
+    using number_integer_t = typename BasicJsonType::number_integer_t;
+    /// type for unsigned integers
+    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
+    /// type for floating-point numbers
+    using number_float_t = typename BasicJsonType::number_float_t;
+    /// type for strings
+    using string_t = typename BasicJsonType::string_t;
+
+    /*!
+    @brief a null value was read
+    @return whether parsing should proceed
+    */
+    virtual bool null() = 0;
+
+    /*!
+    @brief a boolean value was read
+    @param[in] val  boolean value
+    @return whether parsing should proceed
+    */
+    virtual bool boolean(bool val) = 0;
+
+    /*!
+    @brief an integer number was read
+    @param[in] val  integer value
+    @return whether parsing should proceed
+    */
+    virtual bool number_integer(number_integer_t val) = 0;
+
+    /*!
+    @brief an unsigned integer number was read
+    @param[in] val  unsigned integer value
+    @return whether parsing should proceed
+    */
+    virtual bool number_unsigned(number_unsigned_t val) = 0;
+
+    /*!
+    @brief an floating-point number was read
+    @param[in] val  floating-point value
+    @param[in] s    raw token value
+    @return whether parsing should proceed
+    */
+    virtual bool number_float(number_float_t val, const string_t& s) = 0;
+
+    /*!
+    @brief a string was read
+    @param[in] val  string value
+    @return whether parsing should proceed
+    @note It is safe to move the passed string.
+    */
+    virtual bool string(string_t& val) = 0;
+
+    /*!
+    @brief the beginning of an object was read
+    @param[in] elements  number of object elements or -1 if unknown
+    @return whether parsing should proceed
+    @note binary formats may report the number of elements
+    */
+    virtual bool start_object(std::size_t elements) = 0;
+
+    /*!
+    @brief an object key was read
+    @param[in] val  object key
+    @return whether parsing should proceed
+    @note It is safe to move the passed string.
+    */
+    virtual bool key(string_t& val) = 0;
+
+    /*!
+    @brief the end of an object was read
+    @return whether parsing should proceed
+    */
+    virtual bool end_object() = 0;
+
+    /*!
+    @brief the beginning of an array was read
+    @param[in] elements  number of array elements or -1 if unknown
+    @return whether parsing should proceed
+    @note binary formats may report the number of elements
+    */
+    virtual bool start_array(std::size_t elements) = 0;
+
+    /*!
+    @brief the end of an array was read
+    @return whether parsing should proceed
+    */
+    virtual bool end_array() = 0;
+
+    /*!
+    @brief a parse error occurred
+    @param[in] position    the position in the input where the error occurs
+    @param[in] last_token  the last read token
+    @param[in] error_msg   a detailed error message
+    @return whether parsing should proceed (must return false)
+    */
+    virtual bool parse_error(std::size_t position,
+                             const std::string& last_token,
+                             const detail::exception& ex) = 0;
+
+    virtual ~json_sax() = default;
+};
+
+
+namespace detail
+{
+/*!
+@brief SAX implementation to create a JSON value from SAX events
+
+This class implements the @ref json_sax interface and processes the SAX events
+to create a JSON value which makes it basically a DOM parser. The structure or
+hierarchy of the JSON value is managed by the stack `ref_stack` which contains
+a pointer to the respective array or object for each recursion depth.
+
+After successful parsing, the value that is passed by reference to the
+constructor contains the parsed value.
+
+@tparam BasicJsonType  the JSON type
+*/
+template<typename BasicJsonType>
+class json_sax_dom_parser
+{
+  public:
+    using number_integer_t = typename BasicJsonType::number_integer_t;
+    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
+    using number_float_t = typename BasicJsonType::number_float_t;
+    using string_t = typename BasicJsonType::string_t;
+
+    /*!
+    @param[in, out] r  reference to a JSON value that is manipulated while
+                       parsing
+    @param[in] allow_exceptions_  whether parse errors yield exceptions
+    */
+    explicit json_sax_dom_parser(BasicJsonType& r, const bool allow_exceptions_ = true)
+        : root(r), allow_exceptions(allow_exceptions_)
+    {}
+
+    bool null()
+    {
+        handle_value(nullptr);
+        return true;
+    }
+
+    bool boolean(bool val)
+    {
+        handle_value(val);
+        return true;
+    }
+
+    bool number_integer(number_integer_t val)
+    {
+        handle_value(val);
+        return true;
+    }
+
+    bool number_unsigned(number_unsigned_t val)
+    {
+        handle_value(val);
+        return true;
+    }
+
+    bool number_float(number_float_t val, const string_t&)
+    {
+        handle_value(val);
+        return true;
+    }
+
+    bool string(string_t& val)
+    {
+        handle_value(val);
+        return true;
+    }
+
+    bool start_object(std::size_t len)
+    {
+        ref_stack.push_back(handle_value(BasicJsonType::value_t::object));
+
+        if (JSON_UNLIKELY(len != std::size_t(-1) and len > ref_stack.back()->max_size()))
+        {
+            JSON_THROW(out_of_range::create(408,
+                                            "excessive object size: " + std::to_string(len)));
+        }
+
+        return true;
+    }
+
+    bool key(string_t& val)
+    {
+        // add null at given key and store the reference for later
+        object_element = &(ref_stack.back()->m_value.object->operator[](val));
+        return true;
+    }
+
+    bool end_object()
+    {
+        ref_stack.pop_back();
+        return true;
+    }
+
+    bool start_array(std::size_t len)
+    {
+        ref_stack.push_back(handle_value(BasicJsonType::value_t::array));
+
+        if (JSON_UNLIKELY(len != std::size_t(-1) and len > ref_stack.back()->max_size()))
+        {
+            JSON_THROW(out_of_range::create(408,
+                                            "excessive array size: " + std::to_string(len)));
+        }
+
+        return true;
+    }
+
+    bool end_array()
+    {
+        ref_stack.pop_back();
+        return true;
+    }
+
+    bool parse_error(std::size_t, const std::string&,
+                     const detail::exception& ex)
+    {
+        errored = true;
+        if (allow_exceptions)
+        {
+            // determine the proper exception type from the id
+            switch ((ex.id / 100) % 100)
+            {
+                case 1:
+                    JSON_THROW(*reinterpret_cast<const detail::parse_error*>(&ex));
+                case 4:
+                    JSON_THROW(*reinterpret_cast<const detail::out_of_range*>(&ex));
+                // LCOV_EXCL_START
+                case 2:
+                    JSON_THROW(*reinterpret_cast<const detail::invalid_iterator*>(&ex));
+                case 3:
+                    JSON_THROW(*reinterpret_cast<const detail::type_error*>(&ex));
+                case 5:
+                    JSON_THROW(*reinterpret_cast<const detail::other_error*>(&ex));
+                default:
+                    assert(false);
+                    // LCOV_EXCL_STOP
+            }
+        }
+        return false;
+    }
+
+    constexpr bool is_errored() const
+    {
+        return errored;
+    }
+
+  private:
+    /*!
+    @invariant If the ref stack is empty, then the passed value will be the new
+               root.
+    @invariant If the ref stack contains a value, then it is an array or an
+               object to which we can add elements
+    */
+    template<typename Value>
+    BasicJsonType* handle_value(Value&& v)
+    {
+        if (ref_stack.empty())
+        {
+            root = BasicJsonType(std::forward<Value>(v));
+            return &root;
+        }
+        else
+        {
+            assert(ref_stack.back()->is_array() or ref_stack.back()->is_object());
+            if (ref_stack.back()->is_array())
+            {
+                ref_stack.back()->m_value.array->emplace_back(std::forward<Value>(v));
+                return &(ref_stack.back()->m_value.array->back());
+            }
+            else
+            {
+                assert(object_element);
+                *object_element = BasicJsonType(std::forward<Value>(v));
+                return object_element;
+            }
+        }
+    }
+
+    /// the parsed JSON value
+    BasicJsonType& root;
+    /// stack to model hierarchy of values
+    std::vector<BasicJsonType*> ref_stack;
+    /// helper to hold the reference for the next object element
+    BasicJsonType* object_element = nullptr;
+    /// whether a syntax error occurred
+    bool errored = false;
+    /// whether to throw exceptions in case of errors
+    const bool allow_exceptions = true;
+};
+
+template<typename BasicJsonType>
+class json_sax_dom_callback_parser
+{
+  public:
+    using number_integer_t = typename BasicJsonType::number_integer_t;
+    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
+    using number_float_t = typename BasicJsonType::number_float_t;
+    using string_t = typename BasicJsonType::string_t;
+    using parser_callback_t = typename BasicJsonType::parser_callback_t;
+    using parse_event_t = typename BasicJsonType::parse_event_t;
+
+    json_sax_dom_callback_parser(BasicJsonType& r,
+                                 const parser_callback_t cb,
+                                 const bool allow_exceptions_ = true)
+        : root(r), callback(cb), allow_exceptions(allow_exceptions_)
+    {
+        keep_stack.push_back(true);
+    }
+
+    bool null()
+    {
+        handle_value(nullptr);
+        return true;
+    }
+
+    bool boolean(bool val)
+    {
+        handle_value(val);
+        return true;
+    }
+
+    bool number_integer(number_integer_t val)
+    {
+        handle_value(val);
+        return true;
+    }
+
+    bool number_unsigned(number_unsigned_t val)
+    {
+        handle_value(val);
+        return true;
+    }
+
+    bool number_float(number_float_t val, const string_t&)
+    {
+        handle_value(val);
+        return true;
+    }
+
+    bool string(string_t& val)
+    {
+        handle_value(val);
+        return true;
+    }
+
+    bool start_object(std::size_t len)
+    {
+        // check callback for object start
+        const bool keep = callback(static_cast<int>(ref_stack.size()), parse_event_t::object_start, discarded);
+        keep_stack.push_back(keep);
+
+        auto val = handle_value(BasicJsonType::value_t::object, true);
+        ref_stack.push_back(val.second);
+
+        // check object limit
+        if (ref_stack.back())
+        {
+            if (JSON_UNLIKELY(len != std::size_t(-1) and len > ref_stack.back()->max_size()))
+            {
+                JSON_THROW(out_of_range::create(408,
+                                                "excessive object size: " + std::to_string(len)));
+            }
+        }
+
+        return true;
+    }
+
+    bool key(string_t& val)
+    {
+        BasicJsonType k = BasicJsonType(val);
+
+        // check callback for key
+        const bool keep = callback(static_cast<int>(ref_stack.size()), parse_event_t::key, k);
+        key_keep_stack.push_back(keep);
+
+        // add discarded value at given key and store the reference for later
+        if (keep and ref_stack.back())
+        {
+            object_element = &(ref_stack.back()->m_value.object->operator[](val) = discarded);
+        }
+
+        return true;
+    }
+
+    bool end_object()
+    {
+        if (ref_stack.back())
+        {
+            if (not callback(static_cast<int>(ref_stack.size()) - 1, parse_event_t::object_end, *ref_stack.back()))
+            {
+                // discard object
+                *ref_stack.back() = discarded;
+            }
+        }
+
+        assert(not ref_stack.empty());
+        assert(not keep_stack.empty());
+        ref_stack.pop_back();
+        keep_stack.pop_back();
+
+        if (not ref_stack.empty() and ref_stack.back())
+        {
+            // remove discarded value
+            if (ref_stack.back()->is_object())
+            {
+                for (auto it = ref_stack.back()->begin(); it != ref_stack.back()->end(); ++it)
+                {
+                    if (it->is_discarded())
+                    {
+                        ref_stack.back()->erase(it);
+                        break;
+                    }
+                }
+            }
+        }
+
+        return true;
+    }
+
+    bool start_array(std::size_t len)
+    {
+        const bool keep = callback(static_cast<int>(ref_stack.size()), parse_event_t::array_start, discarded);
+        keep_stack.push_back(keep);
+
+        auto val = handle_value(BasicJsonType::value_t::array, true);
+        ref_stack.push_back(val.second);
+
+        // check array limit
+        if (ref_stack.back())
+        {
+            if (JSON_UNLIKELY(len != std::size_t(-1) and len > ref_stack.back()->max_size()))
+            {
+                JSON_THROW(out_of_range::create(408,
+                                                "excessive array size: " + std::to_string(len)));
+            }
+        }
+
+        return true;
+    }
+
+    bool end_array()
+    {
+        bool keep = true;
+
+        if (ref_stack.back())
+        {
+            keep = callback(static_cast<int>(ref_stack.size()) - 1, parse_event_t::array_end, *ref_stack.back());
+            if (not keep)
+            {
+                // discard array
+                *ref_stack.back() = discarded;
+            }
+        }
+
+        assert(not ref_stack.empty());
+        assert(not keep_stack.empty());
+        ref_stack.pop_back();
+        keep_stack.pop_back();
+
+        // remove discarded value
+        if (not keep and not ref_stack.empty())
+        {
+            if (ref_stack.back()->is_array())
+            {
+                ref_stack.back()->m_value.array->pop_back();
+            }
+        }
+
+        return true;
+    }
+
+    bool parse_error(std::size_t, const std::string&,
+                     const detail::exception& ex)
+    {
+        errored = true;
+        if (allow_exceptions)
+        {
+            // determine the proper exception type from the id
+            switch ((ex.id / 100) % 100)
+            {
+                case 1:
+                    JSON_THROW(*reinterpret_cast<const detail::parse_error*>(&ex));
+                case 4:
+                    JSON_THROW(*reinterpret_cast<const detail::out_of_range*>(&ex));
+                // LCOV_EXCL_START
+                case 2:
+                    JSON_THROW(*reinterpret_cast<const detail::invalid_iterator*>(&ex));
+                case 3:
+                    JSON_THROW(*reinterpret_cast<const detail::type_error*>(&ex));
+                case 5:
+                    JSON_THROW(*reinterpret_cast<const detail::other_error*>(&ex));
+                default:
+                    assert(false);
+                    // LCOV_EXCL_STOP
+            }
+        }
+        return false;
+    }
+
+    constexpr bool is_errored() const
+    {
+        return errored;
+    }
+
+  private:
+    /*!
+    @param[in] v  value to add to the JSON value we build during parsing
+    @param[in] skip_callback  whether we should skip calling the callback
+               function; this is required after start_array() and
+               start_object() SAX events, because otherwise we would call the
+               callback function with an empty array or object, respectively.
+
+    @invariant If the ref stack is empty, then the passed value will be the new
+               root.
+    @invariant If the ref stack contains a value, then it is an array or an
+               object to which we can add elements
+
+    @return pair of boolean (whether value should be kept) and pointer (to the
+            passed value in the ref_stack hierarchy; nullptr if not kept)
+    */
+    template<typename Value>
+    std::pair<bool, BasicJsonType*> handle_value(Value&& v, const bool skip_callback = false)
+    {
+        assert(not keep_stack.empty());
+
+        // do not handle this value if we know it would be added to a discarded
+        // container
+        if (not keep_stack.back())
+        {
+            return {false, nullptr};
+        }
+
+        // create value
+        auto value = BasicJsonType(std::forward<Value>(v));
+
+        // check callback
+        const bool keep = skip_callback or callback(static_cast<int>(ref_stack.size()), parse_event_t::value, value);
+
+        // do not handle this value if we just learnt it shall be discarded
+        if (not keep)
+        {
+            return {false, nullptr};
+        }
+
+        if (ref_stack.empty())
+        {
+            root = std::move(value);
+            return {true, &root};
+        }
+        else
+        {
+            // skip this value if we already decided to skip the parent
+            // (https://github.com/nlohmann/json/issues/971#issuecomment-413678360)
+            if (not ref_stack.back())
+            {
+                return {false, nullptr};
+            }
+
+            assert(ref_stack.back()->is_array() or ref_stack.back()->is_object());
+            if (ref_stack.back()->is_array())
+            {
+                ref_stack.back()->m_value.array->push_back(std::move(value));
+                return {true, &(ref_stack.back()->m_value.array->back())};
+            }
+            else
+            {
+                // check if we should store an element for the current key
+                assert(not key_keep_stack.empty());
+                const bool store_element = key_keep_stack.back();
+                key_keep_stack.pop_back();
+
+                if (not store_element)
+                {
+                    return {false, nullptr};
+                }
+
+                assert(object_element);
+                *object_element = std::move(value);
+                return {true, object_element};
+            }
+        }
+    }
+
+    /// the parsed JSON value
+    BasicJsonType& root;
+    /// stack to model hierarchy of values
+    std::vector<BasicJsonType*> ref_stack;
+    /// stack to manage which values to keep
+    std::vector<bool> keep_stack;
+    /// stack to manage which object keys to keep
+    std::vector<bool> key_keep_stack;
+    /// helper to hold the reference for the next object element
+    BasicJsonType* object_element = nullptr;
+    /// whether a syntax error occurred
+    bool errored = false;
+    /// callback function
+    const parser_callback_t callback = nullptr;
+    /// whether to throw exceptions in case of errors
+    const bool allow_exceptions = true;
+    /// a discarded value for the callback
+    BasicJsonType discarded = BasicJsonType::value_t::discarded;
+};
+
+template<typename BasicJsonType>
+class json_sax_acceptor
+{
+  public:
+    using number_integer_t = typename BasicJsonType::number_integer_t;
+    using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
+    using number_float_t = typename BasicJsonType::number_float_t;
+    using string_t = typename BasicJsonType::string_t;
+
+    bool null()
+    {
+        return true;
+    }
+
+    bool boolean(bool)
+    {
+        return true;
+    }
+
+    bool number_integer(number_integer_t)
+    {
+        return true;
+    }
+
+    bool number_unsigned(number_unsigned_t)
+    {
+        return true;
+    }
+
+    bool number_float(number_float_t, const string_t&)
+    {
+        return true;
+    }
+
+    bool string(string_t&)
+    {
+        return true;
+    }
+
+    bool start_object(std::size_t = std::size_t(-1))
+    {
+        return true;
+    }
+
+    bool key(string_t&)
+    {
+        return true;
+    }
+
+    bool end_object()
+    {
+        return true;
+    }
+
+    bool start_array(std::size_t = std::size_t(-1))
+    {
+        return true;
+    }
+
+    bool end_array()
+    {
+        return true;
+    }
+
+    bool parse_error(std::size_t, const std::string&, const detail::exception&)
+    {
+        return false;
+    }
+};
+}
+
+}
+
+// #include <nlohmann/detail/input/lexer.hpp>
+
+// #include <nlohmann/detail/value_t.hpp>
+
+
+namespace nlohmann
+{
+namespace detail
+{
+////////////
+// parser //
+////////////
+
+/*!
 @brief syntax analysis
 
 This class implements a recursive decent parser.
@@ -2892,6 +4505,7 @@ class parser
     using number_integer_t = typename BasicJsonType::number_integer_t;
     using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
     using number_float_t = typename BasicJsonType::number_float_t;
+    using string_t = typename BasicJsonType::string_t;
     using lexer_t = lexer<BasicJsonType>;
     using token_type = typename lexer_t::token_type;
 
@@ -2916,11 +4530,14 @@ class parser
         std::function<bool(int depth, parse_event_t event, BasicJsonType& parsed)>;
 
     /// a parser reading from an input adapter
-    explicit parser(detail::input_adapter_t adapter,
+    explicit parser(detail::input_adapter_t&& adapter,
                     const parser_callback_t cb = nullptr,
                     const bool allow_exceptions_ = true)
-        : callback(cb), m_lexer(adapter), allow_exceptions(allow_exceptions_)
-    {}
+        : callback(cb), m_lexer(std::move(adapter)), allow_exceptions(allow_exceptions_)
+    {
+        // read first token
+        get_token();
+    }
 
     /*!
     @brief public parser interface
@@ -2934,31 +4551,54 @@ class parser
     */
     void parse(const bool strict, BasicJsonType& result)
     {
-        // read first token
-        get_token();
+        if (callback)
+        {
+            json_sax_dom_callback_parser<BasicJsonType> sdp(result, callback, allow_exceptions);
+            sax_parse_internal(&sdp);
+            result.assert_invariant();
 
-        parse_internal(true, result);
-        result.assert_invariant();
+            // in strict mode, input must be completely read
+            if (strict and (get_token() != token_type::end_of_input))
+            {
+                sdp.parse_error(m_lexer.get_position(),
+                                m_lexer.get_token_string(),
+                                parse_error::create(101, m_lexer.get_position(), exception_message(token_type::end_of_input)));
+            }
 
-        // in strict mode, input must be completely read
-        if (strict)
-        {
-            get_token();
-            expect(token_type::end_of_input);
-        }
+            // in case of an error, return discarded value
+            if (sdp.is_errored())
+            {
+                result = value_t::discarded;
+                return;
+            }
 
-        // in case of an error, return discarded value
-        if (errored)
-        {
-            result = value_t::discarded;
-            return;
+            // set top-level value to null if it was discarded by the callback
+            // function
+            if (result.is_discarded())
+            {
+                result = nullptr;
+            }
         }
-
-        // set top-level value to null if it was discarded by the callback
-        // function
-        if (result.is_discarded())
+        else
         {
-            result = nullptr;
+            json_sax_dom_parser<BasicJsonType> sdp(result, allow_exceptions);
+            sax_parse_internal(&sdp);
+            result.assert_invariant();
+
+            // in strict mode, input must be completely read
+            if (strict and (get_token() != token_type::end_of_input))
+            {
+                sdp.parse_error(m_lexer.get_position(),
+                                m_lexer.get_token_string(),
+                                parse_error::create(101, m_lexer.get_position(), exception_message(token_type::end_of_input)));
+            }
+
+            // in case of an error, return discarded value
+            if (sdp.is_errored())
+            {
+                result = value_t::discarded;
+                return;
+            }
         }
     }
 
@@ -2970,413 +4610,311 @@ class parser
     */
     bool accept(const bool strict = true)
     {
-        // read first token
-        get_token();
+        json_sax_acceptor<BasicJsonType> sax_acceptor;
+        return sax_parse(&sax_acceptor, strict);
+    }
 
-        if (not accept_internal())
+    template <typename SAX>
+    bool sax_parse(SAX* sax, const bool strict = true)
+    {
+        (void)detail::is_sax_static_asserts<SAX, BasicJsonType> {};
+        const bool result = sax_parse_internal(sax);
+
+        // strict mode: next byte must be EOF
+        if (result and strict and (get_token() != token_type::end_of_input))
         {
-            return false;
+            return sax->parse_error(m_lexer.get_position(),
+                                    m_lexer.get_token_string(),
+                                    parse_error::create(101, m_lexer.get_position(), exception_message(token_type::end_of_input)));
         }
 
-        // strict => last token must be EOF
-        return not strict or (get_token() == token_type::end_of_input);
+        return result;
     }
 
   private:
-    /*!
-    @brief the actual parser
-    @throw parse_error.101 in case of an unexpected token
-    @throw parse_error.102 if to_unicode fails or surrogate error
-    @throw parse_error.103 if to_unicode fails
-    */
-    void parse_internal(bool keep, BasicJsonType& result)
+    template <typename SAX>
+    bool sax_parse_internal(SAX* sax)
     {
-        // never parse after a parse error was detected
-        assert(not errored);
+        // stack to remember the hieararchy of structured values we are parsing
+        // true = array; false = object
+        std::vector<bool> states;
+        // value to avoid a goto (see comment where set to true)
+        bool skip_to_state_evaluation = false;
 
-        // start with a discarded value
-        if (not result.is_discarded())
+        while (true)
         {
-            result.m_value.destroy(result.m_type);
-            result.m_type = value_t::discarded;
-        }
-
-        switch (last_token)
-        {
-            case token_type::begin_object:
+            if (not skip_to_state_evaluation)
             {
-                if (keep)
+                // invariant: get_token() was called before each iteration
+                switch (last_token)
                 {
-                    if (callback)
+                    case token_type::begin_object:
                     {
-                        keep = callback(depth++, parse_event_t::object_start, result);
-                    }
+                        if (JSON_UNLIKELY(not sax->start_object(std::size_t(-1))))
+                        {
+                            return false;
+                        }
 
-                    if (not callback or keep)
-                    {
-                        // explicitly set result to object to cope with {}
-                        result.m_type = value_t::object;
-                        result.m_value = value_t::object;
-                    }
-                }
+                        // closing } -> we are done
+                        if (get_token() == token_type::end_object)
+                        {
+                            if (JSON_UNLIKELY(not sax->end_object()))
+                            {
+                                return false;
+                            }
+                            break;
+                        }
 
-                // read next token
-                get_token();
-
-                // closing } -> we are done
-                if (last_token == token_type::end_object)
-                {
-                    if (keep and callback and not callback(--depth, parse_event_t::object_end, result))
-                    {
-                        result.m_value.destroy(result.m_type);
-                        result.m_type = value_t::discarded;
-                    }
-                    break;
-                }
-
-                // parse values
-                std::string key;
-                BasicJsonType value;
-                while (true)
-                {
-                    // store key
-                    if (not expect(token_type::value_string))
-                    {
-                        return;
-                    }
-                    key = m_lexer.move_string();
-
-                    bool keep_tag = false;
-                    if (keep)
-                    {
-                        if (callback)
+                        // parse key
+                        if (JSON_UNLIKELY(last_token != token_type::value_string))
                         {
-                            BasicJsonType k(key);
-                            keep_tag = callback(depth, parse_event_t::key, k);
+                            return sax->parse_error(m_lexer.get_position(),
+                                                    m_lexer.get_token_string(),
+                                                    parse_error::create(101, m_lexer.get_position(), exception_message(token_type::value_string)));
                         }
                         else
                         {
-                            keep_tag = true;
+                            if (JSON_UNLIKELY(not sax->key(m_lexer.get_string())))
+                            {
+                                return false;
+                            }
                         }
-                    }
 
-                    // parse separator (:)
-                    get_token();
-                    if (not expect(token_type::name_separator))
-                    {
-                        return;
-                    }
+                        // parse separator (:)
+                        if (JSON_UNLIKELY(get_token() != token_type::name_separator))
+                        {
+                            return sax->parse_error(m_lexer.get_position(),
+                                                    m_lexer.get_token_string(),
+                                                    parse_error::create(101, m_lexer.get_position(), exception_message(token_type::name_separator)));
+                        }
 
-                    // parse and add value
-                    get_token();
-                    value.m_value.destroy(value.m_type);
-                    value.m_type = value_t::discarded;
-                    parse_internal(keep, value);
+                        // remember we are now inside an object
+                        states.push_back(false);
 
-                    if (JSON_UNLIKELY(errored))
-                    {
-                        return;
+                        // parse values
+                        get_token();
+                        continue;
                     }
 
-                    if (keep and keep_tag and not value.is_discarded())
+                    case token_type::begin_array:
                     {
-                        result.m_value.object->emplace(std::move(key), std::move(value));
-                    }
+                        if (JSON_UNLIKELY(not sax->start_array(std::size_t(-1))))
+                        {
+                            return false;
+                        }
 
-                    // comma -> next value
-                    get_token();
-                    if (last_token == token_type::value_separator)
-                    {
-                        get_token();
+                        // closing ] -> we are done
+                        if (get_token() == token_type::end_array)
+                        {
+                            if (JSON_UNLIKELY(not sax->end_array()))
+                            {
+                                return false;
+                            }
+                            break;
+                        }
+
+                        // remember we are now inside an array
+                        states.push_back(true);
+
+                        // parse values (no need to call get_token)
                         continue;
                     }
 
-                    // closing }
-                    if (not expect(token_type::end_object))
+                    case token_type::value_float:
                     {
-                        return;
+                        const auto res = m_lexer.get_number_float();
+
+                        if (JSON_UNLIKELY(not std::isfinite(res)))
+                        {
+                            return sax->parse_error(m_lexer.get_position(),
+                                                    m_lexer.get_token_string(),
+                                                    out_of_range::create(406, "number overflow parsing '" + m_lexer.get_token_string() + "'"));
+                        }
+                        else
+                        {
+                            if (JSON_UNLIKELY(not sax->number_float(res, m_lexer.get_string())))
+                            {
+                                return false;
+                            }
+                            break;
+                        }
                     }
-                    break;
-                }
 
-                if (keep and callback and not callback(--depth, parse_event_t::object_end, result))
-                {
-                    result.m_value.destroy(result.m_type);
-                    result.m_type = value_t::discarded;
-                }
-                break;
-            }
-
-            case token_type::begin_array:
-            {
-                if (keep)
-                {
-                    if (callback)
+                    case token_type::literal_false:
                     {
-                        keep = callback(depth++, parse_event_t::array_start, result);
+                        if (JSON_UNLIKELY(not sax->boolean(false)))
+                        {
+                            return false;
+                        }
+                        break;
                     }
 
-                    if (not callback or keep)
+                    case token_type::literal_null:
                     {
-                        // explicitly set result to array to cope with []
-                        result.m_type = value_t::array;
-                        result.m_value = value_t::array;
+                        if (JSON_UNLIKELY(not sax->null()))
+                        {
+                            return false;
+                        }
+                        break;
                     }
-                }
 
-                // read next token
-                get_token();
-
-                // closing ] -> we are done
-                if (last_token == token_type::end_array)
-                {
-                    if (callback and not callback(--depth, parse_event_t::array_end, result))
+                    case token_type::literal_true:
                     {
-                        result.m_value.destroy(result.m_type);
-                        result.m_type = value_t::discarded;
+                        if (JSON_UNLIKELY(not sax->boolean(true)))
+                        {
+                            return false;
+                        }
+                        break;
                     }
-                    break;
-                }
 
-                // parse values
-                BasicJsonType value;
-                while (true)
-                {
-                    // parse value
-                    value.m_value.destroy(value.m_type);
-                    value.m_type = value_t::discarded;
-                    parse_internal(keep, value);
-
-                    if (JSON_UNLIKELY(errored))
+                    case token_type::value_integer:
                     {
-                        return;
+                        if (JSON_UNLIKELY(not sax->number_integer(m_lexer.get_number_integer())))
+                        {
+                            return false;
+                        }
+                        break;
                     }
 
-                    if (keep and not value.is_discarded())
+                    case token_type::value_string:
                     {
-                        result.m_value.array->push_back(std::move(value));
+                        if (JSON_UNLIKELY(not sax->string(m_lexer.get_string())))
+                        {
+                            return false;
+                        }
+                        break;
                     }
 
-                    // comma -> next value
-                    get_token();
-                    if (last_token == token_type::value_separator)
+                    case token_type::value_unsigned:
                     {
-                        get_token();
-                        continue;
+                        if (JSON_UNLIKELY(not sax->number_unsigned(m_lexer.get_number_unsigned())))
+                        {
+                            return false;
+                        }
+                        break;
                     }
 
-                    // closing ]
-                    if (not expect(token_type::end_array))
+                    case token_type::parse_error:
                     {
-                        return;
+                        // using "uninitialized" to avoid "expected" message
+                        return sax->parse_error(m_lexer.get_position(),
+                                                m_lexer.get_token_string(),
+                                                parse_error::create(101, m_lexer.get_position(), exception_message(token_type::uninitialized)));
                     }
-                    break;
-                }
 
-                if (keep and callback and not callback(--depth, parse_event_t::array_end, result))
-                {
-                    result.m_value.destroy(result.m_type);
-                    result.m_type = value_t::discarded;
-                }
-                break;
-            }
-
-            case token_type::literal_null:
-            {
-                result.m_type = value_t::null;
-                break;
-            }
-
-            case token_type::value_string:
-            {
-                result.m_type = value_t::string;
-                result.m_value = m_lexer.move_string();
-                break;
-            }
-
-            case token_type::literal_true:
-            {
-                result.m_type = value_t::boolean;
-                result.m_value = true;
-                break;
-            }
-
-            case token_type::literal_false:
-            {
-                result.m_type = value_t::boolean;
-                result.m_value = false;
-                break;
-            }
-
-            case token_type::value_unsigned:
-            {
-                result.m_type = value_t::number_unsigned;
-                result.m_value = m_lexer.get_number_unsigned();
-                break;
-            }
-
-            case token_type::value_integer:
-            {
-                result.m_type = value_t::number_integer;
-                result.m_value = m_lexer.get_number_integer();
-                break;
-            }
-
-            case token_type::value_float:
-            {
-                result.m_type = value_t::number_float;
-                result.m_value = m_lexer.get_number_float();
-
-                // throw in case of infinity or NAN
-                if (JSON_UNLIKELY(not std::isfinite(result.m_value.number_float)))
-                {
-                    if (allow_exceptions)
+                    default: // the last token was unexpected
                     {
-                        JSON_THROW(out_of_range::create(406, "number overflow parsing '" +
-                                                        m_lexer.get_token_string() + "'"));
+                        return sax->parse_error(m_lexer.get_position(),
+                                                m_lexer.get_token_string(),
+                                                parse_error::create(101, m_lexer.get_position(), exception_message(token_type::literal_or_value)));
                     }
-                    expect(token_type::uninitialized);
                 }
-                break;
             }
-
-            case token_type::parse_error:
+            else
             {
-                // using "uninitialized" to avoid "expected" message
-                if (not expect(token_type::uninitialized))
-                {
-                    return;
-                }
-                break; // LCOV_EXCL_LINE
+                skip_to_state_evaluation = false;
             }
 
-            default:
+            // we reached this line after we successfully parsed a value
+            if (states.empty())
             {
-                // the last token was unexpected; we expected a value
-                if (not expect(token_type::literal_or_value))
-                {
-                    return;
-                }
-                break; // LCOV_EXCL_LINE
+                // empty stack: we reached the end of the hieararchy: done
+                return true;
             }
-        }
-
-        if (keep and callback and not callback(depth, parse_event_t::value, result))
-        {
-            result.m_type = value_t::discarded;
-        }
-    }
-
-    /*!
-    @brief the actual acceptor
-
-    @invariant 1. The last token is not yet processed. Therefore, the caller
-                  of this function must make sure a token has been read.
-               2. When this function returns, the last token is processed.
-                  That is, the last read character was already considered.
-
-    This invariant makes sure that no token needs to be "unput".
-    */
-    bool accept_internal()
-    {
-        switch (last_token)
-        {
-            case token_type::begin_object:
+            else
             {
-                // read next token
-                get_token();
-
-                // closing } -> we are done
-                if (last_token == token_type::end_object)
+                if (states.back())  // array
                 {
-                    return true;
-                }
-
-                // parse values
-                while (true)
-                {
-                    // parse key
-                    if (last_token != token_type::value_string)
+                    // comma -> next value
+                    if (get_token() == token_type::value_separator)
                     {
-                        return false;
+                        // parse a new value
+                        get_token();
+                        continue;
                     }
 
-                    // parse separator (:)
-                    get_token();
-                    if (last_token != token_type::name_separator)
+                    // closing ]
+                    if (JSON_LIKELY(last_token == token_type::end_array))
                     {
-                        return false;
-                    }
+                        if (JSON_UNLIKELY(not sax->end_array()))
+                        {
+                            return false;
+                        }
 
-                    // parse value
-                    get_token();
-                    if (not accept_internal())
+                        // We are done with this array. Before we can parse a
+                        // new value, we need to evaluate the new state first.
+                        // By setting skip_to_state_evaluation to false, we
+                        // are effectively jumping to the beginning of this if.
+                        assert(not states.empty());
+                        states.pop_back();
+                        skip_to_state_evaluation = true;
+                        continue;
+                    }
+                    else
                     {
-                        return false;
+                        return sax->parse_error(m_lexer.get_position(),
+                                                m_lexer.get_token_string(),
+                                                parse_error::create(101, m_lexer.get_position(), exception_message(token_type::end_array)));
                     }
-
+                }
+                else  // object
+                {
                     // comma -> next value
-                    get_token();
-                    if (last_token == token_type::value_separator)
+                    if (get_token() == token_type::value_separator)
                     {
+                        // parse key
+                        if (JSON_UNLIKELY(get_token() != token_type::value_string))
+                        {
+                            return sax->parse_error(m_lexer.get_position(),
+                                                    m_lexer.get_token_string(),
+                                                    parse_error::create(101, m_lexer.get_position(), exception_message(token_type::value_string)));
+                        }
+                        else
+                        {
+                            if (JSON_UNLIKELY(not sax->key(m_lexer.get_string())))
+                            {
+                                return false;
+                            }
+                        }
+
+                        // parse separator (:)
+                        if (JSON_UNLIKELY(get_token() != token_type::name_separator))
+                        {
+                            return sax->parse_error(m_lexer.get_position(),
+                                                    m_lexer.get_token_string(),
+                                                    parse_error::create(101, m_lexer.get_position(), exception_message(token_type::name_separator)));
+                        }
+
+                        // parse values
                         get_token();
                         continue;
                     }
 
                     // closing }
-                    return (last_token == token_type::end_object);
-                }
-            }
-
-            case token_type::begin_array:
-            {
-                // read next token
-                get_token();
-
-                // closing ] -> we are done
-                if (last_token == token_type::end_array)
-                {
-                    return true;
-                }
-
-                // parse values
-                while (true)
-                {
-                    // parse value
-                    if (not accept_internal())
+                    if (JSON_LIKELY(last_token == token_type::end_object))
                     {
-                        return false;
-                    }
+                        if (JSON_UNLIKELY(not sax->end_object()))
+                        {
+                            return false;
+                        }
 
-                    // comma -> next value
-                    get_token();
-                    if (last_token == token_type::value_separator)
-                    {
-                        get_token();
+                        // We are done with this object. Before we can parse a
+                        // new value, we need to evaluate the new state first.
+                        // By setting skip_to_state_evaluation to false, we
+                        // are effectively jumping to the beginning of this if.
+                        assert(not states.empty());
+                        states.pop_back();
+                        skip_to_state_evaluation = true;
                         continue;
                     }
-
-                    // closing ]
-                    return (last_token == token_type::end_array);
+                    else
+                    {
+                        return sax->parse_error(m_lexer.get_position(),
+                                                m_lexer.get_token_string(),
+                                                parse_error::create(101, m_lexer.get_position(), exception_message(token_type::end_object)));
+                    }
                 }
             }
-
-            case token_type::value_float:
-            {
-                // reject infinity or NAN
-                return std::isfinite(m_lexer.get_number_float());
-            }
-
-            case token_type::literal_false:
-            case token_type::literal_null:
-            case token_type::literal_true:
-            case token_type::value_integer:
-            case token_type::value_string:
-            case token_type::value_unsigned:
-                return true;
-
-            default: // the last token was unexpected
-                return false;
         }
     }
 
@@ -3386,30 +4924,8 @@ class parser
         return (last_token = m_lexer.scan());
     }
 
-    /*!
-    @throw parse_error.101 if expected token did not occur
-    */
-    bool expect(token_type t)
+    std::string exception_message(const token_type expected)
     {
-        if (JSON_UNLIKELY(t != last_token))
-        {
-            errored = true;
-            expected = t;
-            if (allow_exceptions)
-            {
-                throw_exception();
-            }
-            else
-            {
-                return false;
-            }
-        }
-
-        return true;
-    }
-
-    [[noreturn]] void throw_exception() const
-    {
         std::string error_msg = "syntax error - ";
         if (last_token == token_type::parse_error)
         {
@@ -3426,31 +4942,33 @@ class parser
             error_msg += "; expected " + std::string(lexer_t::token_type_name(expected));
         }
 
-        JSON_THROW(parse_error::create(101, m_lexer.get_position(), error_msg));
+        return error_msg;
     }
 
   private:
-    /// current level of recursion
-    int depth = 0;
     /// callback function
     const parser_callback_t callback = nullptr;
     /// the type of the last read token
     token_type last_token = token_type::uninitialized;
     /// the lexer
     lexer_t m_lexer;
-    /// whether a syntax error occurred
-    bool errored = false;
-    /// possible reason for the syntax error
-    token_type expected = token_type::uninitialized;
     /// whether to throw exceptions in case of errors
     const bool allow_exceptions = true;
 };
+}
+}
 
-///////////////
-// iterators //
-///////////////
+// #include <nlohmann/detail/iterators/primitive_iterator.hpp>
 
-/*!
+
+#include <cstddef> // ptrdiff_t
+#include <limits>  // numeric_limits
+
+namespace nlohmann
+{
+namespace detail
+{
+/*
 @brief an iterator for primitive JSON types
 
 This class models an iterator for primitive JSON types (boolean, number,
@@ -3461,9 +4979,15 @@ end_value (`1`) models past the end.
 */
 class primitive_iterator_t
 {
-  public:
+  private:
     using difference_type = std::ptrdiff_t;
+    static constexpr difference_type begin_value = 0;
+    static constexpr difference_type end_value = begin_value + 1;
 
+    /// iterator as signed integer type
+    difference_type m_it = (std::numeric_limits<std::ptrdiff_t>::min)();
+
+  public:
     constexpr difference_type get_value() const noexcept
     {
         return m_it;
@@ -3503,10 +5027,10 @@ class primitive_iterator_t
         return lhs.m_it < rhs.m_it;
     }
 
-    primitive_iterator_t operator+(difference_type i)
+    primitive_iterator_t operator+(difference_type n) noexcept
     {
         auto result = *this;
-        result += i;
+        result += n;
         return result;
     }
 
@@ -3515,57 +5039,57 @@ class primitive_iterator_t
         return lhs.m_it - rhs.m_it;
     }
 
-    friend std::ostream& operator<<(std::ostream& os, primitive_iterator_t it)
+    primitive_iterator_t& operator++() noexcept
     {
-        return os << it.m_it;
-    }
-
-    primitive_iterator_t& operator++()
-    {
         ++m_it;
         return *this;
     }
 
-    primitive_iterator_t const operator++(int)
+    primitive_iterator_t const operator++(int) noexcept
     {
         auto result = *this;
-        m_it++;
+        ++m_it;
         return result;
     }
 
-    primitive_iterator_t& operator--()
+    primitive_iterator_t& operator--() noexcept
     {
         --m_it;
         return *this;
     }
 
-    primitive_iterator_t const operator--(int)
+    primitive_iterator_t const operator--(int) noexcept
     {
         auto result = *this;
-        m_it--;
+        --m_it;
         return result;
     }
 
-    primitive_iterator_t& operator+=(difference_type n)
+    primitive_iterator_t& operator+=(difference_type n) noexcept
     {
         m_it += n;
         return *this;
     }
 
-    primitive_iterator_t& operator-=(difference_type n)
+    primitive_iterator_t& operator-=(difference_type n) noexcept
     {
         m_it -= n;
         return *this;
     }
+};
+}
+}
 
-  private:
-    static constexpr difference_type begin_value = 0;
-    static constexpr difference_type end_value = begin_value + 1;
+// #include <nlohmann/detail/iterators/internal_iterator.hpp>
 
-    /// iterator as signed integer type
-    difference_type m_it = (std::numeric_limits<std::ptrdiff_t>::min)();
-};
 
+// #include <nlohmann/detail/iterators/primitive_iterator.hpp>
+
+
+namespace nlohmann
+{
+namespace detail
+{
 /*!
 @brief an iterator value
 
@@ -3581,7 +5105,34 @@ template<typename BasicJsonType> struct internal_itera
     /// generic iterator for all other types
     primitive_iterator_t primitive_iterator {};
 };
+}
+}
 
+// #include <nlohmann/detail/iterators/iter_impl.hpp>
+
+
+#include <ciso646> // not
+#include <iterator> // iterator, random_access_iterator_tag, bidirectional_iterator_tag, advance, next
+#include <type_traits> // conditional, is_const, remove_const
+
+// #include <nlohmann/detail/exceptions.hpp>
+
+// #include <nlohmann/detail/iterators/internal_iterator.hpp>
+
+// #include <nlohmann/detail/iterators/primitive_iterator.hpp>
+
+// #include <nlohmann/detail/macro_scope.hpp>
+
+// #include <nlohmann/detail/meta/cpp_future.hpp>
+
+// #include <nlohmann/detail/value_t.hpp>
+
+
+namespace nlohmann
+{
+namespace detail
+{
+// forward declare, to be able to friend it later on
 template<typename IteratorType> class iteration_proxy;
 
 /*!
@@ -3597,7 +5148,7 @@ This class implements a both iterators (iterator and c
 
 @requirement The class satisfies the following concept requirements:
 -
-[BidirectionalIterator](http://en.cppreference.com/w/cpp/concept/BidirectionalIterator):
+[BidirectionalIterator](https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator):
   The iterator that can be moved can be moved in both directions (i.e.
   incremented and decremented).
 
@@ -4149,7 +5700,7 @@ class iter_impl
     @brief  return the key of an object iterator
     @pre The iterator is initialized; i.e. `m_object != nullptr`.
     */
-    typename object_t::key_type key() const
+    const typename object_t::key_type& key() const
     {
         assert(m_object != nullptr);
 
@@ -4174,95 +5725,28 @@ class iter_impl
     /// associated JSON instance
     pointer m_object = nullptr;
     /// the actual iterator of the associated instance
-    internal_iterator<typename std::remove_const<BasicJsonType>::type> m_it = {};
+    internal_iterator<typename std::remove_const<BasicJsonType>::type> m_it;
 };
+}
+}
 
-/// proxy class for the iterator_wrapper functions
-template<typename IteratorType> class iteration_proxy
-{
-  private:
-    /// helper class for iteration
-    class iteration_proxy_internal
-    {
-      private:
-        /// the iterator
-        IteratorType anchor;
-        /// an index for arrays (used to create key names)
-        std::size_t array_index = 0;
+// #include <nlohmann/detail/iterators/iteration_proxy.hpp>
 
-      public:
-        explicit iteration_proxy_internal(IteratorType it) noexcept : anchor(it) {}
+// #include <nlohmann/detail/iterators/json_reverse_iterator.hpp>
 
-        /// dereference operator (needed for range-based for)
-        iteration_proxy_internal& operator*()
-        {
-            return *this;
-        }
 
-        /// increment operator (needed for range-based for)
-        iteration_proxy_internal& operator++()
-        {
-            ++anchor;
-            ++array_index;
+#include <cstddef> // ptrdiff_t
+#include <iterator> // reverse_iterator
+#include <utility> // declval
 
-            return *this;
-        }
+namespace nlohmann
+{
+namespace detail
+{
+//////////////////////
+// reverse_iterator //
+//////////////////////
 
-        /// inequality operator (needed for range-based for)
-        bool operator!=(const iteration_proxy_internal& o) const noexcept
-        {
-            return anchor != o.anchor;
-        }
-
-        /// return key of the iterator
-        std::string key() const
-        {
-            assert(anchor.m_object != nullptr);
-
-            switch (anchor.m_object->type())
-            {
-                // use integer array index as key
-                case value_t::array:
-                    return std::to_string(array_index);
-
-                // use key from the object
-                case value_t::object:
-                    return anchor.key();
-
-                // use an empty key for all primitive types
-                default:
-                    return "";
-            }
-        }
-
-        /// return value of the iterator
-        typename IteratorType::reference value() const
-        {
-            return anchor.value();
-        }
-    };
-
-    /// the container to iterate
-    typename IteratorType::reference container;
-
-  public:
-    /// construct iteration proxy from a container
-    explicit iteration_proxy(typename IteratorType::reference cont)
-        : container(cont) {}
-
-    /// return iterator begin (needed for range-based for)
-    iteration_proxy_internal begin() noexcept
-    {
-        return iteration_proxy_internal(container.begin());
-    }
-
-    /// return iterator end (needed for range-based for)
-    iteration_proxy_internal end() noexcept
-    {
-        return iteration_proxy_internal(container.end());
-    }
-};
-
 /*!
 @brief a template for a reverse iterator class
 
@@ -4272,10 +5756,10 @@ create @ref const_reverse_iterator).
 
 @requirement The class satisfies the following concept requirements:
 -
-[BidirectionalIterator](http://en.cppreference.com/w/cpp/concept/BidirectionalIterator):
+[BidirectionalIterator](https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator):
   The iterator that can be moved can be moved in both directions (i.e.
   incremented and decremented).
-- [OutputIterator](http://en.cppreference.com/w/cpp/concept/OutputIterator):
+- [OutputIterator](https://en.cppreference.com/w/cpp/named_req/OutputIterator):
   It is possible to write to the pointed-to element (only if @a Base is
   @ref iterator).
 
@@ -4292,11 +5776,11 @@ class json_reverse_iterator : public std::reverse_iter
     using reference = typename Base::reference;
 
     /// create reverse iterator from iterator
-    json_reverse_iterator(const typename base_iterator::iterator_type& it) noexcept
+    explicit json_reverse_iterator(const typename base_iterator::iterator_type& it) noexcept
         : base_iterator(it) {}
 
     /// create reverse iterator from base class
-    json_reverse_iterator(const base_iterator& it) noexcept : base_iterator(it) {}
+    explicit json_reverse_iterator(const base_iterator& it) noexcept : base_iterator(it) {}
 
     /// post-increment (it++)
     json_reverse_iterator const operator++(int)
@@ -4366,11 +5850,25 @@ class json_reverse_iterator : public std::reverse_iter
         return it.operator * ();
     }
 };
+}
+}
 
-/////////////////////
-// output adapters //
-/////////////////////
+// #include <nlohmann/detail/output/output_adapters.hpp>
 
+
+#include <algorithm> // copy
+#include <cstddef> // size_t
+#include <ios> // streamsize
+#include <iterator> // back_inserter
+#include <memory> // shared_ptr, make_shared
+#include <ostream> // basic_ostream
+#include <string> // basic_string
+#include <vector> // vector
+
+namespace nlohmann
+{
+namespace detail
+{
 /// abstract output adapter interface
 template<typename CharType> struct output_adapter_protocol
 {
@@ -4426,11 +5924,11 @@ class output_stream_adapter : public output_adapter_pr
 };
 
 /// output adapter for basic_string
-template<typename CharType>
+template<typename CharType, typename StringType = std::basic_string<CharType>>
 class output_string_adapter : public output_adapter_protocol<CharType>
 {
   public:
-    explicit output_string_adapter(std::basic_string<CharType>& s) : str(s) {}
+    explicit output_string_adapter(StringType& s) : str(s) {}
 
     void write_character(CharType c) override
     {
@@ -4443,10 +5941,10 @@ class output_string_adapter : public output_adapter_pr
     }
 
   private:
-    std::basic_string<CharType>& str;
+    StringType& str;
 };
 
-template<typename CharType>
+template<typename CharType, typename StringType = std::basic_string<CharType>>
 class output_adapter
 {
   public:
@@ -4456,8 +5954,8 @@ class output_adapter
     output_adapter(std::basic_ostream<CharType>& s)
         : oa(std::make_shared<output_stream_adapter<CharType>>(s)) {}
 
-    output_adapter(std::basic_string<CharType>& s)
-        : oa(std::make_shared<output_string_adapter<CharType>>(s)) {}
+    output_adapter(StringType& s)
+        : oa(std::make_shared<output_string_adapter<CharType, StringType>>(s)) {}
 
     operator output_adapter_t<CharType>()
     {
@@ -4467,19 +5965,57 @@ class output_adapter
   private:
     output_adapter_t<CharType> oa = nullptr;
 };
+}
+}
 
-//////////////////////////////
-// binary reader and writer //
-//////////////////////////////
+// #include <nlohmann/detail/input/binary_reader.hpp>
 
+
+#include <algorithm> // generate_n
+#include <array> // array
+#include <cassert> // assert
+#include <cmath> // ldexp
+#include <cstddef> // size_t
+#include <cstdint> // uint8_t, uint16_t, uint32_t, uint64_t
+#include <cstdio> // snprintf
+#include <cstring> // memcpy
+#include <iterator> // back_inserter
+#include <limits> // numeric_limits
+#include <string> // char_traits, string
+#include <utility> // make_pair, move
+
+// #include <nlohmann/detail/input/input_adapters.hpp>
+
+// #include <nlohmann/detail/input/json_sax.hpp>
+
+// #include <nlohmann/detail/exceptions.hpp>
+
+// #include <nlohmann/detail/macro_scope.hpp>
+
+// #include <nlohmann/detail/meta/is_sax.hpp>
+
+// #include <nlohmann/detail/value_t.hpp>
+
+
+namespace nlohmann
+{
+namespace detail
+{
+///////////////////
+// binary reader //
+///////////////////
+
 /*!
-@brief deserialization of CBOR and MessagePack values
+@brief deserialization of CBOR, MessagePack, and UBJSON values
 */
-template<typename BasicJsonType>
+template<typename BasicJsonType, typename SAX = json_sax_dom_parser<BasicJsonType>>
 class binary_reader
 {
     using number_integer_t = typename BasicJsonType::number_integer_t;
     using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
+    using number_float_t = typename BasicJsonType::number_float_t;
+    using string_t = typename BasicJsonType::string_t;
+    using json_sax_t = SAX;
 
   public:
     /*!
@@ -4489,49 +6025,63 @@ class binary_reader
     */
     explicit binary_reader(input_adapter_t adapter) : ia(std::move(adapter))
     {
+        (void)detail::is_sax_static_asserts<SAX, BasicJsonType> {};
         assert(ia);
     }
 
     /*!
-    @brief create a JSON value from CBOR input
-
+    @param[in] format  the binary format to parse
+    @param[in] sax_    a SAX event processor
     @param[in] strict  whether to expect the input to be consumed completed
-    @return JSON value created from CBOR input
 
-    @throw parse_error.110 if input ended unexpectedly or the end of file was
-                           not reached when @a strict was set to true
-    @throw parse_error.112 if unsupported byte was read
+    @return
     */
-    BasicJsonType parse_cbor(const bool strict)
+    bool sax_parse(const input_format_t format,
+                   json_sax_t* sax_,
+                   const bool strict = true)
     {
-        const auto res = parse_cbor_internal();
-        if (strict)
+        sax = sax_;
+        bool result = false;
+
+        switch (format)
         {
-            get();
-            check_eof(true);
-        }
-        return res;
-    }
+            case input_format_t::cbor:
+                result = parse_cbor_internal();
+                break;
 
-    /*!
-    @brief create a JSON value from MessagePack input
+            case input_format_t::msgpack:
+                result = parse_msgpack_internal();
+                break;
 
-    @param[in] strict  whether to expect the input to be consumed completed
-    @return JSON value created from MessagePack input
+            case input_format_t::ubjson:
+                result = parse_ubjson_internal();
+                break;
 
-    @throw parse_error.110 if input ended unexpectedly or the end of file was
-                           not reached when @a strict was set to true
-    @throw parse_error.112 if unsupported byte was read
-    */
-    BasicJsonType parse_msgpack(const bool strict)
-    {
-        const auto res = parse_msgpack_internal();
-        if (strict)
+            // LCOV_EXCL_START
+            default:
+                assert(false);
+                // LCOV_EXCL_STOP
+        }
+
+        // strict mode: next byte must be EOF
+        if (result and strict)
         {
-            get();
-            check_eof(true);
+            if (format == input_format_t::ubjson)
+            {
+                get_ignore_noop();
+            }
+            else
+            {
+                get();
+            }
+
+            if (JSON_UNLIKELY(current != std::char_traits<char>::eof()))
+            {
+                return sax->parse_error(chars_read, get_token_string(), parse_error::create(110, chars_read, "expected end of input"));
+            }
         }
-        return res;
+
+        return result;
     }
 
     /*!
@@ -4551,14 +6101,16 @@ class binary_reader
     @param[in] get_char  whether a new character should be retrieved from the
                          input (true, default) or whether the last read
                          character should be considered instead
+
+    @return whether a valid CBOR value was passed to the SAX parser
     */
-    BasicJsonType parse_cbor_internal(const bool get_char = true)
+    bool parse_cbor_internal(const bool get_char = true)
     {
         switch (get_char ? get() : current)
         {
             // EOF
             case std::char_traits<char>::eof():
-                JSON_THROW(parse_error::create(110, chars_read, "unexpected end of input"));
+                return unexpect_eof();
 
             // Integer 0x00..0x17 (0..23)
             case 0x00:
@@ -4585,19 +6137,31 @@ class binary_reader
             case 0x15:
             case 0x16:
             case 0x17:
-                return static_cast<number_unsigned_t>(current);
+                return sax->number_unsigned(static_cast<number_unsigned_t>(current));
 
             case 0x18: // Unsigned integer (one-byte uint8_t follows)
-                return get_number<uint8_t>();
+            {
+                uint8_t number;
+                return get_number(number) and sax->number_unsigned(number);
+            }
 
             case 0x19: // Unsigned integer (two-byte uint16_t follows)
-                return get_number<uint16_t>();
+            {
+                uint16_t number;
+                return get_number(number) and sax->number_unsigned(number);
+            }
 
             case 0x1A: // Unsigned integer (four-byte uint32_t follows)
-                return get_number<uint32_t>();
+            {
+                uint32_t number;
+                return get_number(number) and sax->number_unsigned(number);
+            }
 
             case 0x1B: // Unsigned integer (eight-byte uint64_t follows)
-                return get_number<uint64_t>();
+            {
+                uint64_t number;
+                return get_number(number) and sax->number_unsigned(number);
+            }
 
             // Negative integer -1-0x00..-1-0x17 (-1..-24)
             case 0x20:
@@ -4624,28 +6188,31 @@ class binary_reader
             case 0x35:
             case 0x36:
             case 0x37:
-                return static_cast<int8_t>(0x20 - 1 - current);
+                return sax->number_integer(static_cast<int8_t>(0x20 - 1 - current));
 
             case 0x38: // Negative integer (one-byte uint8_t follows)
             {
-                // must be uint8_t !
-                return static_cast<number_integer_t>(-1) - get_number<uint8_t>();
+                uint8_t number;
+                return get_number(number) and sax->number_integer(static_cast<number_integer_t>(-1) - number);
             }
 
             case 0x39: // Negative integer -1-n (two-byte uint16_t follows)
             {
-                return static_cast<number_integer_t>(-1) - get_number<uint16_t>();
+                uint16_t number;
+                return get_number(number) and sax->number_integer(static_cast<number_integer_t>(-1) - number);
             }
 
             case 0x3A: // Negative integer -1-n (four-byte uint32_t follows)
             {
-                return static_cast<number_integer_t>(-1) - get_number<uint32_t>();
+                uint32_t number;
+                return get_number(number) and sax->number_integer(static_cast<number_integer_t>(-1) - number);
             }
 
             case 0x3B: // Negative integer -1-n (eight-byte uint64_t follows)
             {
-                return static_cast<number_integer_t>(-1) -
-                       static_cast<number_integer_t>(get_number<uint64_t>());
+                uint64_t number;
+                return get_number(number) and sax->number_integer(static_cast<number_integer_t>(-1)
+                        - static_cast<number_integer_t>(number));
             }
 
             // UTF-8 string (0x00..0x17 bytes follow)
@@ -4679,7 +6246,8 @@ class binary_reader
             case 0x7B: // UTF-8 string (eight-byte uint64_t for n follow)
             case 0x7F: // UTF-8 string (indefinite length)
             {
-                return get_cbor_string();
+                string_t s;
+                return get_cbor_string(s) and sax->string(s);
             }
 
             // array (0x00..0x17 data items follow)
@@ -4707,39 +6275,34 @@ class binary_reader
             case 0x95:
             case 0x96:
             case 0x97:
-            {
-                return get_cbor_array(current & 0x1F);
-            }
+                return get_cbor_array(static_cast<std::size_t>(current & 0x1F));
 
             case 0x98: // array (one-byte uint8_t for n follows)
             {
-                return get_cbor_array(get_number<uint8_t>());
+                uint8_t len;
+                return get_number(len) and get_cbor_array(static_cast<std::size_t>(len));
             }
 
             case 0x99: // array (two-byte uint16_t for n follow)
             {
-                return get_cbor_array(get_number<uint16_t>());
+                uint16_t len;
+                return get_number(len) and get_cbor_array(static_cast<std::size_t>(len));
             }
 
             case 0x9A: // array (four-byte uint32_t for n follow)
             {
-                return get_cbor_array(get_number<uint32_t>());
+                uint32_t len;
+                return get_number(len) and get_cbor_array(static_cast<std::size_t>(len));
             }
 
             case 0x9B: // array (eight-byte uint64_t for n follow)
             {
-                return get_cbor_array(get_number<uint64_t>());
+                uint64_t len;
+                return get_number(len) and get_cbor_array(static_cast<std::size_t>(len));
             }
 
             case 0x9F: // array (indefinite length)
-            {
-                BasicJsonType result = value_t::array;
-                while (get() != 0xFF)
-                {
-                    result.push_back(parse_cbor_internal(false));
-                }
-                return result;
-            }
+                return get_cbor_array(std::size_t(-1));
 
             // map (0x00..0x17 pairs of data items follow)
             case 0xA0:
@@ -4766,62 +6329,56 @@ class binary_reader
             case 0xB5:
             case 0xB6:
             case 0xB7:
-            {
-                return get_cbor_object(current & 0x1F);
-            }
+                return get_cbor_object(static_cast<std::size_t>(current & 0x1F));
 
             case 0xB8: // map (one-byte uint8_t for n follows)
             {
-                return get_cbor_object(get_number<uint8_t>());
+                uint8_t len;
+                return get_number(len) and get_cbor_object(static_cast<std::size_t>(len));
             }
 
             case 0xB9: // map (two-byte uint16_t for n follow)
             {
-                return get_cbor_object(get_number<uint16_t>());
+                uint16_t len;
+                return get_number(len) and get_cbor_object(static_cast<std::size_t>(len));
             }
 
             case 0xBA: // map (four-byte uint32_t for n follow)
             {
-                return get_cbor_object(get_number<uint32_t>());
+                uint32_t len;
+                return get_number(len) and get_cbor_object(static_cast<std::size_t>(len));
             }
 
             case 0xBB: // map (eight-byte uint64_t for n follow)
             {
-                return get_cbor_object(get_number<uint64_t>());
+                uint64_t len;
+                return get_number(len) and get_cbor_object(static_cast<std::size_t>(len));
             }
 
             case 0xBF: // map (indefinite length)
-            {
-                BasicJsonType result = value_t::object;
-                while (get() != 0xFF)
-                {
-                    auto key = get_cbor_string();
-                    result[key] = parse_cbor_internal();
-                }
-                return result;
-            }
+                return get_cbor_object(std::size_t(-1));
 
             case 0xF4: // false
-            {
-                return false;
-            }
+                return sax->boolean(false);
 
             case 0xF5: // true
-            {
-                return true;
-            }
+                return sax->boolean(true);
 
             case 0xF6: // null
-            {
-                return value_t::null;
-            }
+                return sax->null();
 
             case 0xF9: // Half-Precision Float (two-byte IEEE 754)
             {
                 const int byte1 = get();
-                check_eof();
+                if (JSON_UNLIKELY(not unexpect_eof()))
+                {
+                    return false;
+                }
                 const int byte2 = get();
-                check_eof();
+                if (JSON_UNLIKELY(not unexpect_eof()))
+                {
+                    return false;
+                }
 
                 // code from RFC 7049, Appendix D, Figure 3:
                 // As half-precision floating-point numbers were only added
@@ -4832,51 +6389,59 @@ class binary_reader
                 // half-precision floating-point numbers in the C language
                 // is shown in Fig. 3.
                 const int half = (byte1 << 8) + byte2;
-                const int exp = (half >> 10) & 0x1F;
-                const int mant = half & 0x3FF;
-                double val;
-                if (exp == 0)
+                const double val = [&half]
                 {
-                    val = std::ldexp(mant, -24);
-                }
-                else if (exp != 31)
-                {
-                    val = std::ldexp(mant + 1024, exp - 25);
-                }
-                else
-                {
-                    val = (mant == 0) ? std::numeric_limits<double>::infinity()
-                          : std::numeric_limits<double>::quiet_NaN();
-                }
-                return (half & 0x8000) != 0 ? -val : val;
+                    const int exp = (half >> 10) & 0x1F;
+                    const int mant = half & 0x3FF;
+                    assert(0 <= exp and exp <= 32);
+                    assert(0 <= mant and mant <= 1024);
+                    switch (exp)
+                    {
+                        case 0:
+                            return std::ldexp(mant, -24);
+                        case 31:
+                            return (mant == 0)
+                            ? std::numeric_limits<double>::infinity()
+                            : std::numeric_limits<double>::quiet_NaN();
+                        default:
+                            return std::ldexp(mant + 1024, exp - 25);
+                    }
+                }();
+                return sax->number_float((half & 0x8000) != 0
+                                         ? static_cast<number_float_t>(-val)
+                                         : static_cast<number_float_t>(val), "");
             }
 
             case 0xFA: // Single-Precision Float (four-byte IEEE 754)
             {
-                return get_number<float>();
+                float number;
+                return get_number(number) and sax->number_float(static_cast<number_float_t>(number), "");
             }
 
             case 0xFB: // Double-Precision Float (eight-byte IEEE 754)
             {
-                return get_number<double>();
+                double number;
+                return get_number(number) and sax->number_float(static_cast<number_float_t>(number), "");
             }
 
             default: // anything else (0xFF is handled inside the other types)
             {
-                std::stringstream ss;
-                ss << std::setw(2) << std::uppercase << std::setfill('0') << std::hex << current;
-                JSON_THROW(parse_error::create(112, chars_read, "error reading CBOR; last byte: 0x" + ss.str()));
+                auto last_token = get_token_string();
+                return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read, "error reading CBOR; last byte: 0x" + last_token));
             }
         }
     }
 
-    BasicJsonType parse_msgpack_internal()
+    /*!
+    @return whether a valid MessagePack value was passed to the SAX parser
+    */
+    bool parse_msgpack_internal()
     {
         switch (get())
         {
             // EOF
             case std::char_traits<char>::eof():
-                JSON_THROW(parse_error::create(110, chars_read, "unexpected end of input"));
+                return unexpect_eof();
 
             // positive fixint
             case 0x00:
@@ -5007,7 +6572,7 @@ class binary_reader
             case 0x7D:
             case 0x7E:
             case 0x7F:
-                return static_cast<number_unsigned_t>(current);
+                return sax->number_unsigned(static_cast<number_unsigned_t>(current));
 
             // fixmap
             case 0x80:
@@ -5026,9 +6591,7 @@ class binary_reader
             case 0x8D:
             case 0x8E:
             case 0x8F:
-            {
-                return get_msgpack_object(current & 0x0F);
-            }
+                return get_msgpack_object(static_cast<std::size_t>(current & 0x0F));
 
             // fixarray
             case 0x90:
@@ -5047,9 +6610,7 @@ class binary_reader
             case 0x9D:
             case 0x9E:
             case 0x9F:
-            {
-                return get_msgpack_array(current & 0x0F);
-            }
+                return get_msgpack_array(static_cast<std::size_t>(current & 0x0F));
 
             // fixstr
             case 0xA0:
@@ -5084,73 +6645,113 @@ class binary_reader
             case 0xBD:
             case 0xBE:
             case 0xBF:
-                return get_msgpack_string();
+            {
+                string_t s;
+                return get_msgpack_string(s) and sax->string(s);
+            }
 
             case 0xC0: // nil
-                return value_t::null;
+                return sax->null();
 
             case 0xC2: // false
-                return false;
+                return sax->boolean(false);
 
             case 0xC3: // true
-                return true;
+                return sax->boolean(true);
 
             case 0xCA: // float 32
-                return get_number<float>();
+            {
+                float number;
+                return get_number(number) and sax->number_float(static_cast<number_float_t>(number), "");
+            }
 
             case 0xCB: // float 64
-                return get_number<double>();
+            {
+                double number;
+                return get_number(number) and sax->number_float(static_cast<number_float_t>(number), "");
+            }
 
             case 0xCC: // uint 8
-                return get_number<uint8_t>();
+            {
+                uint8_t number;
+                return get_number(number) and sax->number_unsigned(number);
+            }
 
             case 0xCD: // uint 16
-                return get_number<uint16_t>();
+            {
+                uint16_t number;
+                return get_number(number) and sax->number_unsigned(number);
+            }
 
             case 0xCE: // uint 32
-                return get_number<uint32_t>();
+            {
+                uint32_t number;
+                return get_number(number) and sax->number_unsigned(number);
+            }
 
             case 0xCF: // uint 64
-                return get_number<uint64_t>();
+            {
+                uint64_t number;
+                return get_number(number) and sax->number_unsigned(number);
+            }
 
             case 0xD0: // int 8
-                return get_number<int8_t>();
+            {
+                int8_t number;
+                return get_number(number) and sax->number_integer(number);
+            }
 
             case 0xD1: // int 16
-                return get_number<int16_t>();
+            {
+                int16_t number;
+                return get_number(number) and sax->number_integer(number);
+            }
 
             case 0xD2: // int 32
-                return get_number<int32_t>();
+            {
+                int32_t number;
+                return get_number(number) and sax->number_integer(number);
+            }
 
             case 0xD3: // int 64
-                return get_number<int64_t>();
+            {
+                int64_t number;
+                return get_number(number) and sax->number_integer(number);
+            }
 
             case 0xD9: // str 8
             case 0xDA: // str 16
             case 0xDB: // str 32
-                return get_msgpack_string();
+            {
+                string_t s;
+                return get_msgpack_string(s) and sax->string(s);
+            }
 
             case 0xDC: // array 16
             {
-                return get_msgpack_array(get_number<uint16_t>());
+                uint16_t len;
+                return get_number(len) and get_msgpack_array(static_cast<std::size_t>(len));
             }
 
             case 0xDD: // array 32
             {
-                return get_msgpack_array(get_number<uint32_t>());
+                uint32_t len;
+                return get_number(len) and get_msgpack_array(static_cast<std::size_t>(len));
             }
 
             case 0xDE: // map 16
             {
-                return get_msgpack_object(get_number<uint16_t>());
+                uint16_t len;
+                return get_number(len) and get_msgpack_object(static_cast<std::size_t>(len));
             }
 
             case 0xDF: // map 32
             {
-                return get_msgpack_object(get_number<uint32_t>());
+                uint32_t len;
+                return get_number(len) and get_msgpack_object(static_cast<std::size_t>(len));
             }
 
-            // positive fixint
+            // negative fixint
             case 0xE0:
             case 0xE1:
             case 0xE2:
@@ -5183,19 +6784,29 @@ class binary_reader
             case 0xFD:
             case 0xFE:
             case 0xFF:
-                return static_cast<int8_t>(current);
+                return sax->number_integer(static_cast<int8_t>(current));
 
             default: // anything else
             {
-                std::stringstream ss;
-                ss << std::setw(2) << std::uppercase << std::setfill('0') << std::hex << current;
-                JSON_THROW(parse_error::create(112, chars_read,
-                                               "error reading MessagePack; last byte: 0x" + ss.str()));
+                auto last_token = get_token_string();
+                return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read, "error reading MessagePack; last byte: 0x" + last_token));
             }
         }
     }
 
     /*!
+    @param[in] get_char  whether a new character should be retrieved from the
+                         input (true, default) or whether the last read
+                         character should be considered instead
+
+    @return whether a valid UBJSON value was passed to the SAX parser
+    */
+    bool parse_ubjson_internal(const bool get_char = true)
+    {
+        return get_ubjson_value(get_char ? get_ignore_noop() : current);
+    }
+
+    /*!
     @brief get next character from the input
 
     This function provides the interface to the used input adapter. It does
@@ -5210,27 +6821,44 @@ class binary_reader
         return (current = ia->get_character());
     }
 
+    /*!
+    @return character read from the input after ignoring all 'N' entries
+    */
+    int get_ignore_noop()
+    {
+        do
+        {
+            get();
+        }
+        while (current == 'N');
+
+        return current;
+    }
+
     /*
     @brief read a number from the input
 
     @tparam NumberType the type of the number
+    @param[out] result  number of type @a NumberType
 
-    @return number of type @a NumberType
+    @return whether conversion completed
 
     @note This function needs to respect the system's endianess, because
-          bytes in CBOR and MessagePack are stored in network order (big
-          endian) and therefore need reordering on little endian systems.
-
-    @throw parse_error.110 if input has less than `sizeof(NumberType)` bytes
+          bytes in CBOR, MessagePack, and UBJSON are stored in network order
+          (big endian) and therefore need reordering on little endian systems.
     */
-    template<typename NumberType> NumberType get_number()
+    template<typename NumberType>
+    bool get_number(NumberType& result)
     {
         // step 1: read input into array with system's byte order
         std::array<uint8_t, sizeof(NumberType)> vec;
         for (std::size_t i = 0; i < sizeof(NumberType); ++i)
         {
             get();
-            check_eof();
+            if (JSON_UNLIKELY(not unexpect_eof()))
+            {
+                return false;
+            }
 
             // reverse byte order prior to conversion if necessary
             if (is_little_endian)
@@ -5244,35 +6872,37 @@ class binary_reader
         }
 
         // step 2: convert array into number of type T and return
-        NumberType result;
         std::memcpy(&result, vec.data(), sizeof(NumberType));
-        return result;
+        return true;
     }
 
     /*!
     @brief create a string by reading characters from the input
 
-    @param[in] len number of bytes to read
+    @tparam NumberType the type of the number
+    @param[in] len number of characters to read
+    @param[out] string created by reading @a len bytes
 
+    @return whether string creation completed
+
     @note We can not reserve @a len bytes for the result, because @a len
-          may be too large. Usually, @ref check_eof() detects the end of
+          may be too large. Usually, @ref unexpect_eof() detects the end of
           the input before we run out of string memory.
-
-    @return string created by reading @a len bytes
-
-    @throw parse_error.110 if input has less than @a len bytes
     */
     template<typename NumberType>
-    std::string get_string(const NumberType len)
+    bool get_string(const NumberType len, string_t& result)
     {
-        std::string result;
-        std::generate_n(std::back_inserter(result), len, [this]()
+        bool success = true;
+        std::generate_n(std::back_inserter(result), len, [this, &success]()
         {
             get();
-            check_eof();
+            if (JSON_UNLIKELY(not unexpect_eof()))
+            {
+                success = false;
+            }
             return static_cast<char>(current);
         });
-        return result;
+        return success;
     }
 
     /*!
@@ -5282,14 +6912,16 @@ class binary_reader
     string length and then copies this number of bytes into a string.
     Additionally, CBOR's strings with indefinite lengths are supported.
 
-    @return string
+    @param[out] result  created string
 
-    @throw parse_error.110 if input ended
-    @throw parse_error.113 if an unexpected byte is read
+    @return whether string creation completed
     */
-    std::string get_cbor_string()
+    bool get_cbor_string(string_t& result)
     {
-        check_eof();
+        if (JSON_UNLIKELY(not unexpect_eof()))
+        {
+            return false;
+        }
 
         switch (current)
         {
@@ -5319,74 +6951,137 @@ class binary_reader
             case 0x76:
             case 0x77:
             {
-                return get_string(current & 0x1F);
+                return get_string(current & 0x1F, result);
             }
 
             case 0x78: // UTF-8 string (one-byte uint8_t for n follows)
             {
-                return get_string(get_number<uint8_t>());
+                uint8_t len;
+                return get_number(len) and get_string(len, result);
             }
 
             case 0x79: // UTF-8 string (two-byte uint16_t for n follow)
             {
-                return get_string(get_number<uint16_t>());
+                uint16_t len;
+                return get_number(len) and get_string(len, result);
             }
 
             case 0x7A: // UTF-8 string (four-byte uint32_t for n follow)
             {
-                return get_string(get_number<uint32_t>());
+                uint32_t len;
+                return get_number(len) and get_string(len, result);
             }
 
             case 0x7B: // UTF-8 string (eight-byte uint64_t for n follow)
             {
-                return get_string(get_number<uint64_t>());
+                uint64_t len;
+                return get_number(len) and get_string(len, result);
             }
 
             case 0x7F: // UTF-8 string (indefinite length)
             {
-                std::string result;
                 while (get() != 0xFF)
                 {
-                    check_eof();
-                    result.push_back(static_cast<char>(current));
+                    string_t chunk;
+                    if (not get_cbor_string(chunk))
+                    {
+                        return false;
+                    }
+                    result.append(chunk);
                 }
-                return result;
+                return true;
             }
 
             default:
             {
-                std::stringstream ss;
-                ss << std::setw(2) << std::uppercase << std::setfill('0') << std::hex << current;
-                JSON_THROW(parse_error::create(113, chars_read, "expected a CBOR string; last byte: 0x" + ss.str()));
+                auto last_token = get_token_string();
+                return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, "expected a CBOR string; last byte: 0x" + last_token));
             }
         }
     }
 
-    template<typename NumberType>
-    BasicJsonType get_cbor_array(const NumberType len)
+    /*!
+    @param[in] len  the length of the array or std::size_t(-1) for an
+                    array of indefinite size
+    @return whether array creation completed
+    */
+    bool get_cbor_array(const std::size_t len)
     {
-        BasicJsonType result = value_t::array;
-        std::generate_n(std::back_inserter(*result.m_value.array), len, [this]()
+        if (JSON_UNLIKELY(not sax->start_array(len)))
         {
-            return parse_cbor_internal();
-        });
-        return result;
+            return false;
+        }
+
+        if (len != std::size_t(-1))
+            for (std::size_t i = 0; i < len; ++i)
+            {
+                if (JSON_UNLIKELY(not parse_cbor_internal()))
+                {
+                    return false;
+                }
+            }
+        else
+        {
+            while (get() != 0xFF)
+            {
+                if (JSON_UNLIKELY(not parse_cbor_internal(false)))
+                {
+                    return false;
+                }
+            }
+        }
+
+        return sax->end_array();
     }
 
-    template<typename NumberType>
-    BasicJsonType get_cbor_object(const NumberType len)
+    /*!
+    @param[in] len  the length of the object or std::size_t(-1) for an
+                    object of indefinite size
+    @return whether object creation completed
+    */
+    bool get_cbor_object(const std::size_t len)
     {
-        BasicJsonType result = value_t::object;
-        std::generate_n(std::inserter(*result.m_value.object,
-                                      result.m_value.object->end()),
-                        len, [this]()
+        if (not JSON_UNLIKELY(sax->start_object(len)))
         {
-            get();
-            auto key = get_cbor_string();
-            auto val = parse_cbor_internal();
-            return std::make_pair(std::move(key), std::move(val));
-        });
-        return result;
+            return false;
+        }
+
+        string_t key;
+        if (len != std::size_t(-1))
+        {
+            for (std::size_t i = 0; i < len; ++i)
+            {
+                get();
+                if (JSON_UNLIKELY(not get_cbor_string(key) or not sax->key(key)))
+                {
+                    return false;
+                }
+
+                if (JSON_UNLIKELY(not parse_cbor_internal()))
+                {
+                    return false;
+                }
+                key.clear();
+            }
+        }
+        else
+        {
+            while (get() != 0xFF)
+            {
+                if (JSON_UNLIKELY(not get_cbor_string(key) or not sax->key(key)))
+                {
+                    return false;
+                }
+
+                if (JSON_UNLIKELY(not parse_cbor_internal()))
+                {
+                    return false;
+                }
+                key.clear();
+            }
+        }
+
+        return sax->end_object();
     }
 
     /*!
@@ -5395,14 +7090,16 @@ class binary_reader
     This function first reads starting bytes to determine the expected
     string length and then copies this number of bytes into a string.
 
-    @return string
+    @param[out] result  created string
 
-    @throw parse_error.110 if input ended
-    @throw parse_error.113 if an unexpected byte is read
+    @return whether string creation completed
     */
-    std::string get_msgpack_string()
+    bool get_msgpack_string(string_t& result)
     {
-        check_eof();
+        if (JSON_UNLIKELY(not unexpect_eof()))
+        {
+            return false;
+        }
 
         switch (current)
         {
@@ -5440,83 +7137,523 @@ class binary_reader
             case 0xBE:
             case 0xBF:
             {
-                return get_string(current & 0x1F);
+                return get_string(current & 0x1F, result);
             }
 
             case 0xD9: // str 8
             {
-                return get_string(get_number<uint8_t>());
+                uint8_t len;
+                return get_number(len) and get_string(len, result);
             }
 
             case 0xDA: // str 16
             {
-                return get_string(get_number<uint16_t>());
+                uint16_t len;
+                return get_number(len) and get_string(len, result);
             }
 
             case 0xDB: // str 32
             {
-                return get_string(get_number<uint32_t>());
+                uint32_t len;
+                return get_number(len) and get_string(len, result);
             }
 
             default:
             {
-                std::stringstream ss;
-                ss << std::setw(2) << std::uppercase << std::setfill('0') << std::hex << current;
-                JSON_THROW(parse_error::create(113, chars_read,
-                                               "expected a MessagePack string; last byte: 0x" + ss.str()));
+                auto last_token = get_token_string();
+                return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, "expected a MessagePack string; last byte: 0x" + last_token));
             }
         }
     }
 
-    template<typename NumberType>
-    BasicJsonType get_msgpack_array(const NumberType len)
+    /*!
+    @param[in] len  the length of the array
+    @return whether array creation completed
+    */
+    bool get_msgpack_array(const std::size_t len)
     {
-        BasicJsonType result = value_t::array;
-        std::generate_n(std::back_inserter(*result.m_value.array), len, [this]()
+        if (JSON_UNLIKELY(not sax->start_array(len)))
         {
-            return parse_msgpack_internal();
-        });
-        return result;
+            return false;
+        }
+
+        for (std::size_t i = 0; i < len; ++i)
+        {
+            if (JSON_UNLIKELY(not parse_msgpack_internal()))
+            {
+                return false;
+            }
+        }
+
+        return sax->end_array();
     }
 
-    template<typename NumberType>
-    BasicJsonType get_msgpack_object(const NumberType len)
+    /*!
+    @param[in] len  the length of the object
+    @return whether object creation completed
+    */
+    bool get_msgpack_object(const std::size_t len)
     {
-        BasicJsonType result = value_t::object;
-        std::generate_n(std::inserter(*result.m_value.object,
-                                      result.m_value.object->end()),
-                        len, [this]()
+        if (JSON_UNLIKELY(not sax->start_object(len)))
         {
+            return false;
+        }
+
+        string_t key;
+        for (std::size_t i = 0; i < len; ++i)
+        {
             get();
-            auto key = get_msgpack_string();
-            auto val = parse_msgpack_internal();
-            return std::make_pair(std::move(key), std::move(val));
-        });
-        return result;
+            if (JSON_UNLIKELY(not get_msgpack_string(key) or not sax->key(key)))
+            {
+                return false;
+            }
+
+            if (JSON_UNLIKELY(not parse_msgpack_internal()))
+            {
+                return false;
+            }
+            key.clear();
+        }
+
+        return sax->end_object();
     }
 
     /*!
-    @brief check if input ended
-    @throw parse_error.110 if input ended
+    @brief reads a UBJSON string
+
+    This function is either called after reading the 'S' byte explicitly
+    indicating a string, or in case of an object key where the 'S' byte can be
+    left out.
+
+    @param[out] result   created string
+    @param[in] get_char  whether a new character should be retrieved from the
+                         input (true, default) or whether the last read
+                         character should be considered instead
+
+    @return whether string creation completed
     */
-    void check_eof(const bool expect_eof = false) const
+    bool get_ubjson_string(string_t& result, const bool get_char = true)
     {
-        if (expect_eof)
+        if (get_char)
         {
-            if (JSON_UNLIKELY(current != std::char_traits<char>::eof()))
+            get();  // TODO: may we ignore N here?
+        }
+
+        if (JSON_UNLIKELY(not unexpect_eof()))
+        {
+            return false;
+        }
+
+        switch (current)
+        {
+            case 'U':
             {
-                JSON_THROW(parse_error::create(110, chars_read, "expected end of input"));
+                uint8_t len;
+                return get_number(len) and get_string(len, result);
             }
+
+            case 'i':
+            {
+                int8_t len;
+                return get_number(len) and get_string(len, result);
+            }
+
+            case 'I':
+            {
+                int16_t len;
+                return get_number(len) and get_string(len, result);
+            }
+
+            case 'l':
+            {
+                int32_t len;
+                return get_number(len) and get_string(len, result);
+            }
+
+            case 'L':
+            {
+                int64_t len;
+                return get_number(len) and get_string(len, result);
+            }
+
+            default:
+                auto last_token = get_token_string();
+                return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, "expected a UBJSON string; last byte: 0x" + last_token));
         }
+    }
+
+    /*!
+    @param[out] result  determined size
+    @return whether size determination completed
+    */
+    bool get_ubjson_size_value(std::size_t& result)
+    {
+        switch (get_ignore_noop())
+        {
+            case 'U':
+            {
+                uint8_t number;
+                if (JSON_UNLIKELY(not get_number(number)))
+                {
+                    return false;
+                }
+                result = static_cast<std::size_t>(number);
+                return true;
+            }
+
+            case 'i':
+            {
+                int8_t number;
+                if (JSON_UNLIKELY(not get_number(number)))
+                {
+                    return false;
+                }
+                result = static_cast<std::size_t>(number);
+                return true;
+            }
+
+            case 'I':
+            {
+                int16_t number;
+                if (JSON_UNLIKELY(not get_number(number)))
+                {
+                    return false;
+                }
+                result = static_cast<std::size_t>(number);
+                return true;
+            }
+
+            case 'l':
+            {
+                int32_t number;
+                if (JSON_UNLIKELY(not get_number(number)))
+                {
+                    return false;
+                }
+                result = static_cast<std::size_t>(number);
+                return true;
+            }
+
+            case 'L':
+            {
+                int64_t number;
+                if (JSON_UNLIKELY(not get_number(number)))
+                {
+                    return false;
+                }
+                result = static_cast<std::size_t>(number);
+                return true;
+            }
+
+            default:
+            {
+                auto last_token = get_token_string();
+                return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, "byte after '#' must denote a number type; last byte: 0x" + last_token));
+            }
+        }
+    }
+
+    /*!
+    @brief determine the type and size for a container
+
+    In the optimized UBJSON format, a type and a size can be provided to allow
+    for a more compact representation.
+
+    @param[out] result  pair of the size and the type
+
+    @return whether pair creation completed
+    */
+    bool get_ubjson_size_type(std::pair<std::size_t, int>& result)
+    {
+        result.first = string_t::npos; // size
+        result.second = 0; // type
+
+        get_ignore_noop();
+
+        if (current == '$')
+        {
+            result.second = get();  // must not ignore 'N', because 'N' maybe the type
+            if (JSON_UNLIKELY(not unexpect_eof()))
+            {
+                return false;
+            }
+
+            get_ignore_noop();
+            if (JSON_UNLIKELY(current != '#'))
+            {
+                if (JSON_UNLIKELY(not unexpect_eof()))
+                {
+                    return false;
+                }
+                auto last_token = get_token_string();
+                return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read, "expected '#' after UBJSON type information; last byte: 0x" + last_token));
+            }
+
+            return get_ubjson_size_value(result.first);
+        }
+        else if (current == '#')
+        {
+            return get_ubjson_size_value(result.first);
+        }
+        return true;
+    }
+
+    /*!
+    @param prefix  the previously read or set type prefix
+    @return whether value creation completed
+    */
+    bool get_ubjson_value(const int prefix)
+    {
+        switch (prefix)
+        {
+            case std::char_traits<char>::eof():  // EOF
+                return unexpect_eof();
+
+            case 'T':  // true
+                return sax->boolean(true);
+            case 'F':  // false
+                return sax->boolean(false);
+
+            case 'Z':  // null
+                return sax->null();
+
+            case 'U':
+            {
+                uint8_t number;
+                return get_number(number) and sax->number_unsigned(number);
+            }
+
+            case 'i':
+            {
+                int8_t number;
+                return get_number(number) and sax->number_integer(number);
+            }
+
+            case 'I':
+            {
+                int16_t number;
+                return get_number(number) and sax->number_integer(number);
+            }
+
+            case 'l':
+            {
+                int32_t number;
+                return get_number(number) and sax->number_integer(number);
+            }
+
+            case 'L':
+            {
+                int64_t number;
+                return get_number(number) and sax->number_integer(number);
+            }
+
+            case 'd':
+            {
+                float number;
+                return get_number(number) and sax->number_float(static_cast<number_float_t>(number), "");
+            }
+
+            case 'D':
+            {
+                double number;
+                return get_number(number) and sax->number_float(static_cast<number_float_t>(number), "");
+            }
+
+            case 'C':  // char
+            {
+                get();
+                if (JSON_UNLIKELY(not unexpect_eof()))
+                {
+                    return false;
+                }
+                if (JSON_UNLIKELY(current > 127))
+                {
+                    auto last_token = get_token_string();
+                    return sax->parse_error(chars_read, last_token, parse_error::create(113, chars_read, "byte after 'C' must be in range 0x00..0x7F; last byte: 0x" + last_token));
+                }
+                string_t s(1, static_cast<char>(current));
+                return sax->string(s);
+            }
+
+            case 'S':  // string
+            {
+                string_t s;
+                return get_ubjson_string(s) and sax->string(s);
+            }
+
+            case '[':  // array
+                return get_ubjson_array();
+
+            case '{':  // object
+                return get_ubjson_object();
+
+            default: // anything else
+            {
+                auto last_token = get_token_string();
+                return sax->parse_error(chars_read, last_token, parse_error::create(112, chars_read, "error reading UBJSON; last byte: 0x" + last_token));
+            }
+        }
+    }
+
+    /*!
+    @return whether array creation completed
+    */
+    bool get_ubjson_array()
+    {
+        std::pair<std::size_t, int> size_and_type;
+        if (JSON_UNLIKELY(not get_ubjson_size_type(size_and_type)))
+        {
+            return false;
+        }
+
+        if (size_and_type.first != string_t::npos)
+        {
+            if (JSON_UNLIKELY(not sax->start_array(size_and_type.first)))
+            {
+                return false;
+            }
+
+            if (size_and_type.second != 0)
+            {
+                if (size_and_type.second != 'N')
+                {
+                    for (std::size_t i = 0; i < size_and_type.first; ++i)
+                    {
+                        if (JSON_UNLIKELY(not get_ubjson_value(size_and_type.second)))
+                        {
+                            return false;
+                        }
+                    }
+                }
+            }
+            else
+            {
+                for (std::size_t i = 0; i < size_and_type.first; ++i)
+                {
+                    if (JSON_UNLIKELY(not parse_ubjson_internal()))
+                    {
+                        return false;
+                    }
+                }
+            }
+        }
         else
         {
-            if (JSON_UNLIKELY(current == std::char_traits<char>::eof()))
+            if (JSON_UNLIKELY(not sax->start_array(std::size_t(-1))))
             {
-                JSON_THROW(parse_error::create(110, chars_read, "unexpected end of input"));
+                return false;
             }
+
+            while (current != ']')
+            {
+                if (JSON_UNLIKELY(not parse_ubjson_internal(false)))
+                {
+                    return false;
+                }
+                get_ignore_noop();
+            }
         }
+
+        return sax->end_array();
     }
 
+    /*!
+    @return whether object creation completed
+    */
+    bool get_ubjson_object()
+    {
+        std::pair<std::size_t, int> size_and_type;
+        if (JSON_UNLIKELY(not get_ubjson_size_type(size_and_type)))
+        {
+            return false;
+        }
+
+        string_t key;
+        if (size_and_type.first != string_t::npos)
+        {
+            if (JSON_UNLIKELY(not sax->start_object(size_and_type.first)))
+            {
+                return false;
+            }
+
+            if (size_and_type.second != 0)
+            {
+                for (std::size_t i = 0; i < size_and_type.first; ++i)
+                {
+                    if (JSON_UNLIKELY(not get_ubjson_string(key) or not sax->key(key)))
+                    {
+                        return false;
+                    }
+                    if (JSON_UNLIKELY(not get_ubjson_value(size_and_type.second)))
+                    {
+                        return false;
+                    }
+                    key.clear();
+                }
+            }
+            else
+            {
+                for (std::size_t i = 0; i < size_and_type.first; ++i)
+                {
+                    if (JSON_UNLIKELY(not get_ubjson_string(key) or not sax->key(key)))
+                    {
+                        return false;
+                    }
+                    if (JSON_UNLIKELY(not parse_ubjson_internal()))
+                    {
+                        return false;
+                    }
+                    key.clear();
+                }
+            }
+        }
+        else
+        {
+            if (JSON_UNLIKELY(not sax->start_object(std::size_t(-1))))
+            {
+                return false;
+            }
+
+            while (current != '}')
+            {
+                if (JSON_UNLIKELY(not get_ubjson_string(key, false) or not sax->key(key)))
+                {
+                    return false;
+                }
+                if (JSON_UNLIKELY(not parse_ubjson_internal()))
+                {
+                    return false;
+                }
+                get_ignore_noop();
+                key.clear();
+            }
+        }
+
+        return sax->end_object();
+    }
+
+    /*!
+    @return whether the last read character is not EOF
+    */
+    bool unexpect_eof() const
+    {
+        if (JSON_UNLIKELY(current == std::char_traits<char>::eof()))
+        {
+            return sax->parse_error(chars_read, "<end of file>", parse_error::create(110, chars_read, "unexpected end of input"));
+        }
+        return true;
+    }
+
+    /*!
+    @return a string representation of the last read byte
+    */
+    std::string get_token_string() const
+    {
+        char cr[3];
+        snprintf(cr, 3, "%.2hhX", static_cast<unsigned char>(current));
+        return std::string{cr};
+    }
+
   private:
     /// input adapter
     input_adapter_t ia = nullptr;
@@ -5529,8 +7666,35 @@ class binary_reader
 
     /// whether we can assume little endianess
     const bool is_little_endian = little_endianess();
+
+    /// the SAX parser
+    json_sax_t* sax = nullptr;
 };
+}
+}
 
+// #include <nlohmann/detail/output/binary_writer.hpp>
+
+
+#include <algorithm> // reverse
+#include <array> // array
+#include <cstdint> // uint8_t, uint16_t, uint32_t, uint64_t
+#include <cstring> // memcpy
+#include <limits> // numeric_limits
+
+// #include <nlohmann/detail/input/binary_reader.hpp>
+
+// #include <nlohmann/detail/output/output_adapters.hpp>
+
+
+namespace nlohmann
+{
+namespace detail
+{
+///////////////////
+// binary writer //
+///////////////////
+
 /*!
 @brief serialization to CBOR and MessagePack values
 */
@@ -5663,9 +7827,9 @@ class binary_writer
                 break;
             }
 
-            case value_t::number_float: // Double-Precision Float
+            case value_t::number_float:
             {
-                oa->write_character(static_cast<CharType>(0xFB));
+                oa->write_character(get_cbor_float_prefix(j.m_value.number_float));
                 write_number(j.m_value.number_float);
                 break;
             }
@@ -5678,23 +7842,23 @@ class binary_writer
                 {
                     write_number(static_cast<uint8_t>(0x60 + N));
                 }
-                else if (N <= 0xFF)
+                else if (N <= (std::numeric_limits<uint8_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0x78));
                     write_number(static_cast<uint8_t>(N));
                 }
-                else if (N <= 0xFFFF)
+                else if (N <= (std::numeric_limits<uint16_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0x79));
                     write_number(static_cast<uint16_t>(N));
                 }
-                else if (N <= 0xFFFFFFFF)
+                else if (N <= (std::numeric_limits<uint32_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0x7A));
                     write_number(static_cast<uint32_t>(N));
                 }
                 // LCOV_EXCL_START
-                else if (N <= 0xFFFFFFFFFFFFFFFF)
+                else if (N <= (std::numeric_limits<uint64_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0x7B));
                     write_number(static_cast<uint64_t>(N));
@@ -5716,23 +7880,23 @@ class binary_writer
                 {
                     write_number(static_cast<uint8_t>(0x80 + N));
                 }
-                else if (N <= 0xFF)
+                else if (N <= (std::numeric_limits<uint8_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0x98));
                     write_number(static_cast<uint8_t>(N));
                 }
-                else if (N <= 0xFFFF)
+                else if (N <= (std::numeric_limits<uint16_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0x99));
                     write_number(static_cast<uint16_t>(N));
                 }
-                else if (N <= 0xFFFFFFFF)
+                else if (N <= (std::numeric_limits<uint32_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0x9A));
                     write_number(static_cast<uint32_t>(N));
                 }
                 // LCOV_EXCL_START
-                else if (N <= 0xFFFFFFFFFFFFFFFF)
+                else if (N <= (std::numeric_limits<uint64_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0x9B));
                     write_number(static_cast<uint64_t>(N));
@@ -5755,23 +7919,23 @@ class binary_writer
                 {
                     write_number(static_cast<uint8_t>(0xA0 + N));
                 }
-                else if (N <= 0xFF)
+                else if (N <= (std::numeric_limits<uint8_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0xB8));
                     write_number(static_cast<uint8_t>(N));
                 }
-                else if (N <= 0xFFFF)
+                else if (N <= (std::numeric_limits<uint16_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0xB9));
                     write_number(static_cast<uint16_t>(N));
                 }
-                else if (N <= 0xFFFFFFFF)
+                else if (N <= (std::numeric_limits<uint32_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0xBA));
                     write_number(static_cast<uint32_t>(N));
                 }
                 // LCOV_EXCL_START
-                else if (N <= 0xFFFFFFFFFFFFFFFF)
+                else if (N <= (std::numeric_limits<uint64_t>::max)())
                 {
                     oa->write_character(static_cast<CharType>(0xBB));
                     write_number(static_cast<uint64_t>(N));
@@ -5923,9 +8087,9 @@ class binary_writer
                 break;
             }
 
-            case value_t::number_float: // float 64
+            case value_t::number_float:
             {
-                oa->write_character(static_cast<CharType>(0xCB));
+                oa->write_character(get_msgpack_float_prefix(j.m_value.number_float));
                 write_number(j.m_value.number_float);
                 break;
             }
@@ -5939,19 +8103,19 @@ class binary_writer
                     // fixstr
                     write_number(static_cast<uint8_t>(0xA0 | N));
                 }
-                else if (N <= 255)
+                else if (N <= (std::numeric_limits<uint8_t>::max)())
                 {
                     // str 8
                     oa->write_character(static_cast<CharType>(0xD9));
                     write_number(static_cast<uint8_t>(N));
                 }
-                else if (N <= 65535)
+                else if (N <= (std::numeric_limits<uint16_t>::max)())
                 {
                     // str 16
                     oa->write_character(static_cast<CharType>(0xDA));
                     write_number(static_cast<uint16_t>(N));
                 }
-                else if (N <= 4294967295)
+                else if (N <= (std::numeric_limits<uint32_t>::max)())
                 {
                     // str 32
                     oa->write_character(static_cast<CharType>(0xDB));
@@ -5974,13 +8138,13 @@ class binary_writer
                     // fixarray
                     write_number(static_cast<uint8_t>(0x90 | N));
                 }
-                else if (N <= 0xFFFF)
+                else if (N <= (std::numeric_limits<uint16_t>::max)())
                 {
                     // array 16
                     oa->write_character(static_cast<CharType>(0xDC));
                     write_number(static_cast<uint16_t>(N));
                 }
-                else if (N <= 0xFFFFFFFF)
+                else if (N <= (std::numeric_limits<uint32_t>::max)())
                 {
                     // array 32
                     oa->write_character(static_cast<CharType>(0xDD));
@@ -6004,13 +8168,13 @@ class binary_writer
                     // fixmap
                     write_number(static_cast<uint8_t>(0x80 | (N & 0xF)));
                 }
-                else if (N <= 65535)
+                else if (N <= (std::numeric_limits<uint16_t>::max)())
                 {
                     // map 16
                     oa->write_character(static_cast<CharType>(0xDE));
                     write_number(static_cast<uint16_t>(N));
                 }
-                else if (N <= 4294967295)
+                else if (N <= (std::numeric_limits<uint32_t>::max)())
                 {
                     // map 32
                     oa->write_character(static_cast<CharType>(0xDF));
@@ -6031,6 +8195,165 @@ class binary_writer
         }
     }
 
+    /*!
+    @param[in] j  JSON value to serialize
+    @param[in] use_count   whether to use '#' prefixes (optimized format)
+    @param[in] use_type    whether to use '$' prefixes (optimized format)
+    @param[in] add_prefix  whether prefixes need to be used for this value
+    */
+    void write_ubjson(const BasicJsonType& j, const bool use_count,
+                      const bool use_type, const bool add_prefix = true)
+    {
+        switch (j.type())
+        {
+            case value_t::null:
+            {
+                if (add_prefix)
+                {
+                    oa->write_character(static_cast<CharType>('Z'));
+                }
+                break;
+            }
+
+            case value_t::boolean:
+            {
+                if (add_prefix)
+                    oa->write_character(j.m_value.boolean
+                                        ? static_cast<CharType>('T')
+                                        : static_cast<CharType>('F'));
+                break;
+            }
+
+            case value_t::number_integer:
+            {
+                write_number_with_ubjson_prefix(j.m_value.number_integer, add_prefix);
+                break;
+            }
+
+            case value_t::number_unsigned:
+            {
+                write_number_with_ubjson_prefix(j.m_value.number_unsigned, add_prefix);
+                break;
+            }
+
+            case value_t::number_float:
+            {
+                write_number_with_ubjson_prefix(j.m_value.number_float, add_prefix);
+                break;
+            }
+
+            case value_t::string:
+            {
+                if (add_prefix)
+                {
+                    oa->write_character(static_cast<CharType>('S'));
+                }
+                write_number_with_ubjson_prefix(j.m_value.string->size(), true);
+                oa->write_characters(
+                    reinterpret_cast<const CharType*>(j.m_value.string->c_str()),
+                    j.m_value.string->size());
+                break;
+            }
+
+            case value_t::array:
+            {
+                if (add_prefix)
+                {
+                    oa->write_character(static_cast<CharType>('['));
+                }
+
+                bool prefix_required = true;
+                if (use_type and not j.m_value.array->empty())
+                {
+                    assert(use_count);
+                    const CharType first_prefix = ubjson_prefix(j.front());
+                    const bool same_prefix = std::all_of(j.begin() + 1, j.end(),
+                                                         [this, first_prefix](const BasicJsonType & v)
+                    {
+                        return ubjson_prefix(v) == first_prefix;
+                    });
+
+                    if (same_prefix)
+                    {
+                        prefix_required = false;
+                        oa->write_character(static_cast<CharType>('$'));
+                        oa->write_character(first_prefix);
+                    }
+                }
+
+                if (use_count)
+                {
+                    oa->write_character(static_cast<CharType>('#'));
+                    write_number_with_ubjson_prefix(j.m_value.array->size(), true);
+                }
+
+                for (const auto& el : *j.m_value.array)
+                {
+                    write_ubjson(el, use_count, use_type, prefix_required);
+                }
+
+                if (not use_count)
+                {
+                    oa->write_character(static_cast<CharType>(']'));
+                }
+
+                break;
+            }
+
+            case value_t::object:
+            {
+                if (add_prefix)
+                {
+                    oa->write_character(static_cast<CharType>('{'));
+                }
+
+                bool prefix_required = true;
+                if (use_type and not j.m_value.object->empty())
+                {
+                    assert(use_count);
+                    const CharType first_prefix = ubjson_prefix(j.front());
+                    const bool same_prefix = std::all_of(j.begin(), j.end(),
+                                                         [this, first_prefix](const BasicJsonType & v)
+                    {
+                        return ubjson_prefix(v) == first_prefix;
+                    });
+
+                    if (same_prefix)
+                    {
+                        prefix_required = false;
+                        oa->write_character(static_cast<CharType>('$'));
+                        oa->write_character(first_prefix);
+                    }
+                }
+
+                if (use_count)
+                {
+                    oa->write_character(static_cast<CharType>('#'));
+                    write_number_with_ubjson_prefix(j.m_value.object->size(), true);
+                }
+
+                for (const auto& el : *j.m_value.object)
+                {
+                    write_number_with_ubjson_prefix(el.first.size(), true);
+                    oa->write_characters(
+                        reinterpret_cast<const CharType*>(el.first.c_str()),
+                        el.first.size());
+                    write_ubjson(el.second, use_count, use_type, prefix_required);
+                }
+
+                if (not use_count)
+                {
+                    oa->write_character(static_cast<CharType>('}'));
+                }
+
+                break;
+            }
+
+            default:
+                break;
+        }
+    }
+
   private:
     /*
     @brief write a number to output input
@@ -6039,10 +8362,11 @@ class binary_writer
     @tparam NumberType the type of the number
 
     @note This function needs to respect the system's endianess, because bytes
-          in CBOR and MessagePack are stored in network order (big endian) and
-          therefore need reordering on little endian systems.
+          in CBOR, MessagePack, and UBJSON are stored in network order (big
+          endian) and therefore need reordering on little endian systems.
     */
-    template<typename NumberType> void write_number(NumberType n)
+    template<typename NumberType>
+    void write_number(const NumberType n)
     {
         // step 1: write number to array of length NumberType
         std::array<CharType, sizeof(NumberType)> vec;
@@ -6058,6 +8382,240 @@ class binary_writer
         oa->write_characters(vec.data(), sizeof(NumberType));
     }
 
+    // UBJSON: write number (floating point)
+    template<typename NumberType, typename std::enable_if<
+                 std::is_floating_point<NumberType>::value, int>::type = 0>
+    void write_number_with_ubjson_prefix(const NumberType n,
+                                         const bool add_prefix)
+    {
+        if (add_prefix)
+        {
+            oa->write_character(get_ubjson_float_prefix(n));
+        }
+        write_number(n);
+    }
+
+    // UBJSON: write number (unsigned integer)
+    template<typename NumberType, typename std::enable_if<
+                 std::is_unsigned<NumberType>::value, int>::type = 0>
+    void write_number_with_ubjson_prefix(const NumberType n,
+                                         const bool add_prefix)
+    {
+        if (n <= static_cast<uint64_t>((std::numeric_limits<int8_t>::max)()))
+        {
+            if (add_prefix)
+            {
+                oa->write_character(static_cast<CharType>('i'));  // int8
+            }
+            write_number(static_cast<uint8_t>(n));
+        }
+        else if (n <= (std::numeric_limits<uint8_t>::max)())
+        {
+            if (add_prefix)
+            {
+                oa->write_character(static_cast<CharType>('U'));  // uint8
+            }
+            write_number(static_cast<uint8_t>(n));
+        }
+        else if (n <= static_cast<uint64_t>((std::numeric_limits<int16_t>::max)()))
+        {
+            if (add_prefix)
+            {
+                oa->write_character(static_cast<CharType>('I'));  // int16
+            }
+            write_number(static_cast<int16_t>(n));
+        }
+        else if (n <= static_cast<uint64_t>((std::numeric_limits<int32_t>::max)()))
+        {
+            if (add_prefix)
+            {
+                oa->write_character(static_cast<CharType>('l'));  // int32
+            }
+            write_number(static_cast<int32_t>(n));
+        }
+        else if (n <= static_cast<uint64_t>((std::numeric_limits<int64_t>::max)()))
+        {
+            if (add_prefix)
+            {
+                oa->write_character(static_cast<CharType>('L'));  // int64
+            }
+            write_number(static_cast<int64_t>(n));
+        }
+        else
+        {
+            JSON_THROW(out_of_range::create(407, "number overflow serializing " + std::to_string(n)));
+        }
+    }
+
+    // UBJSON: write number (signed integer)
+    template<typename NumberType, typename std::enable_if<
+                 std::is_signed<NumberType>::value and
+                 not std::is_floating_point<NumberType>::value, int>::type = 0>
+    void write_number_with_ubjson_prefix(const NumberType n,
+                                         const bool add_prefix)
+    {
+        if ((std::numeric_limits<int8_t>::min)() <= n and n <= (std::numeric_limits<int8_t>::max)())
+        {
+            if (add_prefix)
+            {
+                oa->write_character(static_cast<CharType>('i'));  // int8
+            }
+            write_number(static_cast<int8_t>(n));
+        }
+        else if (static_cast<int64_t>((std::numeric_limits<uint8_t>::min)()) <= n and n <= static_cast<int64_t>((std::numeric_limits<uint8_t>::max)()))
+        {
+            if (add_prefix)
+            {
+                oa->write_character(static_cast<CharType>('U'));  // uint8
+            }
+            write_number(static_cast<uint8_t>(n));
+        }
+        else if ((std::numeric_limits<int16_t>::min)() <= n and n <= (std::numeric_limits<int16_t>::max)())
+        {
+            if (add_prefix)
+            {
+                oa->write_character(static_cast<CharType>('I'));  // int16
+            }
+            write_number(static_cast<int16_t>(n));
+        }
+        else if ((std::numeric_limits<int32_t>::min)() <= n and n <= (std::numeric_limits<int32_t>::max)())
+        {
+            if (add_prefix)
+            {
+                oa->write_character(static_cast<CharType>('l'));  // int32
+            }
+            write_number(static_cast<int32_t>(n));
+        }
+        else if ((std::numeric_limits<int64_t>::min)() <= n and n <= (std::numeric_limits<int64_t>::max)())
+        {
+            if (add_prefix)
+            {
+                oa->write_character(static_cast<CharType>('L'));  // int64
+            }
+            write_number(static_cast<int64_t>(n));
+        }
+        // LCOV_EXCL_START
+        else
+        {
+            JSON_THROW(out_of_range::create(407, "number overflow serializing " + std::to_string(n)));
+        }
+        // LCOV_EXCL_STOP
+    }
+
+    /*!
+    @brief determine the type prefix of container values
+
+    @note This function does not need to be 100% accurate when it comes to
+          integer limits. In case a number exceeds the limits of int64_t,
+          this will be detected by a later call to function
+          write_number_with_ubjson_prefix. Therefore, we return 'L' for any
+          value that does not fit the previous limits.
+    */
+    CharType ubjson_prefix(const BasicJsonType& j) const noexcept
+    {
+        switch (j.type())
+        {
+            case value_t::null:
+                return 'Z';
+
+            case value_t::boolean:
+                return j.m_value.boolean ? 'T' : 'F';
+
+            case value_t::number_integer:
+            {
+                if ((std::numeric_limits<int8_t>::min)() <= j.m_value.number_integer and j.m_value.number_integer <= (std::numeric_limits<int8_t>::max)())
+                {
+                    return 'i';
+                }
+                else if ((std::numeric_limits<uint8_t>::min)() <= j.m_value.number_integer and j.m_value.number_integer <= (std::numeric_limits<uint8_t>::max)())
+                {
+                    return 'U';
+                }
+                else if ((std::numeric_limits<int16_t>::min)() <= j.m_value.number_integer and j.m_value.number_integer <= (std::numeric_limits<int16_t>::max)())
+                {
+                    return 'I';
+                }
+                else if ((std::numeric_limits<int32_t>::min)() <= j.m_value.number_integer and j.m_value.number_integer <= (std::numeric_limits<int32_t>::max)())
+                {
+                    return 'l';
+                }
+                else  // no check and assume int64_t (see note above)
+                {
+                    return 'L';
+                }
+            }
+
+            case value_t::number_unsigned:
+            {
+                if (j.m_value.number_unsigned <= (std::numeric_limits<int8_t>::max)())
+                {
+                    return 'i';
+                }
+                else if (j.m_value.number_unsigned <= (std::numeric_limits<uint8_t>::max)())
+                {
+                    return 'U';
+                }
+                else if (j.m_value.number_unsigned <= (std::numeric_limits<int16_t>::max)())
+                {
+                    return 'I';
+                }
+                else if (j.m_value.number_unsigned <= (std::numeric_limits<int32_t>::max)())
+                {
+                    return 'l';
+                }
+                else  // no check and assume int64_t (see note above)
+                {
+                    return 'L';
+                }
+            }
+
+            case value_t::number_float:
+                return get_ubjson_float_prefix(j.m_value.number_float);
+
+            case value_t::string:
+                return 'S';
+
+            case value_t::array:
+                return '[';
+
+            case value_t::object:
+                return '{';
+
+            default:  // discarded values
+                return 'N';
+        }
+    }
+
+    static constexpr CharType get_cbor_float_prefix(float)
+    {
+        return static_cast<CharType>(0xFA);  // Single-Precision Float
+    }
+
+    static constexpr CharType get_cbor_float_prefix(double)
+    {
+        return static_cast<CharType>(0xFB);  // Double-Precision Float
+    }
+
+    static constexpr CharType get_msgpack_float_prefix(float)
+    {
+        return static_cast<CharType>(0xCA);  // float 32
+    }
+
+    static constexpr CharType get_msgpack_float_prefix(double)
+    {
+        return static_cast<CharType>(0xCB);  // float 64
+    }
+
+    static constexpr CharType get_ubjson_float_prefix(float)
+    {
+        return 'd';  // float 32
+    }
+
+    static constexpr CharType get_ubjson_float_prefix(double)
+    {
+        return 'D';  // float 64
+    }
+
   private:
     /// whether we can assume little endianess
     const bool is_little_endian = binary_reader<BasicJsonType>::little_endianess();
@@ -6065,7 +8623,1137 @@ class binary_writer
     /// the output
     output_adapter_t<CharType> oa = nullptr;
 };
+}
+}
 
+// #include <nlohmann/detail/output/serializer.hpp>
+
+
+#include <algorithm> // reverse, remove, fill, find, none_of
+#include <array> // array
+#include <cassert> // assert
+#include <ciso646> // and, or
+#include <clocale> // localeconv, lconv
+#include <cmath> // labs, isfinite, isnan, signbit
+#include <cstddef> // size_t, ptrdiff_t
+#include <cstdint> // uint8_t
+#include <cstdio> // snprintf
+#include <limits> // numeric_limits
+#include <string> // string
+#include <type_traits> // is_same
+
+// #include <nlohmann/detail/exceptions.hpp>
+
+// #include <nlohmann/detail/conversions/to_chars.hpp>
+
+
+#include <cassert> // assert
+#include <ciso646> // or, and, not
+#include <cmath>   // signbit, isfinite
+#include <cstdint> // intN_t, uintN_t
+#include <cstring> // memcpy, memmove
+
+namespace nlohmann
+{
+namespace detail
+{
+
+/*!
+@brief implements the Grisu2 algorithm for binary to decimal floating-point
+conversion.
+
+This implementation is a slightly modified version of the reference
+implementation which may be obtained from
+http://florian.loitsch.com/publications (bench.tar.gz).
+
+The code is distributed under the MIT license, Copyright (c) 2009 Florian Loitsch.
+
+For a detailed description of the algorithm see:
+
+[1] Loitsch, "Printing Floating-Point Numbers Quickly and Accurately with
+    Integers", Proceedings of the ACM SIGPLAN 2010 Conference on Programming
+    Language Design and Implementation, PLDI 2010
+[2] Burger, Dybvig, "Printing Floating-Point Numbers Quickly and Accurately",
+    Proceedings of the ACM SIGPLAN 1996 Conference on Programming Language
+    Design and Implementation, PLDI 1996
+*/
+namespace dtoa_impl
+{
+
+template <typename Target, typename Source>
+Target reinterpret_bits(const Source source)
+{
+    static_assert(sizeof(Target) == sizeof(Source), "size mismatch");
+
+    Target target;
+    std::memcpy(&target, &source, sizeof(Source));
+    return target;
+}
+
+struct diyfp // f * 2^e
+{
+    static constexpr int kPrecision = 64; // = q
+
+    uint64_t f;
+    int e;
+
+    constexpr diyfp() noexcept : f(0), e(0) {}
+    constexpr diyfp(uint64_t f_, int e_) noexcept : f(f_), e(e_) {}
+
+    /*!
+    @brief returns x - y
+    @pre x.e == y.e and x.f >= y.f
+    */
+    static diyfp sub(const diyfp& x, const diyfp& y) noexcept
+    {
+        assert(x.e == y.e);
+        assert(x.f >= y.f);
+
+        return diyfp(x.f - y.f, x.e);
+    }
+
+    /*!
+    @brief returns x * y
+    @note The result is rounded. (Only the upper q bits are returned.)
+    */
+    static diyfp mul(const diyfp& x, const diyfp& y) noexcept
+    {
+        static_assert(kPrecision == 64, "internal error");
+
+        // Computes:
+        //  f = round((x.f * y.f) / 2^q)
+        //  e = x.e + y.e + q
+
+        // Emulate the 64-bit * 64-bit multiplication:
+        //
+        // p = u * v
+        //   = (u_lo + 2^32 u_hi) (v_lo + 2^32 v_hi)
+        //   = (u_lo v_lo         ) + 2^32 ((u_lo v_hi         ) + (u_hi v_lo         )) + 2^64 (u_hi v_hi         )
+        //   = (p0                ) + 2^32 ((p1                ) + (p2                )) + 2^64 (p3                )
+        //   = (p0_lo + 2^32 p0_hi) + 2^32 ((p1_lo + 2^32 p1_hi) + (p2_lo + 2^32 p2_hi)) + 2^64 (p3                )
+        //   = (p0_lo             ) + 2^32 (p0_hi + p1_lo + p2_lo                      ) + 2^64 (p1_hi + p2_hi + p3)
+        //   = (p0_lo             ) + 2^32 (Q                                          ) + 2^64 (H                 )
+        //   = (p0_lo             ) + 2^32 (Q_lo + 2^32 Q_hi                           ) + 2^64 (H                 )
+        //
+        // (Since Q might be larger than 2^32 - 1)
+        //
+        //   = (p0_lo + 2^32 Q_lo) + 2^64 (Q_hi + H)
+        //
+        // (Q_hi + H does not overflow a 64-bit int)
+        //
+        //   = p_lo + 2^64 p_hi
+
+        const uint64_t u_lo = x.f & 0xFFFFFFFF;
+        const uint64_t u_hi = x.f >> 32;
+        const uint64_t v_lo = y.f & 0xFFFFFFFF;
+        const uint64_t v_hi = y.f >> 32;
+
+        const uint64_t p0 = u_lo * v_lo;
+        const uint64_t p1 = u_lo * v_hi;
+        const uint64_t p2 = u_hi * v_lo;
+        const uint64_t p3 = u_hi * v_hi;
+
+        const uint64_t p0_hi = p0 >> 32;
+        const uint64_t p1_lo = p1 & 0xFFFFFFFF;
+        const uint64_t p1_hi = p1 >> 32;
+        const uint64_t p2_lo = p2 & 0xFFFFFFFF;
+        const uint64_t p2_hi = p2 >> 32;
+
+        uint64_t Q = p0_hi + p1_lo + p2_lo;
+
+        // The full product might now be computed as
+        //
+        // p_hi = p3 + p2_hi + p1_hi + (Q >> 32)
+        // p_lo = p0_lo + (Q << 32)
+        //
+        // But in this particular case here, the full p_lo is not required.
+        // Effectively we only need to add the highest bit in p_lo to p_hi (and
+        // Q_hi + 1 does not overflow).
+
+        Q += uint64_t{1} << (64 - 32 - 1); // round, ties up
+
+        const uint64_t h = p3 + p2_hi + p1_hi + (Q >> 32);
+
+        return diyfp(h, x.e + y.e + 64);
+    }
+
+    /*!
+    @brief normalize x such that the significand is >= 2^(q-1)
+    @pre x.f != 0
+    */
+    static diyfp normalize(diyfp x) noexcept
+    {
+        assert(x.f != 0);
+
+        while ((x.f >> 63) == 0)
+        {
+            x.f <<= 1;
+            x.e--;
+        }
+
+        return x;
+    }
+
+    /*!
+    @brief normalize x such that the result has the exponent E
+    @pre e >= x.e and the upper e - x.e bits of x.f must be zero.
+    */
+    static diyfp normalize_to(const diyfp& x, const int target_exponent) noexcept
+    {
+        const int delta = x.e - target_exponent;
+
+        assert(delta >= 0);
+        assert(((x.f << delta) >> delta) == x.f);
+
+        return diyfp(x.f << delta, target_exponent);
+    }
+};
+
+struct boundaries
+{
+    diyfp w;
+    diyfp minus;
+    diyfp plus;
+};
+
+/*!
+Compute the (normalized) diyfp representing the input number 'value' and its
+boundaries.
+
+@pre value must be finite and positive
+*/
+template <typename FloatType>
+boundaries compute_boundaries(FloatType value)
+{
+    assert(std::isfinite(value));
+    assert(value > 0);
+
+    // Convert the IEEE representation into a diyfp.
+    //
+    // If v is denormal:
+    //      value = 0.F * 2^(1 - bias) = (          F) * 2^(1 - bias - (p-1))
+    // If v is normalized:
+    //      value = 1.F * 2^(E - bias) = (2^(p-1) + F) * 2^(E - bias - (p-1))
+
+    static_assert(std::numeric_limits<FloatType>::is_iec559,
+                  "internal error: dtoa_short requires an IEEE-754 floating-point implementation");
+
+    constexpr int      kPrecision = std::numeric_limits<FloatType>::digits; // = p (includes the hidden bit)
+    constexpr int      kBias      = std::numeric_limits<FloatType>::max_exponent - 1 + (kPrecision - 1);
+    constexpr int      kMinExp    = 1 - kBias;
+    constexpr uint64_t kHiddenBit = uint64_t{1} << (kPrecision - 1); // = 2^(p-1)
+
+    using bits_type = typename std::conditional< kPrecision == 24, uint32_t, uint64_t >::type;
+
+    const uint64_t bits = reinterpret_bits<bits_type>(value);
+    const uint64_t E = bits >> (kPrecision - 1);
+    const uint64_t F = bits & (kHiddenBit - 1);
+
+    const bool is_denormal = (E == 0);
+    const diyfp v = is_denormal
+                    ? diyfp(F, kMinExp)
+                    : diyfp(F + kHiddenBit, static_cast<int>(E) - kBias);
+
+    // Compute the boundaries m- and m+ of the floating-point value
+    // v = f * 2^e.
+    //
+    // Determine v- and v+, the floating-point predecessor and successor if v,
+    // respectively.
+    //
+    //      v- = v - 2^e        if f != 2^(p-1) or e == e_min                (A)
+    //         = v - 2^(e-1)    if f == 2^(p-1) and e > e_min                (B)
+    //
+    //      v+ = v + 2^e
+    //
+    // Let m- = (v- + v) / 2 and m+ = (v + v+) / 2. All real numbers _strictly_
+    // between m- and m+ round to v, regardless of how the input rounding
+    // algorithm breaks ties.
+    //
+    //      ---+-------------+-------------+-------------+-------------+---  (A)
+    //         v-            m-            v             m+            v+
+    //
+    //      -----------------+------+------+-------------+-------------+---  (B)
+    //                       v-     m-     v             m+            v+
+
+    const bool lower_boundary_is_closer = (F == 0 and E > 1);
+    const diyfp m_plus = diyfp(2 * v.f + 1, v.e - 1);
+    const diyfp m_minus = lower_boundary_is_closer
+                          ? diyfp(4 * v.f - 1, v.e - 2)  // (B)
+                          : diyfp(2 * v.f - 1, v.e - 1); // (A)
+
+    // Determine the normalized w+ = m+.
+    const diyfp w_plus = diyfp::normalize(m_plus);
+
+    // Determine w- = m- such that e_(w-) = e_(w+).
+    const diyfp w_minus = diyfp::normalize_to(m_minus, w_plus.e);
+
+    return {diyfp::normalize(v), w_minus, w_plus};
+}
+
+// Given normalized diyfp w, Grisu needs to find a (normalized) cached
+// power-of-ten c, such that the exponent of the product c * w = f * 2^e lies
+// within a certain range [alpha, gamma] (Definition 3.2 from [1])
+//
+//      alpha <= e = e_c + e_w + q <= gamma
+//
+// or
+//
+//      f_c * f_w * 2^alpha <= f_c 2^(e_c) * f_w 2^(e_w) * 2^q
+//                          <= f_c * f_w * 2^gamma
+//
+// Since c and w are normalized, i.e. 2^(q-1) <= f < 2^q, this implies
+//
+//      2^(q-1) * 2^(q-1) * 2^alpha <= c * w * 2^q < 2^q * 2^q * 2^gamma
+//
+// or
+//
+//      2^(q - 2 + alpha) <= c * w < 2^(q + gamma)
+//
+// The choice of (alpha,gamma) determines the size of the table and the form of
+// the digit generation procedure. Using (alpha,gamma)=(-60,-32) works out well
+// in practice:
+//
+// The idea is to cut the number c * w = f * 2^e into two parts, which can be
+// processed independently: An integral part p1, and a fractional part p2:
+//
+//      f * 2^e = ( (f div 2^-e) * 2^-e + (f mod 2^-e) ) * 2^e
+//              = (f div 2^-e) + (f mod 2^-e) * 2^e
+//              = p1 + p2 * 2^e
+//
+// The conversion of p1 into decimal form requires a series of divisions and
+// modulos by (a power of) 10. These operations are faster for 32-bit than for
+// 64-bit integers, so p1 should ideally fit into a 32-bit integer. This can be
+// achieved by choosing
+//
+//      -e >= 32   or   e <= -32 := gamma
+//
+// In order to convert the fractional part
+//
+//      p2 * 2^e = p2 / 2^-e = d[-1] / 10^1 + d[-2] / 10^2 + ...
+//
+// into decimal form, the fraction is repeatedly multiplied by 10 and the digits
+// d[-i] are extracted in order:
+//
+//      (10 * p2) div 2^-e = d[-1]
+//      (10 * p2) mod 2^-e = d[-2] / 10^1 + ...
+//
+// The multiplication by 10 must not overflow. It is sufficient to choose
+//
+//      10 * p2 < 16 * p2 = 2^4 * p2 <= 2^64.
+//
+// Since p2 = f mod 2^-e < 2^-e,
+//
+//      -e <= 60   or   e >= -60 := alpha
+
+constexpr int kAlpha = -60;
+constexpr int kGamma = -32;
+
+struct cached_power // c = f * 2^e ~= 10^k
+{
+    uint64_t f;
+    int e;
+    int k;
+};
+
+/*!
+For a normalized diyfp w = f * 2^e, this function returns a (normalized) cached
+power-of-ten c = f_c * 2^e_c, such that the exponent of the product w * c
+satisfies (Definition 3.2 from [1])
+
+     alpha <= e_c + e + q <= gamma.
+*/
+inline cached_power get_cached_power_for_binary_exponent(int e)
+{
+    // Now
+    //
+    //      alpha <= e_c + e + q <= gamma                                    (1)
+    //      ==> f_c * 2^alpha <= c * 2^e * 2^q
+    //
+    // and since the c's are normalized, 2^(q-1) <= f_c,
+    //
+    //      ==> 2^(q - 1 + alpha) <= c * 2^(e + q)
+    //      ==> 2^(alpha - e - 1) <= c
+    //
+    // If c were an exakt power of ten, i.e. c = 10^k, one may determine k as
+    //
+    //      k = ceil( log_10( 2^(alpha - e - 1) ) )
+    //        = ceil( (alpha - e - 1) * log_10(2) )
+    //
+    // From the paper:
+    // "In theory the result of the procedure could be wrong since c is rounded,
+    //  and the computation itself is approximated [...]. In practice, however,
+    //  this simple function is sufficient."
+    //
+    // For IEEE double precision floating-point numbers converted into
+    // normalized diyfp's w = f * 2^e, with q = 64,
+    //
+    //      e >= -1022      (min IEEE exponent)
+    //           -52        (p - 1)
+    //           -52        (p - 1, possibly normalize denormal IEEE numbers)
+    //           -11        (normalize the diyfp)
+    //         = -1137
+    //
+    // and
+    //
+    //      e <= +1023      (max IEEE exponent)
+    //           -52        (p - 1)
+    //           -11        (normalize the diyfp)
+    //         = 960
+    //
+    // This binary exponent range [-1137,960] results in a decimal exponent
+    // range [-307,324]. One does not need to store a cached power for each
+    // k in this range. For each such k it suffices to find a cached power
+    // such that the exponent of the product lies in [alpha,gamma].
+    // This implies that the difference of the decimal exponents of adjacent
+    // table entries must be less than or equal to
+    //
+    //      floor( (gamma - alpha) * log_10(2) ) = 8.
+    //
+    // (A smaller distance gamma-alpha would require a larger table.)
+
+    // NB:
+    // Actually this function returns c, such that -60 <= e_c + e + 64 <= -34.
+
+    constexpr int kCachedPowersSize = 79;
+    constexpr int kCachedPowersMinDecExp = -300;
+    constexpr int kCachedPowersDecStep = 8;
+
+    static constexpr cached_power kCachedPowers[] =
+    {
+        { 0xAB70FE17C79AC6CA, -1060, -300 },
+        { 0xFF77B1FCBEBCDC4F, -1034, -292 },
+        { 0xBE5691EF416BD60C, -1007, -284 },
+        { 0x8DD01FAD907FFC3C,  -980, -276 },
+        { 0xD3515C2831559A83,  -954, -268 },
+        { 0x9D71AC8FADA6C9B5,  -927, -260 },
+        { 0xEA9C227723EE8BCB,  -901, -252 },
+        { 0xAECC49914078536D,  -874, -244 },
+        { 0x823C12795DB6CE57,  -847, -236 },
+        { 0xC21094364DFB5637,  -821, -228 },
+        { 0x9096EA6F3848984F,  -794, -220 },
+        { 0xD77485CB25823AC7,  -768, -212 },
+        { 0xA086CFCD97BF97F4,  -741, -204 },
+        { 0xEF340A98172AACE5,  -715, -196 },
+        { 0xB23867FB2A35B28E,  -688, -188 },
+        { 0x84C8D4DFD2C63F3B,  -661, -180 },
+        { 0xC5DD44271AD3CDBA,  -635, -172 },
+        { 0x936B9FCEBB25C996,  -608, -164 },
+        { 0xDBAC6C247D62A584,  -582, -156 },
+        { 0xA3AB66580D5FDAF6,  -555, -148 },
+        { 0xF3E2F893DEC3F126,  -529, -140 },
+        { 0xB5B5ADA8AAFF80B8,  -502, -132 },
+        { 0x87625F056C7C4A8B,  -475, -124 },
+        { 0xC9BCFF6034C13053,  -449, -116 },
+        { 0x964E858C91BA2655,  -422, -108 },
+        { 0xDFF9772470297EBD,  -396, -100 },
+        { 0xA6DFBD9FB8E5B88F,  -369,  -92 },
+        { 0xF8A95FCF88747D94,  -343,  -84 },
+        { 0xB94470938FA89BCF,  -316,  -76 },
+        { 0x8A08F0F8BF0F156B,  -289,  -68 },
+        { 0xCDB02555653131B6,  -263,  -60 },
+        { 0x993FE2C6D07B7FAC,  -236,  -52 },
+        { 0xE45C10C42A2B3B06,  -210,  -44 },
+        { 0xAA242499697392D3,  -183,  -36 },
+        { 0xFD87B5F28300CA0E,  -157,  -28 },
+        { 0xBCE5086492111AEB,  -130,  -20 },
+        { 0x8CBCCC096F5088CC,  -103,  -12 },
+        { 0xD1B71758E219652C,   -77,   -4 },
+        { 0x9C40000000000000,   -50,    4 },
+        { 0xE8D4A51000000000,   -24,   12 },
+        { 0xAD78EBC5AC620000,     3,   20 },
+        { 0x813F3978F8940984,    30,   28 },
+        { 0xC097CE7BC90715B3,    56,   36 },
+        { 0x8F7E32CE7BEA5C70,    83,   44 },
+        { 0xD5D238A4ABE98068,   109,   52 },
+        { 0x9F4F2726179A2245,   136,   60 },
+        { 0xED63A231D4C4FB27,   162,   68 },
+        { 0xB0DE65388CC8ADA8,   189,   76 },
+        { 0x83C7088E1AAB65DB,   216,   84 },
+        { 0xC45D1DF942711D9A,   242,   92 },
+        { 0x924D692CA61BE758,   269,  100 },
+        { 0xDA01EE641A708DEA,   295,  108 },
+        { 0xA26DA3999AEF774A,   322,  116 },
+        { 0xF209787BB47D6B85,   348,  124 },
+        { 0xB454E4A179DD1877,   375,  132 },
+        { 0x865B86925B9BC5C2,   402,  140 },
+        { 0xC83553C5C8965D3D,   428,  148 },
+        { 0x952AB45CFA97A0B3,   455,  156 },
+        { 0xDE469FBD99A05FE3,   481,  164 },
+        { 0xA59BC234DB398C25,   508,  172 },
+        { 0xF6C69A72A3989F5C,   534,  180 },
+        { 0xB7DCBF5354E9BECE,   561,  188 },
+        { 0x88FCF317F22241E2,   588,  196 },
+        { 0xCC20CE9BD35C78A5,   614,  204 },
+        { 0x98165AF37B2153DF,   641,  212 },
+        { 0xE2A0B5DC971F303A,   667,  220 },
+        { 0xA8D9D1535CE3B396,   694,  228 },
+        { 0xFB9B7CD9A4A7443C,   720,  236 },
+        { 0xBB764C4CA7A44410,   747,  244 },
+        { 0x8BAB8EEFB6409C1A,   774,  252 },
+        { 0xD01FEF10A657842C,   800,  260 },
+        { 0x9B10A4E5E9913129,   827,  268 },
+        { 0xE7109BFBA19C0C9D,   853,  276 },
+        { 0xAC2820D9623BF429,   880,  284 },
+        { 0x80444B5E7AA7CF85,   907,  292 },
+        { 0xBF21E44003ACDD2D,   933,  300 },
+        { 0x8E679C2F5E44FF8F,   960,  308 },
+        { 0xD433179D9C8CB841,   986,  316 },
+        { 0x9E19DB92B4E31BA9,  1013,  324 },
+    };
+
+    // This computation gives exactly the same results for k as
+    //      k = ceil((kAlpha - e - 1) * 0.30102999566398114)
+    // for |e| <= 1500, but doesn't require floating-point operations.
+    // NB: log_10(2) ~= 78913 / 2^18
+    assert(e >= -1500);
+    assert(e <=  1500);
+    const int f = kAlpha - e - 1;
+    const int k = (f * 78913) / (1 << 18) + (f > 0);
+
+    const int index = (-kCachedPowersMinDecExp + k + (kCachedPowersDecStep - 1)) / kCachedPowersDecStep;
+    assert(index >= 0);
+    assert(index < kCachedPowersSize);
+    static_cast<void>(kCachedPowersSize); // Fix warning.
+
+    const cached_power cached = kCachedPowers[index];
+    assert(kAlpha <= cached.e + e + 64);
+    assert(kGamma >= cached.e + e + 64);
+
+    return cached;
+}
+
+/*!
+For n != 0, returns k, such that pow10 := 10^(k-1) <= n < 10^k.
+For n == 0, returns 1 and sets pow10 := 1.
+*/
+inline int find_largest_pow10(const uint32_t n, uint32_t& pow10)
+{
+    // LCOV_EXCL_START
+    if (n >= 1000000000)
+    {
+        pow10 = 1000000000;
+        return 10;
+    }
+    // LCOV_EXCL_STOP
+    else if (n >= 100000000)
+    {
+        pow10 = 100000000;
+        return  9;
+    }
+    else if (n >= 10000000)
+    {
+        pow10 = 10000000;
+        return  8;
+    }
+    else if (n >= 1000000)
+    {
+        pow10 = 1000000;
+        return  7;
+    }
+    else if (n >= 100000)
+    {
+        pow10 = 100000;
+        return  6;
+    }
+    else if (n >= 10000)
+    {
+        pow10 = 10000;
+        return  5;
+    }
+    else if (n >= 1000)
+    {
+        pow10 = 1000;
+        return  4;
+    }
+    else if (n >= 100)
+    {
+        pow10 = 100;
+        return  3;
+    }
+    else if (n >= 10)
+    {
+        pow10 = 10;
+        return  2;
+    }
+    else
+    {
+        pow10 = 1;
+        return 1;
+    }
+}
+
+inline void grisu2_round(char* buf, int len, uint64_t dist, uint64_t delta,
+                         uint64_t rest, uint64_t ten_k)
+{
+    assert(len >= 1);
+    assert(dist <= delta);
+    assert(rest <= delta);
+    assert(ten_k > 0);
+
+    //               <--------------------------- delta ---->
+    //                                  <---- dist --------->
+    // --------------[------------------+-------------------]--------------
+    //               M-                 w                   M+
+    //
+    //                                  ten_k
+    //                                <------>
+    //                                       <---- rest ---->
+    // --------------[------------------+----+--------------]--------------
+    //                                  w    V
+    //                                       = buf * 10^k
+    //
+    // ten_k represents a unit-in-the-last-place in the decimal representation
+    // stored in buf.
+    // Decrement buf by ten_k while this takes buf closer to w.
+
+    // The tests are written in this order to avoid overflow in unsigned
+    // integer arithmetic.
+
+    while (rest < dist
+            and delta - rest >= ten_k
+            and (rest + ten_k < dist or dist - rest > rest + ten_k - dist))
+    {
+        assert(buf[len - 1] != '0');
+        buf[len - 1]--;
+        rest += ten_k;
+    }
+}
+
+/*!
+Generates V = buffer * 10^decimal_exponent, such that M- <= V <= M+.
+M- and M+ must be normalized and share the same exponent -60 <= e <= -32.
+*/
+inline void grisu2_digit_gen(char* buffer, int& length, int& decimal_exponent,
+                             diyfp M_minus, diyfp w, diyfp M_plus)
+{
+    static_assert(kAlpha >= -60, "internal error");
+    static_assert(kGamma <= -32, "internal error");
+
+    // Generates the digits (and the exponent) of a decimal floating-point
+    // number V = buffer * 10^decimal_exponent in the range [M-, M+]. The diyfp's
+    // w, M- and M+ share the same exponent e, which satisfies alpha <= e <= gamma.
+    //
+    //               <--------------------------- delta ---->
+    //                                  <---- dist --------->
+    // --------------[------------------+-------------------]--------------
+    //               M-                 w                   M+
+    //
+    // Grisu2 generates the digits of M+ from left to right and stops as soon as
+    // V is in [M-,M+].
+
+    assert(M_plus.e >= kAlpha);
+    assert(M_plus.e <= kGamma);
+
+    uint64_t delta = diyfp::sub(M_plus, M_minus).f; // (significand of (M+ - M-), implicit exponent is e)
+    uint64_t dist  = diyfp::sub(M_plus, w      ).f; // (significand of (M+ - w ), implicit exponent is e)
+
+    // Split M+ = f * 2^e into two parts p1 and p2 (note: e < 0):
+    //
+    //      M+ = f * 2^e
+    //         = ((f div 2^-e) * 2^-e + (f mod 2^-e)) * 2^e
+    //         = ((p1        ) * 2^-e + (p2        )) * 2^e
+    //         = p1 + p2 * 2^e
+
+    const diyfp one(uint64_t{1} << -M_plus.e, M_plus.e);
+
+    uint32_t p1 = static_cast<uint32_t>(M_plus.f >> -one.e); // p1 = f div 2^-e (Since -e >= 32, p1 fits into a 32-bit int.)
+    uint64_t p2 = M_plus.f & (one.f - 1);                    // p2 = f mod 2^-e
+
+    // 1)
+    //
+    // Generate the digits of the integral part p1 = d[n-1]...d[1]d[0]
+
+    assert(p1 > 0);
+
+    uint32_t pow10;
+    const int k = find_largest_pow10(p1, pow10);
+
+    //      10^(k-1) <= p1 < 10^k, pow10 = 10^(k-1)
+    //
+    //      p1 = (p1 div 10^(k-1)) * 10^(k-1) + (p1 mod 10^(k-1))
+    //         = (d[k-1]         ) * 10^(k-1) + (p1 mod 10^(k-1))
+    //
+    //      M+ = p1                                             + p2 * 2^e
+    //         = d[k-1] * 10^(k-1) + (p1 mod 10^(k-1))          + p2 * 2^e
+    //         = d[k-1] * 10^(k-1) + ((p1 mod 10^(k-1)) * 2^-e + p2) * 2^e
+    //         = d[k-1] * 10^(k-1) + (                         rest) * 2^e
+    //
+    // Now generate the digits d[n] of p1 from left to right (n = k-1,...,0)
+    //
+    //      p1 = d[k-1]...d[n] * 10^n + d[n-1]...d[0]
+    //
+    // but stop as soon as
+    //
+    //      rest * 2^e = (d[n-1]...d[0] * 2^-e + p2) * 2^e <= delta * 2^e
+
+    int n = k;
+    while (n > 0)
+    {
+        // Invariants:
+        //      M+ = buffer * 10^n + (p1 + p2 * 2^e)    (buffer = 0 for n = k)
+        //      pow10 = 10^(n-1) <= p1 < 10^n
+        //
+        const uint32_t d = p1 / pow10;  // d = p1 div 10^(n-1)
+        const uint32_t r = p1 % pow10;  // r = p1 mod 10^(n-1)
+        //
+        //      M+ = buffer * 10^n + (d * 10^(n-1) + r) + p2 * 2^e
+        //         = (buffer * 10 + d) * 10^(n-1) + (r + p2 * 2^e)
+        //
+        assert(d <= 9);
+        buffer[length++] = static_cast<char>('0' + d); // buffer := buffer * 10 + d
+        //
+        //      M+ = buffer * 10^(n-1) + (r + p2 * 2^e)
+        //
+        p1 = r;
+        n--;
+        //
+        //      M+ = buffer * 10^n + (p1 + p2 * 2^e)
+        //      pow10 = 10^n
+        //
+
+        // Now check if enough digits have been generated.
+        // Compute
+        //
+        //      p1 + p2 * 2^e = (p1 * 2^-e + p2) * 2^e = rest * 2^e
+        //
+        // Note:
+        // Since rest and delta share the same exponent e, it suffices to
+        // compare the significands.
+        const uint64_t rest = (uint64_t{p1} << -one.e) + p2;
+        if (rest <= delta)
+        {
+            // V = buffer * 10^n, with M- <= V <= M+.
+
+            decimal_exponent += n;
+
+            // We may now just stop. But instead look if the buffer could be
+            // decremented to bring V closer to w.
+            //
+            // pow10 = 10^n is now 1 ulp in the decimal representation V.
+            // The rounding procedure works with diyfp's with an implicit
+            // exponent of e.
+            //
+            //      10^n = (10^n * 2^-e) * 2^e = ulp * 2^e
+            //
+            const uint64_t ten_n = uint64_t{pow10} << -one.e;
+            grisu2_round(buffer, length, dist, delta, rest, ten_n);
+
+            return;
+        }
+
+        pow10 /= 10;
+        //
+        //      pow10 = 10^(n-1) <= p1 < 10^n
+        // Invariants restored.
+    }
+
+    // 2)
+    //
+    // The digits of the integral part have been generated:
+    //
+    //      M+ = d[k-1]...d[1]d[0] + p2 * 2^e
+    //         = buffer            + p2 * 2^e
+    //
+    // Now generate the digits of the fractional part p2 * 2^e.
+    //
+    // Note:
+    // No decimal point is generated: the exponent is adjusted instead.
+    //
+    // p2 actually represents the fraction
+    //
+    //      p2 * 2^e
+    //          = p2 / 2^-e
+    //          = d[-1] / 10^1 + d[-2] / 10^2 + ...
+    //
+    // Now generate the digits d[-m] of p1 from left to right (m = 1,2,...)
+    //
+    //      p2 * 2^e = d[-1]d[-2]...d[-m] * 10^-m
+    //                      + 10^-m * (d[-m-1] / 10^1 + d[-m-2] / 10^2 + ...)
+    //
+    // using
+    //
+    //      10^m * p2 = ((10^m * p2) div 2^-e) * 2^-e + ((10^m * p2) mod 2^-e)
+    //                = (                   d) * 2^-e + (                   r)
+    //
+    // or
+    //      10^m * p2 * 2^e = d + r * 2^e
+    //
+    // i.e.
+    //
+    //      M+ = buffer + p2 * 2^e
+    //         = buffer + 10^-m * (d + r * 2^e)
+    //         = (buffer * 10^m + d) * 10^-m + 10^-m * r * 2^e
+    //
+    // and stop as soon as 10^-m * r * 2^e <= delta * 2^e
+
+    assert(p2 > delta);
+
+    int m = 0;
+    for (;;)
+    {
+        // Invariant:
+        //      M+ = buffer * 10^-m + 10^-m * (d[-m-1] / 10 + d[-m-2] / 10^2 + ...) * 2^e
+        //         = buffer * 10^-m + 10^-m * (p2                                 ) * 2^e
+        //         = buffer * 10^-m + 10^-m * (1/10 * (10 * p2)                   ) * 2^e
+        //         = buffer * 10^-m + 10^-m * (1/10 * ((10*p2 div 2^-e) * 2^-e + (10*p2 mod 2^-e)) * 2^e
+        //
+        assert(p2 <= UINT64_MAX / 10);
+        p2 *= 10;
+        const uint64_t d = p2 >> -one.e;     // d = (10 * p2) div 2^-e
+        const uint64_t r = p2 & (one.f - 1); // r = (10 * p2) mod 2^-e
+        //
+        //      M+ = buffer * 10^-m + 10^-m * (1/10 * (d * 2^-e + r) * 2^e
+        //         = buffer * 10^-m + 10^-m * (1/10 * (d + r * 2^e))
+        //         = (buffer * 10 + d) * 10^(-m-1) + 10^(-m-1) * r * 2^e
+        //
+        assert(d <= 9);
+        buffer[length++] = static_cast<char>('0' + d); // buffer := buffer * 10 + d
+        //
+        //      M+ = buffer * 10^(-m-1) + 10^(-m-1) * r * 2^e
+        //
+        p2 = r;
+        m++;
+        //
+        //      M+ = buffer * 10^-m + 10^-m * p2 * 2^e
+        // Invariant restored.
+
+        // Check if enough digits have been generated.
+        //
+        //      10^-m * p2 * 2^e <= delta * 2^e
+        //              p2 * 2^e <= 10^m * delta * 2^e
+        //                    p2 <= 10^m * delta
+        delta *= 10;
+        dist  *= 10;
+        if (p2 <= delta)
+        {
+            break;
+        }
+    }
+
+    // V = buffer * 10^-m, with M- <= V <= M+.
+
+    decimal_exponent -= m;
+
+    // 1 ulp in the decimal representation is now 10^-m.
+    // Since delta and dist are now scaled by 10^m, we need to do the
+    // same with ulp in order to keep the units in sync.
+    //
+    //      10^m * 10^-m = 1 = 2^-e * 2^e = ten_m * 2^e
+    //
+    const uint64_t ten_m = one.f;
+    grisu2_round(buffer, length, dist, delta, p2, ten_m);
+
+    // By construction this algorithm generates the shortest possible decimal
+    // number (Loitsch, Theorem 6.2) which rounds back to w.
+    // For an input number of precision p, at least
+    //
+    //      N = 1 + ceil(p * log_10(2))
+    //
+    // decimal digits are sufficient to identify all binary floating-point
+    // numbers (Matula, "In-and-Out conversions").
+    // This implies that the algorithm does not produce more than N decimal
+    // digits.
+    //
+    //      N = 17 for p = 53 (IEEE double precision)
+    //      N = 9  for p = 24 (IEEE single precision)
+}
+
+/*!
+v = buf * 10^decimal_exponent
+len is the length of the buffer (number of decimal digits)
+The buffer must be large enough, i.e. >= max_digits10.
+*/
+inline void grisu2(char* buf, int& len, int& decimal_exponent,
+                   diyfp m_minus, diyfp v, diyfp m_plus)
+{
+    assert(m_plus.e == m_minus.e);
+    assert(m_plus.e == v.e);
+
+    //  --------(-----------------------+-----------------------)--------    (A)
+    //          m-                      v                       m+
+    //
+    //  --------------------(-----------+-----------------------)--------    (B)
+    //                      m-          v                       m+
+    //
+    // First scale v (and m- and m+) such that the exponent is in the range
+    // [alpha, gamma].
+
+    const cached_power cached = get_cached_power_for_binary_exponent(m_plus.e);
+
+    const diyfp c_minus_k(cached.f, cached.e); // = c ~= 10^-k
+
+    // The exponent of the products is = v.e + c_minus_k.e + q and is in the range [alpha,gamma]
+    const diyfp w       = diyfp::mul(v,       c_minus_k);
+    const diyfp w_minus = diyfp::mul(m_minus, c_minus_k);
+    const diyfp w_plus  = diyfp::mul(m_plus,  c_minus_k);
+
+    //  ----(---+---)---------------(---+---)---------------(---+---)----
+    //          w-                      w                       w+
+    //          = c*m-                  = c*v                   = c*m+
+    //
+    // diyfp::mul rounds its result and c_minus_k is approximated too. w, w- and
+    // w+ are now off by a small amount.
+    // In fact:
+    //
+    //      w - v * 10^k < 1 ulp
+    //
+    // To account for this inaccuracy, add resp. subtract 1 ulp.
+    //
+    //  --------+---[---------------(---+---)---------------]---+--------
+    //          w-  M-                  w                   M+  w+
+    //
+    // Now any number in [M-, M+] (bounds included) will round to w when input,
+    // regardless of how the input rounding algorithm breaks ties.
+    //
+    // And digit_gen generates the shortest possible such number in [M-, M+].
+    // Note that this does not mean that Grisu2 always generates the shortest
+    // possible number in the interval (m-, m+).
+    const diyfp M_minus(w_minus.f + 1, w_minus.e);
+    const diyfp M_plus (w_plus.f  - 1, w_plus.e );
+
+    decimal_exponent = -cached.k; // = -(-k) = k
+
+    grisu2_digit_gen(buf, len, decimal_exponent, M_minus, w, M_plus);
+}
+
+/*!
+v = buf * 10^decimal_exponent
+len is the length of the buffer (number of decimal digits)
+The buffer must be large enough, i.e. >= max_digits10.
+*/
+template <typename FloatType>
+void grisu2(char* buf, int& len, int& decimal_exponent, FloatType value)
+{
+    static_assert(diyfp::kPrecision >= std::numeric_limits<FloatType>::digits + 3,
+                  "internal error: not enough precision");
+
+    assert(std::isfinite(value));
+    assert(value > 0);
+
+    // If the neighbors (and boundaries) of 'value' are always computed for double-precision
+    // numbers, all float's can be recovered using strtod (and strtof). However, the resulting
+    // decimal representations are not exactly "short".
+    //
+    // The documentation for 'std::to_chars' (https://en.cppreference.com/w/cpp/utility/to_chars)
+    // says "value is converted to a string as if by std::sprintf in the default ("C") locale"
+    // and since sprintf promotes float's to double's, I think this is exactly what 'std::to_chars'
+    // does.
+    // On the other hand, the documentation for 'std::to_chars' requires that "parsing the
+    // representation using the corresponding std::from_chars function recovers value exactly". That
+    // indicates that single precision floating-point numbers should be recovered using
+    // 'std::strtof'.
+    //
+    // NB: If the neighbors are computed for single-precision numbers, there is a single float
+    //     (7.0385307e-26f) which can't be recovered using strtod. The resulting double precision
+    //     value is off by 1 ulp.
+#if 0
+    const boundaries w = compute_boundaries(static_cast<double>(value));
+#else
+    const boundaries w = compute_boundaries(value);
+#endif
+
+    grisu2(buf, len, decimal_exponent, w.minus, w.w, w.plus);
+}
+
+/*!
+@brief appends a decimal representation of e to buf
+@return a pointer to the element following the exponent.
+@pre -1000 < e < 1000
+*/
+inline char* append_exponent(char* buf, int e)
+{
+    assert(e > -1000);
+    assert(e <  1000);
+
+    if (e < 0)
+    {
+        e = -e;
+        *buf++ = '-';
+    }
+    else
+    {
+        *buf++ = '+';
+    }
+
+    uint32_t k = static_cast<uint32_t>(e);
+    if (k < 10)
+    {
+        // Always print at least two digits in the exponent.
+        // This is for compatibility with printf("%g").
+        *buf++ = '0';
+        *buf++ = static_cast<char>('0' + k);
+    }
+    else if (k < 100)
+    {
+        *buf++ = static_cast<char>('0' + k / 10);
+        k %= 10;
+        *buf++ = static_cast<char>('0' + k);
+    }
+    else
+    {
+        *buf++ = static_cast<char>('0' + k / 100);
+        k %= 100;
+        *buf++ = static_cast<char>('0' + k / 10);
+        k %= 10;
+        *buf++ = static_cast<char>('0' + k);
+    }
+
+    return buf;
+}
+
+/*!
+@brief prettify v = buf * 10^decimal_exponent
+
+If v is in the range [10^min_exp, 10^max_exp) it will be printed in fixed-point
+notation. Otherwise it will be printed in exponential notation.
+
+@pre min_exp < 0
+@pre max_exp > 0
+*/
+inline char* format_buffer(char* buf, int len, int decimal_exponent,
+                           int min_exp, int max_exp)
+{
+    assert(min_exp < 0);
+    assert(max_exp > 0);
+
+    const int k = len;
+    const int n = len + decimal_exponent;
+
+    // v = buf * 10^(n-k)
+    // k is the length of the buffer (number of decimal digits)
+    // n is the position of the decimal point relative to the start of the buffer.
+
+    if (k <= n and n <= max_exp)
+    {
+        // digits[000]
+        // len <= max_exp + 2
+
+        std::memset(buf + k, '0', static_cast<size_t>(n - k));
+        // Make it look like a floating-point number (#362, #378)
+        buf[n + 0] = '.';
+        buf[n + 1] = '0';
+        return buf + (n + 2);
+    }
+
+    if (0 < n and n <= max_exp)
+    {
+        // dig.its
+        // len <= max_digits10 + 1
+
+        assert(k > n);
+
+        std::memmove(buf + (n + 1), buf + n, static_cast<size_t>(k - n));
+        buf[n] = '.';
+        return buf + (k + 1);
+    }
+
+    if (min_exp < n and n <= 0)
+    {
+        // 0.[000]digits
+        // len <= 2 + (-min_exp - 1) + max_digits10
+
+        std::memmove(buf + (2 + -n), buf, static_cast<size_t>(k));
+        buf[0] = '0';
+        buf[1] = '.';
+        std::memset(buf + 2, '0', static_cast<size_t>(-n));
+        return buf + (2 + (-n) + k);
+    }
+
+    if (k == 1)
+    {
+        // dE+123
+        // len <= 1 + 5
+
+        buf += 1;
+    }
+    else
+    {
+        // d.igitsE+123
+        // len <= max_digits10 + 1 + 5
+
+        std::memmove(buf + 2, buf + 1, static_cast<size_t>(k - 1));
+        buf[1] = '.';
+        buf += 1 + k;
+    }
+
+    *buf++ = 'e';
+    return append_exponent(buf, n - 1);
+}
+
+} // namespace dtoa_impl
+
+/*!
+@brief generates a decimal representation of the floating-point number value in [first, last).
+
+The format of the resulting decimal representation is similar to printf's %g
+format. Returns an iterator pointing past-the-end of the decimal representation.
+
+@note The input number must be finite, i.e. NaN's and Inf's are not supported.
+@note The buffer must be large enough.
+@note The result is NOT null-terminated.
+*/
+template <typename FloatType>
+char* to_chars(char* first, char* last, FloatType value)
+{
+    static_cast<void>(last); // maybe unused - fix warning
+    assert(std::isfinite(value));
+
+    // Use signbit(value) instead of (value < 0) since signbit works for -0.
+    if (std::signbit(value))
+    {
+        value = -value;
+        *first++ = '-';
+    }
+
+    if (value == 0) // +-0
+    {
+        *first++ = '0';
+        // Make it look like a floating-point number (#362, #378)
+        *first++ = '.';
+        *first++ = '0';
+        return first;
+    }
+
+    assert(last - first >= std::numeric_limits<FloatType>::max_digits10);
+
+    // Compute v = buffer * 10^decimal_exponent.
+    // The decimal digits are stored in the buffer, which needs to be interpreted
+    // as an unsigned decimal integer.
+    // len is the length of the buffer, i.e. the number of decimal digits.
+    int len = 0;
+    int decimal_exponent = 0;
+    dtoa_impl::grisu2(first, len, decimal_exponent, value);
+
+    assert(len <= std::numeric_limits<FloatType>::max_digits10);
+
+    // Format the buffer like printf("%.*g", prec, value)
+    constexpr int kMinExp = -4;
+    // Use digits10 here to increase compatibility with version 2.
+    constexpr int kMaxExp = std::numeric_limits<FloatType>::digits10;
+
+    assert(last - first >= kMaxExp + 2);
+    assert(last - first >= 2 + (-kMinExp - 1) + std::numeric_limits<FloatType>::max_digits10);
+    assert(last - first >= std::numeric_limits<FloatType>::max_digits10 + 6);
+
+    return dtoa_impl::format_buffer(first, len, decimal_exponent, kMinExp, kMaxExp);
+}
+
+} // namespace detail
+} // namespace nlohmann
+
+// #include <nlohmann/detail/macro_scope.hpp>
+
+// #include <nlohmann/detail/meta/cpp_future.hpp>
+
+// #include <nlohmann/detail/output/output_adapters.hpp>
+
+// #include <nlohmann/detail/value_t.hpp>
+
+
+namespace nlohmann
+{
+namespace detail
+{
 ///////////////////
 // serialization //
 ///////////////////
@@ -6077,6 +9765,9 @@ class serializer
     using number_float_t = typename BasicJsonType::number_float_t;
     using number_integer_t = typename BasicJsonType::number_integer_t;
     using number_unsigned_t = typename BasicJsonType::number_unsigned_t;
+    static constexpr uint8_t UTF8_ACCEPT = 0;
+    static constexpr uint8_t UTF8_REJECT = 1;
+
   public:
     /*!
     @param[in] s  output stream to serialize to
@@ -6086,7 +9777,8 @@ class serializer
         : o(std::move(s)), loc(std::localeconv()),
           thousands_sep(loc->thousands_sep == nullptr ? '\0' : * (loc->thousands_sep)),
           decimal_point(loc->decimal_point == nullptr ? '\0' : * (loc->decimal_point)),
-          indent_char(ichar), indent_string(512, indent_char) {}
+          indent_char(ichar), indent_string(512, indent_char)
+    {}
 
     // delete because of pointer members
     serializer(const serializer&) = delete;
@@ -6303,171 +9995,6 @@ class serializer
 
   private:
     /*!
-    @brief returns the number of expected bytes following in UTF-8 string
-
-    @param[in]  u  the first byte of a UTF-8 string
-    @return  the number of expected bytes following
-    */
-    static constexpr std::size_t bytes_following(const uint8_t u)
-    {
-        return ((u <= 127) ? 0
-                : ((192 <= u and u <= 223) ? 1
-                   : ((224 <= u and u <= 239) ? 2
-                      : ((240 <= u and u <= 247) ? 3 : std::string::npos))));
-    }
-
-    /*!
-    @brief calculates the extra space to escape a JSON string
-
-    @param[in] s  the string to escape
-    @param[in] ensure_ascii  whether to escape non-ASCII characters with
-                             \uXXXX sequences
-    @return the number of characters required to escape string @a s
-
-    @complexity Linear in the length of string @a s.
-    */
-    static std::size_t extra_space(const string_t& s,
-                                   const bool ensure_ascii) noexcept
-    {
-        std::size_t res = 0;
-
-        for (std::size_t i = 0; i < s.size(); ++i)
-        {
-            switch (s[i])
-            {
-                // control characters that can be escaped with a backslash
-                case '"':
-                case '\\':
-                case '\b':
-                case '\f':
-                case '\n':
-                case '\r':
-                case '\t':
-                {
-                    // from c (1 byte) to \x (2 bytes)
-                    res += 1;
-                    break;
-                }
-
-                // control characters that need \uxxxx escaping
-                case 0x00:
-                case 0x01:
-                case 0x02:
-                case 0x03:
-                case 0x04:
-                case 0x05:
-                case 0x06:
-                case 0x07:
-                case 0x0B:
-                case 0x0E:
-                case 0x0F:
-                case 0x10:
-                case 0x11:
-                case 0x12:
-                case 0x13:
-                case 0x14:
-                case 0x15:
-                case 0x16:
-                case 0x17:
-                case 0x18:
-                case 0x19:
-                case 0x1A:
-                case 0x1B:
-                case 0x1C:
-                case 0x1D:
-                case 0x1E:
-                case 0x1F:
-                {
-                    // from c (1 byte) to \uxxxx (6 bytes)
-                    res += 5;
-                    break;
-                }
-
-                default:
-                {
-                    if (ensure_ascii and (s[i] & 0x80 or s[i] == 0x7F))
-                    {
-                        const auto bytes = bytes_following(static_cast<uint8_t>(s[i]));
-                        // invalid characters will be detected by throw_if_invalid_utf8
-                        assert (bytes != std::string::npos);
-
-                        if (bytes == 3)
-                        {
-                            // codepoints that need 4 bytes (i.e., 3 additional
-                            // bytes) in UTF-8 need a surrogate pair when \u
-                            // escaping is used: from 4 bytes to \uxxxx\uxxxx
-                            // (12 bytes)
-                            res += (12 - bytes - 1);
-                        }
-                        else
-                        {
-                            // from x bytes to \uxxxx (6 bytes)
-                            res += (6 - bytes - 1);
-                        }
-
-                        // skip the additional bytes
-                        i += bytes;
-                    }
-                    break;
-                }
-            }
-        }
-
-        return res;
-    }
-
-    static void escape_codepoint(int codepoint, string_t& result, std::size_t& pos)
-    {
-        // expecting a proper codepoint
-        assert(0x00 <= codepoint and codepoint <= 0x10FFFF);
-
-        // the last written character was the backslash before the 'u'
-        assert(result[pos] == '\\');
-
-        // write the 'u'
-        result[++pos] = 'u';
-
-        // convert a number 0..15 to its hex representation (0..f)
-        static const std::array<char, 16> hexify =
-        {
-            {
-                '0', '1', '2', '3', '4', '5', '6', '7',
-                '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
-            }
-        };
-
-        if (codepoint < 0x10000)
-        {
-            // codepoints U+0000..U+FFFF can be represented as \uxxxx.
-            result[++pos] = hexify[(codepoint >> 12) & 0x0F];
-            result[++pos] = hexify[(codepoint >> 8) & 0x0F];
-            result[++pos] = hexify[(codepoint >> 4) & 0x0F];
-            result[++pos] = hexify[codepoint & 0x0F];
-        }
-        else
-        {
-            // codepoints U+10000..U+10FFFF need a surrogate pair to be
-            // represented as \uxxxx\uxxxx.
-            // http://www.unicode.org/faq/utf_bom.html#utf16-4
-            codepoint -= 0x10000;
-            const int high_surrogate = 0xD800 | ((codepoint >> 10) & 0x3FF);
-            const int low_surrogate = 0xDC00 | (codepoint & 0x3FF);
-            result[++pos] = hexify[(high_surrogate >> 12) & 0x0F];
-            result[++pos] = hexify[(high_surrogate >> 8) & 0x0F];
-            result[++pos] = hexify[(high_surrogate >> 4) & 0x0F];
-            result[++pos] = hexify[high_surrogate & 0x0F];
-            ++pos;  // backslash is already in output
-            result[++pos] = 'u';
-            result[++pos] = hexify[(low_surrogate >> 12) & 0x0F];
-            result[++pos] = hexify[(low_surrogate >> 8) & 0x0F];
-            result[++pos] = hexify[(low_surrogate >> 4) & 0x0F];
-            result[++pos] = hexify[low_surrogate & 0x0F];
-        }
-
-        ++pos;
-    }
-
-    /*!
     @brief dump escaped string
 
     Escape a string by replacing certain special characters by a sequence of an
@@ -6481,145 +10008,146 @@ class serializer
 
     @complexity Linear in the length of string @a s.
     */
-    void dump_escaped(const string_t& s, const bool ensure_ascii) const
+    void dump_escaped(const string_t& s, const bool ensure_ascii)
     {
-        throw_if_invalid_utf8(s);
+        uint32_t codepoint;
+        uint8_t state = UTF8_ACCEPT;
+        std::size_t bytes = 0;  // number of bytes written to string_buffer
 
-        const auto space = extra_space(s, ensure_ascii);
-        if (space == 0)
-        {
-            o->write_characters(s.c_str(), s.size());
-            return;
-        }
-
-        // create a result string of necessary size
-        string_t result(s.size() + space, '\\');
-        std::size_t pos = 0;
-
         for (std::size_t i = 0; i < s.size(); ++i)
         {
-            switch (s[i])
+            const auto byte = static_cast<uint8_t>(s[i]);
+
+            switch (decode(state, codepoint, byte))
             {
-                case '"': // quotation mark (0x22)
+                case UTF8_ACCEPT:  // decode found a new code point
                 {
-                    result[pos + 1] = '"';
-                    pos += 2;
-                    break;
-                }
+                    switch (codepoint)
+                    {
+                        case 0x08: // backspace
+                        {
+                            string_buffer[bytes++] = '\\';
+                            string_buffer[bytes++] = 'b';
+                            break;
+                        }
 
-                case '\\': // reverse solidus (0x5C)
-                {
-                    // nothing to change
-                    pos += 2;
-                    break;
-                }
+                        case 0x09: // horizontal tab
+                        {
+                            string_buffer[bytes++] = '\\';
+                            string_buffer[bytes++] = 't';
+                            break;
+                        }
 
-                case '\b': // backspace (0x08)
-                {
-                    result[pos + 1] = 'b';
-                    pos += 2;
-                    break;
-                }
+                        case 0x0A: // newline
+                        {
+                            string_buffer[bytes++] = '\\';
+                            string_buffer[bytes++] = 'n';
+                            break;
+                        }
 
-                case '\f': // formfeed (0x0C)
-                {
-                    result[pos + 1] = 'f';
-                    pos += 2;
-                    break;
-                }
+                        case 0x0C: // formfeed
+                        {
+                            string_buffer[bytes++] = '\\';
+                            string_buffer[bytes++] = 'f';
+                            break;
+                        }
 
-                case '\n': // newline (0x0A)
-                {
-                    result[pos + 1] = 'n';
-                    pos += 2;
-                    break;
-                }
+                        case 0x0D: // carriage return
+                        {
+                            string_buffer[bytes++] = '\\';
+                            string_buffer[bytes++] = 'r';
+                            break;
+                        }
 
-                case '\r': // carriage return (0x0D)
-                {
-                    result[pos + 1] = 'r';
-                    pos += 2;
-                    break;
-                }
+                        case 0x22: // quotation mark
+                        {
+                            string_buffer[bytes++] = '\\';
+                            string_buffer[bytes++] = '\"';
+                            break;
+                        }
 
-                case '\t': // horizontal tab (0x09)
-                {
-                    result[pos + 1] = 't';
-                    pos += 2;
-                    break;
-                }
+                        case 0x5C: // reverse solidus
+                        {
+                            string_buffer[bytes++] = '\\';
+                            string_buffer[bytes++] = '\\';
+                            break;
+                        }
 
-                default:
-                {
-                    // escape control characters (0x00..0x1F) or, if
-                    // ensure_ascii parameter is used, non-ASCII characters
-                    if ((0x00 <= s[i] and s[i] <= 0x1F) or
-                            (ensure_ascii and (s[i] & 0x80 or s[i] == 0x7F)))
-                    {
-                        const auto bytes = bytes_following(static_cast<uint8_t>(s[i]));
-                        // invalid characters will be detected by throw_if_invalid_utf8
-                        assert (bytes != std::string::npos);
-
-                        // check that the additional bytes are present
-                        assert(i + bytes < s.size());
-
-                        // to use \uxxxx escaping, we first need to calculate
-                        // the codepoint from the UTF-8 bytes
-                        int codepoint = 0;
-
-                        // bytes is unsigned type:
-                        assert(bytes <= 3);
-                        switch (bytes)
+                        default:
                         {
-                            case 0:
+                            // escape control characters (0x00..0x1F) or, if
+                            // ensure_ascii parameter is used, non-ASCII characters
+                            if ((codepoint <= 0x1F) or (ensure_ascii and (codepoint >= 0x7F)))
                             {
-                                codepoint = s[i] & 0xFF;
-                                break;
+                                if (codepoint <= 0xFFFF)
+                                {
+                                    std::snprintf(string_buffer.data() + bytes, 7, "\\u%04x",
+                                                  static_cast<uint16_t>(codepoint));
+                                    bytes += 6;
+                                }
+                                else
+                                {
+                                    std::snprintf(string_buffer.data() + bytes, 13, "\\u%04x\\u%04x",
+                                                  static_cast<uint16_t>(0xD7C0 + (codepoint >> 10)),
+                                                  static_cast<uint16_t>(0xDC00 + (codepoint & 0x3FF)));
+                                    bytes += 12;
+                                }
                             }
-
-                            case 1:
+                            else
                             {
-                                codepoint = ((s[i] & 0x3F) << 6)
-                                            + (s[i + 1] & 0x7F);
-                                break;
+                                // copy byte to buffer (all previous bytes
+                                // been copied have in default case above)
+                                string_buffer[bytes++] = s[i];
                             }
-
-                            case 2:
-                            {
-                                codepoint = ((s[i] & 0x1F) << 12)
-                                            + ((s[i + 1] & 0x7F) << 6)
-                                            + (s[i + 2] & 0x7F);
-                                break;
-                            }
-
-                            case 3:
-                            {
-                                codepoint = ((s[i] & 0xF) << 18)
-                                            + ((s[i + 1] & 0x7F) << 12)
-                                            + ((s[i + 2] & 0x7F) << 6)
-                                            + (s[i + 3] & 0x7F);
-                                break;
-                            }
-
-                            default:
-                                break;  // LCOV_EXCL_LINE
+                            break;
                         }
+                    }
 
-                        escape_codepoint(codepoint, result, pos);
-                        i += bytes;
+                    // write buffer and reset index; there must be 13 bytes
+                    // left, as this is the maximal number of bytes to be
+                    // written ("\uxxxx\uxxxx\0") for one code point
+                    if (string_buffer.size() - bytes < 13)
+                    {
+                        o->write_characters(string_buffer.data(), bytes);
+                        bytes = 0;
                     }
-                    else
+                    break;
+                }
+
+                case UTF8_REJECT:  // decode found invalid UTF-8 byte
+                {
+                    std::string sn(3, '\0');
+                    snprintf(&sn[0], sn.size(), "%.2X", byte);
+                    JSON_THROW(type_error::create(316, "invalid UTF-8 byte at index " + std::to_string(i) + ": 0x" + sn));
+                }
+
+                default:  // decode found yet incomplete multi-byte code point
+                {
+                    if (not ensure_ascii)
                     {
-                        // all other characters are added as-is
-                        result[pos++] = s[i];
+                        // code point will not be escaped - copy byte to buffer
+                        string_buffer[bytes++] = s[i];
                     }
                     break;
                 }
             }
         }
 
-        assert(pos == result.size());
-        o->write_characters(result.c_str(), result.size());
+        if (JSON_LIKELY(state == UTF8_ACCEPT))
+        {
+            // write buffer
+            if (bytes > 0)
+            {
+                o->write_characters(string_buffer.data(), bytes);
+            }
+        }
+        else
+        {
+            // we finish reading, but do not accept: string was incomplete
+            std::string sn(3, '\0');
+            snprintf(&sn[0], sn.size(), "%.2X", static_cast<uint8_t>(s.back()));
+            JSON_THROW(type_error::create(316, "incomplete UTF-8 string; last byte: 0x" + sn));
+        }
     }
 
     /*!
@@ -6679,15 +10207,37 @@ class serializer
     void dump_float(number_float_t x)
     {
         // NaN / inf
-        if (not std::isfinite(x) or std::isnan(x))
+        if (not std::isfinite(x))
         {
             o->write_characters("null", 4);
             return;
         }
 
-        // get number of digits for a text -> float -> text round-trip
-        static constexpr auto d = std::numeric_limits<number_float_t>::digits10;
+        // If number_float_t is an IEEE-754 single or double precision number,
+        // use the Grisu2 algorithm to produce short numbers which are
+        // guaranteed to round-trip, using strtof and strtod, resp.
+        //
+        // NB: The test below works if <long double> == <double>.
+        static constexpr bool is_ieee_single_or_double
+            = (std::numeric_limits<number_float_t>::is_iec559 and std::numeric_limits<number_float_t>::digits == 24 and std::numeric_limits<number_float_t>::max_exponent == 128) or
+              (std::numeric_limits<number_float_t>::is_iec559 and std::numeric_limits<number_float_t>::digits == 53 and std::numeric_limits<number_float_t>::max_exponent == 1024);
 
+        dump_float(x, std::integral_constant<bool, is_ieee_single_or_double>());
+    }
+
+    void dump_float(number_float_t x, std::true_type /*is_ieee_single_or_double*/)
+    {
+        char* begin = number_buffer.data();
+        char* end = ::nlohmann::detail::to_chars(begin, begin + number_buffer.size(), x);
+
+        o->write_characters(begin, static_cast<size_t>(end - begin));
+    }
+
+    void dump_float(number_float_t x, std::false_type /*is_ieee_single_or_double*/)
+    {
+        // get number of digits for a float -> text -> float round-trip
+        static constexpr auto d = std::numeric_limits<number_float_t>::max_digits10;
+
         // the actual conversion
         std::ptrdiff_t len = snprintf(number_buffer.data(), number_buffer.size(), "%.*g", d, x);
 
@@ -6744,15 +10294,16 @@ class serializer
     followed.
 
     @param[in,out] state  the state of the decoding
+    @param[in,out] codep  codepoint (valid only if resulting state is UTF8_ACCEPT)
     @param[in] byte       next byte to decode
+    @return               new state
 
-    @note The function has been edited: a std::array is used and the code
-          point is not calculated.
+    @note The function has been edited: a std::array is used.
 
     @copyright Copyright (c) 2008-2009 Bjoern Hoehrmann <bjoern@hoehrmann.de>
     @sa http://bjoern.hoehrmann.de/utf-8/decoder/dfa/
     */
-    static void decode(uint8_t& state, const uint8_t byte)
+    static uint8_t decode(uint8_t& state, uint32_t& codep, const uint8_t byte) noexcept
     {
         static const std::array<uint8_t, 400> utf8d =
         {
@@ -6775,42 +10326,13 @@ class serializer
         };
 
         const uint8_t type = utf8d[byte];
-        state = utf8d[256u + state * 16u + type];
-    }
 
-    /*!
-    @brief throw an exception if a string is not UTF-8 encoded
+        codep = (state != UTF8_ACCEPT)
+                ? (byte & 0x3fu) | (codep << 6)
+                : static_cast<uint32_t>(0xff >> type) & (byte);
 
-    @param[in] str  UTF-8 string to check
-    @throw type_error.316 if passed string is not UTF-8 encoded
-
-    @since version 3.0.0
-    */
-    static void throw_if_invalid_utf8(const std::string& str)
-    {
-        // start with state 0 (= accept)
-        uint8_t state = 0;
-
-        for (size_t i = 0; i < str.size(); ++i)
-        {
-            const auto byte = static_cast<uint8_t>(str[i]);
-            decode(state, byte);
-            if (state == 1)
-            {
-                // state 1 means reject
-                std::stringstream ss;
-                ss << std::setw(2) << std::uppercase << std::setfill('0') << std::hex << static_cast<int>(byte);
-                JSON_THROW(type_error::create(316, "invalid UTF-8 byte at index " + std::to_string(i) + ": 0x" + ss.str()));
-            }
-        }
-
-        if (state != 0)
-        {
-            // we finish reading, but do not accept: string was incomplete
-            std::stringstream ss;
-            ss << std::setw(2) << std::uppercase << std::setfill('0') << std::hex << static_cast<int>(static_cast<uint8_t>(str.back()));
-            JSON_THROW(type_error::create(316, "incomplete UTF-8 string; last byte: 0x" + ss.str()));
-        }
+        state = utf8d[256u + state * 16u + type];
+        return state;
     }
 
   private:
@@ -6827,13 +10349,27 @@ class serializer
     /// the locale's decimal point character
     const char decimal_point = '\0';
 
+    /// string buffer
+    std::array<char, 512> string_buffer{{}};
+
     /// the indentation character
     const char indent_char;
-
     /// the indentation string
     string_t indent_string;
 };
+}
+}
 
+// #include <nlohmann/detail/json_ref.hpp>
+
+
+#include <initializer_list>
+#include <utility>
+
+namespace nlohmann
+{
+namespace detail
+{
 template<typename BasicJsonType>
 class json_ref
 {
@@ -6886,74 +10422,30 @@ class json_ref
     value_type* value_ref = nullptr;
     const bool is_rvalue;
 };
-
-} // namespace detail
-
-/// namespace to hold default `to_json` / `from_json` functions
-namespace
-{
-constexpr const auto& to_json = detail::static_const<detail::to_json_fn>::value;
-constexpr const auto& from_json = detail::static_const<detail::from_json_fn>::value;
 }
+}
 
+// #include <nlohmann/detail/json_pointer.hpp>
 
-/*!
-@brief default JSONSerializer template argument
 
-This serializer ignores the template arguments and uses ADL
-([argument-dependent lookup](http://en.cppreference.com/w/cpp/language/adl))
-for serialization.
-*/
-template<typename, typename>
-struct adl_serializer
-{
-    /*!
-    @brief convert a JSON value to any value type
+#include <cassert> // assert
+#include <numeric> // accumulate
+#include <string> // string
+#include <vector> // vector
 
-    This function is usually called by the `get()` function of the
-    @ref basic_json class (either explicit or via conversion operators).
+// #include <nlohmann/detail/macro_scope.hpp>
 
-    @param[in] j         JSON value to read from
-    @param[in,out] val  value to write to
-    */
-    template<typename BasicJsonType, typename ValueType>
-    static void from_json(BasicJsonType&& j, ValueType& val) noexcept(
-        noexcept(::nlohmann::from_json(std::forward<BasicJsonType>(j), val)))
-    {
-        ::nlohmann::from_json(std::forward<BasicJsonType>(j), val);
-    }
+// #include <nlohmann/detail/exceptions.hpp>
 
-    /*!
-    @brief convert any value type to a JSON value
+// #include <nlohmann/detail/value_t.hpp>
 
-    This function is usually called by the constructors of the @ref basic_json
-    class.
 
-    @param[in,out] j  JSON value to write to
-    @param[in] val     value to read from
-    */
-    template<typename BasicJsonType, typename ValueType>
-    static void to_json(BasicJsonType& j, ValueType&& val) noexcept(
-        noexcept(::nlohmann::to_json(j, std::forward<ValueType>(val))))
-    {
-        ::nlohmann::to_json(j, std::forward<ValueType>(val));
-    }
-};
-
-/*!
-@brief JSON Pointer
-
-A JSON pointer defines a string syntax for identifying a specific value
-within a JSON document. It can be used with functions `at` and
-`operator[]`. Furthermore, JSON pointers are the base for JSON patches.
-
-@sa [RFC 6901](https://tools.ietf.org/html/rfc6901)
-
-@since version 2.0.0
-*/
+namespace nlohmann
+{
+template<typename BasicJsonType>
 class json_pointer
 {
-    /// allow basic_json to access private members
+    // allow basic_json to access private members
     NLOHMANN_BASIC_JSON_TPL_DECLARATION
     friend class basic_json;
 
@@ -6967,19 +10459,21 @@ class json_pointer
     @param[in] s  string representing the JSON pointer; if omitted, the empty
                   string is assumed which references the whole JSON value
 
-    @throw parse_error.107 if the given JSON pointer @a s is nonempty and
-    does not begin with a slash (`/`); see example below
+    @throw parse_error.107 if the given JSON pointer @a s is nonempty and does
+                           not begin with a slash (`/`); see example below
 
-    @throw parse_error.108 if a tilde (`~`) in the given JSON pointer @a s
-    is not followed by `0` (representing `~`) or `1` (representing `/`);
-    see example below
+    @throw parse_error.108 if a tilde (`~`) in the given JSON pointer @a s is
+    not followed by `0` (representing `~`) or `1` (representing `/`); see
+    example below
 
-    @liveexample{The example shows the construction several valid JSON
-    pointers as well as the exceptional behavior.,json_pointer}
+    @liveexample{The example shows the construction several valid JSON pointers
+    as well as the exceptional behavior.,json_pointer}
 
     @since version 2.0.0
     */
-    explicit json_pointer(const std::string& s = "") : reference_tokens(split(s)) {}
+    explicit json_pointer(const std::string& s = "")
+        : reference_tokens(split(s))
+    {}
 
     /*!
     @brief return a string representation of the JSON pointer
@@ -7021,7 +10515,7 @@ class json_pointer
     */
     static int array_index(const std::string& s)
     {
-        size_t processed_chars = 0;
+        std::size_t processed_chars = 0;
         const int res = std::stoi(s, &processed_chars);
 
         // check if the string was completely read
@@ -7076,9 +10570,67 @@ class json_pointer
     @throw parse_error.109 if array index is not a number
     @throw type_error.313 if value cannot be unflattened
     */
-    NLOHMANN_BASIC_JSON_TPL_DECLARATION
-    NLOHMANN_BASIC_JSON_TPL& get_and_create(NLOHMANN_BASIC_JSON_TPL& j) const;
+    BasicJsonType& get_and_create(BasicJsonType& j) const
+    {
+        using size_type = typename BasicJsonType::size_type;
+        auto result = &j;
 
+        // in case no reference tokens exist, return a reference to the JSON value
+        // j which will be overwritten by a primitive value
+        for (const auto& reference_token : reference_tokens)
+        {
+            switch (result->m_type)
+            {
+                case detail::value_t::null:
+                {
+                    if (reference_token == "0")
+                    {
+                        // start a new array if reference token is 0
+                        result = &result->operator[](0);
+                    }
+                    else
+                    {
+                        // start a new object otherwise
+                        result = &result->operator[](reference_token);
+                    }
+                    break;
+                }
+
+                case detail::value_t::object:
+                {
+                    // create an entry in the object
+                    result = &result->operator[](reference_token);
+                    break;
+                }
+
+                case detail::value_t::array:
+                {
+                    // create an entry in the array
+                    JSON_TRY
+                    {
+                        result = &result->operator[](static_cast<size_type>(array_index(reference_token)));
+                    }
+                    JSON_CATCH(std::invalid_argument&)
+                    {
+                        JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
+                    }
+                    break;
+                }
+
+                /*
+                The following code is only reached if there exists a reference
+                token _and_ the current value is primitive. In this case, we have
+                an error situation, because primitive values may only occur as
+                single value; that is, with an empty list of reference tokens.
+                */
+                default:
+                    JSON_THROW(detail::type_error::create(313, "invalid value to unflatten"));
+            }
+        }
+
+        return *result;
+    }
+
     /*!
     @brief return a reference to the pointed to value
 
@@ -7098,18 +10650,134 @@ class json_pointer
     @throw parse_error.109   if an array index was not a number
     @throw out_of_range.404  if the JSON pointer can not be resolved
     */
-    NLOHMANN_BASIC_JSON_TPL_DECLARATION
-    NLOHMANN_BASIC_JSON_TPL& get_unchecked(NLOHMANN_BASIC_JSON_TPL* ptr) const;
+    BasicJsonType& get_unchecked(BasicJsonType* ptr) const
+    {
+        using size_type = typename BasicJsonType::size_type;
+        for (const auto& reference_token : reference_tokens)
+        {
+            // convert null values to arrays or objects before continuing
+            if (ptr->m_type == detail::value_t::null)
+            {
+                // check if reference token is a number
+                const bool nums =
+                    std::all_of(reference_token.begin(), reference_token.end(),
+                                [](const char x)
+                {
+                    return (x >= '0' and x <= '9');
+                });
 
+                // change value to array for numbers or "-" or to object otherwise
+                *ptr = (nums or reference_token == "-")
+                       ? detail::value_t::array
+                       : detail::value_t::object;
+            }
+
+            switch (ptr->m_type)
+            {
+                case detail::value_t::object:
+                {
+                    // use unchecked object access
+                    ptr = &ptr->operator[](reference_token);
+                    break;
+                }
+
+                case detail::value_t::array:
+                {
+                    // error condition (cf. RFC 6901, Sect. 4)
+                    if (JSON_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
+                    {
+                        JSON_THROW(detail::parse_error::create(106, 0,
+                                                               "array index '" + reference_token +
+                                                               "' must not begin with '0'"));
+                    }
+
+                    if (reference_token == "-")
+                    {
+                        // explicitly treat "-" as index beyond the end
+                        ptr = &ptr->operator[](ptr->m_value.array->size());
+                    }
+                    else
+                    {
+                        // convert array index to number; unchecked access
+                        JSON_TRY
+                        {
+                            ptr = &ptr->operator[](
+                                static_cast<size_type>(array_index(reference_token)));
+                        }
+                        JSON_CATCH(std::invalid_argument&)
+                        {
+                            JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
+                        }
+                    }
+                    break;
+                }
+
+                default:
+                    JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
+            }
+        }
+
+        return *ptr;
+    }
+
     /*!
     @throw parse_error.106   if an array index begins with '0'
     @throw parse_error.109   if an array index was not a number
     @throw out_of_range.402  if the array index '-' is used
     @throw out_of_range.404  if the JSON pointer can not be resolved
     */
-    NLOHMANN_BASIC_JSON_TPL_DECLARATION
-    NLOHMANN_BASIC_JSON_TPL& get_checked(NLOHMANN_BASIC_JSON_TPL* ptr) const;
+    BasicJsonType& get_checked(BasicJsonType* ptr) const
+    {
+        using size_type = typename BasicJsonType::size_type;
+        for (const auto& reference_token : reference_tokens)
+        {
+            switch (ptr->m_type)
+            {
+                case detail::value_t::object:
+                {
+                    // note: at performs range check
+                    ptr = &ptr->at(reference_token);
+                    break;
+                }
 
+                case detail::value_t::array:
+                {
+                    if (JSON_UNLIKELY(reference_token == "-"))
+                    {
+                        // "-" always fails the range check
+                        JSON_THROW(detail::out_of_range::create(402,
+                                                                "array index '-' (" + std::to_string(ptr->m_value.array->size()) +
+                                                                ") is out of range"));
+                    }
+
+                    // error condition (cf. RFC 6901, Sect. 4)
+                    if (JSON_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
+                    {
+                        JSON_THROW(detail::parse_error::create(106, 0,
+                                                               "array index '" + reference_token +
+                                                               "' must not begin with '0'"));
+                    }
+
+                    // note: at performs range check
+                    JSON_TRY
+                    {
+                        ptr = &ptr->at(static_cast<size_type>(array_index(reference_token)));
+                    }
+                    JSON_CATCH(std::invalid_argument&)
+                    {
+                        JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
+                    }
+                    break;
+                }
+
+                default:
+                    JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
+            }
+        }
+
+        return *ptr;
+    }
+
     /*!
     @brief return a const reference to the pointed to value
 
@@ -7123,18 +10791,117 @@ class json_pointer
     @throw out_of_range.402  if the array index '-' is used
     @throw out_of_range.404  if the JSON pointer can not be resolved
     */
-    NLOHMANN_BASIC_JSON_TPL_DECLARATION
-    const NLOHMANN_BASIC_JSON_TPL& get_unchecked(const NLOHMANN_BASIC_JSON_TPL* ptr) const;
+    const BasicJsonType& get_unchecked(const BasicJsonType* ptr) const
+    {
+        using size_type = typename BasicJsonType::size_type;
+        for (const auto& reference_token : reference_tokens)
+        {
+            switch (ptr->m_type)
+            {
+                case detail::value_t::object:
+                {
+                    // use unchecked object access
+                    ptr = &ptr->operator[](reference_token);
+                    break;
+                }
 
+                case detail::value_t::array:
+                {
+                    if (JSON_UNLIKELY(reference_token == "-"))
+                    {
+                        // "-" cannot be used for const access
+                        JSON_THROW(detail::out_of_range::create(402,
+                                                                "array index '-' (" + std::to_string(ptr->m_value.array->size()) +
+                                                                ") is out of range"));
+                    }
+
+                    // error condition (cf. RFC 6901, Sect. 4)
+                    if (JSON_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
+                    {
+                        JSON_THROW(detail::parse_error::create(106, 0,
+                                                               "array index '" + reference_token +
+                                                               "' must not begin with '0'"));
+                    }
+
+                    // use unchecked array access
+                    JSON_TRY
+                    {
+                        ptr = &ptr->operator[](
+                            static_cast<size_type>(array_index(reference_token)));
+                    }
+                    JSON_CATCH(std::invalid_argument&)
+                    {
+                        JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
+                    }
+                    break;
+                }
+
+                default:
+                    JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
+            }
+        }
+
+        return *ptr;
+    }
+
     /*!
     @throw parse_error.106   if an array index begins with '0'
     @throw parse_error.109   if an array index was not a number
     @throw out_of_range.402  if the array index '-' is used
     @throw out_of_range.404  if the JSON pointer can not be resolved
     */
-    NLOHMANN_BASIC_JSON_TPL_DECLARATION
-    const NLOHMANN_BASIC_JSON_TPL& get_checked(const NLOHMANN_BASIC_JSON_TPL* ptr) const;
+    const BasicJsonType& get_checked(const BasicJsonType* ptr) const
+    {
+        using size_type = typename BasicJsonType::size_type;
+        for (const auto& reference_token : reference_tokens)
+        {
+            switch (ptr->m_type)
+            {
+                case detail::value_t::object:
+                {
+                    // note: at performs range check
+                    ptr = &ptr->at(reference_token);
+                    break;
+                }
 
+                case detail::value_t::array:
+                {
+                    if (JSON_UNLIKELY(reference_token == "-"))
+                    {
+                        // "-" always fails the range check
+                        JSON_THROW(detail::out_of_range::create(402,
+                                                                "array index '-' (" + std::to_string(ptr->m_value.array->size()) +
+                                                                ") is out of range"));
+                    }
+
+                    // error condition (cf. RFC 6901, Sect. 4)
+                    if (JSON_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
+                    {
+                        JSON_THROW(detail::parse_error::create(106, 0,
+                                                               "array index '" + reference_token +
+                                                               "' must not begin with '0'"));
+                    }
+
+                    // note: at performs range check
+                    JSON_TRY
+                    {
+                        ptr = &ptr->at(static_cast<size_type>(array_index(reference_token)));
+                    }
+                    JSON_CATCH(std::invalid_argument&)
+                    {
+                        JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
+                    }
+                    break;
+                }
+
+                default:
+                    JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
+            }
+        }
+
+        return *ptr;
+    }
+
     /*!
     @brief split the string input to reference tokens
 
@@ -7252,11 +11019,58 @@ class json_pointer
 
     @note Empty objects or arrays are flattened to `null`.
     */
-    NLOHMANN_BASIC_JSON_TPL_DECLARATION
     static void flatten(const std::string& reference_string,
-                        const NLOHMANN_BASIC_JSON_TPL& value,
-                        NLOHMANN_BASIC_JSON_TPL& result);
+                        const BasicJsonType& value,
+                        BasicJsonType& result)
+    {
+        switch (value.m_type)
+        {
+            case detail::value_t::array:
+            {
+                if (value.m_value.array->empty())
+                {
+                    // flatten empty array as null
+                    result[reference_string] = nullptr;
+                }
+                else
+                {
+                    // iterate array and use index as reference string
+                    for (std::size_t i = 0; i < value.m_value.array->size(); ++i)
+                    {
+                        flatten(reference_string + "/" + std::to_string(i),
+                                value.m_value.array->operator[](i), result);
+                    }
+                }
+                break;
+            }
 
+            case detail::value_t::object:
+            {
+                if (value.m_value.object->empty())
+                {
+                    // flatten empty object as null
+                    result[reference_string] = nullptr;
+                }
+                else
+                {
+                    // iterate object and use keys as reference string
+                    for (const auto& element : *value.m_value.object)
+                    {
+                        flatten(reference_string + "/" + escape(element.first), element.second, result);
+                    }
+                }
+                break;
+            }
+
+            default:
+            {
+                // add primitive value with its reference string
+                result[reference_string] = value;
+                break;
+            }
+        }
+    }
+
     /*!
     @param[in] value  flattened JSON
 
@@ -7267,21 +11081,110 @@ class json_pointer
     @throw type_error.315  if object values are not primitive
     @throw type_error.313  if value cannot be unflattened
     */
-    NLOHMANN_BASIC_JSON_TPL_DECLARATION
-    static NLOHMANN_BASIC_JSON_TPL
-    unflatten(const NLOHMANN_BASIC_JSON_TPL& value);
+    static BasicJsonType
+    unflatten(const BasicJsonType& value)
+    {
+        if (JSON_UNLIKELY(not value.is_object()))
+        {
+            JSON_THROW(detail::type_error::create(314, "only objects can be unflattened"));
+        }
 
+        BasicJsonType result;
+
+        // iterate the JSON object values
+        for (const auto& element : *value.m_value.object)
+        {
+            if (JSON_UNLIKELY(not element.second.is_primitive()))
+            {
+                JSON_THROW(detail::type_error::create(315, "values in object must be primitive"));
+            }
+
+            // assign value to reference pointed to by JSON pointer; Note that if
+            // the JSON pointer is "" (i.e., points to the whole value), function
+            // get_and_create returns a reference to result itself. An assignment
+            // will then create a primitive value.
+            json_pointer(element.first).get_and_create(result) = element.second;
+        }
+
+        return result;
+    }
+
     friend bool operator==(json_pointer const& lhs,
-                           json_pointer const& rhs) noexcept;
+                           json_pointer const& rhs) noexcept
+    {
+        return (lhs.reference_tokens == rhs.reference_tokens);
+    }
 
     friend bool operator!=(json_pointer const& lhs,
-                           json_pointer const& rhs) noexcept;
+                           json_pointer const& rhs) noexcept
+    {
+        return not (lhs == rhs);
+    }
 
     /// the reference tokens
     std::vector<std::string> reference_tokens;
 };
+}
 
+// #include <nlohmann/adl_serializer.hpp>
+
+
+#include <utility>
+
+// #include <nlohmann/detail/conversions/from_json.hpp>
+
+// #include <nlohmann/detail/conversions/to_json.hpp>
+
+
+namespace nlohmann
+{
+template<typename, typename>
+struct adl_serializer
+{
+    /*!
+    @brief convert a JSON value to any value type
+
+    This function is usually called by the `get()` function of the
+    @ref basic_json class (either explicit or via conversion operators).
+
+    @param[in] j         JSON value to read from
+    @param[in,out] val  value to write to
+    */
+    template<typename BasicJsonType, typename ValueType>
+    static void from_json(BasicJsonType&& j, ValueType& val) noexcept(
+        noexcept(::nlohmann::from_json(std::forward<BasicJsonType>(j), val)))
+    {
+        ::nlohmann::from_json(std::forward<BasicJsonType>(j), val);
+    }
+
+    /*!
+    @brief convert any value type to a JSON value
+
+    This function is usually called by the constructors of the @ref basic_json
+    class.
+
+    @param[in,out] j  JSON value to write to
+    @param[in] val     value to read from
+    */
+    template<typename BasicJsonType, typename ValueType>
+    static void to_json(BasicJsonType& j, ValueType&& val) noexcept(
+        noexcept(::nlohmann::to_json(j, std::forward<ValueType>(val))))
+    {
+        ::nlohmann::to_json(j, std::forward<ValueType>(val));
+    }
+};
+}
+
+
 /*!
+@brief namespace for Niels Lohmann
+@see https://github.com/nlohmann
+@since version 1.0.0
+*/
+namespace nlohmann
+{
+
+/*!
 @brief a class to store JSON values
 
 @tparam ObjectType type for JSON objects (`std::map` by default; will be used
@@ -7305,42 +11208,42 @@ and `from_json()` (@ref adl_serializer by default)
 
 @requirement The class satisfies the following concept requirements:
 - Basic
- - [DefaultConstructible](http://en.cppreference.com/w/cpp/concept/DefaultConstructible):
+ - [DefaultConstructible](https://en.cppreference.com/w/cpp/named_req/DefaultConstructible):
    JSON values can be default constructed. The result will be a JSON null
    value.
- - [MoveConstructible](http://en.cppreference.com/w/cpp/concept/MoveConstructible):
+ - [MoveConstructible](https://en.cppreference.com/w/cpp/named_req/MoveConstructible):
    A JSON value can be constructed from an rvalue argument.
- - [CopyConstructible](http://en.cppreference.com/w/cpp/concept/CopyConstructible):
+ - [CopyConstructible](https://en.cppreference.com/w/cpp/named_req/CopyConstructible):
    A JSON value can be copy-constructed from an lvalue expression.
- - [MoveAssignable](http://en.cppreference.com/w/cpp/concept/MoveAssignable):
+ - [MoveAssignable](https://en.cppreference.com/w/cpp/named_req/MoveAssignable):
    A JSON value van be assigned from an rvalue argument.
- - [CopyAssignable](http://en.cppreference.com/w/cpp/concept/CopyAssignable):
+ - [CopyAssignable](https://en.cppreference.com/w/cpp/named_req/CopyAssignable):
    A JSON value can be copy-assigned from an lvalue expression.
- - [Destructible](http://en.cppreference.com/w/cpp/concept/Destructible):
+ - [Destructible](https://en.cppreference.com/w/cpp/named_req/Destructible):
    JSON values can be destructed.
 - Layout
- - [StandardLayoutType](http://en.cppreference.com/w/cpp/concept/StandardLayoutType):
+ - [StandardLayoutType](https://en.cppreference.com/w/cpp/named_req/StandardLayoutType):
    JSON values have
-   [standard layout](http://en.cppreference.com/w/cpp/language/data_members#Standard_layout):
+   [standard layout](https://en.cppreference.com/w/cpp/language/data_members#Standard_layout):
    All non-static data members are private and standard layout types, the
    class has no virtual functions or (virtual) base classes.
 - Library-wide
- - [EqualityComparable](http://en.cppreference.com/w/cpp/concept/EqualityComparable):
+ - [EqualityComparable](https://en.cppreference.com/w/cpp/named_req/EqualityComparable):
    JSON values can be compared with `==`, see @ref
    operator==(const_reference,const_reference).
- - [LessThanComparable](http://en.cppreference.com/w/cpp/concept/LessThanComparable):
+ - [LessThanComparable](https://en.cppreference.com/w/cpp/named_req/LessThanComparable):
    JSON values can be compared with `<`, see @ref
    operator<(const_reference,const_reference).
- - [Swappable](http://en.cppreference.com/w/cpp/concept/Swappable):
+ - [Swappable](https://en.cppreference.com/w/cpp/named_req/Swappable):
    Any JSON lvalue or rvalue of can be swapped with any lvalue or rvalue of
    other compatible types, using unqualified function call @ref swap().
- - [NullablePointer](http://en.cppreference.com/w/cpp/concept/NullablePointer):
+ - [NullablePointer](https://en.cppreference.com/w/cpp/named_req/NullablePointer):
    JSON values can be compared against `std::nullptr_t` objects which are used
    to model the `null` value.
 - Container
- - [Container](http://en.cppreference.com/w/cpp/concept/Container):
+ - [Container](https://en.cppreference.com/w/cpp/named_req/Container):
    JSON values can be used like STL containers and provide iterator access.
- - [ReversibleContainer](http://en.cppreference.com/w/cpp/concept/ReversibleContainer);
+ - [ReversibleContainer](https://en.cppreference.com/w/cpp/named_req/ReversibleContainer);
    JSON values can be used like STL containers and provide reverse iterator
    access.
 
@@ -7367,15 +11270,19 @@ class basic_json
 {
   private:
     template<detail::value_t> friend struct detail::external_constructor;
-    friend ::nlohmann::json_pointer;
+    friend ::nlohmann::json_pointer<basic_json>;
     friend ::nlohmann::detail::parser<basic_json>;
     friend ::nlohmann::detail::serializer<basic_json>;
     template<typename BasicJsonType>
     friend class ::nlohmann::detail::iter_impl;
     template<typename BasicJsonType, typename CharType>
     friend class ::nlohmann::detail::binary_writer;
-    template<typename BasicJsonType>
+    template<typename BasicJsonType, typename SAX>
     friend class ::nlohmann::detail::binary_reader;
+    template<typename BasicJsonType>
+    friend class ::nlohmann::detail::json_sax_dom_parser;
+    template<typename BasicJsonType>
+    friend class ::nlohmann::detail::json_sax_dom_callback_parser;
 
     /// workaround type for MSVC
     using basic_json_t = NLOHMANN_BASIC_JSON_TPL;
@@ -7403,13 +11310,17 @@ class basic_json
 
   public:
     using value_t = detail::value_t;
-    /// @copydoc nlohmann::json_pointer
-    using json_pointer = ::nlohmann::json_pointer;
+    /// JSON Pointer, see @ref nlohmann::json_pointer
+    using json_pointer = ::nlohmann::json_pointer<basic_json>;
     template<typename T, typename SFINAE>
     using json_serializer = JSONSerializer<T, SFINAE>;
     /// helper type for initializer lists of basic_json values
     using initializer_list_t = std::initializer_list<detail::json_ref<basic_json>>;
 
+    using input_format_t = detail::input_format_t;
+    /// SAX interface type, see @ref nlohmann::json_sax
+    using json_sax_t = json_sax<basic_json>;
+
     ////////////////
     // exceptions //
     ////////////////
@@ -7517,10 +11428,13 @@ class basic_json
         result["copyright"] = "(C) 2013-2017 Niels Lohmann";
         result["name"] = "JSON for Modern C++";
         result["url"] = "https://github.com/nlohmann/json";
-        result["version"] =
-        {
-            {"string", "3.0.1"}, {"major", 3}, {"minor", 0}, {"patch", 1}
-        };
+        result["version"]["string"] =
+            std::to_string(NLOHMANN_JSON_VERSION_MAJOR) + "." +
+            std::to_string(NLOHMANN_JSON_VERSION_MINOR) + "." +
+            std::to_string(NLOHMANN_JSON_VERSION_PATCH);
+        result["version"]["major"] = NLOHMANN_JSON_VERSION_MAJOR;
+        result["version"]["minor"] = NLOHMANN_JSON_VERSION_MINOR;
+        result["version"]["patch"] = NLOHMANN_JSON_VERSION_PATCH;
 
 #ifdef _WIN32
         result["platform"] = "win32";
@@ -7622,10 +11536,10 @@ class basic_json
     - When all names are unique, objects will be interoperable in the sense
       that all software implementations receiving that object will agree on
       the name-value mappings.
-    - When the names within an object are not unique, later stored name/value
-      pairs overwrite previously stored name/value pairs, leaving the used
-      names unique. For instance, `{"key": 1}` and `{"key": 2, "key": 1}` will
-      be treated as equal and both stored as `{"key": 1}`.
+    - When the names within an object are not unique, it is unspecified which
+      one of the values for a given key will be chosen. For instance,
+      `{"key": 2, "key": 1}` could be equal to either `{"key": 1}` or
+      `{"key": 2}`.
     - Internally, name/value pairs are stored in lexicographical order of the
       names. Objects will also be serialized (see @ref dump) in this order.
       For instance, `{"b": 1, "a": 2}` and `{"a": 2, "b": 1}` will be stored
@@ -8139,7 +12053,7 @@ class basic_json
                     object = nullptr;  // silence warning, see #821
                     if (JSON_UNLIKELY(t == value_t::null))
                     {
-                        JSON_THROW(other_error::create(500, "961c151d2e87f2686a955a9be24d316f1362bf21 3.0.1")); // LCOV_EXCL_LINE
+                        JSON_THROW(other_error::create(500, "961c151d2e87f2686a955a9be24d316f1362bf21 3.2.0")); // LCOV_EXCL_LINE
                     }
                     break;
                 }
@@ -8182,7 +12096,7 @@ class basic_json
             array = create<array_t>(std::move(value));
         }
 
-        void destroy(value_t t)
+        void destroy(value_t t) noexcept
         {
             switch (t)
             {
@@ -8227,7 +12141,7 @@ class basic_json
     value is changed, because the invariant expresses a relationship between
     @a m_type and @a m_value.
     */
-    void assert_invariant() const
+    void assert_invariant() const noexcept
     {
         assert(m_type != value_t::object or m_value.object != nullptr);
         assert(m_type != value_t::array or m_value.array != nullptr);
@@ -8307,7 +12221,6 @@ class basic_json
     */
     using parser_callback_t = typename parser::parser_callback_t;
 
-
     //////////////////
     // constructors //
     //////////////////
@@ -8409,6 +12322,7 @@ class basic_json
     - @a CompatibleType is not derived from `std::istream`,
     - @a CompatibleType is not @ref basic_json (to avoid hijacking copy/move
          constructors),
+    - @a CompatibleType is not a different @ref basic_json type (i.e. with different template arguments)
     - @a CompatibleType is not a @ref basic_json nested type (e.g.,
          @ref json_pointer, @ref iterator, etc ...)
     - @ref @ref json_serializer<U> has a
@@ -8432,21 +12346,91 @@ class basic_json
 
     @since version 2.1.0
     */
-    template<typename CompatibleType, typename U = detail::uncvref_t<CompatibleType>,
-             detail::enable_if_t<not std::is_base_of<std::istream, U>::value and
-                                 not std::is_same<U, basic_json_t>::value and
-                                 not detail::is_basic_json_nested_type<
-                                     basic_json_t, U>::value and
-                                 detail::has_to_json<basic_json, U>::value,
-                                 int> = 0>
-    basic_json(CompatibleType && val) noexcept(noexcept(JSONSerializer<U>::to_json(
-                std::declval<basic_json_t&>(), std::forward<CompatibleType>(val))))
+    template <typename CompatibleType,
+              typename U = detail::uncvref_t<CompatibleType>,
+              detail::enable_if_t<
+                  detail::is_compatible_type<basic_json_t, U>::value, int> = 0>
+    basic_json(CompatibleType && val) noexcept(noexcept(
+                JSONSerializer<U>::to_json(std::declval<basic_json_t&>(),
+                                           std::forward<CompatibleType>(val))))
     {
         JSONSerializer<U>::to_json(*this, std::forward<CompatibleType>(val));
         assert_invariant();
     }
 
     /*!
+    @brief create a JSON value from an existing one
+
+    This is a constructor for existing @ref basic_json types.
+    It does not hijack copy/move constructors, since the parameter has different
+    template arguments than the current ones.
+
+    The constructor tries to convert the internal @ref m_value of the parameter.
+
+    @tparam BasicJsonType a type such that:
+    - @a BasicJsonType is a @ref basic_json type.
+    - @a BasicJsonType has different template arguments than @ref basic_json_t.
+
+    @param[in] val the @ref basic_json value to be converted.
+
+    @complexity Usually linear in the size of the passed @a val, also
+                depending on the implementation of the called `to_json()`
+                method.
+
+    @exceptionsafety Depends on the called constructor. For types directly
+    supported by the library (i.e., all types for which no `to_json()` function
+    was provided), strong guarantee holds: if an exception is thrown, there are
+    no changes to any JSON value.
+
+    @since version 3.2.0
+    */
+    template <typename BasicJsonType,
+              detail::enable_if_t<
+                  detail::is_basic_json<BasicJsonType>::value and not std::is_same<basic_json, BasicJsonType>::value, int> = 0>
+    basic_json(const BasicJsonType& val)
+    {
+        using other_boolean_t = typename BasicJsonType::boolean_t;
+        using other_number_float_t = typename BasicJsonType::number_float_t;
+        using other_number_integer_t = typename BasicJsonType::number_integer_t;
+        using other_number_unsigned_t = typename BasicJsonType::number_unsigned_t;
+        using other_string_t = typename BasicJsonType::string_t;
+        using other_object_t = typename BasicJsonType::object_t;
+        using other_array_t = typename BasicJsonType::array_t;
+
+        switch (val.type())
+        {
+            case value_t::boolean:
+                JSONSerializer<other_boolean_t>::to_json(*this, val.template get<other_boolean_t>());
+                break;
+            case value_t::number_float:
+                JSONSerializer<other_number_float_t>::to_json(*this, val.template get<other_number_float_t>());
+                break;
+            case value_t::number_integer:
+                JSONSerializer<other_number_integer_t>::to_json(*this, val.template get<other_number_integer_t>());
+                break;
+            case value_t::number_unsigned:
+                JSONSerializer<other_number_unsigned_t>::to_json(*this, val.template get<other_number_unsigned_t>());
+                break;
+            case value_t::string:
+                JSONSerializer<other_string_t>::to_json(*this, val.template get_ref<const other_string_t&>());
+                break;
+            case value_t::object:
+                JSONSerializer<other_object_t>::to_json(*this, val.template get_ref<const other_object_t&>());
+                break;
+            case value_t::array:
+                JSONSerializer<other_array_t>::to_json(*this, val.template get_ref<const other_array_t&>());
+                break;
+            case value_t::null:
+                *this = nullptr;
+                break;
+            case value_t::discarded:
+                m_type = value_t::discarded;
+                break;
+        }
+        assert_invariant();
+    }
+
+    /*!
     @brief create a container (array or object) from an initializer list
 
     Creates a JSON value of type array or object from the passed initializer
@@ -8718,7 +12702,7 @@ class basic_json
     @warning A precondition is enforced with a runtime assertion that will
              result in calling `std::abort` if this precondition is not met.
              Assertions can be disabled by defining `NDEBUG` at compile time.
-             See http://en.cppreference.com/w/cpp/error/assert for more
+             See https://en.cppreference.com/w/cpp/error/assert for more
              information.
 
     @throw invalid_iterator.201 if iterators @a first and @a last are not
@@ -8858,7 +12842,7 @@ class basic_json
     changes to any JSON value.
 
     @requirement This function helps `basic_json` satisfying the
-    [Container](http://en.cppreference.com/w/cpp/concept/Container)
+    [Container](https://en.cppreference.com/w/cpp/named_req/Container)
     requirements:
     - The complexity is linear.
     - As postcondition, it holds: `other == basic_json(other)`.
@@ -8943,7 +12927,7 @@ class basic_json
     exceptions.
 
     @requirement This function helps `basic_json` satisfying the
-    [MoveConstructible](http://en.cppreference.com/w/cpp/concept/MoveConstructible)
+    [MoveConstructible](https://en.cppreference.com/w/cpp/named_req/MoveConstructible)
     requirements.
 
     @liveexample{The code below shows the move constructor explicitly called
@@ -8977,7 +12961,7 @@ class basic_json
     @complexity Linear.
 
     @requirement This function helps `basic_json` satisfying the
-    [Container](http://en.cppreference.com/w/cpp/concept/Container)
+    [Container](https://en.cppreference.com/w/cpp/named_req/Container)
     requirements:
     - The complexity is linear.
 
@@ -9014,14 +12998,14 @@ class basic_json
     @complexity Linear.
 
     @requirement This function helps `basic_json` satisfying the
-    [Container](http://en.cppreference.com/w/cpp/concept/Container)
+    [Container](https://en.cppreference.com/w/cpp/named_req/Container)
     requirements:
     - The complexity is linear.
     - All stored elements are destroyed and all memory is freed.
 
     @since version 1.0.0
     */
-    ~basic_json()
+    ~basic_json() noexcept
     {
         assert_invariant();
         m_value.destroy(m_type);
@@ -9078,7 +13062,7 @@ class basic_json
                   const bool ensure_ascii = false) const
     {
         string_t result;
-        serializer s(detail::output_adapter<char>(result), indent_char);
+        serializer s(detail::output_adapter<char, string_t>(result), indent_char);
 
         if (indent >= 0)
         {
@@ -9619,11 +13603,34 @@ class basic_json
     }
 
     /*!
+    @brief get special-case overload
+
+    This overloads converts the current @ref basic_json in a different
+    @ref basic_json type
+
+    @tparam BasicJsonType == @ref basic_json
+
+    @return a copy of *this, converted into @tparam BasicJsonType
+
+    @complexity Depending on the implementation of the called `from_json()`
+                method.
+
+    @since version 3.2.0
+    */
+    template<typename BasicJsonType, detail::enable_if_t<
+                 not std::is_same<BasicJsonType, basic_json>::value and
+                 detail::is_basic_json<BasicJsonType>::value, int> = 0>
+    BasicJsonType get() const
+    {
+        return *this;
+    }
+
+    /*!
     @brief get a value (explicit)
 
     Explicit type conversion between the JSON value and a compatible value
-    which is [CopyConstructible](http://en.cppreference.com/w/cpp/concept/CopyConstructible)
-    and [DefaultConstructible](http://en.cppreference.com/w/cpp/concept/DefaultConstructible).
+    which is [CopyConstructible](https://en.cppreference.com/w/cpp/named_req/CopyConstructible)
+    and [DefaultConstructible](https://en.cppreference.com/w/cpp/named_req/DefaultConstructible).
     The value is converted by calling the @ref json_serializer<ValueType>
     `from_json()` method.
 
@@ -9659,7 +13666,7 @@ class basic_json
     */
     template<typename ValueTypeCV, typename ValueType = detail::uncvref_t<ValueTypeCV>,
              detail::enable_if_t <
-                 not std::is_same<basic_json_t, ValueType>::value and
+                 not detail::is_basic_json<ValueType>::value and
                  detail::has_from_json<basic_json_t, ValueType>::value and
                  not detail::has_non_default_from_json<basic_json_t, ValueType>::value,
                  int> = 0>
@@ -9683,8 +13690,8 @@ class basic_json
     @brief get a value (explicit); special case
 
     Explicit type conversion between the JSON value and a compatible value
-    which is **not** [CopyConstructible](http://en.cppreference.com/w/cpp/concept/CopyConstructible)
-    and **not** [DefaultConstructible](http://en.cppreference.com/w/cpp/concept/DefaultConstructible).
+    which is **not** [CopyConstructible](https://en.cppreference.com/w/cpp/named_req/CopyConstructible)
+    and **not** [DefaultConstructible](https://en.cppreference.com/w/cpp/named_req/DefaultConstructible).
     The value is converted by calling the @ref json_serializer<ValueType>
     `from_json()` method.
 
@@ -9925,13 +13932,14 @@ class basic_json
     template < typename ValueType, typename std::enable_if <
                    not std::is_pointer<ValueType>::value and
                    not std::is_same<ValueType, detail::json_ref<basic_json>>::value and
-                   not std::is_same<ValueType, typename string_t::value_type>::value
+                   not std::is_same<ValueType, typename string_t::value_type>::value and
+                   not detail::is_basic_json<ValueType>::value
 #ifndef _MSC_VER  // fix for issue #167 operator<< ambiguity under VS2015
                    and not std::is_same<ValueType, std::initializer_list<typename string_t::value_type>>::value
-#endif
-#if defined(JSON_HAS_CPP_17)
+#if defined(JSON_HAS_CPP_17) && defined(_MSC_VER) and _MSC_VER <= 1914
                    and not std::is_same<ValueType, typename std::string_view>::value
 #endif
+#endif
                    , int >::type = 0 >
     operator ValueType() const
     {
@@ -10512,7 +14520,7 @@ class basic_json
     @return copy of the element at key @a key or @a default_value if @a key
     is not found
 
-    @throw type_error.306 if the JSON value is not an objec; in that case,
+    @throw type_error.306 if the JSON value is not an object; in that case,
     using `value()` with a key makes no sense.
 
     @complexity Logarithmic in the size of the container.
@@ -10536,7 +14544,7 @@ class basic_json
             {
                 return ptr.get_checked(this);
             }
-            JSON_CATCH (out_of_range&)
+            JSON_INTERNAL_CATCH (out_of_range&)
             {
                 return default_value;
             }
@@ -11047,7 +15055,7 @@ class basic_json
     @complexity Constant.
 
     @requirement This function helps `basic_json` satisfying the
-    [Container](http://en.cppreference.com/w/cpp/concept/Container)
+    [Container](https://en.cppreference.com/w/cpp/named_req/Container)
     requirements:
     - The complexity is constant.
 
@@ -11086,7 +15094,7 @@ class basic_json
     @complexity Constant.
 
     @requirement This function helps `basic_json` satisfying the
-    [Container](http://en.cppreference.com/w/cpp/concept/Container)
+    [Container](https://en.cppreference.com/w/cpp/named_req/Container)
     requirements:
     - The complexity is constant.
     - Has the semantics of `const_cast<const basic_json&>(*this).begin()`.
@@ -11118,7 +15126,7 @@ class basic_json
     @complexity Constant.
 
     @requirement This function helps `basic_json` satisfying the
-    [Container](http://en.cppreference.com/w/cpp/concept/Container)
+    [Container](https://en.cppreference.com/w/cpp/named_req/Container)
     requirements:
     - The complexity is constant.
 
@@ -11157,7 +15165,7 @@ class basic_json
     @complexity Constant.
 
     @requirement This function helps `basic_json` satisfying the
-    [Container](http://en.cppreference.com/w/cpp/concept/Container)
+    [Container](https://en.cppreference.com/w/cpp/named_req/Container)
     requirements:
     - The complexity is constant.
     - Has the semantics of `const_cast<const basic_json&>(*this).end()`.
@@ -11187,7 +15195,7 @@ class basic_json
     @complexity Constant.
 
     @requirement This function helps `basic_json` satisfying the
-    [ReversibleContainer](http://en.cppreference.com/w/cpp/concept/ReversibleContainer)
+    [ReversibleContainer](https://en.cppreference.com/w/cpp/named_req/ReversibleContainer)
     requirements:
     - The complexity is constant.
     - Has the semantics of `reverse_iterator(end())`.
@@ -11224,7 +15232,7 @@ class basic_json
     @complexity Constant.
 
     @requirement This function helps `basic_json` satisfying the
-    [ReversibleContainer](http://en.cppreference.com/w/cpp/concept/ReversibleContainer)
+    [ReversibleContainer](https://en.cppreference.com/w/cpp/named_req/ReversibleContainer)
     requirements:
     - The complexity is constant.
     - Has the semantics of `reverse_iterator(begin())`.
@@ -11261,7 +15269,7 @@ class basic_json
     @complexity Constant.
 
     @requirement This function helps `basic_json` satisfying the
-    [ReversibleContainer](http://en.cppreference.com/w/cpp/concept/ReversibleContainer)
+    [ReversibleContainer](https://en.cppreference.com/w/cpp/named_req/ReversibleContainer)
     requirements:
     - The complexity is constant.
     - Has the semantics of `const_cast<const basic_json&>(*this).rbegin()`.
@@ -11290,7 +15298,7 @@ class basic_json
     @complexity Constant.
 
     @requirement This function helps `basic_json` satisfying the
-    [ReversibleContainer](http://en.cppreference.com/w/cpp/concept/ReversibleContainer)
+    [ReversibleContainer](https://en.cppreference.com/w/cpp/named_req/ReversibleContainer)
     requirements:
     - The complexity is constant.
     - Has the semantics of `const_cast<const basic_json&>(*this).rend()`.
@@ -11361,20 +15369,91 @@ class basic_json
 
     @note The name of this function is not yet final and may change in the
     future.
+
+    @deprecated This stream operator is deprecated and will be removed in
+                future 4.0.0 of the library. Please use @ref items() instead;
+                that is, replace `json::iterator_wrapper(j)` with `j.items()`.
     */
-    static iteration_proxy<iterator> iterator_wrapper(reference ref)
+    JSON_DEPRECATED
+    static iteration_proxy<iterator> iterator_wrapper(reference ref) noexcept
     {
-        return iteration_proxy<iterator>(ref);
+        return ref.items();
     }
 
     /*!
     @copydoc iterator_wrapper(reference)
     */
-    static iteration_proxy<const_iterator> iterator_wrapper(const_reference ref)
+    JSON_DEPRECATED
+    static iteration_proxy<const_iterator> iterator_wrapper(const_reference ref) noexcept
     {
-        return iteration_proxy<const_iterator>(ref);
+        return ref.items();
     }
 
+    /*!
+    @brief helper to access iterator member functions in range-based for
+
+    This function allows to access @ref iterator::key() and @ref
+    iterator::value() during range-based for loops. In these loops, a
+    reference to the JSON values is returned, so there is no access to the
+    underlying iterator.
+
+    For loop without `items()` function:
+
+    @code{cpp}
+    for (auto it = j_object.begin(); it != j_object.end(); ++it)
+    {
+        std::cout << "key: " << it.key() << ", value:" << it.value() << '\n';
+    }
+    @endcode
+
+    Range-based for loop without `items()` function:
+
+    @code{cpp}
+    for (auto it : j_object)
+    {
+        // "it" is of type json::reference and has no key() member
+        std::cout << "value: " << it << '\n';
+    }
+    @endcode
+
+    Range-based for loop with `items()` function:
+
+    @code{cpp}
+    for (auto it : j_object.items())
+    {
+        std::cout << "key: " << it.key() << ", value:" << it.value() << '\n';
+    }
+    @endcode
+
+    @note When iterating over an array, `key()` will return the index of the
+          element as string (see example). For primitive types (e.g., numbers),
+          `key()` returns an empty string.
+
+    @return iteration proxy object wrapping @a ref with an interface to use in
+            range-based for loops
+
+    @liveexample{The following code shows how the function is used.,items}
+
+    @exceptionsafety Strong guarantee: if an exception is thrown, there are no
+    changes in the JSON value.
+
+    @complexity Constant.
+
+    @since version 3.1.0.
+    */
+    iteration_proxy<iterator> items() noexcept
+    {
+        return iteration_proxy<iterator>(*this);
+    }
+
+    /*!
+    @copydoc items()
+    */
+    iteration_proxy<const_iterator> items() const noexcept
+    {
+        return iteration_proxy<const_iterator>(*this);
+    }
+
     /// @}
 
 
@@ -11417,7 +15496,7 @@ class basic_json
     false in the case of a string.
 
     @requirement This function helps `basic_json` satisfying the
-    [Container](http://en.cppreference.com/w/cpp/concept/Container)
+    [Container](https://en.cppreference.com/w/cpp/named_req/Container)
     requirements:
     - The complexity is constant.
     - Has the semantics of `begin() == end()`.
@@ -11488,7 +15567,7 @@ class basic_json
     the case of a string.
 
     @requirement This function helps `basic_json` satisfying the
-    [Container](http://en.cppreference.com/w/cpp/concept/Container)
+    [Container](https://en.cppreference.com/w/cpp/named_req/Container)
     requirements:
     - The complexity is constant.
     - Has the semantics of `std::distance(begin(), end())`.
@@ -11558,7 +15637,7 @@ class basic_json
     @exceptionsafety No-throw guarantee: this function never throws exceptions.
 
     @requirement This function helps `basic_json` satisfying the
-    [Container](http://en.cppreference.com/w/cpp/concept/Container)
+    [Container](https://en.cppreference.com/w/cpp/named_req/Container)
     requirements:
     - The complexity is constant.
     - Has the semantics of returning `b.size()` where `b` is the largest
@@ -12312,7 +16391,7 @@ class basic_json
 
         // passed iterators must belong to objects
         if (JSON_UNLIKELY(not first.m_object->is_object()
-                          or not first.m_object->is_object()))
+                          or not last.m_object->is_object()))
         {
             JSON_THROW(invalid_iterator::create(202, "iterators first and last must point to objects"));
         }
@@ -12943,8 +17022,8 @@ class basic_json
 
     /*!
     @brief serialize to stream
-    @deprecated This stream operator is deprecated and will be removed in a
-                future version of the library. Please use
+    @deprecated This stream operator is deprecated and will be removed in
+                future 4.0.0 of the library. Please use
                 @ref operator<<(std::ostream&, const basic_json&)
                 instead; that is, replace calls like `j >> o;` with `o << j;`.
     @since version 1.0.0; deprecated since version 3.0.0
@@ -13027,7 +17106,7 @@ class basic_json
 
     @since version 2.0.3 (contiguous containers)
     */
-    static basic_json parse(detail::input_adapter i,
+    static basic_json parse(detail::input_adapter&& i,
                             const parser_callback_t cb = nullptr,
                             const bool allow_exceptions = true)
     {
@@ -13036,26 +17115,80 @@ class basic_json
         return result;
     }
 
-    /*!
-    @copydoc basic_json parse(detail::input_adapter, const parser_callback_t)
-    */
-    static basic_json parse(detail::input_adapter& i,
-                            const parser_callback_t cb = nullptr,
-                            const bool allow_exceptions = true)
+    static bool accept(detail::input_adapter&& i)
     {
-        basic_json result;
-        parser(i, cb, allow_exceptions).parse(true, result);
-        return result;
-    }
-
-    static bool accept(detail::input_adapter i)
-    {
         return parser(i).accept(true);
     }
 
-    static bool accept(detail::input_adapter& i)
+    /*!
+    @brief generate SAX events
+
+    The SAX event lister must follow the interface of @ref json_sax.
+
+    This function reads from a compatible input. Examples are:
+    - an array of 1-byte values
+    - strings with character/literal type with size of 1 byte
+    - input streams
+    - container with contiguous storage of 1-byte values. Compatible container
+      types include `std::vector`, `std::string`, `std::array`,
+      `std::valarray`, and `std::initializer_list`. Furthermore, C-style
+      arrays can be used with `std::begin()`/`std::end()`. User-defined
+      containers can be used as long as they implement random-access iterators
+      and a contiguous storage.
+
+    @pre Each element of the container has a size of 1 byte. Violating this
+    precondition yields undefined behavior. **This precondition is enforced
+    with a static assertion.**
+
+    @pre The container storage is contiguous. Violating this precondition
+    yields undefined behavior. **This precondition is enforced with an
+    assertion.**
+    @pre Each element of the container has a size of 1 byte. Violating this
+    precondition yields undefined behavior. **This precondition is enforced
+    with a static assertion.**
+
+    @warning There is no way to enforce all preconditions at compile-time. If
+             the function is called with a noncompliant container and with
+             assertions switched off, the behavior is undefined and will most
+             likely yield segmentation violation.
+
+    @param[in] i  input to read from
+    @param[in,out] sax  SAX event listener
+    @param[in] format  the format to parse (JSON, CBOR, MessagePack, or UBJSON)
+    @param[in] strict  whether the input has to be consumed completely
+
+    @return return value of the last processed SAX event
+
+    @throw parse_error.101 if a parse error occurs; example: `""unexpected end
+    of input; expected string literal""`
+    @throw parse_error.102 if to_unicode fails or surrogate error
+    @throw parse_error.103 if to_unicode fails
+
+    @complexity Linear in the length of the input. The parser is a predictive
+    LL(1) parser. The complexity can be higher if the SAX consumer @a sax has
+    a super-linear complexity.
+
+    @note A UTF-8 byte order mark is silently ignored.
+
+    @liveexample{The example below demonstrates the `sax_parse()` function
+    reading from string and processing the events with a user-defined SAX
+    event consumer.,sax_parse}
+
+    @since version 3.2.0
+    */
+    template <typename SAX>
+    static bool sax_parse(detail::input_adapter&& i, SAX* sax,
+                          input_format_t format = input_format_t::json,
+                          const bool strict = true)
     {
-        return parser(i).accept(true);
+        assert(sax);
+        switch (format)
+        {
+            case input_format_t::json:
+                return parser(std::move(i)).sax_parse(sax, strict);
+            default:
+                return detail::binary_reader<basic_json, SAX>(std::move(i)).sax_parse(format, sax, strict);
+        }
     }
 
     /*!
@@ -13127,10 +17260,19 @@ class basic_json
         return parser(detail::input_adapter(first, last)).accept(true);
     }
 
+    template<class IteratorType, class SAX, typename std::enable_if<
+                 std::is_base_of<
+                     std::random_access_iterator_tag,
+                     typename std::iterator_traits<IteratorType>::iterator_category>::value, int>::type = 0>
+    static bool sax_parse(IteratorType first, IteratorType last, SAX* sax)
+    {
+        return parser(detail::input_adapter(first, last)).sax_parse(sax);
+    }
+
     /*!
     @brief deserialize from stream
-    @deprecated This stream operator is deprecated and will be removed in a
-                future version of the library. Please use
+    @deprecated This stream operator is deprecated and will be removed in
+                version 4.0.0 of the library. Please use
                 @ref operator>>(std::istream&, basic_json&)
                 instead; that is, replace calls like `j << i;` with `i >> j;`.
     @since version 1.0.0; deprecated since version 3.0.0
@@ -13331,9 +17473,11 @@ class basic_json
     vector in CBOR format.,to_cbor}
 
     @sa http://cbor.io
-    @sa @ref from_cbor(const std::vector<uint8_t>&, const size_t) for the
+    @sa @ref from_cbor(detail::input_adapter, const bool strict) for the
         analogous deserialization
     @sa @ref to_msgpack(const basic_json&) for the related MessagePack format
+    @sa @ref to_ubjson(const basic_json&, const bool, const bool) for the
+             related UBJSON format
 
     @since version 2.0.9
     */
@@ -13429,6 +17573,8 @@ class basic_json
     @sa @ref from_msgpack(const std::vector<uint8_t>&, const size_t) for the
         analogous deserialization
     @sa @ref to_cbor(const basic_json& for the related CBOR format
+    @sa @ref to_ubjson(const basic_json&, const bool, const bool) for the
+             related UBJSON format
 
     @since version 2.0.9
     */
@@ -13450,6 +17596,107 @@ class basic_json
     }
 
     /*!
+    @brief create a UBJSON serialization of a given JSON value
+
+    Serializes a given JSON value @a j to a byte vector using the UBJSON
+    (Universal Binary JSON) serialization format. UBJSON aims to be more compact
+    than JSON itself, yet more efficient to parse.
+
+    The library uses the following mapping from JSON values types to
+    UBJSON types according to the UBJSON specification:
+
+    JSON value type | value/range                       | UBJSON type | marker
+    --------------- | --------------------------------- | ----------- | ------
+    null            | `null`                            | null        | `Z`
+    boolean         | `true`                            | true        | `T`
+    boolean         | `false`                           | false       | `F`
+    number_integer  | -9223372036854775808..-2147483649 | int64       | `L`
+    number_integer  | -2147483648..-32769               | int32       | `l`
+    number_integer  | -32768..-129                      | int16       | `I`
+    number_integer  | -128..127                         | int8        | `i`
+    number_integer  | 128..255                          | uint8       | `U`
+    number_integer  | 256..32767                        | int16       | `I`
+    number_integer  | 32768..2147483647                 | int32       | `l`
+    number_integer  | 2147483648..9223372036854775807   | int64       | `L`
+    number_unsigned | 0..127                            | int8        | `i`
+    number_unsigned | 128..255                          | uint8       | `U`
+    number_unsigned | 256..32767                        | int16       | `I`
+    number_unsigned | 32768..2147483647                 | int32       | `l`
+    number_unsigned | 2147483648..9223372036854775807   | int64       | `L`
+    number_float    | *any value*                       | float64     | `D`
+    string          | *with shortest length indicator*  | string      | `S`
+    array           | *see notes on optimized format*   | array       | `[`
+    object          | *see notes on optimized format*   | map         | `{`
+
+    @note The mapping is **complete** in the sense that any JSON value type
+          can be converted to a UBJSON value.
+
+    @note The following values can **not** be converted to a UBJSON value:
+          - strings with more than 9223372036854775807 bytes (theoretical)
+          - unsigned integer numbers above 9223372036854775807
+
+    @note The following markers are not used in the conversion:
+          - `Z`: no-op values are not created.
+          - `C`: single-byte strings are serialized with `S` markers.
+
+    @note Any UBJSON output created @ref to_ubjson can be successfully parsed
+          by @ref from_ubjson.
+
+    @note If NaN or Infinity are stored inside a JSON number, they are
+          serialized properly. This behavior differs from the @ref dump()
+          function which serializes NaN or Infinity to `null`.
+
+    @note The optimized formats for containers are supported: Parameter
+          @a use_size adds size information to the beginning of a container and
+          removes the closing marker. Parameter @a use_type further checks
+          whether all elements of a container have the same type and adds the
+          type marker to the beginning of the container. The @a use_type
+          parameter must only be used together with @a use_size = true. Note
+          that @a use_size = true alone may result in larger representations -
+          the benefit of this parameter is that the receiving side is
+          immediately informed on the number of elements of the container.
+
+    @param[in] j  JSON value to serialize
+    @param[in] use_size  whether to add size annotations to container types
+    @param[in] use_type  whether to add type annotations to container types
+                         (must be combined with @a use_size = true)
+    @return UBJSON serialization as byte vector
+
+    @complexity Linear in the size of the JSON value @a j.
+
+    @liveexample{The example shows the serialization of a JSON value to a byte
+    vector in UBJSON format.,to_ubjson}
+
+    @sa http://ubjson.org
+    @sa @ref from_ubjson(detail::input_adapter, const bool strict) for the
+        analogous deserialization
+    @sa @ref to_cbor(const basic_json& for the related CBOR format
+    @sa @ref to_msgpack(const basic_json&) for the related MessagePack format
+
+    @since version 3.1.0
+    */
+    static std::vector<uint8_t> to_ubjson(const basic_json& j,
+                                          const bool use_size = false,
+                                          const bool use_type = false)
+    {
+        std::vector<uint8_t> result;
+        to_ubjson(j, result, use_size, use_type);
+        return result;
+    }
+
+    static void to_ubjson(const basic_json& j, detail::output_adapter<uint8_t> o,
+                          const bool use_size = false, const bool use_type = false)
+    {
+        binary_writer<uint8_t>(o).write_ubjson(j, use_size, use_type);
+    }
+
+    static void to_ubjson(const basic_json& j, detail::output_adapter<char> o,
+                          const bool use_size = false, const bool use_type = false)
+    {
+        binary_writer<char>(o).write_ubjson(j, use_size, use_type);
+    }
+
+    /*!
     @brief create a JSON value from an input in CBOR format
 
     Deserializes a given input @a i to a JSON value using the CBOR (Concise
@@ -13518,6 +17765,9 @@ class basic_json
     @param[in] i  an input in CBOR format convertible to an input adapter
     @param[in] strict  whether to expect the input to be consumed until EOF
                        (true by default)
+    @param[in] allow_exceptions  whether to throw exceptions in case of a
+    parse error (optional, true by default)
+
     @return deserialized JSON value
 
     @throw parse_error.110 if the given input ends prematurely or the end of
@@ -13533,27 +17783,39 @@ class basic_json
 
     @sa http://cbor.io
     @sa @ref to_cbor(const basic_json&) for the analogous serialization
-    @sa @ref from_msgpack(detail::input_adapter, const bool) for the
+    @sa @ref from_msgpack(detail::input_adapter, const bool, const bool) for the
         related MessagePack format
+    @sa @ref from_ubjson(detail::input_adapter, const bool, const bool) for the
+        related UBJSON format
 
     @since version 2.0.9; parameter @a start_index since 2.1.1; changed to
            consume input adapters, removed start_index parameter, and added
-           @a strict parameter since 3.0.0
+           @a strict parameter since 3.0.0; added @allow_exceptions parameter
+           since 3.2.0
     */
-    static basic_json from_cbor(detail::input_adapter i,
-                                const bool strict = true)
+    static basic_json from_cbor(detail::input_adapter&& i,
+                                const bool strict = true,
+                                const bool allow_exceptions = true)
     {
-        return binary_reader(i).parse_cbor(strict);
+        basic_json result;
+        detail::json_sax_dom_parser<basic_json> sdp(result, allow_exceptions);
+        const bool res = binary_reader(detail::input_adapter(i)).sax_parse(input_format_t::cbor, &sdp, strict);
+        return res ? result : basic_json(value_t::discarded);
     }
 
     /*!
-    @copydoc from_cbor(detail::input_adapter, const bool)
+    @copydoc from_cbor(detail::input_adapter, const bool, const bool)
     */
     template<typename A1, typename A2,
              detail::enable_if_t<std::is_constructible<detail::input_adapter, A1, A2>::value, int> = 0>
-    static basic_json from_cbor(A1 && a1, A2 && a2, const bool strict = true)
+    static basic_json from_cbor(A1 && a1, A2 && a2,
+                                const bool strict = true,
+                                const bool allow_exceptions = true)
     {
-        return binary_reader(detail::input_adapter(std::forward<A1>(a1), std::forward<A2>(a2))).parse_cbor(strict);
+        basic_json result;
+        detail::json_sax_dom_parser<basic_json> sdp(result, allow_exceptions);
+        const bool res = binary_reader(detail::input_adapter(std::forward<A1>(a1), std::forward<A2>(a2))).sax_parse(input_format_t::cbor, &sdp, strict);
+        return res ? result : basic_json(value_t::discarded);
     }
 
     /*!
@@ -13606,7 +17868,11 @@ class basic_json
                   adapter
     @param[in] strict  whether to expect the input to be consumed until EOF
                        (true by default)
+    @param[in] allow_exceptions  whether to throw exceptions in case of a
+    parse error (optional, true by default)
 
+    @return deserialized JSON value
+
     @throw parse_error.110 if the given input ends prematurely or the end of
     file was not reached when @a strict was set to true
     @throw parse_error.112 if unsupported features from MessagePack were
@@ -13620,29 +17886,123 @@ class basic_json
 
     @sa http://msgpack.org
     @sa @ref to_msgpack(const basic_json&) for the analogous serialization
-    @sa @ref from_cbor(detail::input_adapter, const bool) for the related CBOR
-        format
+    @sa @ref from_cbor(detail::input_adapter, const bool, const bool) for the
+        related CBOR format
+    @sa @ref from_ubjson(detail::input_adapter, const bool, const bool) for
+        the related UBJSON format
 
     @since version 2.0.9; parameter @a start_index since 2.1.1; changed to
            consume input adapters, removed start_index parameter, and added
-           @a strict parameter since 3.0.0
+           @a strict parameter since 3.0.0; added @allow_exceptions parameter
+           since 3.2.0
     */
-    static basic_json from_msgpack(detail::input_adapter i,
-                                   const bool strict = true)
+    static basic_json from_msgpack(detail::input_adapter&& i,
+                                   const bool strict = true,
+                                   const bool allow_exceptions = true)
     {
-        return binary_reader(i).parse_msgpack(strict);
+        basic_json result;
+        detail::json_sax_dom_parser<basic_json> sdp(result, allow_exceptions);
+        const bool res = binary_reader(detail::input_adapter(i)).sax_parse(input_format_t::msgpack, &sdp, strict);
+        return res ? result : basic_json(value_t::discarded);
     }
 
     /*!
-    @copydoc from_msgpack(detail::input_adapter, const bool)
+    @copydoc from_msgpack(detail::input_adapter, const bool, const bool)
     */
     template<typename A1, typename A2,
              detail::enable_if_t<std::is_constructible<detail::input_adapter, A1, A2>::value, int> = 0>
-    static basic_json from_msgpack(A1 && a1, A2 && a2, const bool strict = true)
+    static basic_json from_msgpack(A1 && a1, A2 && a2,
+                                   const bool strict = true,
+                                   const bool allow_exceptions = true)
     {
-        return binary_reader(detail::input_adapter(std::forward<A1>(a1), std::forward<A2>(a2))).parse_msgpack(strict);
+        basic_json result;
+        detail::json_sax_dom_parser<basic_json> sdp(result, allow_exceptions);
+        const bool res = binary_reader(detail::input_adapter(std::forward<A1>(a1), std::forward<A2>(a2))).sax_parse(input_format_t::msgpack, &sdp, strict);
+        return res ? result : basic_json(value_t::discarded);
     }
 
+    /*!
+    @brief create a JSON value from an input in UBJSON format
+
+    Deserializes a given input @a i to a JSON value using the UBJSON (Universal
+    Binary JSON) serialization format.
+
+    The library maps UBJSON types to JSON value types as follows:
+
+    UBJSON type | JSON value type                         | marker
+    ----------- | --------------------------------------- | ------
+    no-op       | *no value, next value is read*          | `N`
+    null        | `null`                                  | `Z`
+    false       | `false`                                 | `F`
+    true        | `true`                                  | `T`
+    float32     | number_float                            | `d`
+    float64     | number_float                            | `D`
+    uint8       | number_unsigned                         | `U`
+    int8        | number_integer                          | `i`
+    int16       | number_integer                          | `I`
+    int32       | number_integer                          | `l`
+    int64       | number_integer                          | `L`
+    string      | string                                  | `S`
+    char        | string                                  | `C`
+    array       | array (optimized values are supported)  | `[`
+    object      | object (optimized values are supported) | `{`
+
+    @note The mapping is **complete** in the sense that any UBJSON value can
+          be converted to a JSON value.
+
+    @param[in] i  an input in UBJSON format convertible to an input adapter
+    @param[in] strict  whether to expect the input to be consumed until EOF
+                       (true by default)
+    @param[in] allow_exceptions  whether to throw exceptions in case of a
+    parse error (optional, true by default)
+
+    @return deserialized JSON value
+
+    @throw parse_error.110 if the given input ends prematurely or the end of
+    file was not reached when @a strict was set to true
+    @throw parse_error.112 if a parse error occurs
+    @throw parse_error.113 if a string could not be parsed successfully
+
+    @complexity Linear in the size of the input @a i.
+
+    @liveexample{The example shows the deserialization of a byte vector in
+    UBJSON format to a JSON value.,from_ubjson}
+
+    @sa http://ubjson.org
+    @sa @ref to_ubjson(const basic_json&, const bool, const bool) for the
+             analogous serialization
+    @sa @ref from_cbor(detail::input_adapter, const bool, const bool) for the
+        related CBOR format
+    @sa @ref from_msgpack(detail::input_adapter, const bool, const bool) for
+        the related MessagePack format
+
+    @since version 3.1.0; added @allow_exceptions parameter since 3.2.0
+    */
+    static basic_json from_ubjson(detail::input_adapter&& i,
+                                  const bool strict = true,
+                                  const bool allow_exceptions = true)
+    {
+        basic_json result;
+        detail::json_sax_dom_parser<basic_json> sdp(result, allow_exceptions);
+        const bool res = binary_reader(detail::input_adapter(i)).sax_parse(input_format_t::ubjson, &sdp, strict);
+        return res ? result : basic_json(value_t::discarded);
+    }
+
+    /*!
+    @copydoc from_ubjson(detail::input_adapter, const bool, const bool)
+    */
+    template<typename A1, typename A2,
+             detail::enable_if_t<std::is_constructible<detail::input_adapter, A1, A2>::value, int> = 0>
+    static basic_json from_ubjson(A1 && a1, A2 && a2,
+                                  const bool strict = true,
+                                  const bool allow_exceptions = true)
+    {
+        basic_json result;
+        detail::json_sax_dom_parser<basic_json> sdp(result, allow_exceptions);
+        const bool res = binary_reader(detail::input_adapter(std::forward<A1>(a1), std::forward<A2>(a2))).sax_parse(input_format_t::ubjson, &sdp, strict);
+        return res ? result : basic_json(value_t::discarded);
+    }
+
     /// @}
 
     //////////////////////////
@@ -14017,11 +18377,13 @@ class basic_json
                         break;
                     }
 
+                    // LCOV_EXCL_START
                     default:
                     {
                         // if there exists a parent it cannot be primitive
-                        assert(false);  // LCOV_EXCL_LINE
+                        assert(false);
                     }
+                        // LCOV_EXCL_STOP
                 }
             }
         };
@@ -14066,7 +18428,7 @@ class basic_json
             // wrapper to get a value for an operation
             const auto get_value = [&val](const std::string & op,
                                           const std::string & member,
-                                          bool string_type) -> basic_json&
+                                          bool string_type) -> basic_json &
             {
                 // find value
                 auto it = val.m_value.object->find(member);
@@ -14163,7 +18525,7 @@ class basic_json
                         // the "path" location must exist - use at()
                         success = (result.at(ptr) == get_value("test", "value", false));
                     }
-                    JSON_CATCH (out_of_range&)
+                    JSON_INTERNAL_CATCH (out_of_range&)
                     {
                         // ignore out of range errors: success remains false
                     }
@@ -14216,6 +18578,7 @@ class basic_json
     diff for two JSON values.,diff}
 
     @sa @ref patch -- apply a JSON patch
+    @sa @ref merge_patch -- apply a JSON Merge Patch
 
     @sa [RFC 6902 (JSON Patch)](https://tools.ietf.org/html/rfc6902)
 
@@ -14347,418 +18710,86 @@ class basic_json
     }
 
     /// @}
-};
 
-/////////////
-// presets //
-/////////////
+    ////////////////////////////////
+    // JSON Merge Patch functions //
+    ////////////////////////////////
 
-/*!
-@brief default JSON class
+    /// @name JSON Merge Patch functions
+    /// @{
 
-This type is the default specialization of the @ref basic_json class which
-uses the standard template types.
+    /*!
+    @brief applies a JSON Merge Patch
 
-@since version 1.0.0
-*/
-using json = basic_json<>;
+    The merge patch format is primarily intended for use with the HTTP PATCH
+    method as a means of describing a set of modifications to a target
+    resource's content. This function applies a merge patch to the current
+    JSON value.
 
-//////////////////
-// json_pointer //
-//////////////////
+    The function implements the following algorithm from Section 2 of
+    [RFC 7396 (JSON Merge Patch)](https://tools.ietf.org/html/rfc7396):
 
-NLOHMANN_BASIC_JSON_TPL_DECLARATION
-NLOHMANN_BASIC_JSON_TPL&
-json_pointer::get_and_create(NLOHMANN_BASIC_JSON_TPL& j) const
-{
-    using size_type = typename NLOHMANN_BASIC_JSON_TPL::size_type;
-    auto result = &j;
+    ```
+    define MergePatch(Target, Patch):
+      if Patch is an Object:
+        if Target is not an Object:
+          Target = {} // Ignore the contents and set it to an empty Object
+        for each Name/Value pair in Patch:
+          if Value is null:
+            if Name exists in Target:
+              remove the Name/Value pair from Target
+          else:
+            Target[Name] = MergePatch(Target[Name], Value)
+        return Target
+      else:
+        return Patch
+    ```
 
-    // in case no reference tokens exist, return a reference to the JSON value
-    // j which will be overwritten by a primitive value
-    for (const auto& reference_token : reference_tokens)
-    {
-        switch (result->m_type)
-        {
-            case detail::value_t::null:
-            {
-                if (reference_token == "0")
-                {
-                    // start a new array if reference token is 0
-                    result = &result->operator[](0);
-                }
-                else
-                {
-                    // start a new object otherwise
-                    result = &result->operator[](reference_token);
-                }
-                break;
-            }
+    Thereby, `Target` is the current object; that is, the patch is applied to
+    the current value.
 
-            case detail::value_t::object:
-            {
-                // create an entry in the object
-                result = &result->operator[](reference_token);
-                break;
-            }
+    @param[in] patch  the patch to apply
 
-            case detail::value_t::array:
-            {
-                // create an entry in the array
-                JSON_TRY
-                {
-                    result = &result->operator[](static_cast<size_type>(array_index(reference_token)));
-                }
-                JSON_CATCH(std::invalid_argument&)
-                {
-                    JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
-                }
-                break;
-            }
+    @complexity Linear in the lengths of @a patch.
 
-            /*
-            The following code is only reached if there exists a reference
-            token _and_ the current value is primitive. In this case, we have
-            an error situation, because primitive values may only occur as
-            single value; that is, with an empty list of reference tokens.
-            */
-            default:
-                JSON_THROW(detail::type_error::create(313, "invalid value to unflatten"));
-        }
-    }
+    @liveexample{The following code shows how a JSON Merge Patch is applied to
+    a JSON document.,merge_patch}
 
-    return *result;
-}
+    @sa @ref patch -- apply a JSON patch
+    @sa [RFC 7396 (JSON Merge Patch)](https://tools.ietf.org/html/rfc7396)
 
-NLOHMANN_BASIC_JSON_TPL_DECLARATION
-NLOHMANN_BASIC_JSON_TPL&
-json_pointer::get_unchecked(NLOHMANN_BASIC_JSON_TPL* ptr) const
-{
-    using size_type = typename NLOHMANN_BASIC_JSON_TPL::size_type;
-    for (const auto& reference_token : reference_tokens)
+    @since version 3.0.0
+    */
+    void merge_patch(const basic_json& patch)
     {
-        // convert null values to arrays or objects before continuing
-        if (ptr->m_type == detail::value_t::null)
+        if (patch.is_object())
         {
-            // check if reference token is a number
-            const bool nums =
-                std::all_of(reference_token.begin(), reference_token.end(),
-                            [](const char x)
+            if (not is_object())
             {
-                return (x >= '0' and x <= '9');
-            });
-
-            // change value to array for numbers or "-" or to object otherwise
-            *ptr = (nums or reference_token == "-")
-                   ? detail::value_t::array
-                   : detail::value_t::object;
-        }
-
-        switch (ptr->m_type)
-        {
-            case detail::value_t::object:
-            {
-                // use unchecked object access
-                ptr = &ptr->operator[](reference_token);
-                break;
+                *this = object();
             }
-
-            case detail::value_t::array:
+            for (auto it = patch.begin(); it != patch.end(); ++it)
             {
-                // error condition (cf. RFC 6901, Sect. 4)
-                if (JSON_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
+                if (it.value().is_null())
                 {
-                    JSON_THROW(detail::parse_error::create(106, 0,
-                                                           "array index '" + reference_token +
-                                                           "' must not begin with '0'"));
+                    erase(it.key());
                 }
-
-                if (reference_token == "-")
-                {
-                    // explicitly treat "-" as index beyond the end
-                    ptr = &ptr->operator[](ptr->m_value.array->size());
-                }
                 else
                 {
-                    // convert array index to number; unchecked access
-                    JSON_TRY
-                    {
-                        ptr = &ptr->operator[](
-                            static_cast<size_type>(array_index(reference_token)));
-                    }
-                    JSON_CATCH(std::invalid_argument&)
-                    {
-                        JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
-                    }
+                    operator[](it.key()).merge_patch(it.value());
                 }
-                break;
             }
-
-            default:
-                JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
         }
-    }
-
-    return *ptr;
-}
-
-NLOHMANN_BASIC_JSON_TPL_DECLARATION
-NLOHMANN_BASIC_JSON_TPL&
-json_pointer::get_checked(NLOHMANN_BASIC_JSON_TPL* ptr) const
-{
-    using size_type = typename NLOHMANN_BASIC_JSON_TPL::size_type;
-    for (const auto& reference_token : reference_tokens)
-    {
-        switch (ptr->m_type)
+        else
         {
-            case detail::value_t::object:
-            {
-                // note: at performs range check
-                ptr = &ptr->at(reference_token);
-                break;
-            }
-
-            case detail::value_t::array:
-            {
-                if (JSON_UNLIKELY(reference_token == "-"))
-                {
-                    // "-" always fails the range check
-                    JSON_THROW(detail::out_of_range::create(402,
-                                                            "array index '-' (" + std::to_string(ptr->m_value.array->size()) +
-                                                            ") is out of range"));
-                }
-
-                // error condition (cf. RFC 6901, Sect. 4)
-                if (JSON_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
-                {
-                    JSON_THROW(detail::parse_error::create(106, 0,
-                                                           "array index '" + reference_token +
-                                                           "' must not begin with '0'"));
-                }
-
-                // note: at performs range check
-                JSON_TRY
-                {
-                    ptr = &ptr->at(static_cast<size_type>(array_index(reference_token)));
-                }
-                JSON_CATCH(std::invalid_argument&)
-                {
-                    JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
-                }
-                break;
-            }
-
-            default:
-                JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
+            *this = patch;
         }
     }
 
-    return *ptr;
-}
-
-NLOHMANN_BASIC_JSON_TPL_DECLARATION
-const NLOHMANN_BASIC_JSON_TPL&
-json_pointer::get_unchecked(const NLOHMANN_BASIC_JSON_TPL* ptr) const
-{
-    using size_type = typename NLOHMANN_BASIC_JSON_TPL::size_type;
-    for (const auto& reference_token : reference_tokens)
-    {
-        switch (ptr->m_type)
-        {
-            case detail::value_t::object:
-            {
-                // use unchecked object access
-                ptr = &ptr->operator[](reference_token);
-                break;
-            }
-
-            case detail::value_t::array:
-            {
-                if (JSON_UNLIKELY(reference_token == "-"))
-                {
-                    // "-" cannot be used for const access
-                    JSON_THROW(detail::out_of_range::create(402,
-                                                            "array index '-' (" + std::to_string(ptr->m_value.array->size()) +
-                                                            ") is out of range"));
-                }
-
-                // error condition (cf. RFC 6901, Sect. 4)
-                if (JSON_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
-                {
-                    JSON_THROW(detail::parse_error::create(106, 0,
-                                                           "array index '" + reference_token +
-                                                           "' must not begin with '0'"));
-                }
-
-                // use unchecked array access
-                JSON_TRY
-                {
-                    ptr = &ptr->operator[](
-                        static_cast<size_type>(array_index(reference_token)));
-                }
-                JSON_CATCH(std::invalid_argument&)
-                {
-                    JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
-                }
-                break;
-            }
-
-            default:
-                JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
-        }
-    }
-
-    return *ptr;
-}
-
-NLOHMANN_BASIC_JSON_TPL_DECLARATION
-const NLOHMANN_BASIC_JSON_TPL&
-json_pointer::get_checked(const NLOHMANN_BASIC_JSON_TPL* ptr) const
-{
-    using size_type = typename NLOHMANN_BASIC_JSON_TPL::size_type;
-    for (const auto& reference_token : reference_tokens)
-    {
-        switch (ptr->m_type)
-        {
-            case detail::value_t::object:
-            {
-                // note: at performs range check
-                ptr = &ptr->at(reference_token);
-                break;
-            }
-
-            case detail::value_t::array:
-            {
-                if (JSON_UNLIKELY(reference_token == "-"))
-                {
-                    // "-" always fails the range check
-                    JSON_THROW(detail::out_of_range::create(402,
-                                                            "array index '-' (" + std::to_string(ptr->m_value.array->size()) +
-                                                            ") is out of range"));
-                }
-
-                // error condition (cf. RFC 6901, Sect. 4)
-                if (JSON_UNLIKELY(reference_token.size() > 1 and reference_token[0] == '0'))
-                {
-                    JSON_THROW(detail::parse_error::create(106, 0,
-                                                           "array index '" + reference_token +
-                                                           "' must not begin with '0'"));
-                }
-
-                // note: at performs range check
-                JSON_TRY
-                {
-                    ptr = &ptr->at(static_cast<size_type>(array_index(reference_token)));
-                }
-                JSON_CATCH(std::invalid_argument&)
-                {
-                    JSON_THROW(detail::parse_error::create(109, 0, "array index '" + reference_token + "' is not a number"));
-                }
-                break;
-            }
-
-            default:
-                JSON_THROW(detail::out_of_range::create(404, "unresolved reference token '" + reference_token + "'"));
-        }
-    }
-
-    return *ptr;
-}
-
-NLOHMANN_BASIC_JSON_TPL_DECLARATION
-void json_pointer::flatten(const std::string& reference_string,
-                           const NLOHMANN_BASIC_JSON_TPL& value,
-                           NLOHMANN_BASIC_JSON_TPL& result)
-{
-    switch (value.m_type)
-    {
-        case detail::value_t::array:
-        {
-            if (value.m_value.array->empty())
-            {
-                // flatten empty array as null
-                result[reference_string] = nullptr;
-            }
-            else
-            {
-                // iterate array and use index as reference string
-                for (std::size_t i = 0; i < value.m_value.array->size(); ++i)
-                {
-                    flatten(reference_string + "/" + std::to_string(i),
-                            value.m_value.array->operator[](i), result);
-                }
-            }
-            break;
-        }
-
-        case detail::value_t::object:
-        {
-            if (value.m_value.object->empty())
-            {
-                // flatten empty object as null
-                result[reference_string] = nullptr;
-            }
-            else
-            {
-                // iterate object and use keys as reference string
-                for (const auto& element : *value.m_value.object)
-                {
-                    flatten(reference_string + "/" + escape(element.first), element.second, result);
-                }
-            }
-            break;
-        }
-
-        default:
-        {
-            // add primitive value with its reference string
-            result[reference_string] = value;
-            break;
-        }
-    }
-}
-
-NLOHMANN_BASIC_JSON_TPL_DECLARATION
-NLOHMANN_BASIC_JSON_TPL
-json_pointer::unflatten(const NLOHMANN_BASIC_JSON_TPL& value)
-{
-    if (JSON_UNLIKELY(not value.is_object()))
-    {
-        JSON_THROW(detail::type_error::create(314, "only objects can be unflattened"));
-    }
-
-    NLOHMANN_BASIC_JSON_TPL result;
-
-    // iterate the JSON object values
-    for (const auto& element : *value.m_value.object)
-    {
-        if (JSON_UNLIKELY(not element.second.is_primitive()))
-        {
-            JSON_THROW(detail::type_error::create(315, "values in object must be primitive"));
-        }
-
-        // assign value to reference pointed to by JSON pointer; Note that if
-        // the JSON pointer is "" (i.e., points to the whole value), function
-        // get_and_create returns a reference to result itself. An assignment
-        // will then create a primitive value.
-        json_pointer(element.first).get_and_create(result) = element.second;
-    }
-
-    return result;
-}
-
-inline bool operator==(json_pointer const& lhs, json_pointer const& rhs) noexcept
-{
-    return (lhs.reference_tokens == rhs.reference_tokens);
-}
-
-inline bool operator!=(json_pointer const& lhs, json_pointer const& rhs) noexcept
-{
-    return not (lhs == rhs);
-}
+    /// @}
+};
 } // namespace nlohmann
 
-
 ///////////////////////
 // nonmember support //
 ///////////////////////
@@ -14772,11 +18803,10 @@ namespace std
 @since version 1.0.0
 */
 template<>
-inline void swap(nlohmann::json& j1,
-                 nlohmann::json& j2) noexcept(
-                     is_nothrow_move_constructible<nlohmann::json>::value and
-                     is_nothrow_move_assignable<nlohmann::json>::value
-                 )
+inline void swap<nlohmann::json>(nlohmann::json& j1, nlohmann::json& j2) noexcept(
+    is_nothrow_move_constructible<nlohmann::json>::value and
+    is_nothrow_move_assignable<nlohmann::json>::value
+)
 {
     j1.swap(j2);
 }
@@ -14853,6 +18883,9 @@ inline nlohmann::json::json_pointer operator "" _json_
     return nlohmann::json::json_pointer(std::string(s, n));
 }
 
+// #include <nlohmann/detail/macro_unscope.hpp>
+
+
 // restore GCC/clang diagnostic settings
 #if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
     #pragma GCC diagnostic pop
@@ -14862,13 +18895,18 @@ inline nlohmann::json::json_pointer operator "" _json_
 #endif
 
 // clean up
+#undef JSON_INTERNAL_CATCH
 #undef JSON_CATCH
 #undef JSON_THROW
 #undef JSON_TRY
 #undef JSON_LIKELY
 #undef JSON_UNLIKELY
 #undef JSON_DEPRECATED
+#undef JSON_HAS_CPP_14
+#undef JSON_HAS_CPP_17
 #undef NLOHMANN_BASIC_JSON_TPL_DECLARATION
 #undef NLOHMANN_BASIC_JSON_TPL
+#undef NLOHMANN_JSON_HAS_HELPER
+
 
 #endif
