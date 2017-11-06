Avoid build error with recent clang on FreeBSD 12-CURRENT.

CC              src/main.o
In file included from src/main.c:51:
In file included from
/usr/ports/multimedia/tvheadend/work/tvheadend-4.2.2/src/dvr/dvr.h:27:
/usr/local/include/profile.h:24:28: error: typedef redefinition with
different types ('struct _profile_t *' vs
      'struct profile')
typedef struct _profile_t *profile_t;
                           ^
/usr/ports/multimedia/tvheadend/work/tvheadend-4.2.2/src/profile.h:148:3:
note: previous definition is here
} profile_t;
  ^
In file included from src/main.c:51:
In file included from
/usr/ports/multimedia/tvheadend/work/tvheadend-4.2.2/src/dvr/dvr.h:27:
/usr/local/include/profile.h:45:20: error: conflicting types for
'profile_init'
long KRB5_CALLCONV profile_init
                   ^
/usr/ports/multimedia/tvheadend/work/tvheadend-4.2.2/src/profile.h:197:6:
note: previous declaration is here
void profile_init(void);
     ^
In file included from src/main.c:51:
In file included from
/usr/ports/multimedia/tvheadend/work/tvheadend-4.2.2/src/dvr/dvr.h:27:
/usr/local/include/profile.h:71:20: error: conflicting types for
'profile_release'
void KRB5_CALLCONV profile_release
                   ^
/usr/ports/multimedia/tvheadend/work/tvheadend-4.2.2/src/profile.h:159:20:
note: previous definition is here
static inline void profile_release( profile_t *pro )
                   ^
3 errors generated.
gmake[2]: *** [Makefile:631:
/usr/ports/multimedia/tvheadend/work/tvheadend-4.2.2/build.freebsd/src/main.o]
Error 1
gmake[2]: Leaving directory

Reported by:	Rainer Hurling <rhurlin@gwdg.de>
--- src/main.c.orig	2017-07-01 07:22:23.000000000 +0000
+++ src/main.c	2017-08-23 15:27:26.427162000 +0000
@@ -48,6 +48,7 @@
 #include "subscriptions.h"
 #include "service_mapper.h"
 #include "descrambler.h"
+#include "profile.h"
 #include "dvr/dvr.h"
 #include "htsp_server.h"
 #include "satip/server.h"
@@ -68,7 +69,6 @@
 #include "intlconv.h"
 #include "dbus.h"
 #include "libav.h"
-#include "profile.h"
 #include "bouquet.h"
 #include "tvhtime.h"
 #include "packet.h"
