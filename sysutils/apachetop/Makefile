# New ports collection makefile for:	apachetop
# Date created:			30 Sep 2003
# Whom:				Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	apachetop
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://clueful.shagged.org/apachetop/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	esn@x123.info
COMMENT=	Apache RealTime log stats

WRKSRC=		${WRKDIR}/ApacheTop-${PORTVERSION}

do-build:
	cd ${WRKSRC}; ${MAKE} freebsd

do-install:
	${CP} -rp ${WRKSRC}/${PORTNAME} ${PREFIX}/sbin

.include <bsd.port.mk>
