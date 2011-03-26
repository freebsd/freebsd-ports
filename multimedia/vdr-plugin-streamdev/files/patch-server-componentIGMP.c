--- server/componentIGMP.c.orig
+++ server/componentIGMP.c
@@ -1,9 +1,24 @@
 /*
  *  $Id: componentIGMP.c,v 1.2 2009/07/03 21:44:19 schmirl Exp $
  */
+#include <sys/types.h>
+#include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/igmp.h>
- 
+
+#ifndef IGMP_MEMBERSHIP_QUERY
+#define IGMP_MEMBERSHIP_QUERY IGMP_HOST_MEMBERSHIP_QUERY
+#endif
+#ifndef IGMP_V1_MEMBERSHIP_REPORT
+#define IGMP_V1_MEMBERSHIP_REPORT IGMP_v1_HOST_MEMBERSHIP_REPORT
+#endif
+#ifndef IGMP_V2_MEMBERSHIP_REPORT
+#define IGMP_V2_MEMBERSHIP_REPORT IGMP_v2_HOST_MEMBERSHIP_REPORT
+#endif
+#ifndef IGMP_V2_LEAVE_GROUP
+#define IGMP_V2_LEAVE_GROUP IGMP_HOST_LEAVE_MESSAGE
+#endif
+
 #include "server/componentIGMP.h"
 #include "server/connectionIGMP.h"
 #include "server/setup.h"
