--- src/libfungcalc/fparser/fparser.cc.orig	Sat Aug 14 00:53:10 2004
+++ src/libfungcalc/fparser/fparser.cc	Sat Aug 14 00:54:04 2004
@@ -163,7 +163,7 @@
         }
         return 0;
     }
-};
+}
 
 //---------------------------------------------------------------------------
 // Constructors and destructors
@@ -236,7 +236,7 @@
         }
         return true;
     }
-};
+}
 
 bool FunctionParser::isValidName(const std::string& name)
 {
@@ -361,7 +361,7 @@
     {
         while(F[Ind] && F[Ind] == ' ') ++Ind;
     }
-};
+}
 
 // Returns an iterator to the variable with the same name as 'F', or to
 // Variables.end() if no such variable exists:
