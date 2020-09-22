--- mdnsd/mdns.h.orig	2017-03-10 09:24:12 UTC
+++ mdnsd/mdns.h
@@ -31,6 +31,41 @@
 #include <event.h>
 #include <string.h>
 
+#ifndef T_NSEC
+#define	T_NSEC			47  /* from OpenBSD */
+#endif
+
+#ifndef IFT_CARP
+#define	IFT_CARP		0xf8 /* from DragonFly and NetBSD */
+#endif
+
+#ifndef LINK_STATE_IS_UP /* from DragonFly and OpenBSD */
+#define	LINK_STATE_IS_UP(_s)	((_s) >= LINK_STATE_UP)
+#endif
+
+#ifndef LIST_FOREACH_SAFE /* DragonFly */
+#define	LIST_FOREACH_SAFE	LIST_FOREACH_MUTABLE
+#endif
+
+/* Copied from <sys/time.h> on OpenBSD */
+#ifndef timespeccmp
+#define	timespeccmp(tsp, usp, cmp)					\
+	(((tsp)->tv_sec == (usp)->tv_sec) ?				\
+	    ((tsp)->tv_nsec cmp (usp)->tv_nsec) :			\
+	    ((tsp)->tv_sec cmp (usp)->tv_sec))
+#endif
+#ifndef timespecsub
+#define	timespecsub(tsp, usp, vsp)					\
+	do {								\
+		(vsp)->tv_sec = (tsp)->tv_sec - (usp)->tv_sec;		\
+		(vsp)->tv_nsec = (tsp)->tv_nsec - (usp)->tv_nsec;	\
+		if ((vsp)->tv_nsec < 0) {				\
+			(vsp)->tv_sec--;				\
+			(vsp)->tv_nsec += 1000000000L;			\
+		}							\
+	} while (0)
+#endif
+
 #define MAXCHARSTR	MAXHOSTNAMELEN
 #define MAXLABELLEN	64
 #define MAXPROTOLEN	4
