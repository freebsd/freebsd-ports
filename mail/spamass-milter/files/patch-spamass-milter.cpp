--- spamass-milter.cpp.orig	Thu Jun 26 17:10:44 2003
+++ spamass-milter.cpp	Tue May 25 00:29:58 2004
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
@@ -350,6 +355,9 @@
   string::size_type eoh2(assassin->d().find("\n\r\n"));
   string::size_type eoh = ( eoh1 < eoh2 ? eoh1 : eoh2 );
   string::size_type bob = assassin->d().find_first_not_of("\r\n", eoh);
+
+  if (bob == string::npos)
+  	bob = assassin->d().size();
 
   update_or_insert(assassin, ctx, assassin->spam_flag(), &SpamAssassin::set_spam_flag, "X-Spam-Flag");
   update_or_insert(assassin, ctx, assassin->spam_status(), &SpamAssassin::set_spam_status, "X-Spam-Status");
