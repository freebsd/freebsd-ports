--- internal/apns.go.orig	2024-03-26 13:15:17 UTC
+++ internal/apns.go
@@ -1,18 +1,21 @@
 package internal
 
 import (
+	"crypto/md5"
 	"crypto/tls"
 	"crypto/x509"
+	"encoding/hex"
 	"errors"
+	"net/http"
+	"sync"
+	"time"
+
 	"github.com/freswa/dovecot-xaps-daemon/internal/config"
 	"github.com/freswa/dovecot-xaps-daemon/internal/database"
 	"github.com/freswa/dovecot-xaps-daemon/pkg/apple_xserver_certs"
 	"github.com/sideshow/apns2"
 	log "github.com/sirupsen/logrus"
 	"golang.org/x/net/http2"
-	"net/http"
-	"sync"
-	"time"
 )
 
 const (
@@ -135,11 +138,11 @@ func (apns *Apns) checkDelayed() {
 	}
 	apns.mapMutex.Unlock()
 	for _, reg := range sendNow {
-		apns.SendNotification(reg, false)
+		apns.SendNotification(reg, false, "")
 	}
 }
 
-func (apns *Apns) SendNotification(registration database.Registration, delayed bool) {
+func (apns *Apns) SendNotification(registration database.Registration, delayed bool, mailbox string) {
 	apns.mapMutex.Lock()
 	if delayed {
 		apns.delayedApns[registration] = time.Now()
@@ -149,6 +152,7 @@ func (apns *Apns) SendNotification(registration databa
 		delete(apns.delayedApns, registration)
 		apns.mapMutex.Unlock()
 	}
+
 	log.Debugln("Sending notification to", registration.AccountId, "/", registration.DeviceToken)
 
 	notification := &apns2.Notification{}
@@ -156,6 +160,13 @@ func (apns *Apns) SendNotification(registration databa
 	notification.Topic = apns.Topic
 	composedPayload := []byte(`{"aps":{`)
 	composedPayload = append(composedPayload, []byte(`"account-id":"`+registration.AccountId+`"`)...)
+
+	if mailbox != "" {
+		hash := md5.Sum([]byte(mailbox))
+		mailbox_hash := hex.EncodeToString(hash[:])
+		composedPayload = append(composedPayload, []byte(`, "m":"`+mailbox_hash+`"`)...)
+	}
+
 	composedPayload = append(composedPayload, []byte(`}}`)...)
 	notification.Payload = composedPayload
 	notification.Expiration = time.Now().Add(24 * time.Hour)
