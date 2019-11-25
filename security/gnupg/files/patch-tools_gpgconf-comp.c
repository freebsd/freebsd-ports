--- tools/gpgconf-comp.c.orig	2019-07-09 09:08:45 UTC
+++ tools/gpgconf-comp.c
@@ -653,6 +653,9 @@ static gc_option_t gc_options_scdaemon[] =
    { "card-timeout", GC_OPT_FLAG_NONE|GC_OPT_FLAG_RUNTIME, GC_LEVEL_BASIC,
      "gnupg", "|N|disconnect the card after N seconds of inactivity",
      GC_ARG_TYPE_UINT32, GC_BACKEND_SCDAEMON },
+   { "shared-access", GC_OPT_FLAG_NONE|GC_OPT_FLAG_RUNTIME, GC_LEVEL_BASIC,
+     "gnupg", "use PCSC_SHARE_SHARED for pcsc_connect",
+     GC_ARG_TYPE_NONE, GC_BACKEND_SCDAEMON },
 
    { "Debug",
      GC_OPT_FLAG_GROUP, GC_LEVEL_ADVANCED,
