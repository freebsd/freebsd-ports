--- bidwatcher.cpp.orig	Fri Mar 15 14:15:27 2002
+++ bidwatcher.cpp	Fri Mar 15 14:17:27 2002
@@ -267,7 +267,7 @@
    char WebPage[200];
    strcpy(bidAmount, maxBid->text() );
    strcpy(bidQuant, maxQuant->text() );
-   strcpy(WebPage, "/aw-cgi/eBayISAPI.dll?MakeBid&item=");
+   strcpy(WebPage, PATH_CGI_MakeBid);
    strcat(WebPage, theAuction.ItemNumber);
    strcat(WebPage, "&maxbid=");
    strcat(WebPage,  bidAmount);
@@ -327,7 +327,7 @@
    {
       priceLabel->setText("Submitting bid...");
       // now, finalize bid with the key obtained.
-      strcpy(WebPage, "/aw-cgi/eBayISAPI.dll?AcceptBid&item=");
+      strcpy(WebPage, PATH_CGI_AcceptBid);
       strcat(WebPage, theAuction.ItemNumber);
       strcat(WebPage, "&key=");
       strcat(WebPage, key);
@@ -838,7 +838,7 @@
       char Buff[5000];
       char Buff2[5000];
       char WebPage[250];
-      strcpy(WebPage, "/aw-cgi/eBayISAPI.dll?ReturnUserEmail"
+      strcpy(WebPage, PATH_CGI_ReturnUserEmail
 						 "&requested=");
       strcat(WebPage, name);
       strcat(WebPage, "&userid=");
@@ -946,7 +946,7 @@
    else thisMonth = TRUE;
    char * homedir = getenv("HOME");
    char fileName[200];
-   MakeFileName(homedir, "/.bidwatcher/snipe", fileName, thisMonth);
+   MakeFileName(homedir, DOT_BIDWATCHER "/snipe", fileName, thisMonth);
    fillBlanks(fileName, thisMonth);
 }
 /////////////////////////////////////////////////////////////////////
@@ -1033,7 +1033,7 @@
    else thisMonth = TRUE;
    char * homedir = getenv("HOME");
    char fileName[200];
-   MakeFileName(homedir, "/.bidwatcher/log", fileName, thisMonth);
+   MakeFileName(homedir, DOT_BIDWATCHER "/log", fileName, thisMonth);
    fillBlanks(fileName, thisMonth);
 }
 ///////////////////////////////////////////////////////////////////////////////
@@ -1227,7 +1227,7 @@
    char fileName[200];
    char * homeDir = getenv("HOME");
    strcpy(fileName, homeDir);
-   strcat(fileName, "/.bidwatcher");
+   strcat(fileName, DOT_BIDWATCHER);
    mkdir(fileName, 0700);
    ReadaucFile();
    if ( strlen(authID) > 1 )
@@ -1271,7 +1271,7 @@
    char fileName[200];
    char * homeDir = getenv("HOME");
    strcpy(fileName, homeDir);
-   strcat(fileName, "/.bidwatcher/bw.cfg");
+   strcat(fileName, DOT_BIDWATCHER "/bw.cfg");
    outFile.open(fileName);
    if ( outFile )
    {
@@ -1416,7 +1416,7 @@
 {
    char * homedir = getenv("HOME");
    char fileName[200];
-   MakeFileName(homedir, "/.bidwatcher/snipe", fileName, TRUE);
+   MakeFileName(homedir, DOT_BIDWATCHER "/snipe", fileName, TRUE);
    viewFileWindow->fillBlanks(fileName, TRUE);
    viewFileWindow->show();
 }
@@ -1424,7 +1424,7 @@
 {
    char * homedir = getenv("HOME");
    char fileName[200];
-   MakeFileName(homedir, "/.bidwatcher/log", fileName, TRUE);
+   MakeFileName(homedir, DOT_BIDWATCHER "/log", fileName, TRUE);
    viewEndedWindow->fillBlanks(fileName, TRUE);
    viewEndedWindow->show();
 }
@@ -1460,7 +1460,7 @@
    {
       strcpy(commandLine, "exec ");
       strcat(commandLine, browserPATH);
-      strcat(commandLine, " -remote \"openURL(http://cgi.ebay.com/aw-cgi/eBayISAPI.dll?ViewItem&item=");
+      strcat(commandLine, " -remote \"openURL(http://cgi.ebay.com" PATH_CGI_ViewItem );
       strcat(commandLine, BidMakeup[choice].ItemNumber);
       strcat(commandLine, ",new-window)\"");
       system(commandLine);
@@ -1595,7 +1595,7 @@
    }
    else if (returnVal  == 2)
    {
-      QMessageBox::about(this,"Error","Can't connect to server.");
+      QMessageBox::about(this,"Error","Can't connect to server to update.");
    }
    else if ( returnVal != 10 )
    {
@@ -2001,14 +2001,22 @@
       WriteAucFile();
       return;
    }
+   else if (returnVal == 2)
+       QMessageBox::about(this,"Error","Connection problem while trying to add item.");
    else if ( returnVal == 3 || returnVal == 6 )
        QMessageBox::about(this,"Error","Invalid auction number.");
 
    else if ( returnVal == 4 )
-       QMessageBox::about(this,"Error","Connection time-out");
+       QMessageBox::about(this,"Error","Connection time-out while trying to add item.");
+
+   else if (returnVal == 5)
+       QMessageBox::about(this,"Error","CGI server down while trying to add item.");
+
+   else if (returnVal == 6)
+       QMessageBox::about(this,"Error","itemNumber is out of bounds while trying to add item.");
 
    else if ( returnVal != 10 )
-       QMessageBox::about(this,"Error","Can't connect to server.");
+       QMessageBox::about(this,"Error","Can't connect to server to add item.");
 
    updateInProgress = FALSE;
    statLabel->setText("");
@@ -2261,7 +2269,7 @@
    ifstream inFile;
    char * homedir = getenv("HOME");
    strcpy(fileName, homedir);
-   strcat(fileName, "/.bidwatcher/bw.cfg");
+   strcat(fileName, DOT_BIDWATCHER "/bw.cfg");
    inFile.open(fileName, ios::in);
    if ( inFile )
    {
@@ -2458,7 +2466,7 @@
    char Buff2[HUGEBUFF];
    char WebPage[200];
    int returnVal;
-   strcpy(WebPage, "/aw-cgi/eBayISAPI.dll?MfcISAPICommand=ViewBidItems&userid=");
+   strcpy(WebPage, PATH_CGI_ViewBidItems);
    strcat(WebPage, authID);
    strcat(WebPage, "&completed=0&all=1&rows=200");
 
@@ -2532,7 +2540,7 @@
    char Buff2[HUGEBUFF];
    char WebPage[200];
    int returnVal;
-   strcpy(WebPage, "/aw-cgi/eBayISAPI.dll?ViewListedItems&userid=");
+   strcpy(WebPage, PATH_CGI_ViewListedItems);
    strcat(WebPage, authID);
    strcat(WebPage, "&completed=0&sort=3&since=-1");
    if ( strlen(authID) < 2 ) return -1;
@@ -2687,7 +2695,7 @@
    //char Buff[MAXBUFF];
    char HtmlBuff[HUGEBUFF];
    char WebPage[80];
-   strcpy(WebPage,"/aw-cgi/eBayISAPI.dll?ViewItem&item=");
+   strcpy(WebPage,PATH_CGI_ViewItem);
    strcat(WebPage, NewAuction.ItemNumber);
    brightLabel->setPixmap(brightLed);
    returnVal = FetchHtml(WebPage,HtmlBuff,theAddress, HUGEBUFF, TIMEOUT);
@@ -2695,7 +2703,12 @@
    if ( returnVal == 10 ) return 10;
    else if ( returnVal == 2 ) return 2;
    else if ( returnVal == 4 ) return 4;
-   else if ( strlen(HtmlBuff) < 1000 ) return 5;
+   else if ( strlen(HtmlBuff) < 1000 ) {
+#ifdef DEBUG_NETWORK
+	fprintf( stderr, "BidWatcher::UpdateAuction: [%s]\n", HtmlBuff );
+#endif
+	return 5;
+   }
    else if ( strlen(HtmlBuff) < 5000 ) return 3;
    // ok, html grab was a success - now process the html
    char Buff[HUGEBUFF]; 
@@ -2743,7 +2756,7 @@
    double	t1;
 
 
-   strcpy(WebPage, "/aw-cgi/eBayISAPI.dll?TimeShow");
+   strcpy(WebPage, PATH_CGI_TimeShow);
    
    // try getting the time several times and pick the minimum time
    // difference.  This should reduce the variable network delay.  
@@ -2916,7 +2929,7 @@
       ofstream reportOut;
       char * homedir = getenv("HOME");
       char fileName[200];
-      MakeFileName(homedir, "/.bidwatcher/log", fileName, TRUE);
+      MakeFileName(homedir, DOT_BIDWATCHER "/log", fileName, TRUE);
       reportOut.open(fileName, ios::app);
       char truncDesc[300];
       strcpy( truncDesc,   BidMakeup[index].ItemNumber);
@@ -2946,7 +2959,7 @@
    // now, submit the bid, then check the resulting buffer
    // for a message indicating it was successful:
    MakeClockTime(timeDiff, startTime);
-   strcpy(WebPage, "/aw-cgi/eBayISAPI.dll?AcceptBid&item=");
+   strcpy(WebPage, PATH_CGI_AcceptBid);
    strcat(WebPage, BidMakeup[index].ItemNumber);
    strcat(WebPage, "&key=");
    strcat(WebPage, BidMakeup[index].snipeKey);
@@ -2961,7 +2974,7 @@
    ofstream reportOut;
    char * homedir = getenv("HOME");
    char fileName[200];
-   MakeFileName(homedir, "/.bidwatcher/snipe", fileName, TRUE);
+   MakeFileName(homedir, DOT_BIDWATCHER "/snipe", fileName, TRUE);
    reportOut.open(fileName, ios::app);
    char truncDesc[1024];
    sprintf( truncDesc, "%s $%s %s",
@@ -3037,7 +3050,7 @@
 #if DEBUG_NETWORK
       ofstream outFile;
       char fileName[200];
-      sprintf( fileName, "%s/.bidwatcher/snipe_fail_%s",
+      sprintf( fileName, "%s" DOT_BIDWATCHER "/snipe_fail_%s",
 	       getenv("HOME"), BidMakeup[index].ItemNumber );
 
       outFile.open(fileName);
