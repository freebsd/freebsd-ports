# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fluxbox-tenr-styles-pack
PORTVERSION=	20071215
PORTREVISION=	3
CATEGORIES=	x11-themes
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/fluxthemes/
DISTNAME=	tenr.de-styles-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tenner themes pack for fluxbox

RUN_DEPENDS=	fluxbox:x11-wm/fluxbox

INSTALL_DIR=	${PREFIX}/share/fluxbox/styles/

USES=	tar:bzip2
USE_XORG=	x11
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/tenr.de-styles-pkg

do-install:
	${MKDIR} ${STAGEDIR}${INSTALL_DIR}
	cd ${WRKSRC}; ${COPYTREE_SHARE} \* ${STAGEDIR}${INSTALL_DIR}

.include <bsd.port.mk>
