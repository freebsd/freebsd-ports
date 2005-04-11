--- IMCom.py.orig	Sat Mar 26 00:34:55 2005
+++ IMCom.py	Sat Mar 26 00:36:17 2005
@@ -618,7 +618,7 @@
 
     def sendPriority(self, priority):
         self.priority = priority
-        tosend = "<presence type='available'>"\
+        tosend = "<presence>"\
                  "<show>"+self.currentStatus+"</show>"\
                  "<priority>"+str(priority)+"</priority>"
         if(self.currentStatusReason != None or self.currentStatusReason != ""):
@@ -640,12 +640,12 @@
         self.currentStatus = "online"
         self.currentStatusReason = reason
         if(reason == None):
-            tosend = "<presence type='available'>"\
+            tosend = "<presence>"\
                      "<show>online</show>"\
                      "<priority>"+priority+"</priority>"\
                      "</presence>"
         else:
-            tosend = "<presence type='available'>"\
+            tosend = "<presence>"\
                      "<show>online</show><status>"+self.normalize(reason)+"</status>"\
                      "<priority>"+priority+"</priority>"\
                      "</presence>"
