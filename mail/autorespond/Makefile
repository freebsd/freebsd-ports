# New ports collection makefile for: autorespond
# Date created:		24 Jan 2000
# Whom:			Neil Blakey-Milner <nbm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autorespond
PORTVERSION=	2.0.2
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/devel/

MAINTAINER=	roam@FreeBSD.org

do-build:
	@cd ${WRKSRC} && ${MAKE} autorespond

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autorespond ${PREFIX}/bin/

.include <bsd.port.mk>
