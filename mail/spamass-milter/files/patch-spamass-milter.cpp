--- spamass-milter.cpp.orig	Thu Jun 26 16:10:44 2003
+++ spamass-milter.cpp	Wed Oct 13 00:52:23 2004
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
 
@@ -365,7 +373,7 @@
 	{
 		int score, rv;
 		const char *spam_status = assassin->spam_status().c_str();
-		rv = sscanf(spam_status,"%*s hits=%d", &score);
+		rv = sscanf(spam_status,"%*s score=%d", &score);
 		if (rv != 1)
 			debug(D_ALWAYS, "Could not extract score from <%s>", spam_status);
 		else 
@@ -539,6 +547,10 @@
 	}
   }
 
+  /* if the header line ends in \r\n, don't return the \r */
+  if (header[field_end-1] == '\r')
+	field_end--;
+
   //  Maybe remove the whitespace picked up when a header wraps - this
   //  might actually be a requirement
   return header.substr( field_start, field_end - field_start );
@@ -1341,7 +1353,11 @@
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
