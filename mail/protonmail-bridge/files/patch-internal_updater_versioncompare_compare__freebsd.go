--- internal/updater/versioncompare/compare_freebsd.go.orig	2026-07-26 08:30:05 UTC
+++ internal/updater/versioncompare/compare_freebsd.go
@@ -0,0 +1,31 @@
+// Copyright (c) 2026 Proton AG
+//
+// This file is part of Proton Mail Bridge.
+//
+// Proton Mail Bridge is free software: you can redistribute it and/or modify
+// it under the terms of the GNU General Public License as published by
+// the Free Software Foundation, either version 3 of the License, or
+// (at your option) any later version.
+//
+// Proton Mail Bridge is distributed in the hope that it will be useful,
+// but WITHOUT ANY WARRANTY; without even the implied warranty of
+// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+// GNU General Public License for more details.
+//
+// You should have received a copy of the GNU General Public License
+// along with Proton Mail Bridge. If not, see <https://www.gnu.org/licenses/>.
+
+//go:build freebsd
+
+package versioncompare
+
+import (
+	"github.com/elastic/go-sysinfo/types"
+	"github.com/sirupsen/logrus"
+)
+
+// IsHostVersionEligible - Checks whether host OS version is eligible for update. Defaults to true on Linux.
+func (sysVer SystemVersion) IsHostVersionEligible(log *logrus.Entry, _ types.Host, _ func(host types.Host) string) (bool, error) {
+	log.Info("Checking host OS version on FreeBSD. Defaulting to false.")
+	return false, nil
+}
