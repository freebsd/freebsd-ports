--- fwcutter_list.h.orig	2011-08-21 16:17:01.000000000 +0400
+++ fwcutter_list.h	2011-12-19 18:23:16.000000000 +0400
@@ -131,6 +131,55 @@
 	EXTRACT_LIST_END
 };
 
+static struct extract _1a258b2d93efa641c32ddf3c3a962028[] =
+{
+    /* { .name = "ucode4", .offset = 0xAFE08, .type = EXT_UCODE_1, .length = 0x4EA0 }, */
+    /* { .name = "pcm4", .offset = 0xE8FE0, .type = EXT_PCM, .length = 0x520 }, */
+    /* { .name = "b0g0initvals4", .offset = 0xA2878, .type = EXT_IV, .length = 0xE80 }, */
+    /* { .name = "a0g0bsinitvals4", .offset = 0xA45C0, .type = EXT_IV, .length = 0x30 }, */
+    /* { .name = "b0g0bsinitvals4", .offset = 0xA3700, .type = EXT_IV, .length = 0x30 }, */
+    /* { .name = "a0g0initvals4", .offset = 0xA3738, .type = EXT_IV, .length = 0xE80 }, */
+    { .name = "ucode5", .offset = 0xB4CAC, .type = EXT_UCODE_2, .length = 0x56F0 },
+    { .name = "pcm5", .offset = 0xE9504, .type = EXT_PCM, .length = 0x520 },
+    { .name = "a0g0bsinitvals5", .offset = 0xA6578, .type = EXT_IV, .length = 0x118 },
+    { .name = "b0g0bsinitvals5", .offset = 0xA5018, .type = EXT_IV, .length = 0x118 },
+    { .name = "a0g0initvals5", .offset = 0xA5138, .type = EXT_IV, .length = 0xA18 },
+    { .name = "a0g1initvals5", .offset = 0xA5B58, .type = EXT_IV, .length = 0xA18 },
+    { .name = "b0g0initvals5", .offset = 0xA45F8, .type = EXT_IV, .length = 0xA18 },
+    { .name = "a0g1bsinitvals5", .offset = 0xA6698, .type = EXT_IV, .length = 0x118 },
+    { .name = "ucode9", .offset = 0xBA3A0, .type = EXT_UCODE_2, .length = 0x6248 },
+    { .name = "a0g0bsinitvals9", .offset = 0xA89C0, .type = EXT_IV, .length = 0x118 },
+    { .name = "b0g0initvals9", .offset = 0xA67B8, .type = EXT_IV, .length = 0xAF0 },
+    { .name = "a0g1bsinitvals9", .offset = 0xA8AE0, .type = EXT_IV, .length = 0x118 },
+    { .name = "b0g0bsinitvals9", .offset = 0xA72B0, .type = EXT_IV, .length = 0x118 },
+    { .name = "a0g0initvals9", .offset = 0xA73D0, .type = EXT_IV, .length = 0xAF0 },
+    { .name = "a0g1initvals9", .offset = 0xA7EC8, .type = EXT_IV, .length = 0xAF0 },
+    { .name = "ucode11", .offset = 0xC05EC, .type = EXT_UCODE_2, .length = 0x8000 },
+    { .name = "n0initvals11", .offset = 0xA8C00, .type = EXT_IV, .length = 0xBC8 },
+    { .name = "n0bsinitvals11", .offset = 0xA97D0, .type = EXT_IV, .length = 0x118 },
+    { .name = "n0absinitvals11", .offset = 0xA98F0, .type = EXT_IV, .length = 0x118 },
+    { .name = "ucode13", .offset = 0xC85F0, .type = EXT_UCODE_2, .length = 0x7AC8 },
+    { .name = "b0g0bsinitvals13", .offset = 0xABA70, .type = EXT_IV, .length = 0x118 },
+    { .name = "b0g0initvals13", .offset = 0xAAED0, .type = EXT_IV, .length = 0xB98 },
+    { .name = "a0g1bsinitvals13", .offset = 0xAC730, .type = EXT_IV, .length = 0x118 },
+    { .name = "a0g1initvals13", .offset = 0xABB90, .type = EXT_IV, .length = 0xB98 },
+    { .name = "lp0bsinitvals13", .offset = 0xAADB0, .type = EXT_IV, .length = 0x118 },
+    { .name = "lp0initvals13", .offset = 0xA9A10, .type = EXT_IV, .length = 0x1398 },
+    { .name = "ucode14", .offset = 0xD00BC, .type = EXT_UCODE_2, .length = 0x7910 },
+    { .name = "lp0initvals14", .offset = 0xAC850, .type = EXT_IV, .length = 0xB80 },
+    { .name = "lp0bsinitvals14", .offset = 0xAD3D8, .type = EXT_IV, .length = 0x118 },
+    { .name = "ucode15", .offset = 0xD79D0, .type = EXT_UCODE_3, .length = 0x8768 },
+    { .name = "lp0initvals15", .offset = 0xAD4F8, .type = EXT_IV, .length = 0xC68 },
+    { .name = "lp0bsinitvals15", .offset = 0xAE168, .type = EXT_IV, .length = 0x118 },
+    { .name = "ucode16", .offset = 0xE013C, .type = EXT_UCODE_3, .length = 0x8EA0 },
+    { .name = "lp0bsinitvals16", .offset = 0xAFCE8, .type = EXT_IV, .length = 0x118 },
+    { .name = "n0bsinitvals16", .offset = 0xAEF20, .type = EXT_IV, .length = 0x118 },
+    { .name = "sslpn0initvals16", .offset = 0xAF040, .type = EXT_IV, .length = 0x0 },
+    { .name = "n0initvals16", .offset = 0xAE288, .type = EXT_IV, .length = 0xC90 },
+    { .name = "lp0initvals16", .offset = 0xAF050, .type = EXT_IV, .length = 0xC90 },
+    { .name = "sslpn0bsinitvals16", .offset = 0xAF048, .type = EXT_IV, .length = 0x0 },
+    EXTRACT_LIST_END
+};
 
 static struct extract _cb8d70972b885b1f8883b943c0261a3c[] =
 {
@@ -811,6 +860,14 @@
 		.extract	= _1e4763b4cb8cfbaae43e5c6d3d6b2ae7,
 	},
 	{
+		/* ftp://downloads.netgear.com/files/GPL/WNDR3300-V1.0.29_gpl_src.zip */
+		.name		= "wl_apsta.o",
+		.ucode_version	= "478.104",
+		.md5		= "1a258b2d93efa641c32ddf3c3a962028",
+		.flags		= FW_FLAG_LE | FW_FLAG_V4,
+		.extract	= _1a258b2d93efa641c32ddf3c3a962028,
+	},
+	{
 		/* http://mirror2.openwrt.org/sources/broadcom-wl-4.150.10.5.tar.bz2 */
 		.name		= "wl_apsta_mimo.o",
 		.ucode_version	= "410.2160",
