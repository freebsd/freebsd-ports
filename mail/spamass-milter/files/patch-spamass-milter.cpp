--- spamass-milter.cpp.orig	Thu Jun 26 16:10:44 2003
+++ spamass-milter.cpp	Thu Jun 10 11:46:12 2004
@@ -102,6 +102,10 @@
 #include <csignal>
 #include <string>
 #include <iostream>
+using std::string;
+using std::cout;
+using std::cerr;
+using std::endl;
 
 #ifdef  __cplusplus
 extern "C" {
@@ -273,6 +277,7 @@
 				exit(errno);
 				break;
 			case 0: /* Child */
+				setsid();
 				break;
 			default: /* Parent */
 				exit(0);
@@ -351,6 +356,9 @@
   string::size_type eoh = ( eoh1 < eoh2 ? eoh1 : eoh2 );
   string::size_type bob = assassin->d().find_first_not_of("\r\n", eoh);
 
+  if (bob == string::npos)
+  	bob = assassin->d().size();
+
   update_or_insert(assassin, ctx, assassin->spam_flag(), &SpamAssassin::set_spam_flag, "X-Spam-Flag");
   update_or_insert(assassin, ctx, assassin->spam_status(), &SpamAssassin::set_spam_status, "X-Spam-Status");
 
@@ -1341,7 +1349,11 @@
 {
   // assuming we have a recipient in the form: <username@somehost.somedomain>
   // we return 'username'
-  return _rcpt.substr(1,_rcpt.find('@')-1);
+  int at = _rcpt.find('@');
+  int plus = _rcpt.find('+');
+  if (plus > 0 && plus < at)
+    at = plus;
+  return _rcpt.substr(1,at-1);
 }
 
 int
