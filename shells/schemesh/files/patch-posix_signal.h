--- posix/signal.h.orig	2025-02-16 14:43:54 UTC
+++ posix/signal.h
@@ -138,11 +138,11 @@ static ptr c_signals_list(void) {
                   {SIGBUS, "sigbus"},       {SIGFPE, "sigfpe"},       {SIGKILL, "sigkill"},
                   {SIGUSR1, "sigusr1"},     {SIGSEGV, "sigsegv"},     {SIGUSR2, "sigusr2"},
                   {SIGPIPE, "sigpipe"},     {SIGALRM, "sigalrm"},     {SIGTERM, "sigterm"},
-                  {SIGSTKFLT, "sigstkflt"}, {SIGCHLD, "sigchld"},     {SIGCONT, "sigcont"},
+                  /* {SIGSTKFLT, "sigstkflt"}, */ {SIGCHLD, "sigchld"},     {SIGCONT, "sigcont"},
                   {SIGSTOP, "sigstop"},     {SIGTSTP, "sigtstp"},     {SIGTTIN, "sigttin"},
                   {SIGTTOU, "sigttou"},     {SIGURG, "sigurg"},       {SIGXCPU, "sigxcpu"},
                   {SIGXFSZ, "sigxfsz"},     {SIGVTALRM, "sigvtalrm"}, {SIGPROF, "sigprof"},
-                  {SIGWINCH, "sigwinch"},   {SIGIO, "sigio"},         {SIGPWR, "sigpwr"},
+                  {SIGWINCH, "sigwinch"},   {SIGIO, "sigio"},         /* {SIGPWR, "sigpwr"}, */
                   {SIGSYS, "sigsys"}};

   ptr    ret = Snil;
