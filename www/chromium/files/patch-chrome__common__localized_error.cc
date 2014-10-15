--- chrome/common/localized_error.cc.orig	2014-10-02 17:39:46 UTC
+++ chrome/common/localized_error.cc
@@ -40,6 +40,8 @@
 static const char kWeakDHKeyLearnMoreUrl[] =
     "http://sites.google.com/a/chromium.org/dev/"
     "err_ssl_weak_server_ephemeral_dh_key";
+static const char kSSLv3FallbackUrl[] =
+    "https://code.google.com/p/chromium/issues/detail?id=418848";
 #if defined(OS_CHROMEOS)
 static const char kAppWarningLearnMoreUrl[] =
     "chrome-extension://honijodknafkokifofgiaalefdiedpko/main.html"
@@ -301,6 +303,13 @@
    IDS_ERRORPAGES_DETAILS_BLOCKED_ENROLLMENT_CHECK_PENDING,
    SUGGEST_CHECK_CONNECTION,
   },
+  {net::ERR_SSL_FALLBACK_BEYOND_MINIMUM_VERSION,
+   IDS_ERRORPAGES_TITLE_LOAD_FAILED,
+   IDS_ERRORPAGES_HEADING_SSL_FALLBACK_BEYOND_MINIMUM_VERSION,
+   IDS_ERRORPAGES_SUMMARY_SSL_FALLBACK_BEYOND_MINIMUM_VERSION,
+   IDS_ERRORPAGES_DETAILS_SSL_FALLBACK_BEYOND_MINIMUM_VERSION,
+   SUGGEST_LEARNMORE,
+  },
 };
 
 // Special error page to be used in the case of navigating back to a page
@@ -796,6 +805,9 @@
       case net::ERR_SSL_WEAK_SERVER_EPHEMERAL_DH_KEY:
         learn_more_url = GURL(kWeakDHKeyLearnMoreUrl);
         break;
+      case net::ERR_SSL_FALLBACK_BEYOND_MINIMUM_VERSION:
+        learn_more_url = GURL(kSSLv3FallbackUrl);
+        break;
       default:
         break;
     }
