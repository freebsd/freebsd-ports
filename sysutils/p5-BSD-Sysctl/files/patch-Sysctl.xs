--- Sysctl.xs.orig	2014-01-22 00:02:47.000000000 +0100
+++ Sysctl.xs	2018-05-11 10:26:40.364491000 +0200
@@ -14,6 +14,7 @@
 
 #include <stdio.h>
 #include <sys/types.h>
+#include <sys/cdefs.h>
 #include <sys/sysctl.h>
 
 #include <sys/time.h>       /* struct clockinfo */
@@ -48,78 +49,114 @@
 #include <netinet6/raw_ip6.h>
 #include "bsd-sysctl.h"
 
+void
+_iterator_first(HV *self)
+{
+	SV **headp;
+	int name[CTL_MAXNAME];
+	size_t len;
+
+	headp = hv_fetch(self, "head", 4, 0);
+	if (headp == NULL || *headp == NULL)
+		croak( "failed to fetch head in _iterator_first()\n" );
+
+	if (SvPOK(*headp)) {
+		/* we were given starting node */
+		len = sizeof(name);
+		if (sysctlnametomib(SvPV_nolen(*headp), name, &len) == -1)
+			croak("sysctlnametomib(head) failed in _iterator_first\n");
+	} else {
+		/* start at the top like sysctl -a */
+		name[0] = 1;
+		len = 1;
+	}
+
+	hv_store(self, "_next", 5, newSVpvn((char const *) name, len * sizeof(int)), 0);
+	hv_store(self, "_len0", 5, newSViv(len), 0);
+	hv_store(self, "_name", 5, newSVpvn("", 0), 0);
+}
+
 int
-_init_iterator(HV *self, int *mib, int *miblenp, int valid) {
-    SV **headp;
-    int qoid[CTL_MAXNAME];
-    u_int qoidlen;
-    SV *clen;
-    SV **clenp;
-    int cmplen;
-    int j;
-
-    qoid[0] = 0;
-    qoid[1] = 2;
-    if (valid) {
-        memcpy(qoid+2, mib, (*miblenp) * sizeof(int));
-        qoidlen = *miblenp + 2;
-        *miblenp = (CTL_MAXNAME+2) * sizeof(int);
-        clenp = hv_fetch(self, "_len", 4, 0);
-        cmplen = SvIV(*clenp);
-    }
-    else {
-        headp = hv_fetch(self, "head", 4, 0);
-        if (!(headp && *headp)) {
-            croak( "failed to get some head in _init_iterator()\n" );
-        }
-        if (SvPOK(*headp)) {
-            /* begin where asked */
-            qoidlen = sizeof(qoid);
-            if (sysctlnametomib( SvPV_nolen(*headp), qoid+2, (size_t*)&qoidlen) == -1) {
-                warn( "_init_iterator(%s): sysctlnametomib lookup failed\n",
-                    SvPV_nolen(*headp)
-                );
-                return 0;
-            }
-            cmplen = qoidlen;
-            qoidlen += 2;
-        }
-        else {
-            /* begin at the beginning */
-            qoid[2] = 1;
-            cmplen  = 0;
-            qoidlen = 3;
-        }
-        clen = newSViv(cmplen);
-        SvREFCNT_inc(clen);
-        hv_store(self, "_len", 4, clen, 0);
-    }
-
-    /*
-    printf( "next: " );
-    for (j = 0; j < qoidlen; ++j) {
-        if (j) printf("."); printf("%d", qoid[j]);
-    }
-    printf("\n");
-    */
-
-    /* load the mib */
-    if (sysctl(qoid, qoidlen, mib, (size_t*)miblenp, 0, 0) == -1) {
-        return 0;
-    }
-    *miblenp /= sizeof(int);
-    if (*miblenp < cmplen) {
-        return 0 ;
-    }
-
-    for (j = 0; j < cmplen; ++j) {
-        if (mib[j] != qoid[j+2]) {
-            return 0;
-        }
-    }
-    return 1;
+_iterator_next(HV *self)
+{
+	SV *nextp, **len0p, *namep;
+	int *next, name1[CTL_MAXNAME + 2], name2[CTL_MAXNAME + 2];
+	size_t len0, next_len, len1, len2;
+
+	if (! hv_exists(self, "_len0", 5))
+		_iterator_first(self);
+
+	len0p = hv_fetch(self, "_len0", 5, 0);
+	if (len0p == NULL || *len0p == NULL)
+		croak("hv_fetch(_len0) failed in _iterator_next\n");
+	len0 = SvIV(*len0p);
+	
+	nextp = hv_delete(self, "_next", 5, 0);
+	if (nextp == NULL)
+		return 0;
+	next = (int *) SvPV(nextp, next_len);
+	next_len /= sizeof(int);
+
+	namep = hv_delete(self, "_name", 5, 0);
+	if (namep == NULL)
+		return 0;
+
+	/*
+	 * Get next (after _next): name1 = [ 0, 2, next ]
+	 */
+
+	name1[0] = 0;
+	name1[1] = 2; /* get next */
+	memcpy((name1 + 2), next, next_len * sizeof(int));
+	len1 = next_len + 2;
+
+	len2 = sizeof(name2);
+	if (sysctl(name1, len1, name2, &len2, 0, 0) < 0) {
+		if (errno == ENOENT)
+			return (0);
+
+		croak("sysctl(next) failed in _iterator_next()\n");
+	}
+	len2 /= sizeof(int);
+
+	if (len2 < len0)
+		return 0; /* shorter than first */
+	if (memcmp(name2, next, len0 * sizeof(int)) != 0)
+		return 0; /* does not match anymore */
+
+	/* at this point, name2/len2 has next iterator, update _next here */
+	hv_store(self, "_next", 5, newSVpvn((char const *) name2, len2 * sizeof(int)), 0);
+
+	/* 
+	 * Get name (from name2): name1 = [ 0, 1, name2 ]
+	 */
+
+	name1[0] = 0;
+	name1[1] = 1; /* get name */
+	memcpy((name1 + 2), name2, len2 * sizeof(int));
+	len1 = len2 + 2;
+
+	len2 = sizeof(name2);
+	if (sysctl(name1, len1, name2, &len2, 0, 0) < 0) {
+		if (errno == ENOENT)
+			return (0);
+
+		croak("sysctl(name) failed in _iterator_next()\n");
+	}
+
+	/* at this point, name2/len2 has name, update _name here */
+	hv_store(self, "_name", 5, newSVpvn((char const *) name2, len2 - 1), 0);
+
+	return 1;
 }
 
+/*
+ * The below two comparisons must be true for the 64-bit setting code to
+ * work correctly.
+ */
+_Static_assert(LLONG_MAX >= INT64_MAX, "compile-time assertion failed");
+_Static_assert(ULLONG_MAX >= UINT64_MAX, "compile-time assertion failed");
+
 MODULE = BSD::Sysctl   PACKAGE = BSD::Sysctl
 
 PROTOTYPES: ENABLE
@@ -127,67 +164,18 @@
 SV *
 next (SV *refself)
     INIT:
-        int mib[CTL_MAXNAME+2];
-        size_t miblen;
-        int qoid[CTL_MAXNAME+2];
-        size_t qoidlen;
-        char name[BUFSIZ];
-        size_t namelen;
         HV *self;
-        SV **ctxp;
-        SV *ctx;
-        SV *cname;
-        int j;
-        int *p;
+        SV **namep;
 
     CODE:
         self = (HV *)SvRV(refself);
-        if ((ctxp = hv_fetch(self, "_ctx", 4, 0))) {
-            p = (int *)SvPVX(*ctxp);
-            miblen = *p++;
-            memcpy(mib, p, miblen * sizeof(int));
-
-            if (!_init_iterator(self, mib, (int*)&miblen, 1)) {
-                XSRETURN_UNDEF;
-            }
-        }
-        else {
-            miblen = sizeof(mib)/sizeof(mib[0]);
-            if (!_init_iterator(self, mib, (int*)&miblen, 0)) {
-                XSRETURN_UNDEF;
-            }
-        }
-
-        qoid[0] = 0;
-        qoid[1] = 1;
-        memcpy(qoid+2, mib, miblen * sizeof(int));
-        qoidlen = miblen + 2;
-
-        bzero(name, BUFSIZ);
-        namelen = sizeof(name);
-        j = sysctl(qoid, qoidlen, name, &namelen, 0, 0);
-        if (j || !namelen) {
-            warn("next(): sysctl name failure %d %zu %d", j, namelen, errno);
-            XSRETURN_UNDEF;
-        }
-        cname = newSVpvn(name, namelen-1);
-        SvREFCNT_inc(cname);
-        hv_store(self, "_name", 5, cname, 0);
-        RETVAL = cname;
-
-        /* reuse qoid to build context store
-         *  - the length of the mib
-         *  - followed by the mib values
-         * and copy to an SV to save in the self hash
-         */
-        p = qoid;
-        memcpy(p++, (const void *)&miblen, sizeof(int));
-        memcpy(p, (const void *)mib, miblen * sizeof(int));
-
-        ctx = newSVpvn((const char *)qoid, (miblen+1) * sizeof(int));
-        SvREFCNT_inc(ctx);
-        hv_store(self, "_ctx", 4, ctx, 0);
 
+	if (_iterator_next(self) == 0)
+		XSRETURN_UNDEF;
+	
+	namep = hv_fetch(self, "_name", 5, 0);
+	SvREFCNT_inc(*namep);
+	RETVAL = *namep;
     OUTPUT:
         RETVAL
 
@@ -583,25 +571,79 @@
         }
         case FMT_DEVSTAT: {
             HV *c = (HV *)sv_2mortal((SV *)newHV());
-            struct devstat *inf = (struct devstat *)buf;
+            struct devstat *inf = (struct devstat *)(buf + sizeof(buf));
             RETVAL = newRV((SV *)c);
-            hv_store(c, "devno",           5, newSViv(inf->device_number), 0);
-            hv_store(c, "unitno",          6, newSViv(inf->unit_number), 0);
+            char *p = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
+            do {
+                char name[BUFSIZ];
+                strcpy(name, "#.devno"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSViv(inf->device_number), 0);
+                strcpy(name, "#.device_name"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn(inf->device_name, strlen(inf->device_name)), 0);
+                strcpy(name, "#.unitno"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSViv(inf->unit_number), 0);
 #if __FreeBSD_version < 500000
-            hv_store(c, "sequence",        8, newSVpvn("", 0), 0);
-            hv_store(c, "allocated",       9, newSVpvn("", 0), 0);
-            hv_store(c, "startcount",     10, newSVpvn("", 0), 0);
-            hv_store(c, "endcount",        8, newSVpvn("", 0), 0);
-            hv_store(c, "busyfromsec",    11, newSVpvn("", 0), 0);
-            hv_store(c, "busyfromfrac",   12, newSVpvn("", 0), 0);
+                strcpy(name, "#.sequence"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.allocated"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.startcount"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.endcount"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.busyfromsec"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.busyfromfrac"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.bytes_no_data"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.bytes_read"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.bytes_write"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.bytes_free"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.operations_no_data"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.operations_read"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.operations_write"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
+                strcpy(name, "#.operations_free"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVpvn("", 0)), 0);
 #else
-            hv_store(c, "sequence",        8, newSVuv(inf->sequence0), 0);
-            hv_store(c, "allocated",       9, newSViv(inf->allocated), 0);
-            hv_store(c, "startcount",     10, newSViv(inf->start_count), 0);
-            hv_store(c, "endcount",        8, newSViv(inf->end_count), 0);
-            hv_store(c, "busyfromsec",    11, newSViv(inf->busy_from.sec), 0);
-            hv_store(c, "busyfromfrac",   12, newSVuv(inf->busy_from.frac), 0);
+                strcpy(name, "#.sequence"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVuv(inf->sequence0), 0);
+                strcpy(name, "#.allocated"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSViv(inf->allocated), 0);
+                strcpy(name, "#.startcount"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSViv(inf->start_count), 0);
+                strcpy(name, "#.endcount"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSViv(inf->end_count), 0);
+                strcpy(name, "#.busyfromsec"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSViv(inf->busy_from.sec), 0);
+                strcpy(name, "#.busyfromfrac"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVuv(inf->busy_from.frac), 0);
+                strcpy(name, "#.bytes_no_data"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVuv(inf->bytes[DEVSTAT_NO_DATA]), 0);
+                strcpy(name, "#.bytes_read"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVuv(inf->bytes[DEVSTAT_READ]), 0);
+                strcpy(name, "#.bytes_write"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVuv(inf->bytes[DEVSTAT_WRITE]), 0);
+                strcpy(name, "#.bytes_free"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVuv(inf->bytes[DEVSTAT_FREE]), 0);
+                strcpy(name, "#.operations_no_data"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVuv(inf->operations[DEVSTAT_NO_DATA]), 0);
+                strcpy(name, "#.operations_read"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVuv(inf->operations[DEVSTAT_READ]), 0);
+                strcpy(name, "#.operations_write"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVuv(inf->operations[DEVSTAT_WRITE]), 0);
+                strcpy(name, "#.operations_free"); name[0] = *p;
+                hv_store(c, name, strlen(name), newSVuv(inf->operations[DEVSTAT_FREE]), 0);
 #endif
+                ++p;
+                ++inf;
+            } while (inf < (struct devstat *)(buf + buflen));
             break;
         }
 #if __FreeBSD_version >= 500000
@@ -878,6 +920,10 @@
         SV **oidp;
         SV *oid;
         char *oid_data;
+        int64_t int64val;
+        long long llval;
+        uint64_t uint64val;
+        unsigned long long ullval;
         int oid_fmt;
         int oid_len;
         int intval;
@@ -955,6 +1001,42 @@
             newval  = &ulongval;
             newsize = sizeof(ulongval);
             break;
+
+        case FMT_64:
+            llval = strtoll(value, &endconvptr, 0);
+            if (endconvptr == value || *endconvptr != '\0' ||
+                (llval == 0 && errno == EINVAL)) {
+                warn("invalid 64-bit integer: '%s'", value);
+                XSRETURN_UNDEF;
+            }
+#if (LLONG_MAX > INT64_MAX)
+            if (llval < INT64_MIN)
+                int64val = INT64_MIN;
+            else if (llval > INT64_MAX)
+                int64val = INT64_MAX;
+            else
+#endif
+                int64val = (int64_t)llval;
+            newval  = &int64val;
+            newsize = sizeof(int64val);
+            break;
+
+        case FMT_U64:
+            ullval = strtoull(value, &endconvptr, 0);
+            if (endconvptr == value || *endconvptr != '\0' ||
+                (ullval == 0 && errno == EINVAL)) {
+                warn("invalid unsigned 64-bit integer: '%s'", value);
+                XSRETURN_UNDEF;
+            }
+#if (ULLONG_MAX > UINT64_MAX)
+            if (ullval > UINT64_MAX)
+                uint64val = UINT64_MAX;
+            else
+#endif
+                uint64val = (uint64_t)ullval;
+            newval  = &uint64val;
+            newsize = sizeof(uint64val);
+            break;
         }
         
         if (sysctl((int *)oid_data, oid_len, 0, 0, newval, newsize) == -1) {
