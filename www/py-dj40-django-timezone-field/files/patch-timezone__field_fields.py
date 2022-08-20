From 0257f2e9c7c488e8a859ee924c93d9f38afa4dc7 Mon Sep 17 00:00:00 2001
From: jeremystretch <jstretch@ns1.com>
Date: Fri, 12 Aug 2022 10:03:27 -0400
Subject: [PATCH] Fixes #94: Catch ZoneInfoNotFoundError exception when
 populating timezones

Obtained from:

https://github.com/mfogel/django-timezone-field/commit/0257f2e9c7c488e8a859ee924c93d9f38afa4dc7

--- timezone_field/fields.py.orig	2022-02-09 04:42:10 UTC
+++ timezone_field/fields.py
@@ -38,7 +38,13 @@ class TimeZoneField(models.Field):
     #       existing migration files will need to be accomodated.
     default_max_length = 63
     default_pytz_tzs = [pytz.timezone(tz) for tz in pytz.common_timezones]
-    default_zoneinfo_tzs = [ZoneInfo(tz) for tz in pytz.common_timezones]
+    default_zoneinfo_tzs = []
+    for tz in pytz.common_timezones:
+        try:
+            default_zoneinfo_tzs.append(ZoneInfo(tz))
+        except ZoneInfoNotFoundError:
+            # ZoneInfo does not yet exist for this timezone
+            pass
 
     def __init__(self, *args, **kwargs):
         # allow some use of positional args up until the args we customize
