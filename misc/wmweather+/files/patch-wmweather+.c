--- wmweather+.c.orig	Sun Mar 23 01:04:41 2003
+++ wmweather+.c	Fri Apr 11 02:07:45 2003
@@ -103,7 +103,7 @@
 /**********************************
  * Prototypes
  **********************************/
-void usage(int i) __THROW __attribute__ ((__noreturn__));
+void usage(int i);
 void printversion(void);
 int readconf(char *file);
 int parse_option(char *option, char *value);
@@ -671,12 +671,12 @@
         F("Please specify a METAR station.\n   See http://www.nws.noaa.gov/tg/siteloc.shtml\n");
     }
     if(latitude==999){{
-        time_t t=0;
         int flag=0;
-
-        localtime(&t);
+	time_t t=time(NULL);
+	struct tm *tm;
+	tm=gmtime(&t);
         latitude=0;
-        longitude=timezone/240;
+        longitude=tm->tm_gmtoff/240;
         if(longitude<0){
             flag=1;
             longitude=-longitude;
