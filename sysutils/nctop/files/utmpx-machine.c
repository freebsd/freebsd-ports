--- machines/freebsd.c
+++ machines/freebsd.c
@@ -16,7 +16,7 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include <sys/types.h>
-#include <utmp.h>
+#include <utmpx.h>
 #include <kvm.h>
 #include <fcntl.h>
 #include <sys/sysctl.h>
@@ -93,7 +93,6 @@
 /* read the state of the machine */
 void getstat (int signal) {
 
-	FILE *stream;
 
 
 	size_t len;
@@ -101,18 +100,15 @@
 	/* nusers */
 	{
 
-	struct utmp utmp;
+	struct utmpx *utmp;
 
-	if ((stream = fopen(_PATH_UTMP,"r")) == NULL) {
-		perror(_PATH_UTMP);
-	} else {
-		for (hoststat.nusers=0; fread(&utmp,sizeof(utmp),1,stream);) {
-			if (utmp.ut_name[0] != '\0') {
-				++hoststat.nusers;
-			}
+	setutxent();
+	for (hoststat.nusers=0; (utmp = getutxent()) != NULL;) {
+		if (utmp->ut_type == USER_PROCESS) {
+			++hoststat.nusers;
 		}
-		fclose(stream);
 	}
+	endutxent();
 	}
 
 		
