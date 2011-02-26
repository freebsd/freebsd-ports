--- src/googlecl/calendar/__init__.py.bak	2011-02-17 10:11:57.000000000 +0100
+++ src/googlecl/calendar/__init__.py	2011-02-17 10:14:06.000000000 +0100
@@ -235,12 +235,22 @@
 
 
 class CalendarEntryToStringWrapper(googlecl.base.BaseEntryToStringWrapper):
+  def __init__(self, entry, config):
+    """Initialize a CalendarEntry wrapper.
+
+    Args:
+      entry: CalendarEntry to interpret to strings.
+      config: Configuration parser. Needed for some values.
+    """
+    googlecl.base.BaseEntryToStringWrapper.__init__(self, entry)
+    self.config_parser = config
+
   @property
   def when(self):
     """When event takes place."""
     start_date, end_date, freq = get_datetimes(self.entry)
-    print_format = googlecl.CONFIG.lazy_get(SECTION_HEADER,
-                                            'date_print_format')
+    print_format = self.config_parser.lazy_get(SECTION_HEADER,
+                                                      'date_print_format')
     start_text = time.strftime(print_format, start_date)
     end_text = time.strftime(print_format, end_date)
     value = start_text + ' - ' + end_text
@@ -277,9 +287,9 @@
 
     for entry in single_events:
       print googlecl.base.compile_entry_string(
-                                            CalendarEntryToStringWrapper(entry),
-                                            options.fields.split(','),
-                                            delimiter=options.delimiter)
+                            CalendarEntryToStringWrapper(entry, client.config),
+                            options.fields.split(','),
+                            delimiter=options.delimiter)
 
 
 #===============================================================================
