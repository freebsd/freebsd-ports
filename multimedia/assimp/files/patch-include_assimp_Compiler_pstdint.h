# Origin: http://www.azillionmonkeys.com/qed/pstdint.h
# Subject: Update pstdint.h to version 0.1.15.4

--- include/assimp/Compiler/pstdint.h.orig	2015-11-03 18:47:37 UTC
+++ include/assimp/Compiler/pstdint.h
@@ -3,7 +3,7 @@
  *  BSD License:
  ****************************************************************************
  *
- *  Copyright (c) 2005-2007 Paul Hsieh
+ *  Copyright (c) 2005-2016 Paul Hsieh
  *  All rights reserved.
  *
  *  Redistribution and use in source and binary forms, with or without
@@ -31,7 +31,7 @@
  *
  ****************************************************************************
  *
- *  Version 0.1.10
+ *  Version 0.1.15.4
  *
  *  The ANSI C standard committee, for the C99 standard, specified the
  *  inclusion of a new standard include file called stdint.h.  This is
@@ -42,19 +42,17 @@
  *  integer libraries and so on.  But for most developers its likely
  *  useful just for programming sanity.
  *
- *  The problem is that most compiler vendors have decided not to
- *  implement the C99 standard, and the next C++ language standard
- *  (which has a lot more mindshare these days) will be a long time in
- *  coming and its unknown whether or not it will include stdint.h or
- *  how much adoption it will have.  Either way, it will be a long time
- *  before all compilers come with a stdint.h and it also does nothing
- *  for the extremely large number of compilers available today which
- *  do not include this file, or anything comparable to it.
+ *  The problem is that some compiler vendors chose to ignore the C99
+ *  standard and some older compilers have no opportunity to be updated.
+ *  Because of this situation, simply including stdint.h in your code
+ *  makes it unportable.
  *
  *  So that's what this file is all about.  Its an attempt to build a
  *  single universal include file that works on as many platforms as
- *  possible to deliver what stdint.h is supposed to.  A few things
- *  that should be noted about this file:
+ *  possible to deliver what stdint.h is supposed to.  Even compilers
+ *  that already come with stdint.h can use this file instead without
+ *  any loss of functionality.  A few things that should be noted about
+ *  this file:
  *
  *    1) It is not guaranteed to be portable and/or present an identical
  *       interface on all platforms.  The extreme variability of the
@@ -73,7 +71,7 @@
  *       include stdint.h.  The hope is that one or the other can be
  *       used with no real difference.
  *
- *    5) In the current verison, if your platform can't represent
+ *    5) In the current version, if your platform can't represent
  *       int32_t, int16_t and int8_t, it just dumps out with a compiler
  *       error.
  *
@@ -154,7 +152,12 @@
  *       PRINTF_INT64_DEC_WIDTH
  *       PRINTF_INT32_DEC_WIDTH
  *       PRINTF_INT16_DEC_WIDTH
- *       PRINTF_INT8_DEC_WIDTH
+ *       PRINTF_UINT8_DEC_WIDTH
+ *       PRINTF_UINTMAX_DEC_WIDTH
+ *       PRINTF_UINT64_DEC_WIDTH
+ *       PRINTF_UINT32_DEC_WIDTH
+ *       PRINTF_UINT16_DEC_WIDTH
+ *       PRINTF_UINT8_DEC_WIDTH
  *
  *       Which specifies the maximum number of characters required to
  *       print the number of that type in either hexadecimal or decimal.
@@ -178,6 +181,10 @@
  *  Chris Howie
  *  John Steele Scott
  *  Dave Thorup
+ *  John Dill
+ *  Florian Wobbe
+ *  Christopher Sean Morrison
+ *  Mikkel Fahnoe Jorgensen
  *
  */
 
@@ -190,14 +197,27 @@
  *  do nothing else.  On the Mac OS X version of gcc this is _STDINT_H_.
  */
 
-#if ((defined(__STDC__) && __STDC__ && __STDC_VERSION__ >= 199901L) || (defined (__WATCOMC__) && (defined (_STDINT_H_INCLUDED) || __WATCOMC__ >= 1250)) || (defined(__GNUC__) && (defined(_STDINT_H) || defined(_STDINT_H_)))) && !defined (_PSTDINT_H_INCLUDED) && !defined(_STDINT)
+#if ((defined(__SUNPRO_C) && __SUNPRO_C >= 0x570) || (defined(_MSC_VER) && _MSC_VER >= 1600) || (defined(__STDC__) && __STDC__ && defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || (defined (__WATCOMC__) && (defined (_STDINT_H_INCLUDED) || __WATCOMC__ >= 1250)) || (defined(__GNUC__) && (__GNUC__ > 3 || defined(_STDINT_H) || defined(_STDINT_H_) || defined (__UINT_FAST64_TYPE__)) )) && !defined (_PSTDINT_H_INCLUDED)
 #include <stdint.h>
 #define _PSTDINT_H_INCLUDED
-# ifndef PRINTF_INT64_MODIFIER
-#  define PRINTF_INT64_MODIFIER "ll"
-# endif
-# ifndef PRINTF_INT32_MODIFIER
-#  define PRINTF_INT32_MODIFIER "l"
+# if defined(__GNUC__) && (defined(__x86_64__) || defined(__ppc64__)) && !(defined(__APPLE__) && defined(__MACH__))
+#  ifndef PRINTF_INT64_MODIFIER
+#   define PRINTF_INT64_MODIFIER "l"
+#  endif
+#  ifndef PRINTF_INT32_MODIFIER
+#   define PRINTF_INT32_MODIFIER ""
+#  endif
+# else
+#  ifndef PRINTF_INT64_MODIFIER
+#   define PRINTF_INT64_MODIFIER "ll"
+#  endif
+#  ifndef PRINTF_INT32_MODIFIER
+#   if (UINT_MAX == UINT32_MAX)
+#    define PRINTF_INT32_MODIFIER ""
+#   else
+#    define PRINTF_INT32_MODIFIER "l"
+#   endif
+#  endif
 # endif
 # ifndef PRINTF_INT16_MODIFIER
 #  define PRINTF_INT16_MODIFIER "h"
@@ -208,32 +228,62 @@
 # ifndef PRINTF_INT64_HEX_WIDTH
 #  define PRINTF_INT64_HEX_WIDTH "16"
 # endif
+# ifndef PRINTF_UINT64_HEX_WIDTH
+#  define PRINTF_UINT64_HEX_WIDTH "16"
+# endif
 # ifndef PRINTF_INT32_HEX_WIDTH
 #  define PRINTF_INT32_HEX_WIDTH "8"
 # endif
+# ifndef PRINTF_UINT32_HEX_WIDTH
+#  define PRINTF_UINT32_HEX_WIDTH "8"
+# endif
 # ifndef PRINTF_INT16_HEX_WIDTH
 #  define PRINTF_INT16_HEX_WIDTH "4"
 # endif
+# ifndef PRINTF_UINT16_HEX_WIDTH
+#  define PRINTF_UINT16_HEX_WIDTH "4"
+# endif
 # ifndef PRINTF_INT8_HEX_WIDTH
 #  define PRINTF_INT8_HEX_WIDTH "2"
 # endif
+# ifndef PRINTF_UINT8_HEX_WIDTH
+#  define PRINTF_UINT8_HEX_WIDTH "2"
+# endif
 # ifndef PRINTF_INT64_DEC_WIDTH
-#  define PRINTF_INT64_DEC_WIDTH "20"
+#  define PRINTF_INT64_DEC_WIDTH "19"
+# endif
+# ifndef PRINTF_UINT64_DEC_WIDTH
+#  define PRINTF_UINT64_DEC_WIDTH "20"
 # endif
 # ifndef PRINTF_INT32_DEC_WIDTH
 #  define PRINTF_INT32_DEC_WIDTH "10"
 # endif
+# ifndef PRINTF_UINT32_DEC_WIDTH
+#  define PRINTF_UINT32_DEC_WIDTH "10"
+# endif
 # ifndef PRINTF_INT16_DEC_WIDTH
 #  define PRINTF_INT16_DEC_WIDTH "5"
 # endif
+# ifndef PRINTF_UINT16_DEC_WIDTH
+#  define PRINTF_UINT16_DEC_WIDTH "5"
+# endif
 # ifndef PRINTF_INT8_DEC_WIDTH
 #  define PRINTF_INT8_DEC_WIDTH "3"
 # endif
+# ifndef PRINTF_UINT8_DEC_WIDTH
+#  define PRINTF_UINT8_DEC_WIDTH "3"
+# endif
 # ifndef PRINTF_INTMAX_HEX_WIDTH
-#  define PRINTF_INTMAX_HEX_WIDTH PRINTF_INT64_HEX_WIDTH
+#  define PRINTF_INTMAX_HEX_WIDTH PRINTF_UINT64_HEX_WIDTH
+# endif
+# ifndef PRINTF_UINTMAX_HEX_WIDTH
+#  define PRINTF_UINTMAX_HEX_WIDTH PRINTF_UINT64_HEX_WIDTH
 # endif
 # ifndef PRINTF_INTMAX_DEC_WIDTH
-#  define PRINTF_INTMAX_DEC_WIDTH PRINTF_INT64_DEC_WIDTH
+#  define PRINTF_INTMAX_DEC_WIDTH PRINTF_UINT64_DEC_WIDTH
+# endif
+# ifndef PRINTF_UINTMAX_DEC_WIDTH
+#  define PRINTF_UINTMAX_DEC_WIDTH PRINTF_UINT64_DEC_WIDTH
 # endif
 
 /*
@@ -287,6 +337,20 @@
 # endif
 #endif
 
+/*
+ *  I have no idea what is the truly correct thing to do on older Solaris.
+ *  From some online discussions, this seems to be what is being
+ *  recommended.  For people who actually are developing on older Solaris,
+ *  what I would like to know is, does this define all of the relevant
+ *  macros of a complete stdint.h?  Remember, in pstdint.h 64 bit is
+ *  considered optional.
+ */
+
+#if (defined(__SUNPRO_C) && __SUNPRO_C >= 0x420) && !defined(_PSTDINT_H_INCLUDED)
+#include <sys/inttypes.h>
+#define _PSTDINT_H_INCLUDED
+#endif
+
 #ifndef _PSTDINT_H_INCLUDED
 #define _PSTDINT_H_INCLUDED
 
@@ -303,7 +367,7 @@
 #ifndef UINT8_MAX
 # define UINT8_MAX 0xff
 #endif
-#ifndef uint8_t
+#if !defined(uint8_t) && !defined(_UINT8_T) && !defined(vxWorks)
 # if (UCHAR_MAX == UINT8_MAX) || defined (S_SPLINT_S)
     typedef unsigned char uint8_t;
 #   define UINT8_C(v) ((uint8_t) v)
@@ -318,7 +382,7 @@
 #ifndef INT8_MIN
 # define INT8_MIN INT8_C(0x80)
 #endif
-#ifndef int8_t
+#if !defined(int8_t) && !defined(_INT8_T) && !defined(vxWorks)
 # if (SCHAR_MAX == INT8_MAX) || defined (S_SPLINT_S)
     typedef signed char int8_t;
 #   define INT8_C(v) ((int8_t) v)
@@ -330,7 +394,7 @@
 #ifndef UINT16_MAX
 # define UINT16_MAX 0xffff
 #endif
-#ifndef uint16_t
+#if !defined(uint16_t) && !defined(_UINT16_T) && !defined(vxWorks)
 #if (UINT_MAX == UINT16_MAX) || defined (S_SPLINT_S)
   typedef unsigned int uint16_t;
 # ifndef PRINTF_INT16_MODIFIER
@@ -354,7 +418,7 @@
 #ifndef INT16_MIN
 # define INT16_MIN INT16_C(0x8000)
 #endif
-#ifndef int16_t
+#if !defined(int16_t) && !defined(_INT16_T) && !defined(vxWorks)
 #if (INT_MAX == INT16_MAX) || defined (S_SPLINT_S)
   typedef signed int int16_t;
 # define INT16_C(v) ((int16_t) (v))
@@ -375,7 +439,7 @@
 #ifndef UINT32_MAX
 # define UINT32_MAX (0xffffffffUL)
 #endif
-#ifndef uint32_t
+#if !defined(uint32_t) && !defined(_UINT32_T) && !defined(vxWorks)
 #if (ULONG_MAX == UINT32_MAX) || defined (S_SPLINT_S)
   typedef unsigned long uint32_t;
 # define UINT32_C(v) v ## UL
@@ -405,7 +469,7 @@
 #ifndef INT32_MIN
 # define INT32_MIN INT32_C(0x80000000)
 #endif
-#ifndef int32_t
+#if !defined(int32_t) && !defined(_INT32_T) && !defined(vxWorks)
 #if (LONG_MAX == INT32_MAX) || defined (S_SPLINT_S)
   typedef signed long int32_t;
 # define INT32_C(v) v ## L
@@ -438,7 +502,7 @@
 
 #undef stdint_int64_defined
 #if (defined(__STDC__) && defined(__STDC_VERSION__)) || defined (S_SPLINT_S)
-# if (__STDC__ && __STDC_VERSION >= 199901L) || defined (S_SPLINT_S)
+# if (__STDC__ && __STDC_VERSION__ >= 199901L) || defined (S_SPLINT_S)
 #  define stdint_int64_defined
    typedef long long int64_t;
    typedef unsigned long long uint64_t;
@@ -451,7 +515,7 @@
 #endif
 
 #if !defined (stdint_int64_defined)
-# if defined(__GNUC__)
+# if defined(__GNUC__) && !defined(vxWorks)
 #  define stdint_int64_defined
    __extension__ typedef long long int64_t;
    __extension__ typedef unsigned long long uint64_t;
@@ -514,9 +578,8 @@
 #ifndef PRINTF_INT8_HEX_WIDTH
 # define PRINTF_INT8_HEX_WIDTH "2"
 #endif
-
 #ifndef PRINTF_INT64_DEC_WIDTH
-# define PRINTF_INT64_DEC_WIDTH "20"
+# define PRINTF_INT64_DEC_WIDTH "19"
 #endif
 #ifndef PRINTF_INT32_DEC_WIDTH
 # define PRINTF_INT32_DEC_WIDTH "10"
@@ -527,6 +590,18 @@
 #ifndef PRINTF_INT8_DEC_WIDTH
 # define PRINTF_INT8_DEC_WIDTH "3"
 #endif
+#ifndef PRINTF_UINT64_DEC_WIDTH
+# define PRINTF_UINT64_DEC_WIDTH "20"
+#endif
+#ifndef PRINTF_UINT32_DEC_WIDTH
+# define PRINTF_UINT32_DEC_WIDTH "10"
+#endif
+#ifndef PRINTF_UINT16_DEC_WIDTH
+# define PRINTF_UINT16_DEC_WIDTH "5"
+#endif
+#ifndef PRINTF_UINT8_DEC_WIDTH
+# define PRINTF_UINT8_DEC_WIDTH "3"
+#endif
 
 /*
  *  Ok, lets not worry about 128 bit integers for now.  Moore's law says
@@ -646,7 +721,7 @@ typedef uint_least32_t uint_fast32_t;
  *  type limits.
  */
 
-#if defined(__WATCOMC__) || defined(_MSC_VER) || defined (__GNUC__)
+#if defined(__WATCOMC__) || defined(_MSC_VER) || defined (__GNUC__) && !defined(vxWorks)
 # include <wchar.h>
 # ifndef WCHAR_MIN
 #  define WCHAR_MIN 0
@@ -661,12 +736,12 @@ typedef uint_least32_t uint_fast32_t;
  *  (u)intptr_t types and limits.
  */
 
-#if defined (_MSC_VER) && defined (_UINTPTR_T_DEFINED)
+#if (defined (_MSC_VER) && defined (_UINTPTR_T_DEFINED)) || defined (_UINTPTR_T)
 # define STDINT_H_UINTPTR_T_DEFINED
 #endif
 
 #ifndef STDINT_H_UINTPTR_T_DEFINED
-# if defined (__alpha__) || defined (__ia64__) || defined (__x86_64__) || defined (_WIN64)
+# if defined (__alpha__) || defined (__ia64__) || defined (__x86_64__) || defined (_WIN64) || defined (__ppc64__)
 #  define stdint_intptr_bits 64
 # elif defined (__WATCOMC__) || defined (__TURBOC__)
 #  if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
@@ -674,10 +749,12 @@ typedef uint_least32_t uint_fast32_t;
 #  else
 #    define stdint_intptr_bits 32
 #  endif
-# elif defined (__i386__) || defined (_WIN32) || defined (WIN32)
+# elif defined (__i386__) || defined (_WIN32) || defined (WIN32) || defined (__ppc64__)
 #  define stdint_intptr_bits 32
 # elif defined (__INTEL_COMPILER)
-/* TODO -- what will Intel do about x86-64? */
+/* TODO -- what did Intel do about x86-64? */
+# else
+/* #error "This platform might not be supported yet" */
 # endif
 
 # ifdef stdint_intptr_bits
@@ -727,3 +804,109 @@ typedef uint_least32_t uint_fast32_t;
 
 #endif
 
+#if defined (__TEST_PSTDINT_FOR_CORRECTNESS)
+
+/*
+ *  Please compile with the maximum warning settings to make sure macros are
+ *  not defined more than once.
+ */
+
+#include <stdlib.h>
+#include <stdio.h>
+#include <string.h>
+
+#define glue3_aux(x,y,z) x ## y ## z
+#define glue3(x,y,z) glue3_aux(x,y,z)
+
+#define DECLU(bits) glue3(uint,bits,_t) glue3(u,bits,) = glue3(UINT,bits,_C) (0);
+#define DECLI(bits) glue3(int,bits,_t) glue3(i,bits,) = glue3(INT,bits,_C) (0);
+
+#define DECL(us,bits) glue3(DECL,us,) (bits)
+
+#define TESTUMAX(bits) glue3(u,bits,) = ~glue3(u,bits,); if (glue3(UINT,bits,_MAX) != glue3(u,bits,)) printf ("Something wrong with UINT%d_MAX\n", bits)
+
+#define REPORTERROR(msg) { err_n++; if (err_first <= 0) err_first = __LINE__; printf msg; }
+
+int main () {
+	int err_n = 0;
+	int err_first = 0;
+	DECL(I,8)
+	DECL(U,8)
+	DECL(I,16)
+	DECL(U,16)
+	DECL(I,32)
+	DECL(U,32)
+#ifdef INT64_MAX
+	DECL(I,64)
+	DECL(U,64)
+#endif
+	intmax_t imax = INTMAX_C(0);
+	uintmax_t umax = UINTMAX_C(0);
+	char str0[256], str1[256];
+
+	sprintf (str0, "%" PRINTF_INT32_MODIFIER "d", INT32_C(2147483647));
+	if (0 != strcmp (str0, "2147483647")) REPORTERROR (("Something wrong with PRINTF_INT32_MODIFIER : %s\n", str0));
+	if (atoi(PRINTF_INT32_DEC_WIDTH) != (int) strlen(str0)) REPORTERROR (("Something wrong with PRINTF_INT32_DEC_WIDTH : %s\n", PRINTF_INT32_DEC_WIDTH));
+	sprintf (str0, "%" PRINTF_INT32_MODIFIER "u", UINT32_C(4294967295));
+	if (0 != strcmp (str0, "4294967295")) REPORTERROR (("Something wrong with PRINTF_INT32_MODIFIER : %s\n", str0));
+	if (atoi(PRINTF_UINT32_DEC_WIDTH) != (int) strlen(str0)) REPORTERROR (("Something wrong with PRINTF_UINT32_DEC_WIDTH : %s\n", PRINTF_UINT32_DEC_WIDTH));
+#ifdef INT64_MAX
+	sprintf (str1, "%" PRINTF_INT64_MODIFIER "d", INT64_C(9223372036854775807));
+	if (0 != strcmp (str1, "9223372036854775807")) REPORTERROR (("Something wrong with PRINTF_INT32_MODIFIER : %s\n", str1));
+	if (atoi(PRINTF_INT64_DEC_WIDTH) != (int) strlen(str1)) REPORTERROR (("Something wrong with PRINTF_INT64_DEC_WIDTH : %s, %d\n", PRINTF_INT64_DEC_WIDTH, (int) strlen(str1)));
+	sprintf (str1, "%" PRINTF_INT64_MODIFIER "u", UINT64_C(18446744073709550591));
+	if (0 != strcmp (str1, "18446744073709550591")) REPORTERROR (("Something wrong with PRINTF_INT32_MODIFIER : %s\n", str1));
+	if (atoi(PRINTF_UINT64_DEC_WIDTH) != (int) strlen(str1)) REPORTERROR (("Something wrong with PRINTF_UINT64_DEC_WIDTH : %s, %d\n", PRINTF_UINT64_DEC_WIDTH, (int) strlen(str1)));
+#endif
+
+	sprintf (str0, "%d %x\n", 0, ~0);
+
+	sprintf (str1, "%d %x\n",  i8, ~0);
+	if (0 != strcmp (str0, str1)) REPORTERROR (("Something wrong with i8 : %s\n", str1));
+	sprintf (str1, "%u %x\n",  u8, ~0);
+	if (0 != strcmp (str0, str1)) REPORTERROR (("Something wrong with u8 : %s\n", str1));
+	sprintf (str1, "%d %x\n",  i16, ~0);
+	if (0 != strcmp (str0, str1)) REPORTERROR (("Something wrong with i16 : %s\n", str1));
+	sprintf (str1, "%u %x\n",  u16, ~0);
+	if (0 != strcmp (str0, str1)) REPORTERROR (("Something wrong with u16 : %s\n", str1));
+	sprintf (str1, "%" PRINTF_INT32_MODIFIER "d %x\n",  i32, ~0);
+	if (0 != strcmp (str0, str1)) REPORTERROR (("Something wrong with i32 : %s\n", str1));
+	sprintf (str1, "%" PRINTF_INT32_MODIFIER "u %x\n",  u32, ~0);
+	if (0 != strcmp (str0, str1)) REPORTERROR (("Something wrong with u32 : %s\n", str1));
+#ifdef INT64_MAX
+	sprintf (str1, "%" PRINTF_INT64_MODIFIER "d %x\n",  i64, ~0);
+	if (0 != strcmp (str0, str1)) REPORTERROR (("Something wrong with i64 : %s\n", str1));
+#endif
+	sprintf (str1, "%" PRINTF_INTMAX_MODIFIER "d %x\n",  imax, ~0);
+	if (0 != strcmp (str0, str1)) REPORTERROR (("Something wrong with imax : %s\n", str1));
+	sprintf (str1, "%" PRINTF_INTMAX_MODIFIER "u %x\n",  umax, ~0);
+	if (0 != strcmp (str0, str1)) REPORTERROR (("Something wrong with umax : %s\n", str1));
+
+	TESTUMAX(8);
+	TESTUMAX(16);
+	TESTUMAX(32);
+#ifdef INT64_MAX
+	TESTUMAX(64);
+#endif
+
+#define STR(v) #v
+#define Q(v) printf ("sizeof " STR(v) " = %u\n", (unsigned) sizeof (v));
+	if (err_n) {
+		printf ("pstdint.h is not correct.  Please use sizes below to correct it:\n");
+	}
+
+	Q(int)
+	Q(unsigned)
+	Q(long int)
+	Q(short int)
+	Q(int8_t)
+	Q(int16_t)
+	Q(int32_t)
+#ifdef INT64_MAX
+	Q(int64_t)
+#endif
+
+	return EXIT_SUCCESS;
+}
+
+#endif
