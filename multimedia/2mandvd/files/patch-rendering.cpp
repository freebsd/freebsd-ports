--- rendering.cpp.orig
+++ rendering.cpp
@@ -2017,8 +2017,13 @@
 
 	int valuefade;
 
+#ifdef __clang__
+	QString *wl_tabpnt = new QString[nbre_menuth+1];
+	QString *wl_tab_save_tra = new QString[100];
+#else
 	QString wl_tabpnt[nbre_menuth+1];
 	QString wl_tab_save_tra[100];
+#endif
 
 	QRgb srcPixel;
 	QRgb srcPixel2;
@@ -2991,6 +2996,10 @@
 		      	renderProcess.start(program,arguments);
 		}
 	}
+#ifdef __clang__
+	delete[] wl_tab_save_tra;
+	delete[] wl_tabpnt;
+#endif
 }
 
 void mainfrm::f_gene_mencoder()
