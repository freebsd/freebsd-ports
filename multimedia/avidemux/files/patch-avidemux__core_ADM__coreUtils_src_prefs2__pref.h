--- avidemux_core/ADM_coreUtils/src/prefs2_pref.h.orig	2019-08-15 07:25:39 UTC
+++ avidemux_core/ADM_coreUtils/src/prefs2_pref.h
@@ -18,7 +18,7 @@ static optionDesc myOptions[]={
 { FEATURES_REUSE_2PASS_LOG,"features.reuse_2pass_log"                 ,ADM_param_bool    	,"0",	0,	1},
 { FEATURES_AUDIOBAR_USES_MASTER,"features.audiobar_uses_master"       ,ADM_param_bool    	,"0",	0,	1},
 { FEATURES_THREADING_LAVC,"features.threading_lavc"                   ,ADM_param_uint32_t	,"0",	0,	32},
-{ FEATURES_CPU_CAPS,"features.cpu_caps"                               ,ADM_param_uint32_t	,"4294967295",	0,	4294967295},
+{ FEATURES_CPU_CAPS,"features.cpu_caps"                               ,ADM_param_uint32_t	,"4294967295",	0,	static_cast<float>(4294967295)},
 { FEATURES_CACHE_SIZE,"features.cache_size"                           ,ADM_param_uint32_t	,"16",	8,	16},
 { FEATURES_MPEG_NO_LIMIT,"features.mpeg_no_limit"                     ,ADM_param_bool    	,"0",	0,	1},
 { FEATURES_DXVA2,"features.dxva2"                                     ,ADM_param_bool    	,"0",	0,	1},
