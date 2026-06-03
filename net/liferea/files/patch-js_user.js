taken from:
commit 000a8b75f98f2cf444694a03ca24f9f1d27d037f
Author: Lars Windolf <lars.windolf@gmx.de>
Date:   Sat Dec 27 23:56:49 2025 +0100

    Support user.js to hook into rendering

diff --git js/user.js js/user.js
new file mode 100644
index 00000000..16af9bdc
--- /dev/null
+++ js/user.js
@@ -0,0 +1,24 @@
+// This is a JS hook that allows you to hack the Liferea rendering
+//
+// It is invoked by the htmlview.js rendering scripting and provides you
+// with hooks one to modify the data before rendering and one to modify
+// or enhance the rendering after it is done.
+
+// hooks to modify item info rendering
+
+window.hookPreItemRendering = (data) => {
+        return data;
+};
+window.hookPostItemRendering = () => {
+        // Modify DOM as you like
+};
+
+// hooks to modify node info rendering
+
+window.hookPreNodeRendering = (data) => {
+        return data;
+
+};
+window.hookPostNodeRendering = () => {
+        // Modify DOM as you like
+};
\ No newline at end of file
