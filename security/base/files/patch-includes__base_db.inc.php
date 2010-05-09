--- ./includes/base_db.inc.php.orig	2010-03-05 16:06:18.000000000 +0100
+++ ./includes/base_db.inc.php	2010-04-11 23:52:13.000000000 +0200
@@ -209,7 +209,7 @@
      /* ** Begin DB specific SQL fix-up ** */
      if ($this->DB_type == "mssql")
      {
-        $sql = eregi_replace("''", "NULL", $sql);
+        $sql = preg_replace("/''/i", "NULL", $sql);
      }
 
      if ($this->DB_type == "oci8")
