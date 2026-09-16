--- bin/cbsdsh/src/mksignames.c.orig	2026-09-16 08:21:34 UTC
+++ bin/cbsdsh/src/mksignames.c
@@ -44,6 +44,10 @@ char *progname;
    I don't want to allocate so much unused space for the intervening signal
    numbers, so we just punt if SIGRTMAX is past the bounds of the
    signal_names array (handled in configure). */
+#if defined (SIGRTMAX) && !defined (UNUSABLE_RT_SIGNALS) && (SIGRTMAX >= 2 * NSIG + 3)
+#  define UNUSABLE_RT_SIGNALS
+#endif
+
 #if defined (SIGRTMAX) && defined (UNUSABLE_RT_SIGNALS)
 #  undef SIGRTMAX
 #  undef SIGRTMIN
