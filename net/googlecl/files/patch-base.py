--- src/googlecl/base.py.bak	2011-02-17 10:23:53.000000000 +0100
+++ src/googlecl/base.py	2011-02-17 10:24:55.000000000 +0100
@@ -671,12 +671,13 @@
       # with the missing field value.
       val = getattr(wrapped_entry, attr.replace('-','_')) or missing_field_value
     except ValueError, err:
-      LOG.debug(err.args[0] + ' (Did not add value for field ' + attr + ')')
+      LOG.debug(err.args[0] + ' (value for field ' + attr + ')')
     except AttributeError, err:
       try:
         # Last ditch effort to blindly grab the attribute
         val = getattr(wrapped_entry.entry, attr).text or missing_field_value
       except AttributeError:
+        LOG.debug(err.args[0] + ' (value for field ' + attr + ')')
         val = missing_field_value
     # Apparently, atom(?) doesn't always return a Unicode type when there are
     # non-latin characters, so force everything to Unicode.
