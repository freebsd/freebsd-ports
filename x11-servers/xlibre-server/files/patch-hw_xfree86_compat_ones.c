--- hw/xfree86/compat/ones.c.orig
+++ hw/xfree86/compat/ones.c
@@ -20,8 +20,12 @@ int
 Ones(unsigned long mask)
 {                               /* HACKMEM 169 */
     /* can't add a message here because this should be fast */
+#if defined __has_builtin
 #if __has_builtin(__builtin_popcountl)
     return __builtin_popcountl (mask);
+#endif
+#elif defined __builtin_popcountl
+    return __builtin_popcountl (mask);
 #else
     unsigned long y;
 
