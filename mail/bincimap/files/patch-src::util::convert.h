replace switch statement in inline function with if/then/else; fixes compiler
failure on alpha: ``relocation truncated to fit: GPREL32 *UND*''

diff -u -r1.4 convert.h
--- src/util/convert.h	8 Apr 2003 16:46:28 -0000	1.4
+++ src/util/convert.h	9 Apr 2003 08:02:54 -0000
@@ -269,6 +269,7 @@
   {
     std::string regex = "^";
     for (std::string::const_iterator i = s_in.begin(); i != s_in.end(); ++i) {
+      /*
       switch (*i) {
       case '.': 
       case '[': case ']': 
@@ -291,6 +292,24 @@
       default: 
 	regex += *i;
 	break;
+      }
+      */
+      if (*i == '.' || *i == '[' || *i == ']' || *i == '{' || *i == '}' ||
+	  *i == '(' || *i == ')' || *i == '^' || *i == '$' || *i == '?' ||
+	  *i == '+' || *i == '\\') {
+	regex += "\\";
+	regex += *i;
+      }
+      else if (*i == '*') {
+	regex += ".*?";
+      }
+      else if (*i == '%') {
+	regex += "[^\\";
+	regex += delimiter;
+	regex += "]*?";
+      }
+      else {
+	regex += *i;
       }
     }
     
