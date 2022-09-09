Obtained from:	https://git.savannah.gnu.org/cgit/dmidecode.git/commit/?id=a1a2258ffbe450e8561ee833787da9321fa734b0

--- dmioem.c.orig	2022-06-27 15:06:32 UTC
+++ dmioem.c
@@ -299,6 +299,96 @@ static void dmi_hp_203_devloc(const char *fname, unsig
 	pr_attr(fname, "%s", str);
 }
 
+static int dmi_hp_224_status(u8 code)
+{
+	static const char * const present[] = {
+		"Not Present", /* 0x00 */
+		"Present/Enabled",
+		"Present/Disabled",
+		"Reserved" /* 0x03 */
+	};
+
+	pr_attr("Status", "%s", present[code & 0x03]);
+	if ((code & 0x03) == 0x00)
+		return 0;
+	pr_attr("Option ROM Measuring", "%s", (code & (1 << 2)) ? "Yes" : "No");
+	pr_attr("Hidden", "%s", (code & (1 << 3)) ? "Yes" : "No");
+	return 1;
+}
+
+static void dmi_hp_224_ex_status(u8 status, u8 code)
+{
+	const char *str = "Reserved";
+	static const char * const disable_reason[] = {
+		"Not Specified", /* 0x00 */
+		"User Disabled",
+		"Error Condition",
+		"Reserved"	/* 0x03 */
+	};
+	static const char * const error_condition[] = {
+		"Not Specified", /* 0x00 */
+		"Self-Test",     /* 0x01 */
+	};
+	if ((status & 0x03) == 0x02)
+		pr_attr("Disable Reason", "%s", disable_reason[code & 0x03]);
+	if ((code & 0x03) == 0x02) {
+		u8 error = (code >> 2) & 0x0f;
+		if (error < ARRAY_SIZE(error_condition))
+			str = error_condition[error];
+		pr_attr("Error Condition", "%s", str);
+	}
+}
+
+static void dmi_hp_224_module_type(u8 code)
+{
+	const char *str = "Reserved";
+	static const char * const type[] = {
+		"Not Specified", /* 0x00 */
+		"TPM 1.2",
+		"TPM 2.0",
+		"Intel PTT fTPM" /* 0x03 */
+	};
+	if ((code & 0x0f) < ARRAY_SIZE(type))
+		str = type[code & 0x0f];
+	pr_attr("Type", "%s", str);
+	pr_attr("Standard Algorithm Supported", "%s", (code & (1 << 4)) ? "Yes" : "No");
+	pr_attr("Chinese Algorithm Supported", "%s", (code & (1 << 5)) ? "Yes" : "No");
+}
+
+static void dmi_hp_224_module_attr(u8 code)
+{
+	static const char * const phys_attr[] = {
+		"Not Specified", /* 0x00 */
+		"Pluggable and Optional",
+		"Pluggable but Standard",
+		"Soldered Down on System Board"  /* 0x03 */
+	};
+	static const char * const fips_attr[] = {
+		"Not Specified", /* 0x00 */
+		"Not FIPS Certified",
+		"FIPS Certified",
+		"Reserved"  /* 0x03 */
+	};
+	pr_attr("Trusted Module Attributes", "%s", phys_attr[code & 0x3]);
+	pr_attr("FIPS Certification", "%s", fips_attr[((code >> 2) & 0x03)]);
+}
+
+static void dmi_hp_224_chipid(u16 code)
+{
+	const char *str = "Reserved";
+	static const char * const chipid[] = {
+		"None", /* 0x00 */
+		"STMicroGen10 TPM",
+		"Intel firmware TPM (PTT)",
+		"Nationz TPM",
+		"STMicroGen10 Plus TPM",
+		"STMicroGen11 TPM", /* 0x05 */
+	};
+	if ((code & 0xff) < ARRAY_SIZE(chipid))
+		str = chipid[code & 0xff];
+	pr_attr("Chip Identifier", "%s", str);
+}
+
 static void dmi_hp_238_loc(const char *fname, unsigned int code)
 {
 	const char *str = "Reserved";
@@ -597,6 +687,36 @@ static int dmi_decode_hp(const struct dmi_header *h)
 			pr_attr("Misc. Features", "0x%08x", feat);
 			pr_subattr("iCRU", "%s", feat & 0x0001 ? "Yes" : "No");
 			pr_subattr("UEFI", "%s", feat & 0x1400 ? "Yes" : "No");
+			break;
+
+		case 224:
+			/*
+			 * Vendor Specific: Trusted Module (TPM or TCM) Status
+			 *
+			 * Offset |  Name  | Width | Description
+			 * -------------------------------------
+			 *  0x00  | Type   | BYTE  | 0xE0, Trusted Module (TPM or TCM) Status
+			 *  0x01  | Length | BYTE  | Length of structure
+			 *  0x02  | Handle | WORD  | Unique handle
+			 *  0x04  | Status | BYTE  | Status Flag Byte
+			 *  0x05  | Ex Stat| BYTE  | TPM Extended Status
+			 *  0x06  | Type   | BYTE  | Trusted Module Type
+			 *  0x07  | Attrib | BYTE  | Trusted Module Attributes
+			 *  0x08  | Handle | WORD  | Handle to map to Type 216
+			 *  0x0A  | Chip ID| WORD  | Chip Identifier Values
+			 */
+			pr_handle_name("%s Trusted Module (TPM or TCM) Status", company);
+			if (h->length < 0x05) break;
+			if (!dmi_hp_224_status(data[0x04]))
+				break;
+			if (h->length < 0x0a) break;
+			dmi_hp_224_ex_status(data[0x04], data[0x05]);
+			dmi_hp_224_module_type(data[0x06]);
+			dmi_hp_224_module_attr(data[0x07]);
+			if (!(opt.flags & FLAG_QUIET))
+				pr_attr("Associated Handle", "0x%04X", WORD(data + 0x8));
+			if (h->length < 0x0c) break;
+			dmi_hp_224_chipid(WORD(data + 0x0a));
 			break;
 
 		case 233:
