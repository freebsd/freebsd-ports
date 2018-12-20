--- qtiplot/src/core/ApplicationWindow.cpp.orig	2018-12-20 07:24:36 UTC
+++ qtiplot/src/core/ApplicationWindow.cpp
@@ -10933,11 +10933,11 @@ QStringList ApplicationWindow::depending
 			foreach(Graph *g, layers){
 				QStringList onPlot = g->curveNamesList();
 				onPlot = onPlot.grep (name,TRUE);
-				if (int(onPlot.count()) && plots.contains(w->objectName())<=0)
+				if (onPlot.count() && !plots.contains(w->objectName()))
 					plots << w->objectName();
 			}
 		}else if (w->isA("Graph3D")){
-			if ((((Graph3D*)w)->formula()).contains(name,TRUE) && plots.contains(w->objectName())<=0)
+			if ((((Graph3D*)w)->formula()).contains(name,TRUE) && !plots.contains(w->objectName()))
 				plots << w->objectName();
 		}
 	}
@@ -10954,7 +10954,7 @@ QStringList ApplicationWindow::multilaye
 		for (int j=0; j<onPlot.count(); j++)
 		{
 			QStringList tl = onPlot[j].split("_", QString::SkipEmptyParts);
-			if (tables.contains(tl[0])<=0)
+			if (!tables.contains(tl[0]))
 				tables << tl[0];
 		}
 	}
