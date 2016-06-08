--- third_party/WebKit/Source/platform/text/Character.cpp.orig	2016-05-27 12:28:21.057082000 -0400
+++ third_party/WebKit/Source/platform/text/Character.cpp	2016-05-27 18:52:20.104602000 -0400
@@ -36,8 +36,8 @@
 #include <unicode/uobject.h>
 #include <unicode/uscript.h>
 
-#if defined(USING_SYSTEM_ICU)
-#include "platform/fonts/CharacterPropertyDataGenerator.h"
+#if defined(__FreeBSD__)
+#include "platform/text/CharacterPropertyDataGenerator.h"
 #include <unicode/uniset.h>
 #else
 #define MUTEX_H // Prevent compile failure of utrie2.h on Windows
@@ -49,7 +49,7 @@
 
 namespace blink {
 
-#if defined(USING_SYSTEM_ICU)
+#if defined(__FreeBSD__)
 static icu::UnicodeSet* createUnicodeSet(
     const UChar32* characters, size_t charactersCount,
     const UChar32* ranges, size_t rangesCount)
