--- print-802_11.c.orig	Tue Jul 22 18:36:57 2003
+++ print-802_11.c	Wed Dec 10 18:56:16 2003
@@ -41,15 +41,20 @@
 
 #include "extract.h"
 
+#include "cpack.h"
+
 #include "ieee802_11.h"
+#include "ieee802_11_radio.h"
 
+#define PRINT_RATE(_sep, _r, _suf) \
+	printf("%s%2.1f%s", _sep, (.5 * ((_r) & 0x7f)), _suf)
 #define PRINT_RATES(p) \
 do { \
 	int z; \
 	const char *sep = " ["; \
 	for (z = 0; z < p.rates.length ; z++) { \
-		printf("%s%2.1f", sep, (.5 * (p.rates.rate[z] & 0x7f))); \
-		if (p.rates.rate[z] & 0x80) printf("*"); \
+		PRINT_RATE(sep, p.rates.rate[z], \
+			(p.rates.rate[z] & 0x80 ? "*" : "")); \
 		sep = " "; \
 	} \
 	if (p.rates.length != 0) \
@@ -924,9 +929,194 @@
 	return ieee802_11_print(p, h->len, h->caplen);
 }
 
+static int
+print_radiotap_field(struct cpack_state *s, u_int32_t bit)
+{
+	union {
+		int8_t		i8;
+		u_int8_t	u8;
+		int16_t		i16;
+		u_int16_t	u16;
+		u_int32_t	u32;
+		u_int64_t	u64;
+	} u, u2;
+	int rc;
+
+	switch (bit) {
+	case IEEE80211_RADIOTAP_FLAGS:
+	case IEEE80211_RADIOTAP_RATE:
+	case IEEE80211_RADIOTAP_DB_ANTSIGNAL:
+	case IEEE80211_RADIOTAP_DB_ANTNOISE:
+	case IEEE80211_RADIOTAP_ANTENNA:
+		rc = cpack_uint8(s, &u.u8);
+		break;
+	case IEEE80211_RADIOTAP_DBM_ANTSIGNAL:
+	case IEEE80211_RADIOTAP_DBM_ANTNOISE:
+		rc = cpack_int8(s, &u.i8);
+		break;
+	case IEEE80211_RADIOTAP_CHANNEL:
+		rc = cpack_uint16(s, &u.u16);
+		if (rc != 0)
+			break;
+		rc = cpack_uint16(s, &u2.u16);
+		break;
+	case IEEE80211_RADIOTAP_FHSS:
+	case IEEE80211_RADIOTAP_LOCK_QUALITY:
+	case IEEE80211_RADIOTAP_TX_ATTENUATION:
+		rc = cpack_uint16(s, &u.u16);
+		break;
+	case IEEE80211_RADIOTAP_DB_TX_ATTENUATION:
+		rc = cpack_uint8(s, &u.u8);
+		break;
+	case IEEE80211_RADIOTAP_DBM_TX_POWER:
+		rc = cpack_uint8(s, &u.i8);
+		break;
+	case IEEE80211_RADIOTAP_TSFT:
+		rc = cpack_uint64(s, &u.u64);
+		break;
+	default:
+		/* this bit indicates a field whose
+		 * size we do not know, so we cannot
+		 * proceed.
+		 */
+		printf("[0x%08x] ", bit);
+		return -1;
+	}
+
+	if (rc != 0) {
+		printf("[|802.11]");
+		return rc;
+	}
+
+	switch (bit) {
+	case IEEE80211_RADIOTAP_CHANNEL:
+		printf("%u MHz ", u.u16);
+		if (u2.u16 != 0)
+			printf("(0x%04x) ", u2.u16);
+		break;
+	case IEEE80211_RADIOTAP_FHSS:
+		printf("fhset %d fhpat %d ", u.u16 & 0xff, (u.u16 >> 8) & 0xff);
+		break;
+	case IEEE80211_RADIOTAP_RATE:
+		PRINT_RATE("", u.u8, " Mb/s ");
+		break;
+	case IEEE80211_RADIOTAP_DBM_ANTSIGNAL:
+		printf("%ddB signal ", u.i8);
+		break;
+	case IEEE80211_RADIOTAP_DBM_ANTNOISE:
+		printf("%ddB noise ", u.i8);
+		break;
+	case IEEE80211_RADIOTAP_DB_ANTSIGNAL:
+		printf("%ddB signal ", u.u8);
+		break;
+	case IEEE80211_RADIOTAP_DB_ANTNOISE:
+		printf("%ddB noise ", u.u8);
+		break;
+	case IEEE80211_RADIOTAP_LOCK_QUALITY:
+		printf("%u sq ", u.u16);
+		break;
+	case IEEE80211_RADIOTAP_TX_ATTENUATION:
+		printf("%d tx power ", -(int)u.u16);
+		break;
+	case IEEE80211_RADIOTAP_DB_TX_ATTENUATION:
+		printf("%ddB tx power ", -(int)u.u8);
+		break;
+	case IEEE80211_RADIOTAP_DBM_TX_POWER:
+		printf("%ddBm tx power ", u.i8);
+		break;
+	case IEEE80211_RADIOTAP_FLAGS:
+		if (u.u8 & IEEE80211_RADIOTAP_F_CFP)
+			printf("cfp ");
+		if (u.u8 & IEEE80211_RADIOTAP_F_SHORTPRE)
+			printf("short preamble ");
+		if (u.u8 & IEEE80211_RADIOTAP_F_WEP)
+			printf("wep ");
+		if (u.u8 & IEEE80211_RADIOTAP_F_FRAG)
+			printf("fragmented ");
+		break;
+	case IEEE80211_RADIOTAP_ANTENNA:
+		printf("antenna %d ", u.u8);
+		break;
+	case IEEE80211_RADIOTAP_TSFT:
+		printf("%lldus tsft ", (long long)u.u64);
+		break;
+	}
+	return 0;
+}
+
 static u_int
 ieee802_11_radio_print(const u_char *p, u_int length, u_int caplen)
 {
+#define BITNO_32(x) (((x) >> 16) ? 16 + BITNO_16((x) >> 16) : BITNO_16((x)))
+#define BITNO_16(x) (((x) >> 8) ? 8 + BITNO_8((x) >> 8) : BITNO_8((x)))
+#define BITNO_8(x) (((x) >> 4) ? 4 + BITNO_4((x) >> 4) : BITNO_4((x)))
+#define BITNO_4(x) (((x) >> 2) ? 2 + BITNO_2((x) >> 2) : BITNO_2((x)))
+#define BITNO_2(x) (((x) & 2) ? 1 : 0)
+#define BIT(n)	(1 << n)
+
+	struct cpack_state cpacker;
+	struct ieee80211_radiotap_header *hdr;
+	u_int32_t present, next_present;
+	u_int32_t *presentp, *last_presentp;
+	enum ieee80211_radiotap_type bit;
+	int bit0;
+	const u_char *iter;
+
+	if (caplen < sizeof(*hdr)) {
+		printf("[|802.11]");
+		return caplen;
+	}
+
+	hdr = (struct ieee80211_radiotap_header *)p;
+
+	if (caplen < hdr->it_len) {
+		printf("[|802.11]");
+		return caplen;
+	}
+
+	for (last_presentp = &hdr->it_present;
+	     (*last_presentp & BIT(IEEE80211_RADIOTAP_EXT)) != 0 &&
+	     (u_char*)(last_presentp + 1) <= p + hdr->it_len;
+	     last_presentp++);
+
+	/* are there more bitmap extensions than bytes in header? */
+	if ((*last_presentp & BIT(IEEE80211_RADIOTAP_EXT)) != 0) {
+		printf("[|802.11]");
+		return caplen;
+	}
+
+	iter = (u_char*)(last_presentp + 1);
+
+	cpack_init_in(&cpacker, (u_int8_t*)iter, hdr->it_len - (iter - p));
+
+	for (bit0 = 0, presentp = &hdr->it_present; presentp <= last_presentp;
+	     presentp++, bit0 += 32) {
+		for (present = *presentp; present; present = next_present) {
+			/* clear the least significant bit that is set */
+			next_present = present & (present - 1);
+
+			/* extract the least significant bit that is set */
+			bit = bit0 + BITNO_32(present ^ next_present);
+
+			if (print_radiotap_field(&cpacker, bit) != 0)
+				goto out;
+		}
+	}
+out:
+
+	return hdr->it_len + ieee802_11_print(p + hdr->it_len,
+	    length - hdr->it_len, caplen - hdr->it_len);
+#undef BITNO_32
+#undef BITNO_16
+#undef BITNO_8
+#undef BITNO_4
+#undef BITNO_2
+#undef BIT
+}
+
+static u_int
+ieee802_11_avs_radio_print(const u_char *p, u_int length, u_int caplen)
+{
 	u_int32_t caphdr_len;
 
 	caphdr_len = EXTRACT_32BITS(p + 4);
@@ -977,7 +1167,7 @@
 	}
 
 	if (EXTRACT_32BITS(p) == WLANCAP_MAGIC_COOKIE_V1)
-		return ieee802_11_radio_print(p, length, caplen);
+		return ieee802_11_avs_radio_print(p, length, caplen);
 
 	if (caplen < PRISM_HDR_LEN) {
 		printf("[|802.11]");
