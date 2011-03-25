--- FreeBSD/cpuinfo.h	1970-01-01 02:00:00.000000000 +0200
+++ FreeBSD/cpuinfo.h	2011-01-03 22:13:03.000000000 +0200
@@ -0,0 +1,74 @@
+/*
+    KSysGuard, the KDE System Guard
+
+	Copyright (c) 1999 Chris Schlaeger <cs@kde.org>
+	Copyright (c) 2010 David Naylor <naylor.b.david@gmail.com>
+
+    This program is free software; you can redistribute it and/or modify
+    it under the terms of the GNU General Public License as published by
+    the Free Software Foundation; either version 2 of the License, or
+    (at your option) any later version.
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
+#ifndef _cpuinfo_h_
+#define _cpuinfo_h_
+
+struct SensorModul;
+
+void initCpuInfo(struct SensorModul*);
+void exitCpuInfo(void);
+
+int updateCpuInfo(void);
+
+void printCPUUser(const char* cmd);
+void printCPUUserInfo(const char* cmd);
+void printCPUNice(const char* cmd);
+void printCPUNiceInfo(const char* cmd);
+void printCPUSys(const char* cmd);
+void printCPUSysInfo(const char* cmd);
+void printCPUTotalLoad(const char* cmd);
+void printCPUTotalLoadInfo(const char* cmd);
+void printCPUIntr(const char* cmd);
+void printCPUIntrInfo(const char* cmd);
+void printCPUIdle(const char* cmd);
+void printCPUIdleInfo(const char* cmd);
+void printCPUxUser(const char* cmd);
+void printCPUxUserInfo(const char* cmd);
+void printCPUxNice(const char* cmd);
+void printCPUxNiceInfo(const char* cmd);
+void printCPUxSys(const char* cmd);
+void printCPUxSysInfo(const char* cmd);
+void printCPUxTotalLoad(const char* cmd);
+void printCPUxTotalLoadInfo(const char* cmd);
+void printCPUxIntr(const char* cmd);
+void printCPUxIntrInfo(const char* cmd);
+void printCPUxIdle(const char* cmd);
+void printCPUxIdleInfo(const char* cmd);
+
+void printCPUxClock(const char* cmd);
+void printCPUxClockInfo(const char* cmd);
+void printCPUClock(const char* cmd);
+void printCPUClockInfo(const char* cmd);
+
+void printCPUxTemperature(const char* cmd);
+void printCPUxTemperatureInfo(const char* cmd);
+void printCPUTemperature(const char* cmd);
+void printCPUTemperatureInfo(const char* cmd);
+
+void printNumCpus(const char* cmd);
+void printNumCpusInfo(const char* cmd);
+
+void printNumCores(const char* cmd);
+void printNumCoresInfo(const char* cmd);
+
+#endif /* _cpuinfo_h_ */
