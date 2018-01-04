--- 3rdparty/doctrine/dbal/lib/Doctrine/DBAL/Schema/PostgreSqlSchemaManager.php.orig	2017-11-27 09:11:23 UTC
+++ 3rdparty/doctrine/dbal/lib/Doctrine/DBAL/Schema/PostgreSqlSchemaManager.php
@@ -289,7 +289,16 @@ class PostgreSqlSchemaManager extends Ab
             $sequenceName = $sequence['relname'];
         }
 
-        $data = $this->_conn->fetchAll('SELECT min_value, increment_by FROM ' . $this->_platform->quoteIdentifier($sequenceName));
+        $version = floatval($this->_conn->getWrappedConnection()->getServerVersion());
+
+        if ($version >= 10) {
+           $data = $this->_conn->fetchAll('SELECT min_value, increment_by FROM pg_sequences WHERE schemaname = \'public\' AND sequencename = '.$this->_conn->quote($sequenceName));
+        }
+        else
+        {
+            $data = $this->_conn->fetchAll('SELECT min_value, increment_by FROM ' . $this->_platform->quoteIdentifier($sequenceName));
+        }
+//        $data = $this->_conn->fetchAll('SELECT min_value, increment_by FROM ' . $this->_platform->quoteIdentifier($sequenceName));
 
         return new Sequence($sequenceName, $data[0]['increment_by'], $data[0]['min_value']);
     }
