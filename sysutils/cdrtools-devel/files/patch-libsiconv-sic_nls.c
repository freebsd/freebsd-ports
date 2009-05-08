###########################################################################
# This patch was contributed by Jung-uk Kim <jkim@FreeBSD.org>.
###########################################################################
# The contents of this file are subject to the terms of the
# Common Development and Distribution License, Version 1.0 only
# (the "License").  You may not use this file except in compliance
# with the License.
#
# See the file CDDL.Schily.txt in this distribution for details.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file CDDL.Schily.txt from this distribution.
###########################################################################
# The file CDDL.Schily.txt can be found in the original cdrtools tarball,
# which is mirrored at ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/.
###########################################################################

--- libsiconv/sic_nls.c.orig	2007-11-27 16:49:03.000000000 -0500
+++ libsiconv/sic_nls.c	2008-02-09 03:13:23.000000000 -0500
@@ -440,12 +440,15 @@
 	siconvt_t	*sp;
 	iconv_t		to;
 	iconv_t		from;
-	char		*nm = sip->sic_name;
+	char		*nm;
 
 	if ((sp = (siconvt_t *)malloc(sizeof (siconvt_t)))
 							== NULL) {
 		return ((siconvt_t *)NULL);
 	}
+	nm = sip->sic_name;
+	if (strncmp("iconv:", sip->sic_name, 6) == 0)
+		nm = &sip->sic_name[6];
 	if ((from = iconv_open("UCS-2BE", nm)) == (iconv_t)-1) {
 		free(sp);
 		return ((siconvt_t *)NULL);
@@ -455,7 +458,7 @@
 		iconv_close(from);
 		return ((siconvt_t *)NULL);
 	}
-	sp->sic_name = nm;	/* Allow to compare name pointers */
+	sp->sic_name = sip->sic_name;	/* Allow to compare name pointers */
 	sp->sic_uni2cs = NULL;
 	sp->sic_cs2uni = NULL;
 	sp->sic_cd2uni = from;
