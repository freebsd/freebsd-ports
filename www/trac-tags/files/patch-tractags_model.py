--- tractags/model.py.orig
+++ tractags/model.py
@@ -62,17 +62,7 @@
         self._upgrade_db(db)
 
     def _need_migration(self, db):
-        try:
-            cursor = db.cursor()
-            cursor.execute("SELECT COUNT(*) FROM wiki_namespace")
-            cursor.fetchone()
-            self.env.log.debug("tractags needs to migrate old data")
-            return True
-        except Exception, e:
-            # The expected outcome for any up-to-date installation.
-            if self.rollback_is_safe:
-                db.rollback()
-            return False
+	return False
 
     def _upgrade_db(self, db):
         try:
