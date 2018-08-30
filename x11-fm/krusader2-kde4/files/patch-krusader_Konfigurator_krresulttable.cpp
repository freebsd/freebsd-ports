--- krusader/Konfigurator/krresulttable.cpp.orig	2018-08-30 09:48:49 UTC
+++ krusader/Konfigurator/krresulttable.cpp
@@ -27,7 +27,7 @@
 
 using namespace std;
 
-#define PS(x) _supported.contains(x)>0
+#define PS(x) bool(_supported.contains(x))
 
 KrResultTable::KrResultTable(QWidget* parent)
         : QWidget(parent),
