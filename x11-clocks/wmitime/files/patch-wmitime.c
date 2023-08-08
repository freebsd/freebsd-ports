--- wmitime.c.orig	2015-08-22 01:42:17 UTC
+++ wmitime.c
@@ -248,7 +248,7 @@ void DrawInetTime(void)
 
     /* Compute Inet Time */
     iTime=(clk->tm_hour*3600+clk->tm_min*60+clk->tm_sec);
-    iTime=iTime+((timezone-1)+3600);
+    iTime=iTime+((1-clk->tm_gmtoff)+3600);
     if (clk->tm_isdst)
         iTime-=3600;
     iTime=(iTime*1000)/86400;
@@ -283,11 +283,11 @@ void DrawStdTime(void)
         if (i==0)
             i=12;
 
-        sprintf(blitstr, "%2i:%02i:%02i", i, clk->tm_min, clk->tm_sec);
+        snprintf(blitstr, sizeof(blitstr), "%2i:%02i:%02i", i, clk->tm_min, clk->tm_sec);
     }
     else
     {
-        sprintf(blitstr, "%02i:%02i:%02i", i, clk->tm_min, clk->tm_sec);
+        snprintf(blitstr, sizeof(blitstr), "%02i:%02i:%02i", i, clk->tm_min, clk->tm_sec);
     }
 
 
@@ -344,7 +344,7 @@ void DrawDate(void)
     inbytesleft = sizeof OrigBlitStr;
     outbytesleft = sizeof BlitStr;
 
-    sprintf(OrigBlitStr, "%s", nl_langinfo(ABDAY_1 + clk->tm_wday));
+    snprintf(OrigBlitStr, sizeof(OrigBlitStr), "%s", nl_langinfo(ABDAY_1 + clk->tm_wday));
     iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
     BlitStr[2] = 0;
     BlitString( BlitStr, 6, 50);
@@ -354,14 +354,14 @@ void DrawDate(void)
     inbytesleft = sizeof OrigBlitStr;
     outbytesleft = sizeof BlitStr;
 
-    sprintf(OrigBlitStr, "%s", nl_langinfo(ABMON_1 + clk->tm_mon));
+    snprintf(OrigBlitStr, sizeof(OrigBlitStr), "%s", nl_langinfo(ABMON_1 + clk->tm_mon));
     iconv(cd, &inbuf, &inbytesleft, &outbuf, &outbytesleft);
     BlitStr[3] = 0;
     BlitString( BlitStr, 40, 50);
 
     iconv_close(cd);
 
-    sprintf(BlitStr, "%02i", clk->tm_mday);
+    snprintf(BlitStr, sizeof(BlitStr), "%02i", clk->tm_mday);
     BlitString( BlitStr, 25, 50);
 }
 
@@ -374,7 +374,7 @@ void DrawInetWheel(void)
 
     /* Calculate Wheel Position... */
     iTime=(clk->tm_hour*3600+clk->tm_min*60+clk->tm_sec);
-    iTime=iTime+((timezone-1)+3600);
+    iTime=iTime+((1-clk->tm_gmtoff)+3600);
     if (clk->tm_isdst)
         iTime-=3600;
     iTime=(iTime*1000)/8640;
@@ -566,7 +566,7 @@ void BlitNum(int num, int x, int y)
     char buf[1024];
     int newx=x;
 
-    sprintf(buf, "%03i", num);
+    snprintf(buf, sizeof(buf), "%03i", num);
 
     BlitString(buf, newx, y);
 }
