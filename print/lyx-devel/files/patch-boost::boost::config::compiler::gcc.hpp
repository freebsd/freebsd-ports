$NetBSD$

--- ./boost/boost/config/compiler/gcc.hpp.orig	2003-05-26 08:27:34.000000000 -0600
+++ ./boost/boost/config/compiler/gcc.hpp
@@ -1,7 +1,13 @@
-//  (C) Copyright Boost.org 2001. Permission to copy, use, modify, sell and
-//  distribute this software is granted provided this copyright notice appears
-//  in all copies. This software is provided "as is" without express or implied
-//  warranty, and with no claim as to its suitability for any purpose.
+//  (C) Copyright John Maddock 2001 - 2003.
+//  (C) Copyright Darin Adler 2001 - 2002.
+//  (C) Copyright Jens Maurer 2001 - 2002.
+//  (C) Copyright Beman Dawes 2001 - 2003.
+//  (C) Copyright Douglas Gregor 2002.
+//  (C) Copyright David Abrahams 2002 - 2003.
+//  (C) Copyright Synge Todo 2003.
+//  Use, modification and distribution are subject to the
+//  Boost Software License, Version 1.0. (See accompanying file
+//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 
 //  See http://www.boost.org for most recent version.
 
@@ -23,24 +29,53 @@
 #     endif
 #   endif
 
+#   if __GNUC__ == 2 && __GNUC_MINOR__ < 96
+#     define BOOST_NO_SFINAE
+#   endif
+
 #   if __GNUC__ == 2 && __GNUC_MINOR__ <= 97
 #     define BOOST_NO_MEMBER_TEMPLATE_FRIENDS
 #     define BOOST_NO_OPERATORS_IN_NAMESPACE
 #   endif
 
+#   if __GNUC__ < 3
+#      define BOOST_NO_USING_DECLARATION_OVERLOADS_FROM_TYPENAME_BASE
+#      define BOOST_FUNCTION_SCOPE_USING_DECLARATION_BREAKS_ADL
+#   endif
+
+#
+#
+#
+
+//
+// Bug specific to gcc 3.1 and 3.2:
+//
+#if (__GNUC__ == 3) && ((__GNUC_MINOR__ == 1) || (__GNUC_MINOR__ == 2))
+#  define BOOST_NO_EXPLICIT_FUNCTION_TEMPLATE_ARGUMENTS
+#endif
+
 //
-// Threading support:
-// Turn this on unconditionally here, it will get turned off again later
-// if no threading API is detected.
+// Threading support: Turn this on unconditionally here (except for
+// those platforms where we can know for sure). It will get turned off again
+// later if no threading API is detected.
 //
-#define BOOST_HAS_THREADS
+#if !defined(__MINGW32__) && !defined(linux) && !defined(__linux) && !defined(__linux__)
+# define BOOST_HAS_THREADS
+#endif
 
 //
 // gcc has "long long"
 //
 #define BOOST_HAS_LONG_LONG
 
-#define BOOST_COMPILER "GNU C++ version " BOOST_STRINGIZE(__GNUC__) "." BOOST_STRINGIZE(__GNUC_MINOR__)
+//
+// gcc implements the named return value optimization since version 3.1
+//
+#if __GNUC__ > 3 || ( __GNUC__ == 3 && __GNUC_MINOR__ >= 1 )
+#define BOOST_HAS_NRVO
+#endif
+
+#define BOOST_COMPILER "GNU C++ version " __VERSION__
 
 //
 // versions check:
@@ -49,11 +84,13 @@
 #  error "Compiler not configured - please reconfigure"
 #endif
 //
-// last known and checked version is 3.2:
-#if (__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ > 3))
+// last known and checked version is 3.4:
+#if (__GNUC__ > 3) || ((__GNUC__ == 3) && (__GNUC_MINOR__ > 4))
 #  if defined(BOOST_ASSERT_CONFIG)
 #     error "Unknown compiler version - please run the configure tests and report the results"
 #  else
 #     warning "Unknown compiler version - please run the configure tests and report the results"
 #  endif
 #endif
+
+
