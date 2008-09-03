--- src/tools/hunspell.cxx	2008-08-15 06:06:33.000000000 -0400
+++ src/tools/hunspell.cxx	2008-08-26 06:24:36.000000000 -0400
@@ -70,18 +70,12 @@
     ".openoffice.org2/user/wordbook:" \
     ".openoffice.org2.0/user/wordbook"
 #define OOODIR \
-    "/opt/openoffice.org/basis3.0/share/dict/ooo:" \
-    "/usr/lib/openoffice.org/basis3.0/share/dict/ooo:" \
-    "/opt/openoffice.org2.4/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.4/share/dict/ooo:" \
-    "/opt/openoffice.org2.3/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.3/share/dict/ooo:" \
-    "/opt/openoffice.org2.2/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.2/share/dict/ooo:" \
-    "/opt/openoffice.org2.1/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.1/share/dict/ooo:" \
-    "/opt/openoffice.org2.0/share/dict/ooo:" \
-    "/usr/lib/openoffice.org2.0/share/dict/ooo"
+	"%%PREFIX%%/openoffice.org-DEV300_m29/share/dict/ooo:"	\
+	"%%PREFIX%%/openoffice.org-3.0.0.b2/share/dict/ooo:"	\
+	"%%PREFIX%%/openoffice.org-2.4/share/dict/ooo:"	\
+	"%%PREFIX%%/openoffice.org-2.2/share/dict/ooo:"	\
+	"%%PREFIX%%/openoffice.org-2.1/share/dict/ooo:"	\
+	"%%PREFIX%%/openoffice.org2.0/share/dict/ooo"
 #define HOME getenv("HOME")
 #define DICBASENAME ".hunspell_"
 #define LOGFILE "/tmp/hunspell.log"
