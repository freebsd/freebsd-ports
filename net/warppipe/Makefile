# New ports collection makefile for:	warppipe
# Date created:		27 June 2004
# Whom:			Chris Howells <howells@kde.org>
#
# $FreeBSD$

PORTNAME=	warppipe
PORTVERSION=	0.3.5b
CATEGORIES=	net games
MASTER_SITES=	http://www.warppipe.com/download/
DISTNAME=	WarpPipe-0.3.5-bsd

MAINTAINER=	howells@kde.org
COMMENT=	Online multi-player gaming for the Nintendo GameCube

LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x

USE_XLIB=	YES
WRKSRC=		${WRKDIR}/WarpPipe-0.3.5-bsd
NO_BUILD=	YES

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/WarpPipe ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/soshell ${PREFIX}/bin

.include <bsd.port.mk>
