--- __init__.py.bak	Tue Mar 30 18:08:39 2004
+++ __init__.py	Tue Mar 30 18:11:36 2004
@@ -149,8 +149,11 @@
         timezone = self._get_config("timezone")
         if (timezone != self.__timezone):
             self.__timezone = timezone
-            offset = commands.getoutput("TZ=\"%(timezone)s\" date +%%z"
-                                        % vars())
+            if timezone == "localtime":
+                offset = commands.getoutput("date +%z")
+            else:
+                offset = commands.getoutput("TZ=\"%(timezone)s\" date +%%z"
+                                            % vars())
             sign = (offset[0] == "+") and 1 or -1
             hours = int(offset[1:3])
             mins = int(offset[3:5])
