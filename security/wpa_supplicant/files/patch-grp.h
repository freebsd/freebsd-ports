diff -ru work/wpa_supplicant-0.3.0/eap.c work.sav/wpa_supplicant-0.3.0/eap.c
--- work/wpa_supplicant-0.3.0/eap.c	Sun Dec  5 16:28:25 2004
+++ work.sav/wpa_supplicant-0.3.0/eap.c	Sun Dec 12 15:53:27 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_aka.c work.sav/wpa_supplicant-0.3.0/eap_aka.c
--- work/wpa_supplicant-0.3.0/eap_aka.c	Sat Nov 27 10:29:04 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_aka.c	Sun Dec 12 15:51:53 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_gtc.c work.sav/wpa_supplicant-0.3.0/eap_gtc.c
--- work/wpa_supplicant-0.3.0/eap_gtc.c	Sat Nov 27 10:29:04 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_gtc.c	Sun Dec 12 15:50:50 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <netinet/in.h>
 #include <string.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_leap.c work.sav/wpa_supplicant-0.3.0/eap_leap.c
--- work/wpa_supplicant-0.3.0/eap_leap.c	Sat Nov 27 10:29:04 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_leap.c	Sun Dec 12 15:51:40 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_md5.c work.sav/wpa_supplicant-0.3.0/eap_md5.c
--- work/wpa_supplicant-0.3.0/eap_md5.c	Sat Dec  4 08:53:24 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_md5.c	Sun Dec 12 15:50:32 2004
@@ -15,6 +15,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_mschapv2.c work.sav/wpa_supplicant-0.3.0/eap_mschapv2.c
--- work/wpa_supplicant-0.3.0/eap_mschapv2.c	Sun Dec  5 16:28:25 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_mschapv2.c	Sun Dec 12 15:50:42 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_otp.c work.sav/wpa_supplicant-0.3.0/eap_otp.c
--- work/wpa_supplicant-0.3.0/eap_otp.c	Sat Nov 27 10:29:04 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_otp.c	Sun Dec 12 15:51:01 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <netinet/in.h>
 #include <string.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_peap.c work.sav/wpa_supplicant-0.3.0/eap_peap.c
--- work/wpa_supplicant-0.3.0/eap_peap.c	Sun Dec  5 16:28:25 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_peap.c	Sun Dec 12 15:50:15 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_psk.c work.sav/wpa_supplicant-0.3.0/eap_psk.c
--- work/wpa_supplicant-0.3.0/eap_psk.c	Sat Nov 27 10:29:04 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_psk.c	Sun Dec 12 15:51:47 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_sim.c work.sav/wpa_supplicant-0.3.0/eap_sim.c
--- work/wpa_supplicant-0.3.0/eap_sim.c	Sat Nov 27 10:29:04 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_sim.c	Sun Dec 12 15:51:08 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_tls.c work.sav/wpa_supplicant-0.3.0/eap_tls.c
--- work/wpa_supplicant-0.3.0/eap_tls.c	Sat Nov 27 10:29:04 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_tls.c	Sun Dec 12 15:49:28 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_tls_common.c work.sav/wpa_supplicant-0.3.0/eap_tls_common.c
--- work/wpa_supplicant-0.3.0/eap_tls_common.c	Wed Oct  6 21:25:17 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_tls_common.c	Sun Dec 12 15:53:38 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
diff -ru work/wpa_supplicant-0.3.0/eap_ttls.c work.sav/wpa_supplicant-0.3.0/eap_ttls.c
--- work/wpa_supplicant-0.3.0/eap_ttls.c	Sat Nov 27 10:29:04 2004
+++ work.sav/wpa_supplicant-0.3.0/eap_ttls.c	Sun Dec 12 15:50:25 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
