# New ports collection makefile for:	xinetd
# Version required:	2.1.7-freebsd.4
# Date created:		28 June 1996
# Whom:			markm
#
# $Id$
#

DISTNAME=	xinetd.2.1.7.4
CATEGORIES+=	security
MASTER_SITES=	ftp://ftp.telebase.com/pub/security/
DISTFILES=	xinetd.2.1.7-freebsd.4.tar.gz

WRKSRC=		${WRKDIR}/xinetd.2.1.7-freebsd.4

MAINTAINER=	markm@FreeBSD.ORG

do-build:
	cd ${WRKSRC} ; ./compile-src -os freebsd2 -sf has_SB

do-install:
	cd ${WRKSRC}/xinetd ; make install
	cd ${WRKSRC}/xinetd ; make install.man

.include <bsd.port.mk>
