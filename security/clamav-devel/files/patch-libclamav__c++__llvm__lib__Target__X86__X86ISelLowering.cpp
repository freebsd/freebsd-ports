--- ./libclamav/c++/llvm/lib/Target/X86/X86ISelLowering.cpp.orig	2010-03-12 11:04:55.000000000 -0300
+++ ./libclamav/c++/llvm/lib/Target/X86/X86ISelLowering.cpp	2010-03-12 11:06:58.000000000 -0300
@@ -9795,7 +9795,8 @@
         AsmPieces[2] == "${0:w}" &&
         IA->getConstraintString().compare(0, 5, "=r,0,") == 0) {
       AsmPieces.clear();
-      SplitString(IA->getConstraintString().substr(5), AsmPieces, ",");
+      const std::string &Constraints = IA->getConstraintString();
+      SplitString(StringRef(Constraints).substr(5), AsmPieces, ",");
       std::sort(AsmPieces.begin(), AsmPieces.end());
       if (AsmPieces.size() == 4 &&
           AsmPieces[0] == "~{cc}" &&
