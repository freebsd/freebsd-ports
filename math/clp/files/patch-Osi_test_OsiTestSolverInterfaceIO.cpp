--- Osi/test/OsiTestSolverInterfaceIO.cpp.orig	2018-04-16 06:54:20 UTC
+++ Osi/test/OsiTestSolverInterfaceIO.cpp
@@ -422,10 +422,10 @@ OsiTestSolverInterface::writeMps(const c
    writer.setMpsData(*getMatrixByCol(), getInfinity(),
 		     getColLower(), getColUpper(),
 		     getObjCoefficients(), 
-		     reinterpret_cast<const char *> (NULL) /*integrality*/,
+		     nullptr /*integrality*/,
 		     getRowLower(), getRowUpper(),
-		     reinterpret_cast<const char **> (NULL) /*colnam*/, 
-		     reinterpret_cast<const char **> (NULL) /*rownam*/);
+		     nullptr /*colnam*/, 
+		     nullptr /*rownam*/);
    std::string fname = filename;
    if (extension)
    { if (extension[0] != '\0' && extension[0] != '.')
