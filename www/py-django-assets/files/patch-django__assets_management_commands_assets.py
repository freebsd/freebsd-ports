From: Madison Swain-Bowden <bowdenm@spu.edu>
Date: Sat, 5 Nov 2022 14:08:05 -0700
Subject: [PATCH] Fix issue with running  in Django 4.1

Obtained from:

https://patch-diff.githubusercontent.com/raw/miracle2k/django-assets/pull/103.patch

--- django_assets/management/commands/assets.py.orig	2024-03-24 15:11:16 UTC
+++ django_assets/management/commands/assets.py
@@ -37,7 +37,7 @@ class Command(BaseCommand):
 
 class Command(BaseCommand):
     help = 'Manage assets.'
-    requires_system_checks = False
+    requires_system_checks = []
 
     def add_arguments(self, parser):
         # parser.add_argument('poll_id', nargs='+', type=str)
