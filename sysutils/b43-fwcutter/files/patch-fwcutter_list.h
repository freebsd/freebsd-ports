--- ./fwcutter_list.h.orig	2009-06-02 08:52:55.000000000 -0700
+++ ./fwcutter_list.h	2010-02-16 19:22:34.000000000 -0800
@@ -238,6 +238,108 @@
 	EXTRACT_LIST_END
 };
 
+static struct extract _1a258b2d93efa641c32ddf3c3a962028[] =
+{
+	/* { .name = "ucode4", .offset = 0xAFE08, .type = EXT_UCODE_1, .length = 0x4EA0 }, */
+	/* { .name = "pcm4", .offset = 0xE8FE0, .type = EXT_PCM, .length = 0x520 }, */
+	/* { .name = "b0g0initvals4", .offset = 0xA2878, .type = EXT_IV, .length = 0xE80 }, */
+	/* { .name = "a0g0bsinitvals4", .offset = 0xA45C0, .type = EXT_IV, .length = 0x30 }, */
+	/* { .name = "b0g0bsinitvals4", .offset = 0xA3700, .type = EXT_IV, .length = 0x30 }, */
+	/* { .name = "a0g0initvals4", .offset = 0xA3738, .type = EXT_IV, .length = 0xE80 }, */
+	{ .name = "ucode5", .offset = 0xB4CAC, .type = EXT_UCODE_2, .length = 0x56F0 },
+	{ .name = "pcm5", .offset = 0xE9504, .type = EXT_PCM, .length = 0x520 },
+	{ .name = "a0g0bsinitvals5", .offset = 0xA6578, .type = EXT_IV, .length = 0x118 },
+	{ .name = "b0g0bsinitvals5", .offset = 0xA5018, .type = EXT_IV, .length = 0x118 },
+	{ .name = "a0g0initvals5", .offset = 0xA5138, .type = EXT_IV, .length = 0xA18 },
+	{ .name = "a0g1initvals5", .offset = 0xA5B58, .type = EXT_IV, .length = 0xA18 },
+	{ .name = "b0g0initvals5", .offset = 0xA45F8, .type = EXT_IV, .length = 0xA18 },
+	{ .name = "a0g1bsinitvals5", .offset = 0xA6698, .type = EXT_IV, .length = 0x118 },
+	{ .name = "ucode9", .offset = 0xBA3A0, .type = EXT_UCODE_2, .length = 0x6248 },
+	{ .name = "a0g0bsinitvals9", .offset = 0xA89C0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "b0g0initvals9", .offset = 0xA67B8, .type = EXT_IV, .length = 0xAF0 },
+	{ .name = "a0g1bsinitvals9", .offset = 0xA8AE0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "b0g0bsinitvals9", .offset = 0xA72B0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "a0g0initvals9", .offset = 0xA73D0, .type = EXT_IV, .length = 0xAF0 },
+	{ .name = "a0g1initvals9", .offset = 0xA7EC8, .type = EXT_IV, .length = 0xAF0 },
+	{ .name = "ucode11", .offset = 0xC05EC, .type = EXT_UCODE_2, .length = 0x8000 },
+	{ .name = "n0initvals11", .offset = 0xA8C00, .type = EXT_IV, .length = 0xBC8 },
+	{ .name = "n0bsinitvals11", .offset = 0xA97D0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "n0absinitvals11", .offset = 0xA98F0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "ucode13", .offset = 0xC85F0, .type = EXT_UCODE_2, .length = 0x7AC8 },
+	{ .name = "b0g0bsinitvals13", .offset = 0xABA70, .type = EXT_IV, .length = 0x118 },
+	{ .name = "b0g0initvals13", .offset = 0xAAED0, .type = EXT_IV, .length = 0xB98 },
+	{ .name = "a0g1bsinitvals13", .offset = 0xAC730, .type = EXT_IV, .length = 0x118 },
+	{ .name = "a0g1initvals13", .offset = 0xABB90, .type = EXT_IV, .length = 0xB98 },
+	{ .name = "lp0bsinitvals13", .offset = 0xAADB0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "lp0initvals13", .offset = 0xA9A10, .type = EXT_IV, .length = 0x1398 },
+	{ .name = "ucode14", .offset = 0xD00BC, .type = EXT_UCODE_2, .length = 0x7910 },
+	{ .name = "lp0initvals14", .offset = 0xAC850, .type = EXT_IV, .length = 0xB80 },
+	{ .name = "lp0bsinitvals14", .offset = 0xAD3D8, .type = EXT_IV, .length = 0x118 },
+	{ .name = "ucode15", .offset = 0xD79D0, .type = EXT_UCODE_3, .length = 0x8768 },
+	{ .name = "lp0initvals15", .offset = 0xAD4F8, .type = EXT_IV, .length = 0xC68 },
+	{ .name = "lp0bsinitvals15", .offset = 0xAE168, .type = EXT_IV, .length = 0x118 },
+	{ .name = "ucode16", .offset = 0xE013C, .type = EXT_UCODE_3, .length = 0x8EA0 },
+	{ .name = "lp0bsinitvals16", .offset = 0xAFCE8, .type = EXT_IV, .length = 0x118 },
+	{ .name = "n0bsinitvals16", .offset = 0xAEF20, .type = EXT_IV, .length = 0x118 },
+	{ .name = "sslpn0initvals16", .offset = 0xAF040, .type = EXT_IV, .length = 0x0 },
+	{ .name = "n0initvals16", .offset = 0xAE288, .type = EXT_IV, .length = 0xC90 },
+	{ .name = "lp0initvals16", .offset = 0xAF050, .type = EXT_IV, .length = 0xC90 },
+	{ .name = "sslpn0bsinitvals16", .offset = 0xAF048, .type = EXT_IV, .length = 0x0 },
+	EXTRACT_LIST_END
+};
+
+static struct extract _bb8537e3204a1ea5903fe3e66b5e2763[] =
+{
+	/* ucode major version at offset 0xa8b70 */
+	/* ucode minor version at offset 0xa8b74 */
+	/* { .name = "ucode4", .offset = 0xB6108, .type = EXT_UCODE_1, .length = 0x4EA0 }, */
+	/* { .name = "pcm4", .offset = 0xEF2E0, .type = EXT_PCM, .length = 0x520 }, */
+	/* { .name = "b0g0initvals4", .offset = 0xA8B78, .type = EXT_IV, .length = 0xE80 }, */
+	/* { .name = "a0g0bsinitvals4", .offset = 0xAA8C0, .type = EXT_IV, .length = 0x30 }, */
+	/* { .name = "b0g0bsinitvals4", .offset = 0xA9A00, .type = EXT_IV, .length = 0x30 }, */
+	/* { .name = "a0g0initvals4", .offset = 0xA9A38, .type = EXT_IV, .length = 0xE80 }, */
+	{ .name = "ucode5", .offset = 0xBAFAC, .type = EXT_UCODE_2, .length = 0x56F0 },
+	{ .name = "pcm5", .offset = 0xEF804, .type = EXT_PCM, .length = 0x520 },
+	{ .name = "b0g0bsinitvals5", .offset = 0xAB318, .type = EXT_IV, .length = 0x118 },
+	{ .name = "a0g0bsinitvals5", .offset = 0xAC878, .type = EXT_IV, .length = 0x118 },
+	{ .name = "b0g0initvals5", .offset = 0xAA8F8, .type = EXT_IV, .length = 0xA18 },
+	{ .name = "a0g1initvals5", .offset = 0xABE58, .type = EXT_IV, .length = 0xA18 },
+	{ .name = "a0g0initvals5", .offset = 0xAB438, .type = EXT_IV, .length = 0xA18 },
+	{ .name = "a0g1bsinitvals5", .offset = 0xAC998, .type = EXT_IV, .length = 0x118 },
+	{ .name = "ucode9", .offset = 0xC06A0, .type = EXT_UCODE_2, .length = 0x6248 },
+	{ .name = "a0g1initvals9", .offset = 0xAE1C8, .type = EXT_IV, .length = 0xAF0 },
+	{ .name = "a0g0bsinitvals9", .offset = 0xAECC0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "b0g0bsinitvals9", .offset = 0xAD5B0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "b0g0initvals9", .offset = 0xACAB8, .type = EXT_IV, .length = 0xAF0 },
+	{ .name = "a0g1bsinitvals9", .offset = 0xAEDE0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "a0g0initvals9", .offset = 0xAD6D0, .type = EXT_IV, .length = 0xAF0 },
+	{ .name = "ucode11", .offset = 0xC68EC, .type = EXT_UCODE_2, .length = 0x8000 },
+	{ .name = "n0bsinitvals11", .offset = 0xAFAD0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "n0absinitvals11", .offset = 0xAFBF0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "n0initvals11", .offset = 0xAEF00, .type = EXT_IV, .length = 0xBC8 },
+	{ .name = "ucode13", .offset = 0xCE8F0, .type = EXT_UCODE_2, .length = 0x7AC8 },
+	{ .name = "b0g0initvals13", .offset = 0xB11D0, .type = EXT_IV, .length = 0xB98 },
+	{ .name = "a0g1bsinitvals13", .offset = 0xB2A30, .type = EXT_IV, .length = 0x118 },
+	{ .name = "a0g1initvals13", .offset = 0xB1E90, .type = EXT_IV, .length = 0xB98 },
+	{ .name = "lp0bsinitvals13", .offset = 0xB10B0, .type = EXT_IV, .length = 0x118 },
+	{ .name = "b0g0bsinitvals13", .offset = 0xB1D70, .type = EXT_IV, .length = 0x118 },
+	{ .name = "lp0initvals13", .offset = 0xAFD10, .type = EXT_IV, .length = 0x1398 },
+	{ .name = "ucode14", .offset = 0xD63BC, .type = EXT_UCODE_2, .length = 0x7910 },
+	{ .name = "lp0initvals14", .offset = 0xB2B50, .type = EXT_IV, .length = 0xB80 },
+	{ .name = "lp0bsinitvals14", .offset = 0xB36D8, .type = EXT_IV, .length = 0x118 },
+	{ .name = "ucode15", .offset = 0xDDCD0, .type = EXT_UCODE_3, .length = 0x8768 },
+	{ .name = "lp0bsinitvals15", .offset = 0xB4468, .type = EXT_IV, .length = 0x118 },
+	{ .name = "lp0initvals15", .offset = 0xB37F8, .type = EXT_IV, .length = 0xC68 },
+	{ .name = "ucode16", .offset = 0xE643C, .type = EXT_UCODE_3, .length = 0x8EA0 },
+	{ .name = "n0bsinitvals16", .offset = 0xB5220, .type = EXT_IV, .length = 0x118 },
+	{ .name = "sslpn0initvals16", .offset = 0xB5340, .type = EXT_IV, .length = 0x0 },
+	{ .name = "n0initvals16", .offset = 0xB4588, .type = EXT_IV, .length = 0xC90 },
+	{ .name = "lp0initvals16", .offset = 0xB5350, .type = EXT_IV, .length = 0xC90 },
+	{ .name = "sslpn0bsinitvals16", .offset = 0xB5348, .type = EXT_IV, .length = 0x0 },
+	{ .name = "lp0bsinitvals16", .offset = 0xB5FE8, .type = EXT_IV, .length = 0x118 },
+	EXTRACT_LIST_END
+};
+
 /*
  * Links change, so let's not put them into the README.
  * I still put them here so we know where the file was obtained.
@@ -299,6 +401,24 @@
 		.flags		= FW_FLAG_LE | FW_FLAG_V4 | FW_FLAG_UNSUPPORTED,
 		.extract	= _2dd738b8feb8b3559fd9d8fbaf3bfffc,
 	},
+	{
+		/* ftp://downloads.netgear.com/files/GPL/WNDR3300-V1.0.29_gpl_src.zip */
+		.name		= "wl_apsta.o",
+		.id		= "FW15",
+		.ucode_version	= "478.104",
+		.md5		= "1a258b2d93efa641c32ddf3c3a962028",
+		.flags		= FW_FLAG_LE | FW_FLAG_V4,
+		.extract	= _1a258b2d93efa641c32ddf3c3a962028,
+	},
+	{
+		/* http://downloads.openwrt.org/sources/broadcom-wl-4.178.10.4.tar.bz2 */
+		.name		= "wl_apsta.o",
+		.id		= "FW15",
+		.ucode_version	= "478.104",
+		.md5		= "bb8537e3204a1ea5903fe3e66b5e2763",
+		.flags		= FW_FLAG_LE | FW_FLAG_V4,
+		.extract	= _bb8537e3204a1ea5903fe3e66b5e2763,
+	},
 };
 
 #define FILES (sizeof(files) / sizeof(files[0]))
