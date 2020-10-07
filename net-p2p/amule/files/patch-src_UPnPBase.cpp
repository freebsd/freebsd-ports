--- src/UPnPBase.cpp.orig	2016-09-16 09:55:07.000000000 +0200
+++ src/UPnPBase.cpp	2020-10-07 09:01:15.821714000 +0200
@@ -823,14 +823,18 @@
 	s_CtrlPoint = this;
 	// Null string at first
 	std::ostringstream msg;
-
+	
+	// Declare those here to avoid 
+	// "jump to label ‘error’ [-fpermissive] crosses initialization
+	// of ‘char* ipAddress’"
+	unsigned short port;
+	char *ipAddress;
+	
 	// Start UPnP
 	int ret;
-	char *ipAddress = NULL;
-	unsigned short port = 0;
-	ret = UpnpInit(ipAddress, udpPort);
+	ret = UpnpInit2(0, udpPort);
 	if (ret != UPNP_E_SUCCESS) {
-		msg << "error(UpnpInit): Error code ";
+		msg << "error(UpnpInit2): Error code ";
 		goto error;
 	}
 	port = UpnpGetServerPort();
@@ -1127,7 +1131,11 @@
 
 
 // This function is static
+#if UPNP_VERSION >= 10800
+int CUPnPControlPoint::Callback(Upnp_EventType_e EventType, const void *Event, void * /*Cookie*/)
+#else
 int CUPnPControlPoint::Callback(Upnp_EventType EventType, void *Event, void * /*Cookie*/)
+#endif
 {
 	std::ostringstream msg;
 	std::ostringstream msg2;
@@ -1149,24 +1157,47 @@
 		msg2<< "UPNP_DISCOVERY_SEARCH_RESULT: ";
 		// UPnP Discovery
 upnpDiscovery:
+#if UPNP_VERSION >= 10800
+		 UpnpDiscovery *d_event = (UpnpDiscovery *)Event;
+#else
 		struct Upnp_Discovery *d_event = (struct Upnp_Discovery *)Event;
+#endif
 		IXML_Document *doc = NULL;
+#if UPNP_VERSION >= 10800
+		int errCode = UpnpDiscovery_get_ErrCode(d_event);
+		if (errCode != UPNP_E_SUCCESS) {
+			msg << UpnpGetErrorMessage(errCode) << ".";
+#else
 		int ret;
 		if (d_event->ErrCode != UPNP_E_SUCCESS) {
 			msg << UpnpGetErrorMessage(d_event->ErrCode) << ".";
+#endif
 			AddDebugLogLineC(logUPnP, msg);
 		}
 		// Get the XML tree device description in doc
+#if UPNP_VERSION >= 10800
+		const char *location = UpnpDiscovery_get_Location_cstr(d_event);
+		int ret = UpnpDownloadXmlDoc(location, &doc);
+#else
 		ret = UpnpDownloadXmlDoc(d_event->Location, &doc);
+#endif
 		if (ret != UPNP_E_SUCCESS) {
 			msg << "Error retrieving device description from " <<
+#if UPNP_VERSION >= 10800
+				location << ": " <<
+#else
 				d_event->Location << ": " <<
+#endif
 				UpnpGetErrorMessage(ret) <<
 				"(" << ret << ").";
 			AddDebugLogLineC(logUPnP, msg);
 		} else {
 			msg2 << "Retrieving device description from " <<
+#if UPNP_VERSION >= 10800
+				location << ".";
+#else
 				d_event->Location << ".";
+#endif
 			AddDebugLogLineN(logUPnP, msg2);
 		}
 		if (doc) {
@@ -1194,8 +1225,14 @@
 					AddDebugLogLineC(logUPnP, msg);
 				}
 				// Add the root device to our list
+#if UPNP_VERSION >= 10800
+				int expires = UpnpDiscovery_get_Expires(d_event);
 				upnpCP->AddRootDevice(rootDevice, urlBase,
+					location, expires);
+#else
+				upnpCP->AddRootDevice(rootDevice, urlBase,
 					d_event->Location, d_event->Expires);
+#endif
 			}
 			// Free the XML doc tree
 			IXML::Document::Free(doc);
@@ -1216,28 +1253,60 @@
 	case UPNP_DISCOVERY_ADVERTISEMENT_BYEBYE: {
 		//fprintf(stderr, "Callback: UPNP_DISCOVERY_ADVERTISEMENT_BYEBYE\n");
 		// UPnP Device Removed
+#if UPNP_VERSION >= 10800
+		UpnpDiscovery *dab_event = (UpnpDiscovery *)Event;
+		int errCode = UpnpDiscovery_get_ErrCode(dab_event);
+		if (errCode != UPNP_E_SUCCESS) {
+#else
 		struct Upnp_Discovery *dab_event = (struct Upnp_Discovery *)Event;
 		if (dab_event->ErrCode != UPNP_E_SUCCESS) {
+#endif
 			msg << "error(UPNP_DISCOVERY_ADVERTISEMENT_BYEBYE): " <<
+#if UPNP_VERSION >= 10800
+				UpnpGetErrorMessage(errCode) <<
+#else
 				UpnpGetErrorMessage(dab_event->ErrCode) <<
+#endif
 				".";
 			AddDebugLogLineC(logUPnP, msg);
 		}
+#if UPNP_VERSION >= 10800
+		std::string devType = UpnpDiscovery_get_DeviceType_cstr(dab_event);
+#else
 		std::string devType = dab_event->DeviceType;
+#endif
 		// Check for an InternetGatewayDevice and removes it from the list
 		std::transform(devType.begin(), devType.end(), devType.begin(), tolower);
 		if (stdStringIsEqualCI(devType, UPnP::Device::IGW)) {
+#if UPNP_VERSION >= 10800
+ 			const char *deviceID =
+ 				UpnpDiscovery_get_DeviceID_cstr(dab_event);
+			upnpCP->RemoveRootDevice(deviceID);
+#else
 			upnpCP->RemoveRootDevice(dab_event->DeviceId);
+#endif
 		}
 		break;
 	}
 	case UPNP_EVENT_RECEIVED: {
 		//fprintf(stderr, "Callback: UPNP_EVENT_RECEIVED\n");
 		// Event reveived
+#if UPNP_VERSION >= 10800
+		UpnpEvent *e_event = (UpnpEvent *)Event;
+		int eventKey = UpnpEvent_get_EventKey(e_event);
+		IXML_Document *changedVariables =
+			UpnpEvent_get_ChangedVariables(e_event);
+		const std::string sid = UpnpEvent_get_SID_cstr(e_event);
+#else
 		struct Upnp_Event *e_event = (struct Upnp_Event *)Event;
 		const std::string Sid = e_event->Sid;
+#endif
 		// Parses the event
+#if UPNP_VERSION >= 10800
+		upnpCP->OnEventReceived(sid, eventKey, changedVariables);
+#else
 		upnpCP->OnEventReceived(Sid, e_event->EventKey, e_event->ChangedVariables);
+#endif
 		break;
 	}
 	case UPNP_EVENT_SUBSCRIBE_COMPLETE:
@@ -1252,19 +1321,39 @@
 		//fprintf(stderr, "Callback: UPNP_EVENT_RENEWAL_COMPLETE\n");
 		msg << "error(UPNP_EVENT_RENEWAL_COMPLETE): ";
 upnpEventRenewalComplete:
+#if UPNP_VERSION >= 10800
+		UpnpEventSubscribe *es_event = (UpnpEventSubscribe *)Event;
+		int errCode = UpnpEventSubscribe_get_ErrCode(es_event);
+		if (errCode != UPNP_E_SUCCESS) {
+#else
 		struct Upnp_Event_Subscribe *es_event =
 			(struct Upnp_Event_Subscribe *)Event;
 		if (es_event->ErrCode != UPNP_E_SUCCESS) {
+#endif
 			msg << "Error in Event Subscribe Callback";
+#if UPNP_VERSION >= 10800
+			UPnP::ProcessErrorMessage(msg.str(), errCode, NULL, NULL);
+#else
 			UPnP::ProcessErrorMessage(
 				msg.str(), es_event->ErrCode, NULL, NULL);
+#endif
+			msg << "Error in Event Subscribe Callback";
 		} else {
 #if 0
+#if UPNP_VERSION >= 10800
+			const UpnpString *publisherUrl =
+				UpnpEventSubscribe_get_PublisherUrl(es_event);
+			const char *sid = UpnpEvent_get_SID_cstr(es_event);
+			int timeOut = UpnpEvent_get_TimeOut(es_event);
 			TvCtrlPointHandleSubscribeUpdate(
+				publisherUrl, sid, timeOut);
+#else
+			TvCtrlPointHandleSubscribeUpdate(
 				GET_UPNP_STRING(es_event->PublisherUrl),
 				es_event->Sid,
 				es_event->TimeOut );
 #endif
+#endif
 		}
 
 		break;
@@ -1280,29 +1369,56 @@
 		msg << "error(UPNP_EVENT_SUBSCRIPTION_EXPIRED): ";
 		msg2 << "UPNP_EVENT_SUBSCRIPTION_EXPIRED: ";
 upnpEventSubscriptionExpired:
+#if UPNP_VERSION >= 10800
+		UpnpEventSubscribe *es_event = (UpnpEventSubscribe *)Event;
+#else
 		struct Upnp_Event_Subscribe *es_event =
 			(struct Upnp_Event_Subscribe *)Event;
+#endif
 		Upnp_SID newSID;
 		memset(newSID, 0, sizeof(Upnp_SID));
 		int TimeOut = 1801;
+#if UPNP_VERSION >= 10800
+		const char *publisherUrl =
+			UpnpEventSubscribe_get_PublisherUrl_cstr(es_event);
+#endif
 		int ret = UpnpSubscribe(
 			upnpCP->m_UPnPClientHandle,
+#if UPNP_VERSION >= 10800
+			publisherUrl,
+#else
 			GET_UPNP_STRING(es_event->PublisherUrl),
+#endif
 			&TimeOut,
 			newSID);
 		if (ret != UPNP_E_SUCCESS) {
 			msg << "Error Subscribing to EventURL";
+#if UPNP_VERSION >= 10800
+			int errCode = UpnpEventSubscribe_get_ErrCode(es_event);
+#endif
 			UPnP::ProcessErrorMessage(
+#if UPNP_VERSION >= 10800
+				msg.str(), errCode, NULL, NULL);
+#else
 				msg.str(), es_event->ErrCode, NULL, NULL);
+#endif
 		} else {
 			ServiceMap::iterator it =
+#if UPNP_VERSION >= 10800
+				upnpCP->m_ServiceMap.find(publisherUrl);
+#else
 				upnpCP->m_ServiceMap.find(GET_UPNP_STRING(es_event->PublisherUrl));
+#endif
 			if (it != upnpCP->m_ServiceMap.end()) {
 				CUPnPService &service = *(it->second);
 				service.SetTimeout(TimeOut);
 				service.SetSID(newSID);
 				msg2 << "Re-subscribed to EventURL '" <<
+#if UPNP_VERSION >= 10800
+				publisherUrl <<
+#else
 					GET_UPNP_STRING(es_event->PublisherUrl) <<
+#endif
 					"' with SID == '" <<
 					newSID << "'.";
 				AddDebugLogLineC(logUPnP, msg2);
@@ -1321,17 +1437,34 @@
 	case UPNP_CONTROL_ACTION_COMPLETE: {
 		//fprintf(stderr, "Callback: UPNP_CONTROL_ACTION_COMPLETE\n");
 		// This is here if we choose to do this asynchronously
+#if UPNP_VERSION >= 10800
+		UpnpActionComplete *a_event = (UpnpActionComplete *)Event;
+		int errCode = UpnpActionComplete_get_ErrCode(a_event);
+		IXML_Document *actionResult =
+			UpnpActionComplete_get_ActionResult(a_event);
+		if (errCode != UPNP_E_SUCCESS) {
+#else
 		struct Upnp_Action_Complete *a_event =
 			(struct Upnp_Action_Complete *)Event;
 		if (a_event->ErrCode != UPNP_E_SUCCESS) {
+#endif
 			UPnP::ProcessErrorMessage(
 				"UpnpSendActionAsync",
+#if UPNP_VERSION >= 10800
+				errCode, NULL,
+				actionResult);
+#else
 				a_event->ErrCode, NULL,
 				a_event->ActionResult);
+#endif
 		} else {
 			// Check the response document
 			UPnP::ProcessActionResponse(
+#if UPNP_VERSION >= 10800
+				actionResult,
+#else
 				a_event->ActionResult,
+#endif
 				"<UpnpSendActionAsync>");
 		}
 		/* No need for any processing here, just print out results.
@@ -1342,21 +1475,37 @@
 	case UPNP_CONTROL_GET_VAR_COMPLETE: {
 		//fprintf(stderr, "Callback: UPNP_CONTROL_GET_VAR_COMPLETE\n");
 		msg << "error(UPNP_CONTROL_GET_VAR_COMPLETE): ";
+#if UPNP_VERSION >= 10800
+		UpnpStateVarComplete *sv_event = (UpnpStateVarComplete *)Event;
+		int errCode = UpnpStateVarComplete_get_ErrCode(sv_event);
+		if (errCode != UPNP_E_SUCCESS) {
+#else
 		struct Upnp_State_Var_Complete *sv_event =
 			(struct Upnp_State_Var_Complete *)Event;
 		if (sv_event->ErrCode != UPNP_E_SUCCESS) {
+#endif
 			msg << "m_UpnpGetServiceVarStatusAsync";
 			UPnP::ProcessErrorMessage(
+#if UPNP_VERSION >= 10800
+				msg.str(), errCode, NULL, NULL);
+#else
 				msg.str(), sv_event->ErrCode, NULL, NULL);
+#endif
 		} else {
 #if 0
 			// Warning: The use of UpnpGetServiceVarStatus and
 			// UpnpGetServiceVarStatusAsync is deprecated by the
 			// UPnP forum.
+#if UPNP_VERSION >= 10800
+			const char *ctrlUrl =
+				UpnpStateVarComplete_get_CtrlUrl(sv_event);
+			const char *stateVarName =
+#else
 			TvCtrlPointHandleGetVar(
 				sv_event->CtrlUrl,
 				sv_event->StateVarName,
 				sv_event->CurrentVal );
+#endif
 #endif
 		}
 		break;
