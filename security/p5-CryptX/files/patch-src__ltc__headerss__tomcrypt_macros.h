--- src/ltc/headers/tomcrypt_macros.h.orig	2014-01-23 16:45:59.000000000 +0100
+++ src/ltc/headers/tomcrypt_macros.h	2015-03-02 20:23:48.396007000 +0100
@@ -281,21 +281,19 @@
 
 #ifndef LTC_NO_ROLC
 
-static inline ulong32 ROLc(ulong32 word, const int i)
-{
-   asm ("roll %2,%0"
-      :"=r" (word)
-      :"0" (word),"I" (i));
-   return word;
-}
-
-static inline ulong32 RORc(ulong32 word, const int i)
-{
-   asm ("rorl %2,%0"
-      :"=r" (word)
-      :"0" (word),"I" (i));
-   return word;
-}
+#define ROLc(word, i) ({     \
+   ulong32 _word = word;     \
+   asm ("roll %2,%0"         \
+      :"=r" (_word)          \
+      :"0" (_word),"I" (i)); \
+   _word; })
+
+#define RORc(word, i) ({     \
+   ulong32 _word = word;     \
+   asm ("rorl %2,%0"         \
+      :"=r" (_word)          \
+      :"0" (_word),"I" (i)); \
+   _word; })
 
 #else
 
@@ -324,21 +322,19 @@
 
 #ifndef LTC_NO_ROLC
 
-static inline ulong32 ROLc(ulong32 word, const int i)
-{
-   asm ("rotlwi %0,%0,%2"
-      :"=r" (word)
-      :"0" (word),"I" (i));
-   return word;
-}
-
-static inline ulong32 RORc(ulong32 word, const int i)
-{
-   asm ("rotrwi %0,%0,%2"
-      :"=r" (word)
-      :"0" (word),"I" (i));
-   return word;
-}
+#define ROLc(word, i) ({     \
+   ulong32 _word = word;     \
+   asm ("rotlwi %0,%0,%2"    \
+      :"=r" (_word)          \
+      :"0" (_word),"I" (i)); \
+   _word; })
+
+#define RORc(word, i) ({     \
+   ulong32 _word = word;     \
+   asm ("rotrwi %0,%0,%2"    \
+      :"=r" (_word)          \
+      :"0" (_word),"I" (i)); \
+   _word; })
 
 #else
 
@@ -380,21 +376,19 @@
 
 #ifndef LTC_NO_ROLC
 
-static inline ulong64 ROL64c(ulong64 word, const int i)
-{
-   asm("rolq %2,%0"
-      :"=r" (word)
-      :"0" (word),"J" (i));
-   return word;
-}
-
-static inline ulong64 ROR64c(ulong64 word, const int i)
-{
-   asm("rorq %2,%0"
-      :"=r" (word)
-      :"0" (word),"J" (i));
-   return word;
-}
+#define ROL64c(word, i) ({     \
+   ulong64 _word = word;       \
+   asm ("rolq %2,%0"           \
+      :"=r" (_word)            \
+      :"0" (_word),"J" (i));   \
+   _word; })
+
+#define ROR64c(word, i) ({     \
+   ulong64 _word = word;       \
+   asm ("rorq %2,%0"           \
+      :"=r" (_word)            \
+      :"0" (_word),"J" (i));   \
+   _word; })
 
 #else /* LTC_NO_ROLC */
 
