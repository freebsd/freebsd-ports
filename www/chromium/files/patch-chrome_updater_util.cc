--- chrome/updater/util.cc.orig	2022-03-25 21:59:56 UTC
+++ chrome/updater/util.cc
@@ -253,7 +253,7 @@ GURL AppendQueryParameter(const GURL& url,
   return url.ReplaceComponents(replacements);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // TODO(crbug.com/1276188) - implement the functions below.
 absl::optional<base::FilePath> GetUpdaterFolderPath(UpdaterScope scope) {
