--- nget.cc	2005/01/03 22:04:44	1.135
+++ nget.cc	2008/03/03 06:53:40	1.136
@@ -93,8 +93,8 @@
 
 struct opt_help {
 	int namelen;
-	char *arg;
-	char *desc;
+	const char *arg;
+	const char *desc;
 };
 static opt_help ohelp[NUM_OPTIONS+1];
 static int olongestlen=0;
@@ -114,7 +114,7 @@
 	OPT_MIN_SHORTNAME //sentinel, must be last element.
 };
 
-static void addoption(char *longo,int needarg,char shorto,char *adesc,char *desc){
+static void addoption(const char *longo,int needarg,char shorto,const char *adesc,const char *desc){
 	static int cur=0;
 	assert(cur<NUM_OPTIONS);
 #ifdef HAVE_LIBPOPT
