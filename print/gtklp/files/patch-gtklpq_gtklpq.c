--- gtklpq/gtklpq.c.orig	2019-11-01 16:27:28 UTC
+++ gtklpq/gtklpq.c
@@ -79,20 +79,7 @@ GtkWidget *dialog;
 
 int m_id_upd, c_id_upd, m_id_state, c_id_state;
 
-char PrinterNames[MAX_PRT][DEF_PRN_LEN + 1];
-char PrinterInfos[MAX_PRT][MAXLINE + 1];
-char PrinterLocations[MAX_PRT][MAXLINE + 1];
-int PrinterNum;
-int PrinterChoice;
-char PrinterBannerStart[MAX_PRT][MAXLINE + 1];
-char PrinterBannerEnd[MAX_PRT][MAXLINE + 1];
-
 unsigned int selectedJob;
-
-int lastPrinterChoice;
-
-http_t *cupsHttp;
-cups_lang_t *cupsLanguage;
 
 int main(int argc, char *argv[])
 {
