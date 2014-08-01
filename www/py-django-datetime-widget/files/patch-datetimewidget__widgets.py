diff --git a/datetimewidget/widgets.py b/datetimewidget/widgets.py
index c62930a..3675f0e 100644
--- datetimewidget/widgets.py.orig
+++ datetimewidget/widgets.py
@@ -131,7 +131,7 @@ class DateTimeWidget(MultiWidget):
         ]
         try:
             D = to_current_timezone(datetime.strptime(date_time[0], self.format))
-        except (ValueError, TypeError), e:
+        except (ValueError, TypeError) as e :
             return ''
         else:
             return D
@@ -181,4 +181,4 @@ class DateTimeWidget(MultiWidget):
             },
             js=js
         )
-    media = property(_media)
\ No newline at end of file
+    media = property(_media)
