--- media_tree/include/linux/input.h.orig
+++ media_tree/include/linux/input.h
@@ -104,8 +104,12 @@ struct input_keymap_entry {
 #define EVIOCGREP		_IOR('E', 0x03, unsigned int[2])	/* get repeat settings */
 #define EVIOCSREP		_IOW('E', 0x03, unsigned int[2])	/* set repeat settings */
 
-#define EVIOCGKEYCODE		_IOR('E', 0x04, unsigned int[2])        /* get keycode */
-#define EVIOCGKEYCODE_V2	_IOR('E', 0x04, struct input_keymap_entry)
+/*
+ * These two need to be _IOWR not _IOR (they're wrong on Linux too but
+ * there the driver doesn't care.)
+ */
+#define EVIOCGKEYCODE		_IOWR('E', 0x04, unsigned int[2])       /* get keycode */
+#define EVIOCGKEYCODE_V2	_IOWR('E', 0x04, struct input_keymap_entry)
 #define EVIOCSKEYCODE		_IOW('E', 0x04, unsigned int[2])        /* set keycode */
 #define EVIOCSKEYCODE_V2	_IOW('E', 0x04, struct input_keymap_entry)
 
