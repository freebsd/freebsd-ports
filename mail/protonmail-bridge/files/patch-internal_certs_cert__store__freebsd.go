--- internal/certs/cert_store_freebsd.go.orig	2026-07-26 08:25:11 UTC
+++ internal/certs/cert_store_freebsd.go
@@ -0,0 +1,34 @@
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
+package certs
+
+func osSupportCertInstall() bool {
+	return false
+}
+
+func installCert([]byte) error {
+	return nil // Linux doesn't have a root cert store.
+}
+
+func uninstallCert([]byte) error {
+	return nil // Linux doesn't have a root cert store.
+}
+
+func isCertInstalled([]byte) bool {
+	return false
+}
