--- helpers.cpp.orig	Sat Dec 21 00:00:42 2002
+++ helpers.cpp	Sun Dec 29 09:31:01 2002
@@ -344,13 +344,16 @@
 //////////////////////////////////////////////////////////////////////
 char * StripAndTab(const char * stringToStrip)
 {
-  char *Buff=(char *)malloc(strlen(stringToStrip));
-  Buff[0]='\0';
   int buffLength = strlen(stringToStrip);
   int BuffIdx = 0;
   int u,c;
   int IncludeFlag = 5;
   bool tabFlag = FALSE;
+  if (!buffLength) {
+    ++buffLength;	// some malloc's don't handled malloc(0) well
+  }
+  char *Buff=(char *)malloc(buffLength);
+  Buff[0]='\0';
   for (u = 0; (u < buffLength);u++) {
     c = stringToStrip[u];
     if (c=='<') {
