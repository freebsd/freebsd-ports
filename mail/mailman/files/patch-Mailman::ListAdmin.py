--- /usr/local/src/mailman-2.1.5/Mailman/ListAdmin.py-2.1.5	2004-02-29 12:55:27.000000000 +0900
+++ Mailman/ListAdmin.py	2004-06-10 22:44:39.373711240 +0900
@@ -83,6 +83,8 @@
             except IOError, e:
                 if e.errno <> errno.ENOENT: raise
                 self.__db = {}
+                # put version number in new database
+                self.__db['version'] = IGN, mm_cfg.REQUESTS_FILE_SCHEMA_VERSION
 
     def __closedb(self):
         if self.__db is not None:
@@ -122,7 +124,7 @@
 
     def NumRequestsPending(self):
         self.__opendb()
-        # Subtrace one for the version pseudo-entry
+        # Subtract one for the version pseudo-entry
         return len(self.__db) - 1
 
     def __getmsgids(self, rtype):
