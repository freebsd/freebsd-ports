--- examples/interop-client/interop-client.cc.orig	Thu Jun 28 11:54:08 2001
+++ examples/interop-client/interop-client.cc	Tue Mar  2 23:39:39 2004
@@ -1,8 +1,8 @@
 // Run various interop test cases against a list of servers.
 // This code is incomplete.
 
-#include <iostream.h>
-#include <fstream.h>
+#include <iostream>
+#include <fstream>
 #include <stdexcept>
 
 #include <XmlRpcCpp.h>
@@ -17,13 +17,13 @@
 //=========================================================================
 
 class TestResults {
-    string m_server_name;
-    string m_server_url;
+    std::string m_server_name;
+    std::string m_server_url;
     XmlRpcValue m_toolkit_info;
     XmlRpcValue m_test_results;
 
 public:
-    TestResults(string server_name, string server_url);
+    TestResults(std::string server_name, std::string server_url);
     
 };
 
@@ -33,24 +33,24 @@
 //=========================================================================
 
 static void
-run_interop_tests(const string& server_url_file,
-		  const string& output_html_file)
+run_interop_tests(const std::string& server_url_file,
+		  const std::string& output_html_file)
 {
-    ifstream urls(server_url_file.c_str());
-    ofstream out(output_html_file.c_str());
+    std::ifstream urls(server_url_file.c_str());
+    std::ofstream out(output_html_file.c_str());
 
     while (!urls.eof()) {
-	string url_info;
+	std::string url_info;
 	getline(urls, url_info);
 	size_t comma = url_info.find(',');
-	if (comma == string::npos)
-	    throw domain_error("Lines of " + server_url_file +
+	if (comma == std::string::npos)
+	    throw std::domain_error("Lines of " + server_url_file +
 			       " must be of the form \"name,url\"");
-	string server_name(url_info, 0, comma);
-	string server_url(url_info, comma + 1);
+	std::string server_name(url_info, 0, comma);
+	std::string server_url(url_info, comma + 1);
 
-	cout << "Name: " << server_name << endl;
-	cout << "URL: " << server_url << endl << endl;
+	std::cout << "Name: " << server_name << std::endl;
+	std::cout << "URL: " << server_url << std::endl << std::endl;
     }
 }
 			      
@@ -62,8 +62,8 @@
 // Print out a usage message.
 static void usage (void)
 {
-    cerr << "Usage: interop-client <server-url-file> <output-html-file>";
-    cerr << endl;
+    std::cerr << "Usage: interop-client <server-url-file> <output-html-file>";
+    std::cerr << std::endl;
     exit(1);
 }
 
@@ -73,8 +73,8 @@
     // Parse our command-line arguments.
     if (argc != 3)
 	usage();
-    string server_url_file(argv[1]);
-    string output_html_file(argv[2]);
+    std::string server_url_file(argv[1]);
+    std::string output_html_file(argv[2]);
 
     // Start up our client library.
     XmlRpcClient::Initialize(NAME, VERSION);
@@ -83,14 +83,14 @@
     try {
 	run_interop_tests(server_url_file, output_html_file);
     } catch (XmlRpcFault& fault) {
-	cerr << argv[0] << ": XML-RPC fault #" << fault.getFaultCode()
-	     << ": " << fault.getFaultString() << endl;
+	std::cerr << argv[0] << ": XML-RPC fault #" << fault.getFaultCode()
+	     << ": " << fault.getFaultString() << std::endl;
 	status = 1;
-    } catch (logic_error& err) {
-	cerr << argv[0] << ": " << err.what() << endl;
+    } catch (std::logic_error& err) {
+	std::cerr << argv[0] << ": " << err.what() << std::endl;
 	status = 1;
     } catch (...) {
-	cerr << argv[0] << ": Unknown exception" << endl;
+	std::cerr << argv[0] << ": Unknown exception" << std::endl;
 	status = 1;
     }
 
