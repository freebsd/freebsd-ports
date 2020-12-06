--- pkg/collector/corechecks/system/file_handles.go.orig	2020-05-11 15:38:36 UTC
+++ pkg/collector/corechecks/system/file_handles.go
@@ -3,6 +3,7 @@
 // This product includes software developed at Datadog (https://www.datadoghq.com/).
 // Copyright 2016-2020 Datadog, Inc.
 // +build !windows
+// +build !freebsd
 
 package system
 
