
$FreeBSD$

--- src/acl.c.orig
+++ src/acl.c
@@ -325,7 +325,7 @@
     (1<<ACL_WHERE_ETRN)|(1<<ACL_WHERE_EXPN)|
     (1<<ACL_WHERE_MAILAUTH)|(1<<ACL_WHERE_QUIT)|
     (1<<ACL_WHERE_MAIL)|(1<<ACL_WHERE_STARTTLS)|
-    (1<<ACL_WHERE_VRFY)|(1<<ACL_WHERE_MIME),
+    (1<<ACL_WHERE_VRFY),
 #endif
 
   (1<<ACL_WHERE_AUTH)|(1<<ACL_WHERE_CONNECT)|      /* sender_domains */
