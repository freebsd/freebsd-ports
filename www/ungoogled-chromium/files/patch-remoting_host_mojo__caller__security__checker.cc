--- remoting/host/mojo_caller_security_checker.cc.orig	2024-11-16 12:20:41 UTC
+++ remoting/host/mojo_caller_security_checker.cc
@@ -37,7 +37,7 @@
 namespace remoting {
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr auto kAllowedCallerProgramNames =
     base::MakeFixedFlatSet<base::FilePath::StringPieceType>({
         "remote-open-url",
@@ -98,7 +98,7 @@ bool IsTrustedMojoEndpoint(
   return true;
 #endif
 
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
   // TODO: yuweih - see if it's possible to move away from PID-based security
   // checks, which might be susceptible of PID reuse attacks.
@@ -122,7 +122,7 @@ bool IsTrustedMojoEndpoint(
   base::FilePath::StringType program_name =
       caller_process_image_path.BaseName().value();
   if (!kAllowedCallerProgramNames.contains(program_name)) {
-#if BUILDFLAG(IS_LINUX) && !defined(NDEBUG)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !defined(NDEBUG)
     // Linux binaries generated in out/Debug are underscore-separated. To make
     // debugging easier, we just check the name again with underscores replaced
     // with hyphens.
