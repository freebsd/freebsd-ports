
Add the following file as files/patch-src-irr-rawhoisc.cc and bump
PORTREVISION (to 1).

--- src/irr/rawhoisc.cc.orig	Thu Jun  8 08:16:26 2006
+++ src/irr/rawhoisc.cc	Tue Jan 23 15:14:24 2007
@@ -1,4 +1,4 @@
-//  $Id: rawhoisc.cc,v 4.11 2006/06/08 15:16:26 shane Exp $
+//  $Id: rawhoisc.cc,v 4.11.10.1 2006/12/08 08:33:52 shane Exp $
 // Copyright (c) 2001,2002                        RIPE NCC
 //
 // All Rights Reserved
@@ -187,7 +187,7 @@
 }
 
 void RAWhoisClient::GetVersion() {
-   char *buffer = (char *) calloc (80,1);
+   char *buffer;
    char *start;
 
    if (! _is_open)
@@ -199,7 +199,7 @@
    start = start + 8; //jump
    version = atoi(start)*10 + atoi(start+2); // x.x... format  
    Trace(TR_WHOIS_RESPONSE) << "Whois: Response " << buffer << endl;
-   free(buffer);
+   delete [] buffer;
 }
 
 void RAWhoisClient::SetSources(const char *_sources) {
@@ -298,9 +298,11 @@
       return 0;
    }
    if (is_rpslng()) {
-      response = strdup("");
-      char *prev;
+      response = new char[1];
+      response[0] = '\0';
+      char *prev = NULL;
       do {
+      	free(prev);
         prev = strdup(buffer);
         Trace(TR_WHOIS_RESPONSE) << "Whois: Response <<\n" << buffer <<">>"<< endl;
         if (strstr (buffer, "route") || strstr(buffer, "route6")) {
@@ -315,18 +317,20 @@
           // save response
           tmp = strdup (response);
           // allocate new string
+          delete [] response;
           response = new char [strlen(tmp) + strlen(end_prefix) + 2];
-          memset(response, 0, strlen(response));
           // copy old and new response
-          strncat (response, tmp, strlen(tmp));
-          strncat (response, " ", 1);
-          strncat (response, end_prefix, strlen(end_prefix));
+          strcpy(response, tmp);
+          strcat(response, " ");
+          strcat(response, end_prefix);
           free(tmp);
         }
       } while (fgets(buffer, sizeof(buffer), in) && 
       // this condition should work with irrd version >= 2.2b19
       // until then, ripe-style queries won't work with persistent connections
                !((*prev == '\n') && (*buffer == '\n')));
+
+      free(prev);
 
       // The WHOIS protocol and RPSL give no indication of
       // end of a protocol data unit, so we need to keep
