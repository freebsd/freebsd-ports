--- src/java/org/agnitas/web/MailingSendAction.java.orig	2015-10-24 14:59:58 UTC
+++ src/java/org/agnitas/web/MailingSendAction.java
@@ -820,9 +820,9 @@ public class MailingSendAction extends S
 
     /**
      * Write mailing send to user log
-     * @param admin — admin
-     * @param sendDate — scheduled send date
-     * @param aMailing — mailing to send
+     * @param admin  admin
+     * @param sendDate  scheduled send date
+     * @param aMailing  mailing to send
      */
     protected void logSendAction(Admin admin, Date sendDate, Mailing aMailing) {
         final String description = "mailing %s(%d) %s";
