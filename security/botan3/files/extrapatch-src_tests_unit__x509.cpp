--- src/tests/unit_x509.cpp.orig	2024-02-20 17:28:54 UTC
+++ src/tests/unit_x509.cpp
@@ -18,6 +18,8 @@
    #include <botan/x509path.h>
    #include <botan/x509self.h>
    #include <botan/internal/calendar.h>
+
+   #include <boost/range/algorithm.hpp>
 #endif
 
 namespace Botan_Tests {
@@ -627,7 +629,7 @@ Test::Result test_x509_encode_authority_info_access_ex
 
    for(const auto& ca_issuer : cert.ca_issuers()) {
       result.confirm("CA issuer URI present in certificate",
-                     std::ranges::find(ca_issuers, ca_issuer) != ca_issuers.end());
+                     boost::range::find(ca_issuers, ca_issuer) != ca_issuers.end());
    }
 
    result.confirm("no OCSP url available", cert.ocsp_responder().empty());
@@ -1400,7 +1402,7 @@ Test::Result test_x509_extensions(const Botan::Private
                      !cert_cdps->crl_distribution_urls().empty())) {
       for(const auto& cdp : cert_cdps->distribution_points()) {
          result.confirm("CDP URI present in self-signed certificate",
-                        std::ranges::find(cdp_urls, cdp.point().get_first_attribute("URI")) != cdp_urls.end());
+                        boost::range::find(cdp_urls, cdp.point().get_first_attribute("URI")) != cdp_urls.end());
       }
    }
 
@@ -1436,7 +1438,7 @@ Test::Result test_x509_extensions(const Botan::Private
                      !cert_cdps->crl_distribution_urls().empty())) {
       for(const auto& cdp : cert_cdps->distribution_points()) {
          result.confirm("CDP URI present in self-signed certificate",
-                        std::ranges::find(cdp_urls, cdp.point().get_first_attribute("URI")) != cdp_urls.end());
+                        boost::range::find(cdp_urls, cdp.point().get_first_attribute("URI")) != cdp_urls.end());
       }
    }
 
