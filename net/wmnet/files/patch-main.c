--- main.c.orig	Sat Jun  5 15:28:39 2004
+++ main.c	Sat Jun  5 15:28:46 2004
@@ -32,11 +32,11 @@
 #define LED_SZE_Y (4)
 
 #define LED_ON_NET_X (87)
-#define LED_ON_NET_Y (66)
+#define LED_ON_NET_Y (92)
 #define LED_OFF_NET_X (93)
-#define LED_OFF_NET_Y (66)
+#define LED_OFF_NET_Y (92)
 #define LED_ERR_NET_X (81)
-#define LED_ERR_NET_Y (66)
+#define LED_ERR_NET_Y (92)
 
 #define LED_PWR_X (53)
 #define LED_PWR_Y (7)
@@ -52,6 +52,7 @@
 static unsigned findInterface(char const*);
 static void printversion(void);
 static char const *rateToStr(unsigned long);
+static double getRate(unsigned long, char *);
 static void SetErrLED(int);
 static void SetOffLED(int);
 static void SetOnLED(int);
@@ -68,7 +69,7 @@
 ------------------------------------------------------------------------------*/
 static void DrawActiveIFS(char const* name)
 {
-    copyXPMArea(5, 84, 30, 10, 5, 5);
+    copyXPMArea(5, 110, 30, 10, 5, 5);
 
 	if (name) {
 		int ii, kk = 5;
@@ -77,9 +78,9 @@
 			int const ch = toupper(name[ii]);
 
 			if (ch >= 'A' && ch <= 'Z')
-				copyXPMArea((ch - 'A') * 6, 74, 6, 9, kk, 5);
+				copyXPMArea((ch - 'A') * 6, 100, 6, 9, kk, 5);
 			else
-				copyXPMArea((ch - '0') * 6, 64, 6, 9, kk, 5);
+				copyXPMArea((ch - '0') * 6, 90, 6, 9, kk, 5);
 			kk += 6;
 		}
 	}
@@ -91,25 +92,22 @@
 static void DrawStats(unsigned ifCurr, int height, int x_left, int y_bottom)
 {
     unsigned baseLine = y_bottom - height / 2;
-    unsigned maxVal = 0, ii;
+    unsigned maxVal = 0, ii, currVal = 0;
     char const* ptr = 0;
 
     /* Find the maximum value. We'll scale the graph to this value. */
+	unsigned long rcv, xmt;
 
 	for (ii = 0; ii < G_WIDTH; ++ii) {
-		unsigned long rcv, xmt;
 
 		ifGetData(ifCurr, ii, &xmt, &rcv);
 
 		xmt /= delay;
 		rcv /= delay;
-
-		if (rcv > maxVal)
-			maxVal = rcv;
-		if (xmt > maxVal)
-			maxVal = xmt;
+		currVal = xmt > rcv ? xmt : rcv ;
+		if (currVal > maxVal)
+			maxVal = currVal;
     }
-    ptr = rateToStr(maxVal);
 
     /* Now draw the data points. */
 
@@ -127,27 +125,58 @@
 		}
 		for (jj = 0; jj < height; ++jj)
 			if (y_bottom - jj <= start && y_bottom - jj >= stop)
-				copyXPMArea(100 + 1, 68, 1, 1, ii + x_left, y_bottom - jj);
+				copyXPMArea(99 + 1, 106, 1, 1, ii + x_left, y_bottom - jj);
 			else
-				copyXPMArea(100, 68, 1, 1, ii + x_left, y_bottom - jj);
+				copyXPMArea(99, 106, 1, 1, ii + x_left, y_bottom - jj);
 
 		/* Draw the base line. */
 
-		copyXPMArea(100 + 3, 68, 1, 1, ii + x_left, baseLine);
+		copyXPMArea(100, 106, 1, 1, ii + x_left, baseLine);
 	}
 
-    /* Now draw the data rate... */
+    /* Now draw the download data rate... */
+	
+	/* Clear area */
+	copyXPMArea( 6, 111, 54 , 9 , 6, 63);
+
+	ptr = rateToStr(rcv);
+	copyXPMArea(('D' - 'A') * 6, 100, 6, 9, 6,
+				62);
+	copyXPMArea(64, 90, 4, 9, 12,
+				62);
+	for (ii = 20; *ptr; ++ptr)
+		if (isdigit(*ptr)) {
+			copyXPMArea((*ptr - '0') * 6, 90, 6, 9, 1 + ii, 62 );
+			ii += 6;
+		} else if ('.' == *ptr) {
+			copyXPMArea(60, 90, 4, 9, 1 + ii, 62);
+			ii += 4;
+		} else {
+			copyXPMArea((toupper(*ptr) - 'A') * 6, 100, 6, 9, 1 + ii,
+						62);
+			ii += 6;
+		}
+    
+	/* Now draw the upload data rate... */
+	
+	/* Clear area */
+	copyXPMArea( 6, 111, 54 , 9 , 6, 76);
 
-	for (ii = 5; *ptr; ++ptr)
+	ptr = rateToStr(xmt);
+	copyXPMArea(('U' - 'A') * 6, 100, 6, 9, 6,
+				75);
+	copyXPMArea(64, 90, 4, 9, 12,
+				75);
+	for (ii = 20; *ptr; ++ptr)
 		if (isdigit(*ptr)) {
-			copyXPMArea((*ptr - '0') * 6, 64, 6, 9, 1 + ii, y_bottom - 10);
+			copyXPMArea((*ptr - '0') * 6, 90, 6, 9, 1 + ii, 75 );
 			ii += 6;
 		} else if ('.' == *ptr) {
-			copyXPMArea(60, 64, 4, 9, 1 + ii, y_bottom - 10);
+			copyXPMArea(60, 90, 4, 9, 1 + ii, 75);
 			ii += 4;
 		} else {
-			copyXPMArea((toupper(*ptr) - 'A') * 6, 74, 6, 9, 1 + ii,
-						y_bottom - 10);
+			copyXPMArea((toupper(*ptr) - 'A') * 6, 100, 6, 9, 1 + ii,
+						75);
 			ii += 6;
 		}
 
@@ -205,41 +234,39 @@
 ------------------------------------------------------------------------------*/
 static char const* rateToStr(unsigned long rate)
 {
-	static char buffer[7];
-	char scaleFactor, *ptr = buffer;
+	static char buffer[14];
+	char scaleFactor='\0', *ptr = buffer;
 
-	/* Based upon its magnitude, determine how much 'rate' needs to be
-	   scaled and also indicate its unit of scale. */
-
-	if (rate > 1000000) {
-		rate /= 100000;
-		scaleFactor = 'M';
-	} else if (rate > 1000) {
-		rate /= 100;
-		scaleFactor = 'K';
-	} else {
-		rate *= 10;
-		scaleFactor = '\0';
-	}
+	double drate = getRate(rate,&scaleFactor);
 
-	/* Transform the value into a left - justified string. */
-
-	if (rate >= 1000)
-		*ptr++ = rate / 1000 + '0';
-	if (rate >= 100)
-		*ptr++ = (rate / 100) % 10 + '0';
-	if (rate >= 10)
-		*ptr++ = (rate / 10) % 10 + '0';
-	if (scaleFactor) {
-		*ptr++ = '.';
-		*ptr++ = rate % 10 + '0';
-	}
+	/* Transform the rate value into a left - justified string. */
+	ptr+=sprintf(ptr,"%.1f",drate);
 	*ptr++ = scaleFactor;
 	*ptr = '\0';
 	return buffer;
 }
 
 /*------------------------------------------------------------------------------
+  getRate
+------------------------------------------------------------------------------*/
+static double getRate(unsigned long rate, char *scaleFactor)
+{
+	 double drate = rate;
+
+	/* Based upon its magnitude, determine how much 'rate' needs to be
+	   scaled and also indicate its unit of scale. */
+
+	if (rate > 1048576) {
+		drate /= 1048576;
+		*scaleFactor = 'M';
+	} else if (rate > 1024) {
+		drate /= 1024;
+		*scaleFactor = 'K';
+	}
+	return drate;
+}
+
+/*------------------------------------------------------------------------------
   SetErrLED
 ------------------------------------------------------------------------------*/
 static void SetErrLED(int led)
@@ -314,10 +341,11 @@
 {
     static char const txt[] =
 		"\nwmnet, v1p2 - A network interface monitor for WindowMaker.\n\n"
-		"\t-h         this help screen\n"
-		"\t-i name    start with interface 'name'\n"
-		"\t-u delay   seconds between samples (defaults to 1)\n"
-		"\t-v         print the version number\n";
+		"\t-h               this help screen\n"
+		"\t-i name          start with interface 'name'\n"
+		"\t-u delay         seconds between samples (defaults to 1)\n"
+		"\t-geom <geometry> geometry to use\n"
+		"\t-v               print the version number\n";
 
     fputs(txt, stderr);
 }
@@ -425,6 +453,13 @@
 			case 'v':
 				printversion();
 				return 0;
+			
+			case 'g':
+				if (ii + 1 == argc) {
+					printf("wmnet: must specify geometry\n");
+					return 0;
+				}
+				break;
 
 			default:
 				usage();
