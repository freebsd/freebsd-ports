
$FreeBSD$

--- ntalk.cpp.orig	Wed Oct 23 17:27:37 2002
+++ ntalk.cpp	Wed Oct 23 17:31:54 2002
@@ -44,6 +44,8 @@
 #define WHOIS 		"10"
 #define SRVMESSAGE 	"11"
 
+using namespace std;
+
 
 struct color {
     int you;
@@ -341,7 +343,7 @@
     a = count(msg.begin(), msg.end(), ';');
     for(x = 0; x < a; x++)
     {
-	msg.replace(msg.find(';'), 1, '\n');
+	msg.replace(msg.find(';'), 1, "\n");
     }
 
     mvwprintw(user_w, 0, 0, "%s", msg.c_str());
