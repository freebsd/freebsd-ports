# New ports collection makefile for:	xinetd
# Version required:	2.1.7-freebsd.4
# Date created:		28 June 1996
# Whom:			markm
#
# $Id: Makefile,v 1.2 1996/11/17 07:58:10 obrien Exp $
#

DISTNAME=	xinetd.2.1.7.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.telebase.com/pub/security/
DISTFILES=	xinetd.2.1.7-freebsd.4.tar.gz

MAINTAINER=	markm@FreeBSD.ORG

WRKSRC=		${WRKDIR}/xinetd.2.1.7-freebsd.4
MAN1=		xinetd.1
MAN5=		xinetd.conf.5 xinetd.log.5

do-build:
	cd ${WRKSRC} ; ./compile-src -os freebsd2 -sf has_SB

do-install:
	cd ${WRKSRC}/xinetd ; make install
	cd ${WRKSRC}/xinetd ; make install.man

.include <bsd.port.mk>
