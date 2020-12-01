--- components/download/internal/common/base_file.cc.orig	2020-11-13 06:36:40 UTC
+++ components/download/internal/common/base_file.cc
@@ -604,7 +604,7 @@ GURL GetEffectiveAuthorityURL(const GURL& source_url,
 
 }  // namespace
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformationSync(
@@ -623,7 +623,7 @@ DownloadInterruptReason BaseFile::AnnotateWithSourceIn
 
   return QuarantineFileResultToReason(result);
 }
-#else  // !OS_WIN && !OS_APPLE && !OS_LINUX && !OS_CHROMEOS
+#else  // !OS_WIN && !OS_APPLE && !OS_LINUX && !OS_CHROMEOS && !OS_BSD
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformationSync(
     const std::string& client_guid,
     const GURL& source_url,
