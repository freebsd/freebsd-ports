--- SysInfo/__init__.py.orig	Mon Jan  5 23:16:50 2004
+++ SysInfo/__init__.py	Wed Jan  7 12:50:31 2004
@@ -23,8 +23,9 @@
 
         self.__backgr = ""
 
-        self.__key_color = ""
-        self.__val_color = ""
+        self.__key_color   = ""
+        self.__val_color   = ""
+        self.__title_color = ""
 
         self.__current_size = 0
         self.__size_changed = 0
@@ -40,6 +41,7 @@
         self._set_config_type("fonts", TYPE_STRING, "Sans 10")
         self._set_config_type("key_color", TYPE_STRING, "white")
         self._set_config_type("val_color", TYPE_STRING, "yellow")
+        self._set_config_type("title_color", TYPE_STRING, "#FFA500")
         self._set_config_type("background", TYPE_STRING, "gfx/bg.png")
         self._set_config_type("memory", TYPE_STRING, "RAM")
         self._set_config_type("partition", TYPE_STRING, "/")
@@ -74,6 +76,8 @@
                                         _("The color of the key"))
         configurator.add_color_selector(_("Value color:"), "val_color",
                                         _("The color of the value"))
+        configurator.add_color_selector(_("Title color:"), "title_color",
+                                        _("The color of the titles"))
         configurator.add_option(_("Partition:"), "partition",
                                 "Specify partition type", part)
         configurator.add_option(_("Memory:"), "memory",
@@ -103,8 +107,9 @@
         idle_d, idle_h, idle_m, idle_s = lib.convert.secs_to_dhms(idletime)
         idle_p                         = (idletime / float(uptime)) * 100
 
-        signal.set("value1[%(index)d]"    % vars(), os + " @ " + name)
-        signal.set("value2[%(index)d]"    % vars(), kernel[:6])
+        signal.set("value1[%(index)d]"    % vars(), os + " @ " + \
+                   name.split(".")[0])
+        signal.set("value2[%(index)d]"    % vars(), kernel)
         signal.set("value3[%(index)d]"    % vars(), str(l1) + " " + str(l5) + \
                     " " + str(l15))
         signal.set("value4[%(index)d]"    % vars(), users)
@@ -128,7 +133,7 @@
 
         cpu_type    = lib.cpu.get_model()
         cpu_speed   = lib.cpu.get_speed()
-        cpu_cache   = lib.cpu.get_cache_size()
+        cpu_cache   = "Unknown"
         total, load = lib.cpu.get_load()
 
         signal.set("value1[%(index)d]"    % vars(), cpu_type)
@@ -234,20 +239,22 @@
 
         index = 0
 
-        fonts      = self._get_config("fonts")
-        key_color  = self._get_config("key_color")
-        val_color  = self._get_config("val_color")
-        background = self._get_config("background")
-
-        v1 = (self.__fonts, self.__key_color, self.__val_color, self.__backgr)
-        v2 = (fonts, key_color, val_color, background)
+        fonts       = self._get_config("fonts")
+        key_color   = self._get_config("key_color")
+        val_color   = self._get_config("val_color")
+        title_color = self._get_config("title_color")
+        background  = self._get_config("background")
+
+        v1 = (self.__fonts, self.__key_color, self.__val_color,
+              self.__title_color, self.__backgr)
+        v2 = (fonts, key_color, val_color, title_color, background)
 
         # only take action when some value has changed
         if (v1 != v2 or self.__size_changed):
             signal = self._new_output()
 
             signal.set("icon[%(index)d]" % vars(), "gfx/Info.png")
-            signal.set("key1[%(index)d]" % vars(), _(""))
+            signal.set("key1[%(index)d]" % vars(), (""))
             signal.set("key2[%(index)d]" % vars(), _("Kernel:"))
             signal.set("key3[%(index)d]" % vars(), _("Load:"))
             signal.set("key4[%(index)d]" % vars(), _("Users:"))
@@ -255,25 +262,25 @@
             signal.set("key6[%(index)d]" % vars(), _("Idle time:"))
             index += 1
             signal.set("icon[%(index)d]" % vars(), "gfx/cpu.png")
-            signal.set("key1[%(index)d]" % vars(), _(""))
+            signal.set("key1[%(index)d]" % vars(), (""))
             signal.set("key2[%(index)d]" % vars(), _("Clock:"))
             signal.set("key3[%(index)d]" % vars(), _("Cache:"))
             signal.set("key4[%(index)d]" % vars(), _("Idle time:"))
             index += 1
             signal.set("icon[%(index)d]" % vars(), "gfx/memory.png")
-            signal.set("key1[%(index)d]" % vars(), _(""))
+            signal.set("key1[%(index)d]" % vars(), (""))
             signal.set("key2[%(index)d]" % vars(), _("Total:"))
             signal.set("key3[%(index)d]" % vars(), _("Used:"))
             signal.set("key4[%(index)d]" % vars(), _("Free:"))
             index += 1
             signal.set("icon[%(index)d]" % vars(), "gfx/hdd.png")
-            signal.set("key1[%(index)d]" % vars(), _(""))
+            signal.set("key1[%(index)d]" % vars(), (""))
             signal.set("key2[%(index)d]" % vars(), _("Total:"))
             signal.set("key3[%(index)d]" % vars(), _("Used:"))
             signal.set("key4[%(index)d]" % vars(), _("Free:"))
             index += 1
             signal.set("icon[%(index)d]" % vars(), "gfx/network.png")
-            signal.set("key1[%(index)d]" % vars(), _(""))
+            signal.set("key1[%(index)d]" % vars(), (""))
             signal.set("key2[%(index)d]" % vars(), _("IP addr:"))
             signal.set("key3[%(index)d]" % vars(), _("Bytes in:"))
             signal.set("key4[%(index)d]" % vars(), _("Bytes out:"))
@@ -292,12 +299,16 @@
             if (self.__val_color != val_color or self.__size_changed):
                 for i in xrange(self.__array_size):
                     signal.set("val_color[%(i)d]" %vars(), val_color)
+            if (self.__title_color != title_color or self.__size_changed):
+                for i in xrange(self.__array_size):
+                    signal.set("title_color[%(i)d]" %vars(), title_color)
 
             self._send_output(signal)
 
             self.__fonts        = fonts
             self.__key_color    = key_color
             self.__val_color    = val_color
+            self.__title_color  = title_color
             self.__backgr       = background
             self.__size_changed = 0
 
