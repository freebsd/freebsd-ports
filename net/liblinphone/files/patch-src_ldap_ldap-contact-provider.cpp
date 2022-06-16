--- src/ldap/ldap-contact-provider.cpp.orig	2022-06-16 11:10:05 UTC
+++ src/ldap/ldap-contact-provider.cpp
@@ -158,12 +158,6 @@ void LdapContactProvider::initializeLdap(){
 	} else {
 
 		if(mConfig.count("use_tls")>0 && mConfig["use_tls"] == "1"){
-			if(mConfig.count("use_sal")>0 && mConfig["use_sal"] == "1"){// Using Sal give an IP for a domain. So check the domain rather than the IP.
-				belle_generic_uri_t *serverUri = belle_generic_uri_parse(mConfig["server"].c_str());
-				std::string hostname = belle_generic_uri_get_host(serverUri);
-				std::vector<char> cHostname(hostname.c_str(), hostname.c_str() + hostname.size() + 1);
-				ldap_set_option(mLd, LDAP_OPT_X_TLS_PEER_CN, &cHostname[0]);
-			}
 			ret = ldap_start_tls_s(mLd, NULL, NULL);
 		}
 		if( ret == LDAP_SUCCESS ) {
