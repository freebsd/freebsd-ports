--- examples/meerkat-app-list.cc.orig	Wed Apr 25 04:18:36 2001
+++ examples/meerkat-app-list.cc	Tue Mar  2 23:39:39 2004
@@ -2,8 +2,8 @@
 // For more details about O'Reilly's excellent Meerkat news service, see:
 // http://www.oreillynet.com/pub/a/rss/2000/11/14/meerkat_xmlrpc.html */
 
-#include <iostream.h>
-#include <strstream.h>
+#include <iostream>
+#include <sstream>
 
 #include <XmlRpcCpp.h>
 
@@ -15,12 +15,9 @@
 static void list_apps (int hours) {
 
     // Build our time_period parameter.
-    ostrstream time_period_stream;
-    time_period_stream << hours << "HOUR" << ends;
-    string time_period = time_period_stream.str();
-
-    // (Ask the ostrstream to reclaim ownership of its buffer.)
-    time_period_stream.freeze(false);
+    std::ostringstream time_period_stream;
+    time_period_stream << hours << "HOUR" << std::ends;
+    std::string time_period = time_period_stream.str();
 
     // Assemble our meerkat query recipe.
     XmlRpcValue recipe = XmlRpcValue::makeStruct();
@@ -45,21 +42,21 @@
 	XmlRpcValue app = apps.arrayGetItem(i);
 
 	// Get some information about our application.
-	string title       = app.structGetValue("title").getString();
-	string link        = app.structGetValue("link").getString();
-	string description = app.structGetValue("description").getString();
+	std::string title       = app.structGetValue("title").getString();
+	std::string link        = app.structGetValue("link").getString();
+	std::string description = app.structGetValue("description").getString();
 	
 	// Print a separator line if necessary.
 	if (first)
 	    first = 0;
 	else
-	    cout << endl;
+	    std::cout << std::endl;
 
 	// Print this application entry.
 	if (description.size() > 0) {
-	    cout << title << endl << description << endl << link << endl;
+	    std::cout << title << std::endl << description << std::endl << link << std::endl;
 	} else {
-	    cout << title << endl << description << endl << link << endl;
+	    std::cout << title << std::endl << description << std::endl << link << std::endl;
 	}
     }
 }
@@ -67,8 +64,8 @@
 // Print out a usage message.
 static void usage (void)
 {
-    cerr << "Usage: meekat-app-list [hours]" << endl;
-    cerr << "Data from <http://www.oreillynet.com/meerkat/>." << endl;
+    std::cerr << "Usage: meekat-app-list [hours]" << std::endl;
+    std::cerr << "Data from <http://www.oreillynet.com/meerkat/>." << std::endl;
     exit(1);
 }
 
@@ -85,7 +82,7 @@
     if (hours == 0)
 	usage();
     if (hours > 49) {
-        cerr << "It's not nice to ask for > 49 hours at once." << endl;
+        std::cerr << "It's not nice to ask for > 49 hours at once." << std::endl;
         exit(1);	
     }
 
@@ -96,8 +93,8 @@
     try {
 	list_apps(hours);
     } catch (XmlRpcFault& fault) {
-	cerr << argv[0] << ": XML-RPC fault #" << fault.getFaultCode()
-	     << ": " << fault.getFaultString() << endl;
+	std::cerr << argv[0] << ": XML-RPC fault #" << fault.getFaultCode()
+	     << ": " << fault.getFaultString() << std::endl;
 	status = 1;
     }
 
