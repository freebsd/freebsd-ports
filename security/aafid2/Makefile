# New ports collection makefile for:    aafid2
# Date created:                         2000/06/14 16:55
# Whom:                                 se
#
# $FreeBSD$
#

PORTNAME=	aafid2
PORTVERSION=	0.10
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.cerias.purdue.edu/pub/tools/unix/ids/AAFID/
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A distributed monitoring and intrusion detection system

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	ptksh:${PORTSDIR}/x11-toolkits/p5-Tk

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
		tar -C ${PREFIX}/lib -xzf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
		${SH} ${FILESDIR}/post-install ${PREFIX}

.include <bsd.port.mk>
