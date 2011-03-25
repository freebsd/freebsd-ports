--- FreeBSD/acpi.c	1970-01-01 02:00:00.000000000 +0200
+++ FreeBSD/acpi.c	2011-01-30 10:28:18.000000000 +0200
@@ -0,0 +1,241 @@
+/*
+	KSysGuard, the KDE System Guard
+	
+	Copyright (c) 2011 David Naylor <naylor.b.david@gmail.com>
+	
+	This program is free software; you can redistribute it and/or
+	modify it under the terms of version 2 of the GNU General Public
+	License as published by the Free Software Foundation.
+	
+	This program is distributed in the hope that it will be useful,
+	but WITHOUT ANY WARRANTY; without even the implied warranty of
+	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+	GNU General Public License for more details.
+	
+	You should have received a copy of the GNU General Public License
+	along with this program; if not, write to the Free Software
+	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
+*/
+
+/*
+ * TODO
+ * - battery
+ * - fan
+ */
+
+#include "acpi.h"
+
+#include <fcntl.h>
+#include <stdio.h>
+#include <sys/ioctl.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+#include <unistd.h>
+
+#include <dev/acpica/acpiio.h>
+
+#include "Command.h"
+
+#define BUF_LEN 80
+
+#define MAXTZ 6
+#define TZ_MIB "hw.acpi.thermal.tz%i.temperature"
+#define TZ_MIB_LEN 32
+#define TZ_MONITOR "acpi/thermal_zone/temp%i"
+
+#define MAXBAT 6
+#define BAT_CHARGE_MONITOR "acpi/battery/batt%i/batterycharge"
+#define BAT_CAPACITY_MONITOR "acpi/battery/batt%i/batterycapacity"
+#define BAT_REMAINING_MONITOR "acpi/battery/batt%i/remainingtime"
+#define BAT_VOLTAGE_MONITOR "acpi/battery/batt%i/batteryvoltage"
+#define BAT_RATE_MONITOR "acpi/battery/batt%i/batteryrate"
+#define BAT_UNIT(bat) (bat_bif[bat].bif.units ? "mA" : "mW")
+
+static int acpifd = -1;
+
+static int tz_temp[MAXTZ];
+static int tz_cnt;
+
+static int bat_cnt;
+static union acpi_battery_ioctl_arg bat_bif[MAXBAT], bat_bst[MAXBAT], bat_battinfo[MAXBAT];
+
+void initACPI(struct SensorModul *sm) {
+	char name[BUF_LEN];
+	size_t len;
+
+	/* Assume thermal zones use hw.acpi.thermal.tz%i.temperature format */
+	for (tz_cnt = 0; tz_cnt < MAXTZ; ++tz_cnt) {
+		len = sizeof(int);
+		snprintf(name, TZ_MIB_LEN, TZ_MIB, tz_cnt);
+		if (sysctlbyname(name, &tz_temp[tz_cnt], &len, NULL, 0))
+			break;
+		else {
+			snprintf(name, BUF_LEN, TZ_MONITOR, tz_cnt + 1);
+			registerMonitor(name, "float", printThermal, printThermalInfo, sm);
+		}
+	}
+
+	if ((acpifd = open("/dev/acpi", O_RDONLY)) == -1) {
+		log_error("unable to open /dev/acpi");
+		return;
+	}
+
+	for (bat_cnt = 0; bat_cnt < MAXBAT; ++bat_cnt) {
+		bat_bif[bat_cnt].unit = bat_cnt;
+		if (ioctl(acpifd, ACPIIO_BATT_GET_BIF, &bat_bif[bat_cnt]))
+			break;
+		else {
+			snprintf(name, BUF_LEN, BAT_CHARGE_MONITOR, bat_cnt + 1);
+			registerMonitor(name, "integer", printBatCharge, printBatChargeInfo, sm);
+			snprintf(name, BUF_LEN, BAT_CAPACITY_MONITOR, bat_cnt + 1);
+			registerMonitor(name, "integer", printBatCapacity, printBatCapacityInfo, sm);
+			snprintf(name, BUF_LEN, BAT_REMAINING_MONITOR, bat_cnt + 1);
+			registerMonitor(name, "integer", printBatRemaining, printBatRemainingInfo, sm);
+			snprintf(name, BUF_LEN, BAT_VOLTAGE_MONITOR, bat_cnt + 1);
+			registerMonitor(name, "integer", printBatVoltage, printBatVoltageInfo, sm);
+			snprintf(name, BUF_LEN, BAT_RATE_MONITOR, bat_cnt + 1);
+			registerMonitor(name, "integer", printBatRate, printBatRateInfo, sm);
+		}
+	}
+}
+
+void exitACPI(void) {
+	int bat, tz;
+	char name[BUF_LEN];
+
+	for (tz = 0; tz < tz_cnt; ++tz) {
+		snprintf(name, BUF_LEN, TZ_MONITOR, tz + 1);
+		removeMonitor(name);
+	}
+
+	if (acpifd != -1) {
+		for (bat = 0; bat < bat_cnt; ++bat) {
+			snprintf(name, TZ_MIB_LEN, BAT_CHARGE_MONITOR, bat + 1);
+			removeMonitor(name);
+			snprintf(name, BUF_LEN, BAT_CAPACITY_MONITOR, bat + 1);
+			removeMonitor(name);
+			snprintf(name, BUF_LEN, BAT_REMAINING_MONITOR, bat + 1);
+			removeMonitor(name);
+			snprintf(name, BUF_LEN, BAT_VOLTAGE_MONITOR, bat + 1);
+			removeMonitor(name);
+			
+		}
+
+		close(acpifd);
+		acpifd = -1;
+	}
+}
+
+int updateACPI(void) {
+	int bat, tz;
+	char name[TZ_MIB_LEN];
+	size_t len;
+
+	for (tz = 0; tz < tz_cnt; ++tz) {
+		len = sizeof(int);
+		snprintf(name, TZ_MIB_LEN, TZ_MIB, tz);
+		sysctlbyname(name, &tz_temp[tz], &len, NULL, 0);
+	}
+
+	for (bat = 0; bat < bat_cnt; ++bat) {
+		bat_bst[bat].unit = bat;
+		ioctl(acpifd, ACPIIO_BATT_GET_BST, &bat_bst[bat]);
+		bat_battinfo[bat].unit = bat;
+		ioctl(acpifd, ACPIIO_BATT_GET_BATTINFO, &bat_battinfo[bat]);
+	}
+
+	return (0);
+}
+
+void printThermal(const char *cmd) {
+	int tz;
+
+	sscanf(cmd + 22, "%i", &tz);
+	fprintf(CurrentClient, "%f\n", (tz_temp[tz - 1] - 2732) / 10.0);
+}
+
+void printThermalInfo(const char *cmd) {
+	int tz;
+
+	sscanf(cmd + 22, "%i", &tz);
+	fprintf(CurrentClient, "ACPI Thermal Zone %i\t0\t0\tC\n", tz);
+}
+
+/*
+void printBat(const char *cmd) {
+	int bat;
+
+	sscanf(cmd + 17, "%i", &bat);
+	fprintf(CurrentClient, "");
+}
+*/
+
+void printBatCharge(const char *cmd) {
+	int bat;
+
+	sscanf(cmd + 17, "%i", &bat);
+	fprintf(CurrentClient, "%i\n", bat_bst[bat - 1].bst.cap);
+}
+
+void printBatChargeInfo(const char *cmd) {
+	int bat;
+
+	sscanf(cmd + 17, "%i", &bat);
+	fprintf(CurrentClient, "Battery %i charge\t0\t%i\t%sh\n", bat, bat_bif[bat - 1].bif.dcap, BAT_UNIT(bat - 1));
+}
+
+void printBatCapacity(const char *cmd) {
+	int bat;
+
+	sscanf(cmd + 17, "%i", &bat);
+	fprintf(CurrentClient, "%i\n", bat_battinfo[bat - 1].battinfo.cap);
+}
+
+void printBatCapacityInfo(const char *cmd) {
+	int bat;
+
+	sscanf(cmd + 17, "%i", &bat);
+	fprintf(CurrentClient, "Battery %i capacity\t0\t100\t%%\n", bat);
+}
+
+void printBatRemaining(const char *cmd) {
+	int bat;
+
+	sscanf(cmd + 17, "%i", &bat);
+	fprintf(CurrentClient, "%i\n", bat_battinfo[bat - 1].battinfo.min);
+}
+
+void printBatRemainingInfo(const char *cmd) {
+	int bat;
+
+	sscanf(cmd + 17, "%i", &bat);
+	fprintf(CurrentClient, "Battery %i remaining time\t0\t0\tmin\n", bat);
+}
+
+void printBatVoltage(const char *cmd) {
+	int bat;
+
+	sscanf(cmd + 17, "%i", &bat);
+	fprintf(CurrentClient, "%i\n", bat_bst[bat - 1].bst.volt);
+}
+
+void printBatVoltageInfo(const char *cmd) {
+	int bat;
+
+	sscanf(cmd + 17, "%i", &bat);
+	fprintf(CurrentClient, "Battery %i voltage\t0\t%i\tmV\n", bat, bat_bif[bat - 1].bif.dvol);
+}
+
+void printBatRate(const char *cmd) {
+	int bat;
+
+	sscanf(cmd + 17, "%i", &bat);
+	fprintf(CurrentClient, "%i\n", bat_bst[bat - 1].bst.rate);
+}
+
+void printBatRateInfo(const char *cmd) {
+	int bat;
+
+	sscanf(cmd + 17, "%i", &bat);
+	fprintf(CurrentClient, "Battery %i discharge rate\t0\t0\t%s\n", bat, BAT_UNIT(bat - 1));
+}
