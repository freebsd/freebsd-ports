# New ports collection makefile for: autorespond
# Version required:	1.0.0
# Date created:		24 Jan 2000
# Whom:			Neil Blakey-Milner <nbm@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	autorespond-1.0.0
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/vpopmail/

MAINTAINER=	nbm@FreeBSD.org

do-build:
	@cd ${WRKSRC} && ${MAKE} autorespond

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autorespond ${PREFIX}/bin/

.include <bsd.port.mk>
