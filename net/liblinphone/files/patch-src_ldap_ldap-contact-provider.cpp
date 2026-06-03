--- src/ldap/ldap-contact-provider.cpp.orig	2025-12-22 14:02:00 UTC
+++ src/ldap/ldap-contact-provider.cpp
@@ -279,16 +279,6 @@ void LdapContactProvider::initializeLdap() {
 		         << ldap_err2string(ret) << "), err " << err << " (" << ldap_err2string(err) << ")";
 		fallbackToNextServerUrl();
 	} else if (mConfig.count("use_tls") > 0 && mConfig["use_tls"][0] == "1") {
-		if (mConfig.count("use_sal") > 0 &&
-		    mConfig["use_sal"][0] ==
-		        "1") { // Using Sal give an IP for a domain. So check the domain rather than the IP.
-			belle_generic_uri_t *serverUri = belle_generic_uri_parse(
-			    mConfig["server"][mConfigServerIndex].c_str()); // mServer are results of sal. Use the root urls.
-			const char *cHost = belle_generic_uri_get_host(serverUri);
-			std::string hostname = L_C_TO_STRING(cHost);
-			ldap_set_option(mLd, LDAP_OPT_X_TLS_PEER_CN, &hostname[0]);
-			if (serverUri) belle_sip_object_unref(serverUri);
-		}
 		mTlsConnectionId = -1;
 		mCurrentAction = ACTION_WAIT_TLS_CONNECT;
 		mTlsConnectionTimeout = time(NULL);
