--- FreeBSD/stat.h	1970-01-01 02:00:00.000000000 +0200
+++ FreeBSD/stat.h	2011-01-04 13:29:11.000000000 +0200
@@ -0,0 +1,49 @@
+/*
+    KSysGuard, the KDE System Guard
+
+    Copyright (c) 2011 David Naylor <naylor.b.david@gmail.com>
+
+    This program is free software; you can redistribute it and/or
+    modify it under the terms of version 2 of the GNU General Public
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
+#ifndef _stat_h_
+#define _stat_h_
+
+struct SensorModul;
+
+void initStat(struct SensorModul*);
+void exitStat(void);
+
+int updateStat(void);
+
+void printHardInt(const char *);
+void printHardIntInfo(const char *);
+
+void printSoftInt(const char *);
+void printSoftIntInfo(const char *);
+
+void printInterruptx(const char*);
+void printInterruptxInfo(const char*);
+
+void printContext(const char*);
+void printContextInfo(const char*);
+
+void printTrap(const char*);
+void printTrapInfo(const char*);
+
+void printSyscall(const char*);
+void printSyscallInfo(const char*);
+
+#endif /* _stat_h_ */
