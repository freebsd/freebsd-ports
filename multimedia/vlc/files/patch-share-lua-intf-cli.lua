--- share/lua/intf/cli.lua.orig	2015-07-11 02:39:34.126886159 +0000
+++ share/lua/intf/cli.lua	2015-07-11 02:54:46.665888389 +0000
@@ -343,7 +343,7 @@
                 end
                 if val.args then str = str .. " " .. val.args end
                 if #str%2 == 1 then str = str .. " " end
-                str = str .. string.rep(" .",(width-(#str+#val.help)-1)/2)
+                str = str .. string.rep(" .",math.floor((width-(#str+#val.help)-1)/2))
                 str = str .. string.rep(" ",width-#str-#val.help) .. val.help
             end
             client:append(str)
