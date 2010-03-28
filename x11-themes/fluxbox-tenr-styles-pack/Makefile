# New ports collection makefile for:	fluxbox-tenr-styles-pack
# Date created:		2007-12-15
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fluxbox-tenr-styles-pack
PORTVERSION=	20071215
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/fluxthemes/
DISTNAME=	tenr.de-styles-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Tenner themes pack for fluxbox

RUN_DEPENDS=	fluxbox:${PORTSDIR}/x11-wm/fluxbox

INSTALL_DIR=	${PREFIX}/share/fluxbox/styles/

USE_BZIP2=	yes
USE_XORG=	x11
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/tenr.de-styles-pkg

do-install:
	${MKDIR} ${INSTALL_DIR}
	cd ${WRKSRC}; ${COPYTREE_SHARE} \* ${INSTALL_DIR}

.include <bsd.port.mk>
