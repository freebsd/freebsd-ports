--- qt/qtr.pro.orig	2011-03-17 15:03:37.000000000 -0500
+++ qt/qtr.pro	2011-03-17 15:04:01.000000000 -0500
@@ -21,7 +21,7 @@
 LIBS += $${TRANSMISSION_TOP}/third-party/dht/libdht.a
 LIBS += $${TRANSMISSION_TOP}/third-party/miniupnp/libminiupnp.a
 LIBS += $${TRANSMISSION_TOP}/third-party/libnatpmp/libnatpmp.a
-unix: LIBS += -L$${EVENT_TOP}/lib -levent -lz
+unix: LIBS += -L$${EVENT_TOP}/lib -lz
 win32:DEFINES += QT_DBUS
 win32:LIBS += -levent -lws2_32 -lintl
 win32:LIBS += -lidn -liconv -lwldap32 -liphlpapi
