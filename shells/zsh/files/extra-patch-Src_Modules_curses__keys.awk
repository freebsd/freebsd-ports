https://sourceforge.net/p/zsh/code/ci/c6a85163619ed1cee89ab047a0d98108ed46828d/
--- Src/Modules/curses_keys.awk.orig	2017-12-04 14:09:36 UTC
+++ Src/Modules/curses_keys.awk
@@ -12,8 +12,13 @@ BEGIN {nkeydefs = 0}
 
 END {
     printf("static const struct zcurses_namenumberpair keypad_names[] = {\n")
-    for (i = 0; i < 0 + nkeydefs; i++)
+    for (i = 0; i < 0 + nkeydefs; i++) {
+        if (name[i] == "EVENT")
+            printf("#ifdef KEY_EVENT\n")
         printf("    {\"%s\", KEY_%s},\n", name[i], name[i])
+        if (name[i] == "EVENT")
+            printf("#endif\n")
+    }
     printf("    {NULL, 0}\n")
     printf("};\n")
 }
