# New ports collection makefile for:	abclock
# Date created:				15 August 2000
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	abclock
PORTVERSION=	1.0a
CATEGORIES=	x11-clocks
MASTER_SITES=	http://odur.let.rug.nl/~kleiweg/abclock/

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abclock ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/abc_img ${PREFIX}/bin

.include <bsd.port.mk>
