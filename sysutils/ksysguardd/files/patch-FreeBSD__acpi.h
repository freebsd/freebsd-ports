--- FreeBSD/acpi.h	1970-01-01 02:00:00.000000000 +0200
+++ FreeBSD/acpi.h	2011-01-27 20:56:50.000000000 +0200
@@ -0,0 +1,45 @@
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
+#ifndef _acpi_h_
+#define _acpi_h_
+
+struct SensorModul;
+
+void initACPI(struct SensorModul*);
+void exitACPI(void);
+
+int updateACPI(void);
+
+void printBatCharge(const char*);
+void printBatChargeInfo(const char*);
+void printBatCapacity(const char*);
+void printBatCapacityInfo(const char*);
+void printBatRemaining(const char*);
+void printBatRemainingInfo(const char*);
+void printBatVoltage(const char*);
+void printBatVoltageInfo(const char*);
+void printBatRate(const char*);
+void printBatRateInfo(const char*);
+
+void printThermal(const char *);
+void printThermalInfo(const char *);
+
+#endif /* _acpi_h_ */
