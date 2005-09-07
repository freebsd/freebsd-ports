Index: helpers.cpp
===================================================================
RCS file: /cvsroot/bidwatcher/bidwatcher/Attic/helpers.cpp,v
retrieving revision 1.90.2.57
retrieving revision 1.90.2.59
diff -u -B -b -w -r1.90.2.57 -r1.90.2.59
--- helpers.cpp.orig	25 Feb 2005 13:47:37 -0000	1.90.2.57
+++ helpers.cpp	11 Aug 2005 00:00:57 -0000	1.90.2.59
@@ -54,7 +54,7 @@
 
 const char * const CheckPrice="0123456789.$,";      // Characters allowed in a price
 
-const char * const SearchOps[2][36]={{ "Starts at",           // 1
+const char * const SearchOps[2][37]={{ "Starts at",           // 1
 			  "Currently",           // 2
 			  "First bid",           // 3
 			  "Quantity",            // 4
@@ -91,6 +91,7 @@
                           "Shipping Cost Services Available", // 33, newer version of above
 				" price:",                // 34
 				"price:",				// 35
+			  "Seller information",     // 36
 			  "*"},
 			/* eBay Motors */
 			{ "Currently",           // 1
@@ -350,12 +351,26 @@
 char *StripHtmlTags(const char *stringToStrip) {
   int buffLength = strlen(stringToStrip);
 
+#if DEBUGGING > 0
+#warning "Buffer is double its normal size"
+  char *Buff = (char *) malloc(buffLength*2 + 1);
+  memset(Buff, 0, buffLength*2 + 1);
+#else
   char *Buff = (char *) malloc(buffLength + 1);
   memset(Buff, 0, buffLength + 1);
+#endif
 
   int BuffIdx = 0;
   int u,c;
-  int IncludeFlag = 5; // strip up everything before the first tag, too
+  int SaveIncludeFlag=5, IncludeFlag;
+  // states of IncludeFlag:
+  // 1  - HTML double quote text
+  // 2  - a comment
+  // 3  - java script
+  // 5  - within a HTML statement
+  // 10 - content (and no HTML stuff)
+
+  IncludeFlag = 5; // strip up everything before the first tag, too
   // strip the html tags
   for (u = 0; u < buffLength; u++) {
     c = stringToStrip[u];
@@ -378,14 +393,37 @@
 	    stringToStrip[u+3] == '>') {
 	  Buff[BuffIdx++] = '\n';
 	  u+=2;
+	} else if (stringToStrip[u+1] == '!' && \
+	    stringToStrip[u+2] == '-' && \
+            stringToStrip[u+3] == '-') {
+	  IncludeFlag=2;
+	  u+=3;
+	}
 	}
+    } else if (c == '"' && IncludeFlag < 10) {
+      if (IncludeFlag != 1) {
+	SaveIncludeFlag = IncludeFlag;
+	IncludeFlag = 1;
+      } else {
+      	IncludeFlag = SaveIncludeFlag;
       }
+      continue;
+    } else if (IncludeFlag == 1 && c != '"') {
+      continue;
     } else if (c == '\\' && stringToStrip[u+1] == '>') {
       u += 1;
       continue;
-
-    } else if (c == '>') {
+    } else if (c == '>' && IncludeFlag < 10 && IncludeFlag >= 5) {
       IncludeFlag=10;
+    } else if (c == '-' && u+1<buffLength && IncludeFlag==2) {
+	if (stringToStrip[u+1] == '-' && \
+	    stringToStrip[u+2] == '>') {
+	  Buff[BuffIdx++] = '\n';
+	  IncludeFlag=10;
+	  u+=2;
+	} else {
+	  u+=1;
+	}
     } else if (IncludeFlag==10) {
       if ((BuffIdx > 0) && (c == ' ') &&
 	  (Buff[BuffIdx-1] != ' ') &&
@@ -735,11 +773,12 @@
   else ops_type = auc_type;
 
   // Watch the change, it's strNcmp now.
-  for(idx=0; SearchOps[ops_type][idx][0]!='*';++idx)
+  for(idx=0; SearchOps[ops_type][idx][0]!='*';++idx) {
     if (strncmp(LineData, SearchOps[ops_type][idx],
 		strlen(SearchOps[ops_type][idx]))==0) {
       return (idx+1);
     }
+  }
 
   return 0;
 
@@ -1030,7 +1069,7 @@
     }
   }
 
-   int idx=0;
+   unsigned int idx=0;
    int cnt;
    int ended_early=0;
    int auc_type=TYPE_EBAY;
@@ -1065,23 +1104,44 @@
     * but that's not what I'm going to do right now.
     * Thanks to Bob Beaty!
     */
-   scratch = strstr(Buff, ") -");
+   scratch = strstr(Buff, "eBay: ");
    if (scratch != NULL) {
-     // move past the ") -"
-     scratch += 3;
+     DPRINTF(DLOW, ("found 'eBay:' in auction, new type, scanning...\n"));
+     // move past the "eBay: "
+     scratch += strlen("eBay: ");
+
      // move past any whitespace
      while (isspace(*scratch)) scratch++;
      // copy over the description to a newline
      idx = 0;
-     while (*scratch != '\n') {
+     while (*scratch != '\n' && idx < sizeof(Description) - 1) {
        Description[idx++] = *scratch++;
      }
      // NULL terminate the description I just parsed off
-     Description[idx] = '\0';
+     Description[idx-1] = '\0';
    } else {
+     scratch = strstr(Buff, "eBay Motors: ");
+     if (scratch != NULL) {
+       DPRINTF(DLOW, ("found 'eBay Motors:' in auction. New type. Scanning...\n"));
+       // move past the "eBay Motors:"
+       scratch += 12;
+       // move past any whitespace
+       while (isspace(*scratch)) scratch++;
+       // copy over the description to a newline
+       idx = 0;
+       while (*scratch != '(' && idx < sizeof(Description) - 1) {
+        Description[idx++] = *scratch++;
+       }
+       // NULL terminate the description I just parsed off
+       Description[idx-1] = '\0';
+       DPRINTF(DLOW, ("Auction name = '%s'\n", Description));
+     } else {
+       DPRINTF(DLOW, ("no mandatory matching 'eBay:' nor 'eBay Motors:' in buffer\n"));
      return FALSE;
    }
 
+   }
+
    StringBuffer streamBuff(Buff);
    /* Skip everything before the start of auction data */
 
@@ -1090,14 +1150,16 @@
    while(strstr(LineBuffer.buf(),"eBay")==NULL && streamBuff)
      streamBuff.getline(LineBuffer.buf(), LineBuffer.size(), '\n');
 
-   if (strstr(LineBuffer.buf(),"eBay item") == NULL)
-     if (strstr(LineBuffer.buf(),"eBay Motors item") == NULL)
+   if (strstr(LineBuffer.buf(),"eBay: ") == NULL)
+     if (strstr(LineBuffer.buf(),"eBay Motors: ") == NULL) {
+       DPRINTF(DLOW, ("no matching 'eBay:' nor 'eBay Motors:' in buffer. Failed.\n"));
        return FALSE;
+     }
 
-   if (strstr(LineBuffer.buf(),"eBay Motors item") != NULL)
+   if (strstr(LineBuffer.buf(),"eBay Motors:") != NULL)
      auc_type = TYPE_EBAYMOTORSCAR;
 
-   while(strstr(LineBuffer.buf(),") -")==NULL && streamBuff)
+   while(strstr(LineBuffer.buf()," (item")==NULL && streamBuff)
      streamBuff.getline(LineBuffer.buf(), LineBuffer.size(), '\n');
 
    if ( strstr(LineBuffer.buf(),"Another buyer used Buy It Now to purchase the item immediately") == NULL ){
@@ -1282,6 +1344,8 @@
 		}
 
            scratch = strstr(LineBuffer.buf(), ":");
+	   if (*(scratch+1) == '\n')
+	     streamBuff.getline(LineBuffer.buf(), LineBuffer.size(), '\n');
            //strcpy(LineBuffer.buf(),scratch);
            parseprice2(scratch, this, FALSE);
            if (!CurrentBid ) {
@@ -1398,6 +1462,7 @@
 	 case 10: // seller id
 	 case 18:
 	 case 21:
+	 case 36:
 	   if (!Seller[0]) {
 	     unsigned int count;
 
