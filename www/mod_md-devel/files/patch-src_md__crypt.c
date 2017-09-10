--- src/md_crypt.c.orig	2017-09-08 14:09:36 UTC
+++ src/md_crypt.c
@@ -116,6 +116,425 @@ static void seed_RAND(int pid)
 
 #endif /*ifdef MD_HAVE_ARC4RANDOM (else part) */
 
+#ifdef LIBRESSL_VERSION_NUMBER
+
+/* Extracted from OpenSSL 1.0.2 */
+
+struct tm *OPENSSL_gmtime(const time_t *timer, struct tm *result)
+{
+    struct tm *ts = NULL;
+
+#if defined(OPENSSL_THREADS) && defined(OPENSSL_SYS_VMS)
+    {
+        struct tm data, *ts2 = &data;
+        if (gmtime_r(timer, ts2) == NULL)
+            return NULL;
+        memcpy(result, ts2, sizeof(struct tm));
+        ts = result;
+    }
+#elif defined(OPENSSL_THREADS) && !defined(OPENSSL_SYS_WIN32) && !defined(OPENSSL_SYS_MACOSX)
+    if (gmtime_r(timer, result) == NULL)
+        return NULL;
+    ts = result;
+#else
+    ts = gmtime(timer);
+    if (ts == NULL)
+        return NULL;
+
+    memcpy(result, ts, sizeof(struct tm));
+    ts = result;
+#endif
+    return ts;
+}
+
+#define SECS_PER_DAY (24 * 60 * 60)
+# define ASN1_STRING_FLAG_X509_TIME 0x100
+
+static int leap_year(const int year)
+{
+    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
+        return 1;
+    return 0;
+}
+
+/*
+ * Compute the day of the week and the day of the year from the year, month
+ * and day.  The day of the year is straightforward, the day of the week uses
+ * a form of Zeller's congruence.  For this months start with March and are
+ * numbered 4 through 15.
+ */
+static void determine_days(struct tm *tm)
+{
+    static const int ydays[12] = {
+        0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
+    };
+    int y = tm->tm_year + 1900;
+    int m = tm->tm_mon;
+    int d = tm->tm_mday;
+    int c;
+
+    tm->tm_yday = ydays[m] + d - 1;
+    if (m >= 2) {
+        /* March and onwards can be one day further into the year */
+        tm->tm_yday += leap_year(y);
+        m += 2;
+    } else {
+        /* Treat January and February as part of the previous year */
+        m += 14;
+        y--;
+    }
+    c = y / 100;
+    y %= 100;
+    /* Zeller's congruance */
+    tm->tm_wday = (d + (13 * m) / 5 + y + y / 4 + c / 4 + 5 * c + 6) % 7;
+}
+
+/*
+ * Convert date to and from julian day Uses Fliegel & Van Flandern algorithm
+ */
+static long date_to_julian(int y, int m, int d)
+{
+    return (1461 * (y + 4800 + (m - 14) / 12)) / 4 +
+        (367 * (m - 2 - 12 * ((m - 14) / 12))) / 12 -
+        (3 * ((y + 4900 + (m - 14) / 12) / 100)) / 4 + d - 32075;
+}
+
+static void julian_to_date(long jd, int *y, int *m, int *d)
+{
+    long L = jd + 68569;
+    long n = (4 * L) / 146097;
+    long i, j;
+
+    L = L - (146097 * n + 3) / 4;
+    i = (4000 * (L + 1)) / 1461001;
+    L = L - (1461 * i) / 4 + 31;
+    j = (80 * L) / 2447;
+    *d = L - (2447 * j) / 80;
+    L = j / 11;
+    *m = j + 2 - (12 * L);
+    *y = 100 * (n - 49) + i + L;
+}
+
+/* Convert tm structure and offset into julian day and seconds */
+static int julian_adj(const struct tm *tm, int off_day, long offset_sec,
+                      long *pday, int *psec)
+{
+    int offset_hms, offset_day;
+    long time_jd;
+    int time_year, time_month, time_day;
+    /* split offset into days and day seconds */
+    offset_day = offset_sec / SECS_PER_DAY;
+    /* Avoid sign issues with % operator */
+    offset_hms = offset_sec - (offset_day * SECS_PER_DAY);
+    offset_day += off_day;
+    /* Add current time seconds to offset */
+    offset_hms += tm->tm_hour * 3600 + tm->tm_min * 60 + tm->tm_sec;
+    /* Adjust day seconds if overflow */
+    if (offset_hms >= SECS_PER_DAY) {
+        offset_day++;
+        offset_hms -= SECS_PER_DAY;
+    } else if (offset_hms < 0) {
+        offset_day--;
+        offset_hms += SECS_PER_DAY;
+    }
+
+    /*
+     * Convert date of time structure into a Julian day number.
+     */
+
+    time_year = tm->tm_year + 1900;
+    time_month = tm->tm_mon + 1;
+    time_day = tm->tm_mday;
+
+    time_jd = date_to_julian(time_year, time_month, time_day);
+
+    /* Work out Julian day of new date */
+    time_jd += offset_day;
+
+    if (time_jd < 0)
+        return 0;
+
+    *pday = time_jd;
+    *psec = offset_hms;
+    return 1;
+}
+
+int OPENSSL_gmtime_adj(struct tm *tm, int off_day, long offset_sec)
+{
+    int time_sec, time_year, time_month, time_day;
+    long time_jd;
+
+    /* Convert time and offset into Julian day and seconds */
+    if (!julian_adj(tm, off_day, offset_sec, &time_jd, &time_sec))
+        return 0;
+
+    /* Convert Julian day back to date */
+
+    julian_to_date(time_jd, &time_year, &time_month, &time_day);
+
+    if (time_year < 1900 || time_year > 9999)
+        return 0;
+
+    /* Update tm structure */
+
+    tm->tm_year = time_year - 1900;
+    tm->tm_mon = time_month - 1;
+    tm->tm_mday = time_day;
+
+    tm->tm_hour = time_sec / 3600;
+    tm->tm_min = (time_sec / 60) % 60;
+    tm->tm_sec = time_sec % 60;
+
+    return 1;
+
+}
+
+int OPENSSL_gmtime_diff(int *pday, int *psec,
+                        const struct tm *from, const struct tm *to)
+{
+    int from_sec, to_sec, diff_sec;
+    long from_jd, to_jd, diff_day;
+    if (!julian_adj(from, 0, 0, &from_jd, &from_sec))
+        return 0;
+    if (!julian_adj(to, 0, 0, &to_jd, &to_sec))
+        return 0;
+    diff_day = to_jd - from_jd;
+    diff_sec = to_sec - from_sec;
+    /* Adjust differences so both positive or both negative */
+    if (diff_day > 0 && diff_sec < 0) {
+        diff_day--;
+        diff_sec += SECS_PER_DAY;
+    }
+    if (diff_day < 0 && diff_sec > 0) {
+        diff_day++;
+        diff_sec -= SECS_PER_DAY;
+    }
+
+    if (pday)
+        *pday = (int)diff_day;
+    if (psec)
+        *psec = diff_sec;
+
+    return 1;
+
+}
+
+int asn1_time_to_tm(struct tm *tm, const ASN1_TIME *d)
+{
+    static const int min[9] = { 0, 0, 1, 1, 0, 0, 0, 0, 0 };
+    static const int max[9] = { 99, 99, 12, 31, 23, 59, 59, 12, 59 };
+    static const int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
+    char *a;
+    int n, i, i2, l, o, min_l = 11, strict = 0, end = 6, btz = 5, md;
+    struct tm tmp;
+
+    /*
+     * ASN1_STRING_FLAG_X509_TIME is used to enforce RFC 5280
+     * time string format, in which:
+     *
+     * 1. "seconds" is a 'MUST'
+     * 2. "Zulu" timezone is a 'MUST'
+     * 3. "+|-" is not allowed to indicate a time zone
+     */
+    if (d->type == V_ASN1_UTCTIME) {
+        if (d->flags & ASN1_STRING_FLAG_X509_TIME) {
+            min_l = 13;
+            strict = 1;
+        }
+    } else if (d->type == V_ASN1_GENERALIZEDTIME) {
+        end = 7;
+        btz = 6;
+        if (d->flags & ASN1_STRING_FLAG_X509_TIME) {
+            min_l = 15;
+            strict = 1;
+        } else {
+            min_l = 13;
+        }
+    } else {
+        return 0;
+    }
+
+    l = d->length;
+    a = (char *)d->data;
+    o = 0;
+    memset(&tmp, 0, sizeof(tmp));
+
+    /*
+     * GENERALIZEDTIME is similar to UTCTIME except the year is represented
+     * as YYYY. This stuff treats everything as a two digit field so make
+     * first two fields 00 to 99
+     */
+
+    if (l < min_l)
+        goto err;
+    for (i = 0; i < end; i++) {
+        if (!strict && (i == btz) && ((a[o] == 'Z') || (a[o] == '+') || (a[o] == '-'))) {
+            i++;
+            break;
+        }
+        if (!isdigit(a[o]))
+            goto err;
+        n = a[o] - '0';
+        /* incomplete 2-digital number */
+        if (++o == l)
+            goto err;
+
+        if (!isdigit(a[o]))
+            goto err;
+        n = (n * 10) + a[o] - '0';
+        /* no more bytes to read, but we haven't seen time-zone yet */
+        if (++o == l)
+            goto err;
+
+        i2 = (d->type == V_ASN1_UTCTIME) ? i + 1 : i;
+
+        if ((n < min[i2]) || (n > max[i2]))
+            goto err;
+        switch (i2) {
+        case 0:
+            /* UTC will never be here */
+            tmp.tm_year = n * 100 - 1900;
+            break;
+        case 1:
+            if (d->type == V_ASN1_UTCTIME)
+                tmp.tm_year = n < 50 ? n + 100 : n;
+            else
+                tmp.tm_year += n;
+            break;
+        case 2:
+            tmp.tm_mon = n - 1;
+            break;
+        case 3:
+            /* check if tm_mday is valid in tm_mon */
+            if (tmp.tm_mon == 1) {
+                /* it's February */
+                md = mdays[1] + leap_year(tmp.tm_year + 1900);
+            } else {
+                md = mdays[tmp.tm_mon];
+            }
+            if (n > md)
+                goto err;
+            tmp.tm_mday = n;
+            determine_days(&tmp);
+            break;
+        case 4:
+            tmp.tm_hour = n;
+            break;
+        case 5:
+            tmp.tm_min = n;
+            break;
+        case 6:
+            tmp.tm_sec = n;
+            break;
+        }
+    }
+
+    /*
+     * Optional fractional seconds: decimal point followed by one or more
+     * digits.
+     */
+    if (d->type == V_ASN1_GENERALIZEDTIME && a[o] == '.') {
+        if (strict)
+            /* RFC 5280 forbids fractional seconds */
+            goto err;
+        if (++o == l)
+            goto err;
+        i = o;
+        while ((o < l) && isdigit(a[o]))
+            o++;
+        /* Must have at least one digit after decimal point */
+        if (i == o)
+            goto err;
+        /* no more bytes to read, but we haven't seen time-zone yet */
+        if (o == l)
+            goto err;
+    }
+
+    /*
+     * 'o' will never point to '\0' at this point, the only chance
+     * 'o' can point to '\0' is either the subsequent if or the first
+     * else if is true.
+     */
+    if (a[o] == 'Z') {
+        o++;
+    } else if (!strict && ((a[o] == '+') || (a[o] == '-'))) {
+        int offsign = a[o] == '-' ? 1 : -1;
+        int offset = 0;
+
+        o++;
+        /*
+         * if not equal, no need to do subsequent checks
+         * since the following for-loop will add 'o' by 4
+         * and the final return statement will check if 'l'
+         * and 'o' are equal.
+         */
+        if (o + 4 != l)
+            goto err;
+        for (i = end; i < end + 2; i++) {
+            if (!isdigit(a[o]))
+                goto err;
+            n = a[o] - '0';
+            o++;
+            if (!isdigit(a[o]))
+                goto err;
+            n = (n * 10) + a[o] - '0';
+            i2 = (d->type == V_ASN1_UTCTIME) ? i + 1 : i;
+            if ((n < min[i2]) || (n > max[i2]))
+                goto err;
+            /* if tm is NULL, no need to adjust */
+            if (tm != NULL) {
+                if (i == end)
+                    offset = n * 3600;
+                else if (i == end + 1)
+                    offset += n * 60;
+            }
+            o++;
+        }
+        if (offset && !OPENSSL_gmtime_adj(&tmp, 0, offset * offsign))
+            goto err;
+    } else {
+        /* not Z, or not +/- in non-strict mode */
+        goto err;
+    }
+    if (o == l) {
+        /* success, check if tm should be filled */
+        if (tm != NULL)
+            *tm = tmp;
+        return 1;
+    }
+ err:
+    return 0;
+}
+
+int ASN1_TIME_to_tm(const ASN1_TIME *s, struct tm *tm)
+{
+    if (s == NULL) {
+        time_t now_t;
+
+        time(&now_t);
+        memset(tm, 0, sizeof(*tm));
+        if (OPENSSL_gmtime(&now_t, tm) != NULL)
+            return 1;
+        return 0;
+    }
+
+    return asn1_time_to_tm(tm, s);
+}
+
+int ASN1_TIME_diff(int *pday, int *psec,
+                   const ASN1_TIME *from, const ASN1_TIME *to)
+{
+    struct tm tm_from, tm_to;
+
+    if (!ASN1_TIME_to_tm(from, &tm_from))
+        return 0;
+    if (!ASN1_TIME_to_tm(to, &tm_to))
+        return 0;
+    return OPENSSL_gmtime_diff(pday, psec, &tm_from, &tm_to);
+}
+
+#endif /*ifdef LIBRESSL_VERSION_NUMBER*/
+
 
 apr_status_t md_crypt_init(apr_pool_t *pool)
 {
@@ -409,7 +828,7 @@ apr_status_t md_pkey_gen(md_pkey_t **ppk
     }
 }
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 #ifndef NID_tlsfeature
 #define NID_tlsfeature          1020
