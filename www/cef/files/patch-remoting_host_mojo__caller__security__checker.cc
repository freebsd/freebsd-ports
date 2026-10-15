--- remoting/host/mojo_caller_security_checker.cc.orig	2026-07-01 06:24:19 UTC
+++ remoting/host/mojo_caller_security_checker.cc
@@ -40,7 +40,7 @@
 namespace remoting {
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr auto kAllowedCallerProgramNames =
     base::MakeFixedFlatSet<base::FilePath::StringViewType>({
         "remote-open-url",
@@ -136,7 +136,7 @@ bool IsTrustedMojoEndpoint(
     const named_mojo_ipc_server::ConnectionInfo& caller) {
 #if BUILDFLAG(IS_MAC)
   return IsProcessTrusted(caller.audit_token, kAllowedIdentifiers);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
   static base::NoDestructor<base::FilePath> current_process_image_path(
       GetProcessImagePath(base::GetCurrentProcId()));
@@ -173,7 +173,7 @@ bool IsTrustedMojoEndpoint(
   base::FilePath::StringType program_name =
       caller_process_image_path.BaseName().value();
   if (!kAllowedCallerProgramNames.contains(program_name)) {
-#if BUILDFLAG(IS_LINUX) && !defined(NDEBUG)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(NDEBUG)
     // Linux binaries generated in out/Debug are underscore-separated. To make
     // debugging easier, we just check the name again with underscores replaced
     // with hyphens.
