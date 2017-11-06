Reported upstream

TestSQLApi/TestSQLApiConn::test_database_uri_string errors if pg8000
is installed
https://github.com/pandas-dev/pandas/issues/16527

--- pandas/tests/io/test_sql.py.orig	2017-05-28 19:28:19 UTC
+++ pandas/tests/io/test_sql.py
@@ -938,6 +938,12 @@ class TestSQLApi(SQLAlchemyMixIn, _TestS
 
         # using driver that will not be installed on Travis to trigger error
         # in sqlalchemy.create_engine -> test passing of this error to user
+        try:
+            import pg8000
+            pytest.skip("pg8000 is installed")
+        except ImportError:
+            pass
+
         db_uri = "postgresql+pg8000://user:pass@host/dbname"
         with tm.assert_raises_regex(ImportError, "pg8000"):
             sql.read_sql("select * from table", db_uri)
