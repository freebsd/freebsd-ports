--- sma.h.orig	2003-04-03 09:43:53 UTC
+++ sma.h
@@ -55,102 +55,102 @@
 #define FORMAT_CLOG	5
 
 /* pointer to program name: */
-char *pname;
+extern char *pname;
 
 /* current time: */
-time_t tval;
-struct tm *curr;
-struct tm tp;
+extern time_t tval;
+extern struct tm *curr;
+extern struct tm tp;
 
 /*
  * Command line arguments
  * xflag sets argument x on/off
  * xchar is pointer to argument string if x requires an argument
  */
-int aflag;
-int cflag;
-int dflag;
-int hflag;
-int nflag;
-int sflag;
-int qflag;
-int lflag;
-int vflag;
-int wflag;
-unsigned int lnum;
-unsigned int lrnum;
-int rflag;
-unsigned int rnum;
-unsigned int rrnum;
-int bflag;
-const char *bchar;
-int fflag;
-const char *fchar;
-int oflag;
-const char *ochar;
-int Lflag;
-const char *Lchar;
-int Oflag;
-const char *Ochar;
-int Dflag;
-const char *Dchar;
-int pflag;
-int iflag;
-int tflag;
-int dcaddrflag;
-const char *tchar;
+extern int aflag;
+extern int cflag;
+extern int dflag;
+extern int hflag;
+extern int nflag;
+extern int sflag;
+extern int qflag;
+extern int lflag;
+extern int vflag;
+extern int wflag;
+extern unsigned int lnum;
+extern unsigned int lrnum;
+extern int rflag;
+extern unsigned int rnum;
+extern unsigned int rrnum;
+extern int bflag;
+extern const char *bchar;
+extern int fflag;
+extern const char *fchar;
+extern int oflag;
+extern const char *ochar;
+extern int Lflag;
+extern const char *Lchar;
+extern int Oflag;
+extern const char *Ochar;
+extern int Dflag;
+extern const char *Dchar;
+extern int pflag;
+extern int iflag;
+extern int tflag;
+extern int dcaddrflag;
+extern const char *tchar;
 
 /* Configuration file parameters: */
-int Hflag;
-const char *Hchar;
-int Cflag;
-const char *Cchar;
-int Fflag;
-const char *tbchar;
-int pgflag;
-const char *bechar;
-const char *cfchar;
-const char *puchar;
-const char *pachar;
-const char *plchar;
-const char *ppchar;
-const char *htchar;
-const char *ftchar;
-int csflag;
-int lrflag;
-int rrflag;
-int clsflag;
-unsigned int stnum;
-unsigned int rsnum;
-unsigned int rsrnum;
-unsigned int epnum;
-unsigned int rpnum;
+extern int Hflag;
+extern const char *Hchar;
+extern int Cflag;
+extern const char *Cchar;
+extern int Fflag;
+extern const char *tbchar;
+extern int pgflag;
+extern const char *bechar;
+extern const char *cfchar;
+extern const char *puchar;
+extern const char *pachar;
+extern const char *plchar;
+extern const char *ppchar;
+extern const char *htchar;
+extern const char *ftchar;
+extern int csflag;
+extern int lrflag;
+extern int rrflag;
+extern int clsflag;
+extern unsigned int stnum;
+extern unsigned int rsnum;
+extern unsigned int rsrnum;
+extern unsigned int epnum;
+extern unsigned int rpnum;
 
 /* Start and end times: */
-char *sstring;
-char *estring;
-char *tstring;
-time_t sstime;
-time_t eetime;
-int syear;
-int smonth;
-int sday;
-int shour;
-int sminute;
-int ssecond;
-int eyear;
-int emonth;
-int eday;
-int ehour;
-int eminute;
-int esecond;
+extern char *sstring;
+extern char *estring;
+extern char *tstring;
+extern time_t sstime;
+extern time_t eetime;
+extern int syear;
+extern int smonth;
+extern int sday;
+extern int shour;
+extern int sminute;
+extern int ssecond;
+extern int eyear;
+extern int emonth;
+extern int eday;
+extern int ehour;
+extern int eminute;
+extern int esecond;
 
 /* hash table sizes: */
-int asize;
-int rsize;
-char *hsstring;
-char *hastring;
-char *hrstring;
+extern int asize;
+extern int rsize;
+extern char *hsstring;
+extern char *hastring;
+extern char *hrstring;
 
 /* sender structure: */
 struct in {
@@ -456,25 +456,25 @@ struct host {
 };
 
 /* Filters */
-char *sef;
-char *ref;
-char *srf;
-char *rrf;
+extern char *sef;
+extern char *ref;
+extern char *srf;
+extern char *rrf;
 #ifdef USE_REGEXP
-regex_t csef;
-regex_t cref;
-regex_t csrf;
-regex_t crrf;
+extern regex_t csef;
+extern regex_t cref;
+extern regex_t csrf;
+extern regex_t crrf;
 #endif
 
 /* Output file handle: */
-FILE *ofp;
+extern FILE *ofp;
 
 /* total number of hosts: */
-int hosts;
+extern int hosts;
 
 /* inital host structure: */
-struct host first;
+extern struct host first;
 
 /* function definitions: */
 void usage(void);
