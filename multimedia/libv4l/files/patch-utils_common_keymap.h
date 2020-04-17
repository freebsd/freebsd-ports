--- utils/common/keymap.h.orig	2020-04-09 16:29:54 UTC
+++ utils/common/keymap.h
@@ -2,6 +2,8 @@
 #ifndef __KEYMAP_H
 #define __KEYMAP_H
 
+#include <stdint.h>
+
 struct keymap {
 	struct keymap *next;
 	char *name;
@@ -20,16 +22,16 @@ struct protocol_param {
 
 struct scancode_entry {
 	struct scancode_entry *next;
-	u_int32_t scancode;
+	uint32_t scancode;
 	char *keycode;
 };
 
 struct raw_entry {
 	struct raw_entry *next;
-	u_int32_t scancode;
-	u_int32_t raw_length;
+	uint32_t scancode;
+	uint32_t raw_length;
 	char *keycode;
-	u_int32_t raw[1];
+	uint32_t raw[1];
 };
 
 void free_keymap(struct keymap *map);
