# Correct strings that should be const
#
--- src/mga_merge.c.orig	2017-01-17 22:40:29 UTC
+++ src/mga_merge.c
@@ -18,12 +18,12 @@
 #include "fbdevhw.h"
 
 static int
-StrToRanges(range* r, char* s) {
+StrToRanges(range* r, const char* s) {
     float num=0.0;
     int rangenum=0;
     Bool gotdash = FALSE;
     Bool nextdash = FALSE;
-    char* strnum=NULL;
+    const char* strnum=NULL;
     do {
         switch(*s) {
             case '0': case '1': case '2': case '3': case '4': case '5':
@@ -117,7 +117,7 @@ CopyModeNLink(ScrnInfoPtr pScrn, Display
 }
 
 static DisplayModePtr
-GetModeFromName(char* str, DisplayModePtr i)
+GetModeFromName(const char* str, DisplayModePtr i)
 {
     DisplayModePtr c = i;
     if(!i) return NULL;
@@ -130,9 +130,9 @@ GetModeFromName(char* str, DisplayModePt
 
 /* takes a config file string of MetaModes and generates a MetaModeList */
 static DisplayModePtr
-GenerateModeList(ScrnInfoPtr pScrn, char* str,
+GenerateModeList(ScrnInfoPtr pScrn, const char* str,
 		 DisplayModePtr i, DisplayModePtr j, MgaScrn2Rel srel) {
-    char* strmode = str;
+    const char* strmode = str;
     char modename[256];
     Bool gotdash = FALSE;
     MgaScrn2Rel sr;
@@ -165,7 +165,7 @@ GenerateModeList(ScrnInfoPtr pScrn, char
                     } else {
                         mode1 = GetModeFromName(modename,i);
                         if(!mode1) {
-                            char* tmps = str;
+                            const char* tmps = str;
                             xf86DrvMsg(pScrn->scrnIndex, X_CONFIG,
                                 "Mode: \"%s\" is not a supported mode for monitor 1\n",modename);
                             /* find if a monitor2 mode follows */
@@ -232,7 +232,7 @@ MGAPreInitMergedFB(ScrnInfoPtr pScrn1, i
     MGAPtr pMga1;
     MessageType from;
     int i;
-    char* s;
+    const char* s;
     ClockRangePtr clockRanges;
     MgaScrn2Rel Monitor2Pos;
 
