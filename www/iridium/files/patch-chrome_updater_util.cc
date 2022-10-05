--- chrome/updater/util.cc.orig	2022-10-05 07:34:01 UTC
+++ chrome/updater/util.cc
@@ -263,7 +263,7 @@ GURL AppendQueryParameter(const GURL& url,
   return url.ReplaceComponents(replacements);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // TODO(crbug.com/1276188) - implement the functions below.
 absl::optional<base::FilePath> GetBaseInstallDirectory(UpdaterScope scope) {
