--- misc.cc	2004-05-29 16:00:05.000000000 -0700
+++ misc.cc	2008-03-02 22:53:40.000000000 -0800
@@ -186,7 +186,7 @@
 //	return timestr;
 }
 
-char *text_month[13]={"Jan", "Feb", "Mar", "Apr",
+const char *text_month[13]={"Jan", "Feb", "Mar", "Apr",
 	"May", "Jun", "Jul", "Aug",
 	"Sep", "Oct", "Nov", "Dec"
 };
@@ -251,7 +251,7 @@
 time_t decode_textdate(const char * cbuf, bool local){
 	struct tm tblock;
 	memset(&tblock,0,sizeof(struct tm));
-	char *tdt=NULL;
+	const char *tdt=NULL;
 	int td_tz=local?0x7FFFFFFF:0;
 	int yearlen=0;
 	c_regex_subs rsubs;
