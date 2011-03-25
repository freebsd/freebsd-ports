--- FreeBSD/uptime.h	1970-01-01 02:00:00.000000000 +0200
+++ FreeBSD/uptime.h	2010-11-04 14:09:30.000000000 +0200
@@ -0,0 +1,33 @@
+/*
+    KSysGuard, the KDE System Guard
+
+    Copyright (c) 2006 Greg Martyn <greg.martyn@gmail.com>
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
+#ifndef _uptime_h_
+#define _uptime_h_
+
+struct SensorModul;
+
+void initUptime( struct SensorModul* );
+void exitUptime( void );
+
+void printUptime( const char* cmd );
+void printUptimeInfo( const char* cmd );
+
+#endif
