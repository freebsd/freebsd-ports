# New ports collection makefile for:	mplayerplug-in
# Date Created:				20 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mplayerplug-in
PORTVERSION=	0.40
CATEGORIES=	www multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mplayerplug-in
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	A Mozilla plugin for the MPlayer media player

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_X_PREFIX=	yes
USE_GMAKE=	yes

do-install:
	${MKDIR} ${PREFIX}/lib/browser_plugins
	${INSTALL_PROGRAM} ${WRKSRC}/mplayerplug-in.so \
		${PREFIX}/lib/browser_plugins

.include <bsd.port.mk>
