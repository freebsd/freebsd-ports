--- eap.c	Sun Dec  5 16:28:25 2004
+++ eap.c	Sun Dec 12 15:53:27 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_aka.c	Sat Nov 27 10:29:04 2004
+++ eap_aka.c	Sun Dec 12 15:51:53 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_gtc.c	Sat Nov 27 10:29:04 2004
+++ eap_gtc.c	Sun Dec 12 15:50:50 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <netinet/in.h>
 #include <string.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_leap.c	Sat Nov 27 10:29:04 2004
+++ eap_leap.c	Sun Dec 12 15:51:40 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_md5.c	Sat Dec  4 08:53:24 2004
+++ eap_md5.c	Sun Dec 12 15:50:32 2004
@@ -15,6 +15,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_mschapv2.c	Sun Dec  5 16:28:25 2004
+++ eap_mschapv2.c	Sun Dec 12 15:50:42 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_otp.c	Sat Nov 27 10:29:04 2004
+++ eap_otp.c	Sun Dec 12 15:51:01 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <netinet/in.h>
 #include <string.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_peap.c	Sun Dec  5 16:28:25 2004
+++ eap_peap.c	Sun Dec 12 15:50:15 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_psk.c	Sat Nov 27 10:29:04 2004
+++ eap_psk.c	Sun Dec 12 15:51:47 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_sim.c	Sat Nov 27 10:29:04 2004
+++ eap_sim.c	Sun Dec 12 15:51:08 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_tls.c	Sat Nov 27 10:29:04 2004
+++ eap_tls.c	Sun Dec 12 15:49:28 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_tls_common.c	Wed Oct  6 21:25:17 2004
+++ eap_tls_common.c	Sun Dec 12 15:53:38 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
--- eap_ttls.c	Sat Nov 27 10:29:04 2004
+++ eap_ttls.c	Sun Dec 12 15:50:25 2004
@@ -16,6 +16,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <netinet/in.h>
+#include <grp.h>
 
 #include "common.h"
 #include "eap_i.h"
