--- print-802_11.c.orig	Wed Dec 10 01:52:33 2003
+++ print-802_11.c	Wed Mar 31 11:51:54 2004
@@ -42,14 +42,17 @@
 #include "extract.h"
 
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
@@ -919,9 +922,265 @@
 	return ieee802_11_print(p, h->len, h->caplen);
 }
 
+/*
+ * Useful combinations of channel characteristics.
+ */
+#define	IEEE80211_CHAN_FHSS \
+	(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_GFSK)
+#define	IEEE80211_CHAN_A \
+	(IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_OFDM)
+#define	IEEE80211_CHAN_B \
+	(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_CCK)
+#define	IEEE80211_CHAN_PUREG \
+	(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_OFDM)
+#define	IEEE80211_CHAN_G \
+	(IEEE80211_CHAN_2GHZ | IEEE80211_CHAN_DYN)
+#define	IEEE80211_CHAN_T \
+	(IEEE80211_CHAN_5GHZ | IEEE80211_CHAN_OFDM | IEEE80211_CHAN_TURBO)
+
+#define	IEEE80211_IS_CHAN_FHSS(_flags) \
+	(((_flags) & IEEE80211_CHAN_FHSS) == IEEE80211_CHAN_FHSS)
+#define	IEEE80211_IS_CHAN_A(_flags) \
+	(((_flags) & IEEE80211_CHAN_A) == IEEE80211_CHAN_A)
+#define	IEEE80211_IS_CHAN_B(_flags) \
+	(((_flags) & IEEE80211_CHAN_B) == IEEE80211_CHAN_B)
+#define	IEEE80211_IS_CHAN_PUREG(_flags) \
+	(((_flags) & IEEE80211_CHAN_PUREG) == IEEE80211_CHAN_PUREG)
+#define	IEEE80211_IS_CHAN_G(_flags) \
+	(((_flags) & IEEE80211_CHAN_G) == IEEE80211_CHAN_G)
+#define	IEEE80211_IS_CHAN_T(_flags) \
+	(((_flags) & IEEE80211_CHAN_T) == IEEE80211_CHAN_T)
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
+#define CHECK_EXTRACT_LE_8BITS(_v,_bad) do {		\
+	if (iter + sizeof(u_int8_t) > iterlast) {	\
+		_bad;					\
+	}						\
+	_v = EXTRACT_LE_8BITS(iter);			\
+	iter += sizeof(u_int8_t);			\
+} while (0)
+#define CHECK_EXTRACT_LE_16BITS(_v,_bad) do {		\
+	if (iter + sizeof(u_int16_t) > iterlast) {	\
+		_bad;					\
+	}						\
+	_v = EXTRACT_LE_16BITS(iter);			\
+	iter += sizeof(u_int16_t);			\
+} while (0)
+#define CHECK_EXTRACT_LE_64BITS(_v,_bad) do {		\
+	if (iter + sizeof(u_int64_t) > iterlast) {	\
+		_bad;					\
+	}						\
+	_v = EXTRACT_LE_64BITS(iter);			\
+	iter += sizeof(u_int64_t);			\
+} while (0)
+
+	struct ieee80211_radiotap_header *hdr;
+	u_int32_t present, next_present;
+	u_int32_t *presentp, *last_presentp;
+	enum ieee80211_radiotap_type bit;
+	int bit0, len;
+	const u_int8_t *iter;
+	const u_int8_t *iterlast;
+	union {
+		int8_t		i8;
+		u_int8_t	u8;
+		int16_t		i16;
+		u_int16_t	u16;
+		u_int32_t	u32;
+		u_int64_t	u64;
+	} u, u2;
+
+	if (caplen < sizeof(*hdr)) {
+		printf("[|802.11]");
+		return caplen;
+	}
+
+	hdr = (struct ieee80211_radiotap_header *)p;
+
+	len = EXTRACT_LE_16BITS(&hdr->it_len);
+	if (caplen < len) {
+		printf("[|802.11]");
+		return caplen;
+	}
+
+	for (last_presentp = &hdr->it_present;
+	     (*last_presentp & BIT(IEEE80211_RADIOTAP_EXT)) != 0 &&
+	     (u_char*)(last_presentp + 1) <= p + len;
+	     last_presentp++);
+
+	/* are there more bitmap extensions than bytes in header? */
+	if ((*last_presentp & BIT(IEEE80211_RADIOTAP_EXT)) != 0) {
+		printf("[|802.11]");
+		return caplen;
+	}
+
+	iter = (u_char*)(last_presentp + 1);
+	iterlast = (u_char*)(p + len);
+
+	for (bit0 = 0, presentp = &hdr->it_present; presentp <= last_presentp;
+	     presentp++, bit0 += 32) {
+		present = EXTRACT_LE_32BITS(presentp);
+		for (; present; present = next_present) {
+			/* clear the least significant bit that is set */
+			next_present = present & (present - 1);
+
+			/* extract the least significant bit that is set */
+			bit = bit0 + BITNO_32(present ^ next_present);
+
+			switch (bit) {
+			case IEEE80211_RADIOTAP_FLAGS:
+			case IEEE80211_RADIOTAP_RATE:
+			case IEEE80211_RADIOTAP_DB_ANTSIGNAL:
+			case IEEE80211_RADIOTAP_DB_ANTNOISE:
+			case IEEE80211_RADIOTAP_ANTENNA:
+			case IEEE80211_RADIOTAP_DB_TX_ATTENUATION:
+				CHECK_EXTRACT_LE_8BITS(u.u8, goto bad);
+				break;
+			case IEEE80211_RADIOTAP_DBM_ANTSIGNAL:
+			case IEEE80211_RADIOTAP_DBM_ANTNOISE:
+			case IEEE80211_RADIOTAP_DBM_TX_POWER:
+				CHECK_EXTRACT_LE_8BITS(u.i8, goto bad);
+				break;
+			case IEEE80211_RADIOTAP_FHSS:
+			case IEEE80211_RADIOTAP_LOCK_QUALITY:
+			case IEEE80211_RADIOTAP_TX_ATTENUATION:
+			case IEEE80211_RADIOTAP_CHANNEL:
+				CHECK_EXTRACT_LE_16BITS(u.u16, goto bad);
+				if (bit == IEEE80211_RADIOTAP_CHANNEL)
+					CHECK_EXTRACT_LE_16BITS(u2.u16,
+						goto bad);
+				break;
+			case IEEE80211_RADIOTAP_TSFT:
+				CHECK_EXTRACT_LE_64BITS(u.u64, goto bad);
+				break;
+			default:
+				/* this bit indicates a field whose
+				 * size we do not know, so we cannot
+				 * proceed.
+				 */
+				printf("[0x%08x] ", bit);
+				return -1;
+			bad:
+				/*
+				 * There wasn't enough data for the
+				 * data type; stop decoding.
+				 */
+				printf("[|802.11]");
+				goto out;
+			}
+
+			switch (bit) {
+			case IEEE80211_RADIOTAP_CHANNEL:
+				printf("%u MHz ", u.u16);
+				if (u2.u16 != 0) {
+					/* use flags to disambiguate */
+					if (IEEE80211_IS_CHAN_G(u2.u16) ||
+					    IEEE80211_IS_CHAN_PUREG(u2.u16))
+						printf("(11g) ", u2.u16);
+					else if (IEEE80211_IS_CHAN_T(u2.u16))
+						printf("(turbo) ", u2.u16);
+					else if (IEEE80211_IS_CHAN_B(u2.u16))
+						;
+					else if (IEEE80211_IS_CHAN_A(u2.u16))
+						;
+					else if (IEEE80211_IS_CHAN_FHSS(u2.u16))
+						;
+					else
+						printf("(0x%04x) ", u2.u16);
+				}
+				break;
+			case IEEE80211_RADIOTAP_FHSS:
+				printf("fhset %d fhpat %d ",
+				    u.u16 & 0xff, (u.u16 >> 8) & 0xff);
+				break;
+			case IEEE80211_RADIOTAP_RATE:
+				PRINT_RATE("", u.u8, " Mb/s ");
+				break;
+			case IEEE80211_RADIOTAP_DBM_ANTSIGNAL:
+				printf("%ddB signal ", u.i8);
+				break;
+			case IEEE80211_RADIOTAP_DBM_ANTNOISE:
+				printf("%ddB noise ", u.i8);
+				break;
+			case IEEE80211_RADIOTAP_DB_ANTSIGNAL:
+				printf("%ddB signal ", u.u8);
+				break;
+			case IEEE80211_RADIOTAP_DB_ANTNOISE:
+				printf("%ddB noise ", u.u8);
+				break;
+			case IEEE80211_RADIOTAP_LOCK_QUALITY:
+				printf("%u sq ", u.u16);
+				break;
+			case IEEE80211_RADIOTAP_TX_ATTENUATION:
+				printf("%d tx power ", -(int)u.u16);
+				break;
+			case IEEE80211_RADIOTAP_DB_TX_ATTENUATION:
+				printf("%ddB tx power ", -(int)u.u8);
+				break;
+			case IEEE80211_RADIOTAP_DBM_TX_POWER:
+				printf("%ddBm tx power ", u.i8);
+				break;
+			case IEEE80211_RADIOTAP_FLAGS:
+				if (u.u8 & IEEE80211_RADIOTAP_F_CFP)
+					printf("cfp ");
+				if (u.u8 & IEEE80211_RADIOTAP_F_SHORTPRE)
+					printf("short preamble ");
+				if (u.u8 & IEEE80211_RADIOTAP_F_WEP)
+					printf("wep ");
+				if (u.u8 & IEEE80211_RADIOTAP_F_FRAG)
+					printf("fragmented ");
+				break;
+			case IEEE80211_RADIOTAP_ANTENNA:
+				printf("antenna %d ", u.u8);
+				break;
+			case IEEE80211_RADIOTAP_TSFT:
+				printf("%lldus tsft ", (long long)u.u64);
+				break;
+			}
+		}
+	}
+out:
+
+	return len + ieee802_11_print(p + len, length - len, caplen - len);
+
+#undef CHECK_EXTRACT_8BITS
+#undef CHECK_EXTRACT_LE_16BITS
+#undef CHECK_EXTRACT_LE_64BITS
+
+#undef BITNO_32
+#undef BITNO_16
+#undef BITNO_8
+#undef BITNO_4
+#undef BITNO_2
+#undef BIT
+}
+
+#undef IEEE80211_CHAN_FHSS
+#undef IEEE80211_CHAN_A
+#undef IEEE80211_CHAN_B
+#undef IEEE80211_CHAN_PUREG
+#undef IEEE80211_CHAN_G
+#undef IEEE80211_CHAN_T
+
+#undef IEEE80211_IS_CHAN_FHSS
+#undef IEEE80211_IS_CHAN_A
+#undef IEEE80211_IS_CHAN_B
+#undef IEEE80211_IS_CHAN_PUREG
+#undef IEEE80211_IS_CHAN_G
+#undef IEEE80211_IS_CHAN_T
+
+static u_int
+ieee802_11_avs_radio_print(const u_char *p, u_int length, u_int caplen)
+{
 	u_int32_t caphdr_len;
 
 	caphdr_len = EXTRACT_32BITS(p + 4);
@@ -972,7 +1231,7 @@
 	}
 
 	if (EXTRACT_32BITS(p) == WLANCAP_MAGIC_COOKIE_V1)
-		return ieee802_11_radio_print(p, length, caplen);
+		return ieee802_11_avs_radio_print(p, length, caplen);
 
 	if (caplen < PRISM_HDR_LEN) {
 		printf("[|802.11]");
