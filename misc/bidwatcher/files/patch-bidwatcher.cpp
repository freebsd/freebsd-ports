--- bidwatcher.cpp.orig	Mon Aug 30 18:03:34 2004
+++ bidwatcher.cpp	Thu Jan 13 18:31:11 2005
@@ -29,12 +29,12 @@
 #include <time.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <sys/signal.h>
-#include <ctype.h>
+//#include <sys/signal.h>
+//#include <ctype.h>
 #include <sys/time.h>
-#include <sys/socket.h>
-#include <stdlib.h>
-#include <netdb.h>
+//#include <sys/socket.h>
+//#include <stdlib.h>
+//#include <netdb.h>
 
 // Handle strict Ansi compliance with gcc 3.1 while retaining
 // backward compatibility.
@@ -595,6 +595,40 @@
   delete obj;
 }
 
+int dosignin() {
+
+  URL *bidurl;
+
+  char *Buff;
+  int returnVal;
+  char *ustring, *vstring;
+  char cookiejar[200];
+  sprintf(cookiejar, "%s/%s/cookies.txt", getenv("HOME"), bw_subdir);
+
+  /* Sign in First */
+   bidurl = new URL("http://signin.ebay.com/ws2/eBayISAPI.dll?SignIn",
+		    "",proxyurl);
+   returnVal = fetchURL(bidurl, 0, &Buff, cookiejar, 2);
+
+   delete(bidurl);
+
+   ustring = g_strdup_printf("https://signin.ebay.com/ws/eBayISAPI.dll"
+			     "?co_partnerid=2&amp;siteid=0&amp;UsingSSL=1");
+   vstring = g_strdup_printf("MfcISAPICommand=SignInWelcome"
+			     "&siteid=0&co_partnerId=2&UsingSSL=1"
+			     "&ru=&pp=&pa1=&pa2=&pa3=&i1=-1&pageType=-1"
+			     "&userid=%s&pass=%s&keepMeSignInOption=1",
+			     authID, authPASS); 
+
+   bidurl = new URL(ustring, vstring, proxyurl);
+   g_free(ustring);
+   g_free(vstring);
+
+   returnVal = fetchURL(bidurl, 1, &Buff, cookiejar, 0);
+
+   return returnVal;
+}
+
 
 void auctioninfo::getkey(float bid, int quantity) {
   char *Buff;
@@ -602,9 +636,13 @@
   snipeQty=quantity;
   myBidAmount=bid;
   myBidQuantity=quantity;
-  //printf("myBidAmount set to %f\n",bid);
+  int returnVal;
+
+  char *ustring, *vstring;
+  char cookiejar[200];
+  sprintf(cookiejar, "%s/%s/cookies.txt", getenv("HOME"), bw_subdir);
 
-  char *ustring;
+  dosignin();
 
   /* eBay has gotten pickier about URLs.  If you don't specify
    * ebaymotors then you get some unknown error, yet the bid
@@ -614,6 +652,7 @@
    * key URL.  This should change so we don't look suspicious.
    */
 
+#if 0
   (AuctionType == TYPE_EBAYMOTORSCAR || AuctionType == TYPE_EBAYMOTORS) ?
     ustring = g_strdup_printf("http://cgi.ebay.com/ebaymotors/"
 				    "aw-cgi/eBayISAPI.dll"
@@ -625,14 +664,17 @@
 				 "?MfcISAPICommand=MakeBid"
 				"&item=%llu&maxbid=%.2f&quant=%d",
 				ItemNumber,bid,quantity);
+#endif
+
+  ustring = g_strdup_printf("http://offer.ebay.com/ws/eBayISAPI.dll");
+  vstring = g_strdup_printf("MfcISAPICommand=MakeBid&fp=2&co_partnerid="
+                            "&item=%llu&maxbid=%.2f&quant=%d",
+			    ItemNumber,bid,quantity);
+
+  bidurl = new URL(ustring, vstring, proxyurl);
 
-  /* Lets keep the URL fresh. */
-  if (bidurl)
-    delete(bidurl);
-  bidurl = new URL(ustring, proxyurl);
-  g_free(ustring);
+  returnVal = fetchURL(bidurl, 1, &Buff, cookiejar, 0);
 
-  int returnVal = fetchURL(bidurl, 1, &Buff, TIMEOUT, 0);
   if (returnVal != NET_SUCCESS) {
     if (returnVal == NET_NETERROR)
       showError("Could not obtain bid key: a network error occurred.");
@@ -698,21 +740,18 @@
   char *Buff;
   char lineBuff[1024];
   int returnVal,retval;
-  char *url=g_strdup(bidurl->url);
-  char *end=strstr(url,"?");
-  end[1]='\0';
+  char cookiejar[200];
+  sprintf(cookiejar, "%s/%s/cookies.txt", getenv("HOME"), bw_subdir);
 
-  sprintf(bidurl->url, "%sMfcISAPICommand=MakeBid&item=%llu&key=%s"
+  sprintf(bidurl->fullurlpost, "MfcISAPICommand=MakeBid&item=%llu&key=%s"
 	  "&user=%s&pass=%s&maxbid=%.2f&quant=%d"
 	  "&acceptbinbid=0&mode=1&userid=default&javascriptenabled=1",
-	  url, ItemNumber, snipeKey, authID, authPASS, snipeAmount,
+	  ItemNumber, snipeKey, authID, authPASS, snipeAmount,
 	  snipeQty);
 
-  DPRINTF(DHIGH, ("Bid(%s)\n", bidurl->url));
+  DPRINTF(DHIGH, ("Bid(%s?%s)\n", bidurl->fullurl, bidurl->fullurlpost));
 
-  g_free(url);
-
-  retval = fetchURL(bidurl, 1, &Buff, TIMEOUT, 0);
+  retval = fetchURL(bidurl, 1, &Buff, cookiejar, 0);
 
   if (retval != NET_SUCCESS) {
     sprintf(lineBuff,"Bid on %llu FAILED: Error %d connecting to eBay",
@@ -949,6 +988,9 @@
 
 void DoEmail(char * name, char * auctionid)
 {
+  char cookiejar[200];
+  sprintf(cookiejar, "%s/%s/cookies.txt", getenv("HOME"), bw_subdir);
+
   if (strlen(name) < 2) {
       showError("No name to look up");
       return;
@@ -972,8 +1014,8 @@
       sprintf(WebPage,"http://contact.ebay.com/aw-cgi/eBayISAPI.dll?"
 	      "ReturnUserEmail&requested=%s&userid=%s&pass=%s&iid=%s",
 	      name,authID,authPASS,auctionid);
-      URL *emailurl=new URL(WebPage,proxyurl);
-      int err = fetchURL(emailurl, 0, &Buff, TIMEOUT, 0);
+      URL *emailurl=new URL(WebPage,"",proxyurl);
+      int err = fetchURL(emailurl, 0, &Buff, cookiejar, 0);
       delete(emailurl);
 
       if ((err == NET_NETERROR) || (err == NET_TIMEOUT)
@@ -1101,7 +1143,7 @@
 
   if (strlen(proxystring) > 2) {
     char *pxy = g_strdup_printf("http://%s/",proxystring);
-    proxyurl = new URL(pxy, NULL, proxyuserstring, proxypassstring);
+    proxyurl = new URL(pxy, "", NULL, proxyuserstring, proxypassstring);
     g_free(pxy);
   }
   else proxyurl = NULL;
@@ -2969,8 +3011,8 @@
 			browserPATH, url);
 		system(commandLine);
 	}
-	else if (strstr(browserPATH, "mozilla") != NULL) {
-		// Try to find mozilla.
+	else if (strcasestr(browserPATH, "mozilla") != NULL || strcasestr(browserPATH, "fire") != NULL) {
+		// Try to find mozilla, firefox, or firebird.
 
 		sprintf(commandLine,
 			"exec %s -remote \"openURL(%s,new-window)\"",
@@ -3636,7 +3678,7 @@
 
   if (strlen(proxystring) > 2) {
     char *pxy = g_strdup_printf("http://%s/", proxystring);
-    proxyurl = new URL(pxy, NULL, proxyuserstring, proxypassstring);
+    proxyurl = new URL(pxy, "", NULL, proxyuserstring, proxypassstring);
     g_free(pxy);
   } else {
     proxyurl = NULL;
@@ -4076,37 +4118,6 @@
   CHECK;
 }
 
-/*
-gint getUserAuctions()
-{
-	char address[1024];
-	char *Buff;
-	int ret;
-
-	showStatus("Checking My eBay");
-
-	sprintf(address, "http://signin.ebay.com/aw-cgi/eBayISAPI.dll?"
-		"MfcISAPICommand=SignInWelcome&siteid=0&co_partnerId=2"
-		"&UsingSSL=0&ru=http%%3A%%2F%%2Fcgi1.ebay.com%%2Faw-cgi%%2F"
-		"eBayISAPI.dll%%3FMyEbayAll%%26first%%3DN%%26dayssince%%3D2"
-		"%%26p1%%3D0%%26p2%%3D0%%26p3%%3D0%%26p4%%3D0%%26p5%%3D0%%26"
-		"rows%%3D25%%26pagebid%%3D1%%26pagewon%%3D1%%26pagesell%%3D1"
-		"%%26pagesold%3D1%%26pageunsold%%3D1%%26pagelost%%3D1%%26"
-		"page%%3D1%%26all%%3D1%%26SaveSetting%%3D362413158%%26pass"
-		"%%3D%%7B_pass_%%7D%%26userid%%3D&pp=pass&pa1=&pa2=&pa3=&"
-		"i1=-1&pageType=368&userid=%s&pass=%s", authID, authPASS);
-
-	URL *myurl = new URL(address, proxyurl);
-	ret = fetchURL(myurl, 1, &Buff, TIMEOUT, 0);
-	delete(myurl);
-
-	printf("BUFF: %s\n", Buff);
-
-
-	free(Buff);
-}
-*/
-
 //////////////////////////////////////////////////////////////////////////////
 //
 // GetUserAuctions - grabs users auctions from ebay and adds them to
@@ -4126,6 +4137,8 @@
   char WebPage[200];
   int returnVal;
   unsigned long long *ids;
+  char cookiejar[200];
+  sprintf(cookiejar, "%s/%s/cookies.txt", getenv("HOME"), bw_subdir);
 
   if (!trackBids) return GUA_SUCCESS;
   if (strlen(authID) < 2) return GUA_BADUSER;
@@ -4136,8 +4149,8 @@
   sprintf(WebPage, "http://cgi.ebay.com/aw-cgi/eBayISAPI.dll?"
 	  "MfcISAPICommand=ViewBidItems&userid=%s&completed=0&all=1&rows=200",// items the user has bid on
 	  authID);
-  URL *bidsurl = new URL(WebPage, proxyurl);
-  returnVal = fetchURL(bidsurl, 0, &Buff, TIMEOUT, 0);
+  URL *bidsurl = new URL(WebPage, "", proxyurl);
+  returnVal = fetchURL(bidsurl, 0, &Buff, cookiejar, 0);
   delete(bidsurl);
   blackLED();
   showStatus("");
@@ -4221,8 +4234,8 @@
 	    "http://cgi6.ebay.com/ws/eBayISAPI.dll?ViewSellersOtherItems&userid=%s&sort=3&completed=0&since=-1&rd=1",
 	    authID);
 
-    URL *listingurl = new URL(WebPage, proxyurl);
-    returnVal = fetchURL(listingurl, 0, &Buff, TIMEOUT, 0);
+    URL *listingurl = new URL(WebPage, "", proxyurl);
+    returnVal = fetchURL(listingurl, 0, &Buff, NULL, 0);
     delete listingurl;
     blackLED();
     showStatus("");
@@ -4415,18 +4428,18 @@
     delete(infourl);
     infourl = NULL;
   }
-  infourl = new URL(urlstring, proxyurl);
+  infourl = new URL(urlstring, "", proxyurl);
 
   greenLED();
-  returnVal = fetchURL(infourl, 0, &HtmlBuff, TIMEOUT, 0);
+  returnVal = fetchURL(infourl, 0, &HtmlBuff, NULL, 0);
 
   if (returnVal == NET_NETERROR || returnVal == NET_TIMEOUT) {
     // maybe proxy settings changed
     if (infourl != NULL)
       delete(infourl);
-    infourl = new URL(urlstring, proxyurl);
+    infourl = new URL(urlstring, "", proxyurl);
 
-    returnVal = fetchURL(infourl, 0, &HtmlBuff, TIMEOUT, 0);
+    returnVal = fetchURL(infourl, 0, &HtmlBuff, NULL, 0);
 
     if (returnVal == NET_NETERROR || returnVal == NET_TIMEOUT) {
       // Ok, so it probably is borked.
@@ -4529,7 +4542,7 @@
       gettimeofday(&tm_start, NULL);
 
       resetTimeSyncURL();
-      returnVal = fetchURL(timesyncurl, 0, &HtmlBuff, TIMEOUT, 0);
+      returnVal = fetchURL(timesyncurl, 0, &HtmlBuff, NULL, 0);
 
       gettimeofday(&tm_end, NULL);
       t1 = (tm_end.tv_sec + 0.000001 * tm_end.tv_usec)
@@ -4692,7 +4705,7 @@
   }
 
   timesyncurl = new URL("http://cgi3.ebay.com/aw-cgi/eBayISAPI.dll?TimeShow",
-			proxyurl);
+                        "",proxyurl);
 }
 
 /////////////////////////////////////////////////////////////////////////////
