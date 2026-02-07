--- internal/socket.go.orig	2024-03-26 13:15:17 UTC
+++ internal/socket.go
@@ -2,12 +2,13 @@ package internal
 
 import (
 	"encoding/json"
+	"net/http"
+	"strings"
+
 	"github.com/freswa/dovecot-xaps-daemon/internal/config"
 	"github.com/freswa/dovecot-xaps-daemon/internal/database"
 	"github.com/julienschmidt/httprouter"
 	log "github.com/sirupsen/logrus"
-	"net/http"
-	"strings"
 )
 
 type httpHandler struct {
@@ -147,11 +148,11 @@ func (httpHandler *httpHandler) handleNotify(writer ht
 	}
 
 	// we don't know how to handle other mailboxes other than INBOX, so ignore them
-	if notify.Mailbox != "INBOX" {
-		log.Debugln("Ignoring non INBOX event for:", notify.Mailbox)
-		writer.WriteHeader(http.StatusOK)
-		return
-	}
+	//if notify.Mailbox != "INBOX" {
+	//	log.Debugln("Ignoring non INBOX event for:", notify.Mailbox)
+	//	writer.WriteHeader(http.StatusOK)
+	//	return
+	//}
 
 	// Find all the devices registered for this mailbox event
 	registrations, err := httpHandler.db.FindRegistrations(notify.Username, notify.Mailbox)
@@ -179,7 +180,7 @@ func (httpHandler *httpHandler) handleNotify(writer ht
 	// Send a notification to all registered devices. We ignore failures
 	// because there is not a lot we can do.
 	for _, registration := range registrations {
-		httpHandler.apns.SendNotification(registration, !isMessageNew)
+		httpHandler.apns.SendNotification(registration, !isMessageNew, notify.Mailbox)
 	}
 
 	writer.WriteHeader(http.StatusOK)
