diff -urN bidwatcher-1.3.16/bidwatcher.h bidwatcher-1.3.16-SSL-2/bidwatcher.h
--- bidwatcher.h.orig	2004-08-31 02:40:13.000000000 +0200
+++ bidwatcher.h	2004-12-14 17:10:14.000000000 +0100
@@ -122,19 +122,15 @@
 #define array_elem(a)	(sizeof(a)/sizeof(a[0]))
 
 struct URL {
-  struct hostent *hostinfo;
-  unsigned int port;
-  char url[256], hoststring[256];
+  char fullurl[512], fullurlpost[512];
   bool useproxy;
-  int numaliases;
-  int numaddrs;
   char *proxyuser, *proxypass;
 
   URL(); // since there is dynamic memory involved, be safe.
-  URL(char *newurl, URL *proxy);
-  URL(char *newurl, URL *proxy, char *user, char *pass);
+  URL(char *newurl, char *postval, URL *proxy);
+  URL(char *newurl, char *postval, URL *proxy, char *user, char *pass);
   ~URL();
-  void create(char *newurl, URL *proxy);
+  void create(char *newurl, char *postval, URL *proxy);
 };
 
 //
@@ -399,7 +395,7 @@
 void translate_date(char *date);
 bool GetAucInfo(char *Buff, struct auctioninfo *NewAuction);
 int calcTimeDiff (char *buffer);
-int fetchURL(URL *url, int Post, char **Buff, double timeOut, int redir);
+int fetchURL(URL *url, int Post, char **Buff, char *cookiejar, int redir);
 char *stristr(const char *haystack, const char *needle);
 char translate_special(const char *input, int *len);
 char *getTimeStamp();
