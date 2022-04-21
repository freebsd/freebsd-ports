--- chrome/updater/util.cc.orig	2022-04-21 18:48:31 UTC
+++ chrome/updater/util.cc
@@ -265,7 +265,7 @@ GURL AppendQueryParameter(const GURL& url,
   return url.ReplaceComponents(replacements);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 // TODO(crbug.com/1276188) - implement the functions below.
 absl::optional<base::FilePath> GetUpdaterFolderPath(UpdaterScope scope) {
