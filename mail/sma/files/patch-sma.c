--- sma.c.orig	2003-01-16 11:14:42 UTC
+++ sma.c
@@ -34,6 +34,125 @@ extern int sma_optind;
 
 #include "sma.h"
 
+/* pointer to program name: */
+char *pname;
+
+/* current time: */
+time_t tval;
+struct tm *curr;
+struct tm tp;
+
+/*
+ * Command line arguments
+ * xflag sets argument x on/off
+ * xchar is pointer to argument string if x requires an argument
+ */
+int aflag;
+int cflag;
+int dflag;
+int hflag;
+int nflag;
+int sflag;
+int qflag;
+int lflag;
+int vflag;
+int wflag;
+unsigned int lnum;
+unsigned int lrnum;
+int rflag;
+unsigned int rnum;
+unsigned int rrnum;
+int bflag;
+const char *bchar;
+int fflag;
+const char *fchar;
+int oflag;
+const char *ochar;
+int Lflag;
+const char *Lchar;
+int Oflag;
+const char *Ochar;
+int Dflag;
+const char *Dchar;
+int pflag;
+int iflag;
+int tflag;
+int dcaddrflag;
+const char *tchar;
+
+/* Configuration file parameters: */
+int Hflag;
+const char *Hchar;
+int Cflag;
+const char *Cchar;
+int Fflag;
+const char *tbchar;
+int pgflag;
+const char *bechar;
+const char *cfchar;
+const char *puchar;
+const char *pachar;
+const char *plchar;
+const char *ppchar;
+const char *htchar;
+const char *ftchar;
+int csflag;
+int lrflag;
+int rrflag;
+int clsflag;
+unsigned int stnum;
+unsigned int rsnum;
+unsigned int rsrnum;
+unsigned int epnum;
+unsigned int rpnum;
+
+/* Start and end times: */
+char *sstring;
+char *estring;
+char *tstring;
+time_t sstime;
+time_t eetime;
+int syear;
+int smonth;
+int sday;
+int shour;
+int sminute;
+int ssecond;
+int eyear;
+int emonth;
+int eday;
+int ehour;
+int eminute;
+int esecond;
+
+/* hash table sizes: */
+int asize;
+int rsize;
+char *hsstring;
+char *hastring;
+char *hrstring;
+
+/* Filters */
+char *sef;
+char *ref;
+char *srf;
+char *rrf;
+#ifdef USE_REGEXP
+regex_t csef;
+regex_t cref;
+regex_t csrf;
+regex_t crrf;
+#endif
+
+/* Output file handle: */
+FILE *ofp;
+
+/* total number of hosts: */
+int hosts;
+
+/* inital host structure: */
+struct host first;
+
 int
 main(int argc, char **argv) {
 	FILE *fp = NULL;
