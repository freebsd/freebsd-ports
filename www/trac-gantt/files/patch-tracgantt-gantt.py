--- tracgantt/gantt.py.orig	Wed Jul 19 12:10:01 2006
+++ tracgantt/gantt.py	Wed Jul 19 12:07:44 2006
@@ -230,7 +230,7 @@
                 # 16 chars in the gantt chart display.  We expose the
                 # full summary to the template, but it's not currently
                 # used.
-                sumlen = self.env.config.getint('gantt-charts',
+                sumlen = self.env.config.get('gantt-charts',
                         'summary_length', 16)
 
                 summary = ticket.values['summary']
