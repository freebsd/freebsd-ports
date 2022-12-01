--- chrome/updater/util.cc.orig	2022-12-01 10:35:46 UTC
+++ chrome/updater/util.cc
@@ -264,7 +264,7 @@ GURL AppendQueryParameter(const GURL& url,
   return url.ReplaceComponents(replacements);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // TODO(crbug.com/1276188) - implement the functions below.
 absl::optional<base::FilePath> GetBaseInstallDirectory(UpdaterScope scope) {
