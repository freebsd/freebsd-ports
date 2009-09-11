--- papyon/msnp/notification.py.BACKUP.8715.py.orig	2009-09-10 23:56:54.000000000 -0400
+++ papyon/msnp/notification.py.BACKUP.8715.py	2009-09-10 23:57:37.000000000 -0400
@@ -478,14 +478,11 @@ class NotificationProtocol(BaseProtocol,
     def _handle_UBN(self,command): # contact infos
         if not command.payload:
             return
-<<<<<<< HEAD:papyon/msnp/notification.py
         type = int(command.arguments[1])
         self.emit("buddy-notification-received", type, command)
 
-=======
         print "RECEIVED UBN : %s\n%s" % (unicode(command), command.payload)
-        
->>>>>>> f69a717... Fixed some encoding issues in log messages:papyon/msnp/notification.py
+
     def _handle_UBX(self,command): # contact infos
         if not command.payload:
             return
