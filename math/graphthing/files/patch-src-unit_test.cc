--- src/unit_test.cc.orig	Fri Oct 25 16:15:51 2002
+++ src/unit_test.cc	Fri Oct 25 16:21:23 2002
@@ -19,14 +19,14 @@
 
 
 #define TEST_FAIL		\
-		cout << "\t* Failure at line " << __LINE__ << '\n'
+		std::cout << "\t* Failure at line " << __LINE__ << '\n'
 #define TEST(test)		\
 		++subtests;	\
 		if (!(test)) { ++errors; TEST_FAIL; }
 #define START_TEST(name)		\
 		++tests;		\
 		test_name = (name);	\
-		cout << "Running test " << tests << ": '" << test_name \
+		std::cout << "Running test " << tests << ": '" << test_name \
 							<< "'\n"
 
 
@@ -37,9 +37,9 @@
 	char *test_name;
 
 
-	cout << "-----------------------------\n";
-	cout << "  GraphThing unit testing\n";
-	cout << "-----------------------------\n";
+	std::cout << "-----------------------------\n";
+	std::cout << "  GraphThing unit testing\n";
+	std::cout << "-----------------------------\n";
 
 
 	/**************** START OF TESTS ****************/
@@ -107,13 +107,13 @@
 
 	/**************** END OF TESTS ****************/
 
-	cout << "\n";
-	cout << "-----------------------------\n";
-	cout << "Total tests: " << tests << '\n';
-	cout << "     Errors: " << errors << '\n';
-	cout << '\n';
-	cout << "  (Subtests: " << subtests << ")\n";
-	cout << "-----------------------------\n";
+	std::cout << "\n";
+	std::cout << "-----------------------------\n";
+	std::cout << "Total tests: " << tests << '\n';
+	std::cout << "     Errors: " << errors << '\n';
+	std::cout << '\n';
+	std::cout << "  (Subtests: " << subtests << ")\n";
+	std::cout << "-----------------------------\n";
 
 	return 0;
 }
