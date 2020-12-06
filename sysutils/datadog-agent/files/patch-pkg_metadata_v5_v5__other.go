--- pkg/metadata/v5/v5_other.go.orig	2020-01-31 19:24:57 UTC
+++ pkg/metadata/v5/v5_other.go
@@ -10,13 +10,14 @@ package v5
 import (
 	"github.com/DataDog/datadog-agent/pkg/metadata/common"
 	"github.com/DataDog/datadog-agent/pkg/metadata/host"
+	"github.com/DataDog/datadog-agent/pkg/util"
 )
 
 // GetPayload returns the complete metadata payload as seen in Agent v5.
 // Note: gohai can't be used on the platforms this module builds for
-func GetPayload(hostname string) *Payload {
-	cp := common.GetPayload(hostname)
-	hp := host.GetPayload(hostname)
+func GetPayload(hostnameData util.HostnameData) *Payload {
+	cp := common.GetPayload(hostnameData.Hostname)
+	hp := host.GetPayload(hostnameData)
 
 	return &Payload{
 		CommonPayload: CommonPayload{*cp},
