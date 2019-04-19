--- src/cpp/value.cpp.orig	2019-03-29 03:33:33 UTC
+++ src/cpp/value.cpp
@@ -1,4 +1,3 @@
-#include <iostream>
 /*****************************************************************************
                                 value.cpp
 ******************************************************************************
@@ -622,13 +621,9 @@ class cNewStringWrapper { (public)
 
         switch (nlCode) {
         case value_string::nlCode_all:
-            cerr << "Going to call xmlrpc_string_new_lp" << endl;
-            cerr << "length = " << cppvalue.length() << ", value = "
-                 << cppvalue.c_str() << endl;
             this->valueP = xmlrpc_string_new_lp(&env.env_c,
                                                 cppvalue.length(),
                                                 cppvalue.c_str());
-            cerr << "Back from xmlrpc_string_new_lp" << endl;
             break;
         case value_string::nlCode_lf:
             this->valueP = xmlrpc_string_new_lp_cr(&env.env_c,
@@ -661,12 +656,9 @@ value_string::value_string(std::string          const&
 
 value_string::value_string(std::string const& cppvalue) {
 
-    cerr << "value_string constructor entered" << endl;
     cNewStringWrapper wrapper(cppvalue, nlCode_all);
-    cerr << "wrapper constructed" << endl;
 
     this->instantiate(wrapper.valueP);
-    cerr << "value_string constructor exiting" << endl;
 }
 
 
