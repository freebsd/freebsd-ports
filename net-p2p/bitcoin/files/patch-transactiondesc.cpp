--- src/qt/transactiondesc.cpp.orig	2012-09-13 04:07:22.000000000 +1000
+++ src/qt/transactiondesc.cpp	2012-09-19 18:44:39.000000000 +1000
@@ -8,6 +8,7 @@
 #include "db.h"
 #include "ui_interface.h"
 #include "base58.h"
+#include "walletdb.h"
 
 QString TransactionDesc::FormatTxStatus(const CWalletTx& wtx)
 {
