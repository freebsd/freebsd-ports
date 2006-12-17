--- qbrew/calc.h.orig	Sat Dec 16 14:34:28 2006
+++ qbrew/calc.h	Sat Dec 16 14:34:52 2006
@@ -175,15 +175,15 @@
     static int SRM(Recipe *r);
 
     // convert Specific Gravity to Plato
-    static double Calc::SgToP(double sg);
+    static double SgToP(double sg);
     // convert grain extract to yield
-    static double Calc::extractToYield(double extract);
-    static double Calc::yieldToExtract(double yield);
+    static double extractToYield(double extract);
+    static double yieldToExtract(double yield);
 
     // add an entry to the utilization table
     static void addUEntry(const UEntry &u);
     // get the table of utilizations
-    static const QValueList<UEntry> &Calc::getUEntryList();
+    static const QValueList<UEntry> &getUEntryList();
 
  private:
     static double calcOG(Recipe *r);
