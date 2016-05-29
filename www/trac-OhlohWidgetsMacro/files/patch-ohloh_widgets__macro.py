--- ohloh_widgets/macro.py.orig	2010-07-04 06:54:44 UTC
+++ ohloh_widgets/macro.py
@@ -46,7 +46,7 @@ class OhlohWidgetMacro(MacroWithValidati
        ![[OhlohWidget(project_id, widget_name)]]
     
     The macro gets two parameters which you can get from Ohloh's widget page
-    for your project (!http://www.ohloh.net/p/<project name>/widgets) when you
+    for your project (!https://www.ohloh.net/p/<project name>/widgets) when you
     look at the embeddable HTML snippet:
     
      * project_id -- a 6 digit number which identifies your project
@@ -70,7 +70,7 @@ class OhlohWidgetMacro(MacroWithValidati
     
     def url(self, parameters):
         query_string = ''
-        url_template = 'http://www.ohloh.net/p/%(project_id)d/widgets/%(widget_name)s.js'
+        url_template = 'https://www.ohloh.net/p/%(project_id)d/widgets/%(widget_name)s.js'
         widget_name = parameters.widget_name
         if '?' in widget_name:
             parameters['widget_name'], query_parameters = widget_name.split('?', 1)
