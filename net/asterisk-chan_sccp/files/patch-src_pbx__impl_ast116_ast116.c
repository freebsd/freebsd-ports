--- src/pbx_impl/ast116/ast116.c.orig	2021-12-29 10:49:04 UTC
+++ src/pbx_impl/ast116/ast116.c
@@ -3063,10 +3063,12 @@ DECLARE_PBX_CHANNEL_STRGET(name)
     DECLARE_PBX_CHANNEL_STRGET(linkedid)
     DECLARE_PBX_CHANNEL_STRGET(context)
     DECLARE_PBX_CHANNEL_STRSET(context)
+#if _ASTERISK_VERSION < 21
     DECLARE_PBX_CHANNEL_STRGET(macroexten)
     DECLARE_PBX_CHANNEL_STRSET(macroexten)
     DECLARE_PBX_CHANNEL_STRGET(macrocontext)
     DECLARE_PBX_CHANNEL_STRSET(macrocontext)
+#endif
     DECLARE_PBX_CHANNEL_STRGET(call_forward)
     DECLARE_PBX_CHANNEL_STRSET(call_forward)
 
@@ -3534,10 +3536,12 @@ const PbxInterface iPbx = {
 	setChannelExten: sccp_astwrap_set_channel_exten,
 	getChannelContext: sccp_astwrap_get_channel_context,
 	setChannelContext: sccp_astwrap_set_channel_context,
+#if _ASTERISK_VERSION < 21
 	getChannelMacroExten: sccp_astwrap_get_channel_macroexten,
 	setChannelMacroExten: sccp_astwrap_set_channel_macroexten,
 	getChannelMacroContext: sccp_astwrap_get_channel_macrocontext,
 	setChannelMacroContext: sccp_astwrap_set_channel_macrocontext,
+#endif
 	getChannelCallForward: sccp_astwrap_get_channel_call_forward,
 	setChannelCallForward: sccp_astwrap_set_channel_call_forward,
 
@@ -3685,10 +3689,12 @@ const PbxInterface iPbx = {
 	.setChannelExten = sccp_astwrap_set_channel_exten,
 	.getChannelContext = sccp_astwrap_get_channel_context,
 	.setChannelContext = sccp_astwrap_set_channel_context,
+#if _ASTERISK_VERSION < 21
 	.getChannelMacroExten = sccp_astwrap_get_channel_macroexten,
 	.setChannelMacroExten = sccp_astwrap_set_channel_macroexten,
 	.getChannelMacroContext = sccp_astwrap_get_channel_macrocontext,
 	.setChannelMacroContext = sccp_astwrap_set_channel_macrocontext,
+#endif
 	.getChannelCallForward = sccp_astwrap_get_channel_call_forward,
 	.setChannelCallForward = sccp_astwrap_set_channel_call_forward,
 
