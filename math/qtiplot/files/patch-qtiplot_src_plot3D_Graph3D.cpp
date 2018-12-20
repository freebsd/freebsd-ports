--- qtiplot/src/plot3D/Graph3D.cpp.orig	2011-08-24 10:25:10 UTC
+++ qtiplot/src/plot3D/Graph3D.cpp
@@ -3283,7 +3283,7 @@ Graph3D* Graph3D::restore(ApplicationWin
 				return 0;
 			plot->addRibbon(t, l[0], l[1], fList[2].toDouble(), fList[3].toDouble(),
 					fList[4].toDouble(), fList[5].toDouble(), fList[6].toDouble(), fList[7].toDouble());
-		} else if (formula.contains("(Z)",true) > 0){
+		} else if (formula.contains("(Z)",true)){
 			formula.remove("(X)").remove("(Y)").remove("(Z)");
 			QStringList l = formula.split(",");
 			if (l.size() < 3)
