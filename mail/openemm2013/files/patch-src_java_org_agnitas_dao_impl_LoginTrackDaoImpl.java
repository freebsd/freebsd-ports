--- src/java/org/agnitas/dao/impl/LoginTrackDaoImpl.java.orig	2015-10-11 16:41:55 UTC
+++ src/java/org/agnitas/dao/impl/LoginTrackDaoImpl.java
@@ -37,7 +37,7 @@ import org.springframework.jdbc.core.Row
 /**
  * DAO implementation for login tracking using a MySQL database.
  * 
- * @author Markus Dörschmidt
+ * @author Markus Duerschmidt
  */
 public class LoginTrackDaoImpl implements LoginTrackDao {
 	/**
@@ -69,7 +69,7 @@ public class LoginTrackDaoImpl implement
 	/**
 	 * Implementation of the RowMapper
 	 * 
-	 * @author Markus Dörschmidt
+	 * @author Markus Duerschmidt
 	 *
 	 */
 	static class FailedLoginDataRowMapper implements RowMapper {
