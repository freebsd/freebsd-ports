--- cdbakeoven/dialogs/CdboDialogActionFactory.cpp	Tue Jan 21 11:11:55 2003
+++ cdbakeoven/dialogs/CdboDialogActionFactory.cpp.orig	Tue Jan 21 11:11:58 2003
@@ -385,9 +385,12 @@
 	user->status(i18n("Reading CDROM..."));
 	*out += ".iso";
 	cdboProc = new KProcess();	
-	*cdboProc << "dd";
-	*cdboProc << "if=" + in;
-	*cdboProc << "of=" + *out + "";
+        *cdboProc << "readcd";
+        *cdboProc << "dev=" + user->getScsiDevice();
+	*cdboProc << "-q";
+	*cdboProc << "retries=32";
+	*cdboProc << "-s";
+	*cdboProc << "f=" + *out;
 }
 //---------------------------------------------------------------------------------------------
 void CdboDialogActionFactory::initBurnProcess(QString image, bool audio ){
@@ -517,6 +520,7 @@
 	strBuff.prepend("'" + tmpLbl->text());
 	strBuff.append("'");
 	*cdboShellProc << strBuff;*/
+	image.replace(QRegExp("'"),"");
 	
 	if(image == "-")
 		*cdboShellProc  << " - ";
@@ -1132,7 +1136,7 @@
 	KRun::shellQuote( file );
 	KRun::shellQuote(outName);
 	if(mType.find("x-mp3") != -1){
-		*cdboShellProc << "mpg123 -v -s " + file + " > " + outName;
+		*cdboShellProc << "mpg123 -v -w " + outName + " " + file;
 		tmpList->append(outName);
 		tracksList->append(outName);
 		return true;
@@ -1519,6 +1523,7 @@
 void CdboDialogActionFactory::removeOneFile(QString fileName){
 	if(!fileName) return;
 	
+	fileName.replace(QRegExp("'"),"");	
 	if(!QFile::remove(fileName))
 		user->output(CdboDialogBase::ErrorMessage, i18n("Failed to remove ") + fileName + "!");
 }
