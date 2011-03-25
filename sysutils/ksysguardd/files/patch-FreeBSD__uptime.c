--- FreeBSD/uptime.c	1970-01-01 02:00:00.000000000 +0200
+++ FreeBSD/uptime.c	2010-11-08 19:07:02.000000000 +0200
@@ -0,0 +1,48 @@
+/*
+    KSysGuard, the KDE System Guard
+
+    Copyright (c) 2010 David Naylor <naylor.b.david@gmail.com>
+
+    This program is free software; you can redistribute it and/or
+    modify it under the terms of version 2 or later of the GNU General Public
+    License as published by the Free Software Foundation.
+
+    This program is distributed in the hope that it will be useful,
+    but WITHOUT ANY WARRANTY; without even the implied warranty of
+    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+    GNU General Public License for more details.
+
+    You should have received a copy of the GNU General Public License
+    along with this program; if not, write to the Free Software
+    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
+
+*/
+
+#include <stdio.h>
+#include <time.h>
+
+#include "Command.h"
+#include "ksysguardd.h"
+
+#include "uptime.h"
+
+void initUptime( struct SensorModul* sm ) {
+	registerMonitor( "system/uptime", "float", printUptime, printUptimeInfo, sm );
+}
+
+void exitUptime( void ) {
+	removeMonitor("system/uptime");
+}
+
+void printUptime( const char* cmd ) {
+	struct timespec tp;
+	float uptime = 0.;
+	
+	if (clock_gettime(CLOCK_UPTIME, &tp) != -1)
+		uptime = tp.tv_nsec / 1000000000.0 + tp.tv_sec;
+	fprintf( CurrentClient, "%f\n", uptime);
+}
+
+void printUptimeInfo( const char* cmd ) {
+	fprintf( CurrentClient, "System uptime\t0\t0\ts\n" );
+}
