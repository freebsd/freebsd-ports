https://github.com/rconde01/govmomi/commit/f6cd1b1a345750afe81c43a5b00855dd6bf84d8b

From f6cd1b1a345750afe81c43a5b00855dd6bf84d8b Mon Sep 17 00:00:00 2001
From: Rob Conde <Rob.Conde@ai-solutions.com>
Date: Mon, 5 Jul 2021 16:24:31 -0400
Subject: [PATCH] fix: make processing of mac addresses case insensitive

Closes: #2509

--- vendor/github.com/vmware/govmomi/object/virtual_machine.go.orig	2021-08-31 16:00:45 UTC
+++ vendor/github.com/vmware/govmomi/object/virtual_machine.go
@@ -22,6 +22,7 @@ import (
 	"fmt"
 	"net"
 	"path"
+	"strings"
 
 	"github.com/vmware/govmomi/nfc"
 	"github.com/vmware/govmomi/property"
@@ -333,7 +334,9 @@ func (v VirtualMachine) WaitForNetIP(ctx context.Conte
 			devices := VirtualDeviceList(c.Val.(types.ArrayOfVirtualDevice).VirtualDevice)
 			for _, d := range devices {
 				if nic, ok := d.(types.BaseVirtualEthernetCard); ok {
-					mac := nic.GetVirtualEthernetCard().MacAddress
+					// Convert to lower so that e.g. 00:50:56:83:3A:5D is treated the
+					// same as 00:50:56:83:3a:5d
+					mac := strings.ToLower(nic.GetVirtualEthernetCard().MacAddress)
 					if mac == "" {
 						return false
 					}
@@ -369,7 +372,9 @@ func (v VirtualMachine) WaitForNetIP(ctx context.Conte
 
 			nics := c.Val.(types.ArrayOfGuestNicInfo).GuestNicInfo
 			for _, nic := range nics {
-				mac := nic.MacAddress
+				// Convert to lower so that e.g. 00:50:56:83:3A:5D is treated the
+				// same as 00:50:56:83:3a:5d
+				mac := strings.ToLower(nic.MacAddress)
 				if mac == "" || nic.IpConfig == nil {
 					continue
 				}
