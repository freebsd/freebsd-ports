--- pootle/apps/pootle_store/models.py.orig	2015-06-03 13:30:23 UTC
+++ pootle/apps/pootle_store/models.py
@@ -32,9 +32,8 @@ from django.conf import settings
 from django.core.exceptions import ObjectDoesNotExist
 from django.core.files.storage import FileSystemStorage
 from django.core.urlresolvers import reverse
-from django.db import models, DatabaseError, IntegrityError
+from django.db import models, transaction, DatabaseError, IntegrityError
 from django.db.models.signals import post_delete, post_save, pre_delete
-from django.db.transaction import commit_on_success
 from django.utils import timezone, tzinfo
 from django.utils.translation import ugettext_lazy as _
 
@@ -1102,7 +1101,7 @@ class Store(models.Model, base.Translati
 
         return False
 
-    @commit_on_success
+    @transaction.atomic
     def parse(self, store=None):
         self.clean_stale_lock()
 
@@ -1154,7 +1153,7 @@ class Store(models.Model, base.Translati
         if obsolete_unit:
             obsolete_unit.delete()
 
-    @commit_on_success
+    @transaction.atomic
     def update(self, update_structure=False, update_translation=False,
                store=None, fuzzy=False, only_newer=False, modified_since=0):
         """Update DB with units from file.
@@ -1320,7 +1319,7 @@ class Store(models.Model, base.Translati
             # new qualitychecks, let's flush cache
             deletefromcache(self, ["getcompletestats"])
 
-    @commit_on_success
+    @transaction.atomic
     def update_qualitychecks(self):
         logging.debug(u"Updating quality checks for %s", self.pootle_path)
         for unit in self.units.iterator():
@@ -1583,7 +1582,7 @@ class Store(models.Model, base.Translati
         """Returns a single unit based on the item number."""
         return self.units[item]
 
-    @commit_on_success
+    @transaction.atomic
     def mergefile(self, newfile, profile, allownewstrings, suggestions,
                   notranslate, obsoletemissing):
         """Merges :param:`newfile` with the current store.
@@ -1778,7 +1777,7 @@ class Store(models.Model, base.Translati
             self.pending = pending_name
             self.save()
 
-    @commit_on_success
+    @transaction.atomic
     def import_pending(self):
         """import suggestions from legacy .pending files, into database"""
         self.init_pending()
