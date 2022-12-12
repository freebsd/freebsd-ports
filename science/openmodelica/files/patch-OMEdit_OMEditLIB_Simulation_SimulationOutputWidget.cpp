--- OMEdit/OMEditLIB/Simulation/SimulationOutputWidget.cpp.orig	2022-12-12 04:38:34 UTC
+++ OMEdit/OMEditLIB/Simulation/SimulationOutputWidget.cpp
@@ -577,8 +577,8 @@ void SimulationOutputWidget::compileModel()
     args << "-j" + numProcs;
   }
   args << "-f" << mSimulationOptions.getOutputFileName() + ".makefile";
-  writeCompilationOutput(QString("%1 %2\n").arg("make").arg(args.join(" ")), Qt::blue);
-  mpCompilationProcess->start("make", args);
+  writeCompilationOutput(QString("%1 %2\n").arg("gmake").arg(args.join(" ")), Qt::blue);
+  mpCompilationProcess->start("gmake", args);
 #endif
 }
 
