--- telnet.h.orig	2025-05-15 15:31:27 UTC
+++ telnet.h
@@ -9,7 +9,7 @@ void TelProcessLine(char **, size_t *);
 int TelOpenAndConnect(Window *);
 int TelIsline(Window *);
 void TelProcessLine(char **, size_t *);
-int DoTelnet(char *, size_t *, int);
+int DoTelnet(char *, int *, int);
 int TelIn(Window *, char *, size_t, int);
 void TelBreak(Window *);
 void TelWindowSize(Window *);
