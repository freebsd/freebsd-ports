--- libutil/workid.c	Wed Oct 22 09:13:32 2003
+++ workid.c	Fri Jan  2 12:10:23 2004
@@ -1,30 +1,32 @@
 /*$Id: workid.c,v 5.6 2003/10/22 09:13:32 sasa Exp $*/
 
-#include <stdio.h>
+#include <iceb.h>
+#include <fcntl.h>
 #include <stdlib.h>
 #include <string.h>
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h>
 #endif
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
 #include <utmp.h>
 #include <util.h>
 #ifdef	HAVE_UNISTD_H
 #include <unistd.h>
 #endif
+#include <iostream>
+#include <string>
+#include <fstream>
 
-#define DEV_DIR_WITH_TRAILING_SLASH "/dev/"
-#define DEV_DIR_LEN (sizeof (DEV_DIR_WITH_TRAILING_SLASH) - 1)
-
-#ifndef HOST_NAME_MAX
-#define HOST_NAME_MAX 255
-#endif
+using namespace std;
 
 /*
  * Функция workid возвращает указатель на строку, идентифицирующую
  * рабочее место, на котором запущена программа, в формате:
  *
  * хост|удаленный_хост|терминал
- *   |         |            
+ *   |         |
  *   |         +--- откуда зашли telnet'ом
  *   |
  *   +--- на котором запущена программа
@@ -33,33 +35,31 @@
  *
  */
 
-char *workid() {
-   struct utmp *u;
-   char *ttyname_b = NULL;
-   char host[HOST_NAME_MAX];
-   int n = 0;
-   int found = 0;
-   
-   host[0] = '\0';
-   gethostname(host, HOST_NAME_MAX-1);
-   ttyname_b = ttyname (0);
-   if (!ttyname_b)
-      return(NULL);
-   if (strncmp (ttyname_b, DEV_DIR_WITH_TRAILING_SLASH, DEV_DIR_LEN) == 0)
-      ttyname_b += DEV_DIR_LEN;	/* Discard /dev/ prefix.  */
-
-   while (u=getutent())
-      if (u->ut_type == USER_PROCESS ) 
-         if (strcmp(u->ut_line, ttyname_b) == 0) {
-            found++;
-            break;
-         }
-
-   if (found) {
-      found=strlen(host)+1+strlen(u->ut_host)+1+strlen(u->ut_line)+1;
-      ttyname_b = (char*) malloc(found);
-      sprintf(ttyname_b, "%s|%s|%s", host, u->ut_host, u->ut_line);
-   }
-   else ttyname_b = NULL;
-   return(ttyname_b);
+char* workid() {
+	// get host name
+	static const long length = 1024; //sysconf(_SC_HOST_NAME_MAX);
+	char host[length];
+	host[0] = '\0';
+	gethostname(host, length);
+
+	//get term name
+	static const string devPrefix("/dev/");
+	string ttyname(ttyname(0));
+#if (__GNUC__ >= 3)
+	if (ttyname.compare(0, devPrefix.size(), devPrefix) == 0)
+#else
+	if (ttyname.compare(devPrefix, 0, devPrefix.size()) == 0)
+#endif
+		ttyname.erase(0, devPrefix.size());
+
+	// get remote host
+	utmp buff;
+	int fd = open(_PATH_UTMP, O_RDONLY);
+	if (fd != -1) {
+		while (read(fd, &buff, sizeof(buff)) == sizeof(buff))
+			if (ttyname == buff.ut_line && *buff.ut_host != 0)
+				return strdup((string(host) + '/' + buff.ut_host +'/' + ttyname).c_str());
+	}
+
+	return strdup(string().c_str());
 }
