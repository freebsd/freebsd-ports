--- src/cpptest.cc.orig	Wed May  2 00:26:13 2001
+++ src/cpptest.cc	Tue Mar  2 23:39:39 2004
@@ -28,15 +28,15 @@
 void test_failure (char* file, int line, char* statement)
 {
     total_failures++;
-    cout << endl
-	 << file << ":" << line << ": expected (" << statement << ")" << endl;
+    std::cout << std::endl
+	 << file << ":" << line << ": expected (" << statement << ")" << std::endl;
 }
 
 #define TEST(statement) \
     do { \
         total_tests++; \
         if ((statement)) { \
-            cout << "."; \
+            std::cout << "."; \
 	} else { \
             test_failure(__FILE__, __LINE__, #statement); \
         } \
@@ -45,7 +45,7 @@
 #define TEST_PASSED() \
     do { \
         total_tests++; \
-        cout << "."; \
+        std::cout << "."; \
     } while (0)
 
 #define TEST_FAILED(reason) \
@@ -187,7 +187,7 @@
     TEST(XmlRpcValue::makeString("foo").getString() == "foo");
     TEST(XmlRpcValue::makeString("bar", 3).getString() == "bar");
     TEST(XmlRpcValue::makeString("bar", 3).getString() == "bar");
-    TEST(XmlRpcValue::makeString("a\0b").getString() == string("a\0b"));
+    TEST(XmlRpcValue::makeString("a\0b").getString() == std::string("a\0b"));
     XmlRpcValue::makeArray().getArray();
     XmlRpcValue::makeStruct().getStruct();
 
@@ -219,7 +219,7 @@
     TEST(strct.structHasKey("bar"));
     TEST(!strct.structHasKey("nosuch"));
     for (size_t i = 0; i < strct.structSize(); i++) {
-	string key;
+	std::string key;
 	XmlRpcValue value;
 	strct.structGetKeyAndValue(i, key, value);
 	TEST(key + "val" == value.getString());
@@ -248,30 +248,30 @@
 	test_errors();
 
     } catch (XmlRpcFault& fault) {
-	cout << "Unexpected XML-RPC fault when running test suites." << endl
+	std::cout << "Unexpected XML-RPC fault when running test suites." << std::endl
 	     << "Fault #" << fault.getFaultCode()
-	     << ": " << fault.getFaultString() << endl
-	     << "FAILED" << endl;
+	     << ": " << fault.getFaultString() << std::endl
+	     << "FAILED" << std::endl;
 	exit(1);
     } catch (...) {
-	cout << "Unexpected exception when running test suites." << endl
-	     << "FAILED" << endl;
+	std::cout << "Unexpected exception when running test suites." << std::endl
+	     << "FAILED" << std::endl;
 	exit(1);
     }
 
     // Summarize our test run.
-    cout << endl << "Ran " << total_tests << " tests, "
+    std::cout << std::endl << "Ran " << total_tests << " tests, "
 	 << total_failures << " failed, "
-	 << setprecision(4)
+	 << std::setprecision(4)
 	 << (100.0 - (100.0 * total_failures) / total_tests)
-	 << "% passed" << endl;
+	 << "% passed" << std::endl;
 
     // Print the final result.
     if (total_failures == 0) {
-	cout << "OK" << endl;
+	std::cout << "OK" << std::endl;
 	return 0;
     }
 
-    cout << "FAILED" << endl;
+    std::cout << "FAILED" << std::endl;
     return 1;
 }
