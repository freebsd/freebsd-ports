diff --git js/gopher-renderer.js js/gopher-renderer.js
new file mode 100644
index 00000000..1167e77e
--- /dev/null
+++ js/gopher-renderer.js
@@ -0,0 +1,122 @@
+// vim: set ts=4 sw=4:  
+/*
+ * @file gopher-renderer.js  render gopher:// fetched resources in Lifereas internal browser
+ *
+ * Copyright (C) 2025 Lars Windolf <lars.windolf@gmx.de>
+ *
+ * This program is free software; you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation; either version 2 of the License, or
+ * (at your option) any later version.
+ *
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License
+ * along with this program; if not, write to the Free Software
+ * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
+ */
+
+// Needed because Gopher is Latin-1 encoded and we want to render UTF-8 with emojis
+function convertLatin1ToUtf8(latin1String) {
+    try {
+        const decoder = new TextDecoder('iso-8859-1');
+        const uint8Array = new Uint8Array(latin1String.split('').map(char => char.charCodeAt(0)));
+        const utf8String = decoder.decode(uint8Array);
+        return utf8String;
+    } catch (e) {
+        console.error("TextDecoder failed, falling back to original string");
+        return latin1String;
+    }
+}
+
+function renderListing(el, gopherData) {
+    const lines = gopherData.split('\n');
+    lines.forEach(line => {
+        const [field1, path, host, port] = line.split('\t');
+        const type = field1.charAt(0);
+        const title = field1.slice(1);
+        const item = document.createElement('div');
+        let icon = '';
+        switch (type) {
+            case '0':
+                icon = '📄';
+                break;
+            case '1':
+                icon = '📁';
+                break;
+            case '7':
+                icon = '🔍';
+                break;
+            case 'g':
+            case 'I':
+            case ':':
+                icon = '🖼️';
+                break;
+            case ';':
+                icon = '🎵';
+                break;
+            case '<':
+                icon = '🎬';
+                break;
+            case '9':
+                icon = '🔗';
+                break;
+        }
+
+        item.className = 'gopher-item';
+        switch (type) {
+            case 'i':
+                item.innerHTML = (title === "") ? " " : title;
+                break;
+            case '0':
+            case '1':
+            case '7':
+            case '9':
+            case 'g':
+            case 'I':
+            case ':':
+            case ';':
+            case '<':
+                item.innerHTML = `${icon} <a style="text-decoration: none" href="gopher://${host}:${port}/${type}${path}">${title}</a>`;
+                break;
+            default:
+                item.innerHTML = line;
+                break;
+        }
+        el.appendChild(item);
+    });
+}
+
+document.body.onload = function () {
+    const base64Data = document.body.innerText;
+    const gopherData = convertLatin1ToUtf8(atob(base64Data.replace(/=+$/, '')));
+    const uriFields = window.location.pathname.split('/');
+    let type = '1'; // default to directory listing
+
+    if (uriFields.length >= 2 && uriFields[1].length > 0)
+        type = uriFields[1].charAt(0);
+
+    document.body.innerHTML = '<tt><div id="content" class="content" style="white-space: pre"></div></tt>';
+    const div = document.getElementById('content');
+    switch (type) {
+        case '0':
+            div.innerHTML = gopherData;
+
+            // Replace all text HTTP and Gopher URIs in div with a link
+            const uriRegex = /(https?:\/\/\S+|gopher:\/\/\S+)/g;
+            div.innerHTML = div.innerHTML.replace(uriRegex, match => {
+                return `<a href="${match}" target="_blank">${match}</a>`;
+            });
+            break;
+        case '1':
+            renderListing(div, gopherData);
+            break;
+        default:
+            /* Should not happen at all, should be caught in Webkit protocol handler */
+            div.innerHTML = '<b>Liferea does not support this Gopher item type "' + uriFields[1].charAt(0) + '" for rendering. You can open this link using the floodgap.com proxy <a href="https://gopher.floodgap.com/gopher/1/' + encodeURIComponent(window.location.href) + '">click here</a>.</b>';
+            break;
+    }
+}
\ No newline at end of file
