--- bigbluebutton-tomcat/demo/bbb_api_conf.jsp.orig	2010-11-11 13:33:47.000000000 +0000
+++ bigbluebutton-tomcat/demo/bbb_api_conf.jsp	2010-11-11 13:34:19.000000000 +0000
@@ -1,9 +1,9 @@
 
 <%!
 // This is the security salt that must match the value set in the BigBlueButton server
-String salt = "f1cd94813e3406a62c11351d3d057c99";
+String salt = "%%BBB_SALT%%";
 
 // This is the URL for the BigBlueButton server
-String BigBlueButtonURL = "http://192.168.0.135/bigbluebutton/";
+String BigBlueButtonURL = "http://%%BBB_HOSTNAME%%/bigbluebutton/";
 %>
 
