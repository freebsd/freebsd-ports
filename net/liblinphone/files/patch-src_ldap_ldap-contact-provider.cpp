--- src/ldap/ldap-contact-provider.cpp.orig	2022-05-18 10:10:25 UTC
+++ src/ldap/ldap-contact-provider.cpp
@@ -220,11 +220,6 @@ void LdapContactProvider::initializeLdap(){
 		ms_error("[LDAP] Cannot initialize address to %s : %x (%s), err %x (%s)",mConfig["server"].c_str(), ret, ldap_err2string(ret), err, ldap_err2string(err));
 		mCurrentAction = ACTION_ERROR;
 	}else if(mConfig.count("use_tls")>0 && mConfig["use_tls"] == "1"){
-		if(mConfig.count("use_sal")>0 && mConfig["use_sal"] == "1"){// Using Sal give an IP for a domain. So check the domain rather than the IP.
-			belle_generic_uri_t *serverUri = belle_generic_uri_parse(mConfig["server"].c_str());
-			std::string hostname = belle_generic_uri_get_host(serverUri);
-			ldap_set_option(mLd, LDAP_OPT_X_TLS_PEER_CN, &hostname[0]);
-		}
 		mTlsConnectionId = -1;
 		mCurrentAction = ACTION_WAIT_TLS_CONNECT;
 		mTlsConnectionTimeout = time(NULL);
