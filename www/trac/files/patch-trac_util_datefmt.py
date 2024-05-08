--- trac/util/datefmt.py.orig	2023-09-22 23:00:43 UTC
+++ trac/util/datefmt.py
@@ -34,6 +34,7 @@ else:
     from babel import Locale
     from babel.core import LOCALE_ALIASES, UnknownLocaleError
     from babel.dates import (
+        DateTimeFormat,
         format_datetime as babel_format_datetime,
         format_date as babel_format_date,
         format_time as babel_format_time,
@@ -44,8 +45,9 @@ else:
     )
     # 'context' parameter was added in Babel 2.3.1
     if 'context' in inspect.signature(babel_get_period_names).parameters:
-        def get_period_names(locale=None):
-            return babel_get_period_names(context='format', locale=locale)
+        def get_period_names(width='wide', locale=None):
+            return babel_get_period_names(width=width, context='format',
+                                          locale=locale)
     else:
         get_period_names = babel_get_period_names
 
@@ -292,16 +294,40 @@ def _format_datetime(t, format, tzinfo, locale, hint):
             hint = _STRFTIME_HINTS[format]
             format = 'medium'
         if format in ('short', 'medium', 'long', 'full'):
-            if hint == 'datetime':
-                return babel_format_datetime(t, format, None, locale)
-            if hint == 'date':
-                return babel_format_date(t, format, locale)
-            if hint == 'time':
-                return babel_format_time(t, format, None, locale)
+            return _format_datetime_babel(t, format, locale, hint)
 
     format = _BABEL_FORMATS[hint].get(format, format)
     return _format_datetime_without_babel(t, format)
 
+if babel:
+    class _DateTimeFormatFixup(DateTimeFormat):
+        def __getitem__(self, name):
+            if name.startswith(('b', 'B')):
+                return self.format_period('a', len(name))
+            else:
+                return super().__getitem__(name)
+
+def _format_datetime_babel(t, format, locale, hint):
+    if hint in ('datetime', 'date'):
+        datepart = babel_format_date(t, format, locale)
+        if hint == 'date':
+            return datepart
+    if hint in ('datetime', 'time'):
+        time_format = get_time_format(format, locale)
+        # Use `a` period instead of `b` and `B` periods because `parse_date`
+        # and jQuery timepicker addon don't support the periods
+        if '%(b' in time_format.format or '%(B' in time_format.format:
+            timepart = time_format.format % _DateTimeFormatFixup(t, locale)
+        else:
+            timepart = babel_format_time(t, format, None, locale)
+        if hint == 'time':
+            return timepart
+    if hint == 'datetime':
+        return get_datetime_format(format, locale=locale) \
+               .replace("'", '') \
+               .replace('{0}', timepart) \
+               .replace('{1}', datepart)
+
 def format_datetime(t=None, format='%x %X', tzinfo=None, locale=None):
     """Format the `datetime` object `t` into a `str` string
 
@@ -439,24 +465,29 @@ def get_time_format_jquery_ui(locale):
     """Get the time format for the jQuery UI timepicker addon."""
     if locale == 'iso8601':
         return 'HH:mm:ssZ'
+
+    t = datetime(1999, 10, 29, 23, 59, 58, tzinfo=utc)
     if babel and locale:
         values = {'h': 'h', 'hh': 'hh', 'H': 'H', 'HH': 'HH',
                   'm': 'm', 'mm': 'mm', 's': 's', 'ss': 'ss'}
-        f = get_time_format('medium', locale=locale).format
-        if '%(a)s' in f:
-            t = datetime(1999, 10, 29, 23, 59, 58, tzinfo=utc)
+        # Use `a` period instead of `b` and `B` periods, because jQuery
+        # timepicker addon doesn't support the periods.
+        tmpl = babel_format_time(t, tzinfo=utc, locale=locale)
+        if '23' not in tmpl:
             ampm = babel_format_datetime(t, 'a', None, locale)
-            values['a'] = 'TT' if ampm[0].isupper() else 'tt'
+            ampm = 'TT' if ampm[0].isupper() else 'tt'
+            values.update((period * n, ampm) for period in ('a', 'b', 'B')
+                                             for n in range(1, 6))
+        f = get_time_format('medium', locale=locale).format
         return f % values
+    else:
+        tmpl = format_time(t, tzinfo=utc)
+        ampm = format_time(t, '%p', tzinfo=utc)
+        if ampm:
+            tmpl = tmpl.replace(ampm, 'TT' if ampm[0].isupper() else 'tt', 1)
+        return tmpl.replace('23', 'HH', 1).replace('11', 'hh', 1) \
+                   .replace('59', 'mm', 1).replace('58', 'ss', 1)
 
-    t = datetime(1999, 10, 29, 23, 59, 58, tzinfo=utc)
-    tmpl = format_time(t, tzinfo=utc)
-    ampm = format_time(t, '%p', tzinfo=utc)
-    if ampm:
-        tmpl = tmpl.replace(ampm, 'TT' if ampm[0].isupper() else 'tt', 1)
-    return tmpl.replace('23', 'HH', 1).replace('11', 'hh', 1) \
-               .replace('59', 'mm', 1).replace('58', 'ss', 1)
-
 def get_timezone_list_jquery_ui(t=None):
     """Get timezone list for jQuery timepicker addon"""
     def utcoffset(tz, t):  # in minutes
@@ -701,20 +732,21 @@ def _i18n_parse_date_pattern(locale):
             if name:
                 period_names[name.lower()] = period
     else:
-        if formats[0].find('%(MMM)s') != -1:
-            for width in ('wide', 'abbreviated'):
-                names = get_month_names(width, locale=locale)
-                month_names.update((name.lower(), num)
-                                   for num, name in names.items())
-        if formats[0].find('%(a)s') != -1:
-            names = get_period_names(locale=locale)
+        for width in ('wide', 'abbreviated'):
+            names = get_month_names(width=width, locale=locale)
+            month_names.update((name.lower(), num)
+                               for num, name in names.items())
+            names = get_period_names(width=width, locale=locale)
             period_names.update((name.lower(), period)
                                 for period, name in names.items()
                                 if period in ('am', 'pm'))
 
-    regexp = ['[0-9]+']
-    regexp.extend(re.escape(name) for name in month_names)
-    regexp.extend(re.escape(name) for name in period_names)
+    regexp = []
+    regexp.extend(month_names)
+    regexp.extend(period_names)
+    regexp.sort(key=lambda v: len(v), reverse=True)
+    regexp = list(map(re.escape, regexp))
+    regexp.append('[0-9]+')
 
     return {
         'orders': orders,
