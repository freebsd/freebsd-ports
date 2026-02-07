--- tests/storage/sqlite/sqlite_file.py.orig	2024-06-08 09:38:23 UTC
+++ tests/storage/sqlite/sqlite_file.py
@@ -136,13 +136,13 @@ class SQLiteStorageFileTest(test_lib.StorageTestCase):
             event_data_stream.CONTAINER_TYPE, column_names=column_names))
         self.assertEqual(len(containers), 1)
 
-        filter_expression = 'md5_hash == "8f0bf95a7959baad9666b21a7feed79d"'
+        filter_expression = 'md5_hash == \'8f0bf95a7959baad9666b21a7feed79d\''
         containers = list(test_store._GetAttributeContainersWithFilter(
             event_data_stream.CONTAINER_TYPE, column_names=column_names,
             filter_expression=filter_expression))
         self.assertEqual(len(containers), 1)
 
-        filter_expression = 'md5_hash != "8f0bf95a7959baad9666b21a7feed79d"'
+        filter_expression = 'md5_hash != \'8f0bf95a7959baad9666b21a7feed79d\''
         containers = list(test_store._GetAttributeContainersWithFilter(
             event_data_stream.CONTAINER_TYPE, column_names=column_names,
             filter_expression=filter_expression))
