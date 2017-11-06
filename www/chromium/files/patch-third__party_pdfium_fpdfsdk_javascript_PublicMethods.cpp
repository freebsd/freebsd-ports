--- third_party/pdfium/fpdfsdk/javascript/PublicMethods.cpp.orig	2017-06-05 19:04:22 UTC
+++ third_party/pdfium/fpdfsdk/javascript/PublicMethods.cpp
@@ -68,6 +68,103 @@ const wchar_t* const fullmonths[] = {L"January", L"Feb
                                      L"July",    L"August",   L"September",
                                      L"October", L"November", L"December"};
 
+#if defined(__FreeBSD__)
+/*
+ * cvt.c - IEEE floating point formatting routines for FreeBSD
+ * from GNU libc-4.6.27
+ */
+
+/*
+ *    ap_ecvt converts to decimal
+ *      the number of digits is specified by ndigit
+ *      decpt is set to the position of the decimal point
+ *      sign is set to 0 for positive, 1 for negative
+ */
+
+#define	NDIG	80
+
+static char *
+     ap_cvt(double arg, int ndigits, int *decpt, int *sign, int eflag)
+{
+    register int r2;
+    double fi, fj;
+    register char *p, *p1;
+    static char buf[NDIG];
+
+    if (ndigits >= NDIG - 1)
+	ndigits = NDIG - 2;
+    r2 = 0;
+    *sign = 0;
+    p = &buf[0];
+    if (arg < 0) {
+	*sign = 1;
+	arg = -arg;
+    }
+    arg = modf(arg, &fi);
+    p1 = &buf[NDIG];
+    /*
+     * Do integer part
+     */
+    if (fi != 0) {
+	p1 = &buf[NDIG];
+	while (fi != 0) {
+	    fj = modf(fi / 10, &fi);
+	    *--p1 = (int) ((fj + .03) * 10) + '0';
+	    r2++;
+	}
+	while (p1 < &buf[NDIG])
+	    *p++ = *p1++;
+    }
+    else if (arg > 0) {
+	while ((fj = arg * 10) < 1) {
+	    arg = fj;
+	    r2--;
+	}
+    }
+    p1 = &buf[ndigits];
+    if (eflag == 0)
+	p1 += r2;
+    *decpt = r2;
+    if (p1 < &buf[0]) {
+	buf[0] = '\0';
+	return (buf);
+    }
+    while (p <= p1 && p < &buf[NDIG]) {
+	arg *= 10;
+	arg = modf(arg, &fj);
+	*p++ = (int) fj + '0';
+    }
+    if (p1 >= &buf[NDIG]) {
+	buf[NDIG - 1] = '\0';
+	return (buf);
+    }
+    p = p1;
+    *p1 += 5;
+    while (*p1 > '9') {
+	*p1 = '0';
+	if (p1 > buf)
+	    ++ * --p1;
+	else {
+	    *p1 = '1';
+	    (*decpt)++;
+	    if (eflag == 0) {
+		if (p > buf)
+		    *p = '0';
+		p++;
+	    }
+	}
+    }
+    *p = '\0';
+    return (buf);
+}
+
+static char *
+     fcvt(double arg, int ndigits, int *decpt, int *sign)
+{
+    return (ap_cvt(arg, ndigits, decpt, sign, 0));
+}
+#endif // defined(__FreeBSD__)
+
 CFX_ByteString StrTrim(const CFX_ByteString& pStr) {
   CFX_ByteString result(pStr);
   result.TrimLeft(' ');
