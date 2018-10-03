--- usb/libusb.go.orig	2018-10-01 19:43:54 UTC
+++ usb/libusb.go
@@ -3,6 +3,7 @@ package usb
 import (
 	"encoding/hex"
 	"fmt"
+	"runtime"
 	"strings"
 	"sync"
 	"sync/atomic"
@@ -311,13 +312,21 @@ func (b *LibUSB) matchVidPid(vid uint16,
 }
 
 func (b *LibUSB) identify(dev lowlevel.Device) string {
-	var ports [8]byte
-	p, err := lowlevel.Get_Port_Numbers(dev, ports[:])
-	if err != nil {
-		b.mw.Println(fmt.Sprintf("libusb - identify - error getting port numbers %s", err.Error()))
-		return ""
+	var path string
+	if runtime.GOOS != "freebsd" {
+		var ports [8]byte
+		p, err := lowlevel.Get_Port_Numbers(dev, ports[:])
+		if err != nil {
+			b.mw.Println(fmt.Sprintf("webusb - identify - error getting port numbers %s", err.Error()))
+			return ""
+		}
+		path = hex.EncodeToString(p)
+	} else {
+		bn := lowlevel.Get_Bus_Number(dev)
+		da := lowlevel.Get_Device_Address(dev)
+		path = fmt.Sprintf("%02x%02x", bn, da)
 	}
-	return libusbPrefix + hex.EncodeToString(p)
+	return libusbPrefix + path
 }
 
 type WUD struct {
