# New ports collection makefile for:	leafnode
# Version required:	1.0.1
# Date created:		10 April 1996
# Whom:			Patrick Yu <pyu@rogidi.com>
#			Brian Somers <brian@awfulhak.org>
#
# $Id:$
#

DISTNAME=	leafnode-1.0.1
CATEGORIES+=	news
MASTER_SITES=	ftp://sunsite.unc.edu/pub/Linux/system/news/readers/ \
		ftp://sunsite.doc.ic.ac.uk/Mirrors/sunsite.unc.edu/pub/Linux/system/news/readers/
MAINTAINER=	brian@awfulhak.org
EXTRACT_SUFX=	.ELF.tgz

post-install:
	strip ${PREFIX}/sbin/fetch ${PREFIX}/sbin/leafnode ${PREFIX}/sbin/texpire
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${PREFIX}/man/man8/fetch.8 ${PREFIX}/man/man8/leafnode.8 \
		${PREFIX}/man/man8/texpire.8
	chmod 444 ${PREFIX}/man/man8/fetch.8.gz \
		${PREFIX}/man/man8/leafnode.8.gz \
		${PREFIX}/man/man8/texpire.8.gz
.endif

.include <bsd.port.mk>
