--- cmd/mmctl/commands/utils_unix.go.orig	2024-10-24 13:08:53 UTC
+++ cmd/mmctl/commands/utils_unix.go
@@ -1,8 +1,8 @@
 // Copyright (c) 2015-present Mattermost, Inc. All Rights Reserved.
 // See LICENSE.txt for license information.
 
-//go:build linux || darwin
-// +build linux darwin
+//go:build linux || darwin || freebsd
+// +build linux darwin freebsd
 
 package commands
 
