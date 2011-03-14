# New ports collection makefile for:	warppipe
# Date created:		27 June 2004
# Whom:			Chris Howells <howells@kde.org>
#
# $FreeBSD$

PORTNAME=	warppipe
PORTVERSION=	0.3.5b
PORTREVISION=	1
CATEGORIES=	net games
MASTER_SITES=	http://cubeonline.warppipe.com/download/
DISTNAME=	WarpPipe-0.3.5-bsd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Online multi-player gaming for the Nintendo GameCube

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x

ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/WarpPipe-0.3.5-bsd
NO_BUILD=	YES

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/WarpPipe ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/soshell ${PREFIX}/bin

.include <bsd.port.mk>
