--- usb/webusb.go.orig	2018-09-21 13:31:27 UTC
+++ usb/webusb.go
@@ -274,13 +274,21 @@ func (b *WebUSB) matchVidPid(vid uint16,
 }
 
 func (b *WebUSB) identify(dev lowlevel.Device) string {
-	var ports [8]byte
-	p, err := lowlevel.Get_Port_Numbers(dev, ports[:])
-	if err != nil {
-		b.mw.Println(fmt.Sprintf("webusb - identify - error getting port numbers %s", err.Error()))
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
-	return webusbPrefix + hex.EncodeToString(p)
+	return webusbPrefix + path
 }
 
 type WUD struct {
@@ -331,6 +339,12 @@ func (d *WUD) finishReadQueue() {
 }
 
 func (d *WUD) readWrite(buf []byte, endpoint uint8) (int, error) {
+	var timeout uint
+	if runtime.GOOS != "freebsd" {
+		timeout = usbTimeout
+	} else {
+		timeout = 0
+	}
 	d.mw.Println("webusb - rw - start")
 	for {
 		d.mw.Println("webusb - rw - checking closed")
@@ -343,7 +357,7 @@ func (d *WUD) readWrite(buf []byte, endp
 		d.mw.Println("webusb - rw - lock transfer mutex")
 		d.transferMutex.Lock()
 		d.mw.Println("webusb - rw - actual interrupt transport")
-		p, err := lowlevel.Interrupt_Transfer(d.dev, endpoint, buf, usbTimeout)
+		p, err := lowlevel.Interrupt_Transfer(d.dev, endpoint, buf, timeout)
 		d.transferMutex.Unlock()
 		d.mw.Println("webusb - rw - single transfer done")
 
