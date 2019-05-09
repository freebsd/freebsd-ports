--- apps/i2pcontrol/java/org/mindrot/jbcrypt/BCrypt.java.orig	2019-04-17 11:58:51.939865000 -0400
+++ apps/i2pcontrol/java/org/mindrot/jbcrypt/BCrypt.java	2019-04-17 11:58:57.299331000 -0400
@@ -32,25 +32,25 @@
  * call the hashpw method with a random salt, like this:
  * <p>
  * <code>
- * String pw_hash = BCrypt.hashpw(plain_password, BCrypt.gensalt()); <br />
+ * String pw_hash = BCrypt.hashpw(plain_password, BCrypt.gensalt());
  * </code>
  * <p>
  * To check whether a plaintext password matches one that has been
  * hashed previously, use the checkpw method:
  * <p>
  * <code>
- * if (BCrypt.checkpw(candidate_password, stored_hash))<br />
- * &nbsp;&nbsp;&nbsp;&nbsp;System.out.println("It matches");<br />
- * else<br />
- * &nbsp;&nbsp;&nbsp;&nbsp;System.out.println("It does not match");<br />
+ * if (BCrypt.checkpw(candidate_password, stored_hash))
+ * &nbsp;&nbsp;&nbsp;&nbsp;System.out.println("It matches");
+ * else
+ * &nbsp;&nbsp;&nbsp;&nbsp;System.out.println("It does not match");
  * </code>
  * <p>
  * The gensalt() method takes an optional parameter (log_rounds)
  * that determines the computational complexity of the hashing:
  * <p>
  * <code>
- * String strong_salt = BCrypt.gensalt(10)<br />
- * String stronger_salt = BCrypt.gensalt(12)<br />
+ * String strong_salt = BCrypt.gensalt(10)
+ * String stronger_salt = BCrypt.gensalt(12)
  * </code>
  * <p>
  * The amount of work increases exponentially (2**log_rounds), so 
