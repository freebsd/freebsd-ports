--- ./qtiplot/src/scripting/qti.sip.orig	2011-02-08 15:33:02.000000000 +0300
+++ ./qtiplot/src/scripting/qti.sip	2011-03-19 00:06:07.578146696 +0300
@@ -3390,57 +3390,6 @@
   double pValue();
 };
 
-class Anova : StatisticTest
-{
-%TypeHeaderCode
-#include <Anova.h>
-%End
-public:
-  Anova(ApplicationWindow * /TransferThis/, bool twoWay = false, double level = 0.05);
-  Anova(bool twoWay = false, double level = 0.05) /NoDerived/;
-%MethodCode
-  SIPQTI_APP(new sipAnova(app, a0, a1))
-%End
-
-  bool run();
-  bool addSample(const QString& colName, int aLevel = 1, int bLevel = 1);
-  void setAnovaTwoWayModel(int);
-
-  virtual QString logInfo();
-  double fStat();
-  double statistic();
-  double pValue();
-  //! Sum of squares
-  double ssm();
-  double sse();
-  double sst();
-  //! Mean square value
-  double mse();
-  //! F statistic for factor A
-  double fStatA();
-  //! F statistic for factor B
-  double fStatB();
-  //! F statistic for the interaction
-  double fStatAB();
-  //! P value for factor A
-  double pValueA();
-  //! P value for factor B
-  double pValueB();
-  //! P value for the interaction
-  double pValueAB();
-  //! Sum of squares for factor A
-  double ssa();
-  //! Sum of squares for factor B
-  double ssb();
-  //! Sum of squares for the interaction
-  double ssab();
-  //! Mean square value for factor A
-  double msa();
-  //! Mean square value for factor B
-  double msb();
-  //! Mean square value for the interaction
-  double msab();
-};
 
 // used for output redirection
 class PythonScripting
