# New ports collection makefile for:    aafid2
# Date created:                         2000/06/14 16:55
# Whom:                                 se
#
# $FreeBSD$
#

PORTNAME=	aafid2
PORTVERSION=	0.10
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.rge.com/pub/security/cerias/tools/unix/ids/AAFID/ \
		ftp://ftp.sunsite.org.uk/Mirrors/coast.cs.purdue.edu/pub/COAST/tools/AAFID/ \
		ftp://ftp.auscert.org.au/pub/coast/COAST/tools/AAFID/
EXTRACT_ONLY=

MAINTAINER=	se@FreeBSD.org

RUN_DEPENDS=	ptksh:${PORTSDIR}/x11-toolkits/p5-Tk

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
		tar -C ${PREFIX}/lib -xzf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
		${SH} ${FILESDIR}/post-install ${PREFIX}

.include <bsd.port.mk>
